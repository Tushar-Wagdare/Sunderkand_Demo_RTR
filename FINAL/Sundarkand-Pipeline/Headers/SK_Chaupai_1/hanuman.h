#pragma once

#include <windows.h>

#define PI 3.14159265359

// Transformations
//GLfloat ps_rHead = 0.0f;
//GLfloat rrLeg = 0.0f;
//GLfloat rlLeg = 0.0f;
//GLfloat rrArm = 0.0f;
//
//BOOL hRotate = FALSE;
//BOOL lRotate = FALSE;

GLfloat cap_angle = 0.0f;
BOOL bool_tail_rotate = FALSE;
GLfloat d = 150.0f;

// Structure Declaration For Circle Attributes
//struct Center
//{
//	float xCoordinate;
//	float yCoordinate;
//};
//
//struct Radius
//{
//	float xAxis;
//	float yAxis;
//};
//
//struct Color
//{
//	float r;
//	float g;
//	float b;
//};
//
//struct Size
//{
//	int point_size;
//	int line_width;
//};
//
//struct Angle
//{
//	int from;
//	int to;
//};
//
//struct Circle
//{
//	struct Color color;
//	struct Center center;
//	struct Radius radius;
//	struct Angle angle;
//	struct Size size;
//};

//void DrawCircle(GLenum PrimitiveType, struct Circle circle)
//{
//	//*** Variable Declaration ***
//	float a, b;
//	float f;
//
//
//	switch (PrimitiveType)
//	{
//	case GL_POLYGON:
//
//		glBegin(GL_POLYGON);
//
//		for (int i = circle.angle.from; i < circle.angle.to; i++)
//		{
//			f = (i) * (PI / 180);
//
//			a = cos(f) * circle.radius.xAxis;
//			b = sin(f) * circle.radius.yAxis;
//
//			glColor3f(circle.color.r, circle.color.g, circle.color.b);
//			glVertex3f(a + circle.center.xCoordinate, b + circle.center.yCoordinate, 0.0f);
//
//		}
//		glEnd();
//
//
//		break;
//
//	case GL_POINTS:
//
//		glPointSize(circle.size.point_size);
//		glBegin(GL_POINTS);
//
//		for (int i = circle.angle.from; i < circle.angle.to; i++)
//		{
//			f = (i) * (PI / 180);
//
//			a = cos(f) * circle.radius.xAxis;
//			b = sin(f) * circle.radius.yAxis;
//
//			glColor3f(circle.color.r, circle.color.g, circle.color.b);
//			glVertex3f(a + circle.center.xCoordinate, b + circle.center.yCoordinate, 0.0f);
//
//		}
//		glEnd();
//
//
//		break;
//
//	case GL_LINE_STRIP:
//
//		glLineWidth(circle.size.line_width);
//		glBegin(GL_LINE_STRIP);
//
//		for (int i = circle.angle.from; i < circle.angle.to; i++)
//		{
//			f = (i) * (PI / 180);
//
//			a = cos(f) * (circle.radius.xAxis);
//			b = sin(f) * (circle.radius.yAxis);
//
//			glColor3f(circle.color.r, circle.color.g, circle.color.b);
//			glVertex3f(a + circle.center.xCoordinate, b + circle.center.yCoordinate, 0.0f);
//
//		}
//		glEnd();
//
//		break;
//
//	default:
//		break;
//	}
//}


