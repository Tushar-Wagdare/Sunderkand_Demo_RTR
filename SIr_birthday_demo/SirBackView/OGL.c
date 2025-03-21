// Windows Header Files
#include <Windows.h> //Win32 API
#include "OGL.h"  // our header file
#include <stdio.h>   // for File IO
#include <stdlib.h>   // for Exit()
#include<math.h>

//OpenGL Header Files
#include <gl/GL.h>
//OpenGL Graphics Library Utility
#include <gl/GLU.h>

// Macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define PI 3.1436

//link with OpenGL Library
#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "glu32.lib")

//*** Structure Declaration For Circle ***//
struct Vertex {
	float x;
	float y;
	float z;
};
struct Color {
	float r;
	float g;
	float b;
};
struct Size {
	float point_size;
	float line_width;
};
struct Center
{
	float xCoordinate;
	float yCoordinate;
};
struct Radious
{
	float xAxis;
	float yAxis;
};
struct Angle
{
	int from;
	int to;
};
struct Circle
{
	struct Color color;
	struct Center center;
	struct Radious radious;
	struct Angle angle;
	struct Size size;
};

//Global Function Declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); //in _far memory

// Global Variables Declarations
FILE *gpFILE = NULL;

HWND ghwnd = NULL;
BOOL gbActive = FALSE;
DWORD dwStyle = 0;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
BOOL gbFullscreen = FALSE;

//OpenGL related Global Variables
HDC ghdc = NULL;
HGLRC ghrc = NULL;

//Demo Variables
//Time
GLfloat hour = 210.0f;
GLfloat minut = 270.0f;
GLdouble second = 270.0f;
double elapsedTime = 0.0;//Elapsed time between two frames
double frameCount = 0.0;//number of frame since the last FPS update
double fps = 0.0;//current FPS value
char titleBuffer[32];
//3D Shapes
GLUquadric* quadric = NULL;
//
GLfloat rotateCeilingFan = 0.0f;
GLfloat xScaleSir = 0.01f;
GLfloat yScaleSir = 0.01f;
GLfloat zScaleSir = 0.0f;

GLfloat xTransSir = -0.2f;
GLfloat yTransSir = 0.001f;
GLfloat zTransSir = -0.1f;


//Entry Point Function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	// Functions Declarations
	int initialise(void);
	void uninitialise(void);
	void display(void);
	void update(void);

	//Local Variable Declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("PSS_Window");
	int iResult = 0;
	BOOL bDone = FALSE;

	// Variables For Centering_of_window
	int ScreenWidth = GetSystemMetrics(SM_CXSCREEN); //1920
	int ScreenHeight = GetSystemMetrics(SM_CYSCREEN); //1080
	int MyWindowWidth = 800;
	int MyWindowHeight = 600;
	int x = (ScreenWidth - MyWindowWidth) / 2;   // 560 
	int y = (ScreenHeight - MyWindowHeight) / 2;   // 240

	//code
	gpFILE = fopen("Log.txt", "w");
	if (gpFILE == NULL)
	{
		MessageBox(NULL, TEXT("Log File Cannot Be Opened"), TEXT("Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	fprintf(gpFILE, "Program Started Successfully...\n");

	//wndclss Ex Initilization
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


	//Register WNDCLASSEX
	RegisterClassEx(&wndclass);

	//Create Window
	hwnd = CreateWindowEx(
		WS_EX_APPWINDOW,
		szAppName,
		TEXT("Pranav_Sawale_Chi_Window!"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		x,
		y,
		WIN_WIDTH,
		WIN_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ghwnd = hwnd;

	//Initilization
	iResult = initialise();
	if (iResult != 0)
	{
		MessageBox(hwnd, TEXT("initialise() Failed"), TEXT("Error"), MB_OK | MB_ICONERROR);
		DestroyWindow(hwnd);
	}

	//Show The Window
	ShowWindow(hwnd, iCmdShow);
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);

	//Paint/Redraw The Window
	//UpdateWindow(hwnd); he nako karan he wm_paint la lagta
#pragma region timer variable

	LARGE_INTEGER frequency;
	LARGE_INTEGER startCounter;
	LARGE_INTEGER endCounter;

	

	//Initializing the frequency and start counter
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&startCounter);

#pragma endregion

	// GAME LOOP
	while (bDone == FALSE)
	{
		QueryPerformanceCounter(&endCounter);
		elapsedTime = (double)(endCounter.QuadPart - startCounter.QuadPart) / (double)(frequency.QuadPart);
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
				// RENDER
				display();

				// UPDATE
				update();

				//Increament frame count
				frameCount += 1.0;

				//is one second has passed, update the fps value and res
				if (elapsedTime >= 0.5)
				{
					fps = frameCount / elapsedTime;
					frameCount = 0.0;
					QueryPerformanceCounter(&startCounter);
				}
				sprintf(titleBuffer, "FPS: %.2f", fps);
				SetWindowText(hwnd, titleBuffer);
			}
		}
	}

	//UnInitilization
	uninitialise();

	return((int)msg.wParam);
}

