/* Om Shree Ganeshaya namaha */

// windows header files
#include<windows.h>	// Win32 API
#include<stdio.h>	// for file IO
#include<stdlib.h>	// for exit()

// OpenGL header files
#include<gl/GL.h>
#include<gl/GLU.h>	//graphic library utilities...native

#include"OGL.h"

// Macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

//link with OpenGL librarys
#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "GLU32.lib")

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// global variable declarations
FILE* gpFILE           = NULL;

//global variable declaration
HWND ghwnd             = NULL;
BOOL gbActive          = FALSE;
DWORD dwStyle          = 0;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
BOOL gbFullscreen      = FALSE;

// OpenGL releted global variables
HDC ghdc               = NULL;
HGLRC ghrc             = NULL; //grapgics library rendering context

//entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// funtion declarations
	int initialize(void);
	void uninitialize(void);
	void display(void);
	void update(void);

	// local variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("SCPWindow");
	int iResult = 0;
	BOOL bDone = FALSE;

	int x_wnd_TopLeft = 0;
	int y_wnd_TopLeft = 0;
	int x_size = 800;	//width 
	int y_size = 600;	//height

	// code
	gpFILE = fopen("Log.txt", "w");
	if (gpFILE == NULL)
	{
		MessageBox(NULL, TEXT("Log File Cannot Be Opened"), TEXT("ERROR"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	fprintf(gpFILE, "Program started successfully!...\n");

	// WNDCLASSEX initialization
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	//CS class style, DC - device context (rang denaara speciaalist)- shall be in the ownership of the claass
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH) (GetStockObject(BLACK_BRUSH));
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));


	// Register WNDCLASSEX
	RegisterClassEx(&wndclass);


	int screen_x_mid = (GetSystemMetrics(SM_CXSCREEN)) / 2;
	int screen_y_mid = (GetSystemMetrics(SM_CYSCREEN)) / 2;
	x_wnd_TopLeft = screen_x_mid - (x_size / 2);
	y_wnd_TopLeft = screen_y_mid - (y_size / 2);

	//Create Window
	hwnd = CreateWindowEx(WS_EX_APPWINDOW,
		szAppName,
		TEXT("SREEJITH PILLAI"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE, //exclude clipped area from childern, ws_		x_wnd_TopLeft,	//CW_USEDEFAULT,
		x_wnd_TopLeft,	//CW_USEDEFAULT,
		y_wnd_TopLeft,	//CW_USEDEFAULT,
		WIN_WIDTH,		//CW_USEDEFAULT,
		WIN_HEIGHT,		//CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ghwnd = hwnd;
	// initialization
	iResult = initialize();
	if (iResult != 0)
	{
		MessageBox(hwnd, TEXT("Initialize Function : Failed"), TEXT("ERROR"), MB_OK | MB_ICONERROR);
		DestroyWindow(hwnd);
		//uninitialize();
		//exit(0);
	}
	ShowWindow(hwnd, iCmdShow);		// second parameter SW_MAXIMIZE for maximize
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);
	// redraw/ paint the window
	//UpdateWindow(hwnd);

	// Message LOOP
/*	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
*/
	while (bDone == FALSE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				bDone = TRUE;
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			if (gbActive == TRUE)
			{
				//render
				display();
				//update
				update();
			}
		}
	}
	// uninitialization
	uninitialize();
	return((int)msg.wParam);
}

// callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//function declarations
	void ToggleFullscreen(void);
	void resize(int, int);
	// code
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0); //wm_quit chya wparam = 0, passing 0 is convention
		break;
	case WM_SETFOCUS:
		gbActive = TRUE;
		break;
	case WM_KILLFOCUS:
		gbActive = FALSE;
		break;
	case WM_SIZE:
		resize(LOWORD(lParam),HIWORD(lParam)); // width, height parameters
		break;
	case WM_ERASEBKGND:
		return(0);
	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_ESCAPE:		//VK_ESCAPE -> ASCII - 27
			DestroyWindow(hwnd);
			break;
		}
		break;
	case WM_CHAR:
		switch (LOWORD(wParam))
		{
		case 'F':
		case 'f':
			if (gbFullscreen == FALSE)
			{
				ToggleFullscreen();
				gbFullscreen = TRUE;
			}
			else
			{
				ToggleFullscreen();
				gbFullscreen = FALSE;
			}
			break;
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	default:
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam)); //those events which we are not interested do default action on that...asking to OS
}

void ToggleFullscreen(void)
{
	//local variable declartions
	MONITORINFO mi = { sizeof(MONITORINFO) };

	//code
	if (gbFullscreen == FALSE)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);

		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);
			}
		}
		ShowCursor(FALSE);
	}
	else
	{
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
		ShowCursor(TRUE);
	}
}