void drawHanuman_chaupai_1(void)
{
	///////////////////////////////////////////////////TRANSFORMATIONS/////////////////////////////////////////////////////////
	glLoadIdentity();
	glTranslatef(0.80f, -0.25f, -1.5f);
	glScalef(0.43f, 0.43f, 0.43f);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	
	//*** Function Declarations ***
	//void DrawCircle(GLenum, struct Circle);

	GLfloat s = 100.0f;

	//glRotatef(180, 0.0f, 1.0f, 0.0f);
	//********************* HAnuman  (Right Arm) *********************************
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.55686f, 0.43529f, 0.43529f);
	glVertex3f(5.0f / s, 46.0f / s, 0.0f / s);
	glVertex3f(-2.0f / s, 46.0f / s, 0.0f / s);
	glVertex3f(7.0f / s, 39.0f / s, 0.0f / s);
	glVertex3f(-5.0f / s, 42.0f / s, 0.0f / s);
	glVertex3f(6.0f / s, 33.0f / s, 0.0f / s);
	glVertex3f(-6.0f / s, 31.0f / s, 0.0f / s);
	glVertex3f(3.0f / s, 24.0f / s, 0.0f / s);
	glVertex3f(-6.0f / s, 28.0f / s, 0.0f / s);
	glVertex3f(1.0f / s, 19.0f / s, 0.0f / s);
	glVertex3f(-10.0f / s, 19.0f / s, 0.0f / s);
	glVertex3f(-11.0f / s, 8.0f / s, 0.0f / s);
	glVertex3f(-15.0f / s, 10.0f / s, 0.0f / s);

	glEnd();

	//*********Right Arm (Hand) ************
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.55686f, 0.43529f, 0.43529f);
	glVertex3f(-14.0f / s, 7.0f / s, 0.0f / s);
	glVertex3f(-11.0f / s, 8.0f / s, 0.0f / s);
	glVertex3f(-15.0f / s, 10.0f / s, 0.0f / s);
	glVertex3f(-20.2f / s, 7.7f / s, 0.0f / s);
	glVertex3f(-20.0f / s, 6.5f / s, 0.0f / s);
	glVertex3f(-17.0f / s, 7.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, 0.6f / s, 0.0f / s);
	glVertex3f(-17.0f / s, -0.5f / s, 0.0f / s);
	glVertex3f(-16.0f / s, -0.4f / s, 0.0f / s);
	glVertex3f(-12.0f / s, 3.7f / s, 0.0f / s);
	glVertex3f(-11.0f / s, 8.0f / s, 0.0f / s);

	glEnd();

	//*** Hanuman Right arm (golden bracelate)
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.988f, 0.761f, 0.012f);
	glVertex3f(-14.4f / s, 12.6f / s, 0.0f / s);
	glVertex3f(-15.1f / s, 11.1f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 10.6f / s, 0.0f / s);
	glVertex3f(-13.7f / s, 9.2f / s, 0.0f / s);
	glVertex3f(-9.9f / s, 9.2f / s, 0.0f / s);
	glVertex3f(-10.6f / s, 7.7f / s, 0.0f / s);
	glEnd();

	//glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, -3.0f);
	//********************** Hanuman upper body (cheast) *********************************
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.77255f, 0.60392f, 0.60392f);
	glVertex3f(0.0f / s, 29.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 14.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 9.0f / s, 0.0f / s);
	glVertex3f(12.0f / s, 10.0f / s, 0.0f / s);
	glVertex3f(11.0f / s, 15.0f / s, 0.0f / s);
	glVertex3f(14.0f / s, 29.0f / s, 0.0f / s);
	glVertex3f(15.0f / s, 42.0f / s, 0.0f / s);
	glVertex3f(14.0f / s, 50.0f / s, 0.0f / s);
	glVertex3f(10.0f / s, 56.0f / s, 0.0f / s);
	glVertex3f(5.0f / s, 57.0f / s, 0.0f / s);
	glVertex3f(5.0f / s, 54.0f / s, 0.0f / s);
	glVertex3f(1.0f / s, 52.0f / s, 0.0f / s);
	glVertex3f(-3.0f / s, 50.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 49.0f / s, 0.0f / s);
	glVertex3f(-11.0f / s, 45.0f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 37.0f / s, 0.0f / s);
	glVertex3f(-11.0f / s, 25.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 14.0f / s, 0.0f / s);

	glEnd();

	//glRotatef(rHead, 0.0f, 0.0f, 1.0f);
	//*************************** Hanuman Head ****************
	//**** Face *****
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.92549f, 0.87059f, 0.87059f);
	glVertex3f(-5.0f / s, 67.0f / s, 0.0f / s);
	glVertex3f(-11.0f / s, 74.0f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 68.0f / s, 0.0f / s);
	glVertex3f(-12.0f / s, 64.0f / s, 0.0f / s);
	glVertex3f(-15.0f / s, 61.0f / s, 0.0f / s);
	glVertex3f(-15.0f / s, 57.0f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 56.0f / s, 0.0f / s);
	glVertex3f(-10.0f / s, 57.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 54.0f / s, 0.0f / s);
	glVertex3f(-6.0f / s, 49.0f / s, 0.0f / s);
	glVertex3f(-3.0f / s, 50.0f / s, 0.0f / s);
	glVertex3f(1.0f / s, 52.0f / s, 0.0f / s);
	glVertex3f(5.0f / s, 54.0f / s, 0.0f / s);
	glVertex3f(7.0f / s, 55.0f / s, 0.0f / s);
	glVertex3f(5.0f / s, 59.0f / s, 0.0f / s);
	glVertex3f(4.0f / s, 62.0f / s, 0.0f / s);
	glVertex3f(3.0f / s, 67.0f / s, 0.0f / s);
	glVertex3f(3.0f / s, 72.0f / s, 0.0f / s);
	glVertex3f(-1.0f / s, 74.0f / s, 0.0f / s);
	glVertex3f(-11.0f / s, 74.0f / s, 0.0f / s);

	glEnd();

	//******* Jaw *********
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.92549f, 0.87059f, 0.87059f);
	glVertex3f(-12.0f / s, 54.0f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 55.0f / s, 0.0f / s);
	glVertex3f(-10.0f / s, 54.5f / s, 0.0f / s);
	glVertex3f(-10.0f / s, 57.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 54.0f / s, 0.0f / s);

	glEnd();

	//******* Eye B *********
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-9.5f / s, 67.0f / s, 0.0f / s);
	glVertex3f(-10.0f / s, 69.0f / s, 0.0f / s);
	glVertex3f(-5.8f / s, 69.5f / s, 0.0f / s);
	glVertex3f(-5.7f / s, 71.0f / s, 0.0f / s);
	glVertex3f(-0.9f / s, 69.7f / s, 0.0f / s);

	glEnd();

	//****** Eye Circle (outer)
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	for (int i = 0; i < 360; i++)
	{
		GLfloat fTheata = i * (PI / 180.0f);

		GLfloat fX = 1.0f / s * cos(fTheata);
		GLfloat fY = 1.0f / s * sin(fTheata);

		glVertex3f(fX + (-5.6f / s), fY + (67.9f / s), 0.0f);
	}
	glEnd();

	//****** Eye Circle (inner)
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3f(-5.6f / s, 67.9f / s, 0.0f);

	glEnd();

	//*** Ear (outer)***
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.41569f, 0.36863f, 0.36863f);
	glVertex3f(3.6f / s, 66.0f / s, 0.0f / s);
	glVertex3f(2.1f / s, 68.1f / s, 0.0f / s);
	glVertex3f(2.2f / s, 63.0f / s, 0.0f / s);
	glVertex3f(3.5f / s, 63.1f / s, 0.0f / s);
	glVertex3f(4.7f / s, 65.5f / s, 0.0f / s);
	glVertex3f(5.0f / s, 67.9f / s, 0.0f / s);
	glVertex3f(4.1f / s, 68.4f / s, 0.0f / s);
	glVertex3f(2.1f / s, 68.1f / s, 0.0f / s);

	glEnd();

	//*** Ear (inner)***
	glBegin(GL_TRIANGLES);

	glColor3f(0.30980f, 0.27451f, 0.27451f);
	glVertex3f(3.6f / s, 66.0f / s, 0.0f / s);
	glVertex3f(2.5f / s, 66.4f / s, 0.0f / s);
	glVertex3f(2.5f / s, 64.7f / s, 0.0f / s);

	glEnd();

	//*** Nose ***
	glLineWidth(2);
	glBegin(GL_LINES);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-15.0f / s, 61.0f / s, 0.0f / s);
	glVertex3f(-11.6f / s, 62.0f / s, 0.0f / s);


	glEnd();

	//****************** mukut Upper part *******************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.0, 0.0);
	glVertex3f(3.0f / s, 79.0f / s, 0.0f);
	glVertex3f(6.0f / s, 80.0f / s, 0.0f);
	glVertex3f(8.0f / s, 81.0f / s, 0.0f);
	glVertex3f(6.0f / s, 85.0f / s, 0.0f);
	glVertex3f(2.0f / s, 85.0f / s, 0.0f);
	glVertex3f(1.0f / s, 82.0f / s, 0.0f);
	glVertex3f(-2.0f / s, 82.0f / s, 0.0f);
	glVertex3f(-3.0f / s, 81.0f / s, 0.0f);
	glVertex3f(-2.0f / s, 79.0f / s, 0.0f);
	glVertex3f(5.0f / s, 73.0f / s, 0.0f);
	glVertex3f(7.0f / s, 74.0f / s, 0.0f);
	glVertex3f(6.0f / s, 80.0f / s, 0.0f);
	glEnd();

	//****************** mukut Lower part (middle unit) *******************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.988f, 0.761f, 0.012f);
	glVertex3f(1.0f / s, 75.0f / s, 0.0f);
	glVertex3f(-2.0f / s, 79.0f / s, 0.0f);
	glVertex3f(-6.0f / s, 78.0f / s, 0.0f);
	glVertex3f(-10.0f / s, 74.0f / s, 0.0f);
	glVertex3f(-1.0f / s, 74.0f / s, 0.0f);
	glVertex3f(1.0f / s, 72.0f / s, 0.0f);
	glVertex3f(3.0f / s, 69.0f / s, 0.0f);
	glVertex3f(5.0f / s, 70.0f / s, 0.0f);
	glVertex3f(5.0f / s, 73.0f / s, 0.0f);
	glVertex3f(-2.0f / s, 79.0f / s, 0.0f);
	glEnd();

	//****************** mukut Lower part (left unit) *******************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.988f, 0.761f, 0.012f);
	glVertex3f(-8.0f / s, 78.0f / s, 0.0f);
	glVertex3f(-6.0f / s, 78.0f / s, 0.0f);
	glVertex3f(-5.0f / s, 82.0f / s, 0.0f);
	glVertex3f(-9.0f / s, 80.0f / s, 0.0f);
	glVertex3f(-10.0f / s, 74.0f / s, 0.0f);
	glVertex3f(-6.0f / s, 78.0f / s, 0.0f);
	glEnd();

	//****************** mukut Lower part (right unit) *******************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.988f, 0.761f, 0.012f);
	glVertex3f(5.0f / s, 66.0f / s, 0.0f);
	glVertex3f(5.0f / s, 70.0f / s, 0.0f);
	glVertex3f(3.0f / s, 69.0f / s, 0.0f);
	glVertex3f(5.0f / s, 62.0f / s, 0.0f);
	glVertex3f(13.0f / s, 74.0f / s, 0.0f);
	glVertex3f(10.0f / s, 75.0f / s, 0.0f);
	glVertex3f(5.0f / s, 70.0f / s, 0.0f);
	glEnd();

	//**** Jaw Line ******
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-7.5f / s, 54.3f / s, 0.0f);
	glVertex3f(-2.0f / s, 56.2f / s, 0.0f);
	glVertex3f(2.3f / s, 63.5f / s, 0.0f);
	glEnd();

	//****************** neck mal Rudraksh *******************
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3f(0.235, 0.0, 0.0);
	glVertex3f(6.61446f / s, 55.8534f / s, 0.0f);
	glVertex3f(6.53664f / s, 54.9974f / s, 0.0f);
	glVertex3f(6.14753f / s, 54.1413f / s, 0.0f);
	glVertex3f(5.91406f / s, 53.3631f / s, 0.0f);
	glVertex3f(5.3693f / s, 52.5749f / s, 0.0f);
	glVertex3f(4.82455f / s, 51.9623f / s, 0.0f);
	glVertex3f(4.20197f / s, 51.3398f / s, 0.0f);
	glVertex3f(3.34593f / s, 50.5615f / s, 0.0f);
	glVertex3f(2.5677f / s, 49.8611f / s, 0.0f);
	glVertex3f(1.63384f / s, 48.7716f / s, 0.0f);
	glVertex3f(0.38868f / s, 47.9934f / s, 0.0f);
	glVertex3f(-0.7786f / s, 47.1374f / s, 0.0f);
	glVertex3f(-1.8681f / s, 46.3591f / s, 0.0f);
	glVertex3f(-2.7242f / s, 45.5809f / s, 0.0f);
	glVertex3f(-3.9693f / s, 45.0361f / s, 0.0f);
	glVertex3f(-5.2923f / s, 44.4914f / s, 0.0f);
	glVertex3f(-6.5375f / s, 44.1023f / s, 0.0f);
	glVertex3f(-7.3779f / s, 43.8766f / s, 0.0f);
	glVertex3f(-8.3274f / s, 43.6353f / s, 0.0f);
	glVertex3f(-9.3391f / s, 43.3241f / s, 0.0f);
	glVertex3f(-10.662f / s, 43.4797f / s, 0.0f);
	glVertex3f(-11.206f / s, 44.2579f / s, 0.0f);
	glVertex3f(-11.388f / s, 45.1269f / s, 0.0f);
	glVertex3f(-11.206f / s, 46.1257f / s, 0.0f);
	glVertex3f(-10.584f / s, 46.9039f / s, 0.0f);
	glEnd();


	//glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, -3.0f);

	//************************* Hanuman Gada *********************************
	//***** Rod *******
	glBegin(GL_QUAD_STRIP);

	glColor3f(0.431, 0.216, 0.153);
	glVertex3f(-25.0f / s, 44.0f / s, 0.0f / s);
	glVertex3f(-24.0f / s, 42.0f / s, 0.0f / s);
	glVertex3f(21.0f / s, 67.0f / s, 0.0f / s);
	glVertex3f(23.0f / s, 63.0f / s, 0.0f / s);
	glVertex3f(25.0f / s, 71.0f / s, 0.0f / s);
	glVertex3f(29.0f / s, 64.0f / s, 0.0f / s);
	glVertex3f(41.0f / s, 76.0f / s, 0.0f / s);
	glVertex3f(43.0f / s, 71.0f / s, 0.0f / s);
	glVertex3f(46.0f / s, 75.0f / s, 0.0f / s);
	glVertex3f(45.0f / s, 74.0f / s, 0.0f / s);

	glEnd();

	//****** Gada Circle ********
	glBegin(GL_POLYGON);
	glColor3f(0.988f, 0.761f, 0.012f);
	for (int i = 0; i < 360; i++)
	{
		GLfloat fTheata = i * (PI / 180.0f);

		GLfloat fX = 10.0f / s * cos(fTheata);
		GLfloat fY = 10.0f / s * sin(fTheata);

		glVertex3f(fX + (34.0f / s), fY + (71.0f / s), 0.0f);
	}
	glEnd();


	//********************* HAnuman (Left Arm) **********************************
	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.64706f, 0.50588f, 0.50588f);
	glVertex3f(14.0f / s, 50.0f / s, 0.0f / s);
	glVertex3f(3.0f / s, 44.0f / s, 0.0f / s);
	glVertex3f(14.0f / s, 42.0f / s, 0.0f / s);
	glVertex3f(0.0f / s, 40.0f / s, 0.0f / s);
	glVertex3f(11.0f / s, 24.0f / s, 0.0f / s);
	glVertex3f(0.0f / s, 33.0f / s, 0.0f / s);
	glVertex3f(4.0f / s, 16.0f / s, 0.0f / s);
	glVertex3f(0.0f / s, 26.0f / s, 0.0f / s);
	glVertex3f(-2.0f / s, 16.0f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 34.0f / s, 0.0f / s);
	glVertex3f(-10.0f / s, 24.0f / s, 0.0f / s);
	glVertex3f(-14.0f / s, 42.0f / s, 0.0f / s);
	glVertex3f(-15.0f / s, 33.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, 41.0f / s, 0.0f / s);

	glEnd();
	//*********Left Arm (Hand) ************
	glBegin(GL_TRIANGLE_FAN);

	glColor3f(0.64706f, 0.50588f, 0.50588f);
	glVertex3f(-16.0f / s, 43.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, 41.0f / s, 0.0f / s);
	glVertex3f(-14.0f / s, 42.0f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 46.0f / s, 0.0f / s);
	glVertex3f(-14.0f / s, 47.0f / s, 0.0f / s);
	glVertex3f(-15.0f / s, 46.0f / s, 0.0f / s);
	glVertex3f(-17.0f / s, 49.0f / s, 0.0f / s);
	glVertex3f(-20.0f / s, 48.0f / s, 0.0f / s);
	glVertex3f(-20.0f / s, 44.0f / s, 0.0f / s);
	glVertex3f(-18.0f / s, 41.0f / s, 0.0f / s);

	glEnd();

	//*** Hanuman Left arm (golden bracelate)
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.988f, 0.761f, 0.012f);
	glVertex3f(-17.8f / s, 39.5f / s, 0.0f / s);
	glVertex3f(-18.4f / s, 40.4f / s, 0.0f / s);
	glVertex3f(-15.8f / s, 40.8f / s, 0.0f / s);
	glVertex3f(-16.4f / s, 41.8f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 41.1f / s, 0.0f / s);
	glVertex3f(-13.5f / s, 42.0f / s, 0.0f / s);
	glEnd();

	//****************** Left Arm Rudraksh *******************
	glPointSize(5);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.235, 0.0, 0.0);
	glVertex3f(.0f / s, 34.0f / s, 0.0f);
	glVertex3f(12.80f / s, 34.0f / s, 0.0f);
	glEnd();


	//glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, -3.0f);
	//glRotatef(rrLeg, 0.0f, 0.0f, 1.0f);
	//**************** small leg *********************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.773, 0.604, 0.604);
	glVertex3f(-9.0f / s, -80.0f / s, 0.0f);
	glVertex3f(-4.0f / s, -82.0f / s, 0.0f);
	glVertex3f(-5.0f / s, -77.0f / s, 0.0f);
	glVertex3f(-1.0f / s, -49.0f / s, 0.0f);
	glVertex3f(0.0f / s, -30.0f / s, 0.0f);
	glVertex3f(-6.0f / s, -43.0f / s, 0.0f);
	glVertex3f(-11.0f / s, -43.0f / s, 0.0f);
	glVertex3f(-12.0f / s, -76.0f / s, 0.0f);
	glVertex3f(-18.0f / s, -78.0f / s, 0.0f);
	glVertex3f(-22.0f / s, -76.0f / s, 0.0f);
	glVertex3f(-23.0f / s, -79.0f / s, 0.0f);
	glVertex3f(-21.0f / s, -80.0f / s, 0.0f);
	glVertex3f(-23.0f / s, -81.0f / s, 0.0f);
	glVertex3f(-23.0f / s, -82.0f / s, 0.0f);
	glVertex3f(-13.0f / s, -82.0f / s, 0.0f);
	glVertex3f(-9.0f / s, -82.0f / s, 0.0f);
	glVertex3f(-4.0f / s, -82.0f / s, 0.0f);
	glEnd();

	//*************small leg (gold)**************
	glBegin(GL_POLYGON);
	glColor3f(0.988, 0.761, 0.012);
	glVertex3f(-4.0f / s, -73.0f / s, 0.0f);
	glVertex3f(-12.0f / s, -73.0f / s, 0.0f);
	glVertex3f(-12.0f / s, -75.0f / s, 0.0f);
	glVertex3f(-4.0f / s, -76.0f / s, 0.0f);
	glEnd();



	//glLoadIdentity();
	///glTranslatef(0.0f, 0.0f, -3.0f);
	//glRotatef(rlLeg, 0.0f, 0.0f, 1.0f);
	//**************** big leg *********************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.773, 0.604, 0.604);
	glVertex3f(16.0f / s, -82.0f / s, 0.0f);
	glVertex3f(19.0f / s, -84.0f / s, 0.0f);
	glVertex3f(17.0f / s, -78.0f / s, 0.0f);
	glVertex3f(18.0f / s, -46.0f / s, 0.0f);
	glVertex3f(14.0f / s, -27.0f / s, 0.0f);
	glVertex3f(4.0f / s, -41.0f / s, 0.0f);
	glVertex3f(-1.0f / s, -42.0f / s, 0.0f);
	glVertex3f(5.0f / s, -49.0f / s, 0.0f);
	glVertex3f(4.0f / s, -51.0f / s, 0.0f);
	glVertex3f(9.0f / s, -78.0f / s, 0.0f);
	glVertex3f(2.0f / s, -81.0f / s, 0.0f);
	glVertex3f(-2.0f / s, -81.0f / s, 0.0f);
	glVertex3f(-2.0f / s, -84.0f / s, 0.0f);
	glVertex3f(-1.0f / s, -85.0f / s, 0.0f);
	glVertex3f(-2.0f / s, -86.0f / s, 0.0f);
	glVertex3f(-2.0f / s, -87.0f / s, 0.0f);
	glVertex3f(8.0f / s, -85.0f / s, 0.0f);
	glVertex3f(15.0f / s, -85.0f / s, 0.0f);
	glVertex3f(19.0f / s, -84.0f / s, 0.0f);
	glEnd();

	//*************Big leg (gold)**************
	glBegin(GL_POLYGON);
	glColor3f(0.988, 0.761, 0.012);
	glVertex3f(17.0f / s, -74.0f / s, 0.0f);
	glVertex3f(8.0f / s, -74.0f / s, 0.0f);
	glVertex3f(9.0f / s, -77.0f / s, 0.0f);
	glVertex3f(17.0f / s, -77.0f / s, 0.0f);
	glEnd();


	//glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, -3.0f);

	//************** Draw Tail 1st part ****************
	struct Circle tail01;

	tail01.size.point_size = 15;
	tail01.center.xCoordinate = 28.5f / s;
	tail01.center.yCoordinate = -0.7f / s;
	tail01.radius.xAxis = -16.0f / s;
	tail01.radius.yAxis = -16.0f / s;
	tail01.color.r = 0.698f;
	tail01.color.g = 0.294;
	tail01.color.b = 0.016;
	tail01.angle.from = 30;
	tail01.angle.to = 150;

	DrawCircle(GL_POINTS, tail01);

	//************** Draw Tail 2nd part ****************
	struct Circle tail02;

	tail02.size.point_size = 15;
	tail02.center.xCoordinate = 50.5f / s;
	tail02.center.yCoordinate = -27.5f / s;
	tail02.radius.xAxis = -20.0f / s;
	tail02.radius.yAxis = -20.0f / s;
	tail02.color.r = 0.698f;
	tail02.color.g = 0.294f;
	tail02.color.b = 0.016f;
	tail02.angle.from = 150;
	tail02.angle.to = 300;

	DrawCircle(GL_POINTS, tail02);

	glBegin(GL_TRIANGLES);
	glColor3f(0.698f, 0.294f, 0.016f);
	glVertex3f(65.8f / s, -38.6f / s, 0.0f);
	glVertex3f(71.6f / s, -33.5f / s, 0.0f);
	glVertex3f(77.8f / s, -48.0f / s, 0.0f);
	glEnd();


	//**************** Lower Yellow part *********************

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.882, 0.859, 0.11);
	glVertex3f(-2.0f / s, -15.0f / s, 0.0f);
	glVertex3f(17.0f / s, -8.0f / s, 0.0f);
	glVertex3f(18.0f / s, -3.0f / s, 0.0f);
	glVertex3f(18.0f / s, 1.0f / s, 0.0f);
	glVertex3f(16.0f / s, 5.0f / s, 0.0f);
	glVertex3f(12.0f / s, 10.0f / s, 0.0f);
	glVertex3f(-7.0f / s, 9.0f / s, 0.0f);
	glVertex3f(-9.0f / s, 3.0f / s, 0.0f);
	glVertex3f(-11.0f / s, -3.0f / s, 0.0f);
	glVertex3f(-13.0f / s, -13.0f / s, 0.0f);
	glVertex3f(-13.0f / s, -19.0f / s, 0.0f);
	glVertex3f(-13.0f / s, -25.0f / s, 0.0f);
	glVertex3f(-11.0f / s, -32.0f / s, 0.0f);
	glVertex3f(-11.0f / s, -43.0f / s, 0.0f);
	glVertex3f(-11.0f / s, -43.0f / s, 0.0f);
	glVertex3f(-6.0f / s, -43.0f / s, 0.0f);
	glVertex3f(-4.0f / s, -48.0f / s, 0.0f);
	glVertex3f(4.0f / s, -51.0f / s, 0.0f);
	glVertex3f(5.0f / s, -49.0f / s, 0.0f);
	glVertex3f(5.0f / s, -49.0f / s, 0.0f);
	glVertex3f(7.0f / s, -46.0f / s, 0.0f);
	glVertex3f(6.0f / s, -38.0f / s, 0.0f);
	glVertex3f(14.0f / s, -27.0f / s, 0.0f);
	glVertex3f(12.0f / s, -24.0f / s, 0.0f);
	glVertex3f(12.0f / s, -19.0f / s, 0.0f);
	glVertex3f(15.0f / s, -12.0f / s, 0.0f);
	glVertex3f(16.0f / s, -13.0f / s, 0.0f);
	glVertex3f(18.0f / s, -10.0f / s, 0.0f);
	glVertex3f(18.0f / s, -10.0f / s, 0.0f);
	glVertex3f(17.0f / s, -8.0f / s, 0.0f);
	glEnd();

	//*************green patta on hip **************
	glBegin(GL_POLYGON);
	glColor3f(0.008, 0.478, 0.008);
	glVertex3f(12.0f / s, 12.0f / s, 0.0f);
	glVertex3f(-8.0f / s, 11.0f / s, 0.0f);
	glVertex3f(-9.0f / s, 5.0f / s, 0.0f);
	glVertex3f(14.0f / s, 7.0f / s, 0.0f);
	glEnd();
}