//Callback Function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//Function Declarations
	void ToggleFullscreen(void);
	void resize(int, int);

	// Code
	switch (iMsg)
	{
	case WM_SETFOCUS:
		gbActive = TRUE;
		break;
	case WM_KILLFOCUS:
		gbActive = FALSE;
		break;
	case WM_SIZE:
		resize(LOWORD(lParam), HIWORD(lParam));
		break;
	case WM_ERASEBKGND:
		return(0);
		break;// simply comment this case
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
		default:
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

// Our function
void ToggleFullscreen(void)
{
	// Local Variable Declarations
	MONITORINFO mi = { sizeof(MONITORINFO) };

	// CODE

	//******************(1)*********************
	if (gbFullscreen == FALSE)
	{	// [A]
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			// a, b, c
			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{   // i>
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
				// ii>
				SetWindowPos(ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, SWP_NOZORDER | SWP_FRAMECHANGED);
			}
		}
		// [B]
		ShowCursor(FALSE);
	}
	//*******************(2)********************
	else
	{   // [A]
		SetWindowPlacement(ghwnd, &wpPrev);
		// [B]
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		// [C]
		SetWindowPos(ghwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED);
		// [D]
		ShowCursor(TRUE);
	}

}

int initialise(void)
{
	//Function Prototype
	void resize(int, int);

	//Function Declarations
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	//Initilization of PIXELFORMATDESCRIPTOR
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

	//2nd step -> Get the DC
	ghdc = GetDC(ghwnd);
	if (ghdc == NULL)
	{
		fprintf(gpFILE, "GetDc() Failed.\n");
		return(-1);
	}

	//3rd step -> choose
	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
	if (iPixelFormatIndex == 0)
	{
		fprintf(gpFILE, "ChoosePixelFormat() Failed.\n");
		return(-2);
	}

	//4th step -> set obtained pixel format
	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFILE, "SetPixelFormat() Failed.\n");
		return(-3);
	}

	//5th step -> tell WGL Bridging Library to give me OpenGl Compatible DC form this DC
	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		fprintf(gpFILE, "wglCreateContext() Failed.\n");
		return(-4);
	}

	//6th step -> make rendering context current
	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFILE, "wglMakeCurrent() Failed.\n");
		return(-5);
	}

	//07 - 2nd step Enabling Depth
	glShadeModel(GL_SMOOTH);//optional

	glClearDepth(1.0f);//Compulasary (sagly bits na 1 kr -> )
	glEnable(GL_DEPTH_TEST);//Compulasory (default = Disable)
	glDepthFunc(GL_LEQUAL);//Compulsory (LEQUAL -> less than or equal to (1.0))

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//Optional

	//Initialize Quadric 
	quadric = gluNewQuadric();

	//*********************HERE OPENGL STARTS*********************
	//Set the clear color of window to blue
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	//WarmUp resize call
	resize(WIN_WIDTH, WIN_HEIGHT);

	return(0);
}

void resize(int width, int height) 
{
	//CODE
	if (height <= 0)
		height = 1;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

}

void display(void)
{
	//Function Prototype
	void SirBackView(void);
	

	//CODE
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//3rd step - Compulasory (clears depth buffer)

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Function Call
	SirBackView();
   


	SwapBuffers(ghdc);
}


