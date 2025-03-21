// Windows Header Files
#include <Windows.h>
#include "Headers/common/OGL.h"
#include "Headers/common/utilities.h"
#include <stdio.h>  
#include <stdlib.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>

// Our Header Files for SK_Chaupai_1
#include "Headers/SK_Chaupai_1/hanuman.h"
#include "Headers/SK_Chaupai_1/angad.h"
#include "Headers/SK_Chaupai_1/BaseScene1.h"
#include "Headers/SK_Chaupai_1/BaseScene2.h"
#include "Headers/SK_Chaupai_1/Jamwant.h"
#include "Headers/SK_Chaupai_1/wanersena.h"m
#include "Headers/SK_Chaupai_1/mainak_hanuman.h"
// Our Header Files for SK_Chaupai_2
#include "Headers/SK_Chaupai_2/hanuman.h"
#include "Headers/SK_Chaupai_2/sursa.h"
#include "Headers/SK_Chaupai_2/waterWithProps.h"
#include "Headers/SK_Chaupai_2/skyWithProps.h"
#include "Headers/SK_Chaupai_2/updateChaupai_2.h"

//link with OpenGL Library
#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "glu32.lib")
// Used For PlaySound (link)
#pragma comment(lib, "Winmm.lib")

//MACROS
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

//____________________ Global Variables Declarations ____________________________//
FILE* gpFILE                     = NULL;
HWND ghwnd                       = NULL;
BOOL gbActive                    = FALSE;
DWORD dwStyle                    = 0;
WINDOWPLACEMENT wpPrev           = { sizeof(WINDOWPLACEMENT) };
BOOL gbFullscreen                = FALSE;
//OpenGL related Global Variables
HDC ghdc                         = NULL;
HGLRC ghrc                       = NULL;


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM); //in _far memory


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
	int ScreenWidth    = GetSystemMetrics(SM_CXSCREEN); //1920
	int ScreenHeight   = GetSystemMetrics(SM_CYSCREEN); //1080
	int MyWindowWidth  = 800;
	int MyWindowHeight = 600;
	int x              = (ScreenWidth - MyWindowWidth) / 2;   // 560 
	int y              = (ScreenHeight - MyWindowHeight) / 2;   // 240

	//code
	gpFILE = fopen("Log.txt", "w");
	if (gpFILE == NULL)
	{
		MessageBox(NULL, TEXT("Log File Cannot Be Opened"), TEXT("Error"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	fprintf(gpFILE, "Program Started Successfully...\n");

	//wndclss Ex Initilization
	wndclass.cbSize        = sizeof(WNDCLASSEX);
	wndclass.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wndclass.cbClsExtra    = 0;
	wndclass.cbWndExtra    = 0;
	wndclass.lpfnWndProc   = WndProc;
	wndclass.hInstance     = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon         = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName  = NULL;
	wndclass.hIconSm       = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));


	//Register WNDCLASSEX
	RegisterClassEx(&wndclass);

	//Create Window
	hwnd = CreateWindowEx(
		WS_EX_APPWINDOW,
		szAppName,
		TEXT("SUNDERKAND - GRAPHICS PIPELINE MAPPING"),
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


	// GAME LOOP
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
				// RENDER
				display();

				// UPDATE
				update();
			}
		}
	}

	//UnInitilization
	uninitialise();

	

	return((int)msg.wParam);
}


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

		case 32:
			fprintf(gpFILE, "spacebar is pressed And gCount = %d......\n", gCount);
			//gCount++;
			break;

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

		case 'N':
		case 'n':
			short_sceen++;
			break;
		
		case 's':
		case 'S':
			sps1_scene = TRUE;
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

	//*********************HERE OPENGL STARTS*********************
	//Set the clear color of window to black
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	

	//GetLocalTime
	GetLocalTime(&localTime);

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
	//Current Time
	GetLocalTime(&currentTime);
	
	//****** Function Prototype ******
	void drawMainakParvat(void);
	void drawArrow(void);
	void sp_drawFillerScene2(void);
	void sp_draw_shadowHanuman(void);
	void draw_simhika(void);
	void draw_bird(void);
	void draw_shadowBird(void);
	void drawParvatChaupai3(void);
	//vb
	void draw_shadowHanuman(void);
	void resetVariables(void);
	void draw_bird1(void);
	//ab
	void lankaEntrance(void);
	void lankini(void);
	void AB_resetVariables(void);
	void draw_palace(void);
	void draw_lanka_parvat(void);
	void draw_hanumanji_back(void);
	// PlaySound's Chaupai One
	void ch1_bScene1_sound(void);
	void ch1_bScene2_sound(void);
	void ch1_bScene3_sound(void);
	void ch1_bScene4_sound(void);
	//PlaySound chaupai 2
	void ch2_part1_sound(void);
	void ch2_part2_sound(void);
	//PlaySound chaupai 3
	void ch3_part1_sound(void);
	void ch3_part2_sound(void);
	void ch3_part3_sound(void);
	//PlaySound chaupai 4
	void ch4_part1_sound(void);
	void ch4_part2_sound(void);
	void ch4_part3_sound(void);
	
	
	// CODE
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// **************************************************** Model Calls ************************************************
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	switch (gCount)
	{

	/****************************************** CHAUPAI 1 *****************************************/
	// Chaupai 1, Scene 1 (BaseScene)
	case 1:
		if (ch1_bScene1 == TRUE)
		{
			ch1_bScene1_sound();
		}

		drawBaseScene1();
		drawHanuman_chaupai_1();
		drawAngad();
		drawJamwant();
		drawWanerSena();
		break;

	// Chaupai 1, Scene 2(Filler)
	case 2:
		if (ch1_bScene2 == TRUE)
		{
			ch1_bScene2_sound();
		}

		drawBaseScene2();
		drawHanuman_SP1();
		break;

	// Chaupai 1, Scene 3(Filler Arrow & Shadow)
	case 3:
		if (ch1_bScene3 == TRUE)
		{
			ch1_bScene3_sound();
		}
		sp_drawFillerScene2();
		drawArrow();
		if (sps1_scene == TRUE)
		{
			sp_draw_shadowHanuman();
		}
		break;

	// Chaupai 1, Scene 4 (Mainak Parvat)
	case 4:
		if (ch1_bScene4 == TRUE)
		{
			ch1_bScene4_sound();
		}
		drawMainakParvat();
		drawHanuman_mainak_for_chaupai_1();
		break;
		
	/********************************************* CHAUPAI 2 ****************************************/
	// Chaupai 2, Scene 1
	case 5:
		if (ch2_part1 == TRUE && short_sceen == 1)
		{
			ch2_part1_sound();
		}
		if (ch2_part2 == TRUE && short_sceen == 3)
		{
			ch2_part2_sound();
		}
		drawSky();
		drawHanuman_chaupai_2();
		drawSursa();
		drawWater();
		break;

	case 6:

		if (ch3_part1 == TRUE && gTimeInSeconds > 190)
		{
			ch3_part1_sound();
		}

		//Draw Simhika
		glLoadIdentity();
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
		draw_simhika();
		//Shadow Bird
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -3.0f);
		draw_shadowBird();
		//Bird
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -3.0f);
		draw_bird();
		//Hanuman
		if (vbResetVariables == TRUE)
		{
		   resetVariables();
		   vbResetVariables = FALSE;
		}
		drawHanuman_chaupai_2();
		//Shadow Hanuman
		glLoadIdentity();
		glTranslatef(h_translate, s_translate, -3.0f);
		draw_shadowHanuman();
		break;

	case 7:

		if (ch3_part2 == TRUE)
		{
			ch3_part2_sound();
		}

		//Parvat
		drawParvatChaupai3();
		break;

	case 8:

		if (ch3_part3 == TRUE)
		{
			ch3_part3_sound();
		}

		//Palace
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -3.0f);
		glScalef(2.3f, 2.3f, 2.3f);
		draw_palace();
		//LAnka Parvat
		draw_lanka_parvat();
		//HAnuman Back 
		glLoadIdentity();
		glTranslatef(-0.6f, 0.0f, -3.0f);
		glScalef(0.7f, 0.7f, 1.0f);
		draw_hanumanji_back();
		//Bird
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -3.0f);
		draw_bird1();

		//Bird2
		glLoadIdentity();
		glTranslatef(-3.0f, 0.5f, -4.0f);
		draw_bird1();
		break;

		//Bird
		glLoadIdentity();
		glTranslatef(-6.0f, 0.0f, -3.0f);
		draw_bird1();

	// Lanka entrance gate and Hanuman lands in Lanka 
	case 9:
		if (ch4_part1 == TRUE && gTimeInSeconds >= 336.00f)
		{
			ch4_part1_sound();
		}
		//Lanka Gate
		lankaEntrance();
		if (ab_resetVariables)
		{
			AB_resetVariables();
			ab_resetVariables = FALSE;
		}
		//Hanuman
		drawHanuman_chaupai_2();
		break;

	// Lankini Daemon(normal show)
	case 10:
		if (ch4_part2 == TRUE)
		{
			ch4_part2_sound();
		}
		lankaEntrance();
		glLoadIdentity();
		lankini();
		drawHanuman_chaupai_2();
		break;

	//hanuman entry to lanka
	case 11:
		if (ch4_part3 == TRUE)
		{
			ch4_part3_sound();
		}
		lankaEntrance();
		drawHanuman_chaupai_2();
		break;

	case 12:
		lankaEntrance();
		break;
	default:
		break;
	}


	SwapBuffers(ghdc);
}


void update(void)
{
	//Time 
	GLdouble timeInMiliseconds = 0.000;
	GLdouble timeInSeconds     = 0.000;
	
	//Time Calculation in miliseconds
	timeInMiliseconds          = (((currentTime.wMinute * 60.0f * 1000.0f) + currentTime.wSecond * 1000.0f + ((currentTime.wMilliseconds))) - ((localTime.wMinute * 60.0f * 1000.0f) + localTime.wSecond * 1000.0f + ((localTime.wMilliseconds))));

	//Time in Seconds
	timeInSeconds              = (timeInMiliseconds / 1000.0000) + 0;
	gTimeInSeconds             = timeInSeconds;
	
	

	//Sceen LAdder Run On Time Calculation
	if (timeInSeconds >= 3.00)
	{
		// Base Scene, wanersena, jamwant, angad, hanumanji
		gCount = 1;
	}

	if (timeInSeconds >= 27.00)
	{
		// Filler Scene 1
		gCount = 2;
	}

	if (timeInSeconds >= 45.00)
	{
		// Filler Scene 2.1 // Arrow
		gCount = 3;
	}

	if (timeInSeconds >= 50.00)
	{
		// Filler Scene 2.2 // Hanumanji Shadow
		sps1_scene = TRUE;
	}

	if (timeInSeconds >= 55.00)
	{
		// Mainak Parwat
		gCount = 4;
	}

	if (timeInSeconds >= 85.00)
	{
		// Hanuman ji travels towords lanka
		gCount = 5;
		short_sceen = 1;
	}

	if (timeInSeconds >= 94.00)
	{
		//sursa comming up
		short_sceen = 2;
	}

	if (timeInSeconds >= 122.00)
	{
		//hanumanji talking sursa
		short_sceen = 3;
	}

	if (timeInSeconds >= 129.00)
	{
		//
			short_sceen = 4;
	}

	if (timeInSeconds >= 136.00)
	{
		//
		short_sceen = 5;
	}

	if (timeInSeconds >= 144.50)
	{
		//
		short_sceen = 6;
	}

	if (timeInSeconds >= 149.00)
	{
		//
		short_sceen = 7;
	}

	if (timeInSeconds >= 166.00)
	{
		//
		short_sceen = 8;
	}

	if (timeInSeconds >= 185.00)
	{
		//
		gCount = 6;
	}

	if (timeInSeconds >= 240.00)
	{
		//
		gCount = 7;
	}

	if (timeInSeconds >= 268.00)
	{
		//
		gCount = 8;
	}

	if (timeInSeconds >= 330.00)
	{
		// Chaupai 4
		gCount = 9;
	}

	if (timeInSeconds >= 349.00)
	{
		//
		gCount = 10;
	}

	if (timeInSeconds >= 375.00)
	{
		//
		gCount = 11;
	}

	if (timeInSeconds >= 393.00)
	{
		//
		gCount = 12;
	}


	
	fprintf(gpFILE, "time = %lf\n", timeInSeconds);
	//___________________________________________________________Chaupai 1_________________________________________________//
	switch (gCount)
	{
	case 1:
		// Animation for Caping angle of Tails And Jamwant's Hand
		if (cap_angle <= 10.0f && bool_tail_rotate == FALSE)
			cap_angle = cap_angle + 0.02f;
		else if (cap_angle >= 0.0f)
		{
			bool_tail_rotate = TRUE;
			cap_angle = cap_angle - 0.02f;
		}
		else
			bool_tail_rotate = FALSE;
		// Animation for Clouds, Birds 
		if (xMove >= -5.0f)
		{
			xMove += 0.0023;
		}
		break;


	case 2:
		// Filler scenes 1
		if (SP1_xScaleHanuman <= 2.2f)
		{
			SP1_xScaleHanuman += 0.005f;
			SP1_yScaleHanuman += 0.005f;
			SP1_zScaleHanuman += 0.005f;
		}
		else if (SP1_yHanuman <= 0.0f)
		{
			SP1_yHanuman += 0.5;
		}
		else if (SP1_xHanuman >= -2500.0f)
		{
			SP1_bHanumanRotate = TRUE;
			SP1_xHanuman -= 1.0f;
			SP1_yHanuman += 0.25f;
			SP1_zHanuman -= 0.7f;
		}
		break;


	case 3:
		// Filler scenes 2
		break;


	case 4:
		//_______________________________________Hanumanji Default Animation______________________________//
		//___Head___
		if (pss1_rHead <= 0.0f && pss1_bHead == FALSE)
		{
			pss1_rHead = pss1_rHead + 0.002f;
		}
		else if (pss1_rHead >= -2.0f)
		{
			pss1_bHead = TRUE;
			pss1_rHead = pss1_rHead - 0.002f;
		}
		else
		{
			pss1_bHead = FALSE;
		}
		//___Tail___
		if (pss1_rTail <= 5.0f && pss1_bTail == FALSE)
		{
			pss1_rTail = pss1_rTail + 0.03f;
		}
		else if (pss1_rTail >= -2.0f)
		{
			pss1_bTail = TRUE;
			pss1_rTail = pss1_rTail - 0.03f;
		}
		else
		{
			pss1_bTail = FALSE;
		}
		//___Leg___
		if (pss1_bHanumanRotate == TRUE && pss1_rotate_left_leg <= 12.0f && pss1_bRotateLeg == FALSE)
		{
			pss1_rotate_left_leg = pss1_rotate_left_leg + 0.03;
			pss1_rotate_right_leg = pss1_rotate_right_leg - 0.03;
		}
		else if (pss1_rotate_left_leg >= -5.0f && pss1_bHanumanRotate == TRUE)
		{
			pss1_bRotateLeg = TRUE;
			pss1_rotate_left_leg = pss1_rotate_left_leg - 0.03;
			pss1_rotate_right_leg = pss1_rotate_right_leg + 0.03;
		}
		else
		{
			pss1_bRotateLeg = FALSE;
		}

	    ///////////////////////////
		if (yMainakTranslate <= -0.3f)
		{
			yMainakTranslate += 0.001f;
		}
		//Hanumanji Flying Towords Lanka and Scalling
		if (pss1_xHanuman >= 100.0f)
		{
			pss1_xHanuman = pss1_xHanuman - 0.35f;
			pss1_zHanuman = pss1_zHanuman - 0.09f;
		}
		else if(pss1_yHanuman >= 99.2f && pss1_bHanuman == FALSE)
		{
			pss1_bHanumanRotate = FALSE;
			pss1_yHanuman -= 0.001;
		}
		else
		{
			pss1_bHanumanRotate = TRUE;
			pss1_bHanuman = TRUE;
			pss1_xHanuman = pss1_xHanuman - 0.35f;
			pss1_zHanuman = pss1_zHanuman - 0.09f;

		}
		// Animation for Clouds, Birds 
		if (mn_xMove >= -50.0f)
		{
			mn_xMove += 0.0023;
		}
		break;


	case 5:
		//__________________________________________________________ChauPai 2__________________________________________________________//
		//Default Baground Animation//
		//Water Animation Automation UPDATE
		if (xWater <= 25.0f && bWater == FALSE)
		{
			xWater = xWater + 0.06f;
			yWater = yWater + 0.04f;
		}
		else if (xWater >= 0.0f)
		{
			bWater = TRUE;
			xWater = xWater - 0.06f;
			yWater = yWater - 0.04f;
		}
		else
		{
			bWater = FALSE;
		}
		//Cloud Animation Automation
		if (xCloud <= 2000.0f)
		{
			xCloud = xCloud + 0.3f;
			yCloud = yCloud + 0.05f;
			zCloud = zCloud - 0.1;
		}
		else
		{
			xCloud = -800.0f;
			yCloud = -8.0f;
			zCloud = 1.0f;
		}
		//Bird Animation Automation
		if (zBird <= 900.0f)
		{
			xBird = xBird + 0.3f;
			yBird = yBird + 0.08f;
			zBird = zBird + 1.3f;
		}
		else
		{
			xBird = 0.0f;
			yBird = 0.0f;
			zBird = -9000.0f;
		}
		//_Hanumanji Default Animation//
		//___Head___
		if (rHead <= 0.0f && bHead == FALSE)
		{
			rHead = rHead + 0.011f;
		}
		else if (rHead >= -2.0f)
		{
			bHead = TRUE;
			rHead = rHead - 0.01f;
		}
		else
		{
			bHead = FALSE;
		}
		//___Tail___
		if (rTail <= 5.0f && bTail == FALSE)
		{
			rTail = rTail + 0.03f;
		}
		else if (rTail >= -2.0f)
		{
			bTail = TRUE;
			rTail = rTail - 0.03f;
		}
		else
		{
			bTail = FALSE;
		}
		//___Leg___
		if (bHanumanRotate == TRUE && rotate_left_leg <= 12.0f && bRotateLeg == FALSE)
		{
			rotate_left_leg = rotate_left_leg + 0.05;
			rotate_right_leg = rotate_right_leg - 0.05;
		}
		else if (rotate_left_leg >= -5.0f && bHanumanRotate == TRUE)
		{
			bRotateLeg = TRUE;
			rotate_left_leg = rotate_left_leg - 0.05;
			rotate_right_leg = rotate_right_leg + 0.05;
		}
		else
		{
			bRotateLeg = FALSE;
		}

		//Sursa Default Animation//
		//___Sursa Default Animation___
		if (sursa_rotate >= -10 && bSursa == FALSE)
		{
			sursa_rotate = sursa_rotate - 0.045;
			sursa_yTranslate = sursa_yTranslate + 0.0003;
		}
		else if (sursa_rotate <= 5)
		{
			bSursa = TRUE;
			sursa_rotate = sursa_rotate + 0.045;
			sursa_yTranslate = sursa_yTranslate - 0.0003;
		}
		else
		{
			bSursa = FALSE;
		}
		//****** Main Sceens Animation *****//
		switch (short_sceen)
		{
		case 1:
			//Hanumanji Flying Towords Lanka
			bHanumanRotate = TRUE;
			if (xHanuman >= 150.0f)
			{
				xHanuman = xHanuman - 0.9f;
				zHanuman = zHanuman + 0.35f;
			}
			break;

		case 2:
			//***** Sursa Transformations Update *****
			//____Sursa Comming Up___
			if (ySursa <= -30.0f)
			{
				ySursa = ySursa + 0.25f;
			}
			//Hanumanji Talking To Sursa
			if (ySursa >= -31.0f && yHanuman >= -30.0f)
			{
				bHanumanRotate = FALSE;
				yHanuman = yHanuman - 0.30f;
			}
			break;

		case 3://sceen minimize
			if (timeInSeconds > 125)
			{
				if (xScaleSursa >= 0.5f && sSursa == FALSE)
				{
					xScaleSursa = xScaleSursa - 0.012f;
					yScaleSursa = yScaleSursa - 0.012f;
					//zScaleSursa = zScaleSursa - 0.012f;

					xScaleHanuman = xScaleHanuman - 0.015f;
					yScaleHanuman = yScaleHanuman - 0.015f;
					//zScaleHanuman = zScaleHanuman - 0.015f;
				}
				else if (xScaleSursa <= 0.9f)
				{
					sSursa = TRUE;
					xScaleSursa = xScaleSursa + 0.0025f;
					yScaleSursa = yScaleSursa + 0.0025f;
					//zScaleSursa = zScaleSursa + 0.0015f;

				}
				else if (xScaleHanuman <= 1.2f && sSursa >= 0.89f /*&& zHanuman <= -65.0f*/)
				{
					xScaleHanuman = xScaleHanuman + 0.0025f;
					yScaleHanuman = yScaleHanuman + 0.0025f;
					zScaleHanuman = zScaleHanuman + 0.0015f;
					//zHanuman += 1.2f;
					//xHanuman -= 0.1f;
				}
			}
	
			break;

		case 4://sorah jojan mukh tehi thayahu
			if (xScaleSursa <= 1.4f)
			{
				xScaleSursa = xScaleSursa + 0.0025f;
				yScaleSursa = yScaleSursa + 0.0025f;
				//zScaleSursa = zScaleSursa + 0.0015f;
			}
			else if (xScaleHanuman <= 2.0f)
			{
				xScaleHanuman = xScaleHanuman + 0.0035f;
				yScaleHanuman = yScaleHanuman + 0.0035f;
				//zScaleHanuman = zScaleHanuman + 0.0015f;
			}
			break;

		case 5://jas jas sursa
			if (xScaleSursa <= 2.4f)
			{
				xScaleSursa = xScaleSursa + 0.0016f;
				yScaleSursa = yScaleSursa + 0.0016f;
				//zScaleSursa = zScaleSursa + 0.0015f;

				xScaleHanuman = xScaleHanuman + 0.0016f;
				yScaleHanuman = yScaleHanuman + 0.0016f;
				//zScaleHanuman = zScaleHanuman + 0.0015f;

				xHanuman = xHanuman + 0.01f;
			}
			break;

		case 6://sat jojan ati laghu rup pawansut linha 
			if (xScaleHanuman >= 0.1)
			{
				xScaleHanuman = xScaleHanuman - 0.006f;
				yScaleHanuman = yScaleHanuman - 0.006f;
				//zScaleHanuman = zScaleHanuman - 0.004f;

				yHanuman = yHanuman + 0.032f;
			}
			break;

		case 7://badan paithi puni baher avva
			if (xHanuman >= -220.0f && bHanuman == FALSE)
			{
				bHanumanRotate = TRUE;
				xHanuman = xHanuman - 0.9f;
				yHanuman = yHanuman + 0.008f;
			}
			else if (xHanuman <= 150)
			{
				bHanuman = TRUE;
				xHanuman = xHanuman + 0.9f;
			}
			else if (xScaleHanuman <= 1.0f)
			{
				bHanumanRotate = FALSE;
				xScaleHanuman = xScaleHanuman + 0.005f;
				yScaleHanuman = yScaleHanuman + 0.005f;
				//zScaleHanuman = zScaleHanuman + 0.005f;
			}
			break;

		case 8:
			if (ySursa >= -340.0f && xScaleSursa >= 1.0f)
			{
				ySursa = ySursa - 0.5f;
				xScaleSursa = xScaleSursa - 0.002f;
				yScaleSursa = yScaleSursa - 0.002f;
				//zScaleSursa = zScaleSursa - 0.001f;
			}
			else if (xHanuman >= -1500.0f)
			{
				bHanumanRotate = TRUE;
				xHanuman = xHanuman - 0.6f;
				yHanuman = yHanuman + 0.09f;
				zHanuman = zHanuman - 0.4;
			}
			break;
			
		default:
			break;
		}
		break;


		//_________________________________________________________Chaupai 3__________________________________________________________//
		case 6:
			// Code
			if(left_leg_rotate_simhika == TRUE && right_leg_rotate_simhika == TRUE)
			if (langle <= 10.0f && lRotate == FALSE)
			{
				langle += 0.05f;
			}
			else if (langle >= 0.0f)
			{
				lRotate = TRUE;
				langle -= 0.05f;
			}
			else
			{
				lRotate = FALSE;
			}
			////////////////////////////////////////
			if (rHead <= 0.0f && bHead == FALSE)
			{
				rHead = rHead + 0.011f;
			}
			else if (rHead >= -2.0f)
			{
				bHead = TRUE;
				rHead = rHead - 0.01f;
			}
			else
			{
				bHead = FALSE;
			}
			//___Tail___
			if (rTail <= 5.0f && bTail == FALSE)
			{
				rTail = rTail + 0.03f;
			}
			else if (rTail >= -2.0f)
			{
				bTail = TRUE;
				rTail = rTail - 0.03f;
			}
			else
			{
				bTail = FALSE;
			}
			//___Leg___
			if (bHanumanRotate == TRUE && rotate_left_leg <= 12.0f && bRotateLeg == FALSE)
			{
				rotate_left_leg = rotate_left_leg + 0.05;
				rotate_right_leg = rotate_right_leg - 0.05;
			}
			else if (rotate_left_leg >= -5.0f && bHanumanRotate == TRUE)
			{
				bRotateLeg = TRUE;
				rotate_left_leg = rotate_left_leg - 0.05;
				rotate_right_leg = rotate_right_leg + 0.05;
			}
			else
			{
				bRotateLeg = FALSE;
			}
			/////////////////////////////////////////
			if (xHanuman >= -1.2f)
			{
				xHanuman = xHanuman - 0.12f;
				zHanuman = zHanuman + 0.0009f;
			}
			else if (yHanuman >= 30.2f && bHanuman == FALSE)
			{
				bHanumanRotate = FALSE;
				yHanuman -= 0.095;
				if (xShadow >= 0)
				{
					xShadow -= 0.001f;
					yShadow -= 0.001f;
					zShadow -= 0.001f;
				}
			}
			else if (vb2 <= 0.4f) {
				hanumanKilledSimhika = TRUE;
				vb2 += 0.002f;
				left_leg_rotate_simhika = FALSE;
				right_leg_rotate_simhika = FALSE;
			}
			else
			{
				bHanumanRotate = TRUE;
				bHanuman = TRUE;
				xHanuman = xHanuman - 0.1f;
				yHanuman = yHanuman + 0.02f;
				zHanuman = zHanuman - 0.009f;
			}
			break;


		case 7:
			if (z2_translate <= -1.0f) {
				z2_translate += 0.0025f;
				y2_translate -= 0.0005f;
			}
			break;


		case 8:
			break;


		case 9:

			//Waves Animatiom
			if (abyScaleWave <= 1.1f && abWaves == TRUE)
			{
				abyScaleWave = abyScaleWave + 0.0007f;
			}
			else if (abyScaleWave >= 0.5f)
			{
				abyScaleWave = abyScaleWave - 0.0007f;
				abWaves = FALSE;
			}
			else
			{
				abWaves = TRUE;
			}

			// Animation for Clouds
			if (ab_xMove >= -5.0f)
			{
				ab_xMove += 0.0003;
			}
			//_Hanumanji Default Animation//
			//___Head___
			if (rHead <= 0.0f && bHead == FALSE)
			{
				rHead = rHead + 0.011f;
			}
			else if (rHead >= -2.0f)
			{
				bHead = TRUE;
				rHead = rHead - 0.01f;
			}
			else
			{
				bHead = FALSE;
			}
			//___Tail___
			if (rTail <= 5.0f && bTail == FALSE)
			{
				rTail = rTail + 0.03f;
			}
			else if (rTail >= -2.0f)
			{
				bTail = TRUE;
				rTail = rTail - 0.03f;
			}
			else
			{
				bTail = FALSE;
			}
			//___Leg___
			if (bHanumanRotate == TRUE && rotate_left_leg <= 12.0f && bRotateLeg == FALSE)
			{
				rotate_left_leg = rotate_left_leg + 0.05;
				rotate_right_leg = rotate_right_leg - 0.05;
			}
			else if (rotate_left_leg >= -5.0f && bHanumanRotate == TRUE)
			{
				bRotateLeg = TRUE;
				rotate_left_leg = rotate_left_leg - 0.05;
				rotate_right_leg = rotate_right_leg + 0.05;
			}
			else
			{
				bRotateLeg = FALSE;
			}
			///lanka gate
			if (xHanuman >= 70.0f)
			{
				bHanumanRotate = TRUE;
				xHanuman = xHanuman - 1.0f;
			}
			else if (yHanuman >= -100.0f)
			{
				bHanumanRotate = FALSE;
				yHanuman = yHanuman - 1.0f;
			}
			break;


		case 10:
			ab_xLanka = 2.2f;
			ab_yLanka = 2.2f;
			if (talvar_rotate <= 10.0f && bTalvar_rotate == FALSE) {
				talvar_rotate = talvar_rotate + 0.04f;
				//talvar_rotate = talvar_rotate - 10.0f;
			}
			else if (talvar_rotate >= 0.0f) {

				bTalvar_rotate = TRUE;
				talvar_rotate = talvar_rotate - 0.04f;
			}
			else {
				bTalvar_rotate = FALSE;
			}
			//_Hanumanji Default Animation//
			//___Head___
			if (rHead <= 0.0f && bHead == FALSE)
			{
				rHead = rHead + 0.011f;
			}
			else if (rHead >= -2.0f)
			{
				bHead = TRUE;
				rHead = rHead - 0.01f;
			}
			else
			{
				bHead = FALSE;
			}
			//___Tail___
			if (rTail <= 5.0f && bTail == FALSE)
			{
				rTail = rTail + 0.03f;
			}
			else if (rTail >= -2.0f)
			{
				bTail = TRUE;
				rTail = rTail - 0.03f;
			}
			else
			{
				bTail = FALSE;
			}
			///////////////////
			if (timeInSeconds >= 354.0)
			{

				if (xHanuman >= 0.0f) {
					xHanuman = xHanuman - 0.1f;
					xScaleHanuman = xScaleHanuman + 0.0005f;
					yScaleHanuman = yScaleHanuman + 0.0005f;
				}
				else if (ab_xRotate <= 90.0) {
					ab_hanuman = TRUE;
					ab_Xtranslate = ab_Xtranslate - 0.0005f;
					ab_Ytranslate = ab_Ytranslate - 0.0005f;
					ab_xRotate = ab_xRotate + 0.1f;
				}
			}

			break;


		case 11:
			ab_hanuman = FALSE;
			//_Hanumanji Default Animation//
			//___Head___
			if (rHead <= 0.0f && bHead == FALSE)
			{
				rHead = rHead + 0.011f;
			}
			else if (rHead >= -2.0f)
			{
				bHead = TRUE;
				rHead = rHead - 0.01f;
			}
			else
			{
				bHead = FALSE;
			}
			//___Tail___
			if (rTail <= 5.0f && bTail == FALSE)
			{
				rTail = rTail + 0.03f;
			}
			else if (rTail >= -2.0f)
			{
				bTail = TRUE;
				rTail = rTail - 0.03f;
			}
			else
			{
				bTail = FALSE;
			}
			//ending part
			if (xScaleHanuman >= 0.0f) {
				
				xScaleHanuman = xScaleHanuman - 0.0005f;
				yScaleHanuman = yScaleHanuman - 0.0005f;
			}
			else if (yHanuman >=0.0f){
				yHanuman = yHanuman - 0.1f;
			}
			break;


	default:
		break;
	}
}


void drawMainakParvat(void)
{
	GLfloat s = 100.0f;


	//

	// ************************** Sky And water ************************
	//********************** Background Color ************************

	void pss1_DrawCircle(GLenum, struct Circle);

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	glBegin(GL_QUADS);
	glColor3f(0.514, 0.647, 1.0f);
	glVertex3f(-250.0f / s, 250.0f / s, 0.0f);
	glColor3f(0.514, 0.647, 1.0f);
	glVertex3f(250.0f / s, 250.0f / s, 0.0f);
	glColor3f(0.812, 0.757, 0.706);
	glVertex3f(250.0f / s, -75.0f / s, 0.0f);
	glColor3f(0.812, 0.757, 0.706);
	glVertex3f(-250.0f / s, -75.0f / s, 0.0f);
	glEnd();


	// ************************** Brown Part ***************************
	glLoadIdentity();
	glTranslatef(-0.7f, yMainakTranslate, -2.0f);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.38, 0.243, 0.071);
	glVertex3f(-25.4f / s, -2.156f / s, 0.0f);
	glVertex3f(-25.5924f / s, -0.851087f / s, 0.0f);
	glVertex3f(-36.4287f / s, -4.13585f / s, 0.0f);
	glVertex3f(-41.6776f / s, -9.55403f / s, 0.0f);
	glVertex3f(-7.50926f / s, -9.8588f / s, 0.0f);
	glVertex3f(-12.0808f / s, -6.37085f / s, 0.0f);
	glVertex3f(-11.3358f / s, 0.571184f / s, 0.0f);
	glVertex3f(-17.5329f / s, 6.93754f / s, 0.0f);
	glVertex3f(-14.8577f / s, 13.778f / s, 0.0f);
	glVertex3f(-23.0006f / s, 6.39994f / s, 0.0f);
	glVertex3f(-25.5924f / s, -0.851087f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.49, 0.31, 0.09);
	glVertex3f(-37.0451f / s, -0.780314f / s, 0.0f);
	glVertex3f(-39.3072f / s, -1.86699f / s, 0.0f);
	glVertex3f(-51.2949f / s, -10.3329f / s, 0.0f);
	glVertex3f(-41.6776f / s, -9.55403f / s, 0.0f);
	glVertex3f(-36.4287f / s, -4.13585f / s, 0.0f);
	glVertex3f(-25.5924f / s, -0.851087f / s, 0.0f);
	glVertex3f(-23.0006f / s, 6.39994f / s, 0.0f);
	glVertex3f(-14.8577f / s, 13.778f / s, 0.0f);
	glVertex3f(-11.6282f / s, 17.0882f / s, 0.0f);
	glVertex3f(-6.24466f / s, 23.1154f / s, 0.0f);
	glVertex3f(-9.40454f / s, 29.084f / s, 0.0f);
	glVertex3f(-8.17569f / s, 34.0579f / s, 0.0f);
	glVertex3f(-15.0221f / s, 32.595f / s, 0.0f);
	glVertex3f(-26.1987f / s, 19.7214f / s, 0.0f);
	glVertex3f(-39.3072f / s, -1.86699f / s, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.49, 0.31, 0.09);
	glVertex3f(-9.30539f / s, 4.37002f / s, 0.0f);
	glVertex3f(-7.50926f / s, -9.8588f / s, 0.0f);
	glVertex3f(-12.0808f / s, -6.37085f / s, 0.0f);
	glVertex3f(-11.3358f / s, 0.571184f / s, 0.0f);
	glVertex3f(-17.5329f / s, 6.93754f / s, 0.0f);
	glVertex3f(-14.8577f / s, 13.778f / s, 0.0f);
	glVertex3f(-11.6282f / s, 17.0882f / s, 0.0f);
	glVertex3f(-6.71279f / s, 6.32122f / s, 0.0f);
	glVertex3f(-0.048436f / s, 3.88304f / s, 0.0f);
	glVertex3f(0.967471f / s, -1.96858f / s, 0.0f);
	glVertex3f(5.80319f / s, -5.54458f / s, 0.0f);
	glVertex3f(-5.29052f / s, -9.97393f / s, 0.0f);
	glVertex3f(-7.50926f / s, -9.8588f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.573, 0.353, 0.094);
	glVertex3f(4.11976f / s, 5.68046f / s, 0.0f);
	glVertex3f(3.45318f / s, 23.4136f / s, 0.0f);
	glVertex3f(6.90239f / s, 16.0225f / s, 0.0f);
	glVertex3f(7.054f / s, 7.5321f / s, 0.0f);
	glVertex3f(15.3928f / s, 2.26353f / s, 0.0f);
	glVertex3f(18.5387f / s, -3.87683f / s, 0.0f);
	glVertex3f(5.80319f / s, -5.54458f / s, 0.0f);
	glVertex3f(0.967471f / s, -1.96858f / s, 0.0f);
	glVertex3f(-0.048436f / s, 3.88304f / s, 0.0f);
	glVertex3f(-6.71279f / s, 6.32122f / s, 0.0f);
	glVertex3f(-11.6282f / s, 17.0882f / s, 0.0f);
	glVertex3f(-6.24466f / s, 23.1154f / s, 0.0f);
	glVertex3f(-9.40454f / s, 29.084f / s, 0.0f);
	glVertex3f(-8.17569f / s, 34.0579f / s, 0.0f);
	glVertex3f(1.10165f / s, 32.5605f / s, 0.0f);
	glVertex3f(3.45318f / s, 23.4136f / s, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.573, 0.353, 0.094);
	glVertex3f(23.1395f / s, 9.77381f / s, 0.0f);
	glVertex3f(35.2466f / s, -6.2784f / s, 0.0f);
	glVertex3f(21.2375f / s, 6.99387f / s, 0.0f);
	glVertex3f(12.5045f / s, 9.7684f / s, 0.0f);
	glVertex3f(10.6397f / s, 16.1717f / s, 0.0f);
	glVertex3f(3.45318f / s, 23.4136f / s, 0.0f);
	glVertex3f(3.45318f / s, 23.4136f / s, 0.0f);
	glVertex3f(1.10165f / s, 32.5605f / s, 0.0f);
	glVertex3f(8.5474f / s, 31.4188f / s, 0.0f);
	glVertex3f(20.5552f / s, 20.6482f / s, 0.0f);
	glVertex3f(28.6969f / s, 7.13942f / s, 0.0f);
	glVertex3f(47.4818f / s, -8.09776f / s, 0.0f);
	glVertex3f(35.2466f / s, -6.2784f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.49, 0.31, 0.09);
	glVertex3f(11.9144f / s, 8.97002f / s, 0.0f);
	glVertex3f(35.2466f / s, -6.2784f / s, 0.0f);
	glVertex3f(21.2375f / s, 6.99387f / s, 0.0f);
	glVertex3f(12.5045f / s, 9.7684f / s, 0.0f);
	glVertex3f(10.6397f / s, 16.1717f / s, 0.0f);
	glVertex3f(3.45318f / s, 23.4136f / s, 0.0f);
	glVertex3f(6.90239f / s, 16.0225f / s, 0.0f);
	glVertex3f(7.054f / s, 7.5321f / s, 0.0f);
	glVertex3f(15.3928f / s, 2.26353f / s, 0.0f);
	glVertex3f(18.5387f / s, -3.87683f / s, 0.0f);
	glVertex3f(35.2466f / s, -6.2784f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.702, 0.455, 0.094);
	glVertex3f(21.8756f / s, 21.0255f / s, 0.0f);
	glVertex3f(9.78912f / s, 33.2428f / s, 0.0f);
	glVertex3f(23.1478f / s, 21.7853f / s, 0.0f);
	glVertex3f(23.1478f / s, 21.7853f / s, 0.0f);
	glVertex3f(28.6969f / s, 7.13942f / s, 0.0f);
	glVertex3f(20.5552f / s, 20.6482f / s, 0.0f);
	glVertex3f(8.5474f / s, 31.4188f / s, 0.0f);
	glVertex3f(1.10165f / s, 32.5605f / s, 0.0f);
	glVertex3f(9.78912f / s, 33.2428f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.38, 0.243, 0.071);
	glVertex3f(-40.3885f / s, -0.445272f / s, 0.0f);
	glVertex3f(-51.2949f / s, -10.3329f / s, 0.0f);
	glVertex3f(-39.3072f / s, -1.86699f / s, 0.0f);
	glVertex3f(-26.1987f / s, 19.7214f / s, 0.0f);
	glVertex3f(-15.0221f / s, 32.595f / s, 0.0f);
	glVertex3f(-28.0127f / s, 20.9503f / s, 0.0f);
	glVertex3f(-41.2374f / s, 0.469593f / s, 0.0f);
	glVertex3f(-63.7789f / s, -11.8575f / s, 0.0f);
	glVertex3f(-51.2949f / s, -10.3329f / s, 0.0f);
	glEnd();

	// ******************* Plane Brown Part (change with our water color while rising if) **********************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.38, 0.243, 0.071);
	glVertex3f(-4.47182f / s, -31.2442f / s, 0.0f);
	glVertex3f(80.187f / s, -32.7595f / s, 0.0f);
	glVertex3f(43.412f / s, -32.608f / s, 0.0f);
	glVertex3f(-51.598f / s, -32.7595f / s, 0.0f);
	glVertex3f(-83.0894f / s, -32.7595f / s, 0.0f);
	glVertex3f(-63.7789f / s, -11.8575f / s, 0.0f);
	glVertex3f(-51.2949f / s, -10.3329f / s, 0.0f);
	glVertex3f(-41.6776f / s, -9.55403f / s, 0.0f);
	glVertex3f(-7.50926f / s, -9.8588f / s, 0.0f);
	glVertex3f(5.80319f / s, -5.54458f / s, 0.0f);
	glVertex3f(18.5387f / s, -3.87683f / s, 0.0f);
	glVertex3f(35.2466f / s, -6.2784f / s, 0.0f);
	glVertex3f(47.4818f / s, -8.09776f / s, 0.0f);
	glVertex3f(80.187f / s, -32.7595f / s, 0.0f);
	glEnd();


	//********************** Water Color *******************************
	// water waves
	for (int i = 0; i <= 70; i += 5)
	{
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -3.0f);
		for (int j = -250; j <= 250; j += 25)
		{
			struct Circle circle01;

			circle01.color.r = 0.0f;
			circle01.color.g = 0.718f;
			circle01.color.b = 0.984f;
			circle01.center.xCoordinate = j / s;
			circle01.center.yCoordinate = (-75.0f + -i) / s;
			circle01.angle.from = 0.0f;
			circle01.angle.to = 180.0f;
			circle01.radius.xAxis = 25.0f / s;
			circle01.radius.yAxis = 15.0f / s;

			pss1_DrawCircle(GL_TRIANGLE_FAN, circle01);
		}
	}

	//water bottom plane color
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.718, 0.984);
	glVertex3f(-2.5f, -0.9f, 0.0f);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-2.5f, -1.5f, 0.0f);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(2.5f, -1.5f, 0.0f);

	glColor3f(0.0, 0.718, 0.984);
	glVertex3f(2.5f, -0.9f, 0.0f);
	glEnd();

	// bird 2
	glLoadIdentity();
	glTranslatef(-2.0f, 5.2f, -10.0f);
	glTranslatef(mn_xMove + 0.3, 3.2f - mn_xMove, -11.0f * mn_xMove);

	glBegin(GL_TRIANGLES);
	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, 0.2f, 0.0f);
	glVertex3f(-0.1f, 0.05f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.3f, 0.0f);
	glVertex3f(-0.2f, -0.1f, 0.0f);
	glEnd();

	// bird 3
	glLoadIdentity();
	//glTranslatef(-3.0f, 1.8f, -10.0f);
	glTranslatef(mn_xMove + 0.5, 2.2f, -11.0f);

	glBegin(GL_TRIANGLES);
	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, 0.2f, 0.0f);
	glVertex3f(-0.1f, 0.05f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.3f, 0.0f);
	glVertex3f(-0.2f, -0.1f, 0.0f);
	glEnd();
}

void drawArrow(void)
{
	//For Arrow
	if (arrow_y_translate <= 1.0f && arrow_y_scale >= 0.0f)
	{
		arrow_y_translate += 0.019f / 2.0f;
		arrow_y_scale -= 0.0097f / 2.0f;
	}

	glLoadIdentity();
	glTranslatef(0.0f, arrow_y_translate, arrow_z_translate);
	glScalef(arrow_x_scale, arrow_y_scale, 0.0f);

	// Top Triangle
	glBegin(GL_POLYGON);
	glColor3f(0.647, 0.165, 0.165);
	glVertex3f(7.04506f / s, 47.6946f / s, 0.0f);
	glVertex3f(0.0f / s, 65.0556f / s, 0.0f);
	glVertex3f(0.0f / s, 51.4687f / s, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.647, 0.165, 0.165);
	glVertex3f(-7.04506f / s, 47.6946f / s, 0.0f);
	glVertex3f(0.0f / s, 65.0556f / s, 0.0f);
	glVertex3f(0.0f / s, 51.4687f / s, 0.0f);
	glEnd();

	// Line
	glLineWidth(5);
	glBegin(GL_LINES);
	glColor3f(0.647, 0.165, 0.165);
	glVertex3f(0.0f / s, 51.4687f / s, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f / s, -58.8827f / s, 0.0f);
	glEnd();

	// Down Part 1
	glBegin(GL_POLYGON);
	glColor3f(0.804, 0.498, 0.196);
	glVertex3f(7.04506f / s, -51.2553f / s, 0.0f);
	glVertex3f(7.04506f / s, -30.7202f / s, 0.0f);
	glVertex3f(0.377866f / s, -23.8751f / s, 0.0f);
	glVertex3f(0.377866f / s, -44.8014f / s, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.804, 0.498, 0.196);
	glVertex3f(-7.04506f / s, -51.2553f / s, 0.0f);
	glVertex3f(-7.04506f / s, -30.7202f / s, 0.0f);
	glVertex3f(-0.377866f / s, -23.8751f / s, 0.0f);
	glVertex3f(-0.377866f / s, -44.8014f / s, 0.0f);
	glEnd();

	// Down Part 2 (Bottom Most)
	glBegin(GL_POLYGON);
	glColor3f(0.647, 0.165, 0.165);
	glVertex3f(7.04506f / s, -65.7277f / s, 0.0f);
	glVertex3f(7.04506f / s, -55.1668f / s, 0.0f);
	glVertex3f(0.377866f / s, -48.7128f / s, 0.0f);
	glVertex3f(0.377866f / s, -58.8827f / s, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.647, 0.165, 0.165);
	glVertex3f(-7.04506f / s, -65.7277f / s, 0.0f);
	glVertex3f(-7.04506f / s, -55.1668f / s, 0.0f);
	glVertex3f(-0.377866f / s, -48.7128f / s, 0.0f);
	glVertex3f(-0.377866f / s, -58.8827f / s, 0.0f);
	glEnd();
}

void sp_drawFillerScene2(void)
{
	GLfloat d = 150.0f;
	//Function Prototype

	//Waves Animatiom
	if (yScaleWave <= 1.1f && bWaves == TRUE)
	{
		yScaleWave = yScaleWave + 0.0007f;
	}
	else if (yScaleWave >= 0.5f)
	{
		yScaleWave = yScaleWave - 0.0007f;
		bWaves = FALSE;
	}
	else
	{
		bWaves = TRUE;
	}



	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);



	/////////////////
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


	glBegin(GL_POLYGON);
	glColor3f(0.357, 0.584, 0.796);
	glVertex3f(150.0f / d, 100.0f / d, 0.0f);

	glColor3f(0.357, 0.584, 0.796);
	glVertex3f(-150.0f / d, 100.0f / d, 0.0f);

	glColor3f(0.678, 0.812, 0.953);
	glVertex3f(-150.0f / d, 33.0f / d, 0.0f);

	glColor3f(0.773, 0.875, 0.949);
	glVertex3f(-150.0f / d, 14.0f / d, 0.0f);

	glColor3f(0.773, 0.875, 0.949);
	glVertex3f(150.0f / d, 14.0f / d, 0.0f);

	glColor3f(0.678, 0.812, 0.953);
	glVertex3f(150.0f / d, 33.0f / d, 0.0f);

	glEnd();



	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.718, 0.984);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(150.0f / d, 14.0f / d, 0.0f);
	glVertex3f(-150.0f / d, 14.0f / d, 0.0f);
	glVertex3f(-150.0f / d, -10.0f / d, 0.0f);
	glVertex3f(-130.0f / d, -20.0f / d, 0.0f);
	glVertex3f(-100.0f / d, -30.0f / d, 0.0f);
	glVertex3f(-80.0f / d, -32.0f / d, 0.0f);
	glVertex3f(-60.0f / d, -33.0f / d, 0.0f);
	glVertex3f(-40.0f / d, -34.6f / d, 0.0f);
	glVertex3f(-10.0f / d, -35.0f / d, 0.0f);
	glVertex3f(10.0f / d, -35.0f / d, 0.0f);
	glVertex3f(30.0f / d, -34.0f / d, 0.0f);
	glVertex3f(50.0f / d, -33.5f / d, 0.0f);
	glVertex3f(70.0f / d, -32.0f / d, 0.0f);
	glVertex3f(90.0f / d, -30.0f / d, 0.0f);
	glVertex3f(100.0f / d, -28.0f / d, 0.0f);
	glVertex3f(130.0f / d, -20.0f / d, 0.0f);
	glVertex3f(150.0f / d, -10.0f / d, 0.0f);
	glVertex3f(150.0f / d, 14.0f / d, 0.0f);
	glEnd();


	//Sea waves

	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(26.05f / d, -8.88f / d, 0.0f);
	glVertex3f(24.658f / d, -10.148f / d, 0.0f);
	glVertex3f(21.657f / d, -10.8745f / d, 0.0f);
	glVertex3f(26.3636f / d, -11.0324f / d, 0.0f);
	glVertex3f(30.564f / d, -11.0324f / d, 0.0f);
	glVertex3f(27.722f / d, -9.93f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.4f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(26.05f / d, -8.88f / d, 0.0f);
	glVertex3f(24.658f / d, -10.148f / d, 0.0f);
	glVertex3f(21.657f / d, -10.8745f / d, 0.0f);
	glVertex3f(26.3636f / d, -11.0324f / d, 0.0f);
	glVertex3f(30.564f / d, -11.0324f / d, 0.0f);
	glVertex3f(27.722f / d, -9.93f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_POLYGON);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(61.13f / d, 0.66f / d, 0.0f);
	glVertex3f(60.26f / d, -0.16f / d, 0.0f);
	glVertex3f(58.54f / d, -0.85f / d, 0.0f);
	glVertex3f(61.35f / d, -0.94f / d, 0.0f);
	glVertex3f(64.0f / d, -0.62f / d, 0.0f);
	glVertex3f(62.17f / d, -0.16f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


	//
	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(65.67f / d, -15.63f / d, 0.0f);
	glVertex3f(63.0f / d, -17.0f / d, 0.0f);
	glVertex3f(68.0f / d, -17.0f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(68.0f / d, -5.2f / d, 0.0f);
	glVertex3f(66.0f / d, -6.0f / d, 0.0f);
	glVertex3f(70.0f / d, -6.0f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(79.0f / d, -12.8f / d, 0.0f);
	glVertex3f(77.0f / d, -14.5f / d, 0.0f);
	glVertex3f(81.0f / d, -14.5f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(26.0f / d, 0.56f / d, 0.0f);
	glVertex3f(24.0f / d, -0.68f / d, 0.0f);
	glVertex3f(28.0f / d, -0.46f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(26.0f / d, -8.9f / d, 0.0f);
	glVertex3f(21.0f / d, -10.8f / d, 0.0f);
	glVertex3f(30.0f / d, -10.62f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(12.0f / d, -18.9f / d, 0.0f);
	glVertex3f(10.0f / d, -20.8f / d, 0.0f);
	glVertex3f(15.0f / d, -19.9f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-17.5f / d, -11.0f / d, 0.0f);
	glVertex3f(-21.5f / d, -13.4f / d, 0.0f);
	glVertex3f(-13.22f / d, -13.09f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-17.5f / d, -11.0f / d, 0.0f);
	glVertex3f(-21.5f / d, -13.4f / d, 0.0f);
	glVertex3f(-13.22f / d, -13.09f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.6f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-34.4f / d, -11.12f / d, 0.0f);
	glVertex3f(-38.16f / d, -13.08f / d, 0.0f);
	glVertex3f(-29.5f / d, -13.4f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-67.11f / d, -11.39f / d, 0.0f);
	glVertex3f(-70.88f / d, -13.37f / d, 0.0f);
	glVertex3f(-62.68f / d, -13.08f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-67.11f / d, -11.39f / d, 0.0f);
	glVertex3f(-70.88f / d, -13.37f / d, 0.0f);
	glVertex3f(-62.68f / d, -13.08f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.3f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-56.0f / d, -8.0f / d, 0.0f);
	glVertex3f(-61.0f / d, -10.2f / d, 0.0f);
	glVertex3f(-54.8f / d, -10.3f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-71.0f / d, 4.5f / d, 0.0f);
	glVertex3f(-74.0f / d, 3.5f / d, 0.0f);
	glVertex3f(-69.0f / d, 3.5f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-43.25f / d, -2.33f / d, 0.0f);
	glVertex3f(-45.4f / d, -3.7f / d, 0.0f);
	glVertex3f(-41.8f / d, -3.7f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-58.3f / d, 2.08f / d, 0.0f);
	glVertex3f(-61.5f / d, 0.73f / d, 0.0f);
	glVertex3f(-56.4f / d, 0.5f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


	glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-95.6f / d, -10.8f / d, 0.0f);
	glVertex3f(-98.0f / d, -12.12f / d, 0.0f);
	glVertex3f(-94.0f / d, -12.35f / d, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


	/*glScalef(xScaleWave, yScaleWave, 1.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-98.0f / d, 9.16f / d, 0.0f);
	glVertex3f(-98.7f / d, 7.9f / d, 0.0f);
	glVertex3f(-96.0f / d, 8.2f / d, 0.0f);
	glEnd();
	glLoadIdentity();*/

	//glTranslatef(0.0f, 0.0f, -3.0f);
	//glBegin(GL_LINE_STRIP);
	//for (int i = 0; i < 360; i++)
	//{
	//	float y = 0.0f;
	//	float x = 0.0f;
	//	float theta = i * (M_PI / 180.0f);
	//	y = sin(theta);
	//	glVertex3f(x, y, 0.0f);
	//	x = x + 0.1f;
	//}
	//glEnd();
	//glLoadIdentity();
	/*glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);*/

	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	//dark-sea mountain
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.18, 0.388);
	glVertex3f(-44.3f / d, 13.65f / d, 0.0f);
	glVertex3f(-53.26f / d, 17.27f / d, 0.0f);
	glVertex3f(-62.31f / d, 22.48f / d, 0.0f);
	glVertex3f(-72.46f / d, 17.65f / d, 0.0f);
	glVertex3f(-67.4f / d, 13.08f / d, 0.0f);
	glEnd();

	//light-sea mountain
	glBegin(GL_POLYGON);
	glColor3f(0.357, 0.584, 0.8);
	glVertex3f(-67.4f / d, 13.08f / d, 0.0f);
	glVertex3f(-72.46f / d, 17.65f / d, 0.0f);
	glVertex3f(-78.84f / d, 21.68f / d, 0.0f);
	glVertex3f(-82.12f / d, 20.44f / d, 0.0f);
	glVertex3f(-86.87f / d, 17.84f / d, 0.0f);
	glVertex3f(-97.14f / d, 22.564f / d, 0.0f);
	glVertex3f(-106.9f / d, 13.08f / d, 0.0f);
	glEnd();



	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.984, 0.855, 0.714);

	glVertex3f(0.0f / d, -46.0f / d, 0.0f);
	glVertex3f(150.0f / d, -10.0f / d, 0.0f);
	glVertex3f(130.0f / d, -20.0f / d, 0.0f);
	glVertex3f(100.0f / d, -28.0f / d, 0.0f);
	glVertex3f(90.0f / d, -30.0f / d, 0.0f);
	glVertex3f(70.0f / d, -32.0f / d, 0.0f);
	glVertex3f(50.0f / d, -33.5f / d, 0.0f);
	glVertex3f(30.0f / d, -34.0f / d, 0.0f);
	glVertex3f(10.0f / d, -35.0f / d, 0.0f);
	glVertex3f(-10.0f / d, -35.0f / d, 0.0f);
	glVertex3f(-40.0f / d, -34.6f / d, 0.0f);
	glColor3f(0.851, 0.467, 0.141);
	glVertex3f(-60.0f / d, -33.0f / d, 0.0f);
	glColor3f(0.984, 0.855, 0.714);
	glVertex3f(-80.0f / d, -32.0f / d, 0.0f);
	glVertex3f(-100.0f / d, -30.0f / d, 0.0f);
	glVertex3f(-130.0f / d, -20.0f / d, 0.0f);
	glVertex3f(-150.0f / d, -10.0f / d, 0.0f);
	glColor3f(1.0, 0.788, 0.502);
	glVertex3f(-150.0f / d, -100.0f / d, 0.0f);
	glColor3f(0.851, 0.467, 0.141);
	glVertex3f(150.0f / d, -100.0f / d, 0.0f);
	glColor3f(1.0, 0.788, 0.502);
	glVertex3f(150.0f / d, -10.0f / d, 0.0f);
	glEnd();


	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -0.9f);


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.984, 0.788, 0.584);
	glVertex3f(0.0f / d, -46.0f / d, 0.0f);
	glVertex3f(150.0f / d, -10.0f / d, 0.0f);
	glVertex3f(130.0f / d, -20.0f / d, 0.0f);
	glVertex3f(100.0f / d, -28.0f / d, 0.0f);
	glVertex3f(90.0f / d, -30.0f / d, 0.0f);
	glVertex3f(70.0f / d, -32.0f / d, 0.0f);
	glVertex3f(50.0f / d, -33.5f / d, 0.0f);
	glVertex3f(30.0f / d, -34.0f / d, 0.0f);
	glVertex3f(10.0f / d, -35.0f / d, 0.0f);
	glVertex3f(-10.0f / d, -35.0f / d, 0.0f);
	glVertex3f(-40.0f / d, -34.6f / d, 0.0f);
	glColor3f(0.851, 0.467, 0.141);
	glVertex3f(-60.0f / d, -33.0f / d, 0.0f);
	glColor3f(0.984, 0.855, 0.714);
	glVertex3f(-80.0f / d, -32.0f / d, 0.0f);
	glVertex3f(-100.0f / d, -30.0f / d, 0.0f);
	glVertex3f(-130.0f / d, -20.0f / d, 0.0f);
	glVertex3f(-150.0f / d, -10.0f / d, 0.0f);
	glColor3f(1.0, 0.788, 0.502);
	glVertex3f(-150.0f / d, -100.0f / d, 0.0f);
	glColor3f(0.851, 0.467, 0.141);
	glVertex3f(150.0f / d, -100.0f / d, 0.0f);
	glColor3f(1.0, 0.788, 0.502);
	glVertex3f(150.0f / d, -10.0f / d, 0.0f);
	glEnd();


	////startfish
	//glLoadIdentity();
	//glScalef(0.5f, 0.5f, 0.5f);
	//glTranslatef(0.0f, 0.0f, -1.2f);
	//glBegin(GL_POLYGON);
	//glColor3f(0.773, 0.545, 0.62);
	//glVertex3f(-31.4301f / d, -42.2346f / d, 0.0f);
	//glVertex3f(-34.6897f / d, -38.1602f / d, 0.0f);
	//glVertex3f(-36.1565f / d, -42.3976f / d, 0.0f);
	//glVertex3f(-41.5347f / d, -43.0495f / d, 0.0f);
	//glVertex3f(-38.6011f / d, -47.287f / d, 0.0f);
	//glVertex3f(-40.5569f / d, -52.6653f / d, 0.0f);
	//glVertex3f(-34.0377f / d, -48.1019f / d, 0.0f);
	//glVertex3f(-28.4965f / d, -50.8725f / d, 0.0f);
	//glVertex3f(-29.8003f / d, -45.8202f / d, 0.0f);
	//glVertex3f(-26.2148f / d, -42.0717f / d, 0.0f);
	//glEnd();


	//glPointSize(6.0f);
	//glBegin(GL_POINTS);
	//glColor3f(0.741, 0.451, 0.71);
	//glVertex3f(-33.6846f / d, -43.294f / d, 0.0f);
	//glVertex3f(-36.0756f / d, -44.5705f / d, 0.0f);
	//glVertex3f(-34.6897f / d, -38.1602f / d, 0.0f);
	//glVertex3f(-35.4882f / d, -46.8884f / d, 0.0f);
	//glVertex3f(-31.7611f / d, -47.299f / d, 0.0f);
	//glVertex3f(-31.458f / d, -44.478f / d, 0.0f);
	//glEnd();


	glPointSize(9.0f);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	glColor3f(0.043, 0.471, 0.624);
	glVertex3f(-82.4453f / d, -42.1433f / d, 0.0f);
	glEnd();

	glPointSize(9.0f);
	glBegin(GL_POINTS);
	glColor3f(0.043, 0.471, 0.624);
	glVertex3f(-82.7282f / d, -44.0296f / d, 0.0f);
	glEnd();


	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.3f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

	//Rock 1
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(130.0f / d, -20.0f / d, 0.0f);
	glVertex3f(170.0f / d, -30.0f / d, 0.0f);
	glVertex3f(175.0f / d, -15.0f / d, 0.0f);
	glVertex3f(170.0f / d, 0.0f / d, 0.0f);
	glVertex3f(150.0f / d, 14.0f / d, 0.0f);
	glVertex3f(130.0f / d, 10.0f / d, 0.0f);
	glVertex3f(116.0f / d, 3.35f / d, 0.0f);
	glVertex3f(110.0f / d, -10.0f / d, 0.0f);
	glVertex3f(100.0f / d, -29.0f / d, 0.0f);
	glVertex3f(90.0f / d, -44.565f / d, 0.0f);
	glVertex3f(105.0f / d, -44.565f / d, 0.0f);
	glVertex3f(119.0f / d, -54.0f / d, 0.0f);
	glVertex3f(128.0f / d, -60.0f / d, 0.0f);
	glVertex3f(138.0f / d, -53.565f / d, 0.0f);
	glVertex3f(140.0f / d, -53.5f / d, 0.0f);
	glVertex3f(173.0f / d, -53.7f / d, 0.0f);
	glVertex3f(170.0f / d, -30.0f / d, 0.0f);
	glEnd();

	//Rock 2
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -1.7f);

	glScalef(1.1f, 1.1f, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.502, 0.502, 0.502);
	glVertex3f(173.0f / d, -54.0f / d, 0.0f);
	glVertex3f(184.0f / d, -63.0f / d, 0.0f);
	glVertex3f(186.0f / d, -41.0f / d, 0.0f);
	glVertex3f(170.0f / d, -30.0f / d, 0.0f);
	glVertex3f(150.0f / d, -44.56f / d, 0.0f);
	glVertex3f(147.0f / d, -61.18f / d, 0.0f);
	glVertex3f(142.0f / d, -71.18f / d, 0.0f);
	glVertex3f(160.0f / d, -76.18f / d, 0.0f);
	glVertex3f(175.0f / d, -73.18f / d, 0.0f);
	glVertex3f(184.0f / d, -63.0f / d, 0.0f);
	glEnd();



	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(63.0f / d, 36.0f / d, 0.0f);
	glVertex3f(73.24f / d, 35.6627f / d, 0.0f);
	glVertex3f(69.379f / d, 36.1867f / d, 0.0f);
	glVertex3f(67.4796f / d, 37.4966f / d, 0.0f);
	glVertex3f(65.9076f / d, 37.1036f / d, 0.0f);
	glVertex3f(65.2527f / d, 38.3481f / d, 0.0f);
	glVertex3f(63.9427f / d, 38.9375f / d, 0.0f);
	glVertex3f(62.5018f / d, 38.5446f / d, 0.0f);
	glVertex3f(61.7713f / d, 37.6931f / d, 0.0f);
	glVertex3f(60.6024f / d, 37.5621f / d, 0.0f);
	glVertex3f(59.5544f / d, 35.5972f / d, 0.0f);
	glVertex3f(57.131f / d, 35.3352f / d, 0.0f);
	glVertex3f(56.869f / d, 34.5492f / d, 0.0f);
	glVertex3f(60.6678f / d, 33.9597f / d, 0.0f);
	glVertex3f(62.2398f / d, 33.8288f / d, 0.0f);
	glVertex3f(63.0912f / d, 33.1083f / d, 0.0f);
	glVertex3f(63.9427f / d, 32.9773f / d, 0.0f);
	glVertex3f(64.6632f / d, 33.6978f / d, 0.0f);
	glVertex3f(65.6456f / d, 33.3703f / d, 0.0f);
	glVertex3f(67.3486f / d, 33.5668f / d, 0.0f);
	glVertex3f(68.6585f / d, 33.8288f / d, 0.0f);
	glVertex3f(69.4445f / d, 34.6802f / d, 0.0f);
	glVertex3f(73.24f / d, 35.6627f / d, 0.0f);
	glEnd();



	/*glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


	glLoadIdentity();
	glTranslatef(-1.0f, 0.0f, -1.1f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	*/



	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -0.88f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

	//Trunk
	glBegin(GL_POLYGON);
	glColor3f(0.635, 0.212, 0.0);
	glVertex3f(-94.0f / d, -35.596f / d, 0.0f);
	glVertex3f(-92.5356f / d, -31.644f / d, 0.0f);
	glVertex3f(-90.7754f / d, -26.7547f / d, 0.0f);
	glVertex3f(-89.0153f / d, -20.8875f / d, 0.0f);
	glVertex3f(-86.864f / d, -13.6512f / d, 0.0f);
	glVertex3f(-84.7126f / d, -2.30796f / d, 0.0f);
	glVertex3f(-85.1038f / d, 5.71057f / d, 0.0f);
	glVertex3f(-87.4507f / d, -1.52566f / d, 0.0f);
	glVertex3f(-89.602f / d, -12.2822f / d, 0.0f);
	glVertex3f(-92.1445f / d, -20.1052f / d, 0.0f);
	glVertex3f(-93.709f / d, -25.5813f / d, 0.0f);
	glVertex3f(-95.8465f / d, -30.6413f / d, 0.0f);
	glVertex3f(-97.4738f / d, -35.2309f / d, 0.0f);
	glEnd();

	//Leaves
	//1
	glBegin(GL_POLYGON);
	glColor3f(0.176, 0.337, 0.0);
	glVertex3f(-85.1038f / d, 5.71057f / d, 0.0f);
	glVertex3f(-92.1445f / d, 3.36368f / d, 0.0f);
	glVertex3f(-95.8604f / d, -4.06812f / d, 0.0f);
	glVertex3f(-90.1887f / d, 0.625649f / d, 0.0f);
	glEnd();

	//2
	glBegin(GL_POLYGON);
	glColor3f(0.176, 0.337, 0.0);
	glVertex3f(-85.1038f / d, 5.71057f / d, 0.0f);
	glVertex3f(-88.8197f / d, 9.81762f / d, 0.0f);
	glVertex3f(-97.8161f / d, 11.5778f / d, 0.0f);
	glVertex3f(-92.34f / d, 7.66631f / d, 0.0f);
	glEnd();

	//3
	glBegin(GL_POLYGON);
	glColor3f(0.176, 0.337, 0.0);
	glVertex3f(-85.1038f / d, 5.71057f / d, 0.0f);
	glVertex3f(-83.0288f / d, 10.9923f / d, 0.0f);
	glVertex3f(-85.0095f / d, 14.6706f / d, 0.0f);
	glVertex3f(-86.1413f / d, 11.6525f / d, 0.0f);
	glEnd();

	//4
	glBegin(GL_POLYGON);
	glColor3f(0.176, 0.337, 0.0);
	glVertex3f(-85.1038f / d, 5.71057f / d, 0.0f);
	glVertex3f(-78.7846f / d, 9.01163f / d, 0.0f);
	glVertex3f(-77.6528f / d, 12.0297f / d, 0.0f);
	glVertex3f(-80.4823f / d, 10.2377f / d, 0.0f);
	glEnd();

	//5
	glBegin(GL_POLYGON);
	glColor3f(0.176, 0.337, 0.0);
	glVertex3f(-85.1038f / d, 5.71057f / d, 0.0f);
	glVertex3f(-77.9358f / d, 4.20151f / d, 0.0f);
	glVertex3f(-71.0507f / d, 4.01288f / d, 0.0f);
	glVertex3f(-77.6528f / d, 7.50258f / d, 0.0f);
	glEnd();

	//5
	glBegin(GL_POLYGON);
	glColor3f(0.176, 0.337, 0.0);
	glVertex3f(-85.1038f / d, 5.71057f / d, 0.0f);
	glVertex3f(-79.6277f / d, -2.11239f / d, 0.0f);
	glVertex3f(-74.5428f / d, -5.43714f / d, 0.0f);
	glVertex3f(-78.2587f / d, 0.821223f / d, 0.0f);
	glEnd();

}

void draw_bird(void)
{
	//switch case for wings movement
	switch (dir)
	{
	case up:
		//if (rwAngle > 270.0f)
		//	rwAngle -= 0.01f;

		if (lwAngle <= 65.0f)
			lwAngle += 0.3f;
		else
			dir = down;

		break;
	case down:

		if (lwAngle >= 0.0f)
			lwAngle -= 0.3f;
		else
		{
			dir = up;
			//lwAngle = 180.0f;
		}


	default:
		break;
	}

	switch (scene)
	{
	case 1:
		if (x_translate <= -0.5)
			x_translate += 0.001;
		else scene = 2;

		glTranslatef(x_translate, y_translate, 0.0f);
		glScalef(xScale, yScale, zScale);
		break;

	case 2:
		if (body_angle < 85.0f)
			body_angle += 0.1f;
		else
		{
			scene = 3;
			fly_flag = 0;
		}
		glTranslatef(x_translate, y_translate, 0.0f);
		glRotatef(body_angle, 0, 0, 1);
		glScalef(xScale, yScale, zScale);
		break;
	case 3:
		if (x_translate <= 0.0f && xScale >= 0.0) {
			y_translate -= 0.002;
			xScale -= 0.001;
			yScale -= 0.001;
			zScale -= 0.001;

		}
		glTranslatef(x_translate, y_translate, 0.0f);
		glRotatef(body_angle, 0, 0, 1);
		glScalef(xScale, yScale, zScale);
		break;
	}


	//torse
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.36f, 0.54f, 0.64f);
	glVertex3f(-4.27 / s, -10.17f / s, 0.0f);
	glVertex3f(9.07f / s, -6.12f / s, 0.0f);

	//
	glVertex3f(8.4f / s, -2.2f / s, 0.0f);
	glVertex3f(0.24f / s, -2.37f / s, 0.0f);
	glVertex3f(-7.2f / s, -2.75f / s, 0.0f);
	//	glVertex3f(-13.28f / s, -5.07f / s, 0.0f);
	glVertex3f(-15.67f / s, -2.56f / s, 0.0f);



	//glVertex3f(-16.01f / s, -8.3f / s, 0.0f);

	//glVertex3f(-6.3f / s, -6.6f / s, 0.0f);
	glVertex3f(-16.01f / s, -8.3f / s, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-24.6f / s, -13.64f / s, 0.0f);
	glVertex3f(-20.06f / s, -13.3f / s, 0.0f);
	glVertex3f(-23.76f / s, -17.23f / s, 0.0f);
	glColor3f(0.36f, 0.54f, 0.64f);
	glVertex3f(-16.3f / s, -15.3f / s, 0.0f);
	glVertex3f(-8.78f / s, -18.79f / s, 0.0f);
	glVertex3f(3.81f / s, -17.98f / s, 0.0f);
	glVertex3f(14.22f / s, -12.31f / s, 0.0f);
	glVertex3f(11.04f / s, -8.38f / s, 0.0f);
	glVertex3f(9.07f / s, -6.12f / s, 0.0f);
	glEnd();

	//torso- 2
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.1f, 0.1f);
	glVertex3f(-4.27 / s, -10.17f / s, 0.0f);
	glVertex3f(-6.3f / s, -6.6f / s, 0.0f);
	glVertex3f(-12.144f / s, -8.32f / s, 0.0f);
	glVertex3f(-13.76f / s, -12.31f / s, 0.0f);
	glVertex3f(-11.97f / s, -14.05f / s, 0.0f);
	glVertex3f(-5.26f / s, -14.63f / s, 0.0f);
	glVertex3f(-4.16f / s, -13.01f / s, 0.0f);
	glVertex3f(6.47f / s, -9.42f / s, 0.0f);
	glVertex3f(1.9f / s, -6.41f / s, 0.0f);
	glVertex3f(-6.3f / s, -6.6f / s, 0.0f);
	glEnd();




	//head and neck
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(23.99f / s, -9.54f / s, 0.0f);
	glVertex3f(30.7f / s, -8.38f / s, 0.0f);
	glVertex3f(29.02f / s, -6.18f / s, 0.0f);
	glVertex3f(25.32f / s, -6.18f / s, 0.0f);
	glVertex3f(21.91f / s, -7.92f / s, 0.0f);
	glVertex3f(11.04f / s, -8.38f / s, 0.0f);
	glVertex3f(14.22f / s, -12.31f / s, 0.0f);
	glVertex3f(22.2f / s, -10.98f / s, 0.0f);
	glVertex3f(30.01f / s, -11.1f / s, 0.0f);
	glVertex3f(30.7f / s, -8.38f / s, 0.0f);
	glEnd();

	//eyes
	glPointSize(0.01f);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(27.839f / s, -7.75f / s, 0.0f);
	glEnd();

	//beak
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(30.7f / s, -8.38f / s, 0.0f);
	glVertex3f(30.01f / s, -11.1f / s, 0.0f);
	glVertex3f(33.79f / s, -11.1f / s, 0.0f);
	glEnd();

	//	glTranslatef(0.0f, y_translate, 0.0f);
	if (fly_flag)
		glRotatef(lwAngle, 1, 0, 0);
	//left wing
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3f(0.0f / s, 0.0f / s, 0.0f);
	glVertex3f(9.07f / s, -6.12f / s, 0.0f);
	glVertex3f(9.46f / s, 1.21f / s, 0.0f);
	glVertex3f(18.57f / s, 13.96f / s, 0.0f);
	glVertex3f(20.89f / s, 25.45f / s, 0.0f);
	glColor3f(0.36f, 0.54f, 0.64f);
	glVertex3f(8.70f / s, 19.78f / s, 0.0f);

	glVertex3f(1.26f / s, 11.84f / s, 0.0f);
	glVertex3f(-11.94f / s, -7.06f / s, 0.0f);
	//glVertex3f(18.57f / s, 13.96f / s, 0.0f);
	glVertex3f(9.07f / s, -6.12f / s, 0.0f);

	glEnd();

	//right wing
	if (fly_flag)
		glRotatef(rwAngle, 1, 0, 0);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3f(-12.39f / s, 0.0f / s, 0.0f);
	glVertex3f(1.90f / s, -6.41f / s, 0.0f);
	glVertex3f(-8.1f / s, 3.73f / s, 0.0f);
	glVertex3f(-18.88f / s, 11.41f / s, 0.0f);

	glVertex3f(-32.03f / s, 20.34f / s, 0.0f);
	glColor3f(0.36f, 0.54f, 0.64f);
	glVertex3f(-30.4f / s, 11.52f / s, 0.0f);
	glVertex3f(-22.94f / s, 2.32f / s, 0.0f);
	glVertex3f(-13.36f / s, -7.73f / s, 0.0f);
	glVertex3f(1.90f / s, -6.41f / s, 0.0f);
	glEnd();

}

void draw_bird2(void) {

	switch (dir1)
	{
	case up:
		//if (rwAngle1 > 270.0f)
		//	rwAngle1 -= 0.01f;

		if (lwAngle1 <= 65.0f)
			lwAngle1 += 0.3f;
		else
			dir1 = down;

		break;
	case down:

		if (lwAngle1 >= 0.0f)
			lwAngle1 -= 0.3f;
		else
		{
			dir1 = up;
			//lwAngle1 = 180.0f;
		}


	default:
		break;
	}

	switch (scene1)
	{
	case 1:
		if (x_translate1 <= -0.5)
			x_translate1 += 0.001;
		else scene1 = 2;

		glTranslatef(x_translate1, y_translate1, 0.0f);
		glScalef(xScale1, yScale1, zScale1);
		break;

	case 2:
		if (body_angle1 < 85.0f)
			body_angle1 += 0.8f;
		else
		{
			scene1 = 3;
			fly_flag1 = 0;
		}
		glTranslatef(x_translate1, y_translate1, 0.0f);
		glRotatef(body_angle1, 0, 0, 1);
		glScalef(xScale1, yScale1, zScale1);
		break;
	case 3:
		if (y_translate1 >= 0.0f && xScale1 >= -1.0) {
			y_translate1 -= 0.003;
			xScale1 -= 0.0004;
			yScale1 -= 0.0004;
			zScale1 -= 0.0004;

		}
		glTranslatef(x_translate1, y_translate1, 0.0f);
		glRotatef(body_angle1, 0, 0, 1);
		glScalef(xScale, yScale, zScale);
		break;
	}


	//torse
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.36f, 0.54f, 0.64f);
	glVertex3f(-4.27 / s, -10.17f / s, 0.0f);
	glVertex3f(9.07f / s, -6.12f / s, 0.0f);

	//
	glVertex3f(8.4f / s, -2.2f / s, 0.0f);
	glVertex3f(0.24f / s, -2.37f / s, 0.0f);
	glVertex3f(-7.2f / s, -2.75f / s, 0.0f);
	//	glVertex3f(-13.28f / s, -5.07f / s, 0.0f);
	glVertex3f(-15.67f / s, -2.56f / s, 0.0f);



	//glVertex3f(-16.01f / s, -8.3f / s, 0.0f);

	//glVertex3f(-6.3f / s, -6.6f / s, 0.0f);
	glVertex3f(-16.01f / s, -8.3f / s, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-24.6f / s, -13.64f / s, 0.0f);
	glVertex3f(-20.06f / s, -13.3f / s, 0.0f);
	glVertex3f(-23.76f / s, -17.23f / s, 0.0f);
	glColor3f(0.36f, 0.54f, 0.64f);
	glVertex3f(-16.3f / s, -15.3f / s, 0.0f);
	glVertex3f(-8.78f / s, -18.79f / s, 0.0f);
	glVertex3f(3.81f / s, -17.98f / s, 0.0f);
	glVertex3f(14.22f / s, -12.31f / s, 0.0f);
	glVertex3f(11.04f / s, -8.38f / s, 0.0f);
	glVertex3f(9.07f / s, -6.12f / s, 0.0f);
	glEnd();

	//torso- 2
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.1f, 0.1f);
	glVertex3f(-4.27 / s, -10.17f / s, 0.0f);
	glVertex3f(-6.3f / s, -6.6f / s, 0.0f);
	glVertex3f(-12.144f / s, -8.32f / s, 0.0f);
	glVertex3f(-13.76f / s, -12.31f / s, 0.0f);
	glVertex3f(-11.97f / s, -14.05f / s, 0.0f);
	glVertex3f(-5.26f / s, -14.63f / s, 0.0f);
	glVertex3f(-4.16f / s, -13.01f / s, 0.0f);
	glVertex3f(6.47f / s, -9.42f / s, 0.0f);
	glVertex3f(1.9f / s, -6.41f / s, 0.0f);
	glVertex3f(-6.3f / s, -6.6f / s, 0.0f);
	glEnd();




	//head and neck
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(23.99f / s, -9.54f / s, 0.0f);
	glVertex3f(30.7f / s, -8.38f / s, 0.0f);
	glVertex3f(29.02f / s, -6.18f / s, 0.0f);
	glVertex3f(25.32f / s, -6.18f / s, 0.0f);
	glVertex3f(21.91f / s, -7.92f / s, 0.0f);
	glVertex3f(11.04f / s, -8.38f / s, 0.0f);
	glVertex3f(14.22f / s, -12.31f / s, 0.0f);
	glVertex3f(22.2f / s, -10.98f / s, 0.0f);
	glVertex3f(30.01f / s, -11.1f / s, 0.0f);
	glVertex3f(30.7f / s, -8.38f / s, 0.0f);
	glEnd();

	//eyes
	glPointSize(0.01f);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(27.839f / s, -7.75f / s, 0.0f);
	glEnd();

	//beak
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(30.7f / s, -8.38f / s, 0.0f);
	glVertex3f(30.01f / s, -11.1f / s, 0.0f);
	glVertex3f(33.79f / s, -11.1f / s, 0.0f);
	glEnd();

	//	glTranslatef(0.0f, y_translate1, 0.0f);
	if (fly_flag1)
		glRotatef(lwAngle1, 1, 0, 0);
	//left wing
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3f(0.0f / s, 0.0f / s, 0.0f);
	glVertex3f(9.07f / s, -6.12f / s, 0.0f);
	glVertex3f(9.46f / s, 1.21f / s, 0.0f);
	glVertex3f(18.57f / s, 13.96f / s, 0.0f);
	glVertex3f(20.89f / s, 25.45f / s, 0.0f);
	glColor3f(0.36f, 0.54f, 0.64f);
	glVertex3f(8.70f / s, 19.78f / s, 0.0f);

	glVertex3f(1.26f / s, 11.84f / s, 0.0f);
	glVertex3f(-11.94f / s, -7.06f / s, 0.0f);
	//glVertex3f(18.57f / s, 13.96f / s, 0.0f);
	glVertex3f(9.07f / s, -6.12f / s, 0.0f);

	glEnd();

	//right wing
	if (fly_flag1)
		glRotatef(rwAngle1, 1, 0, 0);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3f(-12.39f / s, 0.0f / s, 0.0f);
	glVertex3f(1.90f / s, -6.41f / s, 0.0f);
	glVertex3f(-8.1f / s, 3.73f / s, 0.0f);
	glVertex3f(-18.88f / s, 11.41f / s, 0.0f);

	glVertex3f(-32.03f / s, 20.34f / s, 0.0f);
	glColor3f(0.36f, 0.54f, 0.64f);
	glVertex3f(-30.4f / s, 11.52f / s, 0.0f);
	glVertex3f(-22.94f / s, 2.32f / s, 0.0f);
	glVertex3f(-13.36f / s, -7.73f / s, 0.0f);
	glVertex3f(1.90f / s, -6.41f / s, 0.0f);
	glEnd();

}

void draw_simhika(void) {

	GLfloat s = 100.0f;

	//water
	glLoadIdentity();
	glTranslatef(xSimhika, ySimhika, zSimhika);



	glBegin(GL_QUADS);
	//glColor3f(0.109f, 0.525f, 0.713f);
	//glColor3f(0.67f, 0.85f, 0.89f);
	glColor3f(0.46f, 0.70f, 0.77f);
	glVertex3f(-350.1 / s, 350.02 / s, 0.0f);
	glVertex3f(-350.6 / s, -350.26 / s, 0.0f);
	glColor3f(0.67f, 0.85f, 0.89f);
	glVertex3f(350.75 / s, -350.06 / s, 0.0f);
	glColor3f(0.023f, 0.223f, 0.439f);
	glVertex3f(350.75 / s, 350.47 / s, 0.0f);
	glEnd();


	glRotatef(180.0, 0.0f, 0.0f, 1.0f);
	glScalef(simhika_xScale, simhika_yScale, simhika_zScale);
	//blood
	glLoadIdentity();
	if (hanumanKilledSimhika == TRUE) {
		glTranslatef(-0.4, -0.2f, -3.0f);
		//glScalef(0.2f, 0.2f, 0.2f);
		float vb = 0.0f;
		float vb1 = 0.0f;
		//const float vb2 = 0.0f; //rad
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		for (float angle = 0.0f; angle <= 360.0; angle = angle++)
		{
			vb = cos(angle) * vb2;
			vb1 = sin(angle) * vb2;

			glVertex3f(vb, vb1, 0.0f);

		}
		glEnd();

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		for (float angle = 0.0f; angle <= 360.0; angle = angle++)
		{
			vb = cos(angle) * vb2;
			vb1 = sin(angle) * vb2;

			glVertex3f(vb, vb1, 0.0f);

		}
		glEnd();

		glPointSize(10.0f);
		glBegin(GL_POINTS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-0.2f, 0.0f, 0.0f);
		glVertex3f(0.0f, -0.4f, 0.0f);
		glVertex3f(0.0f, -0.8f, 0.0f);

		glEnd();

		glPointSize(10.0f);
		glBegin(GL_POINTS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(27.839f / s, -7.75f / s, 0.0f);
		glVertex3f(0.0f, -0.4f, 0.0f);
		glVertex3f(0.0f, -0.8f, 0.0f);

		glEnd();

		//glLoadIdentity();
		//if (left_leg_rotate_simhika == FALSE && right_leg_rotate_simhika == FALSE) {
		//	
		//}

	}



	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	glRotatef(90, 0, 0, 1);

	//hair

	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-8.0f / s, 30.0f / s, 0.0f / s);
	glVertex3f(13.0f / s, 5.0f / s, 0.0f / s);
	glVertex3f(13.0f / s, 14.0f / s, 0.0f / s);
	glVertex3f(12.0f / s, 21.0f / s, 0.0f / s);
	glVertex3f(15.0f / s, 23.0f / s, 0.0f / s);
	glVertex3f(11.0f / s, 45.0f / s, 0.0f / s);
	glVertex3f(5.0f / s, 49.0f / s, 0.0f / s);
	glVertex3f(5.0f / s, 45.0f / s, 0.0f / s);
	glVertex3f(1.0f / s, 58.0f / s, 0.0f / s);
	glVertex3f(1.0f / s, 62.0f / s, 0.0f / s);
	glVertex3f(-1.0f / s, 64.0f / s, 0.0f / s);
	glVertex3f(-1.0f / s, 68.0f / s, 0.0f / s);
	glVertex3f(-4.0f / s, 70.0f / s, 0.0f / s);
	glVertex3f(-4.0f / s, 73.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 74.0f / s, 0.0f / s);
	glVertex3f(-17.0f / s, 76.0f / s, 0.0f / s);
	glVertex3f(-21.0f / s, 76.0f / s, 0.0f / s);
	glVertex3f(-23.0f / s, 73.0f / s, 0.0f / s);
	glVertex3f(-26.0f / s, 72.0f / s, 0.0f / s);
	glVertex3f(-27.0f / s, 68.0f / s, 0.0f / s);
	glVertex3f(-31.0f / s, 66.0f / s, 0.0f / s);
	glVertex3f(-31.0f / s, 60.0f / s, 0.0f / s);
	glVertex3f(-33.0f / s, 58.0f / s, 0.0f / s);
	glVertex3f(-32.0f / s, 52.0f / s, 0.0f / s);
	glVertex3f(-37.0f / s, 49.0f / s, 0.0f / s);
	glVertex3f(-37.0f / s, 43.0f / s, 0.0f / s);
	glVertex3f(-41.0f / s, 39.0f / s, 0.0f / s);
	glVertex3f(-41.0f / s, 32.0f / s, 0.0f / s);
	glVertex3f(-43.0f / s, 24.0f / s, 0.0f / s);
	glVertex3f(-46.0f / s, 22.0f / s, 0.0f / s);
	glVertex3f(-44.0f / s, 16.0f / s, 0.0f / s);
	glVertex3f(-34.0f / s, 9.0f / s, 0.0f / s);

	glEnd();

	// leg left 1
	glLoadIdentity();
	glTranslatef(x1_translate, y1_translate, -3.0f);
	glRotatef(90 - langle, 0, 0, 1);
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.545f, 0.624f, 0.227f);
	glVertex3f(-22.0f / s, -82.0f / s, 0.0f / s);
	glVertex3f(-16.0f / s, -94.0f / s, 0.0f / s);
	glVertex3f(-15.0f / s, -87.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, -78.0f / s, 0.0f / s);
	glVertex3f(-22.0f / s, -80.0f / s, 0.0f / s);
	glVertex3f(-26.0f / s, -79.0f / s, 0.0f / s);
	glVertex3f(-28.0f / s, -93.0f / s, 0.0f / s);
	glVertex3f(-21.0f / s, -95.0f / s, 0.0f / s);
	glVertex3f(-16.0f / s, -94.0f / s, 0.0f / s);

	glEnd();

	// leg upper left 1
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.545f, 0.624f, 0.227f);
	glVertex3f(-22.0f / s, -80.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, -78.0f / s, 0.0f / s);
	glVertex3f(-26.0f / s, -79.0f / s, 0.0f / s);
	glVertex3f(-16.0f / s, -66.0f / s, 0.0f / s);
	glVertex3f(-27.0f / s, -67.0f / s, 0.0f / s);
	glVertex3f(-14.0f / s, -45.0f / s, 0.0f / s);
	glVertex3f(-28.0f / s, -45.0f / s, 0.0f / s);

	glEnd();


	// Panjha right 1
	glLoadIdentity();
	glTranslatef(x1_translate, y1_translate, -3.0f);
	glRotatef(90 + langle, 0, 0, 1);

	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.545f, 0.624f, 0.227f);
	glVertex3f(12.0f / s, -85.0f / s, 0.0f / s);
	glVertex3f(11.0f / s, -79.0f / s, 0.0f / s);
	glVertex3f(2.0f / s, -86.0f / s, 0.0f / s);
	glVertex3f(3.0f / s, -78.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, -83.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, -78.0f / s, 0.0f / s);

	glEnd();


	// leg right 1

	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.545f, 0.624f, 0.227f);
	glVertex3f(-7.0f / s, -78.0f / s, 0.0f / s);
	glVertex3f(3.0f / s, -78.0f / s, 0.0f / s);
	glVertex3f(-6.0f / s, -74.0f / s, 0.0f / s);
	glVertex3f(2.0f / s, -73.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, -63.0f / s, 0.0f / s);
	glVertex3f(5.0f / s, -60.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, -45.0f / s, 0.0f / s);
	glVertex3f(4.0f / s, -43.0f / s, 0.0f / s);

	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	glRotatef(90, 0, 0, 1);
	// lankini Green Part
	glBegin(GL_TRIANGLE_FAN);


	glColor3f(0.83f, 0.33f, 0.27f);
	glVertex3f(-8.0f / s, -25.0f / s, 0.0f / s);
	glVertex3f(12.0f / s, 2.0f / s, 0.0f / s);
	glVertex3f(9.0f / s, -0.0f / s, 0.0f / s);
	glVertex3f(4.0f / s, -4.0f / s, 0.0f / s);
	glVertex3f(-1.0f / s, -6.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, -7.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, -6.0f / s, 0.0f / s);
	glVertex3f(-26.0f / s, -3.0f / s, 0.0f / s);
	glVertex3f(-32.0f / s, 2.0f / s, 0.0f / s);
	glVertex3f(-38.0f / s, -18.0f / s, 0.0f / s);
	glVertex3f(-42.0f / s, -45.0f / s, 0.0f / s);
	glVertex3f(-35.0f / s, -47.0f / s, 0.0f / s);
	glVertex3f(-28.0f / s, -51.0f / s, 0.0f / s);
	glVertex3f(-21.0f / s, -52.0f / s, 0.0f / s);
	glVertex3f(-14.0f / s, -51.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, -52.0f / s, 0.0f / s);
	glVertex3f(-1.0f / s, -50.0f / s, 0.0f / s);
	glVertex3f(4.0f / s, -48.0f / s, 0.0f / s);
	glVertex3f(8.0f / s, -46.0f / s, 0.0f / s);
	glVertex3f(18.0f / s, -43.0f / s, 0.0f / s);
	glVertex3f(21.0f / s, -40.0f / s, 0.0f / s);
	glVertex3f(16.0f / s, -15.0f / s, 0.0f / s);
	glVertex3f(12.0f / s, 2.0f / s, 0.0f / s);

	glEnd();

	// Lankini Mideal Part

	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.83f, 0.33f, 0.27f);
	glVertex3f(-9.0f / s, 34.0f / s, 0.0f / s);
	glVertex3f(-20.0f / s, 48.0f / s, 0.0f / s);
	glVertex3f(-25.0f / s, 42.0f / s, 0.0f / s);
	glVertex3f(-30.0f / s, 41.0f / s, 0.0f / s);
	glVertex3f(-27.0f / s, 33.0f / s, 0.0f / s);
	glVertex3f(-26.0f / s, 29.0f / s, 0.0f / s);
	glVertex3f(-26.0f / s, 26.0f / s, 0.0f / s);
	glVertex3f(-26.0f / s, 21.0f / s, 0.0f / s);
	glVertex3f(-27.0f / s, 17.0f / s, 0.0f / s);
	glVertex3f(-28.0f / s, 14.0f / s, 0.0f / s);
	glVertex3f(-29.0f / s, 12.0f / s, 0.0f / s);
	glVertex3f(-30.0f / s, 9.0f / s, 0.0f / s);
	glVertex3f(-29.0f / s, 6.0f / s, 0.0f / s);
	glVertex3f(-27.0f / s, 4.0f / s, 0.0f / s);
	glVertex3f(-25.0f / s, 2.0f / s, 0.0f / s);
	glVertex3f(-22.0f / s, 1.0f / s, 0.0f / s);
	glVertex3f(-15.0f / s, 0.0f / s, 0.0f / s);
	glVertex3f(-5.0f / s, 3.0f / s, 0.0f / s);
	glVertex3f(5.0f / s, 2.0f / s, 0.0f / s);
	glVertex3f(8.0f / s, 5.0f / s, 0.0f / s);
	glVertex3f(10.0f / s, 9.0f / s, 0.0f / s);
	glVertex3f(10.0f / s, 12.0f / s, 0.0f / s);
	glVertex3f(9.0f / s, 15.0f / s, 0.0f / s);
	glVertex3f(8.0f / s, 19.0f / s, 0.0f / s);
	glVertex3f(8.0f / s, 23.0f / s, 0.0f / s);
	glVertex3f(5.0f / s, 30.0f / s, 0.0f / s);
	glVertex3f(2.0f / s, 37.0f / s, 0.0f / s);
	glVertex3f(1.0f / s, 41.0f / s, 0.0f / s);
	glVertex3f(0.0f / s, 44.0f / s, 0.0f / s);
	glVertex3f(-3.0f / s, 46.0f / s, 0.0f / s);
	glVertex3f(-5.0f / s, 49.0f / s, 0.0f / s);

	glEnd();


	// Lankini Right Hand


	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.545f, 0.624f, 0.227f);
	glVertex3f(-27.0f / s, 33.0f / s, 0.0f / s);
	glVertex3f(-30.0f / s, 41.0f / s, 0.0f / s);
	glVertex3f(-28.0f / s, 30.0f / s, 0.0f / s);
	glVertex3f(-35.0f / s, 39.0f / s, 0.0f / s);
	glVertex3f(-29.0f / s, 26.0f / s, 0.0f / s);
	glVertex3f(-37.0f / s, 35.0f / s, 0.0f / s);
	glVertex3f(-30.0f / s, 22.0f / s, 0.0f / s);
	glVertex3f(-40.0f / s, 27.0f / s, 0.0f / s);
	glVertex3f(-32.0f / s, 17.0f / s, 0.0f / s);
	glVertex3f(-42.0f / s, 21.0f / s, 0.0f / s);
	glVertex3f(-34.0f / s, 14.0f / s, 0.0f / s);
	glVertex3f(-42.0f / s, 17.0f / s, 0.0f / s);
	glVertex3f(-34.0f / s, 9.0f / s, 0.0f / s);
	glVertex3f(-44.0f / s, 14.0f / s, 0.0f / s);
	glVertex3f(-35.0f / s, 5.0f / s, 0.0f / s);
	glVertex3f(-45.0f / s, 10.0f / s, 0.0f / s);
	glVertex3f(-36.0f / s, 2.0f / s, 0.0f / s);
	glVertex3f(-45.0f / s, 6.0f / s, 0.0f / s);
	glVertex3f(-37.0f / s, -2.0f / s, 0.0f / s);
	glVertex3f(-43.0f / s, -2.0f / s, 0.0f / s);

	glEnd();

	//mangat
	glBegin(GL_QUADS);

	glColor3f(0.545f, 0.624f, 0.227f);
	glVertex3f(-37.0f / s, -2.0f / s, 0.0f / s);
	glVertex3f(-36.0f / s, -8.0f / s, 0.0f / s);
	glVertex3f(-41.0f / s, -7.0f / s, 0.0f / s);
	glVertex3f(-43.0f / s, -2.0f / s, 0.0f / s);

	glEnd();

	//fingers
	glBegin(GL_POLYGON);
	glColor3f(0.545f, 0.624f, 0.227f);
	glVertex3f(-36.0f / s, -8.0f / s, 0.0f / s);
	glVertex3f(-36.0f / s, -17.0f / s, 0.0f / s);
	glVertex3f(-38.0f / s, -13.0f / s, 0.0f / s);
	glVertex3f(-43.0f / s, -14.0f / s, 0.0f / s);
	glVertex3f(-41.0f / s, -7.0f / s, 0.0f / s);

	glEnd();
	// Lankini Left Hand

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.545f, 0.624f, 0.227f);
	glVertex3f(-3.0f / s, 46.0f / s, 0.0f / s);
	glVertex3f(-0.0f / s, 44.0f / s, 0.0f / s);
	glVertex3f(1.0f / s, 47.0f / s, 0.0f / s);
	glVertex3f(2.0f / s, 37.0f / s, 0.0f / s);
	glVertex3f(10.0f / s, 42.0f / s, 0.0f / s);
	glVertex3f(3.0f / s, 33.0f / s, 0.0f / s);
	glVertex3f(15.0f / s, 38.0f / s, 0.0f / s);
	glVertex3f(8.0f / s, 30.0f / s, 0.0f / s);
	glVertex3f(23.0f / s, 38.0f / s, 0.0f / s);
	glVertex3f(13.0f / s, 26.0f / s, 0.0f / s);
	glVertex3f(25.0f / s, 29.0f / s, 0.0f / s);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.545f, 0.624f, 0.227f);
	glVertex3f(23.0f / s, 38.0f / s, 0.0f / s);
	glVertex3f(28.0f / s, 38.0f / s, 0.0f / s);
	glVertex3f(29.0f / s, 30.0f / s, 0.0f / s);
	glVertex3f(25.0f / s, 29.0f / s, 0.0f / s);
	glEnd();

	//fingers
	/*glLoadIdentity();
	glRotatef(-talvar_rotate*0.5f, 0.0f, 0.0f, 1.0f);
	glTranslatef(-0.10f / s, 2.0f / s, -3.0f);*/

	glBegin(GL_POLYGON);

	glColor3f(0.545f, 0.624f, 0.227f);
	glVertex3f(28.0f / s, 38.0f / s, 0.0f / s);
	glVertex3f(41.0f / s, 46.0f / s, 0.0f / s);
	glVertex3f(37.0f / s, 40.0f / s, 0.0f / s);
	glVertex3f(40.0f / s, 40.0f / s, 0.0f / s);
	glVertex3f(29.0f / s, 30.0f / s, 0.0f / s);

	glEnd();
	/*glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);*/
	//green part of chest
	glBegin(GL_POLYGON);
	glColor3f(0.83f, 0.33f, 0.27f);

	glVertex3f(3.0f / s, 33.0f / s, 0.0f / s);
	glVertex3f(-26.0f / s, 29.0f / s, 0.0f / s);
	glVertex3f(-28.0f / s, 14.0f / s, 0.0f / s);
	glVertex3f(8.0f / s, 19.0f / s, 0.0f / s);
	glVertex3f(9.0f / s, 27.0f / s, 0.0f / s);

	glEnd();

	//neck 
	glBegin(GL_POLYGON);
	glColor3f(0.545f, 0.624f, 0.227f);

	glVertex3f(-20.0f / s, 48.0f / s, 0.0f / s);
	glVertex3f(-19.0f / s, 43.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, 40.0f / s, 0.0f / s);
	glVertex3f(-4.0f / s, 44.0f / s, 0.0f / s);
	glVertex3f(-2.0f / s, 47.0f / s, 0.0f / s);
	glVertex3f(-5.0f / s, 49.0f / s, 0.0f / s);
	glVertex3f(-20.0f / s, 48.0f / s, 0.0f / s);

	glEnd();



	// golden part of stomach

	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.545f, 0.624f, 0.227f);
	glVertex3f(10.0f / s, 12.0f / s, 0.0f / s);
	glVertex3f(13.0f / s, 5.0f / s, 0.0f / s);
	glVertex3f(10.0f / s, 9.0f / s, 0.0f / s);
	glVertex3f(12.0f / s, 2.0f / s, 0.0f / s);
	glVertex3f(8.0f / s, 5.0f / s, 0.0f / s);
	glVertex3f(9.0f / s, 0.0f / s, 0.0f / s);
	glVertex3f(5.0f / s, 2.0f / s, 0.0f / s);
	glVertex3f(4.0f / s, -4.0f / s, 0.0f / s);
	glVertex3f(-5.0f / s, 3.0f / s, 0.0f / s);
	glVertex3f(-1.0f / s, -6.0f / s, 0.0f / s);
	glVertex3f(-15.0f / s, 0.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, -7.0f / s, 0.0f / s);
	glVertex3f(-22.0f / s, 1.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, -6.0f / s, 0.0f / s);
	glVertex3f(-25.0f / s, 2.0f / s, 0.0f / s);
	glVertex3f(-26.0f / s, -3.0f / s, 0.0f / s);
	glVertex3f(-29.0f / s, 6.0f / s, 0.0f / s);
	glVertex3f(-32.0f / s, 2.0f / s, 0.0f / s);
	glVertex3f(-30.0f / s, 9.0f / s, 0.0f / s);

	glEnd();
	// Lankini Gold Chain
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.83f, 0.33f, 0.27f);
	glVertex3f(-8.0f / s, 30.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, 40.0f / s, 0.0f / s);
	glVertex3f(-4.0f / s, 44.0f / s, 0.0f / s);
	glVertex3f(-2.0f / s, 47.0f / s, 0.0f / s);
	glVertex3f(1.0f / s, 41.0f / s, 0.0f / s);
	glVertex3f(3.0f / s, 35.0f / s, 0.0f / s);
	glVertex3f(1.0f / s, 26.0f / s, 0.0f / s);
	glVertex3f(-1.0f / s, 19.0f / s, 0.0f / s);
	glVertex3f(-4.0f / s, 13.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 16.0f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 20.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, 26.0f / s, 0.0f / s);
	glVertex3f(-22.0f / s, 33.0f / s, 0.0f / s);
	glVertex3f(-23.0f / s, 39.0f / s, 0.0f / s);
	glVertex3f(-19.0f / s, 43.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, 40.0f / s, 0.0f / s);

	glEnd();


	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	glRotatef(-270, 0, 0, 1);
	//face
	glBegin(GL_TRIANGLE_FAN);


	glColor3f(0.545f, 0.624f, 0.227f);
	glVertex3f(-11.0f / s, 60.0f / s, 0.0f / s);
	glVertex3f(-4.0f / s, 62.0f / s, 0.0f / s);
	glVertex3f(-6.0f / s, 68.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 71.0f / s, 0.0f / s);
	glVertex3f(-14.0f / s, 70.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, 70.0f / s, 0.0f / s);
	glVertex3f(-19.0f / s, 67.0f / s, 0.0f / s);
	glVertex3f(-23.0f / s, 63.0f / s, 0.0f / s);
	glVertex3f(-22.0f / s, 58.0f / s, 0.0f / s);
	glVertex3f(-22.0f / s, 54.0f / s, 0.0f / s);
	glVertex3f(-20.0f / s, 48.0f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 47.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 48.0f / s, 0.0f / s);
	glVertex3f(-5.0f / s, 51.0f / s, 0.0f / s);
	//glVertex3f(-2.0f / s, 47.0f / s, 0.0f / s);
	glVertex3f(-3.0f / s, 57.0f / s, 0.0f / s);
	glVertex3f(-4.0f / s, 62.0f / s, 0.0f / s);
	glEnd();

	//left eyebrow
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.176f, 0.173f, 0.29f);

	glVertex3f(-15.0f / s, 62.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, 65.0f / s, 0.0f / s);
	glVertex3f(-21.0f / s, 64.0f / s, 0.0f / s);
	glVertex3f(-20.0f / s, 63.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, 64.0f / s, 0.0f / s);

	glEnd();

	////left eye white part
	glBegin(GL_QUADS);

	glColor3f(0.851f, 0.816f, 0.827f);

	glVertex3f(-14.0f / s, 60.0f / s, 0.0f / s);
	glVertex3f(-16.0f / s, 62.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, 61.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, 60.0f / s, 0.0f / s);

	glEnd();

	//// left eye black
	glPointSize(2);
	glBegin(GL_POINTS);

	glColor3f(0.176f, 0.173f, 0.29f);

	glVertex3f(-16.0f / s, 61.0f / s, 0.0f / s);

	glEnd();

	//right eyebrow
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.176f, 0.173f, 0.29f);

	glVertex3f(-11.0f / s, 65.0f / s, 0.0f / s);
	glVertex3f(-10.0f / s, 65.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, 67.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 68.0f / s, 0.0f / s);
	glVertex3f(-10.0f / s, 67.0f / s, 0.0f / s);
	glVertex3f(-11.0f / s, 65.0f / s, 0.0f / s);
	glEnd();

	//right eye white part
	glBegin(GL_QUADS);

	glColor3f(0.851f, 0.816f, 0.827f);

	glVertex3f(-9.0f / s, 62.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, 64.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 65.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 63.0f / s, 0.0f / s);

	glEnd();

	// left eye black
	glPointSize(2);
	glBegin(GL_POINTS);

	glColor3f(0.176f, 0.173f, 0.29f);

	glVertex3f(-8.0f / s, 63.0f / s, 0.0f / s);

	glEnd();

	//mouth
	glBegin(GL_POLYGON);

	glColor3f(0.471f, 0.173f, 0.173f);

	glVertex3f(-12.0f / s, 55.0f / s, 0.0f / s);
	glVertex3f(-12.0f / s, 52.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, 52.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 53.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 57.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, 56.0f / s, 0.0f / s);
	glVertex3f(-12.0f / s, 55.0f / s, 0.0f / s);

	glEnd();

	//teeth 1
	glBegin(GL_TRIANGLES);

	glColor3f(0.839f, 0.737f, 0.769f);

	glVertex3f(-12.0f / s, 53.0f / s, 0.0f / s);
	glVertex3f(-11.0f / s, 55.0f / s, 0.0f / s);
	glVertex3f(-12.0f / s, 55.0f / s, 0.0f / s);

	glEnd();

	//teeth 2
	glBegin(GL_TRIANGLES);

	glColor3f(0.839f, 0.737f, 0.769f);

	glVertex3f(-7.0f / s, 54.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 56.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 55.0f / s, 0.0f / s);

	glEnd();

	//jiib
	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 0.0f);

	glVertex3f(-6.0f / s, 52.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 54.0f / s, 0.0f / s);
	glVertex3f(-12.0f / s, 53.0f / s, 0.0f / s);
	glVertex3f(-10.0f / s, 51.0f / s, 0.0f / s);
	glEnd();




	//////circle
		/*glLineWidth(0.0001);
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-45.6 / s, 58.9 / s, 0.0f);
		glVertex3f(-46.0436 / s, 60.8058 / s, 0.0f);
		glVertex3f(-45.2 / s, 63.8 / s, 0.0f);
		glVertex3f(-38.8 / s, 84.01 / s, 0.0f);
		glVertex3f(-38.0526 / s, 88.5 / s, 0.0f);
		glVertex3f(-35.3 / s, 87.8232 / s, 0.0f);
		glVertex3f(-3.42 / s, 98.4 / s, 0.0f);
		glVertex3f(0.0 / s, 100.0 / s, 0.0f);
		glVertex3f(3.4 / s, 98.4 / s, 0.0f);
		glVertex3f(27.3 / s, 87.0 / s, 0.0f);
		glVertex3f(27.7 / s, 82.4 / s, 0.0f);
		glVertex3f(28.5 / s, 79.4 / s, 0.0f);
		glVertex3f(24.3 / s, 50.1 / s, 0.0f);
		glVertex3f(24.3 / s, 46.3 / s, 0.0f);
		glVertex3f(23.2 / s, 42.9 / s, 0.0f);
		glVertex3f(-6.46 / s, 31.88 / s, 0.0f);
		glVertex3f(-11.4 / s, 32.6 / s, 0.0f);
		glVertex3f(-45.2 / s, 63.8 / s, 0.0f);
		glVertex3f(-46.0436 / s, 60.8058 / s, 0.0f);
		glVertex3f(-45.6 / s, 58.9 / s, 0.0f);

		glEnd();*/
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	glRotatef(-270, 0, 0, 1);

	// Circle
	float p1 = 0.0f;
	float q1 = 0.0f;
	const float v1 = 0.3f;
	glPointSize(3.0);
	glBegin(GL_POINTS);
	glColor3f(0.86f, 0.86f, 1.0f);
	for (float angle = 0.0f; angle <= 360.0; angle = angle + 10)
	{
		p1 = cos(angle) * v1;
		q1 = sin(angle) * v1;

		glVertex3f(p1, q1, 0.0f);

	}
	glEnd();

	float x3 = -14.03f;
	float y3 = 67.67f;
	const float r3 = 0.6f;
	glPointSize(8.0);
	glBegin(GL_POINTS);
	glColor3f(0.86f, 0.86f, 1.0f);
	for (float angle = 0.0f; angle <= 360.0f; angle = angle + 10)
	{
		x3 = cos(angle) * r3;
		y3 = sin(angle) * r3;

		glVertex3f(x3, y3, 0.0f);

	}
	glEnd();

	float x2 = 1.0f;
	float y2 = 1.0f;
	const float r2 = 0.6f;
	glPointSize(5.0);
	glBegin(GL_POINTS);
	glColor3f(0.86f, 0.86f, 1.0f);
	for (float angle = 0.0f; angle <= 360.0f; angle = angle + 10)
	{
		x2 = cos(angle) * r2;
		y2 = sin(angle) * r2;

		glVertex3f(x2, y2, 0.0f);

	}
	glEnd();
	float x1 = 0.0f;
	float y1 = 0.0f;
	const float r1 = 0.8f;
	glPointSize(10.0);
	glBegin(GL_POINTS);
	glColor3f(0.86f, 0.86f, 1.0f);
	for (float angle = 0.0f; angle <= 360.0f; angle = angle + 10)
	{
		x1 = cos(angle) * r1;
		y1 = sin(angle) * r1;

		glVertex3f(x1, y1, 0.0f);

	}
	glEnd();

	float x = 0.0f;
	float y = 0.0f;
	const float r = 1.0f;
	glPointSize(6.0);
	glBegin(GL_POINTS);
	glColor3f(0.86f, 0.86f, 1.0f);
	for (float angle = 0.0f; angle <= 360.0f; angle = angle + 10)
	{
		x = cos(angle) * r;
		y = sin(angle) * r;

		glVertex3f(x, y, 0.0f);

	}
	glEnd();

	// Circle
	float p = 0.0f;
	float q = 0.0f;
	const float v = 1.2f;

	glPointSize(9.0);
	glBegin(GL_POINTS);
	glColor3f(0.86f, 0.86f, 1.0f);
	for (float angle = 0.0f; angle <= 360.0f; angle = angle + 10)
	{
		p = cos(angle) * v;
		q = sin(angle) * v;

		glVertex3f(p, q, 0.0f);

	}
	glEnd();


	// Circle
	float p2 = 0.0f;
	float q2 = 0.0f;
	const float v2 = 1.4f;

	glBegin(GL_POINTS);
	glColor3f(0.86f, 0.86f, 1.0f);
	for (float angle = 0.0f; angle <= 360.0f; angle = angle + 10)
	{
		p2 = cos(angle) * v2;
		q2 = sin(angle) * v2;

		glVertex3f(p2, q2, 0.0f);

	}
	glEnd();
}

void draw_shadowBird(void) {
	glLoadIdentity();
	glTranslatef(x1Bird, y1Bird, -3.0f);
	glScalef(x1Scale, y1Scale, z1Scale);

	if (x1Bird <= -0.5f) {
		x1Bird += 0.001;

	}
	else if (x1Scale >= 0.1) {

		x1Scale -= 0.0003f;
		y1Scale -= 0.0003f;
		z1Scale -= 0.0003f;
	}

	glRotatef(-50, 0, 0, 1.0);
	glScalef(0.15f, 0.15f, 0.15f);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-15.9 / s, 4.6 / s, 0.0f);
	glVertex3f(-20.5 / s, 9.5 / s, 0.0f);
	glVertex3f(-35.20 / s, 15.0672 / s, 0.0f);
	glVertex3f(-30.30 / s, 20.6 / s, 0.0f);
	glVertex3f(-34.45 / s, 24.87 / s, 0.0f);
	glVertex3f(-41.41 / s, 25.16 / s, 0.0f);
	glVertex3f(-46.9 / s, 25.49 / s, 0.0f);
	glVertex3f(-51.22 / s, 30.7 / s, 0.0f);
	glVertex3f(-55.79 / s, 26.7 / s, 0.0f);
	glVertex3f(-59.7 / s, 32.026 / s, 0.0f);
	glVertex3f(-69.192 / s, 33.33 / s, 0.0f);
	glVertex3f(-74.42 / s, 36.27 / s, 0.0f);
	glVertex3f(-80.62 / s, 37.9 / s, 0.0f);
	glVertex3f(-88.14 / s, 40.07 / s, 0.0f);
	glVertex3f(-75.7 / s, 41.20 / s, 0.0f);
	glVertex3f(-62.65 / s, 40.22 / s, 0.0f);
	glVertex3f(-51.22 / s, 37.94 / s, 0.0f);
	glVertex3f(-37.8 / s, 36.6 / s, 0.0f);
	glVertex3f(-29 / s, 35.6 / s, 0.0f);
	glVertex3f(-20.5 / s, 34.3 / s, 0.0f);
	glVertex3f(-18.8 / s, 28.46 / s, 0.0f);
	glVertex3f(-7.10 / s, 20.94 / s, 0.0f);
	glVertex3f(-0.89 / s, 16.701 / s, 0.0f);
	glVertex3f(-13.31 / s, 24.54 / s, 0.0f);
	glVertex3f(-7.10 / s, 20.9 / s, 0.0f);
	glVertex3f(-0.89 / s, 16.701 / s, 0.0f);
	glVertex3f(-8.08 / s, 10.16 / s, 0.0f);
	glVertex3f(-15.93 / s, 4.61 / s, 0.0f);

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(14.81 / s, -12.38 / s, 0.0f);
	glVertex3f(21.02 / s, -11.074 / s, 0.0f);
	glVertex3f(29.8 / s, -9.11 / s, 0.0f);
	glVertex3f(35.7 / s, -5.84 / s, 0.0f);
	glVertex3f(43.24 / s, -3.88 / s, 0.0f);
	glVertex3f(49.7 / s, -2.57 / s, 0.0f);
	glVertex3f(55.9 / s, -6.17 / s, 0.0f);
	glVertex3f(61.5451 / s, -1.59 / s, 0.0f);
	glVertex3f(67.72 / s, 4.61 / s, 0.0f);
	glVertex3f(59.58 / s, 5.91 / s, 0.0f);
	glVertex3f(52.3 / s, 6.24 / s, 0.0f);
	glVertex3f(38.63 / s, 4.93 / s, 0.0f);
	glVertex3f(30.47 / s, 3.30 / s, 0.0f);
	glVertex3f(24.58 / s, 2.977 / s, 0.0f);
	glVertex3f(18.74 / s, -0.29 / s, 0.0f);
	glVertex3f(15.47 / s, -6.82 / s, 0.0f);
	glVertex3f(14.81 / s, -12.38 / s, 0.0f);

	glEnd();



	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(50.1 / s, -8.13 / s, 0.0f);
	glVertex3f(51.089 / s, -11.074 / s, 0.0f);
	glVertex3f(57.297 / s, -15.32 / s, 0.0f);
	glVertex3f(64.8 / s, -16.62 / s, 0.0f);
	glVertex3f(71.34 / s, -19.24 / s, 0.0f);
	glVertex3f(72.001 / s, -25.45 / s, 0.0f);
	glVertex3f(77.55 / s, -26.75 / s, 0.0f);
	glVertex3f(85.39 / s, -27.738 / s, 0.0f);
	glVertex3f(93.894 / s, -27.08 / s, 0.0f);
	glVertex3f(89.973 / s, -23.49 / s, 0.0f);
	glVertex3f(83.76 / s, -16.62 / s, 0.0f);
	glVertex3f(84.41 / s, -9.43 / s, 0.0f);
	glVertex3f(81.80 / s, -4.21 / s, 0.0f);
	glVertex3f(75.59 / s, -2.90 / s, 0.0f);
	glVertex3f(69.71 / s, -2.57 / s, 0.0f);
	glVertex3f(67.72 / s, 4.61 / s, 0.0f);
	glVertex3f(61.54 / s, -1.59 / s, 0.0f);
	glVertex3f(55.9 / s, -6.17 / s, 0.0f);
	glVertex3f(51.089 / s, -11.074 / s, 0.0f);
	glVertex3f(50.1 / s, -8.13 / s, 0.0f);

	glEnd();

	//tail part

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-15.9 / s, 4.6 / s, 0.0f);
	glVertex3f(-16.25 / s, -2.9 / s, 0.0f);
	glVertex3f(-18.5 / s, -10.09 / s, 0.0f);
	glVertex3f(-27.04 / s, -14.09 / s, 0.0f);
	glVertex3f(-34.22 / s, -18.5 / s, 0.0f);
	glVertex3f(-28.02 / s, -20.87 / s, 0.0f);
	glVertex3f(-21.45 / s, -19.24 / s, 0.0f);
	glVertex3f(-15.24 / s, -15.64 / s, 0.0f);
	glVertex3f(-7.07 / s, -15.64 / s, 0.0f);
	glVertex3f(-3.80 / s, -9.43 / s, 0.0f);
	glVertex3f(-15.9 / s, 4.6 / s, 0.0f);

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-15.9 / s, 4.6 / s, 0.0f);
	glVertex3f(-9.03 / s, -2.25 / s, 0.0f);
	glVertex3f(-3.80 / s, -9.43 / s, 0.0f);
	glVertex3f(2.70 / s, -6.49 / s, 0.0f);
	glVertex3f(8.93 / s, -3.88 / s, 0.0f);
	glVertex3f(18.7 / s, -0.29 / s, 0.0f);
	glVertex3f(24.58 / s, 2.97 / s, 0.0f);
	glVertex3f(26.87 / s, 8.20 / s, 0.0f);
	glVertex3f(33.084 / s, 12.453 / s, 0.0f);
	glVertex3f(27.2 / s, 14.08 / s, 0.0f);
	glVertex3f(21.3 / s, 15.72 / s, 0.0f);
	glVertex3f(13.47 / s, 14.414 / s, 0.0f);
	glVertex3f(6.29 / s, 12.126 / s, 0.0f);
	glVertex3f(-8.08 / s, 10.16 / s, 0.0f);
	glVertex3f(-15.9 / s, 4.6 / s, 0.0f);

	glEnd();
}

void drawParvatChaupai3(void)
{
	glLoadIdentity();

	glTranslatef(0.0f, y2_translate, z2_translate);
	glScalef(2.3f, 2.3f, 0.0f);

	glBegin(GL_QUADS);
	//glColor3f(0.764f, 0.345f, 0.0784f);
	glColor3f(0.949f, 0.698f, 0.0784f);
	glVertex3f(-200.332 / s, 198.696 / s, 0.0f);
	glColor3f(0.858f, 0.5647f, 0.066f);
	glVertex3f(199.684 / s, 200.008 / s, 0.0f);
	//glColor3f(0.878f, 0.623f, 0.066f);
	glColor3f(0.94f, 0.71f, 0.13f);
	glVertex3f(200.06 / s, -14.959 / s, 0.0f);
	glColor3f(0.721f, 0.313f, 0.0f);
	glVertex3f(-202.202 / s, -15.4055 / s, 0.0f);


	glBegin(GL_QUADS);
	glColor3f(0.54f, 0.59f, 0.223f);
	glVertex3f(200.06 / s, -14.959 / s, 0.0f);
	glVertex3f(-202.202 / s, -15.4055 / s, 0.0f);
	glColor3f(0.67f, 0.74f, 0.098f);
	glVertex3f(-200.33 / s, -198.04 / s, 0.0f);
	glVertex3f(200.34 / s, -200.01 / s, 0.0f);

	glEnd();
	// ************************** Brown Part ***************************
//glLoadIdentity();
//glTranslatef(0.0f, y_translate, z_translate);
//glScalef(2.3f, 2.3f, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.38, 0.243, 0.071);
	glVertex3f(-25.4f / s, -2.156f / s, 0.0f);
	glVertex3f(-25.5924f / s, -0.851087f / s, 0.0f);
	glVertex3f(-36.4287f / s, -4.13585f / s, 0.0f);
	glVertex3f(-41.6776f / s, -9.55403f / s, 0.0f);
	glVertex3f(-7.50926f / s, -9.8588f / s, 0.0f);
	glVertex3f(-12.0808f / s, -6.37085f / s, 0.0f);
	glVertex3f(-11.3358f / s, 0.571184f / s, 0.0f);
	glVertex3f(-17.5329f / s, 6.93754f / s, 0.0f);
	glVertex3f(-14.8577f / s, 13.778f / s, 0.0f);
	glVertex3f(-23.0006f / s, 6.39994f / s, 0.0f);
	glVertex3f(-25.5924f / s, -0.851087f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.49, 0.31, 0.09);
	glVertex3f(-37.0451f / s, -0.780314f / s, 0.0f);
	glVertex3f(-39.3072f / s, -1.86699f / s, 0.0f);
	glVertex3f(-51.2949f / s, -10.3329f / s, 0.0f);
	glVertex3f(-41.6776f / s, -9.55403f / s, 0.0f);
	glVertex3f(-36.4287f / s, -4.13585f / s, 0.0f);
	glVertex3f(-25.5924f / s, -0.851087f / s, 0.0f);
	glVertex3f(-23.0006f / s, 6.39994f / s, 0.0f);
	glVertex3f(-14.8577f / s, 13.778f / s, 0.0f);
	glVertex3f(-11.6282f / s, 17.0882f / s, 0.0f);
	glVertex3f(-6.24466f / s, 23.1154f / s, 0.0f);
	glVertex3f(-9.40454f / s, 29.084f / s, 0.0f);
	glVertex3f(-8.17569f / s, 34.0579f / s, 0.0f);
	glVertex3f(-15.0221f / s, 32.595f / s, 0.0f);
	glVertex3f(-26.1987f / s, 19.7214f / s, 0.0f);
	glVertex3f(-39.3072f / s, -1.86699f / s, 0.0f);
	glEnd();

	//upper base part
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.49, 0.31, 0.09);
	glVertex3f(-15.0221 / s, 32.595 / s, 0.0f);
	glVertex3f(-4.34855 / s, 30.659 / s, 0.0f);
	glColor3f(0.96f, 0.69f, 0.070f);
	glVertex3f(-4.34855 / s, 30.659 / s, 0.0f);
	glVertex3f(1.517 / s, 30.4699 / s, 0.0f);
	glVertex3f(1.517 / s, 30.4699 / s, 0.0f);
	glVertex3f(9.78912 / s, 33.2 / s, 0.0f);
	glVertex3f(-0.501 / s, 35.957 / s, 0.0f);
	//glVertex3f(-1.25808 / s, 34.5 / s, 0.0f);
	glVertex3f(-13.7 / s, 35.0 / s, 0.0f);
	glVertex3f(-15.022 / s, 32.59 / s, 0.0f);

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.49, 0.31, 0.09);
	glVertex3f(-9.30539f / s, 4.37002f / s, 0.0f);
	glVertex3f(-7.50926f / s, -9.8588f / s, 0.0f);
	glVertex3f(-12.0808f / s, -6.37085f / s, 0.0f);
	glVertex3f(-11.3358f / s, 0.571184f / s, 0.0f);
	glVertex3f(-17.5329f / s, 6.93754f / s, 0.0f);
	glVertex3f(-14.8577f / s, 13.778f / s, 0.0f);
	glVertex3f(-11.6282f / s, 17.0882f / s, 0.0f);
	glVertex3f(-6.71279f / s, 6.32122f / s, 0.0f);
	glVertex3f(-0.048436f / s, 3.88304f / s, 0.0f);
	glVertex3f(0.967471f / s, -1.96858f / s, 0.0f);
	glVertex3f(5.80319f / s, -5.54458f / s, 0.0f);
	glVertex3f(-5.29052f / s, -9.97393f / s, 0.0f);
	glVertex3f(-7.50926f / s, -9.8588f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.573, 0.353, 0.094);
	glVertex3f(4.11976f / s, 5.68046f / s, 0.0f);
	glVertex3f(3.45318f / s, 23.4136f / s, 0.0f);
	glVertex3f(6.90239f / s, 16.0225f / s, 0.0f);
	glVertex3f(7.054f / s, 7.5321f / s, 0.0f);
	glVertex3f(15.3928f / s, 2.26353f / s, 0.0f);
	glVertex3f(18.5387f / s, -3.87683f / s, 0.0f);
	glVertex3f(5.80319f / s, -5.54458f / s, 0.0f);
	glVertex3f(0.967471f / s, -1.96858f / s, 0.0f);
	glVertex3f(-0.048436f / s, 3.88304f / s, 0.0f);
	glVertex3f(-6.71279f / s, 6.32122f / s, 0.0f);
	glVertex3f(-11.6282f / s, 17.0882f / s, 0.0f);
	glVertex3f(-6.24466f / s, 23.1154f / s, 0.0f);
	glVertex3f(-9.40454f / s, 29.084f / s, 0.0f);
	glVertex3f(-8.17569 / s, 31.5776 / s, 0.0f);
	//glVertex3f(-8.17569f / s, 34.0579f / s, 0.0f);
	glVertex3f(1.10165f / s, 32.5605f / s, 0.0f);
	glVertex3f(3.45318f / s, 23.4136f / s, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.573, 0.353, 0.094);
	glVertex3f(23.1395f / s, 9.77381f / s, 0.0f);
	glVertex3f(35.2466f / s, -6.2784f / s, 0.0f);
	glVertex3f(21.2375f / s, 6.99387f / s, 0.0f);
	glVertex3f(12.5045f / s, 9.7684f / s, 0.0f);
	glVertex3f(10.6397f / s, 16.1717f / s, 0.0f);
	glVertex3f(3.45318f / s, 23.4136f / s, 0.0f);
	glVertex3f(3.45318f / s, 23.4136f / s, 0.0f);
	glVertex3f(1.10165f / s, 32.5605f / s, 0.0f);
	glVertex3f(8.5474f / s, 31.4188f / s, 0.0f);
	glVertex3f(20.5552f / s, 20.6482f / s, 0.0f);
	glVertex3f(28.6969f / s, 7.13942f / s, 0.0f);
	glVertex3f(47.4818f / s, -8.09776f / s, 0.0f);
	glVertex3f(35.2466f / s, -6.2784f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.49, 0.31, 0.09);
	glVertex3f(11.9144f / s, 8.97002f / s, 0.0f);
	glVertex3f(35.2466f / s, -6.2784f / s, 0.0f);
	glVertex3f(21.2375f / s, 6.99387f / s, 0.0f);
	glVertex3f(12.5045f / s, 9.7684f / s, 0.0f);
	glVertex3f(10.6397f / s, 16.1717f / s, 0.0f);
	glVertex3f(3.45318f / s, 23.4136f / s, 0.0f);
	glVertex3f(6.90239f / s, 16.0225f / s, 0.0f);
	glVertex3f(7.054f / s, 7.5321f / s, 0.0f);
	glVertex3f(15.3928f / s, 2.26353f / s, 0.0f);
	glVertex3f(18.5387f / s, -3.87683f / s, 0.0f);
	glVertex3f(35.2466f / s, -6.2784f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.702, 0.455, 0.094);
	glVertex3f(21.8756f / s, 21.0255f / s, 0.0f);
	glVertex3f(9.78912f / s, 33.2428f / s, 0.0f);
	glVertex3f(23.1478f / s, 21.7853f / s, 0.0f);
	glVertex3f(23.1478f / s, 21.7853f / s, 0.0f);
	glVertex3f(28.6969f / s, 7.13942f / s, 0.0f);
	glVertex3f(20.5552f / s, 20.6482f / s, 0.0f);
	glVertex3f(8.5474f / s, 31.4188f / s, 0.0f);
	glVertex3f(1.10165f / s, 32.5605f / s, 0.0f);
	glVertex3f(9.78912f / s, 33.2428f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.38, 0.243, 0.071);
	glVertex3f(-40.3885f / s, -0.445272f / s, 0.0f);
	glVertex3f(-51.2949f / s, -10.3329f / s, 0.0f);
	glVertex3f(-39.3072f / s, -1.86699f / s, 0.0f);
	glVertex3f(-26.1987f / s, 19.7214f / s, 0.0f);
	glVertex3f(-15.0221f / s, 32.595f / s, 0.0f);
	glVertex3f(-28.0127f / s, 20.9503f / s, 0.0f);
	glVertex3f(-41.2374f / s, 0.469593f / s, 0.0f);
	glVertex3f(-63.7789f / s, -11.8575f / s, 0.0f);
	glVertex3f(-51.2949f / s, -10.3329f / s, 0.0f);
	glEnd();
}

void sea(void) {
	GLfloat d = 150.0f;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.718, 0.984);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(150.0f / d, 14.0f / d, 0.0f);
	glVertex3f(-150.0f / d, 14.0f / d, 0.0f);
	glVertex3f(-150.0f / d, -10.0f / d, 0.0f);
	glVertex3f(-130.0f / d, -20.0f / d, 0.0f);
	glVertex3f(-100.0f / d, -30.0f / d, 0.0f);
	glVertex3f(-80.0f / d, -32.0f / d, 0.0f);
	glVertex3f(-60.0f / d, -33.0f / d, 0.0f);
	glVertex3f(-40.0f / d, -34.6f / d, 0.0f);
	glVertex3f(-10.0f / d, -35.0f / d, 0.0f);
	glVertex3f(10.0f / d, -35.0f / d, 0.0f);
	glVertex3f(30.0f / d, -34.0f / d, 0.0f);
	glVertex3f(50.0f / d, -33.5f / d, 0.0f);
	glVertex3f(70.0f / d, -32.0f / d, 0.0f);
	glVertex3f(90.0f / d, -30.0f / d, 0.0f);
	glVertex3f(100.0f / d, -28.0f / d, 0.0f);
	glVertex3f(130.0f / d, -20.0f / d, 0.0f);
	glVertex3f(150.0f / d, -10.0f / d, 0.0f);
	glVertex3f(150.0f / d, 14.0f / d, 0.0f);
	glEnd();


	//Sea waves
	glBegin(GL_POLYGON);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(26.05f / d, -8.88f / d, 0.0f);
	glVertex3f(24.658f / d, -10.148f / d, 0.0f);
	glVertex3f(21.657f / d, -10.8745f / d, 0.0f);
	glVertex3f(26.3636f / d, -11.0324f / d, 0.0f);
	glVertex3f(30.564f / d, -11.0324f / d, 0.0f);
	glVertex3f(27.722f / d, -9.93f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(61.13f / d, 0.66f / d, 0.0f);
	glVertex3f(60.26f / d, -0.16f / d, 0.0f);
	glVertex3f(58.54f / d, -0.85f / d, 0.0f);
	glVertex3f(61.35f / d, -0.94f / d, 0.0f);
	glVertex3f(64.0f / d, -0.62f / d, 0.0f);
	glVertex3f(62.17f / d, -0.16f / d, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(65.67f / d, -15.63f / d, 0.0f);
	glVertex3f(63.0f / d, -17.0f / d, 0.0f);
	glVertex3f(68.0f / d, -17.0f / d, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(68.0f / d, -5.2f / d, 0.0f);
	glVertex3f(66.0f / d, -6.0f / d, 0.0f);
	glVertex3f(70.0f / d, -6.0f / d, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(79.0f / d, -12.8f / d, 0.0f);
	glVertex3f(77.0f / d, -14.5f / d, 0.0f);
	glVertex3f(81.0f / d, -14.5f / d, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(26.0f / d, 0.56f / d, 0.0f);
	glVertex3f(24.0f / d, -0.68f / d, 0.0f);
	glVertex3f(28.0f / d, -0.46f / d, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(26.0f / d, -8.9f / d, 0.0f);
	glVertex3f(21.0f / d, -10.8f / d, 0.0f);
	glVertex3f(30.0f / d, -10.62f / d, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(12.0f / d, -18.9f / d, 0.0f);
	glVertex3f(10.0f / d, -20.8f / d, 0.0f);
	glVertex3f(15.0f / d, -19.9f / d, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-17.5f / d, -11.0f / d, 0.0f);
	glVertex3f(-21.5f / d, -13.4f / d, 0.0f);
	glVertex3f(-13.22f / d, -13.09f / d, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-34.4f / d, -11.12f / d, 0.0f);
	glVertex3f(-38.16f / d, -13.08f / d, 0.0f);
	glVertex3f(-29.5f / d, -13.4f / d, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-67.11f / d, -11.39f / d, 0.0f);
	glVertex3f(-70.88f / d, -13.37f / d, 0.0f);
	glVertex3f(-62.68f / d, -13.08f / d, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-56.0f / d, -8.0f / d, 0.0f);
	glVertex3f(-61.0f / d, -10.2f / d, 0.0f);
	glVertex3f(-54.8f / d, -10.3f / d, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-71.0f / d, 4.5f / d, 0.0f);
	glVertex3f(-74.0f / d, 3.5f / d, 0.0f);
	glVertex3f(-69.0f / d, 3.5f / d, 0.0f);
	glEnd();


	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-43.25f / d, -2.33f / d, 0.0f);
	glVertex3f(-45.4f / d, -3.7f / d, 0.0f);
	glVertex3f(-41.8f / d, -3.7f / d, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-58.3f / d, 2.08f / d, 0.0f);
	glVertex3f(-61.5f / d, 0.73f / d, 0.0f);
	glVertex3f(-56.4f / d, 0.5f / d, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-95.6f / d, -10.8f / d, 0.0f);
	glVertex3f(-98.0f / d, -12.12f / d, 0.0f);
	glVertex3f(-94.0f / d, -12.35f / d, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-98.0f / d, 9.16f / d, 0.0f);
	glVertex3f(-98.7f / d, 7.9f / d, 0.0f);
	glVertex3f(-96.0f / d, 8.2f / d, 0.0f);
	glEnd();
}

void lankaEntrance(void) {
	void drawCloud(void);
	void drawTree(void);

	float D = 100.00f;
	float s = 100.00f;

	//triangle
	gluLookAt(0.0f, -20.0f / D, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -2.0f);
	glScalef(ab_xLanka, ab_yLanka, 0.0f);

	//sea
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.718, 0.984);
	glVertex3f(250.0 / D, 10.0 / D, 0.0f / D);
	glVertex3f(-250.0 / D, 10.0 / D, 0.0f / D);
	glVertex3f(-250.0 / D, -150.0 / D, 0.0f / D);
	glVertex3f(250.0 / D, -150.0 / D, 0.0f / D);
	glEnd();

	////Sea waves 1
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(80.0f / D, -8.0f / D, 0.0f);
	//glVertex3f(83.0f / D, -6.0f / D, 0.0f);
	//glVertex3f(87.0f / D, -9.0f / D, 0.0f);
	//glVertex3f(83.0f / D, -9.0f / D, 0.0f);
	//glEnd();
	////2
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(107.0f / D, -6.0f / D, 0.0f);
	//glVertex3f(112.0f / D, -2.0f / D, 0.0f);
	//glVertex3f(115.0f / D, -6.0f / D, 0.0f);
	//glVertex3f(110.0f / D, -7.0f / D, 0.0f);
	//glEnd();
	////3
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(114.0f / D, -16.0f / D, 0.0f);
	//glVertex3f(119.0f / D, -10.0f / D, 0.0f);
	//glVertex3f(125.0f / D, -13.0f / D, 0.0f);
	//glVertex3f(120.0f / D, -16.0f / D, 0.0f);
	//glEnd();
	////4
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(138.0f / D, -29.0f / D, 0.0f);
	//glVertex3f(142.0f / D, -24.0f / D, 0.0f);
	//glVertex3f(146.0f / D, -29.0f / D, 0.0f);
	//glVertex3f(142.0f / D, -31.0f / D, 0.0f);
	//glEnd();
	////5
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(119.0f / D, -29.0f / D, 0.0f);
	//glVertex3f(125.0f / D, -25.0f / D, 0.0f);
	//glVertex3f(128.0f / D, -30.0f / D, 0.0f);
	//glVertex3f(124.0f / D, -31.0f / D, 0.0f);
	//glEnd();
	////6
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(104.0f / D, -18.0f / D, 0.0f);
	//glVertex3f(107.0f / D, -15.0f / D, 0.0f);
	//glVertex3f(109.0f / D, -18.0f / D, 0.0f);
	//glVertex3f(106.0f / D, -20.0f / D, 0.0f);
	//glEnd();
	////7
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(89.0f / D, -11.0f / D, 0.0f);
	//glVertex3f(93.0f / D, -7.0f / D, 0.0f);
	//glVertex3f(97.0f / D, -11.0f / D, 0.0f);
	//glVertex3f(93.0f / D, -13.0f / D, 0.0f);
	//glEnd();


	// Upper Black background Sky
	glBegin(GL_POLYGON);
	glColor3f(0.086, 0.098, 0.125);
	glVertex3f(250.0 / D, 250.0 / D, 0.0f / D);
	glColor3f(0.086, 0.098, 0.125);
	glVertex3f(-250.0 / D, 250.0 / D, 0.0f / D);
	glColor3f(0.231, 0.259, 0.282);
	glVertex3f(-250.0 / D, 125.0 / D, 0.0f / D);
	glColor3f(0.231, 0.259, 0.282);
	glVertex3f(250.0 / D, 125.0 / D, 0.0f / D);
	glEnd();

	//Lower Sky
	glBegin(GL_POLYGON);
	glColor3f(0.231, 0.259, 0.282);
	glVertex3f(250.0 / D, 125.0 / D, 0.0f / D);
	glColor3f(0.231, 0.259, 0.282);
	glVertex3f(-250.0 / D, 125.0 / D, 0.0f / D);
	glColor3f(0.684, 0.794, 0.841);
	glVertex3f(-250.0 / D, 45.0 / D, 0.0f / D);
	glColor3f(0.684, 0.794, 0.841);
	glVertex3f(250.0 / D, 45.0 / D, 0.0f / D);
	glEnd();

	glLoadIdentity();
	//triangle
	gluLookAt(0.0f, -20.0f / D, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -2.0f);
	glScalef(ab_xLanka, ab_yLanka, 0.0f);
	//AGG (+X)
	for (int i = 250; i >= 51; i -= 25)
	{
		glBegin(GL_QUADS);
		glColor3f(0.361, 0.157, 0.122);
		glVertex3f((i + 10.0f) / D, 60.0 / D, 0.0f / D);
		glColor3f(0.361, 0.157, 0.122);
		glVertex3f((i - 10) / D, 60.0 / D, 0.0f / D);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f((i - 10) / D, 45.0 / D, 0.0f / D);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f((i + 10.0f) / D, 45.0 / D, 0.0f / D);
		glEnd();


		//Aagiche loop right side
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 2)) / D, 60.0f / D, 0.0f);
		}
		glEnd();

		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 4)) / D, 62.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 6)) / D, 64.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 8)) / D, 66.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 10)) / D, 68.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 12)) / D, 70.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 15)) / D, 72.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 1; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 18)) / D, 76.0f / D, 0.0f);
		}
		glEnd();
		//2
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 2)) / D, 60.0f / D, 0.0f);
		}
		glEnd();

		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 4)) / D, 62.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 6)) / D, 64.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 8)) / D, 66.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 10)) / D, 68.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 12)) / D, 70.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 14)) / D, 72.0f / D, 0.0f);
		}
		glEnd();
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 16)) / D, 74.0f / D, 0.0f);
		}
		glEnd();

	}

	//bhinth
	glBegin(GL_QUADS);
	glColor3f(0.443, 0.106, 0.114);
	glVertex3f(533.0 / D, 49.0 / D, 0.0f / D);
	glColor3f(1.0, 0.682, 0.259);
	glVertex3f(533.0 / D, 6.0 / D, 0.0f / D);
	glColor3f(1.0, 0.682, 0.259);
	glVertex3f(17.0 / D, 5.0 / D, 0.0f / D);
	glColor3f(0.443, 0.106, 0.114);
	glVertex3f(17.0 / D, 49.0 / D, 0.0f / D);
	glEnd();

	//bhinth silver color
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(250.0 / D, 25.0 / D, 0.0f / D);
	glVertex3f(250.0 / D, 22.0 / D, 0.0f / D);
	glVertex3f(16.0 / D, 22.0 / D, 0.0f / D);
	glVertex3f(16.0 / D, 25.0 / D, 0.0f / D);
	glEnd();




	//AGG (-X)
	for (int i = -250; i <= -51; i += 25)
	{
		glBegin(GL_QUADS);

		glColor3f(0.361, 0.157, 0.122);
		glVertex3f((i + 10.0f) / D, 60.0 / D, 0.0f / D);
		glColor3f(0.361, 0.157, 0.122);
		glVertex3f((i - 10) / D, 60.0 / D, 0.0f / D);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f((i - 10) / D, 45.0 / D, 0.0f / D);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f((i + 10.0f) / D, 45.0 / D, 0.0f / D);
		glEnd();

		//Aagiche loop left side
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 2)) / D, 60.0f / D, 0.0f);
		}
		glEnd();

		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 4)) / D, 62.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 6)) / D, 64.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 8)) / D, 66.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 10)) / D, 68.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 12)) / D, 70.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 15)) / D, 72.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 1; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 18)) / D, 76.0f / D, 0.0f);
		}
		glEnd();
		//2
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 2)) / D, 60.0f / D, 0.0f);
		}
		glEnd();

		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 4)) / D, 62.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 6)) / D, 64.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 8)) / D, 66.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 10)) / D, 68.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 12)) / D, 70.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 14)) / D, 72.0f / D, 0.0f);
		}
		glEnd();
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 16)) / D, 74.0f / D, 0.0f);
		}
		glEnd();
	}


	//hath
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.031f, 0.063f, 0.125f);
	glVertex3f(48.0 / D, 48.0 / D, 0.0f / D);
	glVertex3f(64.0 / D, 16.0 / D, 0.0f / D);
	glVertex3f(63.0 / D, 20.0 / D, 0.0f / D);
	glVertex3f(62.0 / D, 25.0 / D, 0.0f / D);

	glVertex3f(62.0 / D, 27.0 / D, 0.0f / D);
	glVertex3f(60.0 / D, 45.0 / D, 0.0f / D);
	glVertex3f(58.0 / D, 51.0 / D, 0.0f / D);
	glVertex3f(49.0 / D, 61.0 / D, 0.0f / D);
	glVertex3f(38.0 / D, 66.0 / D, 0.0f / D);

	glVertex3f(35.0 / D, 67.0 / D, 0.0f / D);
	glVertex3f(31.0 / D, 70.0 / D, 0.0f / D);
	glVertex3f(19.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(24.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(17.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(17.0 / D, 49.0 / D, 0.0f / D);
	glVertex3f(31.0 / D, 45.0 / D, 0.0f / D);

	glVertex3f(35.0 / D, 45.0 / D, 0.0f / D);
	glVertex3f(38.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(44.0 / D, 32.0 / D, 0.0f / D);
	glVertex3f(47.0 / D, 25.0 / D, 0.0f / D);

	glVertex3f(48.0 / D, 22.0 / D, 0.0f / D);
	glVertex3f(49.0 / D, 16.0 / D, 0.0f / D);
	glVertex3f(64.0 / D, 16.0 / D, 0.0f / D);
	glEnd();


	//
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(42.0 / D, 63.0 / D, 0.0f / D);
	glVertex3f(41.0 / D, 62.0 / D, 0.0f / D);

	glVertex3f(41.0 / D, 62.0 / D, 0.0f / D);
	glVertex3f(44.0 / D, 61.0 / D, 0.0f / D);

	glVertex3f(44.0 / D, 61.0 / D, 0.0f / D);
	glVertex3f(45.0 / D, 63.0 / D, 0.0f / D);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(18.0 / D, 51.0 / D, 0.0f / D);
	glVertex3f(25.0 / D, 54.0 / D, 0.0f / D);

	glVertex3f(25.0 / D, 54.0 / D, 0.0f / D);
	glVertex3f(25.0 / D, 57.0 / D, 0.0f / D);

	glEnd();

	//hata varchey kadey1
	glBegin(GL_POLYGON);
	glColor3f(0.831f, 0.376f, 0.012f);
	glVertex3f(35.0 / D, 45.0 / D, 0.0f / D);
	glVertex3f(36.0 / D, 55.0 / D, 0.0f / D);
	glVertex3f(38.0 / D, 66.0 / D, 0.0f / D);
	glVertex3f(35.0 / D, 67.0 / D, 0.0f / D);
	glVertex3f(34.0 / D, 56.0 / D, 0.0f / D);
	glVertex3f(31.0 / D, 45.0 / D, 0.0f / D);
	glEnd();

	//

	glBegin(GL_POLYGON);
	glColor3f(0.831f, 0.376f, 0.012f);
	glVertex3f(47.0 / D, 25.0 / D, 0.0f / D);
	glVertex3f(55.0 / D, 28.0 / D, 0.0f / D);
	glVertex3f(62.0 / D, 27.0 / D, 0.0f / D);
	glVertex3f(62.0 / D, 25.0 / D, 0.0f / D);
	glVertex3f(56.0 / D, 26.0 / D, 0.0f / D);
	glVertex3f(48.0 / D, 22.0 / D, 0.0f / D);
	glEnd();


	//darwaja
	glBegin(GL_QUADS);
	glColor3f(0.855f, 0.451f, 0.098f);
	glVertex3f(17.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(10.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(11.0 / D, 5.0 / D, 0.0f / D);
	glVertex3f(17.0 / D, 5.0 / D, 0.0f / D);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.808, 0.0);
	glVertex3f(11.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(11.0 / D, 18.0 / D, 0.0f / D);
	glVertex3f(2.0 / D, 26.0 / D, 0.0f / D);
	glVertex3f(0.0 / D, 32.0 / D, 0.0f / D);
	glVertex3f(0.0 / D, 44.0 / D, 0.0f / D);
	glEnd();

	//entrance glow
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0 / D, 4.0 / D, 0.0f / D);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(11.0 / D, 5.0 / D, 0.0f / D);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(11.0 / D, 18.0 / D, 0.0f / D);
	glVertex3f(2.0 / D, 26.0 / D, 0.0f / D);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.0 / D, 32.0 / D, 0.0f / D);
	glEnd();
	//face shing 1
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(11.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(16.0 / D, 75.0 / D, 0.0f / D);
	glVertex3f(18.0 / D, 76.0 / D, 0.0f / D);
	glVertex3f(17.0 / D, 77.0 / D, 0.0f / D);
	glVertex3f(17.0 / D, 78.0 / D, 0.0f / D);
	glVertex3f(18.0 / D, 78.0 / D, 0.0f / D);
	glVertex3f(19.0 / D, 77.0 / D, 0.0f / D);
	glVertex3f(19.0 / D, 74.0 / D, 0.0f / D);
	glVertex3f(19.0 / D, 72.0 / D, 0.0f / D);
	glVertex3f(14.0 / D, 68.0 / D, 0.0f / D);
	glEnd();

	//face shing 2

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(12.0 / D, 46.0 / D, 0.0f / D);
	glVertex3f(16.0 / D, 41.0 / D, 0.0f / D);
	glVertex3f(19.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(16.0 / D, 39.0 / D, 0.0f / D);
	glVertex3f(9.0 / D, 44.0 / D, 0.0f / D);
	glEnd();

	//face
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.031f, 0.063f, 0.125f);
	glVertex3f(0.0 / D, 69.0 / D, 0.0f / D);
	glVertex3f(0.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(9.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(14.0 / D, 47.0 / D, 0.0f / D);
	glVertex3f(14.0 / D, 68.0 / D, 0.0f / D);
	glVertex3f(11.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(9.0 / D, 76.0 / D, 0.0f / D);
	glVertex3f(5.0 / D, 78.0 / D, 0.0f / D);
	glVertex3f(0.0 / D, 80.0 / D, 0.0f / D);
	glEnd();

	//face glowing eye
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(11.0 / D, 53.0 / D, 0.0f / D);
	glVertex3f(11.0 / D, 56.0 / D, 0.0f / D);
	glVertex3f(9.0 / D, 57.0 / D, 0.0f / D);
	glVertex3f(6.0 / D, 56.0 / D, 0.0f / D);
	glVertex3f(7.0 / D, 52.0 / D, 0.0f / D);
	glVertex3f(9.0 / D, 52.0 / D, 0.0f / D);
	glVertex3f(9.0 / D, 54.0 / D, 0.0f / D);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0 / D, 52.0 / D, 0.0f / D);
	glVertex3f(5.0 / D, 49.0 / D, 0.0f / D);

	glVertex3f(5.0 / D, 49.0 / D, 0.0f / D);
	glVertex3f(8.0 / D, 51.0 / D, 0.0f / D);

	glVertex3f(8.0 / D, 51.0 / D, 0.0f / D);
	glVertex3f(11.0 / D, 49.0 / D, 0.0f / D);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(3.0 / D, 46.0 / D, 0.0f / D);
	glVertex3f(5.0 / D, 48.0 / D, 0.0f / D);

	glVertex3f(5.0 / D, 48.0 / D, 0.0f / D);
	glVertex3f(9.0 / D, 47.0 / D, 0.0f / D);

	glVertex3f(9.0 / D, 47.0 / D, 0.0f / D);
	glVertex3f(11.0 / D, 49.0 / D, 0.0f / D);
	glEnd();

	//road
	glBegin(GL_POLYGON);
	glColor3f(0.882f, 0.757f, 0.431f);
	glVertex3f(17.0 / D, 5.0 / D, 0.0f / D);

	glColor3f(0.529, 0.529, 0.529);
	glVertex3f(450.0 / D, -150.0 / D, 0.0f / D);

	glColor3f(0.529, 0.529, 0.529);
	glVertex3f(0.0 / D, -150.0 / D, 0.0f / D);

	glColor3f(0.882f, 0.757f, 0.431f);
	glVertex3f(0.0 / D, 4.0 / D, 0.0f / D);
	glEnd();

	//on road lines
	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(1.0, 0.808, 0.0);
	glVertex3f(11.0 / D, 5.0 / D, 0.0f / D);
	glVertex3f(350.0 / D, -150.0 / D, 0.0f / D);
	glEnd();


	glBegin(GL_LINES);
	glVertex3f(8.0 / D, 5.0 / D, 0.0f / D);
	glVertex3f(250.0 / D, -150.0 / D, 0.0f / D);
	glEnd();


	//******************************************************************************************************************************************************************//
			//opposite part
			//Sea waves 1
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-80.0f / D, -8.0f / D, 0.0f);
	//glVertex3f(-83.0f / D, -6.0f / D, 0.0f);
	//glVertex3f(-87.0f / D, -9.0f / D, 0.0f);
	//glVertex3f(-83.0f / D, -9.0f / D, 0.0f);
	//glEnd();
	////2
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-107.0f / D, -6.0f / D, 0.0f);
	//glVertex3f(-112.0f / D, -2.0f / D, 0.0f);
	//glVertex3f(-115.0f / D, -6.0f / D, 0.0f);
	//glVertex3f(-110.0f / D, -7.0f / D, 0.0f);
	//glEnd();
	////3
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-114.0f / D, -16.0f / D, 0.0f);
	//glVertex3f(-119.0f / D, -10.0f / D, 0.0f);
	//glVertex3f(-125.0f / D, -13.0f / D, 0.0f);
	//glVertex3f(-120.0f / D, -16.0f / D, 0.0f);
	//glEnd();
	////4
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-138.0f / D, -29.0f / D, 0.0f);
	//glVertex3f(-142.0f / D, -24.0f / D, 0.0f);
	//glVertex3f(-146.0f / D, -29.0f / D, 0.0f);
	//glVertex3f(-142.0f / D, -31.0f / D, 0.0f);
	//glEnd();
	////5
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-119.0f / D, -29.0f / D, 0.0f);
	//glVertex3f(-125.0f / D, -25.0f / D, 0.0f);
	//glVertex3f(-128.0f / D, -30.0f / D, 0.0f);
	//glVertex3f(-124.0f / D, -31.0f / D, 0.0f);
	//glEnd();
	////6
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-104.0f / D, -18.0f / D, 0.0f);
	//glVertex3f(-107.0f / D, -15.0f / D, 0.0f);
	//glVertex3f(-109.0f / D, -18.0f / D, 0.0f);
	//glVertex3f(-106.0f / D, -20.0f / D, 0.0f);
	//glEnd();
	////7
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-89.0f / D, -11.0f / D, 0.0f);
	//glVertex3f(-93.0f / D, -7.0f / D, 0.0f);
	//glVertex3f(-97.0f / D, -11.0f / D, 0.0f);
	//glVertex3f(-93.0f / D, -13.0f / D, 0.0f);
	//glEnd();

	//bhinth
	glBegin(GL_QUADS);
	glColor3f(0.22, 0.239, 0.271);
	glColor3f(0.443, 0.106, 0.114);
	glVertex3f(-533.0 / D, 49.0 / D, 0.0f / D);
	glColor3f(1.0, 0.682, 0.259);
	glVertex3f(-533.0 / D, 6.0 / D, 0.0f / D);
	glColor3f(1.0, 0.682, 0.259);
	glVertex3f(-17.0 / D, 5.0 / D, 0.0f / D);
	glColor3f(0.443, 0.106, 0.114);
	glVertex3f(-17.0 / D, 49.0 / D, 0.0f / D);
	glEnd();

	//bhinth silver color
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-250.0 / D, 25.0 / D, 0.0f / D);
	glVertex3f(-250.0 / D, 22.0 / D, 0.0f / D);
	glVertex3f(-16.0 / D, 22.0 / D, 0.0f / D);
	glVertex3f(-16.0 / D, 25.0 / D, 0.0f / D);
	glEnd();
	//hath
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.031f, 0.063f, 0.125f);
	glVertex3f(-48.0 / D, 48.0 / D, 0.0f / D);
	glVertex3f(-64.0 / D, 16.0 / D, 0.0f / D);
	glVertex3f(-63.0 / D, 20.0 / D, 0.0f / D);
	glVertex3f(-62.0 / D, 25.0 / D, 0.0f / D);

	glVertex3f(-62.0 / D, 27.0 / D, 0.0f / D);
	glVertex3f(-60.0 / D, 45.0 / D, 0.0f / D);
	glVertex3f(-58.0 / D, 51.0 / D, 0.0f / D);
	glVertex3f(-49.0 / D, 61.0 / D, 0.0f / D);
	glVertex3f(-38.0 / D, 66.0 / D, 0.0f / D);

	glVertex3f(-35.0 / D, 67.0 / D, 0.0f / D);
	glVertex3f(-31.0 / D, 70.0 / D, 0.0f / D);
	glVertex3f(-19.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(-24.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(-17.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(-17.0 / D, 49.0 / D, 0.0f / D);
	glVertex3f(-31.0 / D, 45.0 / D, 0.0f / D);

	glVertex3f(-35.0 / D, 45.0 / D, 0.0f / D);
	glVertex3f(-38.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(-44.0 / D, 32.0 / D, 0.0f / D);
	glVertex3f(-47.0 / D, 25.0 / D, 0.0f / D);

	glVertex3f(-48.0 / D, 22.0 / D, 0.0f / D);
	glVertex3f(-49.0 / D, 16.0 / D, 0.0f / D);
	glVertex3f(-64.0 / D, 16.0 / D, 0.0f / D);
	glEnd();

	//

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-42.0 / D, 63.0 / D, 0.0f / D);
	glVertex3f(-41.0 / D, 62.0 / D, 0.0f / D);

	glVertex3f(-41.0 / D, 62.0 / D, 0.0f / D);
	glVertex3f(-44.0 / D, 61.0 / D, 0.0f / D);

	glVertex3f(-44.0 / D, 61.0 / D, 0.0f / D);
	glVertex3f(-45.0 / D, 63.0 / D, 0.0f / D);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-18.0 / D, 51.0 / D, 0.0f / D);
	glVertex3f(-25.0 / D, 54.0 / D, 0.0f / D);

	glVertex3f(-25.0 / D, 54.0 / D, 0.0f / D);
	glVertex3f(-25.0 / D, 57.0 / D, 0.0f / D);

	glEnd();
	//hata varchey kadey1
	glBegin(GL_POLYGON);
	glColor3f(0.831f, 0.376f, 0.012f);
	glVertex3f(-35.0 / D, 45.0 / D, 0.0f / D);
	glVertex3f(-36.0 / D, 55.0 / D, 0.0f / D);
	glVertex3f(-38.0 / D, 66.0 / D, 0.0f / D);
	glVertex3f(-35.0 / D, 67.0 / D, 0.0f / D);
	glVertex3f(-34.0 / D, 56.0 / D, 0.0f / D);
	glVertex3f(-31.0 / D, 45.0 / D, 0.0f / D);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.831f, 0.376f, 0.012f);
	glVertex3f(-47.0 / D, 25.0 / D, 0.0f / D);
	glVertex3f(-55.0 / D, 28.0 / D, 0.0f / D);
	glVertex3f(-62.0 / D, 27.0 / D, 0.0f / D);
	glVertex3f(-62.0 / D, 25.0 / D, 0.0f / D);
	glVertex3f(-56.0 / D, 26.0 / D, 0.0f / D);
	glVertex3f(-48.0 / D, 22.0 / D, 0.0f / D);
	glEnd();

	//darwaja
	glBegin(GL_QUADS);
	glColor3f(0.855f, 0.451f, 0.098f);
	glVertex3f(-17.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(-10.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(-11.0 / D, 5.0 / D, 0.0f / D);
	glVertex3f(-17.0 / D, 5.0 / D, 0.0f / D);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.808, 0.0);
	glVertex3f(-11.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(-11.0 / D, 18.0 / D, 0.0f / D);
	glVertex3f(-2.0 / D, 26.0 / D, 0.0f / D);
	glVertex3f(-0.0 / D, 32.0 / D, 0.0f / D);
	glVertex3f(-0.0 / D, 44.0 / D, 0.0f / D);
	glEnd();
	//entrance glow
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0 / D, 4.0 / D, 0.0f / D);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-11.0 / D, 5.0 / D, 0.0f / D);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-11.0 / D, 18.0 / D, 0.0f / D);
	glVertex3f(-2.0 / D, 26.0 / D, 0.0f / D);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.0 / D, 32.0 / D, 0.0f / D);
	glEnd();

	//face shing 1
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-11.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(-16.0 / D, 75.0 / D, 0.0f / D);
	glVertex3f(-18.0 / D, 76.0 / D, 0.0f / D);
	glVertex3f(-17.0 / D, 77.0 / D, 0.0f / D);
	glVertex3f(-17.0 / D, 78.0 / D, 0.0f / D);
	glVertex3f(-18.0 / D, 78.0 / D, 0.0f / D);
	glVertex3f(-19.0 / D, 77.0 / D, 0.0f / D);
	glVertex3f(-19.0 / D, 74.0 / D, 0.0f / D);
	glVertex3f(-19.0 / D, 72.0 / D, 0.0f / D);
	glVertex3f(-14.0 / D, 68.0 / D, 0.0f / D);
	glEnd();

	//face shing 2

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-12.0 / D, 46.0 / D, 0.0f / D);
	glVertex3f(-16.0 / D, 41.0 / D, 0.0f / D);
	glVertex3f(-19.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(-16.0 / D, 39.0 / D, 0.0f / D);
	glVertex3f(-9.0 / D, 44.0 / D, 0.0f / D);


	glEnd();

	//face
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.031f, 0.063f, 0.125f);
	glVertex3f(-0.0 / D, 69.0 / D, 0.0f / D);
	glVertex3f(-0.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(-9.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(-14.0 / D, 47.0 / D, 0.0f / D);
	glVertex3f(-14.0 / D, 68.0 / D, 0.0f / D);
	glVertex3f(-11.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(-9.0 / D, 76.0 / D, 0.0f / D);
	glVertex3f(-5.0 / D, 78.0 / D, 0.0f / D);
	glVertex3f(-0.0 / D, 80.0 / D, 0.0f / D);
	glEnd();

	//face glowing eye
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-11.0 / D, 53.0 / D, 0.0f / D);
	glVertex3f(-11.0 / D, 56.0 / D, 0.0f / D);
	glVertex3f(-9.0 / D, 57.0 / D, 0.0f / D);
	glVertex3f(-6.0 / D, 56.0 / D, 0.0f / D);
	glVertex3f(-7.0 / D, 52.0 / D, 0.0f / D);
	glVertex3f(-9.0 / D, 52.0 / D, 0.0f / D);
	glVertex3f(-9.0 / D, 54.0 / D, 0.0f / D);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0 / D, 52.0 / D, 0.0f / D);
	glVertex3f(-5.0 / D, 49.0 / D, 0.0f / D);

	glVertex3f(-5.0 / D, 49.0 / D, 0.0f / D);
	glVertex3f(-8.0 / D, 51.0 / D, 0.0f / D);

	glVertex3f(-8.0 / D, 51.0 / D, 0.0f / D);
	glVertex3f(-11.0 / D, 49.0 / D, 0.0f / D);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-3.0 / D, 46.0 / D, 0.0f / D);
	glVertex3f(-5.0 / D, 48.0 / D, 0.0f / D);

	glVertex3f(-5.0 / D, 48.0 / D, 0.0f / D);
	glVertex3f(-9.0 / D, 47.0 / D, 0.0f / D);

	glVertex3f(-9.0 / D, 47.0 / D, 0.0f / D);
	glVertex3f(-11.0 / D, 49.0 / D, 0.0f / D);
	glEnd();

	//road
	glBegin(GL_POLYGON);
	glColor3f(0.882f, 0.757f, 0.431f);
	glVertex3f(-17.0 / D, 5.0 / D, 0.0f / D);

	glColor3f(0.529, 0.529, 0.529);
	glVertex3f(-450.0 / D, -150.0 / D, 0.0f / D);

	glColor3f(0.529, 0.529, 0.529);
	glVertex3f(-0.0 / D, -150.0 / D, 0.0f / D);

	glColor3f(0.882f, 0.757f, 0.431f);
	glVertex3f(-0.0 / D, 4.0 / D, 0.0f / D);
	glEnd();

	//on road lines
	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(1.0, 0.808, 0.0);
	glVertex3f(-11.0 / D, 5.0 / D, 0.0f / D);
	glVertex3f(-320.0 / D, -150.0 / D, 0.0f / D);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-8.0 / D, 5.0 / D, 0.0f / D);
	glVertex3f(-250.0 / D, -150.0 / D, 0.0f / D);
	glEnd();


	if (gCount == 9) {
		//Tree 1
		glLoadIdentity();
		glTranslatef(1.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.667f, 1.0f, 0.0f);
		drawTree();

		//tree2
		glLoadIdentity();
		glTranslatef(2.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.486, 0.988, 0.0);
		drawTree();

		//tree3
		glLoadIdentity();
		glTranslatef(4.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.667f, 1.0f, 0.0f);
		drawTree();

		//tree4
		glLoadIdentity();
		glTranslatef(5.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.486, 0.988, 0.0);
		drawTree();

		//tree5
		glLoadIdentity();
		glTranslatef(6.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.565, 0.933, 0.565);
		drawTree();

		//tree6
		glLoadIdentity();
		glTranslatef(7.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.486, 0.988, 0.0);
		drawTree();

		//tree7
		glLoadIdentity();
		glTranslatef(8.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.565, 0.933, 0.565);
		drawTree();

		//tree8
		glLoadIdentity();
		glTranslatef(9.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.486, 0.988, 0.0);
		drawTree();

		//tree9
		glLoadIdentity();
		glTranslatef(10.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.565, 0.933, 0.565);
		drawTree();

		//tree10
		glLoadIdentity();
		glTranslatef(11.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.667f, 1.0f, 0.0f);
		drawTree();

		//tree11
		glLoadIdentity();
		glTranslatef(12.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.486, 0.988, 0.0);
		drawTree();

		//Tree 1
		glLoadIdentity();
		glTranslatef(-1.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.667f, 1.0f, 0.0f);
		drawTree();

		//tree2
		glLoadIdentity();
		glTranslatef(-2.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.565, 0.933, 0.565);
		drawTree();

		//tree3
		glLoadIdentity();
		glTranslatef(-4.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.667f, 1.0f, 0.0f);
		drawTree();

		//tree4
		glLoadIdentity();
		glTranslatef(-5.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.486, 0.988, 0.0);
		drawTree();

		//tree5
		glLoadIdentity();
		glTranslatef(-6.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.565, 0.933, 0.565);
		drawTree();

		//tree6
		glLoadIdentity();
		glTranslatef(-7.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.486, 0.988, 0.0);
		drawTree();

		//tree7
		glLoadIdentity();
		glTranslatef(-8.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.667f, 1.0f, 0.0f);
		drawTree();

		//tree8
		glLoadIdentity();
		glTranslatef(-9.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.486, 0.988, 0.0);
		drawTree();

		//tree9
		glLoadIdentity();
		glTranslatef(-10.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.565, 0.933, 0.565);
		drawTree();

		//tree10
		glLoadIdentity();
		glTranslatef(-11.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.667f, 1.0f, 0.0f);
		drawTree();

		//tree11
		glLoadIdentity();
		glTranslatef(-12.3f * ab_xLanka, -1.7f * ab_xLanka, -17.6f * ab_xLanka);
		glScalef(ab_xLanka, ab_yLanka, 0.0f);
		glColor3f(0.486, 0.988, 0.0);
		drawTree();

		//waves
		glLoadIdentity();
		glTranslatef(0.5f, -0.2f, -1.4f);
		glScalef(abxScaleWave, abyScaleWave, 1.0f);
		glBegin(GL_POLYGON);
		glColor3f(0.376, 0.878, 1.0);
		glVertex3f(26.05f / d, -8.88f / d, 0.0f);
		glVertex3f(24.658f / d, -10.148f / d, 0.0f);
		glVertex3f(21.657f / d, -10.8745f / d, 0.0f);
		glVertex3f(26.3636f / d, -11.0324f / d, 0.0f);
		glVertex3f(30.564f / d, -11.0324f / d, 0.0f);
		glVertex3f(27.722f / d, -9.93f / d, 0.0f);
		glEnd();
		glLoadIdentity();
		glTranslatef(-0.5f, -0.2f, -1.4f);
		glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


		glScalef(abxScaleWave, abyScaleWave, 1.0f);
		glBegin(GL_POLYGON);
		glColor3f(0.376, 0.878, 1.0);
		glVertex3f(26.05f / d, -8.88f / d, 0.0f);
		glVertex3f(24.658f / d, -10.148f / d, 0.0f);
		glVertex3f(21.657f / d, -10.8745f / d, 0.0f);
		glVertex3f(26.3636f / d, -11.0324f / d, 0.0f);
		glVertex3f(30.564f / d, -11.0324f / d, 0.0f);
		glVertex3f(27.722f / d, -9.93f / d, 0.0f);
		glEnd();
		glLoadIdentity();
		glTranslatef(-0.1f, -0.16f, -1.1f);
		glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

		glScalef(abxScaleWave, abyScaleWave, 1.0f);
		glBegin(GL_POLYGON);
		glColor3f(0.376, 0.878, 1.0);
		glVertex3f(61.13f / d, 0.66f / d, 0.0f);
		glVertex3f(60.26f / d, -0.16f / d, 0.0f);
		glVertex3f(58.54f / d, -0.85f / d, 0.0f);
		glVertex3f(61.35f / d, -0.94f / d, 0.0f);
		glVertex3f(64.0f / d, -0.62f / d, 0.0f);
		glVertex3f(62.17f / d, -0.16f / d, 0.0f);
		glEnd();
		glLoadIdentity();
		glTranslatef(-0.14f, -0.16f, -1.1f);
		glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


		//
		glScalef(abxScaleWave, abyScaleWave, 1.0f);
		glBegin(GL_TRIANGLES);
		glColor3f(0.376, 0.878, 1.0);
		glVertex3f(65.67f / d, -15.63f / d, 0.0f);
		glVertex3f(63.0f / d, -17.0f / d, 0.0f);
		glVertex3f(68.0f / d, -17.0f / d, 0.0f);
		glEnd();
		glLoadIdentity();
		glTranslatef(0.3f, -0.1f, -1.1f);
		glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


		//oppposite	

		glScalef(abxScaleWave, abyScaleWave, 1.0f);
		glBegin(GL_TRIANGLES);
		glColor3f(0.376, 0.878, 1.0);
		glVertex3f(-17.5f / d, -11.0f / d, 0.0f);
		glVertex3f(-21.5f / d, -13.4f / d, 0.0f);
		glVertex3f(-13.22f / d, -13.09f / d, 0.0f);
		glEnd();
		glLoadIdentity();
		glTranslatef(0.6f, -0.1f, -1.1f);
		glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


		glScalef(abxScaleWave, abyScaleWave, 1.0f);
		glBegin(GL_TRIANGLES);
		glColor3f(0.376, 0.878, 1.0);
		glVertex3f(-17.5f / d, -11.0f / d, 0.0f);
		glVertex3f(-21.5f / d, -13.4f / d, 0.0f);
		glVertex3f(-13.22f / d, -13.09f / d, 0.0f);
		glEnd();
		glLoadIdentity();
		glTranslatef(0.5f, -0.3f, -1.6f);
		glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

		glScalef(abxScaleWave, abyScaleWave, 1.0f);
		glBegin(GL_TRIANGLES);
		glColor3f(0.376, 0.878, 1.0);
		glVertex3f(-34.4f / d, -11.12f / d, 0.0f);
		glVertex3f(-38.16f / d, -13.08f / d, 0.0f);
		glVertex3f(-29.5f / d, -13.4f / d, 0.0f);
		glEnd();
		glLoadIdentity();
		glTranslatef(-0.8f, -0.09f, -1.1f);
		glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

		glScalef(abxScaleWave, abyScaleWave, 1.0f);
		glBegin(GL_TRIANGLES);
		glColor3f(0.376, 0.878, 1.0);
		glVertex3f(-67.11f / d, -11.39f / d, 0.0f);
		glVertex3f(-70.88f / d, -13.37f / d, 0.0f);
		glVertex3f(-62.68f / d, -13.08f / d, 0.0f);
		glEnd();


		glLoadIdentity();
		//Draw Cloud 01
		glTranslatef(ab_xMove, 0.2f, -2.0f);
		//glScalef(0.0f, 2.0f, 1.0f);
		drawCloud();

		//Draw Cloud 02
		glTranslatef(0.0f, 0.3f, -2.0f);
		//glScalef(2.0f, 2.0f, 2.0f);
		drawCloud();
	}
}

void drawTree(void)
{
	GLfloat s = 100.0f;
	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(10.0f / s, 5.0f / s, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 15.0f / s;
		float y = sin(a) * 15.0f / s;

		glVertex3f((10.0f / s) + x, (5.0f / s) + y, 0.0f);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(27.0f / s, 17.0f / s, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 15.0f / s;
		float y = sin(a) * 15.0f / s;

		glVertex3f((27.0f / s) + x, (17.0f / s) + y, 0.0f);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(19.0f / s, 43.0f / s, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 15.0f / s;
		float y = sin(a) * 15.0f / s;

		glVertex3f((19.0f / s) + x, (43.0f / s) + y, 0.0f);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(0.0f / s, 30.0f / s, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 25.0f / s;
		float y = sin(a) * 25.0f / s;

		glVertex3f((0.0f / s) + x, (30.0f / s) + y, 0.0f);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(-2.0f / s, 44.0f / s, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 20.0f / s;
		float y = sin(a) * 20.0f / s;

		glVertex3f((-2.0f / s) + x, (44.0f / s) + y, 0.0f);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(-15.0f / s, 21.0f / s, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 20.0f / s;
		float y = sin(a) * 20.0f / s;

		glVertex3f((-15.0f / s) + x, (21.0f / s) + y, 0.0f);
	}
	glEnd();

	// Main Khod
	glBegin(GL_QUADS);
	glColor3f(0.145, 0.059, 0.027);

	glVertex3f(5.0f / s, -27.0f / s, 0.0f);
	glVertex3f(1.0f / s, 30.0f / s, 0.0f);
	glVertex3f(-0.30f / s, 30.0f / s, 0.0f);
	glVertex3f(-3.0f / s, -28.0f / s, 0.0f);

	glVertex3f(3.0f / s, 0.0f / s, 0.0f);
	glVertex3f(15.0f / s, 13.0f / s, 0.0f);
	glVertex3f(14.0f / s, 14.0f / s, 0.0f);
	glVertex3f(2.0f / s, 5.0f / s, 0.0f);

	glVertex3f(-2.0f / s, 0.0f / s, 0.0f);
	glVertex3f(-14.0f / s, 18.0f / s, 0.0f);
	glVertex3f(-13.0f / s, 19.0f / s, 0.0f);
	glVertex3f(-1.0f / s, 6.0f / s, 0.0f);
	glEnd();
}

void drawCloud(void)
{
	GLfloat s = 100.0f;
	//clouds 1
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.086, 0.098, 0.125);
	glVertex3f(-77.9159f / s, 38.207f / s, 0.0f);
	glVertex3f(-72.3219f / s, 37.2294f / s, 0.0f);
	glVertex3f(-75.309f / s, 37.0122f / s, 0.0f);
	glVertex3f(-79.5995f / s, 34.7311f / s, 0.0f);
	glVertex3f(-81.2932f / s, 34.5682f / s, 0.0f);
	glVertex3f(-82.8582f / s, 35.2199f / s, 0.0f);
	glVertex3f(-85.5738f / s, 34.5682f / s, 0.0f);
	glVertex3f(-87.366f / s, 35.1656f / s, 0.0f);
	glVertex3f(-88.8324f / s, 36.3061f / s, 0.0f);
	glVertex3f(-89.5928f / s, 38.0441f / s, 0.0f);
	glVertex3f(-89.2669f / s, 39.2932f / s, 0.0f);
	glVertex3f(-88.0178f / s, 40.7053f / s, 0.0f);
	glVertex3f(-86.1712f / s, 41.4657f / s, 0.0f);
	glVertex3f(-84.2703f / s, 41.8459f / s, 0.0f);
	glVertex3f(-83.7929f / s, 42.8349f / s, 0.0f);
	glVertex3f(-83.0212f / s, 43.5838f / s, 0.0f);
	glVertex3f(-82.0979f / s, 43.964f / s, 0.0f);
	glVertex3f(-81.0117f / s, 44.0183f / s, 0.0f);
	glVertex3f(-79.9254f / s, 43.6924f / s, 0.0f);
	glVertex3f(-78.7306f / s, 42.7148f / s, 0.0f);
	glVertex3f(-77.1012f / s, 41.0312f / s, 0.0f);
	glVertex3f(-75.8521f / s, 41.6286f / s, 0.0f);
	glVertex3f(-74.6572f / s, 42.2804f / s, 0.0f);
	glVertex3f(-73.4081f / s, 42.4976f / s, 0.0f);
	glVertex3f(-72.3219f / s, 42.0088f / s, 0.0f);
	glVertex3f(-71.8874f / s, 41.0312f / s, 0.0f);
	glVertex3f(-72.2132f / s, 38.9674f / s, 0.0f);
	glVertex3f(-66.1847f / s, 38.4243f / s, 0.0f);
	glVertex3f(-65.533f / s, 37.7182f / s, 0.0f);
	glVertex3f(-66.4019f / s, 37.1751f / s, 0.0f);
	glVertex3f(-66.4019f / s, 37.1751f / s, 0.0f);
	glVertex3f(-72.3219f / s, 37.2294f / s, 0.0f);
	glEnd();
}

void lankini(void) {

	GLfloat s = 100.0f;
	glTranslatef(ab_Xtranslate, ab_Ytranslate, -3.0f);
	glScalef(ab_Xscale, ab_Yscale, 1.0f);
	glRotatef(ab_xRotate, 0.0f, 0.0f, 1.0f);
	//shing 1
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.776f, 0.753f, 0.706f);

	glVertex3f(-27.0f / s, 68.0f / s, 0.0f / s);
	glVertex3f(-31.0f / s, 70.0f / s, 0.0f / s);
	glVertex3f(-28.0f / s, 71.0f / s, 0.0f / s);
	glVertex3f(-28.0f / s, 76.0f / s, 0.0f / s);

	glEnd();

	//shing 2
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.776f, 0.753f, 0.706f);

	glVertex3f(-8.0f / s, 74.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 77.0f / s, 0.0f / s);
	glVertex3f(-6.0f / s, 77.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, 80.0f / s, 0.0f / s);

	glEnd();
	//hair 
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.471f, 0.255f, 0.118f);
	glVertex3f(-8.0f / s, 30.0f / s, 0.0f / s);
	glVertex3f(13.0f / s, 5.0f / s, 0.0f / s);
	glVertex3f(13.0f / s, 14.0f / s, 0.0f / s);
	glVertex3f(12.0f / s, 21.0f / s, 0.0f / s);
	glVertex3f(15.0f / s, 23.0f / s, 0.0f / s);
	glVertex3f(11.0f / s, 45.0f / s, 0.0f / s);
	glVertex3f(5.0f / s, 49.0f / s, 0.0f / s);
	glVertex3f(5.0f / s, 45.0f / s, 0.0f / s);
	glVertex3f(1.0f / s, 58.0f / s, 0.0f / s);
	glVertex3f(1.0f / s, 62.0f / s, 0.0f / s);
	glVertex3f(-1.0f / s, 64.0f / s, 0.0f / s);
	glVertex3f(-1.0f / s, 68.0f / s, 0.0f / s);
	glVertex3f(-4.0f / s, 70.0f / s, 0.0f / s);
	glVertex3f(-4.0f / s, 73.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 74.0f / s, 0.0f / s);
	glVertex3f(-17.0f / s, 76.0f / s, 0.0f / s);
	glVertex3f(-21.0f / s, 76.0f / s, 0.0f / s);
	glVertex3f(-23.0f / s, 73.0f / s, 0.0f / s);
	glVertex3f(-26.0f / s, 72.0f / s, 0.0f / s);
	glVertex3f(-27.0f / s, 68.0f / s, 0.0f / s);
	glVertex3f(-31.0f / s, 66.0f / s, 0.0f / s);
	glVertex3f(-31.0f / s, 60.0f / s, 0.0f / s);
	glVertex3f(-33.0f / s, 58.0f / s, 0.0f / s);
	glVertex3f(-32.0f / s, 52.0f / s, 0.0f / s);
	glVertex3f(-37.0f / s, 49.0f / s, 0.0f / s);
	glVertex3f(-37.0f / s, 43.0f / s, 0.0f / s);
	glVertex3f(-41.0f / s, 39.0f / s, 0.0f / s);
	glVertex3f(-41.0f / s, 32.0f / s, 0.0f / s);
	glVertex3f(-43.0f / s, 24.0f / s, 0.0f / s);
	glVertex3f(-46.0f / s, 22.0f / s, 0.0f / s);
	glVertex3f(-44.0f / s, 16.0f / s, 0.0f / s);
	glVertex3f(-34.0f / s, 9.0f / s, 0.0f / s);

	glEnd();
	// Panjha left 1
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.373f, 0.373f, 0.545f);
	glVertex3f(-22.0f / s, -82.0f / s, 0.0f / s);
	glVertex3f(-16.0f / s, -94.0f / s, 0.0f / s);
	glVertex3f(-15.0f / s, -87.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, -78.0f / s, 0.0f / s);
	glVertex3f(-22.0f / s, -80.0f / s, 0.0f / s);
	glVertex3f(-26.0f / s, -79.0f / s, 0.0f / s);
	glVertex3f(-28.0f / s, -93.0f / s, 0.0f / s);
	glVertex3f(-21.0f / s, -95.0f / s, 0.0f / s);
	glVertex3f(-16.0f / s, -94.0f / s, 0.0f / s);

	glEnd();

	// left 1
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.569f, 0.565f, 0.733f);
	glVertex3f(-22.0f / s, -80.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, -78.0f / s, 0.0f / s);
	glVertex3f(-26.0f / s, -79.0f / s, 0.0f / s);
	glVertex3f(-16.0f / s, -66.0f / s, 0.0f / s);
	glVertex3f(-27.0f / s, -67.0f / s, 0.0f / s);
	glVertex3f(-14.0f / s, -51.0f / s, 0.0f / s);
	glVertex3f(-28.0f / s, -51.0f / s, 0.0f / s);

	glEnd();


	// Panjha right 1
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.373f, 0.373f, 0.545f);
	glVertex3f(12.0f / s, -85.0f / s, 0.0f / s);
	glVertex3f(11.0f / s, -79.0f / s, 0.0f / s);
	glVertex3f(2.0f / s, -86.0f / s, 0.0f / s);
	glVertex3f(3.0f / s, -78.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, -83.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, -78.0f / s, 0.0f / s);

	glEnd();


	// leg right 1
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.569f, 0.565f, 0.733f);
	glVertex3f(-7.0f / s, -78.0f / s, 0.0f / s);
	glVertex3f(3.0f / s, -78.0f / s, 0.0f / s);
	glVertex3f(-6.0f / s, -74.0f / s, 0.0f / s);
	glVertex3f(2.0f / s, -73.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, -63.0f / s, 0.0f / s);
	glVertex3f(5.0f / s, -60.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, -52.0f / s, 0.0f / s);
	glVertex3f(4.0f / s, -48.0f / s, 0.0f / s);

	glEnd();

	// lankini Green Part
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.545f, 0.624f, 0.227f);
	glVertex3f(-8.0f / s, -25.0f / s, 0.0f / s);
	glVertex3f(12.0f / s, 2.0f / s, 0.0f / s);
	glVertex3f(9.0f / s, -0.0f / s, 0.0f / s);
	glVertex3f(4.0f / s, -4.0f / s, 0.0f / s);
	glVertex3f(-1.0f / s, -6.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, -7.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, -6.0f / s, 0.0f / s);
	glVertex3f(-26.0f / s, -3.0f / s, 0.0f / s);
	glVertex3f(-32.0f / s, 2.0f / s, 0.0f / s);
	glVertex3f(-38.0f / s, -18.0f / s, 0.0f / s);
	glVertex3f(-42.0f / s, -45.0f / s, 0.0f / s);
	glVertex3f(-35.0f / s, -47.0f / s, 0.0f / s);
	glVertex3f(-28.0f / s, -51.0f / s, 0.0f / s);
	glVertex3f(-21.0f / s, -52.0f / s, 0.0f / s);
	glVertex3f(-14.0f / s, -51.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, -52.0f / s, 0.0f / s);
	glVertex3f(-1.0f / s, -50.0f / s, 0.0f / s);
	glVertex3f(4.0f / s, -48.0f / s, 0.0f / s);
	glVertex3f(8.0f / s, -46.0f / s, 0.0f / s);
	glVertex3f(18.0f / s, -43.0f / s, 0.0f / s);
	glVertex3f(21.0f / s, -40.0f / s, 0.0f / s);
	glVertex3f(16.0f / s, -15.0f / s, 0.0f / s);
	glVertex3f(12.0f / s, 2.0f / s, 0.0f / s);

	glEnd();

	// Lankini Mideal Part

	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.651f, 0.647f, 0.824f);
	glVertex3f(-9.0f / s, 34.0f / s, 0.0f / s);
	glVertex3f(-20.0f / s, 48.0f / s, 0.0f / s);
	glVertex3f(-25.0f / s, 42.0f / s, 0.0f / s);
	glVertex3f(-30.0f / s, 41.0f / s, 0.0f / s);
	glVertex3f(-27.0f / s, 33.0f / s, 0.0f / s);
	glVertex3f(-26.0f / s, 29.0f / s, 0.0f / s);
	glVertex3f(-26.0f / s, 26.0f / s, 0.0f / s);
	glVertex3f(-26.0f / s, 21.0f / s, 0.0f / s);
	glVertex3f(-27.0f / s, 17.0f / s, 0.0f / s);
	glVertex3f(-28.0f / s, 14.0f / s, 0.0f / s);
	glVertex3f(-29.0f / s, 12.0f / s, 0.0f / s);
	glVertex3f(-30.0f / s, 9.0f / s, 0.0f / s);
	glVertex3f(-29.0f / s, 6.0f / s, 0.0f / s);
	glVertex3f(-27.0f / s, 4.0f / s, 0.0f / s);
	glVertex3f(-25.0f / s, 2.0f / s, 0.0f / s);
	glVertex3f(-22.0f / s, 1.0f / s, 0.0f / s);
	glVertex3f(-15.0f / s, 0.0f / s, 0.0f / s);
	glVertex3f(-5.0f / s, 3.0f / s, 0.0f / s);
	glVertex3f(5.0f / s, 2.0f / s, 0.0f / s);
	glVertex3f(8.0f / s, 5.0f / s, 0.0f / s);
	glVertex3f(10.0f / s, 9.0f / s, 0.0f / s);
	glVertex3f(10.0f / s, 12.0f / s, 0.0f / s);
	glVertex3f(9.0f / s, 15.0f / s, 0.0f / s);
	glVertex3f(8.0f / s, 19.0f / s, 0.0f / s);
	glVertex3f(8.0f / s, 23.0f / s, 0.0f / s);
	glVertex3f(5.0f / s, 30.0f / s, 0.0f / s);
	glVertex3f(2.0f / s, 37.0f / s, 0.0f / s);
	glVertex3f(1.0f / s, 41.0f / s, 0.0f / s);
	glVertex3f(0.0f / s, 44.0f / s, 0.0f / s);
	glVertex3f(-3.0f / s, 46.0f / s, 0.0f / s);
	glVertex3f(-5.0f / s, 49.0f / s, 0.0f / s);

	glEnd();


	// Lankini Right Hand

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.651f, 0.647f, 0.824f);
	glVertex3f(-27.0f / s, 33.0f / s, 0.0f / s);
	glVertex3f(-30.0f / s, 41.0f / s, 0.0f / s);
	glVertex3f(-28.0f / s, 30.0f / s, 0.0f / s);
	glVertex3f(-35.0f / s, 39.0f / s, 0.0f / s);
	glVertex3f(-29.0f / s, 26.0f / s, 0.0f / s);
	glVertex3f(-37.0f / s, 35.0f / s, 0.0f / s);
	glVertex3f(-30.0f / s, 22.0f / s, 0.0f / s);
	glVertex3f(-40.0f / s, 27.0f / s, 0.0f / s);
	glVertex3f(-32.0f / s, 17.0f / s, 0.0f / s);
	glVertex3f(-42.0f / s, 21.0f / s, 0.0f / s);
	glVertex3f(-34.0f / s, 14.0f / s, 0.0f / s);
	glVertex3f(-42.0f / s, 17.0f / s, 0.0f / s);
	glVertex3f(-34.0f / s, 9.0f / s, 0.0f / s);
	glVertex3f(-44.0f / s, 14.0f / s, 0.0f / s);
	glVertex3f(-35.0f / s, 5.0f / s, 0.0f / s);
	glVertex3f(-45.0f / s, 10.0f / s, 0.0f / s);
	glVertex3f(-36.0f / s, 2.0f / s, 0.0f / s);
	glVertex3f(-45.0f / s, 6.0f / s, 0.0f / s);
	glVertex3f(-37.0f / s, -2.0f / s, 0.0f / s);
	glVertex3f(-43.0f / s, -2.0f / s, 0.0f / s);

	glEnd();

	//mangat
	glBegin(GL_QUADS);

	glColor3f(0.792f, 0.663f, 0.071f);
	glVertex3f(-37.0f / s, -2.0f / s, 0.0f / s);
	glVertex3f(-36.0f / s, -8.0f / s, 0.0f / s);
	glVertex3f(-41.0f / s, -7.0f / s, 0.0f / s);
	glVertex3f(-43.0f / s, -2.0f / s, 0.0f / s);

	glEnd();

	//fingers
	glBegin(GL_POLYGON);
	glColor3f(0.651f, 0.647f, 0.824f);
	glVertex3f(-36.0f / s, -8.0f / s, 0.0f / s);
	glVertex3f(-36.0f / s, -17.0f / s, 0.0f / s);
	glVertex3f(-38.0f / s, -13.0f / s, 0.0f / s);
	glVertex3f(-43.0f / s, -14.0f / s, 0.0f / s);
	glVertex3f(-41.0f / s, -7.0f / s, 0.0f / s);

	glEnd();
	// Lankini Left Hand

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.651f, 0.647f, 0.824f);
	glVertex3f(-3.0f / s, 46.0f / s, 0.0f / s);
	glVertex3f(-0.0f / s, 44.0f / s, 0.0f / s);
	glVertex3f(1.0f / s, 47.0f / s, 0.0f / s);
	glVertex3f(2.0f / s, 37.0f / s, 0.0f / s);
	glVertex3f(10.0f / s, 42.0f / s, 0.0f / s);
	glVertex3f(3.0f / s, 33.0f / s, 0.0f / s);
	glVertex3f(15.0f / s, 38.0f / s, 0.0f / s);
	glVertex3f(8.0f / s, 30.0f / s, 0.0f / s);
	glVertex3f(23.0f / s, 38.0f / s, 0.0f / s);
	glVertex3f(13.0f / s, 26.0f / s, 0.0f / s);
	glVertex3f(25.0f / s, 29.0f / s, 0.0f / s);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.792f, 0.663f, 0.071f);
	glVertex3f(23.0f / s, 38.0f / s, 0.0f / s);
	glVertex3f(28.0f / s, 38.0f / s, 0.0f / s);
	glVertex3f(29.0f / s, 30.0f / s, 0.0f / s);
	glVertex3f(25.0f / s, 29.0f / s, 0.0f / s);
	glEnd();

	//fingers
	/*glLoadIdentity();
	glRotatef(-talvar_rotate*0.5f, 0.0f, 0.0f, 1.0f);
	glTranslatef(-0.10f / s, 2.0f / s, -3.0f);*/

	glBegin(GL_POLYGON);

	glColor3f(0.651f, 0.647f, 0.824f);
	glVertex3f(28.0f / s, 38.0f / s, 0.0f / s);
	glVertex3f(41.0f / s, 46.0f / s, 0.0f / s);
	glVertex3f(37.0f / s, 40.0f / s, 0.0f / s);
	glVertex3f(40.0f / s, 40.0f / s, 0.0f / s);
	glVertex3f(29.0f / s, 30.0f / s, 0.0f / s);

	glEnd();
	/*glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);*/
	//green part of chest
	glBegin(GL_POLYGON);
	glColor3f(0.545f, 0.624f, 0.227f);

	glVertex3f(3.0f / s, 33.0f / s, 0.0f / s);
	glVertex3f(-26.0f / s, 29.0f / s, 0.0f / s);
	glVertex3f(-28.0f / s, 14.0f / s, 0.0f / s);
	glVertex3f(8.0f / s, 19.0f / s, 0.0f / s);
	glVertex3f(9.0f / s, 27.0f / s, 0.0f / s);

	glEnd();

	//neck 
	glBegin(GL_POLYGON);
	glColor3f(0.651f, 0.647f, 0.824f);

	glVertex3f(-20.0f / s, 48.0f / s, 0.0f / s);
	glVertex3f(-19.0f / s, 43.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, 40.0f / s, 0.0f / s);
	glVertex3f(-4.0f / s, 44.0f / s, 0.0f / s);
	glVertex3f(-2.0f / s, 47.0f / s, 0.0f / s);
	glVertex3f(-5.0f / s, 49.0f / s, 0.0f / s);
	glVertex3f(-20.0f / s, 48.0f / s, 0.0f / s);

	glEnd();

	// Lankini Gold Chain

	glBegin(GL_TRIANGLES);
	glColor3f(0.792f, 0.663f, 0.071f);
	glVertex3f(-5.0f / s, 49.0f / s, 0.0f / s);
	glVertex3f(-4.0f / s, 44.0f / s, 0.0f / s);
	glVertex3f(-2.0f / s, 47.0f / s, 0.0f / s);
	glVertex3f(-20.0f / s, 48.0f / s, 0.0f / s);
	glVertex3f(-23.0f / s, 39.0f / s, 0.0f / s);
	glVertex3f(-19.0f / s, 43.0f / s, 0.0f / s);

	glEnd();


	// golden part of stomach

	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.792f, 0.663f, 0.071f);
	glVertex3f(10.0f / s, 12.0f / s, 0.0f / s);
	glVertex3f(13.0f / s, 5.0f / s, 0.0f / s);
	glVertex3f(10.0f / s, 9.0f / s, 0.0f / s);
	glVertex3f(12.0f / s, 2.0f / s, 0.0f / s);
	glVertex3f(8.0f / s, 5.0f / s, 0.0f / s);
	glVertex3f(9.0f / s, 0.0f / s, 0.0f / s);
	glVertex3f(5.0f / s, 2.0f / s, 0.0f / s);
	glVertex3f(4.0f / s, -4.0f / s, 0.0f / s);
	glVertex3f(-5.0f / s, 3.0f / s, 0.0f / s);
	glVertex3f(-1.0f / s, -6.0f / s, 0.0f / s);
	glVertex3f(-15.0f / s, 0.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, -7.0f / s, 0.0f / s);
	glVertex3f(-22.0f / s, 1.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, -6.0f / s, 0.0f / s);
	glVertex3f(-25.0f / s, 2.0f / s, 0.0f / s);
	glVertex3f(-26.0f / s, -3.0f / s, 0.0f / s);
	glVertex3f(-29.0f / s, 6.0f / s, 0.0f / s);
	glVertex3f(-32.0f / s, 2.0f / s, 0.0f / s);
	glVertex3f(-30.0f / s, 9.0f / s, 0.0f / s);

	glEnd();
	// Lankini Gold Chain
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.792f, 0.663f, 0.071f);
	glVertex3f(-8.0f / s, 30.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, 40.0f / s, 0.0f / s);
	glVertex3f(-4.0f / s, 44.0f / s, 0.0f / s);
	glVertex3f(-2.0f / s, 47.0f / s, 0.0f / s);
	glVertex3f(1.0f / s, 41.0f / s, 0.0f / s);
	glVertex3f(3.0f / s, 35.0f / s, 0.0f / s);
	glVertex3f(1.0f / s, 26.0f / s, 0.0f / s);
	glVertex3f(-1.0f / s, 19.0f / s, 0.0f / s);
	glVertex3f(-4.0f / s, 13.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 16.0f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 20.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, 26.0f / s, 0.0f / s);
	glVertex3f(-22.0f / s, 33.0f / s, 0.0f / s);
	glVertex3f(-23.0f / s, 39.0f / s, 0.0f / s);
	glVertex3f(-19.0f / s, 43.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, 40.0f / s, 0.0f / s);

	glEnd();

	//talvaar
	glLoadIdentity();
	glTranslatef(ab_Xtranslate, ab_Ytranslate, -3.0f);
	glScalef(ab_Xscale, ab_Yscale, 1.0f);
	glRotatef(talvar_rotate, 0.0f, 0.0f, 1.0f);
	glRotatef(ab_xRotate, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.996f, 0.996f, 0.996f);

	glVertex3f(-64.0f / s, 16.0f / s, 0.0f / s);
	glVertex3f(-54.0f / s, 16.0f / s, 0.0f / s);
	glVertex3f(-50.0f / s, 27.0f / s, 0.0f / s);
	glVertex3f(-46.0f / s, 37.0f / s, 0.0f / s);
	glVertex3f(-61.0f / s, 39.0f / s, 0.0f / s);
	glVertex3f(-71.0f / s, 30.0f / s, 0.0f / s);
	glVertex3f(-73.0f / s, 14.0f / s, 0.0f / s);
	glVertex3f(-50.0f / s, -10.0f / s, 0.0f / s);
	glVertex3f(-47.0f / s, -1.0f / s, 0.0f / s);
	glVertex3f(-54.0f / s, 16.0f / s, 0.0f / s);
	glEnd();

	//talvar handle
	glBegin(GL_POLYGON);

	glColor3f(0.792f, 0.663f, 0.071f);

	glVertex3f(-43.0f / s, -2.0f / s, 0.0f / s);
	glVertex3f(-49.0f / s, -2.0f / s, 0.0f / s);
	glVertex3f(-50.0f / s, -10.0f / s, 0.0f / s);
	glVertex3f(-43.0f / s, -14.0f / s, 0.0f / s);
	glVertex3f(-41.0f / s, -7.0f / s, 0.0f / s);
	glVertex3f(-43.0f / s, -2.0f / s, 0.0f / s);

	glEnd();
	glLoadIdentity();
	glTranslatef(ab_Xtranslate, ab_Ytranslate, -3.0f);
	glScalef(ab_Xscale, ab_Yscale, 1.0f);
	glRotatef(ab_xRotate, 0.0f, 0.0f, 1.0f);
	//face
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.7f, 0.7f, 0.9f);

	glVertex3f(-11.0f / s, 60.0f / s, 0.0f / s);
	glVertex3f(-4.0f / s, 62.0f / s, 0.0f / s);
	glVertex3f(-6.0f / s, 68.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 71.0f / s, 0.0f / s);
	glVertex3f(-14.0f / s, 70.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, 70.0f / s, 0.0f / s);
	glVertex3f(-19.0f / s, 67.0f / s, 0.0f / s);
	glVertex3f(-23.0f / s, 63.0f / s, 0.0f / s);
	glVertex3f(-22.0f / s, 58.0f / s, 0.0f / s);
	glVertex3f(-22.0f / s, 54.0f / s, 0.0f / s);
	glVertex3f(-20.0f / s, 48.0f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 47.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 48.0f / s, 0.0f / s);
	glVertex3f(-5.0f / s, 51.0f / s, 0.0f / s);
	//glVertex3f(-2.0f / s, 47.0f / s, 0.0f / s);
	glVertex3f(-3.0f / s, 57.0f / s, 0.0f / s);
	glVertex3f(-4.0f / s, 62.0f / s, 0.0f / s);
	glEnd();

	//left eyebrow
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.176f, 0.173f, 0.29f);

	glVertex3f(-15.0f / s, 62.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, 65.0f / s, 0.0f / s);
	glVertex3f(-21.0f / s, 64.0f / s, 0.0f / s);
	glVertex3f(-20.0f / s, 63.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, 64.0f / s, 0.0f / s);

	glEnd();

	////left eye white part
	glBegin(GL_QUADS);

	glColor3f(0.851f, 0.816f, 0.827f);

	glVertex3f(-14.0f / s, 60.0f / s, 0.0f / s);
	glVertex3f(-16.0f / s, 62.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, 61.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, 60.0f / s, 0.0f / s);

	glEnd();

	//// left eye black
	glPointSize(2);
	glBegin(GL_POINTS);

	glColor3f(0.176f, 0.173f, 0.29f);

	glVertex3f(-16.0f / s, 61.0f / s, 0.0f / s);

	glEnd();

	//right eyebrow
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.176f, 0.173f, 0.29f);

	glVertex3f(-11.0f / s, 65.0f / s, 0.0f / s);
	glVertex3f(-10.0f / s, 65.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, 67.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 68.0f / s, 0.0f / s);
	glVertex3f(-10.0f / s, 67.0f / s, 0.0f / s);
	glVertex3f(-11.0f / s, 65.0f / s, 0.0f / s);
	glEnd();

	//right eye white part
	glBegin(GL_QUADS);

	glColor3f(0.851f, 0.816f, 0.827f);

	glVertex3f(-9.0f / s, 62.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, 64.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 65.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 63.0f / s, 0.0f / s);

	glEnd();

	// left eye black
	glPointSize(2);
	glBegin(GL_POINTS);

	glColor3f(0.176f, 0.173f, 0.29f);

	glVertex3f(-8.0f / s, 63.0f / s, 0.0f / s);

	glEnd();

	//mouth
	glBegin(GL_POLYGON);

	glColor3f(0.471f, 0.173f, 0.173f);

	glVertex3f(-12.0f / s, 55.0f / s, 0.0f / s);
	glVertex3f(-12.0f / s, 52.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, 52.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 53.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 57.0f / s, 0.0f / s);
	glVertex3f(-9.0f / s, 56.0f / s, 0.0f / s);
	glVertex3f(-12.0f / s, 55.0f / s, 0.0f / s);

	glEnd();

	//teeth 1
	glBegin(GL_TRIANGLES);

	glColor3f(0.839f, 0.737f, 0.769f);

	glVertex3f(-12.0f / s, 53.0f / s, 0.0f / s);
	glVertex3f(-11.0f / s, 55.0f / s, 0.0f / s);
	glVertex3f(-12.0f / s, 55.0f / s, 0.0f / s);

	glEnd();

	//teeth 2
	glBegin(GL_TRIANGLES);

	glColor3f(0.839f, 0.737f, 0.769f);

	glVertex3f(-7.0f / s, 54.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 56.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 55.0f / s, 0.0f / s);

	glEnd();

	//jiib
	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 0.0f);

	glVertex3f(-6.0f / s, 52.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 54.0f / s, 0.0f / s);
	glVertex3f(-12.0f / s, 53.0f / s, 0.0f / s);
	glVertex3f(-10.0f / s, 51.0f / s, 0.0f / s);

	glEnd();
}

void draw_shadowHanuman(void) {
	glLoadIdentity();
	glTranslatef(h_translate, s_translate, -3.0f);
	glScalef(xShadow, yShadow, zShadow);
	glRotatef(180.0, 0.0f, 0.0f, 1.0f);
	glRotatef(180.0, 1.0f, 0.0f, 0.0f);
	if (h_translate >= -0.35f) {//-0.5 prynt yeun thambnar {

		h_translate -= 0.0012f;
	}
	else if (h_translate == 1.0f && xShadow >= 0.0f) {
		xShadow -= 0.05f;
		yShadow -= 0.05f;
		zShadow -= 0.05f;
	}
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3f(-39.08 / s, -5.52 / s, 0.0f);
	glVertex3f(-43.2 / s, -1.7 / s, 0.0f);
	glVertex3f(-49.52 / s, -5.19 / s, 0.0f);
	glVertex3f(-64.06 / s, -6.03 / s, 0.0f);
	glVertex3f(-82.814 / s, -7.26 / s, 0.0f);
	glVertex3f(-93.9 / s, -9.48 / s, 0.0f);
	glVertex3f(-94.28 / s, -1.27 / s, 0.0f);
	glVertex3f(-85.331 / s, -0.71 / s, 0.0f);
	glVertex3f(-69.94 / s, 0.12 / s, 0.0f);
	glVertex3f(-54.8 / s, 4.03 / s, 0.0f);
	glVertex3f(-45.2 / s, 4.41 / s, 0.0f);
	glVertex3f(-35.25 / s, 5.15 / s, 0.0f);
	//glVertex3f(-43.2 / s, -1.71 / s, 0.0f);
	glEnd();

	//lower leg
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-40.8 / s, -19.4 / s, 0.0f);
	glVertex3f(-50.07 / s, -22.2 / s, 0.0f);
	glVertex3f(-71.9 / s, -21.4 / s, 0.0f);
	glVertex3f(-88.9 / s, -18.9 / s, 0.0f);
	glVertex3f(-88.4 / s, -14.7 / s, 0.0f);
	glVertex3f(-78.05 / s, -14.14 / s, 0.0f);
	glVertex3f(-63.2 / s, -16.3 / s, 0.0f);
	glVertex3f(-50.9 / s, -13.028 / s, 0.0f);
	glVertex3f(-41.9 / s, -11.07 / s, 0.0f);
	glVertex3f(-39.06 / s, -5.52 / s, 0.0f);
	glEnd();

	//middle part
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-35.25 / s, 5.157 / s, 0.0f);
	glVertex3f(-39.067 / s, -5.52 / s, 0.0f);
	glVertex3f(-40.821 / s, -19.464 / s, 0.0f);
	glVertex3f(-28.25 / s, -19.18 / s, 0.0f);
	glVertex3f(-5.29 / s, -15.26 / s, 0.0f);
	glVertex3f(12.03 / s, -16.66 / s, 0.0f);
	glVertex3f(12.8 / s, -2.5 / s, 0.0f);
	glVertex3f(12.87 / s, 13.83 / s, 0.0f);
	glVertex3f(0.559 / s, 8.51 / s, 0.0f);
	glVertex3f(-10.9 / s, 5.15 / s, 0.0f);
	glVertex3f(-17.9 / s, 6.30 / s, 0.0f);
	glVertex3f(-24.62 / s, 7.11 / s, 0.0f);
	glVertex3f(-35.25 / s, 5.15 / s, 0.0f);
	glVertex3f(-45.2 / s, 4.41 / s, 0.0f);
	glEnd();

	//tail
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-24.62 / s, 7.11 / s, 0.0f);
	glVertex3f(-23.9 / s, 15.9 / s, 0.0f);
	glVertex3f(-30.7 / s, 19.4 / s, 0.0f);
	glVertex3f(-43.6 / s, 16.9 / s, 0.0f);
	glVertex3f(-32.4 / s, 11.312 / s, 0.0f);
	glVertex3f(-35.25 / s, 5.15 / s, 0.0f);

	glEnd();

	//upper gada part
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(12.87 / s, 13.83 / s, 0.0f);
	glVertex3f(26.98 / s, 12.30 / s, 0.0f);
	glVertex3f(37.288 / s, 8.48 / s, 0.0f);
	glVertex3f(47.8 / s, 7.9 / s, 0.0f);
	glVertex3f(58.7 / s, 16.34 / s, 0.0f);
	glVertex3f(48.96 / s, 16.90 / s, 0.0f);
	glVertex3f(39.4 / s, 22.7 / s, 0.0f);
	glVertex3f(28.8 / s, 25.58 / s, 0.0f);
	glVertex3f(19.30 / s, 23.062 / s, 0.0f);

	glEnd();

	//Hanumanright Handmiddle part

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(12.03 / s, -16.665 / s, 0.0f);
	glVertex3f(12.87 / s, -2.57 / s, 0.0f);
	glVertex3f(12.87 / s, 13.83 / s, 0.0f);
	glVertex3f(26.98 / s, 12.30 / s, 0.0f);
	glVertex3f(37.28 / s, 8.48 / s, 0.0f);
	glVertex3f(47.8 / s, 7.95 / s, 0.0f);
	glVertex3f(53.71 / s, 3.75 / s, 0.0f);
	glVertex3f(59.05 / s, 1.46 / s, 0.0f);
	glVertex3f(55.39 / s, -3.79 / s, 0.0f);
	glVertex3f(47.002 / s, -7.71 / s, 0.0f);
	glVertex3f(29.58 / s, -10.17 / s, 0.0f);
	glVertex3f(12.03 / s, -16.6 / s, 0.0f);

	glEnd();

	//Hanuman right hand shadow
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(12.03 / s, -16.665 / s, 0.0f);
	glVertex3f(36.37 / s, -18.9 / s, 0.0f);
	glVertex3f(55.95 / s, -16.6 / s, 0.0f);
	glVertex3f(85.05 / s, -10.51 / s, 0.0f);
	glVertex3f(91.15 / s, -7.83 / s, 0.0f);
	glVertex3f(87.00 / s, -4.07 / s, 0.0f);
	glVertex3f(75.25 / s, -5.47 / s, 0.0f);
	glVertex3f(61.83 / s, -7.99 / s, 0.0f);
	glVertex3f(47.002 / s, -7.71 / s, 0.0f);
	glVertex3f(29.58 / s, -10.17 / s, 0.0f);
	glVertex3f(12.03 / s, -16.66 / s, 0.0f);

	glEnd();


}

void resetVariables(void) {
	xHanuman = 350.0f;
	yHanuman = 70.0f;
	zHanuman = -3.0f;
	rHead = 0.0f;
	rHanuman = 90.0f;
	bHead = FALSE;
	rTail = 0.0f;
	bTail = FALSE;
	bHanumanRotate = TRUE;
	rotate_left_leg = 5.0f;
	rotate_right_leg = 0.0f;
	bRotateLeg = FALSE;
	xScaleHanuman = 0.4f;
	yScaleHanuman = 0.4f;
	zScaleHanuman = 0.4f;
	sHanuman = TRUE;
	bHanuman = FALSE;
	xrHauman = 0.0f;
	yrHauman = 0.0f;
	zrHauman = 1.0f;
	s = 100.0f;
}

void sp_draw_shadowHanuman(void)
{
	//For Shadow
	if (shadow_y_translate <= 0.5f && shadow_y_scale >= 0.0f)
	{
		shadow_y_translate += 0.021 / 2.0f;
		shadow_y_scale -= 0.0097f / 2.0f;
	}

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	glTranslatef(0.0f, shadow_y_translate, shadow_z_translate);
	glScalef(shadow_x_scale, shadow_y_scale, 0.0f);

	glRotatef(90.0f, 0.0f, 0.0f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3f(-39.08 / s, -5.52 / s, 0.0f);
	glVertex3f(-43.2 / s, -1.7 / s, 0.0f);
	glVertex3f(-49.52 / s, -5.19 / s, 0.0f);
	glVertex3f(-64.06 / s, -6.03 / s, 0.0f);
	glVertex3f(-82.814 / s, -7.26 / s, 0.0f);
	glVertex3f(-93.9 / s, -9.48 / s, 0.0f);
	glVertex3f(-94.28 / s, -1.27 / s, 0.0f);
	glVertex3f(-85.331 / s, -0.71 / s, 0.0f);
	glVertex3f(-69.94 / s, 0.12 / s, 0.0f);
	glVertex3f(-54.8 / s, 4.03 / s, 0.0f);
	glVertex3f(-45.2 / s, 4.41 / s, 0.0f);
	glVertex3f(-35.25 / s, 5.15 / s, 0.0f);
	//glVertex3f(-43.2 / s, -1.71 / s, 0.0f);
	glEnd();

	//lower leg
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-40.8 / s, -19.4 / s, 0.0f);
	glVertex3f(-50.07 / s, -22.2 / s, 0.0f);
	glVertex3f(-71.9 / s, -21.4 / s, 0.0f);
	glVertex3f(-88.9 / s, -18.9 / s, 0.0f);
	glVertex3f(-88.4 / s, -14.7 / s, 0.0f);
	glVertex3f(-78.05 / s, -14.14 / s, 0.0f);
	glVertex3f(-63.2 / s, -16.3 / s, 0.0f);
	glVertex3f(-50.9 / s, -13.028 / s, 0.0f);
	glVertex3f(-41.9 / s, -11.07 / s, 0.0f);
	glVertex3f(-39.06 / s, -5.52 / s, 0.0f);
	glEnd();

	//middle part
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-35.25 / s, 5.157 / s, 0.0f);
	glVertex3f(-39.067 / s, -5.52 / s, 0.0f);
	glVertex3f(-40.821 / s, -19.464 / s, 0.0f);
	glVertex3f(-28.25 / s, -19.18 / s, 0.0f);
	glVertex3f(-5.29 / s, -15.26 / s, 0.0f);
	glVertex3f(12.03 / s, -16.66 / s, 0.0f);
	glVertex3f(12.8 / s, -2.5 / s, 0.0f);
	glVertex3f(12.87 / s, 13.83 / s, 0.0f);
	glVertex3f(0.559 / s, 8.51 / s, 0.0f);
	glVertex3f(-10.9 / s, 5.15 / s, 0.0f);
	glVertex3f(-17.9 / s, 6.30 / s, 0.0f);
	glVertex3f(-24.62 / s, 7.11 / s, 0.0f);
	glVertex3f(-35.25 / s, 5.15 / s, 0.0f);
	glVertex3f(-45.2 / s, 4.41 / s, 0.0f);
	glEnd();

	//tail
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-24.62 / s, 7.11 / s, 0.0f);
	glVertex3f(-23.9 / s, 15.9 / s, 0.0f);
	glVertex3f(-30.7 / s, 19.4 / s, 0.0f);
	glVertex3f(-43.6 / s, 16.9 / s, 0.0f);
	glVertex3f(-32.4 / s, 11.312 / s, 0.0f);
	glVertex3f(-35.25 / s, 5.15 / s, 0.0f);

	glEnd();

	//upper gada part
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(12.87 / s, 13.83 / s, 0.0f);
	glVertex3f(26.98 / s, 12.30 / s, 0.0f);
	glVertex3f(37.288 / s, 8.48 / s, 0.0f);
	glVertex3f(47.8 / s, 7.9 / s, 0.0f);
	glVertex3f(58.7 / s, 16.34 / s, 0.0f);
	glVertex3f(48.96 / s, 16.90 / s, 0.0f);
	glVertex3f(39.4 / s, 22.7 / s, 0.0f);
	glVertex3f(28.8 / s, 25.58 / s, 0.0f);
	glVertex3f(19.30 / s, 23.062 / s, 0.0f);

	glEnd();

	//Hanumanright Handmiddle part

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(12.03 / s, -16.665 / s, 0.0f);
	glVertex3f(12.87 / s, -2.57 / s, 0.0f);
	glVertex3f(12.87 / s, 13.83 / s, 0.0f);
	glVertex3f(26.98 / s, 12.30 / s, 0.0f);
	glVertex3f(37.28 / s, 8.48 / s, 0.0f);
	glVertex3f(47.8 / s, 7.95 / s, 0.0f);
	glVertex3f(53.71 / s, 3.75 / s, 0.0f);
	glVertex3f(59.05 / s, 1.46 / s, 0.0f);
	glVertex3f(55.39 / s, -3.79 / s, 0.0f);
	glVertex3f(47.002 / s, -7.71 / s, 0.0f);
	glVertex3f(29.58 / s, -10.17 / s, 0.0f);
	glVertex3f(12.03 / s, -16.6 / s, 0.0f);

	glEnd();

	//Hanuman right hand shadow
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(12.03 / s, -16.665 / s, 0.0f);
	glVertex3f(36.37 / s, -18.9 / s, 0.0f);
	glVertex3f(55.95 / s, -16.6 / s, 0.0f);
	glVertex3f(85.05 / s, -10.51 / s, 0.0f);
	glVertex3f(91.15 / s, -7.83 / s, 0.0f);
	glVertex3f(87.00 / s, -4.07 / s, 0.0f);
	glVertex3f(75.25 / s, -5.47 / s, 0.0f);
	glVertex3f(61.83 / s, -7.99 / s, 0.0f);
	glVertex3f(47.002 / s, -7.71 / s, 0.0f);
	glVertex3f(29.58 / s, -10.17 / s, 0.0f);
	glVertex3f(12.03 / s, -16.66 / s, 0.0f);

	glEnd();


}

void draw_hanumanji_back(void)
{
	// torso //
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.454f, 0.239f, 0.168f);
	glVertex3f(-0.372f / s, 4.68f / s, 0.0f);
	glVertex3f(-6.7f / s, 0.54f / s, 0.0f);
	glVertex3f(-12.48f / s, -2.2f / s, 0.0f);
	glVertex3f(-11.55f / s, -12.04f / s, 0.0f);
	glVertex3f(-9.9f / s, -20.3f / s, 0.0f);
	glVertex3f(-9.3f / s, -27.7f / s, 0.0f);
	glVertex3f(10.09f / s, -27.12f / s, 0.0f);
	glVertex3f(10.63f / s, -19.8f / s, 0.0f);
	glVertex3f(13.14f / s, -12.54f / s, 0.0f);
	glVertex3f(14.44f / s, -2.48f / s, 0.0f);
	glVertex3f(5.91f / s, 1.19f / s, 0.0f);
	glVertex3f(-0.37f / s, 4.68f / s, 0.0f);
	glEnd();

	//hair
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.372f / s, 4.68f / s, 0.0f);
	glVertex3f(-5.6f / s, 7.4f / s, 0.0f);
	glVertex3f(-6.1f / s, 4.62f / s, 0.0f);
	glVertex3f(-8.03f / s, 2.07f / s, 0.0f);
	glVertex3f(-6.75f / s, 0.54f / s, 0.0f);
	glVertex3f(-2.7f / s, 2.4f / s, 0.0f);
	glVertex3f(-0.07f / s, 1.33f / s, 0.0f);
	glVertex3f(3.8f / s, 2.25f / s, 0.0f);
	glVertex3f(7.5f / s, 1.44f / s, 0.0f);
	glVertex3f(5.6f / s, 3.3f / s, 0.0f);
	glVertex3f(5.4f / s, 6.55f / s, 0.0f);
	glVertex3f(-5.6f / s, 7.4f / s, 0.0f);
	glEnd();

	//mukut
	glBegin(GL_TRIANGLES);
	glColor3f(0.988, 0.761, 0.012);
	glVertex3f(-5.6f / s, 7.4f / s, 0.0f);
	glVertex3f(5.6f / s, 7.4f / s, 0.0f);
	glVertex3f(-0.06f / s, 18.02f / s, 0.0f);
	glEnd();

	//left hand
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.454f, 0.239f, 0.168f);
	glVertex3f(-12.48f / s, -2.2f / s, 0.0f);
	glVertex3f(-17.7f / s, -9.92f / s, 0.0f);
	glVertex3f(-19.5f / s, -13.7f / s, 0.0f);
	glVertex3f(-19.5f / s, -21.52f / s, 0.0f);
	glVertex3f(-22.69f / s, -31.3f / s, 0.0f);
	glVertex3f(-15.9f / s, -31.27f / s, 0.0f);
	glVertex3f(-14.4f / s, -25.2f / s, 0.0f);
	glVertex3f(-13.3f / s, -20.5f / s, 0.0f);
	glVertex3f(-11.5f / s, -12.04f / s, 0.0f);
	glVertex3f(-12.48f / s, -2.2f / s, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.454f, 0.239f, 0.168f);
	glVertex3f(13.8f / s, -2.2f / s, 0.0f);
	glVertex3f(17.7f / s, -9.92f / s, 0.0f);
	glVertex3f(19.5f / s, -13.7f / s, 0.0f);
	glVertex3f(19.5f / s, -21.52f / s, 0.0f);
	glVertex3f(22.69f / s, -31.3f / s, 0.0f);
	glVertex3f(15.9f / s, -31.27f / s, 0.0f);
	glVertex3f(14.4f / s, -25.2f / s, 0.0f);
	glVertex3f(13.3f / s, -20.5f / s, 0.0f);
	glVertex3f(11.5f / s, -12.04f / s, 0.0f);
	glVertex3f(13.8f / s, -2.2f / s, 0.0f);
	glEnd();


	//kamarpatta
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.46f / s, -29.37f / s, 0.0f);
	glVertex3f(-9.3f / s, -27.7f / s, 0.0f);
	glVertex3f(-10.1f / s, -30.8f / s, 0.0f);
	glVertex3f(10.34f / s, -30.9f / s, 0.0f);
	glVertex3f(10.09f / s, -27.12f / s, 0.0f);
	glVertex3f(-9.3f / s, -27.7f / s, 0.0f);
	glEnd();

	//left hand
	glBegin(GL_QUADS);
	glColor3f(0.454f, 0.239f, 0.168f);
	glVertex3f(-22.6f / s, -41.5f / s, 0.0f);
	glVertex3f(-25.54f / s, -45.86f / s, 0.0f);
	glVertex3f(-18.7f / s, -46.56f / s, 0.0f);
	glVertex3f(-19.29f / s, -41.4f / s, 0.0f);

	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(0.454f, 0.239f, 0.168f);
	glVertex3f(22.6f / s, -41.5f / s, 0.0f);
	glVertex3f(25.54f / s, -45.86f / s, 0.0f);
	glVertex3f(18.7f / s, -46.56f / s, 0.0f);
	glVertex3f(19.29f / s, -41.4f / s, 0.0f);

	glEnd();

	//left forearm armour
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.84f, 0.0f);
	glVertex3f(-22.69f / s, -31.3f / s, 0.0f);
	glVertex3f(-22.61f / s, -41.59f / s, 0.0f);
	glVertex3f(-19.29f / s, -41.4f / s, 0.0f);
	glVertex3f(-15.9f / s, -31.27f / s, 0.0f);
	glEnd();


	//right forearm armour
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.84f, 0.0f);
	glVertex3f(22.69f / s, -31.3f / s, 0.0f);
	glVertex3f(22.61f / s, -41.59f / s, 0.0f);
	glVertex3f(19.29f / s, -41.4f / s, 0.0f);
	glVertex3f(15.9f / s, -31.27f / s, 0.0f);
	glEnd();

	//	glRotatef(90, 0.0f, 1.0, 0.0f);
	glScalef(0.9f, 0.9f, 0.0f);
	glTranslatef(0.0f, -0.2f, 0.0f);

	//small leg
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.454f, 0.239f, 0.168f);
	glVertex3f(-9.0f / s, -80.0f / s, 0.0f);
	glVertex3f(-4.0f / s, -82.0f / s, 0.0f);
	glVertex3f(-5.0f / s, -77.0f / s, 0.0f);
	glVertex3f(-1.0f / s, -49.0f / s, 0.0f);
	glVertex3f(0.0f / s, -30.0f / s, 0.0f);
	glVertex3f(-6.0f / s, -43.0f / s, 0.0f);
	glVertex3f(-11.0f / s, -43.0f / s, 0.0f);
	glVertex3f(-12.0f / s, -76.0f / s, 0.0f);



	//	glVertex3f(-18.0f / s, -78.0f / s, 0.0f);
	//	glVertex3f(-22.0f / s, -76.0f / s, 0.0f);
		//glVertex3f(-23.0f / s, -79.0f / s, 0.0f);
		//glVertex3f(-21.0f / s, -80.0f / s, 0.0f);
		//glVertex3f(-23.0f / s, -81.0f / s, 0.0f);
		//glVertex3f(-23.0f / s, -82.0f / s, 0.0f);
		//glVertex3f(-13.0f / s, -82.0f / s, 0.0f);
		//glVertex3f(-9.0f / s, -82.0f / s, 0.0f);
	glVertex3f(-4.0f / s, -82.0f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.454f, 0.239f, 0.168f);
	glVertex3f(9.0f / s, -80.0f / s, 0.0f);
	glVertex3f(4.0f / s, -82.0f / s, 0.0f);
	glVertex3f(5.0f / s, -77.0f / s, 0.0f);
	glVertex3f(1.0f / s, -49.0f / s, 0.0f);
	glVertex3f(0.0f / s, -30.0f / s, 0.0f);
	glVertex3f(6.0f / s, -43.0f / s, 0.0f);
	glVertex3f(11.0f / s, -43.0f / s, 0.0f);
	glVertex3f(12.0f / s, -76.0f / s, 0.0f);



	//	glVertex3f(-18.0f / s, -78.0f / s, 0.0f);
	//	glVertex3f(-22.0f / s, -76.0f / s, 0.0f);
		//glVertex3f(-23.0f / s, -79.0f / s, 0.0f);
		//glVertex3f(-21.0f / s, -80.0f / s, 0.0f);
		//glVertex3f(-23.0f / s, -81.0f / s, 0.0f);
		//glVertex3f(-23.0f / s, -82.0f / s, 0.0f);
		//glVertex3f(-13.0f / s, -82.0f / s, 0.0f);
		//glVertex3f(-9.0f / s, -82.0f / s, 0.0f);
	glVertex3f(4.0f / s, -82.0f / s, 0.0f);
	glEnd();

	//*************small leg (gold)**************
	glBegin(GL_POLYGON);
	glColor3f(0.988, 0.761, 0.012);
	glVertex3f(-4.0f / s, -73.0f / s, 0.0f);
	glVertex3f(-12.0f / s, -73.0f / s, 0.0f);
	glVertex3f(-12.0f / s, -75.0f / s, 0.0f);
	glVertex3f(-4.0f / s, -76.0f / s, 0.0f);
	glEnd();

	//*************small leg (gold)**************
	glBegin(GL_POLYGON);
	glColor3f(0.988, 0.761, 0.012);
	glVertex3f(4.0f / s, -73.0f / s, 0.0f);
	glVertex3f(12.0f / s, -73.0f / s, 0.0f);
	glVertex3f(12.0f / s, -75.0f / s, 0.0f);
	glVertex3f(4.0f / s, -76.0f / s, 0.0f);
	glEnd();

	//dhoti
	glLoadIdentity();
	glTranslatef(-0.6f, 0.0f, -3.0f);
	glScalef(0.7f, 0.7f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 0.6f, 0.2f);
	glVertex3f(-10.1f / s, -30.85f / s, 0.0f);
	glVertex3f(-12.89f / s, -37.08f / s, 0.0f);
	glVertex3f(-12.38f / s, -48.12f / s, 0.0f);
	glVertex3f(-10.87f / s, -60.2f / s, 0.0f);
	glVertex3f(10.16f / s, -61.41f / s, 0.0f);
	glVertex3f(11.57f / s, -49.9f / s, 0.0f);
	glVertex3f(12.18f / s, -37.35f / s, 0.0f);
	glVertex3f(10.34f / s, -30.98f / s, 0.0f);
	glVertex3f(-10.1f / s, -30.85f / s, 0.0f);
	glEnd();

	//************** Draw Tail 1st part ****************
	struct Circle tail01a;

	tail01a.size.point_size = 15 * 0.5f;
	tail01a.center.xCoordinate = 28.5f / s;
	tail01a.center.yCoordinate = -0.7f / s;
	tail01a.radius.xAxis = -16.0f / s;
	tail01a.radius.yAxis = -16.0f / s;
	tail01a.color.r = 0.698f;
	tail01a.color.g = 0.294;
	tail01a.color.b = 0.016;
	tail01a.angle.from = 30;
	tail01a.angle.to = 150;



	//************** Draw Tail 2nd part ****************
	struct Circle tail02a;

	tail02a.size.point_size = 15 * 0.5f;
	tail02a.center.xCoordinate = 50.5f / s;
	tail02a.center.yCoordinate = -27.5f / s;
	tail02a.radius.xAxis = -20.0f / s;
	tail02a.radius.yAxis = -20.0f / s;
	tail02a.color.r = 0.698f;
	tail02a.color.g = 0.294f;
	tail02a.color.b = 0.016f;
	tail02a.angle.from = 150;
	tail02a.angle.to = 300;

	glTranslatef(-0.1f, -0.32f, 0.0f);
	glScalef(0.7f, 0.7f, 0.7f);
	DrawCircle(GL_POINTS, tail01a);
	DrawCircle(GL_POINTS, tail02a);
	glBegin(GL_TRIANGLES);
	glColor3f(0.698f, 0.294f, 0.016f);
	glVertex3f(65.8f / s, -38.6f / s, 0.0f);
	glVertex3f(71.6f / s, -33.5f / s, 0.0f);
	glVertex3f(77.8f / s, -48.0f / s, 0.0f);
	glEnd();


}

void draw_palace(void)
{
	float D = 100.0f;
	void draw_ravana_palace11(void);
	void draw_ravana_palace(void);
	void draw_soldier(void);


	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	// Upper Black background Sky
	glBegin(GL_POLYGON);
	glColor3f(0.086, 0.098, 0.125);
	glVertex3f(250.0 / D, 250.0 / D, 0.0f / D);
	glColor3f(0.086, 0.098, 0.125);
	glVertex3f(-250.0 / D, 250.0 / D, 0.0f / D);
	glColor3f(0.231, 0.259, 0.282);
	glVertex3f(-250.0 / D, 125.0 / D, 0.0f / D);
	glColor3f(0.231, 0.259, 0.282);
	glVertex3f(250.0 / D, 125.0 / D, 0.0f / D);
	glEnd();

	//Lower Sky
	glBegin(GL_POLYGON);
	glColor3f(0.231, 0.259, 0.282);
	glVertex3f(250.0 / D, 125.0 / D, 0.0f / D);
	glColor3f(0.231, 0.259, 0.282);
	glVertex3f(-250.0 / D, 125.0 / D, 0.0f / D);
	glColor3f(0.684, 0.794, 0.841);
	glVertex3f(-250.0 / D, 40.0 / D, 0.0f / D);
	glColor3f(0.684, 0.794, 0.841);
	glVertex3f(250.0 / D, 40.0 / D, 0.0f / D);
	glEnd();

	//sun
	glLoadIdentity();
	glTranslatef(5.2f, 2.7f, -8.0f);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.992, 1., 0.525);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 20.0f / s;
		float y = sin(a) * 20.0f / s;

		glVertex3f(0.0f + x, 0.0f + y, 0.0f);
	}
	glEnd();

	//clouds 1
	glLoadIdentity();
	glTranslatef(x11Move * 0.3, 0.7827f, -8.0f);
	glScalef(4.5f, 4.5f, 4.5f);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.949, 0.945, 0.902);
	glVertex3f(-77.9159f / s, 38.207f / s, 0.0f);
	glVertex3f(-72.3219f / s, 37.2294f / s, 0.0f);
	glVertex3f(-75.309f / s, 37.0122f / s, 0.0f);
	glVertex3f(-79.5995f / s, 34.7311f / s, 0.0f);
	glVertex3f(-81.2932f / s, 34.5682f / s, 0.0f);
	glVertex3f(-82.8582f / s, 35.2199f / s, 0.0f);
	glVertex3f(-85.5738f / s, 34.5682f / s, 0.0f);
	glVertex3f(-87.366f / s, 35.1656f / s, 0.0f);
	glVertex3f(-88.8324f / s, 36.3061f / s, 0.0f);
	glVertex3f(-89.5928f / s, 38.0441f / s, 0.0f);
	glVertex3f(-89.2669f / s, 39.2932f / s, 0.0f);
	glVertex3f(-88.0178f / s, 40.7053f / s, 0.0f);
	glVertex3f(-86.1712f / s, 41.4657f / s, 0.0f);
	glVertex3f(-84.2703f / s, 41.8459f / s, 0.0f);
	glVertex3f(-83.7929f / s, 42.8349f / s, 0.0f);
	glVertex3f(-83.0212f / s, 43.5838f / s, 0.0f);
	glVertex3f(-82.0979f / s, 43.964f / s, 0.0f);
	glVertex3f(-81.0117f / s, 44.0183f / s, 0.0f);
	glVertex3f(-79.9254f / s, 43.6924f / s, 0.0f);
	glVertex3f(-78.7306f / s, 42.7148f / s, 0.0f);
	glVertex3f(-77.1012f / s, 41.0312f / s, 0.0f);
	glVertex3f(-75.8521f / s, 41.6286f / s, 0.0f);
	glVertex3f(-74.6572f / s, 42.2804f / s, 0.0f);
	glVertex3f(-73.4081f / s, 42.4976f / s, 0.0f);
	glVertex3f(-72.3219f / s, 42.0088f / s, 0.0f);
	glVertex3f(-71.8874f / s, 41.0312f / s, 0.0f);
	glVertex3f(-72.2132f / s, 38.9674f / s, 0.0f);
	glVertex3f(-66.1847f / s, 38.4243f / s, 0.0f);
	glVertex3f(-65.533f / s, 37.7182f / s, 0.0f);
	glVertex3f(-66.4019f / s, 37.1751f / s, 0.0f);
	glVertex3f(-66.4019f / s, 37.1751f / s, 0.0f);
	glVertex3f(-72.3219f / s, 37.2294f / s, 0.0f);
	glEnd();

	// clouds 2
	glLoadIdentity();
	glTranslatef(x11Move * 0.3, 0.18f, -5.0f);
	glScalef(5.5f, 4.5f, 4.5f);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.949, 0.945, 0.902);
	glVertex3f(-77.9159f / s, 38.207f / s, 0.0f);
	glVertex3f(-72.3219f / s, 37.2294f / s, 0.0f);
	glVertex3f(-75.309f / s, 37.0122f / s, 0.0f);
	glVertex3f(-79.5995f / s, 34.7311f / s, 0.0f);
	glVertex3f(-81.2932f / s, 34.5682f / s, 0.0f);
	glVertex3f(-82.8582f / s, 35.2199f / s, 0.0f);
	glVertex3f(-85.5738f / s, 34.5682f / s, 0.0f);
	glVertex3f(-87.366f / s, 35.1656f / s, 0.0f);
	glVertex3f(-88.8324f / s, 36.3061f / s, 0.0f);
	glVertex3f(-89.5928f / s, 38.0441f / s, 0.0f);
	glVertex3f(-89.2669f / s, 39.2932f / s, 0.0f);
	glVertex3f(-88.0178f / s, 40.7053f / s, 0.0f);
	glVertex3f(-86.1712f / s, 41.4657f / s, 0.0f);
	glVertex3f(-84.2703f / s, 41.8459f / s, 0.0f);
	glVertex3f(-83.7929f / s, 42.8349f / s, 0.0f);
	glVertex3f(-83.0212f / s, 43.5838f / s, 0.0f);
	glVertex3f(-82.0979f / s, 43.964f / s, 0.0f);
	glVertex3f(-81.0117f / s, 44.0183f / s, 0.0f);
	glVertex3f(-79.9254f / s, 43.6924f / s, 0.0f);
	glVertex3f(-78.7306f / s, 42.7148f / s, 0.0f);
	glVertex3f(-77.1012f / s, 41.0312f / s, 0.0f);
	glVertex3f(-75.8521f / s, 41.6286f / s, 0.0f);
	glVertex3f(-74.6572f / s, 42.2804f / s, 0.0f);
	glVertex3f(-73.4081f / s, 42.4976f / s, 0.0f);
	glVertex3f(-72.3219f / s, 42.0088f / s, 0.0f);
	glVertex3f(-71.8874f / s, 41.0312f / s, 0.0f);
	glVertex3f(-72.2132f / s, 38.9674f / s, 0.0f);
	glVertex3f(-66.1847f / s, 38.4243f / s, 0.0f);
	glVertex3f(-65.533f / s, 37.7182f / s, 0.0f);
	glVertex3f(-66.4019f / s, 37.1751f / s, 0.0f);
	glVertex3f(-66.4019f / s, 37.1751f / s, 0.0f);
	glVertex3f(-72.3219f / s, 37.2294f / s, 0.0f);
	glEnd();


	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	glBegin(GL_QUADS);
	glColor3f(0.22f, 0.5f, 0.02f);	//grass green
	glVertex3f(-0.3f, 0.40f, 0.0f);
	glVertex3f(0.7f, -1.5f, 0.0f);
	glVertex3f(5.0f, -1.5f, 0.0f);
	glVertex3f(5.0f, 0.40f, 0.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.941f, 0.901f, 0.549f);	//ground
	glVertex3f(-0.29f, 0.39f, 0.0f);
	glVertex3f(-5.0f, 0.39f, 0.0f);
	glVertex3f(-5.0f, -5.0f, 0.0f);
	glVertex3f(3.0f, -5.0f, 0.0f);
	glEnd();


	//
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	glTranslatef(-0.15f, 0.3f, 0.0f);
	glScalef(2.3f, 2.3f, 2.3f);
	draw_soldier();
	//glLoadIdentity();
	//glTranslatef(-0.15f + 0.02f, 0.25f, 0.0f);
	//draw_soldier();

	float i = 0.0f, j = 0.0f;
	for (j = 0.0f; j < 4; j = j + 0.08)
	{
		for (i = 0.00f; i <= 0.7f; i = i + 0.02f)
		{
			glLoadIdentity();
			glTranslatef(0.0f, 0.0f, -3.0f);
			glTranslatef(-0.15f + i, 0.3f - j, 0.0f);
			draw_soldier();
			fprintf(gpFILE, "i = %f\n", i);
		}
	}


	glLoadIdentity();
	glTranslatef(0.1f, -0.75f, -3.0f);
	glScalef(1.6f, 1.6f, 2.3f);
	// light silver mountain
	glTranslatef(-1.6f, 0.68f, -0.5f);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.427, 0.588, 0.694);
	glVertex3f(53.8413f / s, 14.3137f / s, 0.0f);
	glVertex3f(-41.6256f / s, 10.7739f / s, 0.0f);
	glVertex3f(97.84f / s, 10.77f / s, 0.0f);
	glVertex3f(45.8261f / s, 81.3451f / s, 0.0f);
	glVertex3f(-41.6256f / s, 10.7739f / s, 0.0f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, -0.6f, -3.0f);
	glScalef(2.5f, 2.5f, 2.3f);
	glTranslatef(0.07f, 0.28f, 0.0f);
	// dark green mountain
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.067, 0.369, 0.216);
	glVertex3f(-21.608f / s, 13.3953f / s, 0.0f);
	glVertex3f(97.84f / s, 10.77f / s, 0.0f);
	glVertex3f(99.4759f / s, 34.7588f / s, 0.0f);
	glVertex3f(45.7305f / s, 27.6965f / s, 0.0f);
	glVertex3f(42.6067f / s, 29.4621f / s, 0.0f);
	glVertex3f(39.3472f / s, 29.1904f / s, 0.0f);
	glVertex3f(35.816f / s, 27.5607f / s, 0.0f);
	glVertex3f(29.4327f / s, 25.2518f / s, 0.0f);
	glVertex3f(20.0615f / s, 30.4128f / s, 0.0f);
	glVertex3f(15.5796f / s, 35.4379f / s, 0.0f);
	glVertex3f(12.8633f / s, 36.117f / s, 0.0f);
	glVertex3f(8.24558f / s, 31.7709f / s, 0.0f);
	glVertex3f(3.35625f / s, 30.6844f / s, 0.0f);
	glVertex3f(-6.42242f / s, 24.3011f / s, 0.0f);
	glVertex3f(-41.6256f / s, 10.7739f / s, 0.0f);
	glVertex3f(97.84f / s, 10.77f / s, 0.0f);
	glEnd();



	////TREES////////////

	// Tree 1
	glLoadIdentity();
	glTranslatef(-4.7f, 1.98f, -20.0f);
	glScalef(1.0f, 0.5f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.192, 0.584, 0.114);
	glVertex3f(10.0f / s, 5.0f / s, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 15.0f / s;
		float y = sin(a) * 15.0f / s;

		glVertex3f((10.0f / s) + x, (5.0f / s) + y, 0.0f);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(27.0f / s, 17.0f / s, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 15.0f / s;
		float y = sin(a) * 15.0f / s;

		glVertex3f((27.0f / s) + x, (17.0f / s) + y, 0.0f);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(19.0f / s, 43.0f / s, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 15.0f / s;
		float y = sin(a) * 15.0f / s;

		glVertex3f((19.0f / s) + x, (43.0f / s) + y, 0.0f);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f / s, 30.0f / s, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 25.0f / s;
		float y = sin(a) * 25.0f / s;

		glVertex3f((0.0f / s) + x, (30.0f / s) + y, 0.0f);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-2.0f / s, 44.0f / s, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 20.0f / s;
		float y = sin(a) * 20.0f / s;

		glVertex3f((-2.0f / s) + x, (44.0f / s) + y, 0.0f);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-15.0f / s, 21.0f / s, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 20.0f / s;
		float y = sin(a) * 20.0f / s;

		glVertex3f((-15.0f / s) + x, (21.0f / s) + y, 0.0f);
	}
	glEnd();

	// Main Khod
	glBegin(GL_QUADS);
	glColor3f(0.467, 0.271, 0.18);

	glVertex3f(5.0f / s, -27.0f / s, 0.0f);
	glVertex3f(1.0f / s, 30.0f / s, 0.0f);
	glVertex3f(-0.30f / s, 30.0f / s, 0.0f);
	glVertex3f(-3.0f / s, -28.0f / s, 0.0f);

	glVertex3f(3.0f / s, 0.0f / s, 0.0f);
	glVertex3f(15.0f / s, 13.0f / s, 0.0f);
	glVertex3f(14.0f / s, 14.0f / s, 0.0f);
	glVertex3f(2.0f / s, 5.0f / s, 0.0f);

	glVertex3f(-2.0f / s, 0.0f / s, 0.0f);
	glVertex3f(-14.0f / s, 18.0f / s, 0.0f);
	glVertex3f(-13.0f / s, 19.0f / s, 0.0f);
	glVertex3f(-1.0f / s, 6.0f / s, 0.0f);
	glEnd();

	//// Tree 2
	//glLoadIdentity();
	//glTranslatef(-5.3f, -0.29f, -8.0f);
	//glScalef(1.0f, 3.0f, 1.0f);

	//glBegin(GL_TRIANGLE_FAN);
	//glColor3f(0.165, 0.494, 0.098);
	//glVertex3f(10.0f / s, 5.0f / s, 0.0f);
	//for (int i = 0; i < 363; i++)
	//{
	//	float a = i * (3.14 / 180);
	//	float x = cos(a) * 15.0f / s;
	//	float y = sin(a) * 15.0f / s;

	//	glVertex3f((10.0f / s) + x, (5.0f / s) + y, 0.0f);
	//}
	//glEnd();

	//glBegin(GL_TRIANGLE_FAN);
	////glColor3f(0.0f, 1.0f, 0.0f);
	//glVertex3f(27.0f / s, 17.0f / s, 0.0f);
	//for (int i = 0; i < 363; i++)
	//{
	//	float a = i * (3.14 / 180);
	//	float x = cos(a) * 15.0f / s;
	//	float y = sin(a) * 15.0f / s;

	//	glVertex3f((27.0f / s) + x, (17.0f / s) + y, 0.0f);
	//}
	//glEnd();

	//glBegin(GL_TRIANGLE_FAN);
	////glColor3f(0.0f, 1.0f, 0.0f);
	//glVertex3f(19.0f / s, 43.0f / s, 0.0f);
	//for (int i = 0; i < 363; i++)
	//{
	//	float a = i * (3.14 / 180);
	//	float x = cos(a) * 15.0f / s;
	//	float y = sin(a) * 15.0f / s;

	//	glVertex3f((19.0f / s) + x, (43.0f / s) + y, 0.0f);
	//}
	//glEnd();


	//glBegin(GL_TRIANGLE_FAN);
	////glColor3f(0.0f, 1.0f, 0.0f);
	//glVertex3f(0.0f / s, 30.0f / s, 0.0f);
	//for (int i = 0; i < 363; i++)
	//{
	//	float a = i * (3.14 / 180);
	//	float x = cos(a) * 25.0f / s;
	//	float y = sin(a) * 25.0f / s;

	//	glVertex3f((0.0f / s) + x, (30.0f / s) + y, 0.0f);
	//}
	//glEnd();


	//glBegin(GL_TRIANGLE_FAN);
	////glColor3f(0.0f, 1.0f, 0.0f);
	//glVertex3f(-2.0f / s, 44.0f / s, 0.0f);
	//for (int i = 0; i < 363; i++)
	//{
	//	float a = i * (3.14 / 180);
	//	float x = cos(a) * 20.0f / s;
	//	float y = sin(a) * 20.0f / s;

	//	glVertex3f((-2.0f / s) + x, (44.0f / s) + y, 0.0f);
	//}
	//glEnd();


	//glBegin(GL_TRIANGLE_FAN);
	////glColor3f(0.0f, 1.0f, 0.0f);
	//glVertex3f(-15.0f / s, 21.0f / s, 0.0f);
	//for (int i = 0; i < 363; i++)
	//{
	//	float a = i * (3.14 / 180);
	//	float x = cos(a) * 20.0f / s;
	//	float y = sin(a) * 20.0f / s;

	//	glVertex3f((-15.0f / s) + x, (21.0f / s) + y, 0.0f);
	//}
	//glEnd();

	//// Main Khod
	//glBegin(GL_QUADS);
	//glColor3f(0.467, 0.271, 0.18);

	//glVertex3f(5.0f / s, -27.0f / s, 0.0f);
	//glVertex3f(1.0f / s, 30.0f / s, 0.0f);
	//glVertex3f(-0.30f / s, 30.0f / s, 0.0f);
	//glVertex3f(-3.0f / s, -28.0f / s, 0.0f);

	//glVertex3f(3.0f / s, 0.0f / s, 0.0f);
	//glVertex3f(15.0f / s, 13.0f / s, 0.0f);
	//glVertex3f(14.0f / s, 14.0f / s, 0.0f);
	//glVertex3f(2.0f / s, 5.0f / s, 0.0f);

	//glVertex3f(-2.0f / s, 0.0f / s, 0.0f);
	//glVertex3f(-14.0f / s, 18.0f / s, 0.0f);
	//glVertex3f(-13.0f / s, 19.0f / s, 0.0f);
	//glVertex3f(-1.0f / s, 6.0f / s, 0.0f);
	//glEnd();

	// Tree 3
	glLoadIdentity();
	glTranslatef(2.7f, 1.98f, -20.0f);
	glScalef(-5.0f, 2.5f, 1.0f);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.165, 0.494, 0.098);
	glVertex3f(10.0f / s, 5.0f / s, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 15.0f / s;
		float y = sin(a) * 15.0f / s;

		glVertex3f((10.0f / s) + x, (5.0f / s) + y, 0.0f);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(27.0f / s, 17.0f / s, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 15.0f / s;
		float y = sin(a) * 15.0f / s;

		glVertex3f((27.0f / s) + x, (17.0f / s) + y, 0.0f);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(19.0f / s, 43.0f / s, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 15.0f / s;
		float y = sin(a) * 15.0f / s;

		glVertex3f((19.0f / s) + x, (43.0f / s) + y, 0.0f);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f / s, 30.0f / s, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 25.0f / s;
		float y = sin(a) * 25.0f / s;

		glVertex3f((0.0f / s) + x, (30.0f / s) + y, 0.0f);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-2.0f / s, 44.0f / s, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 20.0f / s;
		float y = sin(a) * 20.0f / s;

		glVertex3f((-2.0f / s) + x, (44.0f / s) + y, 0.0f);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-15.0f / s, 21.0f / s, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 20.0f / s;
		float y = sin(a) * 20.0f / s;

		glVertex3f((-15.0f / s) + x, (21.0f / s) + y, 0.0f);
	}
	glEnd();


	// Main Khod
	glBegin(GL_QUADS);
	glColor3f(0.467, 0.271, 0.18);

	glVertex3f(5.0f / s, -27.0f / s, 0.0f);
	glVertex3f(1.0f / s, 30.0f / s, 0.0f);
	glVertex3f(-0.30f / s, 30.0f / s, 0.0f);
	glVertex3f(-3.0f / s, -28.0f / s, 0.0f);

	glVertex3f(3.0f / s, 0.0f / s, 0.0f);
	glVertex3f(15.0f / s, 13.0f / s, 0.0f);
	glVertex3f(14.0f / s, 14.0f / s, 0.0f);
	glVertex3f(2.0f / s, 5.0f / s, 0.0f);

	glVertex3f(-2.0f / s, 0.0f / s, 0.0f);
	glVertex3f(-14.0f / s, 18.0f / s, 0.0f);
	glVertex3f(-13.0f / s, 19.0f / s, 0.0f);
	glVertex3f(-1.0f / s, 6.0f / s, 0.0f);
	glEnd();

	//tree 1 smitas
	GLfloat d = 150.0f;
	// tree pink converted into green
	glLoadIdentity();
	glTranslatef(1.4f, 0.8f, -4.0f);
	glScalef(0.5f, 0.5f, 0.0f);
	//Tree top
	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(-93.2706f / d, 3.39394f / d, 0.0f);
	glVertex3f(-66.6771f / d, 16.2357f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.306, 0.725, 0.333);
	glVertex3f(-93.2706f / d, 3.39394f / d, 0.0f);
	glVertex3f(-74.0586f / d, -17.436f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(-74.0586f / d, -17.436f / d, 0.0f);
	glVertex3f(-59.195f / d, -20.3696f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(-66.6771f / d, 16.2357f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(-87.4079f / d, 33.0941f / d, 0.0f);
	glVertex3f(-66.6771f / d, 16.2357f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(-87.4079f / d, 33.0941f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glVertex3f(-57.3678f / d, 52.1038f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(-57.3678f / d, 52.1038f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glVertex3f(-8.08333f / d, 40.1348f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(-57.3678f / d, 52.1038f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glVertex3f(-8.08333f / d, 40.1348f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.306, 0.725, 0.333);
	glVertex3f(-31.0827f / d, 45.2978f / d, 0.0f);
	glVertex3f(-8.08333f / d, 40.1348f / d, 0.0f);
	glVertex3f(23.7404f / d, 50.555f / d, 0.0f);
	glVertex3f(51.6213f / d, 36.7553f / d, 0.0f);
	glVertex3f(2.90006f / d, 74.4931f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(2.90006f / d, 74.4931f / d, 0.0f);
	glVertex3f(51.6213f / d, 36.7553f / d, 0.0f);
	glVertex3f(42.046f / d, 69.1423f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.306, 0.725, 0.333);
	glVertex3f(23.7404f / d, 50.555f / d, 0.0f);
	glVertex3f(35.0054f / d, 22.674f / d, 0.0f);
	glVertex3f(91.3305f / d, 13.3804f / d, 0.0f);
	glVertex3f(51.6213f / d, 36.7553f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(23.7404f / d, 50.555f / d, 0.0f);
	glVertex3f(35.0054f / d, 22.674f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glVertex3f(-8.08333f / d, 40.1348f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.306, 0.725, 0.333);
	glVertex3f(35.0054f / d, 22.674f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(35.0054f / d, 22.674f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.306, 0.725, 0.333);
	glVertex3f(35.0054f / d, 22.674f / d, 0.0f);
	glVertex3f(91.3305f / d, 13.3804f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(91.3305f / d, 13.3804f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glVertex3f(82.3185f / d, -9.14965f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(63.7312f / d, -12.8108f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glVertex3f(82.3185f / d, -9.14965f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.306, 0.725, 0.333);
	glVertex3f(63.7312f / d, -12.8108f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glVertex3f(59.5068f / d, -28.0186f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(13.6018f / d, -11.6843f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glVertex3f(59.5068f / d, -28.0186f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(13.6018f / d, -11.6843f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glEnd();

	//Tree trunk

	glBegin(GL_POLYGON);
	glColor3f(0.647, 0.435, 0.267);
	glVertex3f(-2.10449f / d, -7.61757f / d, 0.0f);
	glVertex3f(-3.43808f / d, -8.097880f / d, 0.0f);
	glVertex3f(10.2874f / d, -28.2465f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.655, 0.439, 0.271);
	glVertex3f(26.1288f / d, -16.121f / d, 0.0f);
	glVertex3f(28.6713f / d, -16.3165f / d, 0.0f);
	glVertex3f(8.17077f / d, -37.5258f / d, 0.0f);
	glVertex3f(10.2874f / d, -28.2465f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.447, 0.251, 0.11);
	glVertex3f(28.6713f / d, -16.3165f / d, 0.0f);
	glVertex3f(9.11393f / d, -37.2429f / d, 0.0f);
	glVertex3f(30.0403f / d, -17.6855f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.447, 0.251, 0.11);
	glVertex3f(-3.24159f / d, -8.16338f / d, 0.0f);
	glVertex3f(-5.55499f / d, -8.49268f / d, 0.0f);
	glVertex3f(8.13606f / d, -31.7668f / d, 0.0f);
	glVertex3f(10.2874f / d, -28.2465f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.647, 0.435, 0.267);
	glVertex3f(-7.90095f / d, -8.88475f / d, 0.0f);
	glVertex3f(-5.3585f / d, -8.68917f / d, 0.0f);
	glVertex3f(8.13606f / d, -31.7668f / d, 0.0f);
	glVertex3f(3.4423f / d, -30.789f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.647, 0.435, 0.267);
	glVertex3f(-18.0708f / d, -11.0361f / d, 0.0f);
	glVertex3f(-4.57621f / d, -14.7519f / d, 0.0f);
	glVertex3f(-20.6132f / d, -11.8183f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.447, 0.251, 0.11);
	glVertex3f(-20.6132f / d, -11.8183f / d, 0.0f);
	glVertex3f(-23.8098f / d, -12.6624f / d, 0.0f);
	glVertex3f(-3.20719f / d, -18.2723f / d, 0.0f);
	glVertex3f(-4.57621f / d, -14.7519f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.655, 0.439, 0.271);
	glVertex3f(8.13606f / d, -31.7668f / d, 0.0f);
	glVertex3f(3.4423f / d, -30.789f / d, 0.0f);
	glVertex3f(2.23627f / d, -41.9758f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.447, 0.251, 0.11);
	glVertex3f(10.2874f / d, -28.2465f / d, 0.0f);
	glVertex3f(8.17077f / d, -37.5258f / d, 0.0f);
	glVertex3f(2.23627f / d, -41.9758f / d, 0.0f);
	glVertex3f(1.74733f / d, -59.5774f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.655, 0.439, 0.271);
	glVertex3f(2.23627f / d, -41.9758f / d, 0.0f);
	glVertex3f(1.74733f / d, -59.5774f / d, 0.0f);
	glVertex3f(-27.1193f / d, -90.5562f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.447, 0.251, 0.11);
	glVertex3f(1.74733f / d, -59.5774f / d, 0.0f);
	glVertex3f(-27.1193f / d, -90.5562f / d, 0.0f);
	glVertex3f(-7.88488f / d, -91.4949f / d, 0.0f);
	glVertex3f(-3.44426f / d, -90.5562f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.286, 0.094, 0.008);
	glVertex3f(-3.44426f / d, -90.5562f / d, 0.0f);
	glVertex3f(-7.88488f / d, -91.4949f / d, 0.0f);
	glVertex3f(-0.364861f / d, -91.7296f / d, 0.0f);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.286, 0.094, 0.008);
	glVertex3f(-0.364861f / d, -91.7296f / d, 0.0f);
	glVertex3f(-7.88488f / d, -91.4949f / d, 0.0f);
	glVertex3f(-27.1193f / d, -90.5562f / d, 0.0f);
	glVertex3f(-53.3261f / d, -91.9252f / d, 0.0f);
	glVertex3f(-74.0569f / d, -93.2786f / d, 0.0f);
	glVertex3f(32.9608f / d, -93.8418f / d, 0.0f);
	glEnd();

	// 2 tree pink converted into green
	glLoadIdentity();
	glTranslatef(2.9f, 0.3f, -4.0f);
	glScalef(0.5f, 1.0f, 1.0f);
	//Tree top
	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(-93.2706f / d, 3.39394f / d, 0.0f);
	glVertex3f(-66.6771f / d, 16.2357f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.306, 0.725, 0.333);
	glVertex3f(-93.2706f / d, 3.39394f / d, 0.0f);
	glVertex3f(-74.0586f / d, -17.436f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(-74.0586f / d, -17.436f / d, 0.0f);
	glVertex3f(-59.195f / d, -20.3696f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(-66.6771f / d, 16.2357f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(-87.4079f / d, 33.0941f / d, 0.0f);
	glVertex3f(-66.6771f / d, 16.2357f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(-87.4079f / d, 33.0941f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glVertex3f(-57.3678f / d, 52.1038f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(-57.3678f / d, 52.1038f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glVertex3f(-8.08333f / d, 40.1348f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(-57.3678f / d, 52.1038f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glVertex3f(-8.08333f / d, 40.1348f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.306, 0.725, 0.333);
	glVertex3f(-31.0827f / d, 45.2978f / d, 0.0f);
	glVertex3f(-8.08333f / d, 40.1348f / d, 0.0f);
	glVertex3f(23.7404f / d, 50.555f / d, 0.0f);
	glVertex3f(51.6213f / d, 36.7553f / d, 0.0f);
	glVertex3f(2.90006f / d, 74.4931f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(2.90006f / d, 74.4931f / d, 0.0f);
	glVertex3f(51.6213f / d, 36.7553f / d, 0.0f);
	glVertex3f(42.046f / d, 69.1423f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.306, 0.725, 0.333);
	glVertex3f(23.7404f / d, 50.555f / d, 0.0f);
	glVertex3f(35.0054f / d, 22.674f / d, 0.0f);
	glVertex3f(91.3305f / d, 13.3804f / d, 0.0f);
	glVertex3f(51.6213f / d, 36.7553f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(23.7404f / d, 50.555f / d, 0.0f);
	glVertex3f(35.0054f / d, 22.674f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glVertex3f(-8.08333f / d, 40.1348f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.306, 0.725, 0.333);
	glVertex3f(35.0054f / d, 22.674f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(35.0054f / d, 22.674f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.306, 0.725, 0.333);
	glVertex3f(35.0054f / d, 22.674f / d, 0.0f);
	glVertex3f(91.3305f / d, 13.3804f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(91.3305f / d, 13.3804f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glVertex3f(82.3185f / d, -9.14965f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(63.7312f / d, -12.8108f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glVertex3f(82.3185f / d, -9.14965f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.306, 0.725, 0.333);
	glVertex3f(63.7312f / d, -12.8108f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glVertex3f(59.5068f / d, -28.0186f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(13.6018f / d, -11.6843f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glVertex3f(59.5068f / d, -28.0186f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(13.6018f / d, -11.6843f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glEnd();

	//Tree trunk

	glBegin(GL_POLYGON);
	glColor3f(0.647, 0.435, 0.267);
	glVertex3f(-2.10449f / d, -7.61757f / d, 0.0f);
	glVertex3f(-3.43808f / d, -8.097880f / d, 0.0f);
	glVertex3f(10.2874f / d, -28.2465f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.655, 0.439, 0.271);
	glVertex3f(26.1288f / d, -16.121f / d, 0.0f);
	glVertex3f(28.6713f / d, -16.3165f / d, 0.0f);
	glVertex3f(8.17077f / d, -37.5258f / d, 0.0f);
	glVertex3f(10.2874f / d, -28.2465f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.447, 0.251, 0.11);
	glVertex3f(28.6713f / d, -16.3165f / d, 0.0f);
	glVertex3f(9.11393f / d, -37.2429f / d, 0.0f);
	glVertex3f(30.0403f / d, -17.6855f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.447, 0.251, 0.11);
	glVertex3f(-3.24159f / d, -8.16338f / d, 0.0f);
	glVertex3f(-5.55499f / d, -8.49268f / d, 0.0f);
	glVertex3f(8.13606f / d, -31.7668f / d, 0.0f);
	glVertex3f(10.2874f / d, -28.2465f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.647, 0.435, 0.267);
	glVertex3f(-7.90095f / d, -8.88475f / d, 0.0f);
	glVertex3f(-5.3585f / d, -8.68917f / d, 0.0f);
	glVertex3f(8.13606f / d, -31.7668f / d, 0.0f);
	glVertex3f(3.4423f / d, -30.789f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.647, 0.435, 0.267);
	glVertex3f(-18.0708f / d, -11.0361f / d, 0.0f);
	glVertex3f(-4.57621f / d, -14.7519f / d, 0.0f);
	glVertex3f(-20.6132f / d, -11.8183f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.447, 0.251, 0.11);
	glVertex3f(-20.6132f / d, -11.8183f / d, 0.0f);
	glVertex3f(-23.8098f / d, -12.6624f / d, 0.0f);
	glVertex3f(-3.20719f / d, -18.2723f / d, 0.0f);
	glVertex3f(-4.57621f / d, -14.7519f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.655, 0.439, 0.271);
	glVertex3f(8.13606f / d, -31.7668f / d, 0.0f);
	glVertex3f(3.4423f / d, -30.789f / d, 0.0f);
	glVertex3f(2.23627f / d, -41.9758f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.447, 0.251, 0.11);
	glVertex3f(10.2874f / d, -28.2465f / d, 0.0f);
	glVertex3f(8.17077f / d, -37.5258f / d, 0.0f);
	glVertex3f(2.23627f / d, -41.9758f / d, 0.0f);
	glVertex3f(1.74733f / d, -59.5774f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.655, 0.439, 0.271);
	glVertex3f(2.23627f / d, -41.9758f / d, 0.0f);
	glVertex3f(1.74733f / d, -59.5774f / d, 0.0f);
	glVertex3f(-27.1193f / d, -90.5562f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.447, 0.251, 0.11);
	glVertex3f(1.74733f / d, -59.5774f / d, 0.0f);
	glVertex3f(-27.1193f / d, -90.5562f / d, 0.0f);
	glVertex3f(-7.88488f / d, -91.4949f / d, 0.0f);
	glVertex3f(-3.44426f / d, -90.5562f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.286, 0.094, 0.008);
	glVertex3f(-3.44426f / d, -90.5562f / d, 0.0f);
	glVertex3f(-7.88488f / d, -91.4949f / d, 0.0f);
	glVertex3f(-0.364861f / d, -91.7296f / d, 0.0f);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.286, 0.094, 0.008);
	glVertex3f(-0.364861f / d, -91.7296f / d, 0.0f);
	glVertex3f(-7.88488f / d, -91.4949f / d, 0.0f);
	glVertex3f(-27.1193f / d, -90.5562f / d, 0.0f);
	glVertex3f(-53.3261f / d, -91.9252f / d, 0.0f);
	glVertex3f(-74.0569f / d, -93.2786f / d, 0.0f);
	glVertex3f(32.9608f / d, -93.8418f / d, 0.0f);
	glEnd();

	//3 tree pink converted into green
	glLoadIdentity();
	glTranslatef(-2.9f, 1.7f, -9.0f);
	glScalef(0.7f, 1.7f, 1.0f);
	//Tree top
	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(-93.2706f / d, 3.39394f / d, 0.0f);
	glVertex3f(-66.6771f / d, 16.2357f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.306, 0.725, 0.333);
	glVertex3f(-93.2706f / d, 3.39394f / d, 0.0f);
	glVertex3f(-74.0586f / d, -17.436f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(-74.0586f / d, -17.436f / d, 0.0f);
	glVertex3f(-59.195f / d, -20.3696f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(-66.6771f / d, 16.2357f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(-87.4079f / d, 33.0941f / d, 0.0f);
	glVertex3f(-66.6771f / d, 16.2357f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(-87.4079f / d, 33.0941f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glVertex3f(-57.3678f / d, 52.1038f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(-57.3678f / d, 52.1038f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glVertex3f(-8.08333f / d, 40.1348f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(-57.3678f / d, 52.1038f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glVertex3f(-8.08333f / d, 40.1348f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.306, 0.725, 0.333);
	glVertex3f(-31.0827f / d, 45.2978f / d, 0.0f);
	glVertex3f(-8.08333f / d, 40.1348f / d, 0.0f);
	glVertex3f(23.7404f / d, 50.555f / d, 0.0f);
	glVertex3f(51.6213f / d, 36.7553f / d, 0.0f);
	glVertex3f(2.90006f / d, 74.4931f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(2.90006f / d, 74.4931f / d, 0.0f);
	glVertex3f(51.6213f / d, 36.7553f / d, 0.0f);
	glVertex3f(42.046f / d, 69.1423f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.306, 0.725, 0.333);
	glVertex3f(23.7404f / d, 50.555f / d, 0.0f);
	glVertex3f(35.0054f / d, 22.674f / d, 0.0f);
	glVertex3f(91.3305f / d, 13.3804f / d, 0.0f);
	glVertex3f(51.6213f / d, 36.7553f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(23.7404f / d, 50.555f / d, 0.0f);
	glVertex3f(35.0054f / d, 22.674f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glVertex3f(-8.08333f / d, 40.1348f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.306, 0.725, 0.333);
	glVertex3f(35.0054f / d, 22.674f / d, 0.0f);
	glVertex3f(-49.8578f / d, 23.4719f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(35.0054f / d, 22.674f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.306, 0.725, 0.333);
	glVertex3f(35.0054f / d, 22.674f / d, 0.0f);
	glVertex3f(91.3305f / d, 13.3804f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(91.3305f / d, 13.3804f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glVertex3f(82.3185f / d, -9.14965f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(63.7312f / d, -12.8108f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glVertex3f(82.3185f / d, -9.14965f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.306, 0.725, 0.333);
	glVertex3f(63.7312f / d, -12.8108f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glVertex3f(59.5068f / d, -28.0186f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.631, 0.278);
	glVertex3f(13.6018f / d, -11.6843f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glVertex3f(59.5068f / d, -28.0186f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.149, 0.718, 0.122);
	glVertex3f(13.6018f / d, -11.6843f / d, 0.0f);
	glVertex3f(39.2122f / d, 3.73843f / d, 0.0f);
	glVertex3f(-2.46836f / d, -7.5266f / d, 0.0f);
	glEnd();

	//Tree trunk

	glBegin(GL_POLYGON);
	glColor3f(0.647, 0.435, 0.267);
	glVertex3f(-2.10449f / d, -7.61757f / d, 0.0f);
	glVertex3f(-3.43808f / d, -8.097880f / d, 0.0f);
	glVertex3f(10.2874f / d, -28.2465f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.655, 0.439, 0.271);
	glVertex3f(26.1288f / d, -16.121f / d, 0.0f);
	glVertex3f(28.6713f / d, -16.3165f / d, 0.0f);
	glVertex3f(8.17077f / d, -37.5258f / d, 0.0f);
	glVertex3f(10.2874f / d, -28.2465f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.447, 0.251, 0.11);
	glVertex3f(28.6713f / d, -16.3165f / d, 0.0f);
	glVertex3f(9.11393f / d, -37.2429f / d, 0.0f);
	glVertex3f(30.0403f / d, -17.6855f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.447, 0.251, 0.11);
	glVertex3f(-3.24159f / d, -8.16338f / d, 0.0f);
	glVertex3f(-5.55499f / d, -8.49268f / d, 0.0f);
	glVertex3f(8.13606f / d, -31.7668f / d, 0.0f);
	glVertex3f(10.2874f / d, -28.2465f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.647, 0.435, 0.267);
	glVertex3f(-7.90095f / d, -8.88475f / d, 0.0f);
	glVertex3f(-5.3585f / d, -8.68917f / d, 0.0f);
	glVertex3f(8.13606f / d, -31.7668f / d, 0.0f);
	glVertex3f(3.4423f / d, -30.789f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.647, 0.435, 0.267);
	glVertex3f(-18.0708f / d, -11.0361f / d, 0.0f);
	glVertex3f(-4.57621f / d, -14.7519f / d, 0.0f);
	glVertex3f(-20.6132f / d, -11.8183f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.447, 0.251, 0.11);
	glVertex3f(-20.6132f / d, -11.8183f / d, 0.0f);
	glVertex3f(-23.8098f / d, -12.6624f / d, 0.0f);
	glVertex3f(-3.20719f / d, -18.2723f / d, 0.0f);
	glVertex3f(-4.57621f / d, -14.7519f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.655, 0.439, 0.271);
	glVertex3f(8.13606f / d, -31.7668f / d, 0.0f);
	glVertex3f(3.4423f / d, -30.789f / d, 0.0f);
	glVertex3f(2.23627f / d, -41.9758f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.447, 0.251, 0.11);
	glVertex3f(10.2874f / d, -28.2465f / d, 0.0f);
	glVertex3f(8.17077f / d, -37.5258f / d, 0.0f);
	glVertex3f(2.23627f / d, -41.9758f / d, 0.0f);
	glVertex3f(1.74733f / d, -59.5774f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.655, 0.439, 0.271);
	glVertex3f(2.23627f / d, -41.9758f / d, 0.0f);
	glVertex3f(1.74733f / d, -59.5774f / d, 0.0f);
	glVertex3f(-27.1193f / d, -90.5562f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.447, 0.251, 0.11);
	glVertex3f(1.74733f / d, -59.5774f / d, 0.0f);
	glVertex3f(-27.1193f / d, -90.5562f / d, 0.0f);
	glVertex3f(-7.88488f / d, -91.4949f / d, 0.0f);
	glVertex3f(-3.44426f / d, -90.5562f / d, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.286, 0.094, 0.008);
	glVertex3f(-3.44426f / d, -90.5562f / d, 0.0f);
	glVertex3f(-7.88488f / d, -91.4949f / d, 0.0f);
	glVertex3f(-0.364861f / d, -91.7296f / d, 0.0f);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.286, 0.094, 0.008);
	glVertex3f(-0.364861f / d, -91.7296f / d, 0.0f);
	glVertex3f(-7.88488f / d, -91.4949f / d, 0.0f);
	glVertex3f(-27.1193f / d, -90.5562f / d, 0.0f);
	glVertex3f(-53.3261f / d, -91.9252f / d, 0.0f);
	glVertex3f(-74.0569f / d, -93.2786f / d, 0.0f);
	glVertex3f(32.9608f / d, -93.8418f / d, 0.0f);
	glEnd();

	//Ravna Palace
	glLoadIdentity();
	glTranslatef(1.35f, 0.2f, -3.0f);
	glScalef(0.5f, 0.5f, 1.5f);
	draw_ravana_palace11();

	glLoadIdentity();
	glTranslatef(1.0f, -0.4f, -3.0f);
	glScalef(1.0f, 1.0f, 1.5f);
	draw_ravana_palace11();

	glLoadIdentity();
	glTranslatef(1.0f, -1.0f, -3.0f);
	glScalef(0.7f, 0.7f, 1.5f);
	draw_ravana_palace11();



	glLoadIdentity();
	glTranslatef(-0.0f, -0.2f, -3.0f);
	glScalef(1.5f, 1.5f, 1.5f);
	draw_ravana_palace();

	//_______________________________________________________________________lanka Bhint)_____________________________________________________________________/
	//bhinth
	glLoadIdentity();
	glTranslatef(0.95f, -2.30f, -5.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glRotatef(-65.0f, 0.0f, 1.0, 0.0f);
	glRotatef(-34.0f, 0.0f, 0.0, 1.0f);
	//glRotatef(-57.0f, 0.0f, 0.0, 0.0f);
	//AGG (+X)
	for (int i = 250; i >= 51; i -= 25)
	{
		glBegin(GL_QUADS);
		glColor3f(0.361, 0.157, 0.122);
		glVertex3f((i + 10.0f) / D, 60.0 / D, 0.0f / D);
		glColor3f(0.361, 0.157, 0.122);
		glVertex3f((i - 10) / D, 60.0 / D, 0.0f / D);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f((i - 10) / D, 45.0 / D, 0.0f / D);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f((i + 10.0f) / D, 45.0 / D, 0.0f / D);
		glEnd();


		//Aagiche loop right side
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 2)) / D, 60.0f / D, 0.0f);
		}
		glEnd();

		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 4)) / D, 62.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 6)) / D, 64.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 8)) / D, 66.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 10)) / D, 68.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 12)) / D, 70.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 15)) / D, 72.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 1; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 18)) / D, 76.0f / D, 0.0f);
		}
		glEnd();
		//2
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 2)) / D, 60.0f / D, 0.0f);
		}
		glEnd();

		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 4)) / D, 62.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 6)) / D, 64.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 8)) / D, 66.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 10)) / D, 68.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 12)) / D, 70.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 14)) / D, 72.0f / D, 0.0f);
		}
		glEnd();
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 16)) / D, 74.0f / D, 0.0f);
		}
		glEnd();

	}

	//bhinth
	glBegin(GL_QUADS);
	glColor3f(0.443, 0.106, 0.114);
	glVertex3f(533.0 / D, 49.0 / D, 0.0f / D);
	glColor3f(1.0, 0.682, 0.259);
	glVertex3f(533.0 / D, 6.0 / D, 0.0f / D);
	glColor3f(1.0, 0.682, 0.259);
	glVertex3f(17.0 / D, 5.0 / D, 0.0f / D);
	glColor3f(0.443, 0.106, 0.114);
	glVertex3f(17.0 / D, 49.0 / D, 0.0f / D);
	glEnd();

	//bhinth silver color
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(250.0 / D, 25.0 / D, 0.0f / D);
	glVertex3f(250.0 / D, 22.0 / D, 0.0f / D);
	glVertex3f(16.0 / D, 22.0 / D, 0.0f / D);
	glVertex3f(16.0 / D, 25.0 / D, 0.0f / D);
	glEnd();




	//AGG (-X)
	for (int i = -250; i <= -51; i += 25)
	{
		glBegin(GL_QUADS);

		glColor3f(0.361, 0.157, 0.122);
		glVertex3f((i + 10.0f) / D, 60.0 / D, 0.0f / D);
		glColor3f(0.361, 0.157, 0.122);
		glVertex3f((i - 10) / D, 60.0 / D, 0.0f / D);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f((i - 10) / D, 45.0 / D, 0.0f / D);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f((i + 10.0f) / D, 45.0 / D, 0.0f / D);
		glEnd();

		//Aagiche loop left side
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 2)) / D, 60.0f / D, 0.0f);
		}
		glEnd();

		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 4)) / D, 62.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 6)) / D, 64.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 8)) / D, 66.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 10)) / D, 68.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 12)) / D, 70.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 15)) / D, 72.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 1; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i - (j / 18)) / D, 76.0f / D, 0.0f);
		}
		glEnd();
		//2
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 2)) / D, 60.0f / D, 0.0f);
		}
		glEnd();

		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 4)) / D, 62.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 6)) / D, 64.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 8)) / D, 66.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 10)) / D, 68.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 12)) / D, 70.0f / D, 0.0f);
		}
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 14)) / D, 72.0f / D, 0.0f);
		}
		glEnd();
		glEnd();
		glPointSize(3);
		glBegin(GL_POINTS);
		for (int j = 0; j <= 20; j++)
		{
			glColor3f(0.949, 0.773, 0.471);
			glVertex3f((i + (j / 16)) / D, 74.0f / D, 0.0f);
		}
		glEnd();
	}


	//hath
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.031f, 0.063f, 0.125f);
	glVertex3f(48.0 / D, 48.0 / D, 0.0f / D);
	glVertex3f(64.0 / D, 16.0 / D, 0.0f / D);
	glVertex3f(63.0 / D, 20.0 / D, 0.0f / D);
	glVertex3f(62.0 / D, 25.0 / D, 0.0f / D);

	glVertex3f(62.0 / D, 27.0 / D, 0.0f / D);
	glVertex3f(60.0 / D, 45.0 / D, 0.0f / D);
	glVertex3f(58.0 / D, 51.0 / D, 0.0f / D);
	glVertex3f(49.0 / D, 61.0 / D, 0.0f / D);
	glVertex3f(38.0 / D, 66.0 / D, 0.0f / D);

	glVertex3f(35.0 / D, 67.0 / D, 0.0f / D);
	glVertex3f(31.0 / D, 70.0 / D, 0.0f / D);
	glVertex3f(19.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(24.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(17.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(17.0 / D, 49.0 / D, 0.0f / D);
	glVertex3f(31.0 / D, 45.0 / D, 0.0f / D);

	glVertex3f(35.0 / D, 45.0 / D, 0.0f / D);
	glVertex3f(38.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(44.0 / D, 32.0 / D, 0.0f / D);
	glVertex3f(47.0 / D, 25.0 / D, 0.0f / D);

	glVertex3f(48.0 / D, 22.0 / D, 0.0f / D);
	glVertex3f(49.0 / D, 16.0 / D, 0.0f / D);
	glVertex3f(64.0 / D, 16.0 / D, 0.0f / D);
	glEnd();


	//
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(42.0 / D, 63.0 / D, 0.0f / D);
	glVertex3f(41.0 / D, 62.0 / D, 0.0f / D);

	glVertex3f(41.0 / D, 62.0 / D, 0.0f / D);
	glVertex3f(44.0 / D, 61.0 / D, 0.0f / D);

	glVertex3f(44.0 / D, 61.0 / D, 0.0f / D);
	glVertex3f(45.0 / D, 63.0 / D, 0.0f / D);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(18.0 / D, 51.0 / D, 0.0f / D);
	glVertex3f(25.0 / D, 54.0 / D, 0.0f / D);

	glVertex3f(25.0 / D, 54.0 / D, 0.0f / D);
	glVertex3f(25.0 / D, 57.0 / D, 0.0f / D);

	glEnd();

	//hata varchey kadey1
	glBegin(GL_POLYGON);
	glColor3f(0.831f, 0.376f, 0.012f);
	glVertex3f(35.0 / D, 45.0 / D, 0.0f / D);
	glVertex3f(36.0 / D, 55.0 / D, 0.0f / D);
	glVertex3f(38.0 / D, 66.0 / D, 0.0f / D);
	glVertex3f(35.0 / D, 67.0 / D, 0.0f / D);
	glVertex3f(34.0 / D, 56.0 / D, 0.0f / D);
	glVertex3f(31.0 / D, 45.0 / D, 0.0f / D);
	glEnd();

	//

	glBegin(GL_POLYGON);
	glColor3f(0.831f, 0.376f, 0.012f);
	glVertex3f(47.0 / D, 25.0 / D, 0.0f / D);
	glVertex3f(55.0 / D, 28.0 / D, 0.0f / D);
	glVertex3f(62.0 / D, 27.0 / D, 0.0f / D);
	glVertex3f(62.0 / D, 25.0 / D, 0.0f / D);
	glVertex3f(56.0 / D, 26.0 / D, 0.0f / D);
	glVertex3f(48.0 / D, 22.0 / D, 0.0f / D);
	glEnd();


	//darwaja
	glBegin(GL_QUADS);
	glColor3f(0.855f, 0.451f, 0.098f);
	glVertex3f(17.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(10.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(11.0 / D, 5.0 / D, 0.0f / D);
	glVertex3f(17.0 / D, 5.0 / D, 0.0f / D);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.808, 0.0);
	glVertex3f(11.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(11.0 / D, 18.0 / D, 0.0f / D);
	glVertex3f(2.0 / D, 26.0 / D, 0.0f / D);
	glVertex3f(0.0 / D, 32.0 / D, 0.0f / D);
	glVertex3f(0.0 / D, 44.0 / D, 0.0f / D);
	glEnd();

	//entrance glow
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0 / D, 4.0 / D, 0.0f / D);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(11.0 / D, 5.0 / D, 0.0f / D);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(11.0 / D, 18.0 / D, 0.0f / D);
	glVertex3f(2.0 / D, 26.0 / D, 0.0f / D);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.0 / D, 32.0 / D, 0.0f / D);
	glEnd();
	//face shing 1
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(11.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(16.0 / D, 75.0 / D, 0.0f / D);
	glVertex3f(18.0 / D, 76.0 / D, 0.0f / D);
	glVertex3f(17.0 / D, 77.0 / D, 0.0f / D);
	glVertex3f(17.0 / D, 78.0 / D, 0.0f / D);
	glVertex3f(18.0 / D, 78.0 / D, 0.0f / D);
	glVertex3f(19.0 / D, 77.0 / D, 0.0f / D);
	glVertex3f(19.0 / D, 74.0 / D, 0.0f / D);
	glVertex3f(19.0 / D, 72.0 / D, 0.0f / D);
	glVertex3f(14.0 / D, 68.0 / D, 0.0f / D);
	glEnd();

	//face shing 2

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(12.0 / D, 46.0 / D, 0.0f / D);
	glVertex3f(16.0 / D, 41.0 / D, 0.0f / D);
	glVertex3f(19.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(16.0 / D, 39.0 / D, 0.0f / D);
	glVertex3f(9.0 / D, 44.0 / D, 0.0f / D);
	glEnd();

	//face
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.031f, 0.063f, 0.125f);
	glVertex3f(0.0 / D, 69.0 / D, 0.0f / D);
	glVertex3f(0.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(9.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(14.0 / D, 47.0 / D, 0.0f / D);
	glVertex3f(14.0 / D, 68.0 / D, 0.0f / D);
	glVertex3f(11.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(9.0 / D, 76.0 / D, 0.0f / D);
	glVertex3f(5.0 / D, 78.0 / D, 0.0f / D);
	glVertex3f(0.0 / D, 80.0 / D, 0.0f / D);
	glEnd();

	//face glowing eye
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(11.0 / D, 53.0 / D, 0.0f / D);
	glVertex3f(11.0 / D, 56.0 / D, 0.0f / D);
	glVertex3f(9.0 / D, 57.0 / D, 0.0f / D);
	glVertex3f(6.0 / D, 56.0 / D, 0.0f / D);
	glVertex3f(7.0 / D, 52.0 / D, 0.0f / D);
	glVertex3f(9.0 / D, 52.0 / D, 0.0f / D);
	glVertex3f(9.0 / D, 54.0 / D, 0.0f / D);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0 / D, 52.0 / D, 0.0f / D);
	glVertex3f(5.0 / D, 49.0 / D, 0.0f / D);

	glVertex3f(5.0 / D, 49.0 / D, 0.0f / D);
	glVertex3f(8.0 / D, 51.0 / D, 0.0f / D);

	glVertex3f(8.0 / D, 51.0 / D, 0.0f / D);
	glVertex3f(11.0 / D, 49.0 / D, 0.0f / D);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(3.0 / D, 46.0 / D, 0.0f / D);
	glVertex3f(5.0 / D, 48.0 / D, 0.0f / D);

	glVertex3f(5.0 / D, 48.0 / D, 0.0f / D);
	glVertex3f(9.0 / D, 47.0 / D, 0.0f / D);

	glVertex3f(9.0 / D, 47.0 / D, 0.0f / D);
	glVertex3f(11.0 / D, 49.0 / D, 0.0f / D);
	glEnd();

	//******************************************************************************************************************************************************************//
			//opposite part
			//Sea waves 1
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-80.0f / D, -8.0f / D, 0.0f);
	//glVertex3f(-83.0f / D, -6.0f / D, 0.0f);
	//glVertex3f(-87.0f / D, -9.0f / D, 0.0f);
	//glVertex3f(-83.0f / D, -9.0f / D, 0.0f);
	//glEnd();
	////2
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-107.0f / D, -6.0f / D, 0.0f);
	//glVertex3f(-112.0f / D, -2.0f / D, 0.0f);
	//glVertex3f(-115.0f / D, -6.0f / D, 0.0f);
	//glVertex3f(-110.0f / D, -7.0f / D, 0.0f);
	//glEnd();
	////3
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-114.0f / D, -16.0f / D, 0.0f);
	//glVertex3f(-119.0f / D, -10.0f / D, 0.0f);
	//glVertex3f(-125.0f / D, -13.0f / D, 0.0f);
	//glVertex3f(-120.0f / D, -16.0f / D, 0.0f);
	//glEnd();
	////4
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-138.0f / D, -29.0f / D, 0.0f);
	//glVertex3f(-142.0f / D, -24.0f / D, 0.0f);
	//glVertex3f(-146.0f / D, -29.0f / D, 0.0f);
	//glVertex3f(-142.0f / D, -31.0f / D, 0.0f);
	//glEnd();
	////5
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-119.0f / D, -29.0f / D, 0.0f);
	//glVertex3f(-125.0f / D, -25.0f / D, 0.0f);
	//glVertex3f(-128.0f / D, -30.0f / D, 0.0f);
	//glVertex3f(-124.0f / D, -31.0f / D, 0.0f);
	//glEnd();
	////6
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-104.0f / D, -18.0f / D, 0.0f);
	//glVertex3f(-107.0f / D, -15.0f / D, 0.0f);
	//glVertex3f(-109.0f / D, -18.0f / D, 0.0f);
	//glVertex3f(-106.0f / D, -20.0f / D, 0.0f);
	//glEnd();
	////7
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-89.0f / D, -11.0f / D, 0.0f);
	//glVertex3f(-93.0f / D, -7.0f / D, 0.0f);
	//glVertex3f(-97.0f / D, -11.0f / D, 0.0f);
	//glVertex3f(-93.0f / D, -13.0f / D, 0.0f);
	//glEnd();

	//bhinth
	glBegin(GL_QUADS);
	glColor3f(0.22, 0.239, 0.271);
	glColor3f(0.443, 0.106, 0.114);
	glVertex3f(-533.0 / D, 49.0 / D, 0.0f / D);
	glColor3f(1.0, 0.682, 0.259);
	glVertex3f(-533.0 / D, 6.0 / D, 0.0f / D);
	glColor3f(1.0, 0.682, 0.259);
	glVertex3f(-17.0 / D, 5.0 / D, 0.0f / D);
	glColor3f(0.443, 0.106, 0.114);
	glVertex3f(-17.0 / D, 49.0 / D, 0.0f / D);
	glEnd();

	//bhinth silver color
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(-250.0 / D, 25.0 / D, 0.0f / D);
	glVertex3f(-250.0 / D, 22.0 / D, 0.0f / D);
	glVertex3f(-16.0 / D, 22.0 / D, 0.0f / D);
	glVertex3f(-16.0 / D, 25.0 / D, 0.0f / D);
	glEnd();
	//hath
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.031f, 0.063f, 0.125f);
	glVertex3f(-48.0 / D, 48.0 / D, 0.0f / D);
	glVertex3f(-64.0 / D, 16.0 / D, 0.0f / D);
	glVertex3f(-63.0 / D, 20.0 / D, 0.0f / D);
	glVertex3f(-62.0 / D, 25.0 / D, 0.0f / D);

	glVertex3f(-62.0 / D, 27.0 / D, 0.0f / D);
	glVertex3f(-60.0 / D, 45.0 / D, 0.0f / D);
	glVertex3f(-58.0 / D, 51.0 / D, 0.0f / D);
	glVertex3f(-49.0 / D, 61.0 / D, 0.0f / D);
	glVertex3f(-38.0 / D, 66.0 / D, 0.0f / D);

	glVertex3f(-35.0 / D, 67.0 / D, 0.0f / D);
	glVertex3f(-31.0 / D, 70.0 / D, 0.0f / D);
	glVertex3f(-19.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(-24.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(-17.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(-17.0 / D, 49.0 / D, 0.0f / D);
	glVertex3f(-31.0 / D, 45.0 / D, 0.0f / D);

	glVertex3f(-35.0 / D, 45.0 / D, 0.0f / D);
	glVertex3f(-38.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(-44.0 / D, 32.0 / D, 0.0f / D);
	glVertex3f(-47.0 / D, 25.0 / D, 0.0f / D);

	glVertex3f(-48.0 / D, 22.0 / D, 0.0f / D);
	glVertex3f(-49.0 / D, 16.0 / D, 0.0f / D);
	glVertex3f(-64.0 / D, 16.0 / D, 0.0f / D);
	glEnd();

	//

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-42.0 / D, 63.0 / D, 0.0f / D);
	glVertex3f(-41.0 / D, 62.0 / D, 0.0f / D);

	glVertex3f(-41.0 / D, 62.0 / D, 0.0f / D);
	glVertex3f(-44.0 / D, 61.0 / D, 0.0f / D);

	glVertex3f(-44.0 / D, 61.0 / D, 0.0f / D);
	glVertex3f(-45.0 / D, 63.0 / D, 0.0f / D);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-18.0 / D, 51.0 / D, 0.0f / D);
	glVertex3f(-25.0 / D, 54.0 / D, 0.0f / D);

	glVertex3f(-25.0 / D, 54.0 / D, 0.0f / D);
	glVertex3f(-25.0 / D, 57.0 / D, 0.0f / D);

	glEnd();
	//hata varchey kadey1
	glBegin(GL_POLYGON);
	glColor3f(0.831f, 0.376f, 0.012f);
	glVertex3f(-35.0 / D, 45.0 / D, 0.0f / D);
	glVertex3f(-36.0 / D, 55.0 / D, 0.0f / D);
	glVertex3f(-38.0 / D, 66.0 / D, 0.0f / D);
	glVertex3f(-35.0 / D, 67.0 / D, 0.0f / D);
	glVertex3f(-34.0 / D, 56.0 / D, 0.0f / D);
	glVertex3f(-31.0 / D, 45.0 / D, 0.0f / D);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.831f, 0.376f, 0.012f);
	glVertex3f(-47.0 / D, 25.0 / D, 0.0f / D);
	glVertex3f(-55.0 / D, 28.0 / D, 0.0f / D);
	glVertex3f(-62.0 / D, 27.0 / D, 0.0f / D);
	glVertex3f(-62.0 / D, 25.0 / D, 0.0f / D);
	glVertex3f(-56.0 / D, 26.0 / D, 0.0f / D);
	glVertex3f(-48.0 / D, 22.0 / D, 0.0f / D);
	glEnd();

	//darwaja
	glBegin(GL_QUADS);
	glColor3f(0.855f, 0.451f, 0.098f);
	glVertex3f(-17.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(-10.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(-11.0 / D, 5.0 / D, 0.0f / D);
	glVertex3f(-17.0 / D, 5.0 / D, 0.0f / D);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.808, 0.0);
	glVertex3f(-11.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(-11.0 / D, 18.0 / D, 0.0f / D);
	glVertex3f(-2.0 / D, 26.0 / D, 0.0f / D);
	glVertex3f(-0.0 / D, 32.0 / D, 0.0f / D);
	glVertex3f(-0.0 / D, 44.0 / D, 0.0f / D);
	glEnd();
	//entrance glow
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0 / D, 4.0 / D, 0.0f / D);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-11.0 / D, 5.0 / D, 0.0f / D);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-11.0 / D, 18.0 / D, 0.0f / D);
	glVertex3f(-2.0 / D, 26.0 / D, 0.0f / D);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.0 / D, 32.0 / D, 0.0f / D);
	glEnd();

	//face shing 1
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-11.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(-16.0 / D, 75.0 / D, 0.0f / D);
	glVertex3f(-18.0 / D, 76.0 / D, 0.0f / D);
	glVertex3f(-17.0 / D, 77.0 / D, 0.0f / D);
	glVertex3f(-17.0 / D, 78.0 / D, 0.0f / D);
	glVertex3f(-18.0 / D, 78.0 / D, 0.0f / D);
	glVertex3f(-19.0 / D, 77.0 / D, 0.0f / D);
	glVertex3f(-19.0 / D, 74.0 / D, 0.0f / D);
	glVertex3f(-19.0 / D, 72.0 / D, 0.0f / D);
	glVertex3f(-14.0 / D, 68.0 / D, 0.0f / D);
	glEnd();

	//face shing 2

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-12.0 / D, 46.0 / D, 0.0f / D);
	glVertex3f(-16.0 / D, 41.0 / D, 0.0f / D);
	glVertex3f(-19.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(-16.0 / D, 39.0 / D, 0.0f / D);
	glVertex3f(-9.0 / D, 44.0 / D, 0.0f / D);


	glEnd();

	//face
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.031f, 0.063f, 0.125f);
	glVertex3f(-0.0 / D, 69.0 / D, 0.0f / D);
	glVertex3f(-0.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(-9.0 / D, 44.0 / D, 0.0f / D);
	glVertex3f(-14.0 / D, 47.0 / D, 0.0f / D);
	glVertex3f(-14.0 / D, 68.0 / D, 0.0f / D);
	glVertex3f(-11.0 / D, 73.0 / D, 0.0f / D);
	glVertex3f(-9.0 / D, 76.0 / D, 0.0f / D);
	glVertex3f(-5.0 / D, 78.0 / D, 0.0f / D);
	glVertex3f(-0.0 / D, 80.0 / D, 0.0f / D);
	glEnd();

	//face glowing eye
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-11.0 / D, 53.0 / D, 0.0f / D);
	glVertex3f(-11.0 / D, 56.0 / D, 0.0f / D);
	glVertex3f(-9.0 / D, 57.0 / D, 0.0f / D);
	glVertex3f(-6.0 / D, 56.0 / D, 0.0f / D);
	glVertex3f(-7.0 / D, 52.0 / D, 0.0f / D);
	glVertex3f(-9.0 / D, 52.0 / D, 0.0f / D);
	glVertex3f(-9.0 / D, 54.0 / D, 0.0f / D);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0 / D, 52.0 / D, 0.0f / D);
	glVertex3f(-5.0 / D, 49.0 / D, 0.0f / D);

	glVertex3f(-5.0 / D, 49.0 / D, 0.0f / D);
	glVertex3f(-8.0 / D, 51.0 / D, 0.0f / D);

	glVertex3f(-8.0 / D, 51.0 / D, 0.0f / D);
	glVertex3f(-11.0 / D, 49.0 / D, 0.0f / D);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-3.0 / D, 46.0 / D, 0.0f / D);
	glVertex3f(-5.0 / D, 48.0 / D, 0.0f / D);

	glVertex3f(-5.0 / D, 48.0 / D, 0.0f / D);
	glVertex3f(-9.0 / D, 47.0 / D, 0.0f / D);

	glVertex3f(-9.0 / D, 47.0 / D, 0.0f / D);
	glVertex3f(-11.0 / D, 49.0 / D, 0.0f / D);
	glEnd();



	draw_soldier();
	//______________________________________________________________________________________________________________//_______________________________________________________________________//
	//// Blue mountain
	////glScalef(0.5f, 0.5f, 0.0f);
	//glBegin(GL_TRIANGLE_FAN);
	//glColor3f(0.0, 0.18, 0.42);
	//glVertex3f(-43.9073f / s, 24.953f / s, 0.0f);
	//glVertex3f(-6.42242f / s, 24.3011f / s, 0.0f);
	//glVertex3f(-38.3661f / s, 27.3976f / s, 0.0f);
	//glVertex3f(-46.8409f / s, 29.8423f / s, 0.0f);
	//glVertex3f(-52.8711f / s, 31.6251f / s, 0.0f);
	//glVertex3f(-58.2494f / s, 33.1019f / s, 0.0f);
	//glVertex3f(-64.4425f / s, 34.2427f / s, 0.0f);
	//glVertex3f(-70.1467f / s, 34.2427f / s, 0.0f);
	//glVertex3f(-75.199f / s, 33.7538f / s, 0.0f);
	//glVertex3f(-79.9254f / s, 32.7759f / s, 0.0f);
	//glVertex3f(-98.3419f / s, 27.0717f / s, 0.0f);
	//glVertex3f(-98.17f / s, 10.77f / s, 0.0f);
	//glVertex3f(-41.6256f / s, 10.7739f / s, 0.0f);
	//glVertex3f(-6.42242f / s, 24.3011f / s, 0.0f);
	//glEnd();




	/*glLoadIdentity();
	glTranslatef(1.0f, -0.2f, -3.0f);
	glScalef(1.5f, 1.5f, 1.5f);
	glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);
	draw_ravana_palace();*/



	//glLoadIdentity();
	//glTranslatef(1.0f, 0.0f, -3.0f);
	//glScalef(0.5f, 0.5f, 1.0f);
	//draw_ravana_palace();

	//////

}

void draw_lanka_parvat(void)
{
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	glScalef(2.5f, 2.5f, 2.0f);
	glTranslatef(-0.2f, -0.5f, 0.5f);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.38, 0.243, 0.071);
	glVertex3f(-25.4f / s, -2.156f / s, 0.0f);
	glVertex3f(-25.5924f / s, -0.851087f / s, 0.0f);
	glVertex3f(-36.4287f / s, -4.13585f / s, 0.0f);
	glVertex3f(-41.6776f / s, -9.55403f / s, 0.0f);
	glVertex3f(-7.50926f / s, -9.8588f / s, 0.0f);
	glVertex3f(-12.0808f / s, -6.37085f / s, 0.0f);
	glVertex3f(-11.3358f / s, 0.571184f / s, 0.0f);
	glVertex3f(-17.5329f / s, 6.93754f / s, 0.0f);
	glVertex3f(-14.8577f / s, 13.778f / s, 0.0f);
	glVertex3f(-23.0006f / s, 6.39994f / s, 0.0f);
	glVertex3f(-25.5924f / s, -0.851087f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.49, 0.31, 0.09);
	glVertex3f(-37.0451f / s, -0.780314f / s, 0.0f);
	glVertex3f(-39.3072f / s, -1.86699f / s, 0.0f);
	glVertex3f(-51.2949f / s, -10.3329f / s, 0.0f);
	glVertex3f(-41.6776f / s, -9.55403f / s, 0.0f);
	glVertex3f(-36.4287f / s, -4.13585f / s, 0.0f);
	glVertex3f(-25.5924f / s, -0.851087f / s, 0.0f);
	glVertex3f(-23.0006f / s, 6.39994f / s, 0.0f);
	glVertex3f(-14.8577f / s, 13.778f / s, 0.0f);
	glVertex3f(-11.6282f / s, 17.0882f / s, 0.0f);
	glVertex3f(-6.24466f / s, 23.1154f / s, 0.0f);
	glVertex3f(-9.40454f / s, 29.084f / s, 0.0f);
	glVertex3f(-8.17569f / s, 34.0579f / s, 0.0f);
	glVertex3f(-15.0221f / s, 32.595f / s, 0.0f);
	glVertex3f(-26.1987f / s, 19.7214f / s, 0.0f);
	glVertex3f(-39.3072f / s, -1.86699f / s, 0.0f);
	glEnd();

	//upper base part
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.49, 0.31, 0.09);
	glVertex3f(-15.0221 / s, 32.595 / s, 0.0f);
	glVertex3f(-4.34855 / s, 30.659 / s, 0.0f);
	glColor3f(0.96f, 0.69f, 0.070f);
	glVertex3f(-4.34855 / s, 30.659 / s, 0.0f);
	glVertex3f(1.517 / s, 30.4699 / s, 0.0f);
	glVertex3f(1.517 / s, 30.4699 / s, 0.0f);
	glVertex3f(9.78912 / s, 33.2 / s, 0.0f);
	glVertex3f(-0.501 / s, 35.957 / s, 0.0f);
	//glVertex3f(-1.25808 / s, 34.5 / s, 0.0f);
	glVertex3f(-13.7 / s, 35.0 / s, 0.0f);
	glVertex3f(-15.022 / s, 32.59 / s, 0.0f);

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.49, 0.31, 0.09);
	glVertex3f(-9.30539f / s, 4.37002f / s, 0.0f);
	glVertex3f(-7.50926f / s, -9.8588f / s, 0.0f);
	glVertex3f(-12.0808f / s, -6.37085f / s, 0.0f);
	glVertex3f(-11.3358f / s, 0.571184f / s, 0.0f);
	glVertex3f(-17.5329f / s, 6.93754f / s, 0.0f);
	glVertex3f(-14.8577f / s, 13.778f / s, 0.0f);
	glVertex3f(-11.6282f / s, 17.0882f / s, 0.0f);
	glVertex3f(-6.71279f / s, 6.32122f / s, 0.0f);
	glVertex3f(-0.048436f / s, 3.88304f / s, 0.0f);
	glVertex3f(0.967471f / s, -1.96858f / s, 0.0f);
	glVertex3f(5.80319f / s, -5.54458f / s, 0.0f);
	glVertex3f(-5.29052f / s, -9.97393f / s, 0.0f);
	glVertex3f(-7.50926f / s, -9.8588f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.573, 0.353, 0.094);
	glVertex3f(4.11976f / s, 5.68046f / s, 0.0f);
	glVertex3f(3.45318f / s, 23.4136f / s, 0.0f);
	glVertex3f(6.90239f / s, 16.0225f / s, 0.0f);
	glVertex3f(7.054f / s, 7.5321f / s, 0.0f);
	glVertex3f(15.3928f / s, 2.26353f / s, 0.0f);
	glVertex3f(18.5387f / s, -3.87683f / s, 0.0f);
	glVertex3f(5.80319f / s, -5.54458f / s, 0.0f);
	glVertex3f(0.967471f / s, -1.96858f / s, 0.0f);
	glVertex3f(-0.048436f / s, 3.88304f / s, 0.0f);
	glVertex3f(-6.71279f / s, 6.32122f / s, 0.0f);
	glVertex3f(-11.6282f / s, 17.0882f / s, 0.0f);
	glVertex3f(-6.24466f / s, 23.1154f / s, 0.0f);
	glVertex3f(-9.40454f / s, 29.084f / s, 0.0f);
	glVertex3f(-8.17569 / s, 31.5776 / s, 0.0f);
	//glVertex3f(-8.17569f / s, 34.0579f / s, 0.0f);
	glVertex3f(1.10165f / s, 32.5605f / s, 0.0f);
	glVertex3f(3.45318f / s, 23.4136f / s, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.573, 0.353, 0.094);
	glVertex3f(23.1395f / s, 9.77381f / s, 0.0f);
	glVertex3f(35.2466f / s, -6.2784f / s, 0.0f);
	glVertex3f(21.2375f / s, 6.99387f / s, 0.0f);
	glVertex3f(12.5045f / s, 9.7684f / s, 0.0f);
	glVertex3f(10.6397f / s, 16.1717f / s, 0.0f);
	glVertex3f(3.45318f / s, 23.4136f / s, 0.0f);
	glVertex3f(3.45318f / s, 23.4136f / s, 0.0f);
	glVertex3f(1.10165f / s, 32.5605f / s, 0.0f);
	glVertex3f(8.5474f / s, 31.4188f / s, 0.0f);
	glVertex3f(20.5552f / s, 20.6482f / s, 0.0f);
	glVertex3f(28.6969f / s, 7.13942f / s, 0.0f);
	glVertex3f(47.4818f / s, -8.09776f / s, 0.0f);
	glVertex3f(35.2466f / s, -6.2784f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.49, 0.31, 0.09);
	glVertex3f(11.9144f / s, 8.97002f / s, 0.0f);
	glVertex3f(35.2466f / s, -6.2784f / s, 0.0f);
	glVertex3f(21.2375f / s, 6.99387f / s, 0.0f);
	glVertex3f(12.5045f / s, 9.7684f / s, 0.0f);
	glVertex3f(10.6397f / s, 16.1717f / s, 0.0f);
	glVertex3f(3.45318f / s, 23.4136f / s, 0.0f);
	glVertex3f(6.90239f / s, 16.0225f / s, 0.0f);
	glVertex3f(7.054f / s, 7.5321f / s, 0.0f);
	glVertex3f(15.3928f / s, 2.26353f / s, 0.0f);
	glVertex3f(18.5387f / s, -3.87683f / s, 0.0f);
	glVertex3f(35.2466f / s, -6.2784f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.702, 0.455, 0.094);
	glVertex3f(21.8756f / s, 21.0255f / s, 0.0f);
	glVertex3f(9.78912f / s, 33.2428f / s, 0.0f);
	glVertex3f(23.1478f / s, 21.7853f / s, 0.0f);
	glVertex3f(23.1478f / s, 21.7853f / s, 0.0f);
	glVertex3f(28.6969f / s, 7.13942f / s, 0.0f);
	glVertex3f(20.5552f / s, 20.6482f / s, 0.0f);
	glVertex3f(8.5474f / s, 31.4188f / s, 0.0f);
	glVertex3f(1.10165f / s, 32.5605f / s, 0.0f);
	glVertex3f(9.78912f / s, 33.2428f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.38, 0.243, 0.071);
	glVertex3f(-40.3885f / s, -0.445272f / s, 0.0f);
	glVertex3f(-51.2949f / s, -10.3329f / s, 0.0f);
	glVertex3f(-39.3072f / s, -1.86699f / s, 0.0f);
	glVertex3f(-26.1987f / s, 19.7214f / s, 0.0f);
	glVertex3f(-15.0221f / s, 32.595f / s, 0.0f);
	glVertex3f(-28.0127f / s, 20.9503f / s, 0.0f);
	glVertex3f(-41.2374f / s, 0.469593f / s, 0.0f);
	glVertex3f(-63.7789f / s, -11.8575f / s, 0.0f);
	glVertex3f(-51.2949f / s, -10.3329f / s, 0.0f);
	glEnd();
}

void draw_ravana_palace(void)
{
	glTranslatef(45.0f / s, 15.0f / s, 0.0f);
	glScalef(0.47f, 0.47f, 0.0f);

	// p4 - refer the pic in the code folder
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(1.0f, 0.6f, 0.2f);	//bhagva
	glVertex3f(70.8 / s, -13.97f / s, 0.0f);
	glVertex3f(26.8 / s, 6.11f / s, 0.0f);
	glVertex3f(-67.9 / s, -11.2f / s, 0.0f);
	glVertex3f(-38.5 / s, -47.25f / s, 0.0f);
	glEnd();

	//s10
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.84f, 0.0f);	//gold color
	glVertex3f(-38.5 / s, -47.25f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glVertex3f(70.8 / s, -24.97f / s, 0.0f);
	glVertex3f(70.8 / s, -13.97f / s, 0.0f);
	glEnd();

	//s11
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.84f, 0.0f);	//gold color
	glVertex3f(-38.5 / s, -47.25f / s, 0.0f);
	glVertex3f(-67.9 / s, -11.2f / s, 0.0f);
	glVertex3f(-67.9 / s, -22.2f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glEnd();


	/////////////////////////////////////////////////////////////side palace code begins/////////////////////////////////
		// p3 - refer the pic in the code folder
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(1.0f, 0.6f, 0.2f);	//bhagva
	//glVertex3f(56.06 / s, 0.89f / s, 0.0f);
	//glVertex3f(20.9 / s, 16.6f / s, 0.0f);
	//glVertex3f(-43.53 / s, 2.84f / s, 0.0f);
	//glVertex3f(-21.0 / s, -19.4f / s, 0.0f);
	glVertex3f(56.06 / s, -6.89f / s, 0.0f);
	glVertex3f(20.9 / s, 10.6f / s, 0.0f);
	glVertex3f(-43.53 / s, -4.84f / s, 0.0f);
	glVertex3f(-21.0 / s, -25.4f / s, 0.0f);
	glEnd();

	//s9
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.84f, 0.0f);	//gold color
	glVertex3f(-21.0 / s, -25.4f / s, 0.0f);
	glVertex3f(-21.0 / s, -36.6f / s, 0.0f);
	glVertex3f(56.06 / s, -15.0f / s, 0.0f);
	glVertex3f(56.06 / s, -6.89f / s, 0.0f);
	glEnd();

	//s8
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-21.0 / s, -36.6f / s, 0.0f);
	glVertex3f(-43.53 / s, -12.1f / s, 0.0f);
	glVertex3f(-43.53 / s, -4.84f / s, 0.0f);
	glVertex3f(-21.0 / s, -25.4f / s, 0.0f);
	glEnd();

	// p2 - refer the pic in the code folder
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(1.0f, 0.6f, 0.2f);	//bhagva
	glVertex3f(19.46 / s, 17.8f / s, 0.0f);
	glVertex3f(-25.7 / s, 9.27f / s, 0.0f);
	glVertex3f(-13.1 / s, -0.16f / s, 0.0f);
	glVertex3f(33.4 / s, 10.0f / s, 0.0f);
	glEnd();

	//s7
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.84f, 0.0f);	//gold color
	glVertex3f(-13.3 / s, -0.16f / s, 0.0f);
	glVertex3f(-13.3 / s, -15.7f / s, 0.0f);
	glVertex3f(33.4 / s, -5.3f / s, 0.0f);
	glVertex3f(33.4 / s, 9.9f / s, 0.0f);
	glEnd();

	//s6
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.84f, 0.0f);	//gold color
	glVertex3f(-25.7 / s, 9.27f / s, 0.0f);
	glVertex3f(-25.7 / s, -6.32f / s, 0.0f);
	glVertex3f(-13.3 / s, -15.7f / s, 0.0f);
	glVertex3f(-13.3 / s, -0.16f / s, 0.0f);
	glEnd();


	// S1 - refer the pic in the code folder
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(1.0f, 0.84f, 0.0f);	//gold color
	glVertex3f(-12.85 / s, 11.06f / s, 0.0f);
	glVertex3f(1.13 / s, 3.25f / s, 0.0f);
	glVertex3f(1.13 / s, 7.07f / s, 0.0f);
	glVertex3f(-12.85 / s, 15.54f / s, 0.0f);

	glEnd();

	// S2 - refer the pic in the code folder
	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(1.13 / s, 7.07f / s, 0.0f);
	glVertex3f(1.13 / s, 3.25f / s, 0.0f);
	glVertex3f(24.4 / s, 8.21f / s, 0.0f);
	glVertex3f(24.4 / s, 12.28f / s, 0.0f);
	glEnd();

	//p1
	glColor3f(1.0f, 0.6f, 0.2f);	//bhagva
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-12.85 / s, 15.54f / s, 0.0f);
	glVertex3f(1.13 / s, 7.07f / s, 0.0f);
	glVertex3f(24.4 / s, 12.28f / s, 0.0f);
	glVertex3f(10.5 / s, 19.4f / s, 0.0f);
	glEnd();

	//s3
	glColor3f(1.0f, 0.84f, 0.0f);	//gold color
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(2.8 / s, 11.39f / s, 0.0f);
	glVertex3f(-4.0 / s, 16.59f / s, 0.0f);
	glVertex3f(-4.8 / s, 12.69f / s, 0.0f);
	glVertex3f(5.45 / s, 9.92f / s, 0.0f);
	glVertex3f(15.7 / s, 12.0f / s, 0.0f);
	glVertex3f(16.2 / s, 15.7f / s, 0.0f);
	glVertex3f(9.7 / s, 13.6f / s, 0.0f);
	glVertex3f(2.1 / s, 13.7f / s, 0.0f);
	glVertex3f(-4.0 / s, 16.59f / s, 0.0f);
	glEnd();

	//s4 
	glColor3f(1.0f, 0.84f, 0.0f);	//gold color
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(6.2 / s, 18.7f / s, 0.0f);
	glVertex3f(-1.9 / s, 24.0f / s, 0.0f);
	glVertex3f(-1.9 / s, 16.8f / s, 0.0f);
	glVertex3f(5.2 / s, 15.29f / s, 0.0f);
	glVertex3f(13.7 / s, 17.1f / s, 0.0f);
	glVertex3f(13.7 / s, 23.7f / s, 0.0f);
	glVertex3f(5.6 / s, 23.0f / s, 0.0f);
	glVertex3f(-1.9 / s, 24.0f / s, 0.0f);
	glEnd();

	//s5
	glColor3f(1.0f, 0.0f, 0.0f);	//red color
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(6.3 / s, 28.6f / s, 0.0f);
	glVertex3f(-6.1 / s, 27.8f / s, 0.0f);
	glVertex3f(-1.9 / s, 24.0f / s, 0.0f);
	glVertex3f(5.6 / s, 23.0f / s, 0.0f);
	glVertex3f(13.7 / s, 23.7f / s, 0.0f);
	glVertex3f(19.2 / s, 27.3f / s, 0.0f);
	glVertex3f(6.7 / s, 41.3f / s, 0.0f);	// top point
	glVertex3f(-6.1 / s, 27.8f / s, 0.0f);
	glEnd();
	//////////////////////////////////////////////////////////////////////////////
		//s12

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(31.2 / s, -25.0f / s, 0.0f);
	glVertex3f(17.9 / s, -29.6f / s, 0.0f);
	glVertex3f(24.89 / s, -34.21f / s, 0.0f);
	glVertex3f(38.89 / s, -29.73f / s, 0.0f);

	glEnd();

	//s13

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.6f, 0.2f);	//bhagva

	glVertex3f(17.9 / s, -29.6f / s, 0.0f);
	glVertex3f(17.9 / s, -40.73f / s, 0.0f);
	glVertex3f(24.89 / s, -45.21f / s, 0.0f);
	glVertex3f(24.89 / s, -34.21f / s, 0.0f);


	glEnd();

	//s15

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.6f, 0.2f);	//bhagva

	glVertex3f(24.89 / s, -45.21f / s, 0.0f);
	glVertex3f(24.89 / s, -34.21f / s, 0.0f);
	glVertex3f(41.9 / s, -60.21f / s, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(24.89 / s, -34.21f / s, 0.0f);
	glVertex3f(41.9 / s, -60.21f / s, 0.0f);
	glVertex3f(54.67 / s, -55.75f / s, 0.0f);
	glVertex3f(38.89 / s, -29.73f / s, 0.0f);
	glEnd();


	//front left tomb
	//right wall
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.84f, 0.0f);
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glVertex3f(-32.95 / s, -57.95f / s, 0.0f);
	glVertex3f(-32.95 / s, 34.95f / s, 0.0f);

	glEnd();

	//left wall
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.84f, 0.0f);
	glVertex3f(-41.82 / s, -54.95f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-41.82 / s, 37.95f / s, 0.0f);
	glEnd();

	//top arch left triangle
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-41.82 / s, 37.95f / s, 0.0f);
	glVertex3f(-38.7 / s, 50.95f / s, 0.0f);
	glEnd();

	//top arch right triangle
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-32.95 / s, 34.95f / s, 0.0f);
	glVertex3f(-38.7 / s, 50.95f / s, 0.0f);
	glEnd();



	//front right tomb
	// 
	glTranslatef(104.0f / s, 33.0f / s, 0.0f);

	//right wall
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.84f, 0.0f);
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glVertex3f(-32.95 / s, -57.95f / s, 0.0f);
	glVertex3f(-32.95 / s, 34.95f / s, 0.0f);

	glEnd();

	//left wall
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.84f, 0.0f);
	glVertex3f(-41.82 / s, -54.95f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-41.82 / s, 37.95f / s, 0.0f);
	glEnd();

	//top arch left triangle
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-41.82 / s, 37.95f / s, 0.0f);
	glVertex3f(-38.7 / s, 50.95f / s, 0.0f);
	glEnd();

	//top arch right triangle
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-32.95 / s, 34.95f / s, 0.0f);
	glVertex3f(-38.7 / s, 50.95f / s, 0.0f);
	glEnd();

	//rear right tomb
// 
	glTranslatef(-45.0f / s, 25.0f / s, 0.0f);
	glScalef(1.0f, 0.8f, 0.0f);
	//right wall
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.84f, 0.0f);
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glVertex3f(-32.95 / s, -57.95f / s, 0.0f);
	glVertex3f(-32.95 / s, 34.95f / s, 0.0f);

	glEnd();

	//left wall
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.84f, 0.0f);
	glVertex3f(-41.82 / s, -54.95f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-41.82 / s, 37.95f / s, 0.0f);
	glEnd();

	//top arch left triangle
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-41.82 / s, 37.95f / s, 0.0f);
	glVertex3f(-38.7 / s, 50.95f / s, 0.0f);
	glEnd();

	//top arch right triangle
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-32.95 / s, 34.95f / s, 0.0f);
	glVertex3f(-38.7 / s, 50.95f / s, 0.0f);
	glEnd();

	//////

	//rear left tomb
	// 
	glTranslatef(-85.0f / s, -33.0f / s, 0.0f);
	//glScalef(1.0f, 1.6f, 0.0f);
	//right wall
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.84f, 0.0f);
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glVertex3f(-32.95 / s, -57.95f / s, 0.0f);
	glVertex3f(-32.95 / s, 34.95f / s, 0.0f);

	glEnd();

	//left wall
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.84f, 0.0f);
	glVertex3f(-41.82 / s, -54.95f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-41.82 / s, 37.95f / s, 0.0f);
	glEnd();

	//top arch left triangle
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-41.82 / s, 37.95f / s, 0.0f);
	glVertex3f(-38.7 / s, 50.95f / s, 0.0f);
	glEnd();

	//top arch right triangle
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-32.95 / s, 34.95f / s, 0.0f);
	glVertex3f(-38.7 / s, 50.95f / s, 0.0f);
	glEnd();

}

void draw_soldier(void)
{
	glTranslatef(1.0f, -0.3f, 2.0f);
	//soldier torso
	glScalef(2.3f, 2.3f, 2.3f);
	glLineWidth(5.0f);
	glColor3f(0.57f, 0.568f, 0.57f);
	glBegin(GL_LINES);
	glVertex3f(-0.8f, -0.01f, 0.0f);
	glVertex3f(-0.8f, -0.03f, 0.0f);
	glEnd();

	//soldier helmet
	glPointSize(4.5f);
	glColor3f(1.0f, 0.84f, 0.0f);
	glBegin(GL_POINTS);
	glVertex3f(-0.8f, 0.01f, 0.0f);
	glEnd();

	//soldier head
	glPointSize(4.5f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	glVertex3f(-0.8f, 0.0f, 0.0f);
	glEnd();


	//leg left
	glLineWidth(1.0f);
	glColor3f(0.57f, 0.568f, 0.57f);
	glBegin(GL_LINES);
	glVertex3f(-0.802f, -0.03f, 0.0f);
	glVertex3f(-0.802f, -0.04f, 0.0f);
	glEnd();

	//leg right
	glColor3f(0.57f, 0.568f, 0.57f);
	glBegin(GL_LINES);
	glVertex3f(-0.797f, -0.03f, 0.0f);
	glVertex3f(-0.797f, -0.04f, 0.0f);
	glEnd();



	switch (sph_dir)
	{
	case up_dir:
		if (y_sph_trnslate <= 0.010)
			y_sph_trnslate += 0.0000001;
		else sph_dir = dn_dir;
		break;
	case dn_dir:
		if (y_sph_trnslate >= 0.00)
			y_sph_trnslate -= 0.0000001;
		else sph_dir = up_dir;
		break;
	}


	glTranslatef(0.0f, y_sph_trnslate, 0.0f);
	//sphere
	glLineWidth(1.5);
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex3f(-0.793f, 0.04f, 0.0f);
	glVertex3f(-0.793f, -0.04f, 0.0f);
	glEnd();

	//sphere head
	glLineWidth(1.5);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex3f(-0.793f, 0.04f, 0.0f);
	glVertex3f(-0.793f, 0.02f, 0.0f);
	glEnd();
}

void draw_side_palace_1(void)
{


	// p3 - refer the pic in the code folder
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(1.0f, 0.6f, 0.2f);	//bhagva
	//glVertex3f(56.06 / s, 0.89f / s, 0.0f);
	//glVertex3f(20.9 / s, 16.6f / s, 0.0f);
	//glVertex3f(-43.53 / s, 2.84f / s, 0.0f);
	//glVertex3f(-21.0 / s, -19.4f / s, 0.0f);
	glVertex3f(56.06 / s, -6.89f / s, 0.0f);
	glVertex3f(20.9 / s, 10.6f / s, 0.0f);
	glVertex3f(-43.53 / s, -4.84f / s, 0.0f);
	glVertex3f(-21.0 / s, -25.4f / s, 0.0f);
	glEnd();

	//s9
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.84f, 0.0f);	//gold color
	glVertex3f(-21.0 / s, -25.4f / s, 0.0f);
	glVertex3f(-21.0 / s, -36.6f / s, 0.0f);
	glVertex3f(56.06 / s, -15.0f / s, 0.0f);
	glVertex3f(56.06 / s, -6.89f / s, 0.0f);
	glEnd();

	//s8
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-21.0 / s, -36.6f / s, 0.0f);
	glVertex3f(-43.53 / s, -12.1f / s, 0.0f);
	glVertex3f(-43.53 / s, -4.84f / s, 0.0f);
	glVertex3f(-21.0 / s, -25.4f / s, 0.0f);
	glEnd();

	// p2 - refer the pic in the code folder
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(1.0f, 0.6f, 0.2f);	//bhagva
	glVertex3f(19.46 / s, 17.8f / s, 0.0f);
	glVertex3f(-25.7 / s, 9.27f / s, 0.0f);
	glVertex3f(-13.1 / s, -0.16f / s, 0.0f);
	glVertex3f(33.4 / s, 10.0f / s, 0.0f);
	glEnd();

	//s7
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.84f, 0.0f);	//gold color
	glVertex3f(-13.3 / s, -0.16f / s, 0.0f);
	glVertex3f(-13.3 / s, -15.7f / s, 0.0f);
	glVertex3f(33.4 / s, -5.3f / s, 0.0f);
	glVertex3f(33.4 / s, 9.9f / s, 0.0f);
	glEnd();

	//s6
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.84f, 0.0f);	//gold color
	glVertex3f(-25.7 / s, 9.27f / s, 0.0f);
	glVertex3f(-25.7 / s, -6.32f / s, 0.0f);
	glVertex3f(-13.3 / s, -15.7f / s, 0.0f);
	glVertex3f(-13.3 / s, -0.16f / s, 0.0f);
	glEnd();


	// S1 - refer the pic in the code folder
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(1.0f, 0.84f, 0.0f);	//gold color
	glVertex3f(-12.85 / s, 11.06f / s, 0.0f);
	glVertex3f(1.13 / s, 3.25f / s, 0.0f);
	glVertex3f(1.13 / s, 7.07f / s, 0.0f);
	glVertex3f(-12.85 / s, 15.54f / s, 0.0f);

	glEnd();

	// S2 - refer the pic in the code folder
	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(1.13 / s, 7.07f / s, 0.0f);
	glVertex3f(1.13 / s, 3.25f / s, 0.0f);
	glVertex3f(24.4 / s, 8.21f / s, 0.0f);
	glVertex3f(24.4 / s, 12.28f / s, 0.0f);
	glEnd();

	//p1
	glColor3f(1.0f, 0.6f, 0.2f);	//bhagva
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-12.85 / s, 15.54f / s, 0.0f);
	glVertex3f(1.13 / s, 7.07f / s, 0.0f);
	glVertex3f(24.4 / s, 12.28f / s, 0.0f);
	glVertex3f(10.5 / s, 19.4f / s, 0.0f);
	glEnd();

	//s3
	glColor3f(1.0f, 0.84f, 0.0f);	//gold color
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(2.8 / s, 11.39f / s, 0.0f);
	glVertex3f(-4.0 / s, 16.59f / s, 0.0f);
	glVertex3f(-4.8 / s, 12.69f / s, 0.0f);
	glVertex3f(5.45 / s, 9.92f / s, 0.0f);
	glVertex3f(15.7 / s, 12.0f / s, 0.0f);
	glVertex3f(16.2 / s, 15.7f / s, 0.0f);
	glVertex3f(9.7 / s, 13.6f / s, 0.0f);
	glVertex3f(2.1 / s, 13.7f / s, 0.0f);
	glVertex3f(-4.0 / s, 16.59f / s, 0.0f);
	glEnd();

	//s4 
	glColor3f(1.0f, 0.84f, 0.0f);	//gold color
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(6.2 / s, 18.7f / s, 0.0f);
	glVertex3f(-1.9 / s, 24.0f / s, 0.0f);
	glVertex3f(-1.9 / s, 16.8f / s, 0.0f);
	glVertex3f(5.2 / s, 15.29f / s, 0.0f);
	glVertex3f(13.7 / s, 17.1f / s, 0.0f);
	glVertex3f(13.7 / s, 23.7f / s, 0.0f);
	glVertex3f(5.6 / s, 23.0f / s, 0.0f);
	glVertex3f(-1.9 / s, 24.0f / s, 0.0f);
	glEnd();

	//s5
	glColor3f(1.0f, 0.0f, 0.0f);	//red color
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(6.3 / s, 28.6f / s, 0.0f);
	glVertex3f(-6.1 / s, 27.8f / s, 0.0f);
	glVertex3f(-1.9 / s, 24.0f / s, 0.0f);
	glVertex3f(5.6 / s, 23.0f / s, 0.0f);
	glVertex3f(13.7 / s, 23.7f / s, 0.0f);
	glVertex3f(19.2 / s, 27.3f / s, 0.0f);
	glVertex3f(6.7 / s, 41.3f / s, 0.0f);	// top point
	glVertex3f(-6.1 / s, 27.8f / s, 0.0f);
	glEnd();


}

void AB_resetVariables(void)
{
	//Hanuman Animation 
	xHanuman = 700.0f;
	yHanuman = 150.0f;
	zHanuman = -800.0f;
	rHead = 0.0f;
	rHanuman = 90.0f;
	bHead = FALSE;
	rTail = 0.0f;
	bTail = FALSE;
	bHanumanRotate = FALSE;
	rotate_left_leg = 0.0f;
	rotate_right_leg = 0.0f;
	bRotateLeg = FALSE;
	xScaleHanuman = 1.0f;
	yScaleHanuman = 1.0f;
	zScaleHanuman = 1.0f;
	sHanuman = TRUE;
	bHanuman = FALSE;
	xrHauman = 0.0f;
	yrHauman = 0.0f;
	zrHauman = 1.0f;
}

void draw_bird1(void)
{
	//switch case for wings movement
	switch (dir11)
	{
	case up11:
		//if (rwAngle > 270.0f)
		//	rwAngle -= 0.01f;

		if (lw11Angle <= 65.0f)
			lw11Angle += 0.3f;
		else
			dir11 = down11;

		break;
	case down11:

		if (lw11Angle >= 0.0f)
			lw11Angle -= 0.3f;
		else
		{
			dir11 = up11;
			//lwAngle = 180.0f;
		}
		break;

	default:
		break;
	}

	if (x11_translate <= 10.5)
		x11_translate += 0.001;

	glTranslatef(x11_translate, 1.0f, 0.0f);
	glScalef(0.3f, 0.3f, 0.0f);





	//torse
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.36f, 0.54f, 0.64f);
	glVertex3f(-4.27 / s, -10.17f / s, 0.0f);
	glVertex3f(9.07f / s, -6.12f / s, 0.0f);

	//
	glVertex3f(8.4f / s, -2.2f / s, 0.0f);
	glVertex3f(0.24f / s, -2.37f / s, 0.0f);
	glVertex3f(-7.2f / s, -2.75f / s, 0.0f);
	//	glVertex3f(-13.28f / s, -5.07f / s, 0.0f);
	glVertex3f(-15.67f / s, -2.56f / s, 0.0f);



	//glVertex3f(-16.01f / s, -8.3f / s, 0.0f);

	//glVertex3f(-6.3f / s, -6.6f / s, 0.0f);
	glVertex3f(-16.01f / s, -8.3f / s, 0.0f);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-24.6f / s, -13.64f / s, 0.0f);
	glVertex3f(-20.06f / s, -13.3f / s, 0.0f);
	glVertex3f(-23.76f / s, -17.23f / s, 0.0f);
	glColor3f(0.36f, 0.54f, 0.64f);
	glVertex3f(-16.3f / s, -15.3f / s, 0.0f);
	glVertex3f(-8.78f / s, -18.79f / s, 0.0f);
	glVertex3f(3.81f / s, -17.98f / s, 0.0f);
	glVertex3f(14.22f / s, -12.31f / s, 0.0f);
	glVertex3f(11.04f / s, -8.38f / s, 0.0f);
	glVertex3f(9.07f / s, -6.12f / s, 0.0f);
	glEnd();

	//torso- 2
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.1f, 0.1f);
	glVertex3f(-4.27 / s, -10.17f / s, 0.0f);
	glVertex3f(-6.3f / s, -6.6f / s, 0.0f);
	glVertex3f(-12.144f / s, -8.32f / s, 0.0f);
	glVertex3f(-13.76f / s, -12.31f / s, 0.0f);
	glVertex3f(-11.97f / s, -14.05f / s, 0.0f);
	glVertex3f(-5.26f / s, -14.63f / s, 0.0f);
	glVertex3f(-4.16f / s, -13.01f / s, 0.0f);
	glVertex3f(6.47f / s, -9.42f / s, 0.0f);
	glVertex3f(1.9f / s, -6.41f / s, 0.0f);
	glVertex3f(-6.3f / s, -6.6f / s, 0.0f);
	glEnd();




	//head and neck
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(23.99f / s, -9.54f / s, 0.0f);
	glVertex3f(30.7f / s, -8.38f / s, 0.0f);
	glVertex3f(29.02f / s, -6.18f / s, 0.0f);
	glVertex3f(25.32f / s, -6.18f / s, 0.0f);
	glVertex3f(21.91f / s, -7.92f / s, 0.0f);
	glVertex3f(11.04f / s, -8.38f / s, 0.0f);
	glVertex3f(14.22f / s, -12.31f / s, 0.0f);
	glVertex3f(22.2f / s, -10.98f / s, 0.0f);
	glVertex3f(30.01f / s, -11.1f / s, 0.0f);
	glVertex3f(30.7f / s, -8.38f / s, 0.0f);
	glEnd();

	//eyes
	glPointSize(0.01f);
	glBegin(GL_POINTS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(27.839f / s, -7.75f / s, 0.0f);
	glEnd();

	//beak
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(30.7f / s, -8.38f / s, 0.0f);
	glVertex3f(30.01f / s, -11.1f / s, 0.0f);
	glVertex3f(33.79f / s, -11.1f / s, 0.0f);
	glEnd();

	//	glTranslatef(0.0f, y_translate, 0.0f);
	if (fly_flag11)
		glRotatef(lw11Angle, 1, 0, 0);
	//left wing
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3f(0.0f / s, 0.0f / s, 0.0f);
	glVertex3f(9.07f / s, -6.12f / s, 0.0f);
	glVertex3f(9.46f / s, 1.21f / s, 0.0f);
	glVertex3f(18.57f / s, 13.96f / s, 0.0f);
	glVertex3f(20.89f / s, 25.45f / s, 0.0f);
	glColor3f(0.36f, 0.54f, 0.64f);
	glVertex3f(8.70f / s, 19.78f / s, 0.0f);

	glVertex3f(1.26f / s, 11.84f / s, 0.0f);
	glVertex3f(-11.94f / s, -7.06f / s, 0.0f);
	//glVertex3f(18.57f / s, 13.96f / s, 0.0f);
	glVertex3f(9.07f / s, -6.12f / s, 0.0f);

	glEnd();

	//right wing
	if (fly_flag11)
		glRotatef(lw11Angle, 1, 0, 0);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3f(-12.39f / s, 0.0f / s, 0.0f);
	glVertex3f(1.90f / s, -6.41f / s, 0.0f);
	glVertex3f(-8.1f / s, 3.73f / s, 0.0f);
	glVertex3f(-18.88f / s, 11.41f / s, 0.0f);

	glVertex3f(-32.03f / s, 20.34f / s, 0.0f);
	glColor3f(0.36f, 0.54f, 0.64f);
	glVertex3f(-30.4f / s, 11.52f / s, 0.0f);
	glVertex3f(-22.94f / s, 2.32f / s, 0.0f);
	glVertex3f(-13.36f / s, -7.73f / s, 0.0f);
	glVertex3f(1.90f / s, -6.41f / s, 0.0f);
	glEnd();



	if (x11Move >= -5.0f)
	{
		x11Move += 0.0023;
	}

	// bird 1
	glLoadIdentity();
	glTranslatef(-4.0f, 3.2f, -10.0f);
	glTranslatef(x11Move, 3.2f, -11.0f);

	glBegin(GL_TRIANGLES);
	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, 0.2f, 0.0f);
	glVertex3f(-0.1f, 0.05f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.3f, 0.0f);
	glVertex3f(-0.2f, -0.1f, 0.0f);
	glEnd();

	// bird 2
	glLoadIdentity();
	glTranslatef(-2.0f, 5.2f, -10.0f);
	glTranslatef(x11Move, 3.2f, -11.0f);

	glBegin(GL_TRIANGLES);
	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, 0.2f, 0.0f);
	glVertex3f(-0.1f, 0.05f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.3f, 0.0f);
	glVertex3f(-0.2f, -0.1f, 0.0f);
	glEnd();

	// bird 3
	glLoadIdentity();
	glTranslatef(-3.0f, 1.8f, -10.0f);
	glTranslatef(-x11Move + 0.5, 3.2f, -11.0f);

	glBegin(GL_TRIANGLES);
	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, 0.2f, 0.0f);
	glVertex3f(-0.1f, 0.05f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.5f, 0.3f, 0.0f);
	glVertex3f(-0.2f, -0.1f, 0.0f);
	glEnd();




}

void draw_ravana_palace11(void)
{
	glTranslatef(45.0f / s, 15.0f / s, 0.0f);
	glScalef(0.47f, 0.47f, 0.0f);

	// p4 - refer the pic in the code folder
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(1.0f, 0.6f, 0.2f);	//bhagva
	glVertex3f(70.8 / s, -13.97f / s, 0.0f);
	glVertex3f(26.8 / s, 6.11f / s, 0.0f);
	glVertex3f(-67.9 / s, -11.2f / s, 0.0f);
	glVertex3f(-38.5 / s, -47.25f / s, 0.0f);
	glEnd();

	//s10
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f, 0.5f, 0.5f);	//gold color
	glVertex3f(-38.5 / s, -47.25f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glVertex3f(70.8 / s, -24.97f / s, 0.0f);
	glVertex3f(70.8 / s, -13.97f / s, 0.0f);
	glEnd();

	//s11
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f, 0.5f, 0.5f);	//gold color
	glVertex3f(-38.5 / s, -47.25f / s, 0.0f);
	glVertex3f(-67.9 / s, -11.2f / s, 0.0f);
	glVertex3f(-67.9 / s, -22.2f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glEnd();


	/////////////////////////////////////////////////////////////side palace code begins/////////////////////////////////
		// p3 - refer the pic in the code folder
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(1.0f, 0.6f, 0.2f);	//bhagva
	//glVertex3f(56.06 / s, 0.89f / s, 0.0f);
	//glVertex3f(20.9 / s, 16.6f / s, 0.0f);
	//glVertex3f(-43.53 / s, 2.84f / s, 0.0f);
	//glVertex3f(-21.0 / s, -19.4f / s, 0.0f);
	glVertex3f(56.06 / s, -6.89f / s, 0.0f);
	glVertex3f(20.9 / s, 10.6f / s, 0.0f);
	glVertex3f(-43.53 / s, -4.84f / s, 0.0f);
	glVertex3f(-21.0 / s, -25.4f / s, 0.0f);
	glEnd();

	//s9
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f, 0.5f, 0.5f);	//gold color
	glVertex3f(-21.0 / s, -25.4f / s, 0.0f);
	glVertex3f(-21.0 / s, -36.6f / s, 0.0f);
	glVertex3f(56.06 / s, -15.0f / s, 0.0f);
	glVertex3f(56.06 / s, -6.89f / s, 0.0f);
	glEnd();

	//s8
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-21.0 / s, -36.6f / s, 0.0f);
	glVertex3f(-43.53 / s, -12.1f / s, 0.0f);
	glVertex3f(-43.53 / s, -4.84f / s, 0.0f);
	glVertex3f(-21.0 / s, -25.4f / s, 0.0f);
	glEnd();

	// p2 - refer the pic in the code folder
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(1.0f, 0.6f, 0.2f);	//bhagva
	glVertex3f(19.46 / s, 17.8f / s, 0.0f);
	glVertex3f(-25.7 / s, 9.27f / s, 0.0f);
	glVertex3f(-13.1 / s, -0.16f / s, 0.0f);
	glVertex3f(33.4 / s, 10.0f / s, 0.0f);
	glEnd();

	//s7
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f, 0.5f, 0.5f);	//gold color
	glVertex3f(-13.3 / s, -0.16f / s, 0.0f);
	glVertex3f(-13.3 / s, -15.7f / s, 0.0f);
	glVertex3f(33.4 / s, -5.3f / s, 0.0f);
	glVertex3f(33.4 / s, 9.9f / s, 0.0f);
	glEnd();

	//s6
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f, 0.5f, 0.5f);	//gold color
	glVertex3f(-25.7 / s, 9.27f / s, 0.0f);
	glVertex3f(-25.7 / s, -6.32f / s, 0.0f);
	glVertex3f(-13.3 / s, -15.7f / s, 0.0f);
	glVertex3f(-13.3 / s, -0.16f / s, 0.0f);
	glEnd();


	// S1 - refer the pic in the code folder
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.5f, 0.5f, 0.5f);	//gold color
	glVertex3f(-12.85 / s, 11.06f / s, 0.0f);
	glVertex3f(1.13 / s, 3.25f / s, 0.0f);
	glVertex3f(1.13 / s, 7.07f / s, 0.0f);
	glVertex3f(-12.85 / s, 15.54f / s, 0.0f);

	glEnd();

	// S2 - refer the pic in the code folder
	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(1.13 / s, 7.07f / s, 0.0f);
	glVertex3f(1.13 / s, 3.25f / s, 0.0f);
	glVertex3f(24.4 / s, 8.21f / s, 0.0f);
	glVertex3f(24.4 / s, 12.28f / s, 0.0f);
	glEnd();

	//p1
	glColor3f(1.0f, 0.6f, 0.2f);	//bhagva
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-12.85 / s, 15.54f / s, 0.0f);
	glVertex3f(1.13 / s, 7.07f / s, 0.0f);
	glVertex3f(24.4 / s, 12.28f / s, 0.0f);
	glVertex3f(10.5 / s, 19.4f / s, 0.0f);
	glEnd();

	//s3
	glColor3f(0.5f, 0.5f, 0.5f);	//gold color
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(2.8 / s, 11.39f / s, 0.0f);
	glVertex3f(-4.0 / s, 16.59f / s, 0.0f);
	glVertex3f(-4.8 / s, 12.69f / s, 0.0f);
	glVertex3f(5.45 / s, 9.92f / s, 0.0f);
	glVertex3f(15.7 / s, 12.0f / s, 0.0f);
	glVertex3f(16.2 / s, 15.7f / s, 0.0f);
	glVertex3f(9.7 / s, 13.6f / s, 0.0f);
	glVertex3f(2.1 / s, 13.7f / s, 0.0f);
	glVertex3f(-4.0 / s, 16.59f / s, 0.0f);
	glEnd();

	//s4 
	glColor3f(0.5f, 0.5f, 0.5f);	//gold color
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(6.2 / s, 18.7f / s, 0.0f);
	glVertex3f(-1.9 / s, 24.0f / s, 0.0f);
	glVertex3f(-1.9 / s, 16.8f / s, 0.0f);
	glVertex3f(5.2 / s, 15.29f / s, 0.0f);
	glVertex3f(13.7 / s, 17.1f / s, 0.0f);
	glVertex3f(13.7 / s, 23.7f / s, 0.0f);
	glVertex3f(5.6 / s, 23.0f / s, 0.0f);
	glVertex3f(-1.9 / s, 24.0f / s, 0.0f);
	glEnd();

	//s5
	glColor3f(1.0f, 0.0f, 0.0f);	//red color
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(6.3 / s, 28.6f / s, 0.0f);
	glVertex3f(-6.1 / s, 27.8f / s, 0.0f);
	glVertex3f(-1.9 / s, 24.0f / s, 0.0f);
	glVertex3f(5.6 / s, 23.0f / s, 0.0f);
	glVertex3f(13.7 / s, 23.7f / s, 0.0f);
	glVertex3f(19.2 / s, 27.3f / s, 0.0f);
	glVertex3f(6.7 / s, 41.3f / s, 0.0f);	// top point
	glVertex3f(-6.1 / s, 27.8f / s, 0.0f);
	glEnd();
	//////////////////////////////////////////////////////////////////////////////
		//s12

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(31.2 / s, -25.0f / s, 0.0f);
	glVertex3f(17.9 / s, -29.6f / s, 0.0f);
	glVertex3f(24.89 / s, -34.21f / s, 0.0f);
	glVertex3f(38.89 / s, -29.73f / s, 0.0f);

	glEnd();

	//s13

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.6f, 0.2f);	//bhagva

	glVertex3f(17.9 / s, -29.6f / s, 0.0f);
	glVertex3f(17.9 / s, -40.73f / s, 0.0f);
	glVertex3f(24.89 / s, -45.21f / s, 0.0f);
	glVertex3f(24.89 / s, -34.21f / s, 0.0f);


	glEnd();

	//s15

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.6f, 0.2f);	//bhagva

	glVertex3f(24.89 / s, -45.21f / s, 0.0f);
	glVertex3f(24.89 / s, -34.21f / s, 0.0f);
	glVertex3f(41.9 / s, -60.21f / s, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(24.89 / s, -34.21f / s, 0.0f);
	glVertex3f(41.9 / s, -60.21f / s, 0.0f);
	glVertex3f(54.67 / s, -55.75f / s, 0.0f);
	glVertex3f(38.89 / s, -29.73f / s, 0.0f);
	glEnd();


	//front left tomb
	//right wall
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);	//gold color
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glVertex3f(-32.95 / s, -57.95f / s, 0.0f);
	glVertex3f(-32.95 / s, 34.95f / s, 0.0f);

	glEnd();

	//left wall
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);	//gold color
	glVertex3f(-41.82 / s, -54.95f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-41.82 / s, 37.95f / s, 0.0f);
	glEnd();

	//top arch left triangle
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-41.82 / s, 37.95f / s, 0.0f);
	glVertex3f(-38.7 / s, 50.95f / s, 0.0f);
	glEnd();

	//top arch right triangle
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-32.95 / s, 34.95f / s, 0.0f);
	glVertex3f(-38.7 / s, 50.95f / s, 0.0f);
	glEnd();



	//front right tomb
	// 
	glTranslatef(104.0f / s, 33.0f / s, 0.0f);

	//right wall
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);	//gold color
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glVertex3f(-32.95 / s, -57.95f / s, 0.0f);
	glVertex3f(-32.95 / s, 34.95f / s, 0.0f);

	glEnd();

	//left wall
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);	//gold color
	glVertex3f(-41.82 / s, -54.95f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-41.82 / s, 37.95f / s, 0.0f);
	glEnd();

	//top arch left triangle
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-41.82 / s, 37.95f / s, 0.0f);
	glVertex3f(-38.7 / s, 50.95f / s, 0.0f);
	glEnd();

	//top arch right triangle
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-32.95 / s, 34.95f / s, 0.0f);
	glVertex3f(-38.7 / s, 50.95f / s, 0.0f);
	glEnd();

	//rear right tomb
// 
	glTranslatef(-45.0f / s, 25.0f / s, 0.0f);
	glScalef(1.0f, 0.8f, 0.0f);
	//right wall
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);	//gold color
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glVertex3f(-32.95 / s, -57.95f / s, 0.0f);
	glVertex3f(-32.95 / s, 34.95f / s, 0.0f);

	glEnd();

	//left wall
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);	//gold color
	glVertex3f(-41.82 / s, -54.95f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-41.82 / s, 37.95f / s, 0.0f);
	glEnd();

	//top arch left triangle
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-41.82 / s, 37.95f / s, 0.0f);
	glVertex3f(-38.7 / s, 50.95f / s, 0.0f);
	glEnd();

	//top arch right triangle
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-32.95 / s, 34.95f / s, 0.0f);
	glVertex3f(-38.7 / s, 50.95f / s, 0.0f);
	glEnd();

	//////

	//rear left tomb
	// 
	glTranslatef(-85.0f / s, -33.0f / s, 0.0f);
	//glScalef(1.0f, 1.6f, 0.0f);
	//right wall
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);	//gold color
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glVertex3f(-32.95 / s, -57.95f / s, 0.0f);
	glVertex3f(-32.95 / s, 34.95f / s, 0.0f);

	glEnd();

	//left wall
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);	//gold color
	glVertex3f(-41.82 / s, -54.95f / s, 0.0f);
	glVertex3f(-38.5 / s, -59.15f / s, 0.0f);
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-41.82 / s, 37.95f / s, 0.0f);
	glEnd();

	//top arch left triangle
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-41.82 / s, 37.95f / s, 0.0f);
	glVertex3f(-38.7 / s, 50.95f / s, 0.0f);
	glEnd();

	//top arch right triangle
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);	//red
	glVertex3f(-38.5 / s, 32.95f / s, 0.0f);
	glVertex3f(-32.95 / s, 34.95f / s, 0.0f);
	glVertex3f(-38.7 / s, 50.95f / s, 0.0f);
	glEnd();

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

	//close the log file
	if (gpFILE)
	{
		fprintf(gpFILE, "Program Ended Successfully...\n");
		fclose(gpFILE);
		gpFILE = NULL;
	}
}
