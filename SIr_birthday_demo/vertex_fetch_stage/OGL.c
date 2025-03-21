/* Om Shree Ganeshaya namaha */

// windows header files
#include<windows.h>	// Win32 API
#include<stdio.h>	// for file IO
#include<stdlib.h>	// for exit()
#include<math.h>

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
FILE* gpFILE = NULL;

//global variable declaration
HWND ghwnd = NULL;
BOOL gbActive = FALSE;
DWORD dwStyle = 0;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
BOOL gbFullscreen = FALSE;

// OpenGL releted global variables
HDC ghdc = NULL;
HGLRC ghrc = NULL; //grapgics library rendering context

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
	pfd.cDepthBits = 32;

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

	//enabling depth step - 2
	glShadeModel(GL_SMOOTH);	//azun tar lighting ani coloring kela nahi when karu then shading smooth kar..beautification....not compulsory..
	glClearDepth(1.0f);	// like clear color use depth colo..all bite of depth buffer turn to 1....compulsory
	glEnable(GL_DEPTH_TEST);	// out of 8 tests enable the depth test....compulsory
	glDepthFunc(GL_LEQUAL);	// potential fragment of z co-ordinates is less than or equal to 1.0 - clear depth
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// when enabling depth the corners round shape will appear as ellipse...artifacts..then to correct it use NICEST...that hint is given here...beautification....optional

	//set the clear colour of window to blue
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	// for black 2^32 is the range alpha is opaque so 1
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


GLfloat x_translate = 0.001;
GLfloat X_circle0_translate = 0.0, X_circle1_translate = 0.0, x_line_translate = 0.0;
int condition = 1, countref , line_state = 1;
int start1;
void display(void)
{
	void drawConveyor(void);
	void draw_circle_with_LINES(GLfloat);
	// code
	// depth step - 3
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// kontya colour ne binth clear haru colour buffer -> chotta bacchan tech frame buffer..also clear depth buffer using clear depth value - 1.0f...complusory
	glMatrixMode(GL_MODELVIEW);	//internally model view matrix bolavte...this is all zeros matrix
	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);	// z axis -ve number scrren che aath and +ve number scrren che baher
	
	// bg green colour
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.517f, 0.568f);
	glVertex3f(-2.0f, 2.0f, 0.0f);
	glVertex3f(-2.0f, -2.0f, 0.0f);
	glVertex3f(2.0f, -2.0f, 0.0f);
	glVertex3f(2.0f, 2.0f, 0.0f);
	glEnd();



	// draw conveyor
	glTranslatef(x_translate, 0.0, 0.0);
	drawConveyor();

	// draw red line
	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);

	glTranslatef(0.0, x_line_translate, 0.0);
	glLineWidth(1.5f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.75f, -0.5f, 0.0f);
	glVertex3f(-0.75f, 0.0f, 0.0f);
	glEnd();

	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(X_circle0_translate, 0.0f, -3.0f);

	switch (condition)
	{
	case 1:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.3);

		break;

	case 2:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.46);
		break;

	case 3:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.4);
		break;

	case 4:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.44);
		break;

	case 5:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.35);
		break;

	case 6:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.33);
		break;

	case 7:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.4);
		break;

	case 8:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.46);
		break;
	default:
		break;
	}




	//////////////////
	//if (countref == 1000)
	//{
	//	start1 = 1;

	//}

	//if (X_circle1_translate >= 4.0)
	//{
	//	X_circle1_translate = -0.5;
	//	countref = 0;
	//	start1 = 0;
	//}
		

	//////////////////


	if (X_circle0_translate >= 4.0)
	{
		X_circle0_translate = -0.5;
		condition++;
		if(condition >= 9)
			condition = 1;
	}
		

	//draw_circle_with_LINES(0.3);
	//draw_circle_with_LINES(0.4);

	x_translate = x_translate + 0.001;
	X_circle0_translate = X_circle0_translate + 0.001;

	if (x_translate >= 17.0)
	{
		x_translate = 0.0;
	}
	//if (start1)
	//	X_circle1_translate = X_circle1_translate + 0.0006;

	switch (line_state)
	{
	case 1:
		if (x_line_translate <= 0.2)
			x_line_translate = x_line_translate + 0.001;
		else line_state = 2;
		break;

	case 2:
		if (x_line_translate >= 0.0)
			x_line_translate = x_line_translate - 0.001;
		else line_state = 1;
		break;
	default:
		break;
	}


	//countref++;
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
	glVertex3f(-20.5f, -0.275f, 0.0f);
	glVertex3f(-20.5f, -0.3f, 0.0f);
	glVertex3f(3.5f, -0.3f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(3.5f, -0.5f, 0.0f);
	glVertex3f(-20.5f, -0.5f, 0.0f);
	glVertex3f(-20.5f, -0.575f, 0.0f);
	glVertex3f(3.5f, -0.575f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.613f, 0.615f, 0.58f);
	glVertex3f(3.5f, -0.3f, 0.0f);
	glVertex3f(-20.5f, -0.3f, 0.0f);
	glVertex3f(-20.5f, -0.5f, 0.0f);
	glVertex3f(3.5f, -0.5f, 0.0f);
	glEnd();
}

void conveyorTiles(void)
{
	glLineWidth(1.2f);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f - 20.5, -0.3f, 0.0f);
	glVertex3f(-0.075f - 20.5, -0.5f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.02f - 20.5, -0.3f, 0.0f);
	glVertex3f(-0.055f - 20.5, -0.5f, 0.0f);
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
	for (i = 0.0; i < 19.5; i = i + 0.01)
	{
		glTranslatef(0.1f, 0.0f, 0.0f);
		conveyorTiles();
	}
}

void draw_circle_with_LINES(GLfloat y_pos)
{
	GLfloat theta;
	int i;
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(1.5f);
	glBegin(GL_LINES);

	for (i = 0; i < 1000; i++)
	{
		theta = i * ((2 * 3.14159) / 1000);
		glVertex3f( (0.05 * cos(theta)) - 1.8, (0.05 * sin(theta)) - y_pos, 0.0f);
		glVertex3f(0.0 -1.8, 0.0- y_pos, 0.0);
	}

	glEnd();
}