int initialize(void)
{
	// function declarations
	void resize(int width, int height);

	// code
	//step - 1 initialize pixel format descriptor
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));	//initialize to zero all members of structure
	// initialization of PIXELFORMATDESCRIPTOR
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;	// windows OpenGL last version was 1.5, we write 1 since integer
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;	//window var draw kar | tll now retained mode drawing but now immediate mode | nantar
	pfd.iPixelType = PFD_TYPE_RGBA;	// pixel type RGBA vapar
	pfd.cColorBits = 32;	// 8 x 4 , 4 -< Red, Green, Blue, Alpha
	pfd.cRedBits = 8;	// 8 as above
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;

	// step - 2 get the dc
	ghdc = GetDC(ghwnd);
	if (ghdc == NULL)
	{
		fprintf(gpFILE, "GetDC Failed !!!\n");
		return(-1);
	}

	//step - 3 tell the OS and mi dilela pixel format descriptor la match honara closest matching pixel format dindex de
	// get index from os 
	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	if (iPixelFormatIndex == 0)	// if successful non-zero positive and if fail then zero
	{
		fprintf(gpFILE, "Choose pixel format function : Failed\n");
		return(-2);
	}
	// step - 4 set obtained pixel format
	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFILE, "Set pixel format Failed\n");
		return(-3);
	}

	// step 5 tell windows graphics bridging library WGL to give openGL compatible DC from this DC
	// create openGL context from device context
	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		fprintf(gpFILE, "wglCreateContext function failed\n");
		return(-4);
	}

	// now ghdc will end its role and give its control to ghrc
	// make rendering context current

	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFILE, "wglMakeCurrent function failed\n");
		return(-5);
	}

	//set the clear colour of window to blue
	glClearColor(0.0f, 0.517f, 0.568f, 1.0f);	// for black 2^32 is the range alpha is opaque so 1
	resize(WIN_WIDTH, WIN_HEIGHT);
	// HERE OpenGL STARTS !!! 
	return(0);
}

void resize(int width, int height)
{
	// code
	if (height <= 0)
		height = 1;

	glMatrixMode(GL_PROJECTION);	// matrix maths use projection mode now
	glLoadIdentity();	// use identity matrix first

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);	// window madla kutla area view karaycha tho focus kara - here akkhi window bagh 0 - akkhi height ani width- binocular

	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

}

GLfloat x_translate = 0.001, y_translate = 0.0, z_translate = 0.0;
int beltMotion      = 0;
int scene           = 1;
int test_count;

void display(void)
{
	void drawConveyor(void);
	void drawBoard(void);
	void drawBoardTopView(void);
	// code
	glClear(GL_COLOR_BUFFER_BIT);	
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();	
	glTranslatef(0.0f, 0.0f, -3.0f);
	

	switch (scene)
	{
	case 1:
		GLfloat i;
		//drawConveyor();
		glTranslatef(x_translate, 0.0, 0.0);
		drawConveyor();


		glLoadIdentity();
		glTranslatef(0.0f, -0.17f, -3.0f);
		glTranslatef(x_translate - 2.0, 0.0, 0.0);
		glRotatef(-60, 1.0, 0.0, 0.0);

		drawBoard();

		if (!beltMotion)
		{
			x_translate = x_translate + 0.002;
		}


		if (x_translate >= 2.0)
		{
			beltMotion = 1;

			scene = 2;
		}
		break;

	case 2:

		glTranslatef(0.0, y_translate, z_translate);
		drawConveyor();
		glLoadIdentity();
		glTranslatef(0.0f, -0.17f + y_translate, -3.0f + z_translate);
		glTranslatef(x_translate - 2.0, 0.0, 0.0);
		glRotatef(-60, 1.0, 0.0, 0.0);

		drawBoard();

		if(y_translate <= 0.3)
			y_translate = y_translate + 0.0055;

		if (z_translate <= 0.7)
		{
			z_translate = z_translate + 0.001;
			//scene = 3;
		}
		else
			scene = 10; // 3;
			

		break;

	case 3:

		glTranslatef(0.0, y_translate, z_translate);
		drawConveyor();
		glLoadIdentity();
		glTranslatef(0.0f, -0.17f + y_translate, -3.0f + z_translate);
		glTranslatef(x_translate - 2.0, 0.0, 0.0);
		glRotatef(-60, 1.0, 0.0, 0.0);

		drawBoard();

		if (y_translate >= 0.0)
			y_translate = y_translate - 0.0055;

		if (z_translate >= 0.0)
		{
			z_translate = z_translate - 0.001;
			//scene = 3;
		}
		else
		{
			scene = 4;
			x_translate = 0.0;
		}
			
		break;

	case 4:
		glTranslatef(x_translate, 0.0, 0.0);
		drawConveyor();

		glLoadIdentity();
		glTranslatef(0.0f, -0.17f, -3.0f);
		glTranslatef(x_translate, 0.0, 0.0);
		glRotatef(-60, 1.0, 0.0, 0.0);

		drawBoard();

		if (x_translate <= 2.5)
		{
			x_translate = x_translate + 0.002;
		}
		

		break;	

	case 10:
		drawBoardTopView();
		test_count++;

		if (test_count == 10000)
		{
			scene = 3;
		}

		break;
	}










	SwapBuffers(ghdc);	// double buffering he OS, buffer swap kar, ghdc os la kaltat
}

