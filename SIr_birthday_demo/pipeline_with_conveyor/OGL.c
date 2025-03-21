/* Om Shree Ganeshaya namaha */
//windows header files
#include<windows.h>
#include<windowsx.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//OpenGL header files
#include<gl/GL.h>
#include<gl/GLU.h>	
#include"OGL.h"
#include "camera.h"
#include "Headers/utilities.h"
#include"Headers/ourFunctions.h"
//Macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600
//link with OpenGL librarys
#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "GLU32.lib")
//Used For PlaySound (link)
#pragma comment(lib, "Winmm.lib")
//float x;
BOOL isMouseDragging = FALSE;

//global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

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
	int iResult       = 0;
	BOOL bDone        = FALSE;

	int x_wnd_TopLeft = 0;
	int y_wnd_TopLeft = 0;
	int x_size        = 800;	
	int y_size        = 600;	

	// code
	gpFILE = fopen("Log.txt", "w");
	if (gpFILE == NULL)
	{
		MessageBox(NULL, TEXT("Log File Cannot Be Opened"), TEXT("ERROR"), MB_OK | MB_ICONERROR);
		exit(0);
	}
	fprintf(gpFILE, "Program started successfully!...\n");

	// WNDCLASSEX initialization
	wndclass.cbSize        = sizeof(WNDCLASSEX);
	wndclass.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	
	wndclass.cbClsExtra    = 0;
	wndclass.cbWndExtra    = 0;
	wndclass.lpfnWndProc   = WndProc;
	wndclass.hInstance     = hInstance;
	wndclass.hbrBackground = (HBRUSH) (GetStockObject(BLACK_BRUSH));
	wndclass.hIcon         = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
	wndclass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName  = NULL;
	wndclass.hIconSm       = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));


	// Register WNDCLASSEX
	RegisterClassEx(&wndclass);


	int screen_x_mid = (GetSystemMetrics(SM_CXSCREEN)) / 2;
	int screen_y_mid = (GetSystemMetrics(SM_CYSCREEN)) / 2;
	x_wnd_TopLeft    = screen_x_mid - (x_size / 2);
	y_wnd_TopLeft    = screen_y_mid - (y_size / 2);

	//Create Window
	hwnd = CreateWindowEx(WS_EX_APPWINDOW,
		szAppName,
		TEXT("SREEJITH PILLAI"),
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE, 
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
	}
	ShowWindow(hwnd, iCmdShow);		
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);


