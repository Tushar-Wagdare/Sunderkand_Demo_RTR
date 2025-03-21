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
FILE* gpFILE = NULL;//like struct   (gpFIE  globle pointer of type FILE)
HWND ghwnd = NULL;
BOOL gbActive = FALSE; 
DWORD dwStyle = 0;
WINDOWPLACEMENT wpPrev = { sizeof(WINDOWPLACEMENT) };
BOOL gbFullscreen = FALSE;
//*** OpenGL Related Globle Variables ***
PIXELFORMATDESCRIPTOR pfd;
int iPexelFormatIndex = 0;
HDC ghdc = NULL;
HGLRC ghrc = NULL;
//Framebuffer Animation
GLint count_for_color = 0;
GLfloat fbPointTranslate = 1.0f;
GLfloat fbPointPlace = 0.0f;
GLfloat red = 0.0f;
GLfloat green = 0.0f;
GLfloat blue = 0.0f;
GLfloat swapBuffers = 0.0f;
BOOL bFBfull = FALSE;
GLfloat xPipeTranslate = 0.0f;

//GLU 3D Shapes
GLUquadric* quadric = NULL;



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
	glClearColor(1.0f, 0.0f, 1.0f, 1.0f);


	//Initialize Quadric 
	quadric = gluNewQuadric();


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
	//Function declaration
	void fillBuffers(void);
	void drawPipe(void);

	//*** Code ***
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//3rd step - Compulasory (clears depth buffer)

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//----------------------------------------------------------------------------------------------------------------->
	//Buffer Sceen
	fillBuffers();

	//Ball Gun

	//Pipe
	drawPipe();







	SwapBuffers(ghdc);
}



void update(void)
{
	//Function declaration
	void updateBuffers(void);

	// Code
	updateBuffers();

	if (swapBuffers >= 180 && xPipeTranslate > -0.2f)
	{
		xPipeTranslate = xPipeTranslate - 0.001f;
	}
}



