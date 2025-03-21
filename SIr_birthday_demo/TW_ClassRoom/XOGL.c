#include<windows.h>//* WIN32 API //
#include<stdio.h>//* For FileIO //
#include<stdlib.h>//* exit() //
#include "OGL.h"//* ICON //

//*** OpenGL Headers ***//
#include<gl/GL.h>
#include<gl/GLU.h>

//*** MACRO'S ***
#define WIN_WIDTH 800
#define WIN_HIGHT 600

//*** link With OpenGL Library//
#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "glu32.lib")

//*** Globle Function Declarations ***
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);//CALLBACK - calling convention

//*** Globle Variable Declaration ***
FILE* gpFILE           = NULL;//like struct   (gpFIE  globle pointer of type FILE)
HWND ghwnd             = NULL;
BOOL gbActive          = FALSE; 
DWORD dwStyle          = 0;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
BOOL gbFullscreen      = FALSE;
//*** OpenGL Related Globle Variables ***
PIXELFORMATDESCRIPTOR pfd;
int iPexelFormatIndex  = 0;
HDC ghdc               = NULL;
HGLRC ghrc             = NULL;

//Sir BAck View Variables
GLfloat scale = 1.0f;



//*** Enrty-point Function ***
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//*** Function Declarations ***
	int initialize(void);
	void uninitialize(void);
	void display(void);
	void update(void);

	//*** Local Variable Declarations ***
	WNDCLASSEX wndclass;
	HWND hwnd;
	TCHAR szAppName[] = TEXT("Tushar_Wagdare_Chi_Window");
	MSG msg;
	int iResult       = 0;
	BOOL bDone        = FALSE;
	//For resolution
	int iWinWidth, iWinHight;
	iWinWidth         = GetSystemMetrics(SM_CXSCREEN);//1920
	iWinHight         = GetSystemMetrics(SM_CYSCREEN);//1080

	
	//*** Code ***
	gpFILE = fopen("Log.txt", "w");//Asleli file ughadat ani nasali tr create kart (w - write and create always)  (log - mahiti lihine)
	if (gpFILE == NULL)
	{
		MessageBox(NULL, TEXT("Log Create Hou Shakat Nahi"), TEXT("Error"), MB_OK || MB_ICONERROR);
		exit(0);
	}
	fprintf(gpFILE, "Program Started Successfulle\n");//(f) File madhe print karto
    fprintf(gpFILE, "W = %d  H = %d\n", iWinWidth, iWinHight);


	//*** WNDCLASSEX INITIALIZATION ***
	wndclass.cbSize        = sizeof(WNDCLASSEX);
	wndclass.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;//CS_OWNDC- de(penter) chi ownership aplyakade thevachi
	wndclass.cbClsExtra    = 0;
	wndclass.cbWndExtra    = 0;
	wndclass.lpfnWndProc   = WndProc;
	wndclass.hInstance     = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));//icon load kr ani mazyakade icon ahe ani ha ghe tyacha resource 
	wndclass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName  = NULL;
	wndclass.hIconSm       = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));


	//*** REGISTER WNDCLASSEX ***
	RegisterClassEx(&wndclass);


	//*** CREATE WINDOW ***
	hwnd = CreateWindowEx(WS_EX_APPWINDOW,
		szAppName,
		TEXT("Tushar Tulshiram Wagdare"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,  
		(iWinWidth / 2) - (800 / 2),// 960 - 400  =  560
		(iWinHight / 2) - (600 / 2),// 540 - 300  =  240
		WIN_WIDTH,// Mazya Desktop Chya Window Chya Upper left Corner Pasun (x,y) = (560,240)  he coordinates ghe ani 800 by 600 chi window drow kr...
		WIN_HIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);


	ghwnd = hwnd;


	//*** Initialization ***
	iResult = initialize();
	if (iResult != 0)
	{
		MessageBox(hwnd, TEXT("initialize() Failed !"), TEXT("Error"), MB_OK || MB_ICONERROR);
		DestroyWindow(hwnd);
	}
	fprintf(gpFILE, "iResult initialization successfull\n");


	//*** SHOW THE WINDOW ***
	ShowWindow(hwnd, iCmdShow);
	SetForegroundWindow(hwnd);//mazya window la vr ann...
	SetFocus(hwnd);


	//*** Game LOOP ***
	while(bDone == FALSE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))//PM_REMOVE - message queue rikama karto
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
				//*** Render ***
				display();

				//*** Update ***
				update();
			}
		}
	}


	//*** Uninitialization ***
	uninitialize();


	return((int)msg.wParam);
}



//*** CALLBACK FUNCTION ***
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//*** Function Declaration ***
	void ToggleFullscreen(void);
	void resize(int, int);


	//*** Code ***
	switch (iMsg)
	{
	case WM_SETFOCUS:
		gbActive = TRUE;
		break;

	case WM_KILLFOCUS:
			gbActive = FALSE;
			break;

	case WM_SIZE:
		resize(LOWORD(lParam), HIWORD(lParam));//lPAram ha width ani hight sangto...
		break;

	case WM_ERASEBKGND://background erase kar
		return(0);

	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_ESCAPE:
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

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		break;
	}


	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}



void ToggleFullscreen(void)
{
	//*** Local Variable Declaration ****
	MONITORINFO mi = { sizeof(MONITORINFO) };


	//*** Code ***
	if (gbFullscreen == FALSE)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			fprintf(gpFILE, "Window Contains WS_OVERLAPPEDWINDOW\n");

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
		fprintf(gpFILE, "Window Is Now Already In Fullscreen Mode\n");
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
		ShowCursor(TRUE);
		fprintf(gpFILE, "Now Window Is Normal\n");
	}
}



