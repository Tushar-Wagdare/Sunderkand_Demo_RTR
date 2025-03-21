#include<Windows.h> // Windows header files 
#include "OGL.h"
#include<stdlib.h> // For exit
#include<stdio.h> // For file IO (input output)

// OpenGL header files
#include<gl/GL.h>
#include<gl/GLU.h>

// MACROS

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// Link with OpenGL libraray

#pragma comment(lib,"OpenGL32.lib")
#pragma comment(lib, "glu32.lib")

//global function delaration



LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); // Entry point function

// global variable declaration
FILE* gpFile = NULL;

HWND ghwnd = NULL;
BOOL gbActive = FALSE;

DWORD dwStyle = 0;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
BOOL gbFullscreen = FALSE;

//OpenGL related Global variables
HDC ghdc = NULL;   // DC
HGLRC ghrc = NULL; // rendating context


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCnmdLine, int iCmdShow) // function defition
{

	// Function Declarations
	
	int initialize(void);
	void uninitialized(void);
	void display(void);
	void update(void);

	// Local variable Declarations

	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("VBWindow");
	int iResult = 0;
	BOOL bDone = FALSE;

	gpFile = fopen("Log.txt", "w");
	if (gpFile == NULL)
	{
		MessageBox(NULL, TEXT("Log file cannot be open!!!"), TEXT("File create error"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	fprintf(gpFile, "Program started successfully \n");

	//Code
	//WNDCLASSEX initialisation

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

	int WW = WIN_WIDTH;
	int WH = WIN_HEIGHT;

	float SW = GetSystemMetrics(SM_CXSCREEN);
	float SH = GetSystemMetrics(SM_CYSCREEN);
	int X = (SW - WW) / 2;
	int Y = (SH - WH) / 2;


	//Create Window 
	hwnd = CreateWindowEx(
		WS_EX_APPWINDOW,
		szAppName,
		TEXT("Vaishnavi Bhave"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
		X,
		Y,
		WW,
		WH,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ghwnd = hwnd;

	// initialization

	iResult = initialize();

	if (iResult != 0)
	{
		MessageBox(hwnd, TEXT("Initialize() FAILED !!!"), TEXT(" error"), MB_OK | MB_ICONERROR);
		DestroyWindow(hwnd);
		
	}

	// Show Window
	ShowWindow(hwnd, iCmdShow);

	SetForegroundWindow(hwnd);
	SetFocus(hwnd);


	// Game Loop
	while (bDone == FALSE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				bDone = TRUE;
			}
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
				// Render
				display();

				// Update
				update();

			}
		}
	}

	//uninitialization
	uninitialized();

	return((int)msg.wParam);
}

// callBack Function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	// function declaration

	void resize(int, int);

	void ToggleFullscreen(void);

	HDC hdc;
	PAINTSTRUCT ps;
	RECT rc;
	TCHAR str[] = TEXT("Hello World !!!");

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
		resize(LOWORD(lParam), HIWORD(lParam));
		break;

	case WM_ERASEBKGND:
		return 0;
		

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
	// local variable declarations

	MONITORINFO mi = { sizeof(MONITORINFO) };

	// code
	if (gbFullscreen == FALSE)
	{
		dwStyle = GetWindowLong(ghwnd, GWL_STYLE);
		if (dwStyle & WS_OVERLAPPEDWINDOW)
		{
			if (GetWindowPlacement(ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(ghwnd, MONITORINFOF_PRIMARY), &mi))
			{
				SetWindowLong(ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
				SetWindowPos(
					ghwnd,
					HWND_TOP, //WS_OVERLAPPED is brought back using this statement 
					mi.rcMonitor.left, // this is rect rc , that is rectasngle vala rc giving us left of monitor  
					mi.rcMonitor.top, // this is rect rc , that is rectasngle vala rc giving us top of monitor
					mi.rcMonitor.right - mi.rcMonitor.left, // right of monitor - left gives width
					mi.rcMonitor.bottom - mi.rcMonitor.top, // height of
					SWP_NOZORDER | SWP_FRAMECHANGED
				);
			}
		}
		ShowCursor(FALSE);
	}

	else
	{
		SetWindowPlacement(ghwnd, &wpPrev);
		SetWindowLong(ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
		SetWindowPos(
			ghwnd,
			HWND_TOP,
			0,
			0,
			0,
			0,
			SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED
		);
		ShowCursor(TRUE);
	}

}

int initialize(void)
{
	// Function Declarations

	void resize(int, int);

	// Code
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR)); 	// Remaining members are kept zero in pfd struct using this.

	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cRedBits = 8;
	pfd.cGreenBits = 8;
	pfd.cBlueBits = 8;
	pfd.cAlphaBits = 8;

	// Get the DC (device context , painter)

	ghdc = GetDC(ghwnd);
	if (ghdc == NULL)
	{
		fprintf(gpFile, "GetDC() failed \n");
		return -1;
	}

	iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd); // iPixelFormatIndex must be always non-zero positive
	if (iPixelFormatIndex == 0)
	{
		fprintf(gpFile, "ChoosePixelFormat() Failed \n");
		return -2;
	}

	// set obtained pixel format step-4

	if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
	{
		fprintf(gpFile, "SetPixelFormat() Failed \n");
		return -3;
	}
	// Tell Windows graphing libraray to give OpenGL compatible context from this DC
	// Create OpenGl context from device context.

	ghrc = wglCreateContext(ghdc);
	if (ghrc == NULL)
	{
		fprintf(gpFile, "wglCreateContext() failed \n");
		return -4;
	}
	// now ghdc will end its role and will give control to ghrc for furthrt steps
	//Make rendering context current

	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFile, "wglMakeCurrent() failed \n");
		return -5;
	}
	// set the clear colour of window to blue

	glClearColor(0.61f, 0.69f, 0.807f, 1.0f);
	// Here OpenGL starts.....

	resize(WIN_WIDTH, WIN_HEIGHT);

	return 0;
}

