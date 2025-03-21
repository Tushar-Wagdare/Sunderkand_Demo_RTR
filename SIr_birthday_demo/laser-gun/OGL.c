// Windows header files
#include <windows.h> //Win32 SDK API
#include <stdio.h> //for FileIO
#include <stdlib.h> //for Exit

//OpenGL Header Files
#include<gl/GL.h> // GL.h hi file Smita chya laptop chya C:\Program Files (x86)\Windows Kits\10\Include\10.0.22000.0\um\gl ya path la ahe

#include<GL/glu.h>

#include "OGL.h"


//Macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

//Link with openGL library
#pragma comment(lib, "OpenGL32.lib") //Hi lib sangte ki me OpenGL program karnar asun..........

#pragma comment(lib, "glu32.lib") //Mala opengl utility (GLU) function vapraych ahe

// Global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


//Global variable declarations
DWORD dwStyle = 0;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
BOOL gbFullscreen = FALSE;
FILE* gpFile = NULL;

HWND ghwnd = NULL;
BOOL gbActive = FALSE;

//OpenGL related variables
HDC ghdc = NULL;
HGLRC ghrc = NULL;




// Entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hprevInstance, LPSTR lpszCmdLine, int iCmdShow) //windows.h madhe '#pragma argused' ha macro ahe tyamule hprevInstance ani lpszCmdLine he vaparla nahi tari error ala nahi. Pan Microsoft backward compatibility sathi ajunhi te code madhe hprevInstance ani lpszCmdLine vapartat.
{

	//Window centering
	int screen_width = GetSystemMetrics(SM_CXSCREEN);
	int screen_height = GetSystemMetrics(SM_CYSCREEN);

	int window_width = 800;
	int window_height = 600;

	int window_x = (screen_width - window_width) / 2;
	int window_y = (screen_height - window_height) / 2;

	//Functions declarations >>>> Hi apli functions ahet
	int initialize(void);
	void uninitialize(void);
	void display(void);
	void update(void);

	// local variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("Smita_Patil_chi_Window!"); //He process ch naav ahe
	int iResult = 0;
	BOOL bDone = FALSE;


	// code
	gpFile = fopen("Log.txt", "w");
	if (gpFile == NULL)
	{
		MessageBox(NULL, TEXT("Log File Cannot Be Opened"), TEXT("Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	fprintf(gpFile, "Program Started Successfully!\n");

	// WNDCLASSEX declarations
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));

	// Register WNDCLASSEX
	RegisterClassEx(&wndclass);

	// Create the window
	hwnd = CreateWindowEx(WS_EX_APPWINDOW,
		szAppName,
		TEXT("SMITA_PATIL"), //He window ch naav ahe
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		window_x,
		window_y,
		WIN_WIDTH,
		WIN_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ghwnd = hwnd;

	//Initialization
	iResult = initialize();

	if (iResult != 0)
	{
		MessageBox(hwnd, TEXT("initialize Function Failed"), TEXT("Error"), MB_OK | MB_ICONERROR);
		DestroyWindow(hwnd);
	}

	// Show the window
	ShowWindow(hwnd, iCmdShow);

	// Paint/redraw the window
	//UpdateWindow(hwnd); >>> Removed because it was used for WM_PAINT and WM_PAINT is not used for real time rendering

	SetForegroundWindow(hwnd);
	SetFocus(hwnd);


	// Game Loop >>>>>> Hi loop aplyala ashichi ashi DirectX madhe vapraychi ahe
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
				//Render
				display();

				// Update
				update();
			}
		}
	}

	//Uninitialize
	uninitialize();

	return((int)msg.wParam);

}