int initialize(void)
{
	//*** Function Declarations ***
	void resize(int, int);


	//01 -  Initialization Of PFD 
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
	
	pfd.nSize      = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion   = 1;
	pfd.dwFlags    = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits   = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits  = 8;
	pfd.cAlphaBits = 8;
	pfd.cDepthBits = 32;//1st change in depth


	//02 - Get The DC
	ghdc = GetDC(ghwnd);
		if (ghdc == NULL)
		{
			fprintf(gpFILE, "GetDC Failed !!!\n\n");
			return(-1);
		}


	//03 - Tell OS Hya PFD shi match honara PFD de
	iPexelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	if (iPexelFormatIndex == 0)
	{
		fprintf(gpFILE, "ChoosepixelFormat() Failed\n\n");
		return(-2);
	}
	

	//04 - Set Obtained Pixel Format
	if (SetPixelFormat(ghdc, iPexelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFILE, "SetPixelFormat() Failed\n\n");
		return(-3);
	}


	//05 - Tell WGL Bridging library To Give OpenGL Copatible DC From 'ghdc'
	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		fprintf(gpFILE, "wglCreateContex() Failed\n\n");
		return(-4);
	}


	//06 - Now 'ghdc' End Its Roll And Give Controll To 'ghrc'
	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFILE, "wglMakeCurrent() failed\n\n");
		return(-5);
	}


	//07 - 2nd step Enabling Depth
	glShadeModel(GL_SMOOTH);//optional

	glClearDepth(1.0f);//Compulasary (sagly bits na 1 kr -> )
	glEnable(GL_DEPTH_TEST);//Compulasory (default = Disable)
	glDepthFunc(GL_LEQUAL);//Compulsory (LEQUAL -> less than or equal to (1.0))

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//Optional


	//08 - Set the Clear Color of Window To Blue
	glClearColor(0.0f, 0.2f, 0.0f, 1.0f);


	//Warmup call
	resize(WIN_WIDTH, WIN_HIGHT);


	return(0);
}