void resize(int width, int height)
{
	// code
	if (height <= 0)
	{
		height = 1;
	}
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.f);

}

void display(void)
{
// Code
glClear(GL_COLOR_BUFFER_BIT);

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

glTranslatef(0.0f, 0.0f, -3.0f);
glScalef(0.02f, 0.02f, 0.02f); 

glBegin(GL_QUADS);
glColor3f(0.61f, 0.69f, 0.807f);
glVertex3f(100.0f, 100.0f, 0.0f);
glVertex3f(-100.0f, 100.0f, 0.0f);
glVertex3f(-100.0f, -100.0f, 0.0f);
glVertex3f(100.0f, -100.0f, 0.0f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.905f, 0.941f, 0.89f);
glVertex3f(20.7251f, 27.48f, 0.0f);
glVertex3f(51.8002f, 24.2f, 0.0f);
glVertex3f(64.8985f, 17.56f, 0.0f);
glVertex3f(-5.22f, 25.309f, 0.0f);
glEnd();

//quad right 
glBegin(GL_QUADS);
glColor3f(0.713f, 0.733f, 0.690f);
glVertex3f(1.50583f, 24.2888f, 0.0f);
glVertex3f(56.70f, 18.808f, 0.0f);
glVertex3f(46.79f, -34.394f, 0.0f);
glVertex3f(0.85255f, -22.31f, 0.0f);
glEnd();

//dark grey part
glBegin(GL_QUADS);
glColor3f(0.219f, 0.227f, 0.213f);
glVertex3f(2.551f, 18.818f, 0.0f);
glVertex3f(54.27f, 16.749f, 0.0f);
glVertex3f(48.82f, -15.3f, 0.0f);
glVertex3f(2.163f, -7.1416f, 0.0f);
glEnd();


//faint grey
glBegin(GL_QUADS);
glColor3f(0.513f, 0.533f, 0.533f);
glVertex3f(48.827f, -16.232f, 0.0f);
glVertex3f(2.099f, -7.5755f, 0.0f);
glVertex3f(2.0260f, -22.562f, 0.0f);
glVertex3f(45.60f, -33.91f, 0.0f);
glEnd();

//glLineWidth(2.0);
//glBegin(GL_LINE_STRIP);
//glColor3f(0.905f, 0.941f, 0.89f);
//glVertex3f(55.0f, 16.59f, 0.0f);
//glVertex3f(54.48f, 14.017f, 0.0f);
//glVertex3f(50.8f, 14.172f, 0.0f);
//glVertex3f(51.34f, 16.95f, 0.0f);
//glVertex3f(55.0f, 16.59f, 0.0f);
//glEnd();
//

//white base
glBegin(GL_QUADS);
glColor3f(0.905f, 0.941f, 0.89f);
glVertex3f(-53.699f, 4.4482f, 0.0f);
glVertex3f(1.788f, -4.984f, 0.0f);
glVertex3f(1.788f, 5.488f, 0.0f);
glVertex3f(-34.4f, 10.91f, 0.0f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.894f, 0.929f, 0.87f);
glVertex3f(1.788f, 5.488f, 0.0f);
glVertex3f(-34.42f, 10.91f, 0.0f);
glVertex3f(-18.050f, 13.67f, 0.0f);
glVertex3f(1.8514f, 11.915f, 0.0f);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.713f, 0.733f, 0.690f);
glVertex3f(1.46f, -5.2131f, 0.0f);
glVertex3f(-53.99f,4.2173f, 0.0f);
glVertex3f(-53.52f, 2.825f, 0.0f);
glVertex3f(1.26f, -7.44f, 0.0f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.513f, 0.533f, 0.533f);
glVertex3f(-53.52f, 2.85f, 0.0f);
glVertex3f(-51.23f, -8.549f, 0.0f);
glVertex3f(1.088f, -22.34f, 0.0f);
glVertex3f(1.265f, -7.4440f, 0.0f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.513f, 0.533f, 0.533f);
glVertex3f(-53.52f, 2.85f, 0.0f);
glVertex3f(-62.07f, 4.379f, 0.0f);
glVertex3f(-60.42f, -5.690f, 0.0f);
glVertex3f(-51.23f, -8.54f, 0.0f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.219f, 0.227f, 0.213f);
glVertex3f(-54.031f, 11.389f, 0.0f);
glVertex3f(-63.30f, 12.605f, 0.0f);
glVertex3f(-62.075f, 4.379f, 0.0f);
glVertex3f(-53.52f, 2.825f, 0.0f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.219f, 0.227f, 0.213f);
glVertex3f(-54.031f, 11.38f, 0.0f);
glVertex3f(-53.682f, 4.8285f, 0.0f);
glVertex3f(-20.082f, 13.358f, 0.0f);
glVertex3f(-19.966f, 17.364f, 0.0f);
glEnd();


