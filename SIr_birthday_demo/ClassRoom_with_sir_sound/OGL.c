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
// Used For PlaySound (link)
#pragma comment(lib, "Winmm.lib")

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


double elapsedTime = 0.0;//Elapsed time between two frames
double frameCount = 0.0;//number of frame since the last FPS update
double fps = 0.0;//current FPS value
char titleBuffer[32];

//3D Shapes
GLUquadric* quadric = NULL;

// Demo Variables
//Time
GLfloat hour             = 210.0f;
GLfloat minut            = 270.0f;
GLdouble second          = 270.0f;
GLfloat rotateCeilingFan = 0.0f;
GLfloat cloud_X_scale    = 60.25f;
GLfloat cloud_Y_scale    = 60.1f;

// For PlaySound()
//PLAYSOUND BOOLS (Chaupai-1)
BOOL sir_sound_1 = TRUE;

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
	//Classroom Function
	void drawClassroom1(void);
	void Students(void);
	void watch(void);
	void ceilingFan(void);
	void drawCloud(void);

	

	//CODE
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//3rd step - Compulasory (clears depth buffer)

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Function Call
    drawClassroom1();
	Students();
	watch();
	ceilingFan();
	drawCloud();

	

	SwapBuffers(ghdc);
}

void kalla_ka_sanga_mala(void)
{
	// PlaySound Using Resource
	PlaySound(MAKEINTRESOURCE(KALLA_KA_SANGA_MALA), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	sir_sound_1 = FALSE;
}


void drawCloud(void)
{
	//PlaySound
	void kalla_ka_sanga_mala(void);
	
	if (cloud_X_scale > 0.35f)
	{
		cloud_X_scale -= 0.05f;
		cloud_Y_scale -= 0.05f;
	}
	else
	{
		cloud_Y_scale = 0.15f;
		if (sir_sound_1 == TRUE)
		{
			kalla_ka_sanga_mala();
		}
	}
	// Tree 1
	glLoadIdentity();
	glTranslatef(0.05f, -0.23f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	//glScalef(0.5f, 0.2f, 1.0f);
	glScalef(cloud_X_scale, cloud_Y_scale, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(10.0f, 5.0f, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 15.0f;
		float y = sin(a) * 15.0f;

		glVertex3f((10.0f) + x, (5.0f) + y, 0.0f);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(27.0f, 17.0f, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 15.0f;
		float y = sin(a) * 15.0f;

		glVertex3f((27.0f) + x, (17.0f) + y, 0.0f);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(19.0f, 43.0f, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 15.0f;
		float y = sin(a) * 15.0f;

		glVertex3f((19.0f) + x, (43.0f) + y, 0.0f);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f , 30.0f, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 25.0f;
		float y = sin(a) * 25.0f;

		glVertex3f((0.0f) + x, (30.0f) + y, 0.0f);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-2.0f, 44.0f, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 20.0f;
		float y = sin(a) * 20.0f;

		glVertex3f((-2.0f) + x, (44.0f) + y, 0.0f);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-15.0f, 21.0f, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 20.0f;
		float y = sin(a) * 20.0f;

		glVertex3f((-15.0f) + x, (21.0f) + y, 0.0f);
	}
	glEnd();

	//Dots
	glEnable(GL_POINT_SMOOTH);

	glPointSize(20);
	glBegin(GL_POINTS);
	glVertex3f(40.0f, -10.0f, 0.0f);
	glEnd();

	glPointSize(15);
	glBegin(GL_POINTS);
	glVertex3f(60.0f, -30.0f, 0.0f);
	glEnd();

	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex3f(70.0f, -50.0f, 0.0f);
	glEnd();


	glDisable(GL_POINT_SMOOTH);
}

void drawClassroom1(void)
{
	//Function Declaration
	void SirBackView(void);


	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	glScalef(0.022f, 0.022f, 0.022f);

	// 1
	glBegin(GL_POLYGON);
	glColor3f(0.733, 0.725, 0.725);
	glVertex3f(99.6372f   , 56.22f    , 0.0f);
	glVertex3f(-99.6372f  , 56.22f    , 0.0f);
	glVertex3f(-99.9391f  , 48.6563f  , 0.0f);
	glColor3f(0.753, 0.784, 0.925);
	glVertex3f(-67.2865f  , 33.3984f  , 0.0f);
	glVertex3f(67.2865f   , 33.3984f  , 0.0f);
	glVertex3f(99.9391f   , 48.6563f  , 0.0f);
	glEnd();

	//2 back of blackboard
	glBegin(GL_POLYGON);
	glColor3f(0.812, 0.835, 0.796);
	glVertex3f(67.2865f  , 33.3984f   , 0.0f);
	glVertex3f(-67.2865f  , 33.3984f  , 0.0f);
	glColor3f(0.518, 0.522, 0.498);
	glVertex3f(-67.2865f  , -33.9797f  , 0.0f);
	glVertex3f(67.2865f  , -33.9797f   , 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.812, 0.835, 0.796);
	glVertex3f(67.2865f, 33.3984f, 0.0f);

	glEnd();

	//3
	glBegin(GL_POLYGON);
	glColor3f(0.569, 0.533, 0.42);
	glVertex3f(-67.2865f  , -33.9797f , 0.0f);
	glVertex3f(-67.2865f  , 33.3984f  , 0.0f);
	glVertex3f(-99.9391f  , 48.6563f  , 0.0f);
	glVertex3f(-99.9391f  , -56.22f   , 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.569, 0.533, 0.42);
	glVertex3f(67.2865f  , -33.9797f  , 0.0f);
	glVertex3f(67.2865f  , 33.3984f   , 0.0f);
	glVertex3f(99.9391f  , 48.6563f   , 0.0f);
	glVertex3f(99.9391f  , -56.22f    , 0.0f);
	glEnd();

	//4 flour
	glBegin(GL_POLYGON);
	glColor3f(0.694, 0.455, 0.192);
	glVertex3f(67.2865f   , -33.9797f  , 0.0f);
	glColor3f(0.416, 0.235, 0.102);
	glVertex3f(-67.2865f  , -33.9797f  , 0.0f);
	glVertex3f(-99.9391f  , -49.6995f  , 0.0f);
	glColor3f(0.416, 0.235, 0.102);
	glVertex3f(-99.9391f  , -56.22f    , 0.0f);
	glVertex3f(99.9391f   , -56.22f    , 0.0f);
	glColor3f(0.694, 0.455, 0.192);
	glVertex3f(99.9391f   , -49.6995f  , 0.0f);
	glEnd();

	//BlackBoard
	glBegin(GL_POLYGON);
	glColor3f(0.173, 0.173, 0.18);
	glVertex3f(20.0893f   , 3.86695f   , 0.0f);
	glVertex3f(-20.0893f  , 3.86695f   , 0.0f);
	glVertex3f(-20.0893f  , -17.4484f  , 0.0f);
	glVertex3f(20.0893f   , -17.4484f  , 0.0f);
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
	glVertex3f(18.1718f   , 53.1175f   , 0.0f);
	glVertex3f(-18.1718f  , 53.1175f   , 0.0f);
	glVertex3f(-18.1718f  , -38.3435f  , 0.0f);
	glVertex3f(18.1718f   , -38.3435f  , 0.0f);
	glEnd();

	//upper back 
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(14.6406f   , 49.5863f  , 0.0f);
	glVertex3f(-14.6406f  , 49.5863f  , 0.0f);
	glVertex3f(-14.6406f  , 43.0672f  , 0.0f);
	glVertex3f(14.6406f   , 43.0672f  , 0.0f);
	glEnd();
	//inside
	glBegin(GL_POLYGON);
	glColor3f(0., 0.569, 0.878);
	glVertex3f(-1.43639f  , 47.0756f  , 0.0f);
	glVertex3f(-11.0252f  , 47.0756f  , 0.0f);
	glVertex3f(-11.0252f  , 44.4819f  , 0.0f);
	glVertex3f(-1.43639f  , 44.4819f  , 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0., 0.569, 0.878);
	glVertex3f(1.43639f  , 47.0756f  , 0.0f);
	glVertex3f(11.0252f  , 47.0756f  , 0.0f);
	glVertex3f(11.0252f  , 44.4819f  , 0.0f);
	glVertex3f(1.43639f  , 44.4819f  , 0.0f);
	glEnd();

	//back white
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(16.295f   , 36.748f   , 0.0f);
	glVertex3f(1.77035f  , 36.748f   , 0.0f);
	glVertex3f(1.77035f  , 3.54884f  , 0.0f);
	glVertex3f(16.295f   , 3.54884f  , 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-16.295f   , 36.748f   , 0.0f);
	glVertex3f(-1.77035f  , 36.748f   , 0.0f);
	glVertex3f(-1.77035f  , 3.54884f  , 0.0f);
	glVertex3f(-16.295f   , 3.54884f  , 0.0f);
	glEnd();
	//bottom white bk
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-16.295f   , -36.748f   , 0.0f);
	glVertex3f(-1.77035f  , -36.748f   , 0.0f);
	glVertex3f(-1.77035f  , -3.54884f  , 0.0f);
	glVertex3f(-16.295f   , -3.54884f  , 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(16.295f   , -36.748f   , 0.0f);
	glVertex3f(1.77035f  , -36.748f   , 0.0f);
	glVertex3f(1.77035f  , -3.54884f  , 0.0f);
	glVertex3f(16.295f   , -3.54884f  , 0.0f);
	glEnd();
	// in betwn brown part
	glBegin(GL_POLYGON);
	glColor3f(0.424, 0.157, 0.075);
	glVertex3f(14.1257f  , -33.5413f  , 0.0f);
	glVertex3f(4.41121f  , -33.5413f  , 0.0f);
	glVertex3f(4.41121f  , -7.03852f  , 0.0f);
	glVertex3f(14.1257f  , -7.03852f  , 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.424, 0.157, 0.075);
	glVertex3f(-14.1257f  , -33.5413f  , 0.0f);
	glVertex3f(-4.41121f  , -33.5413f  , 0.0f);
	glVertex3f(-4.41121f  , -7.03852f  , 0.0f);
	glVertex3f(-14.1257f  , -7.03852f  , 0.0f);
	glEnd();

	// small inside triangles 
	glBegin(GL_TRIANGLES);
	// blue
	glColor3f(0.133, 0.2, 0.416);
	glVertex3f(14.2358f  , 35.7027f  , 0.0f);
	glVertex3f(3.75624f  , 35.7027f  , 0.0f);
	glVertex3f(8.93051f  , 29.7425f  , 0.0f);

	glVertex3f(14.2358f  , 4.52608f  , 0.0f);
	glVertex3f(8.93051f  , 10.7483f  , 0.0f);
	glVertex3f(3.75624f  , 4.52608f  , 0.0f);

	//green
	glColor3f(0.122, 0.282, 0.251);
	glVertex3f(7.81706f  , 28.629f   , 0.0f);
	glVertex3f(2.70829f  , 34.3928f  , 0.0f);
	glVertex3f(2.70829f  , 22.4723f  , 0.0f);

	glVertex3f(7.81706f  , 11.6653f  , 0.0f);
	glVertex3f(2.70829f  , 18.215f   , 0.0f);
	glVertex3f(2.70829f  , 5.44308f  , 0.0f);

	glVertex3f(15.0217f  , 18.215f   , 0.0f);
	glVertex3f(9.78198f  , 11.6653f  , 0.0f);
	glVertex3f(15.0872f  , 5.44308f  , 0.0f);

	glVertex3f(15.0217f  , 22.4723f  , 0.0f);
	glVertex3f(15.0217f  , 34.3928f  , 0.0f);
	glVertex3f(9.78198f  , 28.629f   , 0.0f);
	glEnd(); 

	// small inside triangles 
	glBegin(GL_TRIANGLES);
	// blue
	glColor3f(0.133, 0.2, 0.416);
	glVertex3f(-14.2358f  , 35.7027f  , 0.0f);
	glVertex3f(-3.75624f  , 35.7027f  , 0.0f);
	glVertex3f(-8.93051f  , 29.7425f  , 0.0f);

	glVertex3f(-14.2358f  , 4.52608f  , 0.0f);
	glVertex3f(-8.93051f  , 10.7483f  , 0.0f);
	glVertex3f(-3.75624f  , 4.52608f  , 0.0f);

	//green
	glColor3f(-0.122, 0.282, 0.251);
	glVertex3f(-7.81706f  , 28.629f   , 0.0f);
	glVertex3f(-2.70829f  , 34.3928f  , 0.0f);
	glVertex3f(-2.70829f  , 22.4723f  , 0.0f);

	glVertex3f(-7.81706f  , 11.6653f  , 0.0f);
	glVertex3f(-2.70829f  , 18.215f   , 0.0f);
	glVertex3f(-2.70829f  , 5.44308f  , 0.0f);

	glVertex3f(-15.0217f  , 18.215f   , 0.0f);
	glVertex3f(-9.78198f  , 11.6653f  , 0.0f);
	glVertex3f(-15.0872f  , 5.44308f  , 0.0f);

	glVertex3f(-15.0217f  , 22.4723f  , 0.0f);
	glVertex3f(-15.0217f  , 34.3928f  , 0.0f);
	glVertex3f(-9.78198f  , 28.629f   , 0.0f);
	glEnd();

	// middle quad red
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.11, 0.098);
	glVertex3f(15.0217f  , 20.2334f  , 0.0f);
	glVertex3f(8.93051f  , 27.0571f  , 0.0f);
	glVertex3f(2.70829f  , 20.2334f  , 0.0f);
	glVertex3f(8.93051f  , 12.8442f  , 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.11, 0.098);
	glVertex3f(-15.0217f  , 20.2334f  , 0.0f);
	glVertex3f(-8.93051f  , 27.0571f  , 0.0f);
	glVertex3f(-2.70829f  , 20.2334f  , 0.0f);
	glVertex3f(-8.93051f  , 12.8442f  , 0.0f);
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
	glVertex3f(18.1718f   , 53.1175f   , 0.0f);
	glVertex3f(-18.1718f  , 53.1175f   , 0.0f);
	glVertex3f(-18.1718f  , -38.3435f  , 0.0f);
	glVertex3f(18.1718f   , -38.3435f  , 0.0f);
	glEnd();

	//upper back 
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(14.6406f   , 49.5863f  , 0.0f);
	glVertex3f(-14.6406f  , 49.5863f  , 0.0f);
	glVertex3f(-14.6406f  , 43.0672f  , 0.0f);
	glVertex3f(14.6406f   , 43.0672f  , 0.0f);
	glEnd();
	//inside
	glBegin(GL_POLYGON);
	glColor3f(0., 0.569, 0.878);
	glVertex3f(-1.43639f  , 47.0756f  , 0.0f);
	glVertex3f(-11.0252f  , 47.0756f  , 0.0f);
	glVertex3f(-11.0252f  , 44.4819f  , 0.0f);
	glVertex3f(-1.43639f  , 44.4819f  , 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0., 0.569, 0.878);
	glVertex3f(1.43639f  , 47.0756f  , 0.0f);
	glVertex3f(11.0252f  , 47.0756f  , 0.0f);
	glVertex3f(11.0252f  , 44.4819f  , 0.0f);
	glVertex3f(1.43639f  , 44.4819f  , 0.0f);
	glEnd();

	//back white
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(16.295f   , 36.748f   , 0.0f);
	glVertex3f(1.77035f  , 36.748f   , 0.0f);
	glVertex3f(1.77035f  , 3.54884f  , 0.0f);
	glVertex3f(16.295f   , 3.54884f  , 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-16.295f   , 36.748f    , 0.0f);
	glVertex3f(-1.77035f  , 36.748f   , 0.0f);
	glVertex3f(-1.77035f  , 3.54884f  , 0.0f);
	glVertex3f(-16.295f   , 3.54884f   , 0.0f);
	glEnd();
	//bottom white bk
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-16.295f   , -36.748f   , 0.0f);
	glVertex3f(-1.77035f  , -36.748f   , 0.0f);
	glVertex3f(-1.77035f  , -3.54884f  , 0.0f);
	glVertex3f(-16.295f   , -3.54884f  , 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(16.295f   , -36.748f   , 0.0f);
	glVertex3f(1.77035f  , -36.748f   , 0.0f);
	glVertex3f(1.77035f  , -3.54884f  , 0.0f);
	glVertex3f(16.295f   , -3.54884f  , 0.0f);
	glEnd();
	// in betwn brown part
	glBegin(GL_POLYGON);
	glColor3f(0.424, 0.157, 0.075);
	glVertex3f(14.1257f  , -33.5413f  , 0.0f);
	glVertex3f(4.41121f  , -33.5413f  , 0.0f);
	glVertex3f(4.41121f  , -7.03852f  , 0.0f);
	glVertex3f(14.1257f  , -7.03852f  , 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.424, 0.157, 0.075);
	glVertex3f(-14.1257f  , -33.5413f  , 0.0f);
	glVertex3f(-4.41121f  , -33.5413f  , 0.0f);
	glVertex3f(-4.41121f  , -7.03852f  , 0.0f);
	glVertex3f(-14.1257f  , -7.03852f  , 0.0f);
	glEnd();

	// small inside triangles 
	glBegin(GL_TRIANGLES);
	// blue
	glColor3f(0.133, 0.2, 0.416);
	glVertex3f(14.2358f  , 35.7027f  , 0.0f);
	glVertex3f(3.75624f  , 35.7027f  , 0.0f);
	glVertex3f(8.93051f  , 29.7425f  , 0.0f);

	glVertex3f(14.2358f  , 4.52608f  , 0.0f);
	glVertex3f(8.93051f  , 10.7483f  , 0.0f);
	glVertex3f(3.75624f  , 4.52608f  , 0.0f);

	//green
	glColor3f(0.122, 0.282, 0.251);
	glVertex3f(7.81706f  , 28.629f   , 0.0f);
	glVertex3f(2.70829f  , 34.3928f  , 0.0f);
	glVertex3f(2.70829f  , 22.4723f  , 0.0f);

	glVertex3f(7.81706f  , 11.6653f  , 0.0f);
	glVertex3f(2.70829f  , 18.215f   , 0.0f);
	glVertex3f(2.70829f  , 5.44308f  , 0.0f);

	glVertex3f(15.0217f  , 18.215f   , 0.0f);
	glVertex3f(9.78198f  , 11.6653f  , 0.0f);
	glVertex3f(15.0872f  , 5.44308f  , 0.0f);

	glVertex3f(15.0217f  , 22.4723f  , 0.0f);
	glVertex3f(15.0217f  , 34.3928f  , 0.0f);
	glVertex3f(9.78198f  , 28.629f   , 0.0f);
	glEnd();

	// small inside triangles 
	glBegin(GL_TRIANGLES);
	// blue
	glColor3f(0.133, 0.2, 0.416);
	glVertex3f(-14.2358f  , 35.7027f  , 0.0f);
	glVertex3f(-3.75624f  , 35.7027f  , 0.0f);
	glVertex3f(-8.93051f  , 29.7425f  , 0.0f);

	glVertex3f(-14.2358f  , 4.52608f  , 0.0f);
	glVertex3f(-8.93051f  , 10.7483f  , 0.0f);
	glVertex3f(-3.75624f  , 4.52608f  , 0.0f);

	//green
	glColor3f(-0.122, 0.282, 0.251);
	glVertex3f(-7.81706f  , 28.629f   , 0.0f);
	glVertex3f(-2.70829f  , 34.3928f  , 0.0f);
	glVertex3f(-2.70829f  , 22.4723f  , 0.0f);

	glVertex3f(-7.81706f  , 11.6653f  , 0.0f);
	glVertex3f(-2.70829f  , 18.215f   , 0.0f);
	glVertex3f(-2.70829f  , 5.44308f  , 0.0f);

	glVertex3f(-15.0217f  , 18.215f   , 0.0f);
	glVertex3f(-9.78198f  , 11.6653f  , 0.0f);
	glVertex3f(-15.0872f  , 5.44308f  , 0.0f);

	glVertex3f(-15.0217f  , 22.4723f  , 0.0f);
	glVertex3f(-15.0217f  , 34.3928f  , 0.0f);
	glVertex3f(-9.78198f  , 28.629f   , 0.0f);
	glEnd();

	// middle quad red
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.11, 0.098);
	glVertex3f(15.0217f  , 20.2334f  , 0.0f);
	glVertex3f(8.93051f  , 27.0571f  , 0.0f);
	glVertex3f(2.70829f  , 20.2334f  , 0.0f);
	glVertex3f(8.93051f  , 12.8442f  , 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.11, 0.098);
	glVertex3f(-15.0217f  , 20.2334f  , 0.0f);
	glVertex3f(-8.93051f  , 27.0571f  , 0.0f);
	glVertex3f(-2.70829f  , 20.2334f  , 0.0f);
	glVertex3f(-8.93051f  , 12.8442f  , 0.0f);
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



	//Sir BAck View
	glLoadIdentity();
	SirBackView();


	//************************* CHAIR ******************************
	glLoadIdentity();
	glTranslatef(0.0f, -0.75f, -3.0f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.25f, 0.25f, 0.5f);

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

void Students(void)
{
	//Function Declaration
	void drawBoy(void);
	void drawGirl(void);
	void drawBoy1(void);
	void drawGirl1(void);
	void drawBoy2(void);
	void drawGirl2(void);
	void drawBoy3(void);
	void drawGirl3(void);

	void drawBoy4(void);
	void drawBoy5(void);
	void drawGirl4(void);
	void drawBoy6(void);
	void drawGirl5(void);
	void drawBoy7(void);
	void drawGirl6(void);
	void drawBoy3(void);
	void drawGirl7(void);

	//CaLL
	drawBoy();
	drawBoy1();
	drawGirl();
	drawGirl1();
	drawBoy2();
	drawBoy3();
	drawGirl2();
	drawGirl3();

	drawBoy4();
	drawBoy5();
	drawGirl4();
	drawGirl5();
	drawBoy6();
	drawBoy7();
	drawGirl6();
	drawGirl7();

}

void drawBoy(void)
{
	glLoadIdentity();
	glTranslatef(-0.2f, -0.4f, -1.4f);
	glScalef(0.015f, 0.01f, 0.01f);
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

void drawBoy1(void)
{
	glLoadIdentity();
	glTranslatef(-0.2f, -0.53f, -1.4f);
	glScalef(0.015f, 0.01f, 0.01f);
	glScalef(0.2f, 0.2f, 0.5f);

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.208, 0.11, 0.122);
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
	glColor3f(0.165, 0.153, 0.3);
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
	glColor3f(0,0.5,0);
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
	glColor3f(0, 0.5, 0);
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

void drawBoy2(void)
{
	glLoadIdentity();
	glTranslatef(-0.4f, -0.4f, -1.4f);
	glScalef(0.015f, 0.01f, 0.01f);
	glScalef(0.2f, 0.2f, 0.5f);

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.412, 0.239, 0.133);
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
	glColor3f(0.678, 0.518, 0.788);
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
	glColor3f(0.0, 1.0, 1.0);
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
	glColor3f(0.0, 1.0, 1.0);
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

void drawBoy3(void)
{
	glLoadIdentity();
	glTranslatef(-0.4f, -0.53f, -1.4f);
	glScalef(0.015f, 0.01f, 0.01f);
	glScalef(0.2f, 0.2f, 0.5f);

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.208, 0.11, 0.122);
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
	glColor3f(0.561, 0.298, 0.137);
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

void drawBoy4(void)
{
	glLoadIdentity();
	glTranslatef(-0.6f, -0.4f, -1.4f);
	glScalef(0.015f, 0.01f, 0.01f);
	glScalef(0.2f, 0.2f, 0.5f);

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.647, 0.341, 0.161);
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
	glColor3f(0.843, 0., 0.004);
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
	glColor3f(1.0, 1.0, 0.0);
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
	glColor3f(1.0, 1.0, 0.0);
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

void drawBoy5(void)
{
	glLoadIdentity();
	glTranslatef(-0.6f, -0.53f, -1.4f);
	glScalef(0.015f, 0.01f, 0.01f);
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
	glColor3f(0.843, 0.5, 0.014);
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
	glColor3f(1.0, 0.0, 1.0);
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
	glColor3f(1.0, 0.0, 1.0);
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

void drawBoy6(void)
{
	glLoadIdentity();
	glTranslatef(-0.8f, -0.4f, -1.4f);
	glScalef(0.015f, 0.01f, 0.01f);
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
	glColor3f(0.678, 0.518, 0.088);
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

void drawBoy7(void)
{
	glLoadIdentity();
	glTranslatef(-0.8f, -0.53f, -1.4f);
	glScalef(0.015f, 0.01f, 0.01f);
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
	glColor3f(0,0,0);
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
	glColor3f(0, 0, 0);
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
	glColor3f(1.0, 1.859, 0.1);
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
	glColor3f(0.1, 0.1, 0.1);
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
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-18.0322, 20.4497, 0.0f);
	glVertex3f(-4.79576, 17.3518, 0.0f);
	glVertex3f(6.75088, 17.9151, 0.0f);
	glVertex3f(12.665, 23.5476, 0.0f);
	glEnd();

}

void drawGirl1(void)
{
	glLoadIdentity();
	glTranslatef(0.3f, -0.53f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.3f, 0.2f, 0.5f);

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
	glColor3f(1.0, 0.3, 0.675);
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
	glColor3f(0, 0, 0);
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
	glColor3f(0, 0, 0);
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
	glColor3f(0.3, 0.3, 0.3);
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
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-18.0322, 20.4497, 0.0f);
	glVertex3f(-4.79576, 17.3518, 0.0f);
	glVertex3f(6.75088, 17.9151, 0.0f);
	glVertex3f(12.665, 23.5476, 0.0f);
	glEnd();

}

void drawGirl2(void)
{
	glLoadIdentity();
	glTranslatef(0.5f, -0.4f, -1.4f);
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
	glColor3f(0.678, 0.518, 0.088);
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

void drawGirl3(void)
{
	glLoadIdentity();
	glTranslatef(0.5f, -0.53f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.3f, 0.2f, 0.5f);

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
	glColor3f(0.2, 0.2, 0.0);
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
	glColor3f(0.2, 0.2, 0.0);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-18.0322, 20.4497, 0.0f);
	glVertex3f(-4.79576, 17.3518, 0.0f);
	glVertex3f(6.75088, 17.9151, 0.0f);
	glVertex3f(12.665, 23.5476, 0.0f);
	glEnd();

}

void drawGirl4(void)
{
	glLoadIdentity();
	glTranslatef(0.65f, -0.4f, -1.4f);
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
	glColor3f(0.843, 0., 0.004);
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
	glColor3f(1.0, 1.0, 0.0);
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
	glColor3f(1.0, 1.0, 0.0);
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
	glColor3f(0.647, 0.341, 0.161);
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
	glColor3f(0.647, 0.341, 0.161);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-18.0322, 20.4497, 0.0f);
	glVertex3f(-4.79576, 17.3518, 0.0f);
	glVertex3f(6.75088, 17.9151, 0.0f);
	glVertex3f(12.665, 23.5476, 0.0f);
	glEnd();

}

void drawGirl5(void)
{
	glLoadIdentity();
	glTranslatef(0.7f, -0.53f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.3f, 0.2f, 0.5f);

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
	glColor3f(0.208, 0.11, 0.122);
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
	glColor3f(0.208, 0.11, 0.122);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-18.0322, 20.4497, 0.0f);
	glVertex3f(-4.79576, 17.3518, 0.0f);
	glVertex3f(6.75088, 17.9151, 0.0f);
	glVertex3f(12.665, 23.5476, 0.0f);
	glEnd();

}

void drawGirl6(void)
{
	glLoadIdentity();
	glTranslatef(0.82f, -0.4f, -1.4f);
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
	glColor3f(0.678, 0.518, 0.788);
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
	glColor3f(0.0, 1.0, 1.0);
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
	glColor3f(0.0, 1.0, 1.0);
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
	glColor3f(0.412, 0.239, 0.133);
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
	glColor3f(0.412, 0.239, 0.133);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-18.0322, 20.4497, 0.0f);
	glVertex3f(-4.79576, 17.3518, 0.0f);
	glVertex3f(6.75088, 17.9151, 0.0f);
	glVertex3f(12.665, 23.5476, 0.0f);
	glEnd();

}

void drawGirl7(void)
{
	glLoadIdentity();
	glTranslatef(0.9f, -0.53f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.3f, 0.2f, 0.5f);

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
	glColor3f(0.165, 0.153, 0.3);
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
	glColor3f(0, 0.5, 0);
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
	glColor3f(0, 0.5, 0);
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
	glColor3f(0.208, 0.11, 0.122);
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
	glColor3f(0.208, 0.11, 0.122);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-18.0322, 20.4497, 0.0f);
	glVertex3f(-4.79576, 17.3518, 0.0f);
	glVertex3f(6.75088, 17.9151, 0.0f);
	glVertex3f(12.665, 23.5476, 0.0f);
	glEnd();

}

void SirBackView(void)
{
	glTranslatef(-0.3f, -0.2f, -3.0f);
	glScalef(0.007f, 0.007f, 0.0f);
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
	glTranslatef(-0.3f, -0.2f, -3.0f);
	glScalef(0.007f, 0.007f, 0.0f);

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

void watch(void)
{
	void DrawCircle(GLenum, struct Circle);

	glLoadIdentity();
	glTranslatef(0.0f, 0.5f, -3.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	//glScalef(0.01f, 0.01f, 0.01f);

		//Outer Part
	struct Circle watch1;
	watch1.size.point_size = 1;
	watch1.center.xCoordinate = 0.0f;
	watch1.center.yCoordinate = 0.0f;
	watch1.radious.xAxis = 1.1f;
	watch1.radious.yAxis = 1.1f;
	watch1.color.r = 1.0f;// 0.463;
	watch1.color.g = 1.0f;// 0.459;
	watch1.color.b = 1.0f;// 0.463;
	watch1.angle.from = 0;
	watch1.angle.to = 361;
	DrawCircle(GL_TRIANGLE_FAN, watch1);

	//Inner Part
	struct Circle watch;
	watch.size.point_size = 1;
	watch.center.xCoordinate = 0.0f;
	watch.center.yCoordinate = 0.0f;
	watch.radious.xAxis = 1.0f;
	watch.radious.yAxis = 1.0f;
	watch.color.r = 0.31;
	watch.color.g = 0.275;
	watch.color.b = 0.275;
	watch.angle.from = 0;
	watch.angle.to = 361;
	DrawCircle(GL_TRIANGLE_FAN, watch);

	

	//60 Lines
	
	for (int i = 0; i <= 360; i+=6)
	{
		float angle = i * (3.1436f / 180);
		float x = 0.92f * cos(angle);
		float y = 0.92f * sin(angle);

		if (i % 30 == 0)
		{
			glPointSize(3);
		}
		else
		{
			glPointSize(1);
		}
		glEnable(GL_POINT_SMOOTH);
		glBegin(GL_POINTS);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(x, y, 0.0f);
		glEnd();
		glDisable(GL_POINT_SMOOTH);
	}

	//Kate
	glLoadIdentity();
	glTranslatef(0.0f, 0.5f, -3.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-hour, 0.0f, 0.0f, 1.0f);

	//Hour Hand
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.075f, 0.05f, 0.0f);
	glVertex3f(0.075f, 0.05f, 0.0f);
	glVertex3f(0.075f, -0.05f, 0.0f);
	glVertex3f(-0.075f, -0.05f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.075f, 0.03f, 0.0f);
	glVertex3f(0.5f, 0.03f, 0.0f);
	glVertex3f(0.5f, -0.03f, 0.0f);
	glVertex3f(0.075f, -0.03f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.03f, 0.0f);
	glVertex3f(0.6f, 0.0f, 0.0f);
	glVertex3f(0.5f, -0.03f, 0.0f);
	glEnd();

	//Minut HAnd
	glLoadIdentity();
	glTranslatef(0.0f, 0.5f, -3.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-minut, 0.0f, 0.0f, 1.0f);

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.085f, 0.03f, 0.0f);
	glVertex3f(0.085f, 0.03f, 0.0f);
	glVertex3f(0.085f, -0.03f, 0.0f);
	glVertex3f(-0.085f, -0.03f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.085f, 0.02f, 0.0f);
	glVertex3f(0.6f, 0.02f, 0.0f);
	glVertex3f(0.6f, -0.02f, 0.0f);
	glVertex3f(0.085f, -0.02f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.6f, 0.02f, 0.0f);
	glVertex3f(0.7f, 0.0f, 0.0f);
	glVertex3f(0.6f, -0.02f, 0.0f);
	glEnd();


	//Second Hand
	glLoadIdentity();
	glTranslatef(0.0f, 0.5f, -3.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-second, 0.0f, 0.0f, 1.0f);

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.095f, 0.02f, 0.0f);
	glVertex3f(0.095f, 0.02f, 0.0f);
	glVertex3f(0.095f, -0.02f, 0.0f);
	glVertex3f(-0.095f, -0.02f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.095f, 0.01f, 0.0f);
	glVertex3f(0.8f, 0.01f, 0.0f);
	glVertex3f(0.8f, -0.01f, 0.0f);
	glVertex3f(0.095f, -0.01f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.8f, 0.01f, 0.0f);
	glVertex3f(0.9f, 0.0f, 0.0f);
	glVertex3f(0.8f, -0.01f, 0.0f);
	glEnd();

	//Inner dot
	//glEnable(GL_POINT_SMOOTH);
	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glEnd();
	//glDisable(GL_POINT_SMOOTH);

}