// Call back function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//Local function declarations
	void ToggleFullscreen(void);
	void resize(int, int);

	// code
	switch (iMsg)
	{
	case WM_SETFOCUS:
		gbActive = TRUE;
		break;

	case WM_KILLFOCUS:
		gbActive = FALSE;
		break;

	case WM_SIZE:
		resize(LOWORD(lParam), HIWORD(lParam)); //He height ani width sangta
		break;

	case WM_ERASEBKGND:
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
	//Local variable declarations 
	MONITORINFO mi = { sizeof(MONITORINFO) };
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
	//function declarations
	// Code
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
	void resize(int, int);

	//Initialization of PIXELFORMATDESCRIPTOR
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;
	pfd.cDepthBits = 32;//1st change of depth - 3D

	//Get the DC
	ghdc = GetDC(ghwnd);
	if (ghdc == NULL)
	{
		fprintf(gpFile, "GetDC() Failed/n");
		return(-1);
	}

	//Tell OS 
	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	if (iPixelFormatIndex == 0)
	{
		fprintf(gpFile, "ChoosePixelFormat() Failed\n");
		return(-2);
	}

	//Set the obtained pixel format
	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFile, "SetPixelFormat() Failed\n");
		return(-3);
	}

	//Tell windows graphics (bridging) library to give me openGL compatible context from this device context
	//Create openGL context from device context
	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		fprintf(gpFile, "wglCreateContext() Failed\n");
		return(-4);
	}

	//Now ghdc will end its role and will give control to ghrc to do further drawing
	//Make rendering context current
	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFile, "wglMakeCurrent() Failed\n");
		return(-5);
	}

	//2nd step of Depth - 3D (3 compulsory - 2 beautification)
	//Enabling Depth
	glShadeModel(GL_SMOOTH); // Jevha pan apan color karu or shade karu, teva to shade smooth kar - Beautification

	glClearDepth(1.0f); //Compulsory step : Depth buffer la clear karayla glClearDepth() vapar ani depth buffer madhlya saglya buffers na 1 bit kar.

	glEnable(GL_DEPTH_TEST); //Compulsory: 8 test paiki hi ek test - GL_DEPTH_TEST enable kar. Ya tests by default disabled astat.

	glDepthFunc(GL_LEQUAL); //Compulsory: glDepthFunc -> Depth sathi konta function vaparu? - LEQUAL (L less than Equal to) with 1.0f (from glClearDepth()).

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); //Optional: Beautification - Jevha Depth enable karta, tevha corner chya goshti circular na dista elliptical distat. This is not good. Mhanun correction kartana te nicest kar.

	// Set the clear color of window to blue.
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	resize(WIN_WIDTH, WIN_HEIGHT);

	return(0);
}