glBegin(GL_QUADS);
glColor3f(0.635f, 0.647f, 0.611f);
glVertex3f(-63.30f, 12.605f, 0.0f);
glVertex3f(-53.711f, 10.389f, 0.0f);
glVertex3f(-19.96f, 17.364f, 0.0f);
glVertex3f(-29.6425f, 17.779f, 0.0f);
glEnd();

//chimneys
glBegin(GL_QUADS);
glColor3f(0.219f, 0.227f, 0.213f);
glVertex3f(-62.183f, 24.96f, 0.0f);
glVertex3f(-60.829f, 17.8528f, 0.0f);
glVertex3f(-57.94f, 18.0f, 0.0f);
glVertex3f(-58.284, 25.066f, 0.0f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.219f, 0.227f, 0.213f);
glVertex3f(-60.8f, 17.852f, 0.0f);
glVertex3f(-61.599f, 12.855f, 0.0f);
glVertex3f(-55.745f, 12.98f, 0.0f);
glVertex3f(-57.946f, 18.00, 0.0f);
glEnd();
//line on right side
glLineWidth(5.0f);
glBegin(GL_LINES);
glColor3f(0.713f, 0.733f, 0.690f);
glVertex3f(25.22f, 18.079f, 0.0f);
glVertex3f(21.451f, -27.6019f, 0.0f);
glEnd();
//
////points
//
//
//
//glPointSize(8.0f);
//glBegin(GL_POINTS);
//glColor3f(0.219f, 0.227f, 0.213f);
//glVertex3f(25.22f, 16.889f, 0.0f);
//glVertex3f(24.728f, 11.43f, 0.0f);
//glVertex3f(24.23f, 6.670f, 0.0f);
//glVertex3f(23.935f, 1.8090f, 0.0f);
//glVertex3f(23.538f, -3.052f, 0.0f);
//glVertex3f(23.141f, -7.814f, 0.0f);
//glEnd();
//////points
//glPointSize(8.0f);
//glBegin(GL_POINTS);
//glColor3f(0.513f, 0.533f, 0.533f);
//glVertex3f(22.86f, -12.2f, 0.0f);
//glVertex3f(22.48f, -16.588f, 0.0f);
//glVertex3f(22.02f, -20.69f, 0.0f);
//glVertex3f(21.82f, -26.481f, 0.0f);
//glEnd();

