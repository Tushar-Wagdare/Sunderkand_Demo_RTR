#pragma once

#include <windows.h>
#include <gl/GL.h>  // OpenGL Header Files
#include <gl/GLU.h> // OpenGL Graphics Library Utility
#include <math.h>   // For sin and cos

//#include "..\SK_Chaupai_1\hanuman.h"
//#include "..\SK_Chaupai_2\hanuman.h"


#define PI 3.14159265359
GLint gCount      = 0;
GLfloat s         = 100.0f;


//Demo Variables
GLint main_sceen  = 1;
GLint short_sceen = 0;


// Structure Declaration For Circle Attributes
struct Center
{
	float xCoordinate;
	float yCoordinate;
};

struct Radius
{
	float xAxis;
	float yAxis;
};

struct Color
{
	float r;
	float g;
	float b;
};

struct Size
{
	int point_size;
	int line_width;
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
	struct Radius radius;
	struct Angle angle;
	struct Size size;
};


void pss1_DrawCircle(GLenum PrimitiveType, struct Circle circle)
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

			a = cos(f) * circle.radius.xAxis;
			b = sin(f) * circle.radius.yAxis;

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

			a = cos(f) * circle.radius.xAxis;
			b = sin(f) * circle.radius.yAxis;

			glColor3f(circle.color.r, circle.color.g, circle.color.b);
			glVertex3f(a + circle.center.xCoordinate, b + circle.center.yCoordinate, 0.0f);
		}
		glEnd();
		break;


	case GL_LINE_STRIP:
		glLineWidth(circle.size.line_width);
		glBegin(GL_LINE_STRIP);
		for (int i = circle.angle.from; i < circle.angle.to; i++)
		{
			f = (i) * (PI / 180);

			a = cos(f) * (circle.radius.xAxis);
			b = sin(f) * (circle.radius.yAxis);

			glColor3f(circle.color.r, circle.color.g, circle.color.b);
			glVertex3f(a + circle.center.xCoordinate, b + circle.center.yCoordinate, 0.0f);
		}
		glEnd();
		break;


	default:
		break;
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

			a = cos(f) * circle.radius.xAxis;
			b = sin(f) * circle.radius.yAxis;

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

			a = cos(f) * circle.radius.xAxis;
			b = sin(f) * circle.radius.yAxis;

			glColor3f(circle.color.r, circle.color.g, circle.color.b);
			glVertex3f(a + circle.center.xCoordinate, b + circle.center.yCoordinate, 0.0f);
		}
		glEnd();
		break;


	case GL_LINE_STRIP:
		glLineWidth(circle.size.line_width);
		glBegin(GL_LINE_STRIP);
		for (int i = circle.angle.from; i < circle.angle.to; i++)
		{
			f = (i) * (PI / 180);

			a = cos(f) * (circle.radius.xAxis);
			b = sin(f) * (circle.radius.yAxis);

			glColor3f(circle.color.r, circle.color.g, circle.color.b);
			glVertex3f(a + circle.center.xCoordinate, b + circle.center.yCoordinate, 0.0f);
		}
		glEnd();
		break;


	default:
		break;
	}

}

void tw_DrawCircle(GLenum PrimitiveType, struct Circle circle)
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

			a = cos(f) * circle.radius.xAxis;
			b = sin(f) * circle.radius.yAxis;

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

			a = cos(f) * circle.radius.xAxis;
			b = sin(f) * circle.radius.yAxis;

			glColor3f(circle.color.r, circle.color.g, circle.color.b);
			glVertex3f(a + circle.center.xCoordinate, b + circle.center.yCoordinate, 0.0f);
		}
		glEnd();
		break;


	case GL_LINE_STRIP:
		glLineWidth(circle.size.line_width);
		glBegin(GL_LINE_STRIP);
		for (int i = circle.angle.from; i < circle.angle.to; i++)
		{
			f = (i) * (PI / 180);

			a = cos(f) * (circle.radius.xAxis);
			b = sin(f) * (circle.radius.yAxis);

			glColor3f(circle.color.r, circle.color.g, circle.color.b);
			glVertex3f(a + circle.center.xCoordinate, b + circle.center.yCoordinate, 0.0f);
		}
		glEnd();
		break;


	default:
		break;
	}
}