void resize(int width, int height)
{
	//*** Code ***
	if (height <= 0)
	{
		height = 1;//os chya calculation mule hight 0 or -ve hote mhanun...
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}



void display(void)
{
	// *** Variable Declaration ***
	void SirBackView(void);
	void drawClassroom1(void);
	void drawBoy(void);
	void drawGirl(void);


	//*** Code ***
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//3rd step - Compulasory (clears depth buffer)

	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();


	//----------------------------------------------------------------------------------------------------------------->
	//Function Call
	drawClassroom1();
	drawBoy();
	drawGirl();
	//glLoadIdentity();
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//closed shape filled asu de
	//SirBackView();




	SwapBuffers(ghdc);
}



void update(void)
{
	//*** Code ***
}



void SirBackView(void)
{
	glTranslatef(0.0f, 0.0f, -3.0f);
	glScalef(0.01f, 0.01f, 0.0f);


	//Right Ear
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.45f, 0.45f);
	glVertex3f(-12.6f, 24.2f, 0.0f);
	glVertex3f(-13.2f, 22.8f, 0.0f);
	glVertex3f(-13.5f, 20.9f, 0.0f);
	glVertex3f(-13.2f, 19.2f, 0.0f);
	glVertex3f(-12.9f, 17.2f, 0.0f);
	glVertex3f(-11.8f, 17.6f, 0.0f);
	glVertex3f(-11.5f, 20.4f, 0.0f);
	glVertex3f(-11.4f, 22.2f, 0.0f);
	glVertex3f(-11.5f, 23.8f, 0.0f);
	//glVertex3f(f, f, 0.0f);
	glEnd();

	//Right Ear dot
	glEnable(GL_POINT_SMOOTH);
	glPointSize(3);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.3f, 20.6f, 0.0f);
	glEnd();
	glDisable(GL_POINT_SMOOTH);


	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(-13.5f, 14.0f, 0.0f);
	glVertex3f(-11.8f, 17.6f, 0.0f);
	glVertex3f(-12.9f, 17.2f, 0.0f);
	glVertex3f(-13.2f, 19.2f, 0.0f);
	glVertex3f(-15.0f, 18.3f, 0.0f);
	glVertex3f(-16.7f, 18.2f, 0.0f);
	glVertex3f(-18.7f, 18.1f, 0.0f);
	glVertex3f(-20.1f, 17.3f, 0.0f);
	//glVertex3f(-f, f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(-23.6f, 15.0f, 0.0f);
	glVertex3f(-20.0f, 16.3f, 0.0f);
	glVertex3f(-21.3f, 18.6f, 0.0f);
	glVertex3f(-24.2f, 19.3f, 0.0f);
	glVertex3f(-24.0f, 17.9f, 0.0f);
	//glVertex3f(-f, f, 0.0f);
	glEnd();

	//Left Ear
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.45f, 0.45f);
	glVertex3f(-25.4f, 22.5f, 0.0f);
	glVertex3f(-25.1f, 21.5f, 0.0f);
	glVertex3f(-24.7f, 20.1f, 0.0f);
	glVertex3f(-24.5f, 18.9f, 0.0f);
	glVertex3f(-25.3f, 19.3f, 0.0f);
	glVertex3f(-25.7f, 20.4f, 0.0f);
	glVertex3f(-26.1f, 21.6f, 0.0f);
	glVertex3f(-26.3f, 23.4f, 0.0f);
	//glVertex3f(-f, f, 0.0f);
	glEnd();


	//Head Heir UPside
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(-18.5f, 30.3f, 0.0f);
	glVertex3f(-12.6f, 24.2f, 0.0f);
	glVertex3f(-11.5f, 23.8f, 0.0f);
	glVertex3f(-11.0f, 25.4f, 0.0f);
	glVertex3f(-11.1f, 27.8f, 0.0f);
	glVertex3f(-11.9f, 29.5f, 0.0f);
	glVertex3f(-13.9f, 30.8f, 0.0f);
	glVertex3f(-14.4f, 32.0f, 0.0f);
	glVertex3f(-16.4f, 32.9f, 0.0f);
	glVertex3f(-18.6f, 33.2f, 0.0f);
	glVertex3f(-20.6f, 33.2f, 0.0f);
	glVertex3f(-22.7f, 32.6f, 0.0f);
	glVertex3f(-24.1f, 31.7f, 0.0f);
	glVertex3f(-25.2f, 30.3f, 0.0f);
	glVertex3f(-25.8f, 28.7f, 0.0f);
	glVertex3f(-26.0f, 27.0f, 0.0f);
	glVertex3f(-25.6f, 25.6f, 0.0f);
	glVertex3f(-25.1f, 24.7f, 0.0f);
	glVertex3f(-25.4f, 23.5f, 0.0f);
	glVertex3f(-12.6f, 24.2f, 0.0f);
	glEnd();

	//Head Heir DOWNside
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(-19.6f, 19.5f, 0.0f);
	glVertex3f(-12.6f, 24.2f, 0.0f);
	glVertex3f(-25.4f, 23.5f, 0.0f);
	glVertex3f(-25.4f, 22.5f, 0.0f);
	glVertex3f(-25.1f, 21.5f, 0.0f);
	glVertex3f(-24.7f, 20.1f, 0.0f);
	glVertex3f(-24.5f, 18.9f, 0.0f);
	glVertex3f(-23.6f, 18.5f, 0.0f);
	glVertex3f(-22.4f, 18.2f, 0.0f);
	glVertex3f(-21.3f, 18.3f, 0.0f);
	glVertex3f(-20.0f, 17.4f, 0.0f);
	glVertex3f(-18.7f, 18.1f, 0.0f);
	glVertex3f(-16.7f, 18.2f, 0.0f);
	glVertex3f(-15.02f, 18.3f, 0.0f);
	glVertex3f(-13.2f, 19.2f, 0.0f);
	glVertex3f(-13.5f, 20.9f, 0.0f);
	glVertex3f(-13.2f, 22.8f, 0.0f);
	glVertex3f(-12.6f, 24.2f, 0.0f);
	glEnd();


	//Right Elbow
	//glTranslatef(14.5f, -10.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(14.5f, -10.0f, 0.0f);
	glVertex3f(6.5f, -11.0f, 0.0f);
	glVertex3f(14.5f, -14.0f, 0.0f);
	glVertex3f(18.0f, -10.0f, 0.0f);
	glVertex3f(20.0f, 13.5f, 0.0f);
	glVertex3f(19.0f, 17.0f, 0.0f);
	glVertex3f(15.0f, 17.0f, 0.0f);
	glVertex3f(11.7f, 4.0f, 0.0f);
	glVertex3f(11.5f, -3.5f, 0.0f);
	glVertex3f(6.5f, -11.0f, 0.0f);
	glEnd();

	//Right Palm
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(15.0f, 16.8f, 0.0f);
	glVertex3f(19.0f, 17.2f, 0.0f);
	glVertex3f(17.5f, 20.0f, 0.0f);
	glVertex3f(22.5f, 22.6f, 0.0f);
	glVertex3f(17.2f, 23.3f, 0.0f);
	glVertex3f(18.6f, 26.4f, 0.0f);
	glVertex3f(14.7f, 22.8f, 0.0f);
	glVertex3f(13.1f, 23.6f, 0.0f);
	glEnd();

	//Right Thumb
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(15.0f, 16.8f, 0.0f);
	glVertex3f(15.6f, 18.2f, 0.0f);
	glVertex3f(13.1f, 18.2f, 0.0f);
	glVertex3f(14.7f, 19.5f, 0.0f);
	glVertex3f(13.7f, 20.7f, 0.0f);
	glVertex3f(15.1f, 21.1f, 0.0f);
	glVertex3f(13.0f, 22.0f, 0.0f);
	glEnd();


	//Pen
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(24.1f, 18.0f, 0.0f);
	glVertex3f(23.9f, 19.6f, 0.0f);
	glVertex3f(13.1f, 23.6f, 0.0f);
	glVertex3f(11.8f, 23.0f, 0.0f);
	glVertex3f(13.0f, 22.0f, 0.0f);
	glEnd();


	//Pant Drawing Right
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	glScalef(0.01f, 0.01f, 0.0f);

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(-6.0f, -30.0f, 0.0f);
	glVertex3f(-20.0f, -28.0f, 0.0f);
	glVertex3f(-4.0f, -37.0f, 0.0f);
	glVertex3f(-21.0f, -53.0f, 0.0f);
	glVertex3f(-5.0f, -49.0f, 0.0f);
	glVertex3f(-20.0f, -67.0f, 0.0f);
	glVertex3f(-5.0f, -66.0f, 0.0f);
	glVertex3f(-19.0f, -76.0f, 0.0f);
	glVertex3f(-3.0f, -96.0f, 0.0f);
	glVertex3f(-16.0f, -96.0f, 0.0f);
	glEnd();

	//Pant Drawing Left
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(-20.0f, -28.0f, 0.0f);
	glVertex3f(-36.0f, -25.0f, 0.0f);
	glVertex3f(-20.0f, -31.0f, 0.0f);
	glVertex3f(-37.0f, -27.0f, 0.0f);
	glVertex3f(-20.0f, -40.0f, 0.0f);
	glVertex3f(-36.0f, -34.0f, 0.0f);
	glVertex3f(-21.0f, -53.0f, 0.0f);
	glVertex3f(-38.0f, -46.0f, 0.0f);
	glVertex3f(-23.0f, -70.0f, 0.0f);
	glVertex3f(-37.0f, -65.0f, 0.0f);
	glVertex3f(-27.0f, -85.0f, 0.0f);
	glVertex3f(-39.0f, -83.0f, 0.0f);
	glVertex3f(-28.0f, -96.0f, 0.0f);
	glVertex3f(-40.0f, -96.0f, 0.0f);
	glEnd();

	//Shirt Base
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-20.0f, 10.0f, 0.0f);
	glVertex3f(-6.0f, -30.0f, 0.0f);
	glVertex3f(-6.0f, -21.0f, 0.0f);
	glVertex3f(-1.0f, -10.0f, 0.0f);
	glVertex3f(2.0f, -12.0f, 0.0f);
	glVertex3f(10.0f, -12.0f, 0.0f);
	glVertex3f(14.0f, -10.0f, 0.0f);
	glVertex3f(16.0f, -7.0f, 0.0f);
	glVertex3f(2.0f, 5.0f, 0.0f);
	glVertex3f(1.0f, 7.0f, 0.0f);
	glVertex3f(-12.0f, 12.0f, 0.0f);
	glVertex3f(-13.0f, 14.0f, 0.0f);
	glVertex3f(-19.0f, 17.0f, 0.0f);
	glVertex3f(-23.0f, 16.0f, 0.0f);
	glVertex3f(-25.0f, 15.0f, 0.0f);
	glVertex3f(-26.0f, 13.0f, 0.0f);
	glVertex3f(-38.0f, 11.0f, 0.0f);
	//glVertex3f(-39.0f, 9.0f, 0.0f);
	//glVertex3f(-54.0f, 0.0f, 0.0f);
	//glVertex3f(-49.0f, -6.0f, 0.0f);
	//glVertex3f(-46.0f, -6.0f, 0.0f);
	glVertex3f(-38.0f, -4.0f, 0.0f);
	glVertex3f(-38.0f, -11.0f, 0.0f);
	glVertex3f(-38.0f, -13.0f, 0.0f);
	glVertex3f(-36.0f, -25.0f, 0.0f);
	glVertex3f(-32.0f, -27.0f, 0.0f);
	glVertex3f(-29.0f, -28.0f, 0.0f);
	glVertex3f(-25.0f, -30.0f, 0.0f);
	glVertex3f(-20.0f, -31.0f, 0.0f);
	glVertex3f(-15.0f, -32.0f, 0.0f);
	glVertex3f(-10.0f, -31.0f, 0.0f);
	glVertex3f(-6.0f, -30.0f, 0.0f);
	glEnd();

	glTranslatef(-37.0f, 4.0f, 0.0f);
	//Left Arm Shoulder
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(8.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 7.0f, 0.0f);
	glVertex3f(-16.0f, -3.0f, 0.0f);
	glVertex3f(-10.0f, -8.0f, 0.0f);
	glVertex3f(-8.0f, -8.0f, 0.0f);
	glVertex3f(0.0f, -7.0f, 0.0f);
	glVertex3f(8.0f, 0.0f, 0.0f);
	glEnd();

	//Left Arm Elbow
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(-10.0f, -13.0f, 0.0f);
	glVertex3f(-12.0f, -15.0f, 0.0f);
	glVertex3f(-1.0f, -18.0f, 0.0f);
	glVertex3f(0.0f, -15.0f, 0.0f);
	glVertex3f(0.0f, -13.0f, 0.0f);
	glVertex3f(-5.0f, -11.0f, 0.0f);
	glVertex3f(-8.0f, -8.0f, 0.0f);
	glVertex3f(-10.0f, -8.0f, 0.0f);
	glVertex3f(-16.0f, -3.0f, 0.0f);
	glVertex3f(-18.0f, -5.0f, 0.0f);
	glVertex3f(-19.0f, -7.0f, 0.0f);
	glVertex3f(-20.0f, -9.0f, 0.0f);
	glVertex3f(-12.0f, -15.0f, 0.0f);
	glEnd();

	//Left Arm Hand
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(0.2f, -14.0f, 0.0f);
	glVertex3f(-1.2f, -19.0f, 0.0f);
	glVertex3f(2.0f, -26.0f, 0.0f);
	glVertex3f(-0.5f, -24.5f, 0.0f);
	glVertex3f(0.0f, -28.0f, 0.0f);
	glVertex3f(-3.0f, -26.0f, 0.0f);
	glVertex3f(-3.5f, -28.0f, 0.0f);
	glEnd();

	//Shirt BAse
	glTranslatef(37.0f, -4.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.2f, 0.2f);
	glVertex3f(-5.0f, -19.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-38.0f, -4.0f, 0.0f);
	glColor3f(0.5f, 0.2f, 0.2f);
	glVertex3f(-6.0f, -21.0f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.5f, 0.2f, 0.2f);
	glVertex3f(-39.0f, 9.0f, 0.0f);
	glVertex3f(2.0f, 4.0f, 0.0f);
	glVertex3f(-1.0f, -10.0f, 0.0f);
	glVertex3f(1.0f, 7.0f, 0.0f);
	glVertex3f(-38.0f, -4.0f, 0.0f);
	glVertex3f(-38.0f, 11.0f, 0.0f);
	glVertex3f(-26.0f, 13.0f, 0.0f);
	glVertex3f(-19.0f, 14.0f, 0.0f);
	glVertex3f(-19.0f, 14.0f, 0.0f);
	glVertex3f(-12.0f, 12.0f, 0.0f);
	//glVertex3f(f, f, 0.0f);
	glEnd();
}

