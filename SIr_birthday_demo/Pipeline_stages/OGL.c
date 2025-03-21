// Windows Header Files
#include <Windows.h> //Win32 API
#include "OGL.h"  // our header file
#include <stdio.h>   // for File IO
#include <stdlib.h>   // for Exit()
#include <math.h>

//OpenGL Header Files
#include <gl/GL.h>
//OpenGL Graphics Library Utility
#include <gl/GLU.h>

// Macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

int winWidth;
int winHeight;


//link with OpenGL Library
#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "glu32.lib")

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


GLUquadric *quadric = NULL;

int gCount = 0;

//
GLint pss_slice  = 2;
GLint pss_stacks = 2;


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

#pragma region TIMER VARIABLES

	LARGE_INTEGER frequency;    //The frequency of the performance counter
	LARGE_INTEGER startCounter; //counter value at start of the frame
	LARGE_INTEGER endCounter;  //counter value at end of frame

	double elapsedTime = 0.0;  //Elapsed time between two frames
	double frameCount = 0.0;  //Number of frames since laste FPS update
	double fps = 0.0;  // Current FPS value

	char titleBuffer[256];
	//

	//Initliazing the frequency and start counter
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&startCounter);

#pragma endregion

	// GAME LOOP
	while (bDone == FALSE)
	{
		QueryPerformanceCounter(&endCounter);
		elapsedTime = (double)((endCounter.QuadPart - startCounter.QuadPart) / (frequency.QuadPart));

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

				// Increment frame count
				frameCount += 1.0;

				// If One second has passed, update FPS value and reset the frame count and counter
				if (elapsedTime >= 0.5)
				{
					fps = frameCount / elapsedTime;
					frameCount = 0.0;
					QueryPerformanceCounter(&startCounter);
				}

				sprintf(titleBuffer, "FPS: %.2f | Dimensions: W(%d) X H(%d)", fps, winWidth, winHeight);
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
		winWidth = LOWORD(lParam);
		winHeight = HIWORD(lParam);
		resize(winWidth, winHeight);
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
	
	case WM_LBUTTONDOWN:
		gCount++;
		break;

	case WM_RBUTTONDOWN:
		gCount--;
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

		case 'h':
			if (pss_slice < 20)
			{
				pss_slice += 1;
				pss_stacks += 1;
			}
			break;

		case 'l':
			if (pss_slice > 0)
			{
				pss_slice -= 1;
				pss_stacks -= 1;
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
	pfd.cDepthBits = 32;    // First Change (compulsory)

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

	// Enabling Depth // Second Change
	glShadeModel(GL_SMOOTH); // (optional) beautification
	glClearDepth(1.0f);      // (compulsory) 
	glEnable(GL_DEPTH_TEST); // (compulsory) out of 8 tests enable depth test only
	glDepthFunc(GL_LEQUAL);  // (compulsory) compare karyana sathi <= with glClearDepth(1.0f)
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // (optional) beautification


	//*********************HERE OPENGL STARTS*********************
	//Set the clear color of window to blue
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Initialise Quadric
	quadric = gluNewQuadric();

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
	void drawBoardTop_VS(void);
	void drawBoardTop_TS(void);
	void drawBoardTop_GS(void);
	void drawBoardTop_R(void);
	void drawBoardTop_FP(void);
	void drawBoardTop_Test(void);
	

	//CODE
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	

	switch (gCount)
	{
	case 1:
		drawBoardTop_VS();
		break;

	case 2:
		drawBoardTop_TS();
		break;
	
	case 3:
		drawBoardTop_GS();
		break;

	case 4:
		drawBoardTop_R();
		break;

	case 5:
		drawBoardTop_FP();
		break;

	case 6:
		drawBoardTop_Test();
		break;
			 
	default:
		break;
	}
	

	SwapBuffers(ghdc);
}

void update(void)
{
	//CODE
	
}



void drawBoardTop_VS(void)
{
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
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

	///////////////////// Vertex Shader Stage ////////////////////////

	
	// Triangle Dots
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	
	glEnable(GL_POINT_SMOOTH);

	glPointSize(7);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-69.753, 46.2316f, 0.0f);
	glVertex3f(-87.5968, 19.466f, 0.0f);
	glVertex3f(-52.7203, 19.466f, 0.0f);
	glEnd();

	// Circle Dots
	glLoadIdentity();
	glTranslatef(-1.1f, -0.4f, -3.0f);
	
	float x       = 0.0f;
	float y       = 0.0f;
	const float r = 0.3f;
	glBegin(GL_POINTS);
	for (float angle = 0.0f; angle <= 360.0; angle+=13)
	{
		x = cos(angle) * r;
		y = sin(angle) * r;

		glVertex3f(x, y, 0.0f);
	}
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	// Rectangle Dots
	glBegin(GL_POINTS);
	glVertex3f(0.0, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();

	// Square Dots
	glBegin(GL_POINTS);
	glVertex3f(-9.80055, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();

	//Dots shape to be drawn in Geometry Shader
	glBegin(GL_POINTS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(31.0915, 31.6322f, 0.0f);
	glVertex3f(31.4295, -22.102f, 0.0f);
	glVertex3f(85.5017, 0.540695f, 0.0f);
	glEnd();

	//AXIS
	// X
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(87.6227, 29.8244f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(89.0194, 29.8082f, 0.0f);
	glVertex3f(87.6227, 31.0425f, 0.0f);
	glVertex3f(87.6227, 28.6226f, 0.0f);
	glEnd();

	//Y
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(73.1148, 43.2817f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(73.1148, 44.9188f, 0.0f);
	glVertex3f(71.7818, 43.2817f, 0.0f);
	glVertex3f(74.3777, 43.2817f, 0.0f);
	glEnd();

	//Z
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(65.8406, 23.3181f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(65.0446, 24.152f, 0.0f);
	glVertex3f(64.514, 22.1431f, 0.0f);
	glVertex3f(66.5608f, 22.4084f, 0.0f);
	glEnd();
}

void drawBoardTop_TS(void)
{
	void drawDodecahedron(void);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
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

	///////////////////// Tessilation Stage ////////////////////////

	
	
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	
	// Cylinder Cone
	glLoadIdentity();
	glTranslatef(-0.92f, 0.6f, -2.5f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0, 0.21, 0.36, pss_slice, pss_stacks);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	
	// Sphere
	glLoadIdentity();
	glTranslatef(-1.1f, -0.4f, -3.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluSphere(quadric, 0.3, pss_slice, pss_stacks);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	// Rectangle Dots
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();
	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Square Dots
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-9.80055, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();
	// Mesh like
	for (float i = -9.93574; i >= -29.199; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-9.80055, i, 0.0f);
		glVertex3f(-30.0776, i, 0.0f);
		glEnd();
	}
	for (float i = -9.80055; i >= -30.0776; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(i, -9.93574, 0.0f);
		glVertex3f(i, -29.199, 0.0f);
		glEnd();
	}

	////Dots shape to be drawn in Geometry Shader
	//glBegin(GL_LINE_LOOP);
	//glColor3f(1.0f, 1.0f, 1.0f);
	//glVertex3f(31.0915, 31.6322f, 0.0f);
	//glVertex3f(31.4295, -22.102f, 0.0f);
	//glVertex3f(85.5017, 0.540695f, 0.0f);
	//glEnd();

	//*********************** AXIS *****************************
	// X
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(87.6227, 29.8244f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(89.0194, 29.8082f, 0.0f);
	glVertex3f(87.6227, 31.0425f, 0.0f);
	glVertex3f(87.6227, 28.6226f, 0.0f);
	glEnd();

	//Y
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(73.1148, 43.2817f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(73.1148, 44.9188f, 0.0f);
	glVertex3f(71.7818, 43.2817f, 0.0f);
	glVertex3f(74.3777, 43.2817f, 0.0f);
	glEnd();

	//Z
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(65.8406, 23.3181f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(65.0446, 24.152f, 0.0f);
	glVertex3f(64.514, 22.1431f, 0.0f);
	glVertex3f(66.5608f, 22.4084f, 0.0f);
	glEnd();

	
}

void drawBoardTop_GS(void)
{
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
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

	///////////////////// Geometry Stage ////////////////////////


	//
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	
	// Cylinder 1
	glLoadIdentity();
	glTranslatef(-0.92f, 0.6f, -2.5f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0, 0.21, 0.36, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Cylinder 2
	glLoadIdentity();
	glTranslatef(-0.3f, 0.6f, -2.5f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0, 0.21, 0.36, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);



	// Sphere 1
	glLoadIdentity();
	glTranslatef(-1.1f, -0.4f, -3.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluSphere(quadric, 0.3, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Sphere 1
	glLoadIdentity();
	glTranslatef(-0.3f, -0.4f, -3.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluSphere(quadric, 0.3, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	// Rectangle 1
	glLoadIdentity();
	glTranslatef(0.5f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();
	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Rectangle 2
	glLoadIdentity();
	glTranslatef(0.5f, -0.4f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();
	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Clipped Rectangle 3 to fail in test
	glLoadIdentity();
	glTranslatef(1.2f, -0.4f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();
	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Square 1
	glLoadIdentity();
	glTranslatef(0.5f, -0.2f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-9.80055, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();
	// Mesh like
	for (float i = -9.93574; i >= -29.199; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-9.80055, i, 0.0f);
		glVertex3f(-30.0776, i, 0.0f);
		glEnd();
	}
	for (float i = -9.80055; i >= -30.0776; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(i, -9.93574, 0.0f);
		glVertex3f(i, -29.199, 0.0f);
		glEnd();
	}

	// Square 2
	glLoadIdentity();
	glTranslatef(0.8f, -0.2f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-9.80055, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();
	// Mesh like
	for (float i = -9.93574; i >= -29.199; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-9.80055, i, 0.0f);
		glVertex3f(-30.0776, i, 0.0f);
		glEnd();
	}
	for (float i = -9.80055; i >= -30.0776; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(i, -9.93574, 0.0f);
		glVertex3f(i, -29.199, 0.0f);
		glEnd();
	}




	//*********************** AXIS *****************************
	glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, -3.0f);
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	// X
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(87.6227, 29.8244f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(89.0194, 29.8082f, 0.0f);
	glVertex3f(87.6227, 31.0425f, 0.0f);
	glVertex3f(87.6227, 28.6226f, 0.0f);
	glEnd();

	//Y
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(73.1148, 43.2817f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(73.1148, 44.9188f, 0.0f);
	glVertex3f(71.7818, 43.2817f, 0.0f);
	glVertex3f(74.3777, 43.2817f, 0.0f);
	glEnd();

	//Z
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(65.8406, 23.3181f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(65.0446, 24.152f, 0.0f);
	glVertex3f(64.514, 22.1431f, 0.0f);
	glVertex3f(66.5608f, 22.4084f, 0.0f);
	glEnd();


}

void drawBoardTop_R(void)
{
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
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

	///////////////////// Rasterizer Stage ////////////////////////


	//
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);

	// Cylinder 1
	glLoadIdentity();
	glTranslatef(-0.92f, 0.6f, -2.5f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0, 0.21, 0.36, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Cylinder 2
	glLoadIdentity();
	glTranslatef(-0.3f, 0.6f, -2.5f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0, 0.21, 0.36, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);



	// Sphere 1
	glLoadIdentity();
	glTranslatef(-1.1f, -0.4f, -3.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluSphere(quadric, 0.3, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Sphere 1
	glLoadIdentity();
	glTranslatef(-0.3f, -0.4f, -3.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluSphere(quadric, 0.3, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	// Rectangle 1
	glLoadIdentity();
	glTranslatef(0.5f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();
	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Rectangle 2
	glLoadIdentity();
	glTranslatef(0.5f, -0.4f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();
	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Clipped Rectangle 3 to fail in test
	glLoadIdentity();
	glTranslatef(1.2f, -0.4f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();
	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Square 1
	glLoadIdentity();
	glTranslatef(0.5f, -0.2f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-9.80055, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();
	// Mesh like
	for (float i = -9.93574; i >= -29.199; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-9.80055, i, 0.0f);
		glVertex3f(-30.0776, i, 0.0f);
		glEnd();
	}
	for (float i = -9.80055; i >= -30.0776; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(i, -9.93574, 0.0f);
		glVertex3f(i, -29.199, 0.0f);
		glEnd();
	}

	// Square 2
	glLoadIdentity();
	glTranslatef(0.8f, -0.2f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-9.80055, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();
	// Mesh like
	for (float i = -9.93574; i >= -29.199; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-9.80055, i, 0.0f);
		glVertex3f(-30.0776, i, 0.0f);
		glEnd();
	}
	for (float i = -9.80055; i >= -30.0776; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(i, -9.93574, 0.0f);
		glVertex3f(i, -29.199, 0.0f);
		glEnd();
	}




	//*********************** AXIS *****************************
	glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, -3.0f);
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	// X
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(87.6227, 29.8244f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(89.0194, 29.8082f, 0.0f);
	glVertex3f(87.6227, 31.0425f, 0.0f);
	glVertex3f(87.6227, 28.6226f, 0.0f);
	glEnd();

	//Y
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(73.1148, 43.2817f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(73.1148, 44.9188f, 0.0f);
	glVertex3f(71.7818, 43.2817f, 0.0f);
	glVertex3f(74.3777, 43.2817f, 0.0f);
	glEnd();

	//Z NO z axis in rasterizer
	/*glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(65.8406, 23.3181f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(65.0446, 24.152f, 0.0f);
	glVertex3f(64.514, 22.1431f, 0.0f);
	glVertex3f(66.5608f, 22.4084f, 0.0f);
	glEnd();*/


}

void drawBoardTop_FP(void)
{
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
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

	///////////////////// Fragment Process Stage ////////////////////////


	//
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);

	// Cylinder 1
	glLoadIdentity();
	glTranslatef(-0.92f, 0.6f, -2.5f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0, 0.21, 0.36, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Cylinder 2
	glLoadIdentity();
	glTranslatef(-0.3f, 0.6f, -2.5f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 1.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0, 0.21, 0.36, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);



	// Sphere 1
	glLoadIdentity();
	glTranslatef(-1.1f, -0.4f, -3.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluSphere(quadric, 0.3, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Sphere 1
	glLoadIdentity();
	glTranslatef(-0.3f, -0.4f, -3.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 1.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluSphere(quadric, 0.3, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	// Rectangle 1
	glLoadIdentity();
	glTranslatef(0.5f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 47.0428f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();


	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Rectangle 2
	glLoadIdentity();
	glTranslatef(0.5f, -0.4f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 47.0428f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();

	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Clipped Rectangle 3 to fail in test
	glLoadIdentity();
	glTranslatef(1.2f, -0.4f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();
	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Square 1
	glLoadIdentity();
	glTranslatef(0.5f, -0.2f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-9.80055, -9.93574f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();

	// Mesh like
	for (float i = -9.93574; i >= -29.199; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-9.80055, i, 0.0f);
		glVertex3f(-30.0776, i, 0.0f);
		glEnd();
	}
	for (float i = -9.80055; i >= -30.0776; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(i, -9.93574, 0.0f);
		glVertex3f(i, -29.199, 0.0f);
		glEnd();
	}

	// Square 2
	glLoadIdentity();
	glTranslatef(0.8f, -0.2f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-9.80055, -9.93574f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();

	// Mesh like
	for (float i = -9.93574; i >= -29.199; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-9.80055, i, 0.0f);
		glVertex3f(-30.0776, i, 0.0f);
		glEnd();
	}
	for (float i = -9.80055; i >= -30.0776; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(i, -9.93574, 0.0f);
		glVertex3f(i, -29.199, 0.0f);
		glEnd();
	}




	//*********************** AXIS *****************************
	glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, -3.0f);
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	// X
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(87.6227, 29.8244f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(89.0194, 29.8082f, 0.0f);
	glVertex3f(87.6227, 31.0425f, 0.0f);
	glVertex3f(87.6227, 28.6226f, 0.0f);
	glEnd();

	//Y
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(73.1148, 43.2817f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(73.1148, 44.9188f, 0.0f);
	glVertex3f(71.7818, 43.2817f, 0.0f);
	glVertex3f(74.3777, 43.2817f, 0.0f);
	glEnd();

	//Z NO z axis in rasterizer
	/*glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(65.8406, 23.3181f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(65.0446, 24.152f, 0.0f);
	glVertex3f(64.514, 22.1431f, 0.0f);
	glVertex3f(66.5608f, 22.4084f, 0.0f);
	glEnd();*/


}

void drawBoardTop_Test(void)
{
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
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

	///////////////////// Tests Stage ////////////////////////


	//
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);

	// Cylinder 1
	glLoadIdentity();
	glTranslatef(-0.92f, 0.6f, -2.5f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0, 0.21, 0.36, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Cylinder 2
	glLoadIdentity();
	glTranslatef(-0.3f, 0.6f, -2.5f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 1.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0, 0.21, 0.36, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);



	// Sphere 1
	glLoadIdentity();
	glTranslatef(-1.1f, -0.4f, -3.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluSphere(quadric, 0.3, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Sphere 1
	glLoadIdentity();
	glTranslatef(-0.3f, -0.4f, -3.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 1.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluSphere(quadric, 0.3, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	// Rectangle 1
	glLoadIdentity();
	glTranslatef(0.5f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 47.0428f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();


	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Rectangle 2
	glLoadIdentity();
	glTranslatef(0.5f, -0.4f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 47.0428f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();

	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Clipped Rectangle 3 to fail in test
	//glLoadIdentity();
	//glTranslatef(1.2f, -0.4f, -1.9f);
	//glScalef(0.01f, 0.01f, 0.01f);
	//glScalef(1.0f, 1.0f, 0.01f);

	//glBegin(GL_LINE_LOOP);
	//glColor3f(1.0f, 0.0f, 0.0f);
	//glVertex3f(0.0, 47.0428f, 0.0f);
	//glVertex3f(-40.5541, 47.0428f, 0.0f);
	//glVertex3f(-40.5541, 19.466f, 0.0f);
	//glVertex3f(0.0, 19.466f, 0.0f);
	//glEnd();
	//glLineWidth(1);
	//// Mesh like
	//for (float i = 19.466; i < 47.0428; i += 1.51536)
	//{
	//	glBegin(GL_LINES);
	//	glVertex3f(0.0, i, 0.0f);
	//	glVertex3f(-40.5541, i, 0.0f);
	//	glEnd();
	//}
	//for (float i = 0; i > -40.5541; i -= 1.51536)
	//{
	//	glBegin(GL_LINES);
	//	glVertex3f(i, 19.466, 0.0f);
	//	glVertex3f(i, 47.0428, 0.0f);
	//	glEnd();
	//}

	// Square 1
	glLoadIdentity();
	glTranslatef(0.5f, -0.2f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-9.80055, -9.93574f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();

	// Mesh like
	for (float i = -9.93574; i >= -29.199; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-9.80055, i, 0.0f);
		glVertex3f(-30.0776, i, 0.0f);
		glEnd();
	}
	for (float i = -9.80055; i >= -30.0776; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(i, -9.93574, 0.0f);
		glVertex3f(i, -29.199, 0.0f);
		glEnd();
	}

	// Square 2
	glLoadIdentity();
	glTranslatef(0.8f, -0.2f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-9.80055, -9.93574f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();

	// Mesh like
	for (float i = -9.93574; i >= -29.199; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-9.80055, i, 0.0f);
		glVertex3f(-30.0776, i, 0.0f);
		glEnd();
	}
	for (float i = -9.80055; i >= -30.0776; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(i, -9.93574, 0.0f);
		glVertex3f(i, -29.199, 0.0f);
		glEnd();
	}




	//*********************** AXIS *****************************
	glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, -3.0f);
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	// X
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(87.6227, 29.8244f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(89.0194, 29.8082f, 0.0f);
	glVertex3f(87.6227, 31.0425f, 0.0f);
	glVertex3f(87.6227, 28.6226f, 0.0f);
	glEnd();

	//Y
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(73.1148, 43.2817f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(73.1148, 44.9188f, 0.0f);
	glVertex3f(71.7818, 43.2817f, 0.0f);
	glVertex3f(74.3777, 43.2817f, 0.0f);
	glEnd();

	//Z NO z axis in rasterizer
	/*glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(65.8406, 23.3181f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(65.0446, 24.152f, 0.0f);
	glVertex3f(64.514, 22.1431f, 0.0f);
	glVertex3f(66.5608f, 22.4084f, 0.0f);
	glEnd();*/


}

//void drawBoardTop_GS(void)
//{
//	glLoadIdentity();
//	glTranslatef(0.0f, 0.0f, -3.0f);
//	// border
//	glBegin(GL_QUADS);
//	glColor3f(0.4f, 0.2f, 0.0f);
//	glVertex3f(-1.55f, 0.85f, 0.0f);
//	glVertex3f(-1.55f, -0.85f, 0.0f);
//	glVertex3f(1.55f, -0.85f, 0.0f);
//	glVertex3f(1.55f, 0.85f, 0.0f);
//	glEnd();
//
//
//	// main screen
//	glBegin(GL_QUADS);
//	glColor3f(0.87f, 0.721f, 0.529f);
//	glVertex3f(-1.5f, 0.8f, 0.0f);
//	glVertex3f(-1.5f, -0.8f, 0.0f);
//	glVertex3f(1.5f, -0.8f, 0.0f);
//	glVertex3f(1.5f, 0.8f, 0.0f);
//	glEnd();
//
//	///////////////////// Vertex Shader Stage ////////////////////////
//
//
//	// Triangle Dots
//	glLoadIdentity();
//	glTranslatef(0.0f, 0.0f, -1.9f);
//	glScalef(0.01f, 0.01f, 0.01f);
//
//	glEnable(GL_POINT_SMOOTH);
//
//	glPointSize(7);
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glVertex3f(-69.753, 46.2316f, 0.0f);
//	glVertex3f(-87.5968, 19.466f, 0.0f);
//	glVertex3f(-52.7203, 19.466f, 0.0f);
//	glEnd();
//
//	// Circle Dots
//	glLoadIdentity();
//	glTranslatef(-1.1f, -0.4f, -3.0f);
//
//	float x = 0.0f;
//	float y = 0.0f;
//	const float r = 0.3f;
//	glBegin(GL_POINTS);
//	for (float angle = 0.0f; angle <= 360.0; angle += 13)
//	{
//		x = cos(angle) * r;
//		y = sin(angle) * r;
//
//		glVertex3f(x, y, 0.0f);
//	}
//	glEnd();
//
//	glLoadIdentity();
//	glTranslatef(0.0f, 0.0f, -1.9f);
//	glScalef(0.01f, 0.01f, 0.01f);
//	// Rectangle Dots
//	glBegin(GL_LINE_LOOP);
//	glVertex3f(0.0, 47.0428f, 0.0f);
//	glVertex3f(-40.5541, 47.0428f, 0.0f);
//	glVertex3f(-40.5541, 19.466f, 0.0f);
//	glVertex3f(0.0, 19.466f, 0.0f);
//	glEnd();
//
//	// Square Dots
//	glBegin(GL_LINE_LOOP);
//	glVertex3f(-9.80055, -9.93574f, 0.0f);
//	glVertex3f(-30.0776, -9.93574f, 0.0f);
//	glVertex3f(-30.0776, -29.199f, 0.0f);
//	glVertex3f(-9.80055, -29.199f, 0.0f);
//	glEnd();
//
//	//Dots shape to be drawn in Geometry Shader
//	glBegin(GL_POINTS);
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glVertex3f(31.0915, 31.6322f, 0.0f);
//	glVertex3f(31.4295, -22.102f, 0.0f);
//	glVertex3f(85.5017, 0.540695f, 0.0f);
//	glEnd();
//
//	// REctangle
//	glBegin(GL_LINE_LOOP);
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glVertex3f(59.7356, 0.0f, 0.0f);
//	glVertex3f(9.49479, 0.0f, 0.0f);
//	glVertex3f(9.49479, -29.199f, 0.0f);
//	glVertex3f(59.7356, -29.199f, 0.0f);
//	glEnd();
//
//	//Square
//	glBegin(GL_LINE_LOOP);
//	glVertex3f(19.7248, 19.466f, 0.0f);
//	glVertex3f(40.1849, 19.466f, 0.0f);
//	glVertex3f(40.1849, 39.5561f, 0.0f);
//	glVertex3f(19.7248, 39.5561f, 0.0f);
//	glEnd();
//
//
//	//AXIS
//	// X
//	glEnable(GL_LINE_SMOOTH);
//	glLineWidth(1);
//	glBegin(GL_LINES);
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glVertex3f(73.1148, 29.8244f, 0.0f);
//	glVertex3f(87.6227, 29.8244f, 0.0f);
//	glEnd();
//	glBegin(GL_TRIANGLES);
//	glVertex3f(89.0194, 29.8082f, 0.0f);
//	glVertex3f(87.6227, 31.0425f, 0.0f);
//	glVertex3f(87.6227, 28.6226f, 0.0f);
//	glEnd();
//
//	//Y
//	glBegin(GL_LINES);
//	glColor3f(0.0f, 1.0f, 0.0f);
//	glVertex3f(73.1148, 29.8244f, 0.0f);
//	glVertex3f(73.1148, 43.2817f, 0.0f);
//	glEnd();
//	glBegin(GL_TRIANGLES);
//	glVertex3f(73.1148, 44.9188f, 0.0f);
//	glVertex3f(71.7818, 43.2817f, 0.0f);
//	glVertex3f(74.3777, 43.2817f, 0.0f);
//	glEnd();
//
//	//Z
//	glBegin(GL_LINES);
//	glColor3f(0.0f, 0.0f, 1.0f);
//	glVertex3f(73.1148, 29.8244f, 0.0f);
//	glVertex3f(65.8406, 23.3181f, 0.0f);
//	glEnd();
//	glBegin(GL_TRIANGLES);
//	glVertex3f(65.0446, 24.152f, 0.0f);
//	glVertex3f(64.514, 22.1431f, 0.0f);
//	glVertex3f(66.5608f, 22.4084f, 0.0f);
//	glEnd();
//}


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

	//Delete quadric
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