glPointSize(4.0f);
glBegin(GL_POINTS);
glColor3f(0.219f, 0.227f, 0.213f);
glVertex3f(-43.538f, 3.15091f, 0.0f);
glVertex3f(-40.150f, 2.4633f, 0.0f);
glVertex3f(-36.565f, 1.800f, 0.0f);
glVertex3f(-32.833f, 1.2602f, 0.0f);
glVertex3f(-28.70f, 0.691453f, 0.0f);
glVertex3f(-24.524f, -0.090631f, 0.0f);
glVertex3f(-20.11f, -0.94381f, 0.0f);
glVertex3f(-15.41f, -1.6548f, 0.0f);
glEnd();

//door
glBegin(GL_QUADS);
glColor3f(0.713f, 0.733f, 0.690f);
glVertex3f(-45.477f, -6.5424f, 0.0f);
glVertex3f(-45.2272f, -10.0257f, 0.0f);
glVertex3f(-30.96f, -13.91f, 0.0f);
glVertex3f(-31.177f, -10.29f, 0.0f);
glEnd();

glLineWidth(5.0f);
glBegin(GL_LINES);
glColor3f(0.635f, 0.647f, 0.611f);
glVertex3f(-38.79f, -8.0097f, 0.0f);
glVertex3f(-38.792f, -11.768f, 0.0f);
glVertex3f(-54.031f, 11.389f, 0.0f);
glVertex3f(-51.23f, -8.549f, 0.0f);
glEnd();

glLoadIdentity();

glTranslatef(0.0f, 0.0f, -3.0f);
glScalef(0.02f, 0.02f, 0.02f);

glBegin(GL_QUADS);
glColor3f(0.61f, 0.69f, 0.807f);
glVertex3f(6.568f, -19.1f, 0.0f);
glVertex3f(6.338f, -21.745f, 0.0f);
glVertex3f(8.258f, -22.12f, 0.0f);
glVertex3f(8.335f, -19.4409f, 0.0f);
glEnd();

glLoadIdentity();
glTranslatef(0.1f, -0.02f, -3.0f);
glScalef(0.02f, 0.02f, 0.02f);

glBegin(GL_QUADS);
glColor3f(0.61f, 0.69f, 0.807f);
glVertex3f(6.568f, -19.1f, 0.0f);
glVertex3f(6.338f, -21.745f, 0.0f);
glVertex3f(8.258f, -22.12f, 0.0f);
glVertex3f(8.335f, -19.4409f, 0.0f);
glEnd();

glLoadIdentity();
glTranslatef(0.2f, -0.04f, -3.0f);
glScalef(0.02f, 0.02f, 0.02f);

glBegin(GL_QUADS);
glColor3f(0.61f, 0.69f, 0.807f);
glVertex3f(6.568f, -19.1f, 0.0f);
glVertex3f(6.338f, -21.745f, 0.0f);
glVertex3f(8.258f, -22.12f, 0.0f);
glVertex3f(8.335f, -19.4409f, 0.0f);
glEnd();

glLoadIdentity();
glTranslatef(0.3f, -0.06f, -3.0f);
glScalef(0.02f, 0.02f, 0.02f);

glBegin(GL_QUADS);
glColor3f(0.219f, 0.227f, 0.213f);
glVertex3f(5.568f, -19.1f, 0.0f);
glVertex3f(5.338f, -24.145f, 0.0f);
glVertex3f(8.258f, -24.745f, 0.0f);
glVertex3f(8.335f, -19.4409f, 0.0f);
glEnd();

glLoadIdentity();
glTranslatef(0.45f, -0.085f, -3.0f);
glScalef(0.02f, 0.02f, 0.02f);

glBegin(GL_QUADS);
glColor3f(0.61f, 0.69f, 0.807f);
glVertex3f(6.568f, -19.1f, 0.0f);
glVertex3f(6.338f, -21.745f, 0.0f);
glVertex3f(8.258f, -22.12f, 0.0f);
glVertex3f(8.335f, -19.4409f, 0.0f);
glEnd();
glLoadIdentity();
glTranslatef(0.6f, -0.12f, -3.0f);
glScalef(0.02f, 0.02f, 0.02f);

glBegin(GL_QUADS);
glColor3f(0.219f, 0.227f, 0.213f);
glVertex3f(5.568f, -19.1f, 0.0f);
glVertex3f(5.338f, -24.145f, 0.0f);
glVertex3f(8.258f, -24.745f, 0.0f);
glVertex3f(8.335f, -19.4409f, 0.0f);
glEnd();