void SirBackView(void)
{
	glLoadIdentity();
	glTranslatef(xTransSir, yTransSir, zTransSir);
	glScalef(xScaleSir, yScaleSir, zScaleSir);
	glRotatef(180, 0, 1, 0);
	glLineWidth(1);

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
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(-23.6f, 15.0f, 0.0f);
	glVertex3f(-20.0f, 16.3f, 0.0f);
	glVertex3f(-21.3f, 18.6f, 0.0f);
	glVertex3f(-24.2f, 19.3f, 0.0f);
	glVertex3f(-24.0f, 17.9f, 0.0f);
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

	glLoadIdentity();
	glTranslatef(0.425f + xTransSir, 0.04f + yTransSir, zTransSir);
	glScalef(xScaleSir, yScaleSir, zScaleSir);
	//Left Elbow
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(-53.0f, -18.8f, 0.0f);
	glVertex3f(-37.4f, -24.1f, 0.0f);
	glVertex3f(-33.7f, -25.4f, 0.0f);
	glVertex3f(-37.8f, -18.1f, 0.0f);
	glVertex3f(-44.2f, -15.1f, 0.0f);
	glVertex3f(-52.1f, -15.3f, 0.0f);
	glVertex3f(-56.7f, -13.0f, 0.0f);
	glVertex3f(-58.5f, -11.0f, 0.0f);
	glVertex3f(-60.0f, -12.5f, 0.0f);
	glVertex3f(-60.3f, -14.6f, 0.0f);
	glVertex3f(-59.0f, -16.6f, 0.0f);
	glEnd();
	//Left HAnd
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(-33.7f, -25.4f, 0.0f);
	glVertex3f(-37.4f, -24.1f, 0.0f);
	glVertex3f(-33.5f, -30.0f, 0.0f);
	glVertex3f(-37.8f, -27.4f, 0.0f);
	glVertex3f(-33.3f, -34.3f, 0.0f);
	glVertex3f(-36.0f, -30.8f, 0.0f);
	glVertex3f(-35.4f, -34.8f, 0.0f);
	glVertex3f(-36.9f, -31.9f, 0.0f);
	glVertex3f(-37.9f, -33.4f, 0.0f);
	glVertex3f(-38.9f, -31.4f, 0.0f);
	glEnd();



	//___________________ Right HAnd _______________________//
	glLoadIdentity();
	glTranslatef(0.38f + xTransSir, 0.023f + yTransSir, zTransSir);
	glScalef(xScaleSir, yScaleSir, zScaleSir);
	//Card
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 0.5f);
	glVertex3f(-1.4f, -30.0f, -0.01f);
	glVertex3f(4.4f, -37.6f, -0.01f);
	glVertex3f(9.0f, -33.0f, -0.01f);
	glVertex3f(4.1f, -26.1f, -0.01f);
	glEnd();
	//RRight Shoulder
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.2f, -7.3f, 0.0f);
	glVertex3f(8.2f, -9.1f, 0.0f);
	glVertex3f(9.9f, -9.2f, 0.0f);
	glVertex3f(11.8f, -8.5f, 0.0f);
	glVertex3f(13.8f, -7.1f, 0.0f);
	glVertex3f(15.5f, -5.4f, 0.0f);
	glVertex3f(17.0f, -3.5f, 0.0f);
	glVertex3f(1.1f, 7.0f, 0.0f);
	glVertex3f(0.0f, 8.8f, 0.0f);
	glVertex3f(-0.2f, -7.3f, 0.0f);
	glEnd();
	//Right Elbow
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(12.5f, -15.3f, 0.0f);
	glVertex3f(21.1f, -9.1f, 0.0f);
	glVertex3f(20.f, -6.7f, 0.0f);
	glVertex3f(19.5f, -4.9f, 0.0f);
	glVertex3f(17.0f, -3.5f, 0.0f);
	glVertex3f(15.5f, -5.4f, 0.0f);
	glVertex3f(13.8f, -7.1f, 0.0f);
	glVertex3f(11.8f, -8.5f, 0.0f);
	glVertex3f(9.9f, -9.2f, 0.0f);
	glVertex3f(8.2f, -9.1f, 0.0f);
	glVertex3f(6.4f, -10.8f, 0.0f);
	glVertex3f(-0.5f, -14.3f, 0.0f);
	glVertex3f(-0.3f, -16.6f, 0.0f);
	glVertex3f(1.0f, -19.7f, 0.0f);
	glEnd();
	//Right Palm
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(1.0f, -19.7f, 0.0f);
	glVertex3f(-0.3f, -16.6f, 0.0f);
	glVertex3f(0.5f, -26.0f, 0.0f);
	glVertex3f(-2.2f, -27.2f, 0.0f);
	glVertex3f(3.2f, -28.0f, 0.0f);
	glVertex3f(-0.3f, -29.1f, 0.0f);
	glVertex3f(3.4f, -29.6f, 0.0f);
	glEnd();
	//Right Thumb
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(0.75f, -24.0f, 0.0f);
	glVertex3f(0.35f, -26.0f, 0.0f);
	glVertex3f(2.6f, -24.4f, 0.0f);
	glVertex3f(3.0f, -25.88f, 0.0f);
	glVertex3f(5.0f, -24.07f, 0.0f);
	glEnd();
	



	//Pant Drawing Right
	glLoadIdentity();
	glTranslatef(xTransSir, yTransSir, zTransSir);
	glScalef(xScaleSir, yScaleSir, zScaleSir);
	glRotatef(180, 0, 1, 0);

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

	//Shirt BAse
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
	glEnd();
}


