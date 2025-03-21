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

GLfloat p_angle = 0.0f;
GLfloat c_angle = 0.0f;

//Texture variable (object)

GLuint texture_astro = 0;
GLuint texture_ortho = 0;
GLuint texture_techused = 0;
GLuint texture_gmem = 0;
GLuint texture_gl = 0;
GLuint texture_sir = 0;
GLuint texture_madam = 0;

int fpp_scene_count = 0;


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

			case VK_SPACE:
				fpp_scene_count = fpp_scene_count + 1;
				if (fpp_scene_count >= 7)
				{
					fpp_scene_count = 0;
				}
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
	BOOL bResult;

	void resize(int, int);
	BOOL loadGLTexture(GLuint*, TCHAR[]);

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

	//Loading images to create texture
	bResult = loadGLTexture(&texture_astro, MAKEINTRESOURCE(MYIMAGE_ASTROMEDICOMP_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of Astro Texture Failed\n");
		return(-6);
	}

	bResult = loadGLTexture(&texture_ortho, MAKEINTRESOURCE(MYIMAGE_ORTHO_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of Ortho Texture Failed\n");
		return(-7);
	}

	bResult = loadGLTexture(&texture_techused, MAKEINTRESOURCE(MYIMAGE_TECHUSED_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of TechUsed Texture Failed\n");
		return(-8);
	}

	bResult = loadGLTexture(&texture_gmem, MAKEINTRESOURCE(MYIMAGE_GROUPMEMBERS_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of GroupMembers Texture Failed\n");
		return(-9);
	}

	bResult = loadGLTexture(&texture_gl, MAKEINTRESOURCE(MYIMAGE_GROUPLEADER_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of Ortho Texture Failed\n");
		return(-10);
	}

	bResult = loadGLTexture(&texture_sir, MAKEINTRESOURCE(MYIMAGE_SIR_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of Ortho Texture Failed\n");
		return(-11);
	}

	bResult = loadGLTexture(&texture_madam, MAKEINTRESOURCE(MYIMAGE_MADAM_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFile, "Loading of Ortho Texture Failed\n");
		return(-12);
	}

	//Tell openGL to enable the texture
	glEnable(GL_TEXTURE_2D);

	resize(WIN_WIDTH, WIN_HEIGHT);

	return(0);
}

BOOL loadGLTexture(GLuint* texture, TCHAR imageResourceID[])
{
	//Local variable declarations
	HBITMAP hBitmap = NULL;
	BITMAP bmp;

	hBitmap = (HBITMAP) LoadImage(GetModuleHandle(NULL), imageResourceID, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION); //DIB > Device Independent Bitmap

	if (hBitmap == NULL)
	{
		fprintf(gpFile, "Load Image Failed\n");
		return(FALSE);
	}

	//Get image data
	GetObject(hBitmap, sizeof(BITMAP), &bmp);

	//Create OpenGL texture object
	glGenTextures(1, texture);

	//Bind to the generted texture
	glBindTexture(GL_TEXTURE_2D, *texture);

	//Decide image pixel alignment & unpacking
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	//Set texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	//Create multiple mipmap images
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, bmp.bmWidth, bmp.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, (void*)bmp.bmBits);

	fprintf(gpFile, "%ld, %ld\n", bmp.bmWidth, bmp.bmHeight);
	//unbind
	glBindTexture(GL_TEXTURE_2D, 0);

	//Delete image resource
	DeleteObject(hBitmap);
	hBitmap = NULL;

	return(TRUE);

}

void resize(int width, int height)
{
	// Code
	if (height <= 0)
		height = 1;

	glMatrixMode(GL_PROJECTION); //Current Transformation Matrix
	glLoadIdentity();

	//gluPerspective(45.0f, 
	//	(GLfloat)width / (GLfloat)height, 
	//	0.1f, 
	//	100.0f); //45.0f is fovy *** (GLfloat)width / (GLfloat)height is ratio **** 0.1f is near, 100.0f is far.. near and far are not hard coded, they are standard.



	if (width <= height)
	{
		glOrtho(-100.0f,
			100.0f,
			-100.0f * ((GLfloat)height / (GLfloat)width),
			100.0f * ((GLfloat)height / (GLfloat)width),
			-100.0f,
			100.0f);
	}
	else
	{
		glOrtho(-100.0f * ((GLfloat)width / (GLfloat)height),
			100.0f * ((GLfloat)width / (GLfloat)height),
			-100.0f,
			100.0f,
			-100.0f,
			100.0f);
	}


	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void display(void) //He call kela jaen Game Loop madhe
{
	
	//Function Declarations
	void AstroMediComp(void);
	void Ortho(void);
	void TechUsed(void);
	void GroupMem(void);
	void GroupLead(void);
	void Sir(void);
	void Madam(void);

	// Code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //3rd test : Compulsory for Depth 3D.

	glMatrixMode(GL_MODELVIEW); //Current Transformation Matrix
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -6.0f);

	//glRotatef(p_angle, 0.0f, 1.0f, 0.0f);

	

	switch (fpp_scene_count)
	{
	case 0:
		AstroMediComp();
		break;

	case 1:
		Ortho();
		break;

	case 2:
		TechUsed();
		break;

	case 3:
		GroupMem();
		break;

	case 4:
		GroupLead();
		break;

	case 5:
		Sir();
		break;

	case 6:
		Madam();
		break;

	default:
		break;
	}


	SwapBuffers(ghdc);
}

void AstroMediComp(void)
{
	//Astromedicomp
	glBindTexture(GL_TEXTURE_2D, texture_astro);

	glBegin(GL_QUADS);

	//front face
	//glTexCoord2f(0.0, 0.0);
	glTexCoord2f(1.0, 1.0);

	glVertex3f(200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-200.0f, -100.0f, 1.0f);

	glTexCoord2f(1.0, 0.0);
	//glTexCoord2f(0.0, 1.0);
	glVertex3f(200.0f, -100.0f, 1.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Ortho(void)
{
	//Ortho
	glBindTexture(GL_TEXTURE_2D, texture_ortho);

	glBegin(GL_QUADS);

	//front face
	//glTexCoord2f(0.0, 0.0);
	glTexCoord2f(1.0, 1.0);

	glVertex3f(200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-200.0f, -100.0f, 1.0f);

	glTexCoord2f(1.0, 0.0);
	//glTexCoord2f(0.0, 1.0);
	glVertex3f(200.0f, -100.0f, 1.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}

void TechUsed(void)
{
	//Tech Used
	glBindTexture(GL_TEXTURE_2D, texture_techused);

	glBegin(GL_QUADS);

	//front face
	//glTexCoord2f(0.0, 0.0);
	glTexCoord2f(1.0, 1.0);

	glVertex3f(200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-200.0f, -100.0f, 1.0f);

	glTexCoord2f(1.0, 0.0);
	//glTexCoord2f(0.0, 1.0);
	glVertex3f(200.0f, -100.0f, 1.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}

void GroupMem(void)
{
	//GroupMem
	glBindTexture(GL_TEXTURE_2D, texture_gmem);

	glBegin(GL_QUADS);

	//front face
	//glTexCoord2f(0.0, 0.0);
	glTexCoord2f(1.0, 1.0);

	glVertex3f(200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-200.0f, -100.0f, 1.0f);

	glTexCoord2f(1.0, 0.0);
	//glTexCoord2f(0.0, 1.0);
	glVertex3f(200.0f, -100.0f, 1.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}

void GroupLead(void)
{
	//GL
	glBindTexture(GL_TEXTURE_2D, texture_gl);

	glBegin(GL_QUADS);

	//front face
	//glTexCoord2f(0.0, 0.0);
	glTexCoord2f(1.0, 1.0);

	glVertex3f(200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-200.0f, -100.0f, 1.0f);

	glTexCoord2f(1.0, 0.0);
	//glTexCoord2f(0.0, 1.0);
	glVertex3f(200.0f, -100.0f, 1.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}


void Sir(void)
{
	//Sir
	glBindTexture(GL_TEXTURE_2D, texture_sir);

	glBegin(GL_QUADS);

	//front face
	//glTexCoord2f(0.0, 0.0);
	glTexCoord2f(1.0, 1.0);

	glVertex3f(200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-200.0f, -100.0f, 1.0f);

	glTexCoord2f(1.0, 0.0);
	//glTexCoord2f(0.0, 1.0);
	glVertex3f(200.0f, -100.0f, 1.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Madam(void)
{
	//Madam
	glBindTexture(GL_TEXTURE_2D, texture_madam);

	glBegin(GL_QUADS);

	//front face
	//glTexCoord2f(0.0, 0.0);
	glTexCoord2f(1.0, 1.0);

	glVertex3f(200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-200.0f, -100.0f, 1.0f);

	glTexCoord2f(1.0, 0.0);
	//glTexCoord2f(0.0, 1.0);
	glVertex3f(200.0f, -100.0f, 1.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}


void update(void) //ithe update cha code tevach yeto jeva animation karaych asta
{
	// Code
	/*p_angle = p_angle + 0.3f;
	if (p_angle >= 360.0f)
	{
		p_angle = p_angle - 360.0f;
	}

	c_angle = c_angle - 0.2f;
	if (c_angle <= 0.0f)
	{
		c_angle = c_angle + 360.0f;
	}*/
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

	/*if (texture_kundali)
	{
		glDeleteTextures(1, &texture_kundali);
		texture_kundali = 0;
	}*/

	if (texture_astro)
	{
		glDeleteTextures(1, &texture_astro);
		texture_astro = 0;
	}

	// Close the log file
	if (gpFile)
	{
		fprintf(gpFile, "Program Ended Successfully!\n");
		fclose(gpFile);
		gpFile = NULL;
	}
}