void resize(int width, int height)
{
	// Code
	if (height <= 0)
		height = 1;

	glMatrixMode(GL_PROJECTION); //Current Transformation Matrix
	glLoadIdentity();

	gluPerspective(45.0f, 
		(GLfloat)width / (GLfloat)height, 
		0.1f, 
		100.0f); //45.0f is fovy *** (GLfloat)width / (GLfloat)height is ratio **** 0.1f is near, 100.0f is far.. near and far are not hard coded, they are standard.

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void display(void) //He call kela jaen Game Loop madhe
{
	// Code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //3rd test : Compulsory for Depth 3D.

	glMatrixMode(GL_MODELVIEW); //Current Transformation Matrix
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -3.0f);
	glScalef(0.008f, 0.008f, 0.008f);

	//Gun body main
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.651, 0.718, 0.816);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(13.6288f, 20.4432f, 0.0f);
	glVertex3f(-5.06714f, 8.38697f, 0.0f);
	glVertex3f(-21.8411f, -2.97039f, 0.0f);
	glVertex3f(-24.462f, -4.8924f, 0.0f);
	glVertex3f(-26.2093f, -7.86279f, 0.0f);
	glVertex3f(-26.9082f, -11.3574f, 0.0f);
	glVertex3f(-25.5104f, -15.9003f, 0.0f);

	glColor3f(0.898, 0.961, 0.992);
	glVertex3f(-23.2389f, -19.3949f, 0.0f);
	glVertex3f(-19.3949f, -21.4916f, 0.0f);
	glVertex3f(-14.153f, -20.7927f, 0.0f);
	glVertex3f(-10.2574f, -18.3882f, 0.0f);
	glVertex3f(-6.63969f, -15.7256f, 0.0f);
	glVertex3f(2.09674f, -9.26062f, 0.0f);
	glVertex3f(6.1155f, -6.46496f, 0.0f);
	glVertex3f(12.0563f, -1.39783f, 0.0f);
	glVertex3f(23.2389f, 6.81441f, 0.0f);
	glVertex3f(21.8729f, 8.69467f, 0.0f);
	glVertex3f(20.2884f, 10.166f, 0.0f);
	glVertex3f(18.3465f, 13.1046f, 0.0f);

	glColor3f(0.651, 0.718, 0.816);
	glVertex3f(16.4245f, 15.5508f, 0.0f);
	glVertex3f(15.2014f, 17.997f, 0.0f);
	glVertex3f(13.6288f, 20.4432f, 0.0f);
	glEnd();

	//circle
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.239, 0.467, 0.675);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.92404f, 3.28219f, 0.0f);
	glVertex3f(-1.81086f, 3.84809f, 0.0f);
	glVertex3f(-2.94265f, 0.0f, 0.0f);
	glVertex3f(-0.565895f, -2.60312f, 0.0f);
	glVertex3f(2.94265f, -0.565895f, 0.0f);
	glVertex3f(1.92404f, 3.28219f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.239, 0.467, 0.675);
	glVertex3f(-12.7295f, -7.75772f, 0.0f);
	glVertex3f(-7.86279f, -0.17473f, 0.0f);
	glVertex3f(-21.1422f, -8.5617f, 0.0f);
	glVertex3f(-21.8411f, -12.0563f, 0.0f);
	glVertex3f(-20.4433f, -14.6772f, 0.0f);
	glVertex3f(-16.774f, -15.3761f, 0.0f);
	glVertex3f(-4.01876f, -5.59132f, 0.0f);
	glVertex3f(-7.86279f, -0.17473f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.239, 0.467, 0.675);
	glVertex3f(-5.06714f, 8.38697f, 0.0f);
	glVertex3f(-8.56171f, 14.153f, 0.0f);
	glVertex3f(-21.1422f, 5.06713f, 0.0f);
	glVertex3f(-22.54f, 2.97038f, 0.0f);
	glVertex3f(-22.7147f, 0.524183f, 0.0f);
	glVertex3f(-21.8411f, -2.97039f, 0.0f);
	glEnd();

	//handle
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.651, 0.718, 0.816);
	glVertex3f(-0.071289f, -21.1045f, 0.0f);
	glVertex3f(6.1155f, -6.46496f, 0.0f);
	glVertex3f(2.09674f, -9.26062f, 0.0f);
	glVertex3f(-6.63969f, -15.7256f, 0.0f);
	glVertex3f(-10.2574f, -18.3882f, 0.0f);
	glVertex3f(-3.84404f, -40.0129f, 0.0f);
	glVertex3f(12.231f, -28.4808f, 0.0f);
	glVertex3f(6.1155f, -6.46496f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.929, 0.388, 0.216);
	glVertex3f(2.09674f, -9.26062f, 0.0f);
	glVertex3f(-6.63969f, -15.7256f, 0.0f);
	glVertex3f(-5.30341f, -19.5378f, 0.0f);
	glVertex3f(3.50449f, -13.8234f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.761, 0.306, 0.22);
	glVertex3f(4.01673f, -16.3688f, 0.0f);
	glVertex3f(-4.39798f, -22.0278f, 0.0f);
	glVertex3f(-3.10341f, -25.4687f, 0.0f);
	glVertex3f(5.14852f, -19.7642f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.929, 0.388, 0.216);
	glVertex3f(5.72456f, -21.9601f, 0.0f);
	glVertex3f(-2.87705f, -27.5059f, 0.0f);
	glVertex3f(-1.58248f, -32.1997f, 0.0f);
	glVertex3f(6.94743f, -25.9412f, 0.0f);
	glEnd();

	//trigger
	glLineWidth(2.0f);
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.651, 0.718, 0.816);
	glVertex3f(12.0563f, -1.39783f, 0.0f);
	glVertex3f(6.1155f, -6.46496f, 0.0f);
	glVertex3f(8.5617f, -12.5805f, 0.0f);
	glVertex3f(11.1826f, -11.3574f, 0.0f);
	glVertex3f(13.2794f, -9.26062f, 0.0f);
	glVertex3f(14.3277f, -5.76604f, 0.0f);
	glVertex3f(13.9783f, -3.14512f, 0.0f);
	glEnd();

	glLineWidth(2.5f);
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINES);
	glColor3f(0.651, 0.718, 0.816);
	glVertex3f(6.1155f, -6.46496f, 0.0f);
	glVertex3f(11.0079f, -6.46496f, 0.0f);
	glEnd();

	glLineWidth(2.5f);
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINES);
	glColor3f(0.157, 0.259, 0.408);
	glVertex3f(16.4245f, 15.5508f, 0.0f);
	glVertex3f(8.21224f, 9.95953f, 0.0f);
	glEnd();

	glLineWidth(2.5f);
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINES);
	glColor3f(0.157, 0.259, 0.408);
	glVertex3f(18.3465f, 13.1046f, 0.0f);
	glVertex3f(6.98914f, 4.71767f, 0.0f);
	glEnd();

	glLineWidth(2.5f);
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINES);
	glColor3f(0.157, 0.259, 0.408);
	glVertex3f(20.2884f, 10.166f, 0.0f);
	glVertex3f(12.4057f, 4.54294f, 0.0f);
	glEnd();

	//front
	glBegin(GL_POLYGON);
	glColor3f(0.373, 0.416, 0.471);
	glVertex3f(20.2685f, 20.2685f, 0.0f);
	glVertex3f(15.2014f, 17.997f, 0.0f);
	glVertex3f(18.3465f, 13.1046f, 0.0f);
	glVertex3f(21.8729f, 8.69467f, 0.0f);
	glVertex3f(25.5104f, 12.9299f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.651, 0.718, 0.816);
	glVertex3f(25.5104f, 26.7335f, 0.0f);
	glVertex3f(17.997f, 23.4136f, 0.0f);
	glVertex3f(20.2685f, 20.2685f, 0.0f);

	glColor3f(0.898, 0.961, 0.992);
	glVertex3f(25.5104f, 12.9299f, 0.0f);
	glVertex3f(27.6071f, 10.1343f, 0.0f);
	glVertex3f(32.849f, 15.9003f, 0.0f);
	glVertex3f(28.584f, 20.8443f, 0.0f);
	glEnd();

	glLineWidth(2.5f);
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINES);
	glColor3f(0.157, 0.259, 0.408);
	glVertex3f(41.9349f, 30.228f, 0.0f);
	glVertex3f(29.0367f, 21.0707f, 0.0f);
	glEnd();

	glLineWidth(2.5f);
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINES);
	glColor3f(0.157, 0.259, 0.408);
	glVertex3f(35.6446f, 18.1718f, 0.0f);
	glVertex3f(28.8302f, 28.306f, 0.0f);
	glEnd();

	glLineWidth(2.5f);
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINES);
	glColor3f(0.157, 0.259, 0.408);
	glVertex3f(38.2656f, 21.4916f, 0.0f);
	glVertex3f(32.849f, 29.8786f, 0.0f);
	glEnd();

	glLineWidth(2.5f);
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINES);
	glColor3f(0.157, 0.259, 0.408);
	glVertex3f(41.4107f, 24.8115f, 0.0f);
	glVertex3f(36.693f, 31.1017f, 0.0f);
	glEnd();

	SwapBuffers(ghdc);
}

void update(void) //ithe update cha code tevach yeto jeva animation karaych asta
{
	// Code

}

void uninitialize(void)
{
	//Function declarations
	void ToggleFullscreen(void);

	// Code
	// If application is exitting in fullscreen
	if (gbFullscreen == TRUE)
	{
		ToggleFullscreen();
		gbFullscreen = FALSE;
	}

	//Make the HDC as current DC
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}

	// Destroy or delete Rendering context
	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	// Release the HDC
	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
	}

	// destroy window
	if (ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}

	// Close the log file
	if (gpFile)
	{
		fprintf(gpFile, "Program Ended Successfully!\n");
		fclose(gpFile);
		gpFile = NULL;
	}
}