void fillBuffers(void)
{
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	glRotatef(swapBuffers, 0.0f, 1.0f, 0.0f);
	//1st FrameBuffer
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.518f, 0.26f, 0.0f);
	glVertex3f(1.49f, 0.26f, 0.0f);
	glVertex3f(1.49f, -0.25f, 0.0f);
	glVertex3f(0.518f, -0.25f, 0.0f);
	glEnd();
	//1st FrameBuffer OUTLET
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.49f, -0.25f, 0.0f);
	glVertex3f(1.49f, -0.20f, 0.0f);
	glVertex3f(1.55f, -0.20f, 0.0f);
	glVertex3f(1.55f, -0.25f, 0.0f);
	glEnd();
	//1st FrameBuffer Inlet
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.4f, 0.25f, 0.0f);
	glVertex3f(1.49f, 0.25f, 0.0f);
	glVertex3f(1.54f, 0.30f, 0.0f);
	glVertex3f(1.35f, 0.30f, 0.0f);
	glEnd();
	
	//2st FrameBuffer
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.518f, 0.26f, 0.0f);
	glVertex3f(-1.49f, 0.26f, 0.0f);
	glVertex3f(-1.49f, -0.25f, 0.0f);
	glVertex3f(-0.518f, -0.25f, 0.0f);
	glEnd();
	//2st FrameBuffer Inlet
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.49f, -0.25f, 0.0f);
	glVertex3f(-1.49f, -0.20f, 0.0f);
	glVertex3f(-1.55f, -0.20f, 0.0f);
	glVertex3f(-1.55f, -0.25f, 0.0f);
	glEnd();
	//2st FrameBuffer Outlet
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.4f, 0.25f, 0.0f);
	glVertex3f(-1.49f, 0.25f, 0.0f);
	glVertex3f(-1.54f, 0.30f, 0.0f);
	glVertex3f(-1.35f, 0.30f, 0.0f);
	glEnd();
	//WALL 2
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.52f, -0.25f, -0.01f);
	glVertex3f(-1.52f, -0.20f, -0.01f);
	glEnd();
	////Wall 1
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.52f, -0.25f, 0.0f);
	glVertex3f(1.52f, -0.20f, 0.0f);
	glEnd();


	//_______________________________________Filling The Framebuffer 1 ________________________________//
	glLoadIdentity();
	//glEnable(GL_POINT_SMOOTH);
	if (count_for_color <= (11 * 21))
	{
		//Fragments Falling Into Framebuffer
		glTranslatef(0.0f, 0.0f, -2.99f);

		glPointSize(20);
		glBegin(GL_POINTS);
		glColor3f(red, green, blue);
		glVertex3f(-1.45f, fbPointTranslate, 0.0f);
		glEnd();

		glLoadIdentity();
		glTranslatef(-1.45f, -0.22, -2.99f);
		//Variables For filling Frame Buffer
		float red1 = 0.0f;
		float green1 = 0.0f;
		float blue1 = 0.0f;
		float fbYTranslate = 0.0f;
		float fbXTranslate = 0.0f;
		float r = 0.0f;
		float g = 0.0f;
		float b = 0.0f;

		//____COLOR INTERPOLATION ____
		for (int i = 1; i <= count_for_color; i++)
		{
			glPointSize(20);
			glBegin(GL_POINTS);
			glColor3f(red1, green1, blue1);
			glVertex3f(fbXTranslate + (i * 0.045f) - 0.045, fbYTranslate, 0.0f);
			glEnd();

			if (i > 42 && i < 199)
			{
				//1st Line
				if (i > 45 && i < 59)
				{
					g = 59 - i;
					b = i - 44;

					red1 = 0.14f * 0;
					green1 = 1.0f * (g / 15);
					blue1 = 1.0f * (b / 15);
				}
				else
				{
					//2st Line
					if (i > 67 && i < 79)
					{
						g = 79 - i;
						b = i - 66;

						red1 = 0.14f * 2;
						green1 = 1.0f * (g / 15) * (0.14 * 8);
						blue1 = 1.0f * (b / 15) * (0.14 * 8);
					}
					else
					{
						//3st Line
						if (i > 89 && i < 99)
						{
							g = 99 - i;
							b = i - 88;

							red1 = 0.14f * 3;
							green1 = 1.0f * (g / 15) * (0.14 * 7);
							blue1 = 1.0f * (b / 15) * (0.14 * 7);
						}
						else
						{
							//4st Line
							if (i > 111 && i < 119)
							{
								g = 119 - i;
								b = i - 110;

								red1 = 0.14f * 4;
								green1 = 1.0f * (g / 15) * (0.14 * 5);
								blue1 = 1.0f * (b / 15) * (0.14 * 5);
							}
							else
							{
								//5st Line
								if (i > 133 && i < 139)
								{
									g = 139 - i;
									b = i - 132;

									red1 = 0.14f * 5;
									green1 = 1.0f * (g / 15) * (0.14 * 3);
									blue1 = 1.0f * (b / 15) * (0.14 * 3);
								}
								else
								{
									//6st Line
									if (i > 155 && i < 159)
									{
										g = 159 - i;
										b = i - 154;

										red1 = 0.14f * 6;
										green1 = 1.0f * (g / 15) * (0.14 * 1);
										blue1 = 1.0f * (b / 15) * (0.14 * 1);
									}
									else
									{
										//7st Line
										if (i > 177 && i < 179)
										{
											g = 179 - i;
											b = i - 176;

											red1 = 0.14f * 7;
											green1 = 1.0f * (g / 15) * (0.14 * 0);
											blue1 = 1.0f * (b / 15) * (0.14 * 0);
										}
										else
										{
											red1 = 0.0f;
											green1 = 0.0f;
											blue1 = 0.0f;
										}
									}
								}
							}
						}
					}
				}
				if (i % 21 == 0)
				{
					fbYTranslate = fbYTranslate + 0.045f;
					fbXTranslate = -(i * 0.045f);
				}
			}
			else
			{
				red1 = 0.0f;
				green1 = 0.0f;
				blue1 = 0.0f;
				if (i % 21 == 0)
				{
					fbYTranslate = fbYTranslate + 0.045f;
					fbXTranslate = -(i * 0.045f);
				}
			}
		}
	}
	else
	{
		bFBfull = TRUE;
		if (swapBuffers >= 180)
		{
			count_for_color = 0;
		}
	}
	//____ SWAPPING BUFFERS ______
	if (bFBfull)
	{
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -2.99f);
		glRotatef(swapBuffers, 0.0f, 1.0f, 0.0f);
		//Variables For filling Frame Buffer
		float red1 = 0.0f;
		float green1 = 0.0f;
		float blue1 = 0.0f;
		float fbYTranslate = 0.0f;
		float fbXTranslate = 0.0f;
		float r = 0.0f;
		float g = 0.0f;
		float b = 0.0f;

		for (int i = 1; i <= (11 * 21); i++)
		{
			//glPointSize(20);
			glBegin(GL_POINTS);
			glColor3f(red1, green1, blue1);
			glVertex3f(fbXTranslate + (i * 0.045f) - 0.045 - 1.45f, -0.22f + fbYTranslate, 0.0f);
			glEnd();

			if (i % 21 == 0)
			{
				fbYTranslate = fbYTranslate + 0.045f;
				fbXTranslate = -(i * 0.045f);
			}
			if (i > 42 && i < 199)
			{
				//1st Line
				if (i > 45 && i < 59)
				{
					g = 59 - i;
					b = i - 44;

					red1 = 0.14f * 0;
					green1 = 1.0f * (g / 15);
					blue1 = 1.0f * (b / 15);
				}
				else
				{
					//2st Line
					if (i > 67 && i < 79)
					{
						g = 79 - i;
						b = i - 66;

						red1 = 0.14f * 2;
						green1 = 1.0f * (g / 15) * (0.14 * 8);
						blue1 = 1.0f * (b / 15) * (0.14 * 8);
					}
					else
					{
						//3st Line
						if (i > 89 && i < 99)
						{
							g = 99 - i;
							b = i - 88;

							red1 = 0.14f * 3;
							green1 = 1.0f * (g / 15) * (0.14 * 7);
							blue1 = 1.0f * (b / 15) * (0.14 * 7);
						}
						else
						{
							//4st Line
							if (i > 111 && i < 119)
							{
								g = 119 - i;
								b = i - 110;

								red1 = 0.14f * 4;
								green1 = 1.0f * (g / 15) * (0.14 * 5);
								blue1 = 1.0f * (b / 15) * (0.14 * 5);
							}
							else
							{
								//5st Line
								if (i > 133 && i < 139)
								{
									g = 139 - i;
									b = i - 132;

									red1 = 0.14f * 5;
									green1 = 1.0f * (g / 15) * (0.14 * 3);
									blue1 = 1.0f * (b / 15) * (0.14 * 3);
								}
								else
								{
									//6st Line
									if (i > 155 && i < 159)
									{
										g = 159 - i;
										b = i - 154;

										red1 = 0.14f * 6;
										green1 = 1.0f * (g / 15) * (0.14 * 1);
										blue1 = 1.0f * (b / 15) * (0.14 * 1);
									}
									else
									{
										//7st Line
										if (i > 177 && i < 179)
										{
											g = 179 - i;
											b = i - 176;

											red1 = 0.14f * 7;
											green1 = 1.0f * (g / 15) * (0.14 * 0);
											blue1 = 1.0f * (b / 15) * (0.14 * 0);
										}
										else
										{
											red1 = 0.0f;
											green1 = 0.0f;
											blue1 = 0.0f;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	glDisable(GL_POINT_SMOOTH);
}


void drawPipe(void)
{
	glLoadIdentity();
	glTranslatef(1.7f + xPipeTranslate, -0.225f, -2.98f);
	glScalef(0.1f, 0.04f, 0.1f);

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);
	//glVertex3f(f, f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 0.5f, 0.0f);
	glVertex3f(1.0f, -0.5f, 0.0f);
	glVertex3f(10.0f, -0.5f, 0.0f);
	glVertex3f(10.0f, 0.5f, 0.0f);
	//glVertex3f(f, f, 0.0f);
	glEnd();
}


void updateBuffers(void)
{
	//*** Code ***
	if (fbPointTranslate >= -0.22)
	{
		fbPointTranslate = fbPointTranslate - 0.01f;
	}
	else
	{
		count_for_color++;
		fbPointTranslate = 1.0f;
		fprintf(gpFILE, "count_for_color = %d", count_for_color);

		if (count_for_color > 42 && count_for_color < 199)
		{
			float r = 0.0f;
			float g = 0.0f;
			float b = 0.0f;

			//1st Line
			if (count_for_color > 45 && count_for_color < 59)
			{
				g = 59 - count_for_color;
				b = count_for_color - 44;

				red = 0.14f * 0;
				green = 1.0f * (g / 15);
				blue = 1.0f * (b / 15);
			}
			else
			{
				//2st Line
				if (count_for_color > 67 && count_for_color < 79)
				{
					g = 79 - count_for_color;
					b = count_for_color - 66;

					red = 0.14f * 2;
					green = 1.0f * (g / 15) * (0.14 * 8);
					blue = 1.0f * (b / 15) * (0.14 * 8);
				}
				else
				{
					//3st Line
					if (count_for_color > 89 && count_for_color < 99)
					{
						g = 99 - count_for_color;
						b = count_for_color - 88;

						red = 0.14f * 3;
						green = 1.0f * (g / 15) * (0.14 * 7);
						blue = 1.0f * (b / 15) * (0.14 * 7);
					}
					else
					{
						//4st Line
						if (count_for_color > 111 && count_for_color < 119)
						{
							g = 119 - count_for_color;
							b = count_for_color - 110;

							red = 0.14f * 4;
							green = 1.0f * (g / 15) * (0.14 * 5);
							blue = 1.0f * (b / 15) * (0.14 * 5);
						}
						else
						{
							//5st Line
							if (count_for_color > 133 && count_for_color < 139)
							{
								g = 139 - count_for_color;
								b = count_for_color - 132;

								red = 0.14f * 5;
								green = 1.0f * (g / 15) * (0.14 * 3);
								blue = 1.0f * (b / 15) * (0.14 * 3);
							}
							else
							{
								//6st Line
								if (count_for_color > 155 && count_for_color < 159)
								{
									g = 159 - count_for_color;
									b = count_for_color - 154;

									red = 0.14f * 6;
									green = 1.0f * (g / 15) * (0.14 * 1);
									blue = 1.0f * (b / 15) * (0.14 * 1);
								}
								else
								{
									//7st Line
									if (count_for_color > 177 && count_for_color < 179)
									{
										g = 179 - count_for_color;
										b = count_for_color - 176;

										red = 0.14f * 7;
										green = 1.0f * (g / 15) * (0.14 * 0);
										blue = 1.0f * (b / 15) * (0.14 * 0);
									}
									else
									{
										red = 0.0f;
										green = 0.0f;
										blue = 0.0f;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (count_for_color >= (11 * 21) && swapBuffers <= 180)
	{
		swapBuffers = swapBuffers + 0.1f;
	}
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


	//*** PushPop Pointer Release ***
	if (quadric)
	{
		gluDeleteQuadric(quadric);
		quadric = NULL;
	}


	//*** Close Log File ***
	if (gpFILE)
	{
		fprintf(gpFILE, "Program Ended Successfully\n");
		fclose(gpFILE);
		gpFILE = NULL;
	}
}