void drawClassroom1(void)
{
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.3f);
	glScalef(0.01f, 0.01f, 0.01f);

	// 1
	glBegin(GL_POLYGON);
	glColor3f(0.733, 0.725, 0.725);
	glVertex3f(99.6372f, 56.22f, 0.0f);
	glVertex3f(-99.6372f, 56.22f, 0.0f);
	glVertex3f(-99.9391f, 48.6563f, 0.0f);
	glColor3f(0.753, 0.784, 0.925);
	glVertex3f(-67.2865f, 33.3984f, 0.0f);
	glVertex3f(67.2865f, 33.3984f, 0.0f);
	glVertex3f(99.9391f, 48.6563f, 0.0f);
	glEnd();

	//2 back of blackboard
	glBegin(GL_POLYGON);
	glColor3f(0.812, 0.835, 0.796);
	glVertex3f(67.2865f, 33.3984f, 0.0f);
	glVertex3f(-67.2865f, 33.3984f, 0.0f);
	glColor3f(0.518, 0.522, 0.498);
	glVertex3f(-67.2865f, -33.9797f, 0.0f);
	glVertex3f(67.2865f, -33.9797f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.812, 0.835, 0.796);
	glVertex3f(67.2865f, 33.3984f, 0.0f);

	glEnd();

	//3
	glBegin(GL_POLYGON);
	glColor3f(0.569, 0.533, 0.42);
	glVertex3f(-67.2865f, -33.9797f, 0.0f);
	glVertex3f(-67.2865f, 33.3984f, 0.0f);
	glVertex3f(-99.9391f, 48.6563f, 0.0f);
	glVertex3f(-99.9391f, -56.22f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.569, 0.533, 0.42);
	glVertex3f(67.2865f, -33.9797f, 0.0f);
	glVertex3f(67.2865f, 33.3984f, 0.0f);
	glVertex3f(99.9391f, 48.6563f, 0.0f);
	glVertex3f(99.9391f, -56.22f, 0.0f);
	glEnd();

	//4 flour
	glBegin(GL_POLYGON);
	glColor3f(0.694, 0.455, 0.192);
	glVertex3f(67.2865f, -33.9797f, 0.0f);
	glColor3f(0.416, 0.235, 0.102);
	glVertex3f(-67.2865f, -33.9797f, 0.0f);
	glVertex3f(-99.9391f, -49.6995f, 0.0f);
	glColor3f(0.416, 0.235, 0.102);
	glVertex3f(-99.9391f, -56.22f, 0.0f);
	glVertex3f(99.9391f, -56.22f, 0.0f);
	glColor3f(0.694, 0.455, 0.192);
	glVertex3f(99.9391f, -49.6995f, 0.0f);
	glEnd();

	//BlackBoard
	glBegin(GL_POLYGON);
	glColor3f(0.173, 0.173, 0.18);
	glVertex3f(20.0893f, 3.86695f, 0.0f);
	glVertex3f(-20.0893f, 3.86695f, 0.0f);
	glVertex3f(-20.0893f, -17.4484f, 0.0f);
	glVertex3f(20.0893f, -17.4484f, 0.0f);
	glEnd();

	///////////////////////////////////////////////////////////
	//window Right
	glLoadIdentity();
	glTranslatef(0.5f, -0.13f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.5f, 0.5f, 0.5f);
	// back brown
	glBegin(GL_POLYGON);
	glColor3f(0.424, 0.157, 0.075);
	glVertex3f(18.1718f, 53.1175f, 0.0f);
	glVertex3f(-18.1718f, 53.1175f, 0.0f);
	glVertex3f(-18.1718f, -38.3435f, 0.0f);
	glVertex3f(18.1718f, -38.3435f, 0.0f);
	glEnd();

	//upper back 
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(14.6406f, 49.5863f, 0.0f);
	glVertex3f(-14.6406f, 49.5863f, 0.0f);
	glVertex3f(-14.6406f, 43.0672f, 0.0f);
	glVertex3f(14.6406f, 43.0672f, 0.0f);
	glEnd();
	//inside
	glBegin(GL_POLYGON);
	glColor3f(0., 0.569, 0.878);
	glVertex3f(-1.43639f, 47.0756f, 0.0f);
	glVertex3f(-11.0252f, 47.0756f, 0.0f);
	glVertex3f(-11.0252f, 44.4819f, 0.0f);
	glVertex3f(-1.43639f, 44.4819f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0., 0.569, 0.878);
	glVertex3f(1.43639f, 47.0756f, 0.0f);
	glVertex3f(11.0252f, 47.0756f, 0.0f);
	glVertex3f(11.0252f, 44.4819f, 0.0f);
	glVertex3f(1.43639f, 44.4819f, 0.0f);
	glEnd();

	//back white
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(16.295f, 36.748f, 0.0f);
	glVertex3f(1.77035f, 36.748f, 0.0f);
	glVertex3f(1.77035f, 3.54884f, 0.0f);
	glVertex3f(16.295f, 3.54884f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-16.295f, 36.748f, 0.0f);
	glVertex3f(-1.77035f, 36.748f, 0.0f);
	glVertex3f(-1.77035f, 3.54884f, 0.0f);
	glVertex3f(-16.295f, 3.54884f, 0.0f);
	glEnd();
	//bottom white bk
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-16.295f, -36.748f, 0.0f);
	glVertex3f(-1.77035f, -36.748f, 0.0f);
	glVertex3f(-1.77035f, -3.54884f, 0.0f);
	glVertex3f(-16.295f, -3.54884f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(16.295f, -36.748f, 0.0f);
	glVertex3f(1.77035f, -36.748f, 0.0f);
	glVertex3f(1.77035f, -3.54884f, 0.0f);
	glVertex3f(16.295f, -3.54884f, 0.0f);
	glEnd();
	// in betwn brown part
	glBegin(GL_POLYGON);
	glColor3f(0.424, 0.157, 0.075);
	glVertex3f(14.1257f, -33.5413f, 0.0f);
	glVertex3f(4.41121f, -33.5413f, 0.0f);
	glVertex3f(4.41121f, -7.03852f, 0.0f);
	glVertex3f(14.1257f, -7.03852f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.424, 0.157, 0.075);
	glVertex3f(-14.1257f, -33.5413f, 0.0f);
	glVertex3f(-4.41121f, -33.5413f, 0.0f);
	glVertex3f(-4.41121f, -7.03852f, 0.0f);
	glVertex3f(-14.1257f, -7.03852f, 0.0f);
	glEnd();

	// small inside triangles 
	glBegin(GL_TRIANGLES);
	// blue
	glColor3f(0.133, 0.2, 0.416);
	glVertex3f(14.2358f, 35.7027f, 0.0f);
	glVertex3f(3.75624f, 35.7027f, 0.0f);
	glVertex3f(8.93051f, 29.7425f, 0.0f);

	glVertex3f(14.2358f, 4.52608f, 0.0f);
	glVertex3f(8.93051f, 10.7483f, 0.0f);
	glVertex3f(3.75624f, 4.52608f, 0.0f);

	//green
	glColor3f(0.122, 0.282, 0.251);
	glVertex3f(7.81706f, 28.629f, 0.0f);
	glVertex3f(2.70829f, 34.3928f, 0.0f);
	glVertex3f(2.70829f, 22.4723f, 0.0f);

	glVertex3f(7.81706f, 11.6653f, 0.0f);
	glVertex3f(2.70829f, 18.215f, 0.0f);
	glVertex3f(2.70829f, 5.44308f, 0.0f);

	glVertex3f(15.0217f, 18.215f, 0.0f);
	glVertex3f(9.78198f, 11.6653f, 0.0f);
	glVertex3f(15.0872f, 5.44308f, 0.0f);

	glVertex3f(15.0217f, 22.4723f, 0.0f);
	glVertex3f(15.0217f, 34.3928f, 0.0f);
	glVertex3f(9.78198f, 28.629f, 0.0f);
	glEnd();

	// small inside triangles 
	glBegin(GL_TRIANGLES);
	// blue
	glColor3f(0.133, 0.2, 0.416);
	glVertex3f(-14.2358f, 35.7027f, 0.0f);
	glVertex3f(-3.75624f, 35.7027f, 0.0f);
	glVertex3f(-8.93051f, 29.7425f, 0.0f);

	glVertex3f(-14.2358f, 4.52608f, 0.0f);
	glVertex3f(-8.93051f, 10.7483f, 0.0f);
	glVertex3f(-3.75624f, 4.52608f, 0.0f);

	//green
	glColor3f(-0.122, 0.282, 0.251);
	glVertex3f(-7.81706f, 28.629f, 0.0f);
	glVertex3f(-2.70829f, 34.3928f, 0.0f);
	glVertex3f(-2.70829f, 22.4723f, 0.0f);

	glVertex3f(-7.81706f, 11.6653f, 0.0f);
	glVertex3f(-2.70829f, 18.215f, 0.0f);
	glVertex3f(-2.70829f, 5.44308f, 0.0f);

	glVertex3f(-15.0217f, 18.215f, 0.0f);
	glVertex3f(-9.78198f, 11.6653f, 0.0f);
	glVertex3f(-15.0872f, 5.44308f, 0.0f);

	glVertex3f(-15.0217f, 22.4723f, 0.0f);
	glVertex3f(-15.0217f, 34.3928f, 0.0f);
	glVertex3f(-9.78198f, 28.629f, 0.0f);
	glEnd();

	// middle quad red
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.11, 0.098);
	glVertex3f(15.0217f, 20.2334f, 0.0f);
	glVertex3f(8.93051f, 27.0571f, 0.0f);
	glVertex3f(2.70829f, 20.2334f, 0.0f);
	glVertex3f(8.93051f, 12.8442f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.11, 0.098);
	glVertex3f(-15.0217f, 20.2334f, 0.0f);
	glVertex3f(-8.93051f, 27.0571f, 0.0f);
	glVertex3f(-2.70829f, 20.2334f, 0.0f);
	glVertex3f(-8.93051f, 12.8442f, 0.0f);
	glEnd();

	///////////////////////////////////////////////////////////
	//window left
	glLoadIdentity();
	glTranslatef(-0.5f, -0.13f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.5f, 0.5f, 0.5f);
	// back brown
	glBegin(GL_POLYGON);
	glColor3f(0.424, 0.157, 0.075);
	glVertex3f(18.1718f, 53.1175f, 0.0f);
	glVertex3f(-18.1718f, 53.1175f, 0.0f);
	glVertex3f(-18.1718f, -38.3435f, 0.0f);
	glVertex3f(18.1718f, -38.3435f, 0.0f);
	glEnd();

	//upper back 
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(14.6406f, 49.5863f, 0.0f);
	glVertex3f(-14.6406f, 49.5863f, 0.0f);
	glVertex3f(-14.6406f, 43.0672f, 0.0f);
	glVertex3f(14.6406f, 43.0672f, 0.0f);
	glEnd();
	//inside
	glBegin(GL_POLYGON);
	glColor3f(0., 0.569, 0.878);
	glVertex3f(-1.43639f, 47.0756f, 0.0f);
	glVertex3f(-11.0252f, 47.0756f, 0.0f);
	glVertex3f(-11.0252f, 44.4819f, 0.0f);
	glVertex3f(-1.43639f, 44.4819f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0., 0.569, 0.878);
	glVertex3f(1.43639f, 47.0756f, 0.0f);
	glVertex3f(11.0252f, 47.0756f, 0.0f);
	glVertex3f(11.0252f, 44.4819f, 0.0f);
	glVertex3f(1.43639f, 44.4819f, 0.0f);
	glEnd();

	//back white
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(16.295f, 36.748f, 0.0f);
	glVertex3f(1.77035f, 36.748f, 0.0f);
	glVertex3f(1.77035f, 3.54884f, 0.0f);
	glVertex3f(16.295f, 3.54884f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-16.295f, 36.748f, 0.0f);
	glVertex3f(-1.77035f, 36.748f, 0.0f);
	glVertex3f(-1.77035f, 3.54884f, 0.0f);
	glVertex3f(-16.295f, 3.54884f, 0.0f);
	glEnd();
	//bottom white bk
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-16.295f, -36.748f, 0.0f);
	glVertex3f(-1.77035f, -36.748f, 0.0f);
	glVertex3f(-1.77035f, -3.54884f, 0.0f);
	glVertex3f(-16.295f, -3.54884f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(16.295f, -36.748f, 0.0f);
	glVertex3f(1.77035f, -36.748f, 0.0f);
	glVertex3f(1.77035f, -3.54884f, 0.0f);
	glVertex3f(16.295f, -3.54884f, 0.0f);
	glEnd();
	// in betwn brown part
	glBegin(GL_POLYGON);
	glColor3f(0.424, 0.157, 0.075);
	glVertex3f(14.1257f, -33.5413f, 0.0f);
	glVertex3f(4.41121f, -33.5413f, 0.0f);
	glVertex3f(4.41121f, -7.03852f, 0.0f);
	glVertex3f(14.1257f, -7.03852f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.424, 0.157, 0.075);
	glVertex3f(-14.1257f, -33.5413f, 0.0f);
	glVertex3f(-4.41121f, -33.5413f, 0.0f);
	glVertex3f(-4.41121f, -7.03852f, 0.0f);
	glVertex3f(-14.1257f, -7.03852f, 0.0f);
	glEnd();

	// small inside triangles 
	glBegin(GL_TRIANGLES);
	// blue
	glColor3f(0.133, 0.2, 0.416);
	glVertex3f(14.2358f, 35.7027f, 0.0f);
	glVertex3f(3.75624f, 35.7027f, 0.0f);
	glVertex3f(8.93051f, 29.7425f, 0.0f);

	glVertex3f(14.2358f, 4.52608f, 0.0f);
	glVertex3f(8.93051f, 10.7483f, 0.0f);
	glVertex3f(3.75624f, 4.52608f, 0.0f);

	//green
	glColor3f(0.122, 0.282, 0.251);
	glVertex3f(7.81706f, 28.629f, 0.0f);
	glVertex3f(2.70829f, 34.3928f, 0.0f);
	glVertex3f(2.70829f, 22.4723f, 0.0f);

	glVertex3f(7.81706f, 11.6653f, 0.0f);
	glVertex3f(2.70829f, 18.215f, 0.0f);
	glVertex3f(2.70829f, 5.44308f, 0.0f);

	glVertex3f(15.0217f, 18.215f, 0.0f);
	glVertex3f(9.78198f, 11.6653f, 0.0f);
	glVertex3f(15.0872f, 5.44308f, 0.0f);

	glVertex3f(15.0217f, 22.4723f, 0.0f);
	glVertex3f(15.0217f, 34.3928f, 0.0f);
	glVertex3f(9.78198f, 28.629f, 0.0f);
	glEnd();

	// small inside triangles 
	glBegin(GL_TRIANGLES);
	// blue
	glColor3f(0.133, 0.2, 0.416);
	glVertex3f(-14.2358f, 35.7027f, 0.0f);
	glVertex3f(-3.75624f, 35.7027f, 0.0f);
	glVertex3f(-8.93051f, 29.7425f, 0.0f);

	glVertex3f(-14.2358f, 4.52608f, 0.0f);
	glVertex3f(-8.93051f, 10.7483f, 0.0f);
	glVertex3f(-3.75624f, 4.52608f, 0.0f);

	//green
	glColor3f(-0.122, 0.282, 0.251);
	glVertex3f(-7.81706f, 28.629f, 0.0f);
	glVertex3f(-2.70829f, 34.3928f, 0.0f);
	glVertex3f(-2.70829f, 22.4723f, 0.0f);

	glVertex3f(-7.81706f, 11.6653f, 0.0f);
	glVertex3f(-2.70829f, 18.215f, 0.0f);
	glVertex3f(-2.70829f, 5.44308f, 0.0f);

	glVertex3f(-15.0217f, 18.215f, 0.0f);
	glVertex3f(-9.78198f, 11.6653f, 0.0f);
	glVertex3f(-15.0872f, 5.44308f, 0.0f);

	glVertex3f(-15.0217f, 22.4723f, 0.0f);
	glVertex3f(-15.0217f, 34.3928f, 0.0f);
	glVertex3f(-9.78198f, 28.629f, 0.0f);
	glEnd();

	// middle quad red
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.11, 0.098);
	glVertex3f(15.0217f, 20.2334f, 0.0f);
	glVertex3f(8.93051f, 27.0571f, 0.0f);
	glVertex3f(2.70829f, 20.2334f, 0.0f);
	glVertex3f(8.93051f, 12.8442f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.11, 0.098);
	glVertex3f(-15.0217f, 20.2334f, 0.0f);
	glVertex3f(-8.93051f, 27.0571f, 0.0f);
	glVertex3f(-2.70829f, 20.2334f, 0.0f);
	glVertex3f(-8.93051f, 12.8442f, 0.0f);
	glEnd();


	glLoadIdentity();
	glTranslatef(0.0f, -0.2f, -3.0f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.8f, 1.8f, 1.5f);
	// CARPET
	glBegin(GL_POLYGON);
	glColor3f(0.153, 0.306, 0.322);
	glVertex3f(10.5634f, -33.5764f, 0.0f);
	glVertex3f(-10.5634f, -33.5764f, 0.0f);
	glVertex3f(-20.1836f, -50.176f, 0.0f);
	glVertex3f(20.1836f, -50.176f, 0.0f);

	glEnd();


	//************************* CHAIR ******************************
	glLoadIdentity();
	glTranslatef(0.0f, -0.7f, -3.0f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.5f, 0.5f, 0.5f);

	//top
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.096834, 58.8766, 0.0f);
	glVertex3f(35.5671, 59.1785, 0.0f);
	glVertex3f(36.1709, 70.048, 0.0f);
	glVertex3f(32.8497, 76.0866, 0.0f);
	glVertex3f(27.113, 80.9175, 0.0f);
	glVertex3f(21.0744, 82.1253, 0.0f);
	glVertex3f(-21.0744, 82.1253, 0.0f);
	glVertex3f(-27.113, 80.9175, 0.0f);
	glVertex3f(-32.8497, 76.0866, 0.0f);
	glVertex3f(-36.1709, 70.048, 0.0f);
	glVertex3f(-35.5671, 59.1785, 0.0f);
	glVertex3f(-0.241117, 67.6326, 0.0f);
	glVertex3f(-0.096834, 58.8766, 0.0f);
	glEnd();

	//side rods
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(4);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-33.5671, 59.1785, 0.0f);
	glVertex3f(-39.6023, -64.4754, 0.0f);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(33.5671, 59.1785, 0.0f);
	glVertex3f(39.6023, -64.4754, 0.0f);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-38.4643, -35.4116, 0.0f);
	glVertex3f(38.4643, -35.4116, 0.0f);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-35.6971, 26.7807, 0.0f);
	glVertex3f(-28.1871, -29.7791, 0.0f);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(35.6971, 26.7807, 0.0f);
	glVertex3f(28.1871, -29.7791, 0.0f);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(30.2993, -13.5856, 0.0f);
	glVertex3f(-30.2993, -13.5856, 0.0f);
	glEnd();

	//seat
	glBegin(GL_POLYGON);
	glVertex3f(38.8199, 9.5802, 0.0f);//
	glVertex3f(25.0868, 20.733, 0.0f);
	glVertex3f(-25.0868, 20.733, 0.0f);
	glVertex3f(-38.8199, 9.5802, 0.0f);//
	glEnd();
}