//************************* CleanedUp Main C File ***************************
//###############################################################
//Chaupai 03 #defines
#define up_dir 1
#define dn_dir 2
int sph_dir                      = 1;
#define up 1
#define down 2
int dir                          = up;
#define up 1
#define down 2
int dir1                         = up;
#define up11 1
#define down11 2
int dir11                        = up11;
GLfloat x11Move                  = 0.0f;

//Chaupai 3 Variables
//***********************************Bird1******************************
GLfloat rwAngle                  = 360.0f, lwAngle = 0.0f, body_angle = 0.0f, lw11Angle = 0.0f;
GLfloat y_translate              = 1.0f;//-0.0659f;
GLfloat x_translate              = -1.55f;
GLfloat x11_translate            = -1.55f;
GLfloat xScale                   = 0.6;
GLfloat yScale                   = 0.6;
GLfloat zScale                   = 0.6;
int scene                        = 1;
int fly_flag                     = 1;
int fly_flag11                   = 1;
//*********************************** Bird2 ******************************
GLfloat rwAngle1                 = 360.0f, lwAngle1 = 0.0f, body_angle1 = 0.0f;
GLfloat y_translate1             = 1.2f;//-0.0659f;
GLfloat x_translate1             = -1.55f; //kuthun translate honar te kalta
GLfloat xScale1                  = 0.8;
GLfloat yScale1                  = 0.8;
GLfloat zScale1                  = 0.8;
int scene1                       = 1;
int fly_flag1                    = 1;
GLfloat x1_translate             = 0.0f;
GLfloat y1_translate             = 0.0f;
GLfloat langle                   = 0.0f;
BOOL lRotate                     = FALSE;
GLfloat h_translate              = 3.0f;
GLfloat s_translate              = -0.05f;
GLfloat xShadow                  = 0.2f;
GLfloat yShadow                  = 0.2f;
GLfloat zShadow                  = 0.2f;
BOOL vbResetVariables            = TRUE;
GLfloat vb2                      = 0.0f;
BOOL hanumanKilledSimhika        = FALSE;
GLfloat left_leg_rotate_simhika  = TRUE;
GLfloat right_leg_rotate_simhika = TRUE;
GLfloat xSimhika                 = 0.0f;
GLfloat ySimhika                 = 0.0f;
GLfloat zSimhika                 = -3.5f;
GLfloat simhika_xScale           = 0.0f;
GLfloat simhika_yScale           = 0.0f;
GLfloat simhika_zScale           = 0.0f;

//Chaupai 04
BOOL ab_resetVariables           = TRUE;
GLfloat x1Bird                   = -1.54f;
GLfloat y1Bird                   = -0.1f;
GLfloat hScale                   = 0.4;
GLfloat sScale                   = 0.4;
GLfloat pScale                   = 0.4;
GLfloat x1Scale                  = 0.6f;
GLfloat y1Scale                  = 0.6f;
GLfloat z1Scale                  = 0.6f;
GLfloat z2_translate             = -3.5f;
GLfloat y2_translate             = 0.0f;
GLfloat talvar_rotate            = 0.0f;
BOOL bTalvar_rotate              = FALSE;
GLfloat ab_tangle                = 0.0f;
GLfloat ab_rangle                = 0.0f;
GLfloat ab_xMove                 = 0.0f;
GLfloat ab_xLanka                = 1.0f;
GLfloat ab_yLanka                = 1.0f;
GLfloat ab_Xtranslate            = -0.2f;
GLfloat ab_Ytranslate            = -0.2f;
GLfloat ab_Xscale                = 0.3f;
GLfloat ab_Yscale                = 0.3f;
GLfloat ab_xRotate               = 0.0f;
GLfloat abxScaleWave             = 1.0f;
GLfloat abyScaleWave             = 1.0f;
BOOL abWaves                     = TRUE;
GLfloat x_sph_trnslate, y_sph_trnslate;