void update(void)
{
	if (zTransSir >= -1.7f)
	{
		zTransSir = zTransSir - 0.00005f;
	}
}

void DrawCircle(GLenum PrimitiveType, struct Circle circle)
{
	//*** Variable Declaration ***
	float a, b;
	float f;


	switch (PrimitiveType)
	{
	case GL_TRIANGLE_FAN:
		glBegin(GL_TRIANGLE_FAN);
		//glColor3f(0.9f, 0.9, 0.9);
		glColor3f(circle.color.r, circle.color.g, circle.color.b);
		glVertex3f(circle.center.xCoordinate, circle.center.yCoordinate, 0.0f);
		for (int i = circle.angle.from; i < circle.angle.to; i++)
		{
			f = (i) * (PI / 180);

			a = cos(f) * circle.radious.xAxis;
			b = sin(f) * circle.radious.yAxis;

			glColor3f(circle.color.r, circle.color.g, circle.color.b);
			glVertex3f(a + circle.center.xCoordinate, b + circle.center.yCoordinate, 0.0f);
		}
		glEnd();
		break;


	case GL_POINTS:
		glPointSize(circle.size.point_size);
		glBegin(GL_POINTS);
		for (int i = circle.angle.from; i < circle.angle.to; i++)
		{
			f = (i) * (PI / 180);

			a = cos(f) * circle.radious.xAxis;
			b = sin(f) * circle.radious.yAxis;

			glColor3f(circle.color.r, circle.color.g, circle.color.b);
			glVertex3f(a + circle.center.xCoordinate, b + circle.center.yCoordinate, 0.0f);
		}
		glEnd();
		break;


	case GL_LINE_LOOP:
		glLineWidth(circle.size.line_width);
		glBegin(GL_LINE_LOOP);
		for (int i = circle.angle.from; i < circle.angle.to; i++)
		{
			f = (i) * (PI / 180);

			a = cos(f) * (circle.radious.xAxis);
			b = sin(f) * (circle.radious.yAxis);

			glColor3f(circle.color.r, circle.color.g, circle.color.b);
			glVertex3f(a + circle.center.xCoordinate, b + circle.center.yCoordinate, 0.0f);
		}
		glEnd();
		break;


	default:
		break;
	}
}

void uninitialise(void)
{
	//Function Declarations
	void ToggleFullscreen(void);

	//CODE
	// if application is exiting in fullscreen
	if (gbFullscreen == TRUE)
	{
		ToggleFullscreen();
		gbFullscreen = FALSE;
	}

	//make the hdc as current dc
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}

	//Delete Rendering Context
	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;
	}

	//Delete the ghdc
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

	//*** PushPop Pointer Release ***
	if (quadric)
	{
		gluDeleteQuadric(quadric);
		quadric = NULL;
	}

	//close the log file
	if (gpFILE)
	{
		fprintf(gpFILE, "Program Ended Successfully...\n");
		fclose(gpFILE);
		gpFILE = NULL;
	}
}