void drawBoy(void)
{
	glLoadIdentity();
	glTranslatef(-0.3f, -0.4f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.2f, 0.2f, 0.5f);

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.733, 0.725, 0.725);
	glVertex3f(-1.44927f, 56.22f, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(9.73336f, 42.6097, 0.0f);
	glVertex3f(11.1312f, 47.1527, 0.0f);
	glVertex3f(11.6554f, 50.4725, 0.0f);
	glVertex3f(8.50026f, 60.0826, 0.0f);
	glVertex3f(4.31677f, 63.4024, 0.0f);
	glVertex3f(-2.45873f, 64.1784, 0.0f);
	glVertex3f(-7.21531f, 62.3541, 0.0f);
	glVertex3f(-11.2341f, 59.9079, 0.0f);
	glVertex3f(-12.9814f, 55.8891, 0.0f);
	glVertex3f(-14.0297f, 52.3945, 0.0f);
	glVertex3f(-14.2045f, 47.5021, 0.0f);
	glVertex3f(-12.8066f, 43.8328, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-7.7395, 37.3679, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glEnd();

	//boy neck
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(6.46189f, 38.4162, 0.0f);
	glVertex3f(-7.7395f, 37.3679f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glEnd();

	//T-Shirt
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 0.675);
	glVertex3f(-0.948761f, 8.13055, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(25.4536f, 16.1265, 0.0f);
	glVertex3f(21.2162f, 24.1124, 0.0f);
	glVertex3f(14.2082f, 29.3277, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(-14.2082f, 29.3277, 0.0f);
	glVertex3f(-21.2162f, 24.1124, 0.0f);
	glVertex3f(-25.4536f, 16.1265, 0.0f);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-19.6912f, -20.2176, 0.0f);
	glVertex3f(-11.0534f, -25.1069, 0.0f);
	glVertex3f(0.029106f, -27.2256, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glEnd();

	//Bottom right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 1.0);
	glVertex3f(22.1941f, -30.3222, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(-0.3f, -25.2256, 0.0f);
	glVertex3f(0.02911f, -41.8936, 0.0f);
	glVertex3f(14.0452f, -39.9378, 0.0f);
	glVertex3f(24.3128f, -35.2115, 0.0f);
	glVertex3f(31.4838f, -25.7588, 0.0f);
	glVertex3f(31.4838f, -11.4167, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glEnd();
	//Bottom left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 1.0);
	glVertex3f(-22.1941f, -30.3222, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glVertex3f(-9.31884f, -24.5958, 0.0f);
	glVertex3f(-0.029106f, -27.2256, 0.0f);
	glVertex3f(-0.02911f, -41.8936, 0.0f);
	glVertex3f(-14.0452f, -39.9378, 0.0f);
	glVertex3f(-24.3128f, -35.2115, 0.0f);
	glVertex3f(-31.4838f, -25.7588, 0.0f);
	glVertex3f(-31.4838f, -11.4167, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(27.4094f, -11.2538, 0.0f);
	glEnd();
	//left hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-27.4094f, -11.2538, 0.0f);
	glEnd();

}

void drawGirl(void)
{
	glLoadIdentity();
	glTranslatef(0.3f, -0.4f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.2f, 0.2f, 0.5f);

	//girl neck
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(6.46189f, 38.4162, 0.0f);
	glVertex3f(-7.7395f, 37.3679f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glEnd();

	//T-Shirt
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 0.675);
	glVertex3f(-0.948761f, 8.13055, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(25.4536f, 16.1265, 0.0f);
	glVertex3f(21.2162f, 24.1124, 0.0f);
	glVertex3f(14.2082f, 29.3277, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(-14.2082f, 29.3277, 0.0f);
	glVertex3f(-21.2162f, 24.1124, 0.0f);
	glVertex3f(-25.4536f, 16.1265, 0.0f);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-19.6912f, -20.2176, 0.0f);
	glVertex3f(-11.0534f, -25.1069, 0.0f);
	glVertex3f(0.029106f, -27.2256, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glEnd();

	//Bottom right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 1.0);
	glVertex3f(22.1941f, -30.3222, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(-0.3f, -27.2256, 0.0f);
	glVertex3f(0.02911f, -41.8936, 0.0f);
	glVertex3f(14.0452f, -39.9378, 0.0f);
	glVertex3f(24.3128f, -35.2115, 0.0f);
	glVertex3f(31.4838f, -25.7588, 0.0f);
	glVertex3f(31.4838f, -11.4167, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glEnd();
	//Bottom left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 1.0);
	glVertex3f(-22.1941f, -30.3222, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glVertex3f(-9.31884f, -24.5958, 0.0f);
	glVertex3f(-0.029106f, -27.2256, 0.0f);
	glVertex3f(-0.02911f, -41.8936, 0.0f);
	glVertex3f(-14.0452f, -39.9378, 0.0f);
	glVertex3f(-24.3128f, -35.2115, 0.0f);
	glVertex3f(-31.4838f, -25.7588, 0.0f);
	glVertex3f(-31.4838f, -11.4167, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(27.4094f, -11.2538, 0.0f);
	glEnd();
	//left hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-27.4094f, -11.2538, 0.0f);
	glEnd();

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.733, 0.725, 0.725);
	glVertex3f(-1.44927f, 56.22f, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(9.73336f, 42.6097, 0.0f);
	glVertex3f(11.1312f, 47.1527, 0.0f);
	glVertex3f(11.6554f, 50.4725, 0.0f);
	glVertex3f(8.50026f, 60.0826, 0.0f);
	glVertex3f(4.31677f, 63.4024, 0.0f);
	glVertex3f(-2.45873f, 64.1784, 0.0f);
	glVertex3f(-7.21531f, 62.3541, 0.0f);
	glVertex3f(-11.2341f, 59.9079, 0.0f);
	glVertex3f(-12.9814f, 55.8891, 0.0f);
	glVertex3f(-14.0297f, 52.3945, 0.0f);
	glVertex3f(-14.2045f, 47.5021, 0.0f);
	glVertex3f(-12.8066f, 43.8328, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-7.7395, 37.3679, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.733, 0.725, 0.725);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-18.0322, 20.4497, 0.0f);
	glVertex3f(-4.79576, 17.3518, 0.0f);
	glVertex3f(6.75088, 17.9151, 0.0f);
	glVertex3f(12.665, 23.5476, 0.0f);
	glEnd();

}


void uninitialize(void)
{
	//*** Function Declarations ***
	void ToggleFullscreen(void);


	//*** Code ***
	if (gbFullscreen == TRUE)//if application is exiting in fullscreen tr ha code follow hoil
	{
		ToggleFullscreen();
		gbFullscreen = FALSE;
	}


	//*** Make The hdc As Current DC ***//
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}


	//*** Destroy Rendering Contex***
	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}


	//*** Release HDC ***
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
		ghdc = NULL;
	}


	//*** Destroy Window ***
	if (ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}


	//*** Close Log File ***
	if (gpFILE)
	{
		fprintf(gpFILE, "Program Ended Successfully\n");
		fclose(gpFILE);
		gpFILE = NULL;
	}
}