//Chaupai 1
GLfloat yMainakTranslate         = -1.5f;
GLfloat mn_xMove                 = 0.0f;
BOOL pss1_bHanuman               = FALSE;
GLfloat arrow_y_translate        = -1.7f;
GLfloat arrow_z_translate        = -3.0f;
GLfloat arrow_x_scale            = 1.0f;
GLfloat arrow_y_scale            = 1.0f;
GLfloat arrow_z_scale            = 1.0f;
GLfloat shadow_y_translate       = -1.7f;
GLfloat shadow_z_translate       = -3.0f;
GLfloat shadow_x_scale           = 1.0f;
GLfloat shadow_y_scale           = 1.0f;
GLfloat shadow_z_scale           = 1.0f;
BOOL sps1_scene                  = FALSE;
GLfloat xScaleWave               = -1.2f;
GLfloat yScaleWave               = 0.0f;
BOOL bWaves                      = TRUE;


//Time
SYSTEMTIME localTime             = { sizeof(SYSTEMTIME) };
SYSTEMTIME currentTime           = { sizeof(SYSTEMTIME) };
GLdouble gTimeInSeconds          = 0.000;




// For PlaySound()
//PLAYSOUND BOOLS (Chaupai-1)
BOOL ch1_bScene1                 = TRUE;
BOOL ch1_bScene2                 = TRUE;
BOOL ch1_bScene3                 = TRUE;
BOOL ch1_bScene4                 = TRUE;
//PlaySound Chaupai 2
BOOL ch2_part1                   = TRUE;
BOOL ch2_part2                   = TRUE;
//PlaySound Chaupai 3
BOOL ch3_part1                   = TRUE;
BOOL ch3_part2                   = TRUE;
BOOL ch3_part3                   = TRUE;
//PlaySound Chaupai 4
BOOL ch4_part1                   = TRUE;
BOOL ch4_part2                   = TRUE;
BOOL ch4_part3                   = TRUE;


// PlaySound Functions

void ch1_bScene1_sound(void)
{
	// PlaySound Using Resource
	PlaySound(MAKEINTRESOURCE(CH_1_S_1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	ch1_bScene1 = FALSE;
}
void ch1_bScene2_sound(void)
{
	// PlaySound Using Resource
	PlaySound(MAKEINTRESOURCE(CH_1_S_2), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	ch1_bScene2 = FALSE;
}
void ch1_bScene3_sound(void)
{
	// PlaySound Using Resource
	PlaySound(MAKEINTRESOURCE(CH_1_S_3), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	ch1_bScene3 = FALSE;
}
void ch1_bScene4_sound(void)
{
	// PlaySound Using Resource
	PlaySound(MAKEINTRESOURCE(CH_1_S_4), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	ch1_bScene4 = FALSE;
}
void ch2_part2_sound(void)
{
	PlaySound(MAKEINTRESOURCE(CH_2_P_2), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	ch2_part2 = FALSE;
}
void ch2_part1_sound(void)
{
	PlaySound(MAKEINTRESOURCE(CH_2_P_1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	ch2_part1 = FALSE;
}
void ch3_part1_sound(void)
{
	PlaySound(MAKEINTRESOURCE(CH_3_S_1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	ch3_part1 = FALSE;
}
void ch3_part2_sound(void)
{
	PlaySound(MAKEINTRESOURCE(CH_3_S_2), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	ch3_part2 = FALSE;
}
void ch3_part3_sound(void)
{
	PlaySound(MAKEINTRESOURCE(CH_3_S_3), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	ch3_part3 = FALSE;
}
void ch4_part1_sound(void)
{
	PlaySound(MAKEINTRESOURCE(CH_4_S_1), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	ch4_part1 = FALSE;
}
void ch4_part2_sound(void)
{
	PlaySound(MAKEINTRESOURCE(CH_4_S_2), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	ch4_part2 = FALSE;
}
void ch4_part3_sound(void)
{
	PlaySound(MAKEINTRESOURCE(CH_4_S_3), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	ch4_part3 = FALSE;
}