void ceilingFan(void)
{
	glLoadIdentity();
	glTranslatef(0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glColor3f(0.322, 0.09, 0.1061);
	gluCylinder(quadric, 0.06, 0.06, 1.0, 50, 50); 

	glLoadIdentity();
	glTranslatef(0.6f, 0.5f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glColor3f(0.333, 0.341, 0.357);
	gluCylinder(quadric, 0.0, 0.2, 0.5, 50, 50);

	glLoadIdentity();
	glTranslatef(0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(rotateCeilingFan, 0.0f, 1.0f, 0.0f);
	glScalef(2.5f, 1.0f, 2.5f);
	glColor3f(0.5f,0.0f,0.0f);
	gluSphere(quadric, 0.2, 50.0f, 50.0f);


	glLoadIdentity();
	glTranslatef(0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-rotateCeilingFan, 0.0f, 1.0f, 0.0f);
	//Fan 1
	//Cube
	glBegin(GL_QUADS);
	//Front face
	glColor3f(0.1,0.1,0.1);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	//Right face
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	//Back face
	//glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Left Face
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Top Face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	//Bottom Face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-90.0f - rotateCeilingFan, 0.0f, 1.0f, 0.0f);
	//Fan 2
	//Cube
	glBegin(GL_QUADS);
	//Front face
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	//Right face
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	//Back face
	//glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Left Face
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Top Face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	//Bottom Face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-180.0f - rotateCeilingFan, 0.0f, 1.0f, 0.0f);
	//Fan 3
	//Cube
	glBegin(GL_QUADS);
	//Front face
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	//Right face
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	//Back face
	//glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Left Face
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Top Face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	//Bottom Face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-270.0f - rotateCeilingFan, 0.0f, 1.0f, 0.0f);
	//Fan 4
	//Cube
	glBegin(GL_QUADS);
	//Front face
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	//Right face
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	//Back face
	//glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Left Face
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Top Face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	//Bottom Face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glEnd();


	// Fan 2----------------------------------------------------------
	glLoadIdentity();
	glTranslatef(-0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glColor3f(0.322, 0.09, 0.1061);
	gluCylinder(quadric , 0.06, 0.06, 1.0, 50, 50);

	glLoadIdentity();
	glTranslatef(-0.6f, 0.5f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glColor3f(0.333, 0.341, 0.357);
	gluCylinder(quadric, 0.0, 0.2, 0.5, 50, 50);

	glLoadIdentity();
	glTranslatef(-0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(rotateCeilingFan, 0.0f, 1.0f, 0.0f);
	glScalef(2.5f, 1.0f, 2.5f);
	glColor3f(0.5f, 0.0f, 0.0f);
	gluSphere(quadric, 0.2, 50.0f, 50.0f);


	glLoadIdentity();
	glTranslatef(-0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-rotateCeilingFan - 45.0f, 0.0f, 1.0f, 0.0f);
	//Fan 1
	//Cube
	glBegin(GL_QUADS);
	//Front face
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	//Right face
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	//Back face
	//glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Left Face
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Top Face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	//Bottom Face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-90.0f - rotateCeilingFan - 45.0f, 0.0f, 1.0f, 0.0f);
	//Fan 2
	//Cube
	glBegin(GL_QUADS);
	//Front face
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	//Right face
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	//Back face
	//glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Left Face
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Top Face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	//Bottom Face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-180.0f - rotateCeilingFan - 45.0f, 0.0f, 1.0f, 0.0f);
	//Fan 3
	//Cube
	glBegin(GL_QUADS);
	//Front face
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	//Right face
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	//Back face
	//glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Left Face
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Top Face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	//Bottom Face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-270.0f - rotateCeilingFan - 45.0f, 0.0f, 1.0f, 0.0f);
	//Fan 4
	//Cube
	glBegin(GL_QUADS);
	//Front face
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	//Right face
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	//Back face
	//glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Left Face
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Top Face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	//Bottom Face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glEnd();
}




void update(void)
{
	//CODE
	//Time watch
	/*second = 360.0f / 60.0f;
	minut = second / 60.0f;
	hour = minut / 60.0f;*/
	if (second <= 360.0f)
	{
		second = second + (0.01);
		minut = minut + (0.01 / 60.0f);
		hour = hour + (0.01 / (60.0f * 60.0f));
	}
	else
	{
		second = second - 360.0f;
	}

	//Fan
	rotateCeilingFan = rotateCeilingFan + 0.5f;
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