//---------------------------------------------------------------------------------------------------------------//
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

				//if one second has passed, update the fps value and res
				if (elapsedTime >= 0.5)
				{
					fps = frameCount / elapsedTime;
					frameCount = 0.0;
					QueryPerformanceCounter(&startCounter);
				}
				sprintf(titleBuffer, "FPS:%.2f | W(%.2f)xH(%.2f) | MX(%.2f), MY(%.2f) | CFX(%.2f), CFY(%.2f), CFZ(%.2f) | CY(%.2f), CP(%.2f) | CPX(%.2f), CPY(%.2f), CPZ(%.2f)", fps, canvas.x, canvas.y, mouse.x, mouse.y, camera.front.x, camera.front.y,camera.front.z, camera.yaw,camera.pitch, camera.position.x, camera.position.y, camera.position.z);
				SetWindowText(hwnd, titleBuffer);
			}
		}
	}

	uninitialize();
	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//function declarations
	void ToggleFullscreen(void);
	void resize(int, int);
	// code
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0); 
		break;
	case WM_SETFOCUS:
		gbActive = TRUE;
		break;
	case WM_KILLFOCUS:
		gbActive = FALSE;
		break;
	case WM_SIZE:
		canvas.x = LOWORD(lParam);
		canvas.y = HIWORD(lParam);
		resize(canvas.x, canvas.y);
		break;
	case WM_ERASEBKGND:
		return(0);

	case WM_LBUTTONDOWN:
		isMouseDragging = TRUE;
		lastMouse.y = GET_Y_LPARAM(lParam);
		lastMouse.x = GET_X_LPARAM(lParam);
		SetCapture(ghwnd);
		break;

	//-----------------------------------------------------------------------------//
	case WM_MOUSEMOVE:
		if (isMouseDragging)
		{
			//mouse.x = LOWORD(lParam) / canvas.x;// Normalization 
			//mouse.x = (mouse.x * 2.0f) - 1.0f;// Range Remapping
			mouse.x = GET_X_LPARAM(lParam);

			//mouse.y = HIWORD(lParam) / canvas.y;
			//mouse.y = -((mouse.y * 2.0f) - 1.0f);
			mouse.y = GET_Y_LPARAM(lParam);

			delta.x = mouse.x - lastMouse.x;
			delta.y = mouse.y - lastMouse.y;

			camera.yaw   += delta.x * 0.01f;
			camera.pitch -= delta.y * 0.01f;

			if (camera.pitch > 89.0f)
			{
				camera.pitch = 89.0f;
			}
			if (camera.pitch < -89.0f)
			{
				camera.pitch = -89.0f;
			}

			camera.front.x = cos(toRadians(camera.yaw)) * cos(toRadians(camera.pitch));
			camera.front.y = sin(toRadians(camera.pitch));
			camera.front.z = sin(toRadians(camera.yaw)) * cos(toRadians(camera.pitch));
			NormalizeVec3f(&camera.front);
			camera.up = (Vec3f){ 0.0f,1.0f,0.0f };
			/*camera.front.x = cos(camera.yaw) * cos((camera.pitch));
			camera.front.y = sin((camera.pitch));
			camera.front.z = sin((camera.yaw)) * cos((camera.pitch));*/
		}
		break;

	case WM_LBUTTONUP:
		isMouseDragging = FALSE;
		ReleaseCapture();
		break;


	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_ESCAPE:		
			DestroyWindow(hwnd);
			break;

		case VK_SPACE:
			fpp_scene_count++;
			resize(canvas.x, canvas.y);
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

		case 'W':
		case 'w':
			camera.position.x += camera.front.x;
			camera.position.y += camera.front.y;
			camera.position.z += camera.front.z;
			break;

		case 'S':
		case 's':
			camera.position.x -= camera.front.x;
			camera.position.y -= camera.front.y;
			camera.position.z -= camera.front.z;
			break;

		case 'A':
		case 'a':
			camera.right = cross(camera.front, camera.up);
			camera.position.x -= camera.right.x;
			camera.position.y -= camera.right.y;
			camera.position.z -= camera.right.z;
			break;

		case 'D':
		case 'd':
			camera.right = cross(camera.front, camera.up);
			camera.position.x += camera.right.x;
			camera.position.y += camera.right.y;
			camera.position.z += camera.right.z;
			break;

		case 'N':
		case 'n':
			tw_count_for_color = 0;
			tw_scene++;
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
	default:
		break;
	}

	return(DefWindowProc(hwnd, iMsg, wParam, lParam)); 
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
	BOOL loadGLTexture(GLuint*, TCHAR[]);
	BOOL bResult;

	// code
	//step - 1 initialize pixel format descriptor
	PIXELFORMATDESCRIPTOR pfd;
	int iPixelFormatIndex = 0;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
	// initialization of PIXELFORMATDESCRIPTOR
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;	
	pfd.iPixelType = PFD_TYPE_RGBA;	
	pfd.cColorBits = 32;	
	pfd.cRedBits = 8;	
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
	if (iPixelFormatIndex == 0)	
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

	if (wglMakeCurrent(ghdc, ghrc) == FALSE)
	{
		fprintf(gpFILE, "wglMakeCurrent function failed\n");
		return(-5);
	}

	//Enabling Depth//Second Change
	glShadeModel(GL_SMOOTH); 
	glClearDepth(1.0f);     
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);  
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 


	//set the clear colour of window to blue
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	
	
	//Initialise Quadric
	quadric = gluNewQuadric();
	//Initialize Camera
	camera = createCamera((Vec3f) { 0.0f, 0.0f, 100.0f }, (Vec3f) { 0.0f, 0.0f, -0.1f }, (Vec3f) { 0.0f, 1.0f, 0.0f }, 270.0f, 0.0f, 0.0f);

	//Loading images to create texture
	bResult = loadGLTexture(&texture_astro, MAKEINTRESOURCE(MYIMAGE_ASTROMEDICOMP_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Astro Texture Failed\n");
		return(-6);
	}

	bResult = loadGLTexture(&texture_ortho, MAKEINTRESOURCE(MYIMAGE_ORTHO_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Ortho Texture Failed\n");
		return(-7);
	}

	bResult = loadGLTexture(&texture_techused, MAKEINTRESOURCE(MYIMAGE_TECHUSED_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of TechUsed Texture Failed\n");
		return(-8);
	}

	bResult = loadGLTexture(&texture_gmem, MAKEINTRESOURCE(MYIMAGE_GROUPMEMBERS_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of GroupMembers Texture Failed\n");
		return(-9);
	}

	bResult = loadGLTexture(&texture_gl, MAKEINTRESOURCE(MYIMAGE_GROUPLEADER_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Ortho Texture Failed\n");
		return(-10);
	}

	bResult = loadGLTexture(&texture_sir, MAKEINTRESOURCE(MYIMAGE_SIR_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Ortho Texture Failed\n");
		return(-11);
	}

	bResult = loadGLTexture(&texture_madam, MAKEINTRESOURCE(MYIMAGE_MADAM_BITMAP));
	if (bResult == FALSE)
	{
		fprintf(gpFILE, "Loading of Ortho Texture Failed\n");
		return(-12);
	}

	//Tell openGL to enable the texture
	glEnable(GL_TEXTURE_2D);

	resize(WIN_WIDTH, WIN_HEIGHT);
	// HERE OpenGL STARTS !!! 
	return(0);
}

BOOL loadGLTexture(GLuint* texture, TCHAR imageResourceID[])
{
	//Local variable declarations
	HBITMAP hBitmap = NULL;
	BITMAP bmp;

	hBitmap = (HBITMAP)LoadImage(GetModuleHandle(NULL), imageResourceID, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION); //DIB > Device Independent Bitmap

	if (hBitmap == NULL)
	{
		fprintf(gpFILE, "Load Image Failed\n");
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

	fprintf(gpFILE, "%ld, %ld\n", bmp.bmWidth, bmp.bmHeight);
	//unbind
	glBindTexture(GL_TEXTURE_2D, 0);

	//Delete image resource
	DeleteObject(hBitmap);
	hBitmap = NULL;

	return(TRUE);

}

void resize(int width, int height)
{
	// code
	if (height <= 0)
		height = 1;

	glMatrixMode(GL_PROJECTION);	
	glLoadIdentity();	

	glViewport(0, 0, (GLsizei)width, (GLsizei)height);	

	
	if (fpp_scene_count == 0 || fpp_scene_count == 1 || fpp_scene_count == 7 || fpp_scene_count == 8 || fpp_scene_count == 9 || fpp_scene_count == 10 || fpp_scene_count == 11)
	{
		if (canvas.x <= canvas.y)
		{
			glOrtho(-100.0f,
				100.0f,
				-100.0f * ((GLfloat)canvas.y / (GLfloat)canvas.x),
				100.0f * ((GLfloat)canvas.y / (GLfloat)canvas.x),
				-100.0f,
				100.0f);
		}
		else
		{
			glOrtho(-100.0f * ((GLfloat)canvas.x / (GLfloat)canvas.y),
				100.0f * ((GLfloat)canvas.x / (GLfloat)canvas.y),
				-100.0f,
				100.0f,
				-100.0f,
				100.0f);
		}
	}
	else 
	{
		gluPerspective(45.0f, (GLfloat)canvas.x / (GLfloat)canvas.y, 0.1f, 1000.0f);
	}

}

void display(void)
{
	void floor_blue(void);
	// code
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();	
	glTranslatef(0.0f, 0.0f, -3.0f);	


	switch (fpp_scene_count)
	{

	case 0:
		AstroMediComp();
		break;

	case 1:
		Ortho();
		break;

	case 2:
		vb_Factory();

		if (vb_x_move < 0.4)
		{
			vb_x_move -= 0.003f;
		}
		else
		{
			vb_z_tranlsate -= 0.05f;
		}
		glLoadIdentity();
		glTranslatef(vb_x_move, -0.63f, -1.4f);
		glScalef(0.01f, 0.01f, 0.01f);
		glScalef(2.7f, 2.2f, 0.0f);
		drawCloud1();


		glLoadIdentity();
		glTranslatef(-vb_x_move, -0.68f, -1.4f);
		glScalef(0.01f, 0.01f, 0.01f);
		glScalef(5.7f, 2.7f, 0.0f);
		drawCloud1();
		break;

	case 3:
		//vertex_fetch_stage();
		vertex_fetch_stage_1();
		break;

	case 4:
		scene_pipeline_stage();
		break;

	case 5:
		switch (tw_scene)
		{
		case 0:
			//------------------------ 1st Scene --------------------------//
			//------- Buffer Sceen ------//
			// bg green colour
			glTranslatef(0.0f, 0.0f, -5.0f);
			glBegin(GL_QUADS);
			glColor3f(0.0f, 0.517f, 0.568f);
			glVertex3f(-20.5f, 20.0f, 0.0f);
			glVertex3f(-20.5f, -20.0f, 0.0f);
			glVertex3f(20.5f, -20.0f, 0.0f);
			glVertex3f(20.5f, 20.0f, 0.0f);
			glEnd();

			//floor
			vertex_fetch_stage_2();
			floor_blue1();
			fillBuffers();
			drawPipe();
			break;

		case 1:
			//------------------------- 2nd Scene --------------------------//
			//------ Lazer Gun -------//

			SirBackView();

			updateColors();
			screen1();
			turret1();
			turret2();
			turret3();
			break;

		case 2:
			if (camera.position.z >= -13.0f)
			{
				screen2();
			}
			else
			{
				SirBackView();
			}
			break;


		default:
			break;
		}
		break;

	case 6:
		//Function Call
		drawClassroom1();
		Students();
		watch();
		ceilingFan();
		drawCloud();
		break;

	case 7:
		TechUsed();
		break;

	case 8:
		GroupMem();
		break;

	case 9:
		GroupLead();
		break;

	case 10:
		Sir();
		break;

	case 11:
		Madam();
		break;

	default:
		break;
	}
	

	SwapBuffers(ghdc);	
}

void update(void)
{
	//Function declaration
	void updateBuffers(void);

	switch (fpp_scene_count)
	{

	case 6:
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
		break;

	case 5:
		switch (tw_scene)
		{
		case 0:
			updateBuffers();
			if (tw_swapBuffers >= 180 && tw_xPipeTranslate > -0.2f)
			{
				tw_xPipeTranslate = tw_xPipeTranslate - 0.001f;
			}
			break;

		case 1:

			break;

		case 2:
			if (camera.position.z >= -13.0f)
			{
				//camera.front.x = 0.0f;
				//camera.front.y = 15.0f;
				//camera.front.z = -25.0f;

				////camera.position.x += 0.001f;
				camera.position.y = 8.0f;
				camera.position.z -= 0.05f;
			}
			else
			{
				if (tw_zTransSir >= -1.7f)
				{
				    camera.position.y = 0.0f;
					tw_zTransSir = tw_zTransSir - 0.005f;
				}
			}
			break;

		default:
			break;
		}
		break;
		

	default:
		break;
	}
}

void uninitialize(void)
{
	// function declarations
	void ToggleFullscreen(void);

	//code
	if (gbFullscreen == TRUE)
	{
		ToggleFullscreen();
		gbFullscreen = FALSE;
	}

	// make the hdc as current dc
	if (wglGetCurrentContext() == ghrc)
	{
		wglMakeCurrent(NULL, NULL);	
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

	//Delete quadric
	if (quadric)
	{
		gluDeleteQuadric(quadric);
		quadric = NULL;
	}

	// close the log file
	if (gpFILE)
	{
		fprintf(gpFILE, "Program Ended Successfully!...\n");
		fclose(gpFILE);
		gpFILE = NULL;
	}
}