glLoadIdentity();
glTranslatef(0.7f, -0.14f, -3.0f);
glScalef(0.02f, 0.02f, 0.02f);

glBegin(GL_QUADS);
glColor3f(0.61f, 0.69f, 0.807f);
glVertex3f(6.568f, -19.1f, 0.0f);
glVertex3f(6.338f, -21.745f, 0.0f);
glVertex3f(8.258f, -22.12f, 0.0f);
glVertex3f(8.335f, -19.4409f, 0.0f);
glEnd();

glLoadIdentity();
glTranslatef(0.0f, 0.0f, -3.0f);
glScalef(0.02f, 0.02f, 0.02f);

glBegin(GL_QUADS);
glColor3f(0.219f, 0.227f, 0.213f);
glVertex3f(-17.122f, -14.499f, 0.0f);
glVertex3f(-16.81f, -17.27f, 0.0f);
glVertex3f(-14.80f, -17.893f, 0.0f);
glVertex3f(-15.11f, -14.808f, 0.0f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.219f, 0.227f, 0.213f);
glVertex3f(-49.966f, 21.283f, 0.0f);
glVertex3f(-49.8356f, 14.4979f, 0.0f);
glVertex3f(-45.1482f, 14.979f, 0.0f);
glVertex3f(-46.98f, 21.664f, 0.0f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.219f, 0.227f, 0.213f);
glVertex3f(-43.22f, 25.50f, 0.0f);
glVertex3f(-42.683f, 19.8979f, 0.0f);
glVertex3f(-40.312f, 20.051f, 0.0f);
glVertex3f(-40.75f, 25.597f, 0.0f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.219f, 0.227f, 0.213f);
glVertex3f(-42.68f, 19.897f, 0.0f);
glVertex3f(-43.591f, 15.812f, 0.0f);
glVertex3f(-38.498f, 16.09f, 0.0f);
glVertex3f(-40.3123f, 20.051f, 0.0f);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.219f, 0.227f, 0.213f);
glVertex3f(-32.6269f, 22.5546f, 0.0f);
glVertex3f(-33.1319f, 16.769f, 0.0f);
glVertex3f(-29.45f, 16.8613f, 0.0f);
glVertex3f(-30.606f, 22.508f, 0.0f);
glEnd();

glLoadIdentity();
glTranslatef(0.0f, 0.0f, -3.0f);
glScalef(0.02f, 0.02f, 0.02f);

glBegin(GL_QUADS);
glColor3f(0.219f, 0.227f, 0.213f);
glVertex3f(-21.225f, 12.76f, 0.0f);
glVertex3f(-21.2795f, 11.40f, 0.0f);
glVertex3f(-20.028f, 11.3459f, 0.0f);
glVertex3f(-19.973f, 12.65f, 0.0f);
glEnd();

glLoadIdentity();
glTranslatef(0.2f, 0.0f, -3.0f);
glScalef(0.02f, 0.02f, 0.02f);

glBegin(GL_QUADS);
glColor3f(0.219f, 0.227f, 0.213f);
glVertex3f(-21.225f, 12.76f, 0.0f);
glVertex3f(-21.2795f, 11.40f, 0.0f);
glVertex3f(-20.028f, 11.3459f, 0.0f);
glVertex3f(-19.973f, 12.65f, 0.0f);
glEnd();

SwapBuffers(ghdc);



}

 
void update(void)
{
	// Code

}


void uninitialized(void)
{
	//  function declarations

	void ToggleFullscreen(void);
	if (gbFullscreen == TRUE)
	{
		ToggleFullscreen();
		gbFullscreen = FALSE;
	}

	// make the hdc as current context

	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);
	}
	
	if (ghrc)
	{
		wglDeleteContext(ghrc);
		ghrc = NULL;

	}

	// release the hdc

	if (ghdc)
	{
		ReleaseDC(ghwnd, ghdc);
	}

	// code
	// if application is exiting in fullscreen
	// destroy window
	if (ghwnd)
	{
		DestroyWindow(ghwnd);
		ghwnd = NULL;
	}

	// close the log file

	if (gpFile)
	{
		fprintf(gpFile, "Program ended successfully \n");
		fclose(gpFile);
		gpFile = NULL;
	}
}