void update(void)
{
	//code
}

void uninitialize(void)
{
	// function declarations
	void ToggleFullscreen(void);

	//code
	// if application is exitting in full screen then this below code works
	if (gbFullscreen == TRUE)
	{
		ToggleFullscreen();
		gbFullscreen = FALSE;
	}

	// make the hdc as current dc
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);	//opengl cha context sod ani maza context de
	}

	// destroy/delete rendering context
	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	//release the hdc
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}

	//Destroy Window
	if (ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}

	// close the log file
	if (gpFILE)
	{
		fprintf(gpFILE, "Program Ended Successfully!...\n");
		fclose(gpFILE);
		gpFILE = NULL;
	}
}



void conveyorSurface(void)
{
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(3.5f, -0.275f, 0.0f);
	glVertex3f(-7.5f, -0.275f, 0.0f);
	glVertex3f(-7.5f, -0.3f, 0.0f);
	glVertex3f(3.5f, -0.3f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(3.5f, -0.5f, 0.0f);
	glVertex3f(-7.5f, -0.5f, 0.0f);
	glVertex3f(-7.5f, -0.575f, 0.0f);
	glVertex3f(3.5f, -0.575f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.613f, 0.615f, 0.58f);
	glVertex3f(3.5f, -0.3f, 0.0f);
	glVertex3f(-7.5f, -0.3f, 0.0f);
	glVertex3f(-7.5f, -0.5f, 0.0f);
	glVertex3f(3.5f, -0.5f, 0.0f);
	glEnd();
}

void conveyorTiles(void)
{
	glLineWidth(1.2f);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f -7.5, -0.3f, 0.0f);
	glVertex3f(-0.075f - 7.5, -0.5f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.02f - 7.5, -0.3f, 0.0f);
	glVertex3f(-0.055f - 7.5, -0.5f, 0.0f);
	glEnd();
}

void drawConveyor(void)
{
	void conveyorSurface(void);
	void conveyorTiles(void);

	conveyorSurface();

	conveyorTiles();
	//glTranslatef(-3.5f, 0.0f, 0.0f);
	GLfloat i;
	for (i = 0.0; i < 3.5; i = i + 0.01)
	{
		glTranslatef(0.1f, 0.0f, 0.0f);
		conveyorTiles();
	}
}

void drawBoard(void)
{
	//glBegin(GL_QUADS);
	//glColor3f(0.4f, 0.2f, 0.0f);
	//glVertex3f(-0.65f, -0.1f, 0.0f);
	//glVertex3f(-0.65f -0.075f, -0.65f, 0.0f);
	//glVertex3f(0.65f - 0.075f, -0.65f, 0.0f);
	//glVertex3f(0.65f, -0.1f, 0.0f);
	//glEnd();

	//glBegin(GL_QUADS);
	//glColor3f(0.87f, 0.721f, 0.529f);
	//glVertex3f(-0.6f, -0.15f, 0.0f);
	//glVertex3f(-0.6f - 0.075f, -0.6f, 0.0f);
	//glVertex3f(0.6f - 0.075f, -0.6f, 0.0f);
	//glVertex3f(0.6f, -0.15f, 0.0f);
	//glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.2f, 0.0f);
	glVertex3f(-0.65f, -0.1f, 0.0f);
	glVertex3f(-0.65f, -0.65f, 0.0f);
	glVertex3f(0.65f, -0.65f, 0.0f);
	glVertex3f(0.65f, -0.1f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.87f, 0.721f, 0.529f);
	glVertex3f(-0.6f, -0.15f, 0.0f);
	glVertex3f(-0.6f, -0.6f, 0.0f);
	glVertex3f(0.6f, -0.6f, 0.0f);
	glVertex3f(0.6f, -0.15f, 0.0f);
	glEnd();

}



void drawBoardTopView(void)
{
	// border
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.2f, 0.0f);
	glVertex3f(-1.55f, 0.85f, 0.0f);
	glVertex3f(-1.55f, -0.85f, 0.0f);
	glVertex3f(1.55f, -0.85f, 0.0f);
	glVertex3f(1.55f, 0.85f, 0.0f);
	glEnd();


	// main screen
	glBegin(GL_QUADS);
	glColor3f(0.87f, 0.721f, 0.529f);
	glVertex3f(-1.5f, 0.8f, 0.0f);
	glVertex3f(-1.5f, -0.8f, 0.0f);
	glVertex3f(1.5f, -0.8f, 0.0f);
	glVertex3f(1.5f, 0.8f, 0.0f);
	glEnd();

	/////////

}