#pragma once
#include <windows.h>


void drawSky(void)
{
	//********************** Background Color ************************
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


	//****************************** DRAW Cloud 02 **************************
  //****************** Clouds **************************************

	struct Circle cloud04;
	cloud04.color.r = 1.0f; cloud04.color.g = 1.0f; cloud04.color.b = 1.0f;
	cloud04.angle.from = 0.0f;
	cloud04.angle.to = 181.0f;
	cloud04.center.xCoordinate = 0.0f;
	cloud04.center.yCoordinate = 0.0f;
	cloud04.radius.xAxis = 0.7f;
	cloud04.radius.yAxis = 0.5f;


	//2nd mini
	struct Circle cloud05;
	cloud05.color.r = 1.0f; cloud05.color.g = 1.0f; cloud05.color.b = 1.0f;
	cloud05.angle.from = 0.0f;
	cloud05.angle.to = 181.0f;
	cloud05.center.xCoordinate = -0.5f;
	cloud05.center.yCoordinate = 0.0f;
	cloud05.radius.xAxis = 0.5f;
	cloud05.radius.yAxis = 0.3f;


	//3rd mini
	struct Circle cloud06;
	cloud06.color.r = 1.0f; cloud06.color.g = 1.0f; cloud06.color.b = 1.0f;
	cloud06.angle.from = 0.0f;
	cloud06.angle.to = 181.0f;
	cloud06.center.xCoordinate = 0.5f;
	cloud06.center.yCoordinate = 0.0f;
	cloud06.radius.xAxis = 0.7f;
	cloud06.radius.yAxis = 0.2f;


	//*********** Draw Cloud Call ***********
	glLoadIdentity();
	glTranslatef(-2 + xCloud / s, yCloud / s + 4.0f, -10.0f + zCloud / s);
	DrawCircle(GL_TRIANGLE_FAN, cloud05);
	DrawCircle(GL_TRIANGLE_FAN, cloud06);
	DrawCircle(GL_TRIANGLE_FAN, cloud04);


    //****************************** DRAW Cloud 03 **************************
    //****************** Clouds **************************************
    //1st big
	struct Circle cloud07;
	cloud07.color.r = 1.0f; cloud07.color.g = 1.0f; cloud07.color.b = 1.0f;
	cloud07.angle.from = 0.0f;
	cloud07.angle.to = 181.0f;
	cloud07.center.xCoordinate = 0.0f;
	cloud07.center.yCoordinate = 0.0f;
	cloud07.radius.xAxis = 0.7f;
	cloud07.radius.yAxis = 0.5f;


	//2nd mini
	struct Circle cloud08;
	cloud08.color.r = 1.0f; cloud08.color.g = 1.0f; cloud08.color.b = 1.0f;
	cloud08.angle.from = 0.0f;
	cloud08.angle.to = 181.0f;
	cloud08.center.xCoordinate = -0.5f;
	cloud08.center.yCoordinate = 0.0f;
	cloud08.radius.xAxis = 0.5f;
	cloud08.radius.yAxis = 0.3f;


	//3rd mini
	struct Circle cloud09;
	cloud09.color.r = 1.0f; cloud09.color.g = 1.0f; cloud09.color.b = 1.0f;
	cloud09.angle.from = 0.0f;
	cloud09.angle.to = 181.0f;
	cloud09.center.xCoordinate = 0.5f;
	cloud09.center.yCoordinate = 0.0f;
	cloud09.radius.xAxis = 0.7f;
	cloud09.radius.yAxis = 0.2f;


	//*********** Draw Cloud Call ***********
	glLoadIdentity();
	glTranslatef(-6.0f + xCloud / s, 3.0f + yCloud / s, -10.0f + zCloud / s);
	DrawCircle(GL_TRIANGLE_FAN, cloud08);
	DrawCircle(GL_TRIANGLE_FAN, cloud09);
	DrawCircle(GL_TRIANGLE_FAN, cloud07);


	//****************************** DRAW Cloud 04 **************************
	//****************** Clouds **************************************
	//1st big
	struct Circle cloud10;
	cloud10.color.r = 1.0f; cloud10.color.g = 1.0f; cloud10.color.b = 1.0f;
	cloud10.angle.from = 0.0f;
	cloud10.angle.to = 181.0f;
	cloud10.center.xCoordinate = 0.0f;
	cloud10.center.yCoordinate = 0.0f;
	cloud10.radius.xAxis = 0.7f;
	cloud10.radius.yAxis = 0.5f;


	//2nd mini
	struct Circle cloud11;
	cloud11.color.r = 1.0f; cloud11.color.g = 1.0f; cloud11.color.b = 1.0f;
	cloud11.angle.from = 0.0f;
	cloud11.angle.to = 181.0f;
	cloud11.center.xCoordinate = -0.5f;
	cloud11.center.yCoordinate = 0.0f;
	cloud11.radius.xAxis = 0.5f;
	cloud11.radius.yAxis = 0.3f;


	//3rd mini
	struct Circle cloud12;
	cloud12.color.r = 1.0f; cloud12.color.g = 1.0f; cloud12.color.b = 1.0f;
	cloud12.angle.from = 0.0f;
	cloud12.angle.to = 181.0f;
	cloud12.center.xCoordinate = 0.5f;
	cloud12.center.yCoordinate = 0.0f;
	cloud12.radius.xAxis = 0.7f;
	cloud12.radius.yAxis = 0.2f;


	//*********** Draw Cloud Call ***********
	glLoadIdentity();
	glTranslatef(3.2f + xCloud / s, 2.0f + yCloud / s, -6.0f + zCloud / s);
	DrawCircle(GL_TRIANGLE_FAN, cloud11);
	DrawCircle(GL_TRIANGLE_FAN, cloud12);
	DrawCircle(GL_TRIANGLE_FAN, cloud10);


	//Transformation
	glLoadIdentity();
	glTranslatef(-3.5f, 1.3f, -5.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	//***************************************** Dev lok *******************************************
	//********************* Dev01 (Right Arm) *********************************
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.75686f, 0.63529f, 0.63529f);
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
	glColor3f(0.75686f, 0.63529f, 0.63529f);
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


	//*** Dev Right arm (golden bracelate)
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.988f, 0.761f, 0.012f);
	glVertex3f(-14.4f / s, 12.6f / s, 0.0f / s);
	glVertex3f(-15.1f / s, 11.1f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 10.6f / s, 0.0f / s);
	glVertex3f(-13.7f / s, 9.2f / s, 0.0f / s);
	glVertex3f(-9.9f / s, 9.2f / s, 0.0f / s);
	glVertex3f(-10.6f / s, 7.7f / s, 0.0f / s);
	glEnd();


	//********************** Dev upper body (cheast) *********************************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f,0.0f,1.0f);
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


	//*************************** Dev Head ****************************
	//**** Face *****
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.95686f, 0.83529f, 0.83529f);
	glVertex3f(-10.0f / s, 67.0f / s, 0.0f / s);
	glVertex3f(-11.0f / s, 74.0f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 68.0f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 64.0f / s, 0.0f / s);
	glVertex3f(-15.0f / s, 61.0f / s, 0.0f / s);
	glVertex3f(-14.0f / s, 56.0f / s, 0.0f / s);
	glVertex3f(-11.0f / s, 56.0f / s, 0.0f / s);
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


	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-11.5f / s, 56.5f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 58.0f / s, 0.0f / s);
	glEnd();


	//******* Jaw *********
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.95686f, 0.83529f, 0.83529f);
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

		glVertex3f(fX + (-7.0f / s), fY + (66.0f / s), 0.0f);
	}
	glEnd();


	//****** Eye Circle (inner)
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-7.0f / s, 66.0f / s, 0.0f);
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


	//****************** mukut Upper part *******************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 1.0, 1.0);
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
	glColor3f(0.0f, 0.8f, 0.8f);
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
	//glColor3f(0.8, 0.373, 0.063);
	glColor3f(0.0f, 0.8f, 0.8f);
	glVertex3f(-8.0f / s, 78.0f / s, 0.0f);
	glVertex3f(-6.0f / s, 78.0f / s, 0.0f);
	glVertex3f(-5.0f / s, 82.0f / s, 0.0f);
	glVertex3f(-9.0f / s, 80.0f / s, 0.0f);
	glVertex3f(-10.0f / s, 74.0f / s, 0.0f);
	glVertex3f(-6.0f / s, 78.0f / s, 0.0f);
	glEnd();


	//****************** mukut Lower part (right unit) *******************
	glBegin(GL_TRIANGLE_FAN);
	//glColor3f(0.8, 0.373, 0.063);
	glColor3f(0.0f, 0.8f, 0.8f);
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
	glColor3f(1.0, 0.0, 0.0);
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


	//********************* Dev (Left Arm) **********************************
	glTranslatef(0.24f, 0.03f, 0.0f);
	glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.75686f, 0.63529f, 0.63529f);
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


	//Duppatta
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-11.0f / s, 39.0f / s, 0.0f / s);
	glVertex3f(-4.0f / s, 31.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 5.0f / s, 0.0f / s);
	glVertex3f(-16.0f / s, 15.0f / s, 0.0f / s);
	glEnd();


	//*********Left Arm (Hand) ************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.75686f, 0.63529f, 0.63529f);
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


	//*** Dev Left arm (golden bracelate)
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.988f, 0.761f, 0.012f);
	glVertex3f(-17.8f / s, 39.5f / s, 0.0f / s);
	glVertex3f(-18.4f / s, 40.4f / s, 0.0f / s);
	glVertex3f(-15.8f / s, 40.8f / s, 0.0f / s);
	glVertex3f(-16.4f / s, 41.8f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 41.1f / s, 0.0f / s);
	glVertex3f(-13.5f / s, 42.0f / s, 0.0f / s);
	glEnd();



	//***************************************** 2nd Dev *********************************************
	//***************************************** Dev lok *******************************************
	//********************* Dev01 (Right Arm) *********************************
	glLoadIdentity();
	glTranslatef(-3.6f, 1.6f, -6.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.75686f, 0.63529f, 0.63529f);
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
	glColor3f(0.75686f, 0.63529f, 0.63529f);
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


	//*** Dev Right arm (golden bracelate)
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.988f, 0.761f, 0.012f);
	glVertex3f(-14.4f / s, 12.6f / s, 0.0f / s);
	glVertex3f(-15.1f / s, 11.1f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 10.6f / s, 0.0f / s);
	glVertex3f(-13.7f / s, 9.2f / s, 0.0f / s);
	glVertex3f(-9.9f / s, 9.2f / s, 0.0f / s);
	glVertex3f(-10.6f / s, 7.7f / s, 0.0f / s);
	glEnd();


	//********************** Dev upper body (cheast) *********************************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 1.0f, 1.0f);
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


	//*************************** Dev Head ****************************
	//**** Face *****
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.95686f, 0.83529f, 0.83529f);
	glVertex3f(-10.0f / s, 67.0f / s, 0.0f / s);
	glVertex3f(-11.0f / s, 74.0f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 68.0f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 64.0f / s, 0.0f / s);
	glVertex3f(-15.0f / s, 61.0f / s, 0.0f / s);
	glVertex3f(-14.0f / s, 56.0f / s, 0.0f / s);
	glVertex3f(-11.0f / s, 56.0f / s, 0.0f / s);
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


	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-11.5f / s, 56.5f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 58.0f / s, 0.0f / s);
	glEnd();


	//******* Jaw *********
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.95686f, 0.83529f, 0.83529f);
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

		glVertex3f(fX + (-7.0f / s), fY + (66.0f / s), 0.0f);
	}
	glEnd();


	//****** Eye Circle (inner)
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-7.0f / s, 66.0f / s, 0.0f);
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


	//****************** mukut Upper part *******************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 1.0, 0.0);
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
	glColor3f(0.0f, 1.0f, 0.0f);
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
	//glColor3f(0.8, 0.373, 0.063);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-8.0f / s, 78.0f / s, 0.0f);
	glVertex3f(-6.0f / s, 78.0f / s, 0.0f);
	glVertex3f(-5.0f / s, 82.0f / s, 0.0f);
	glVertex3f(-9.0f / s, 80.0f / s, 0.0f);
	glVertex3f(-10.0f / s, 74.0f / s, 0.0f);
	glVertex3f(-6.0f / s, 78.0f / s, 0.0f);
	glEnd();


	//****************** mukut Lower part (right unit) *******************
	glBegin(GL_TRIANGLE_FAN);
	//glColor3f(0.8, 0.373, 0.063);
	glColor3f(0.0f, 1.0f, 0.0f);
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
	glColor3f(1.0, 0.0, 0.0);
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


	//********************* Dev (Left Arm) **********************************
	glTranslatef(0.24f, 0.03f, 0.0f);
	glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.75686f, 0.63529f, 0.63529f);
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


	//Duppatta
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-11.0f / s, 39.0f / s, 0.0f / s);
	glVertex3f(-4.0f / s, 31.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 5.0f / s, 0.0f / s);
	glVertex3f(-16.0f / s, 15.0f / s, 0.0f / s);
	glEnd();


	//*********Left Arm (Hand) ************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.75686f, 0.63529f, 0.63529f);
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


	//*** Dev Left arm (golden bracelate)
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.988f, 0.761f, 0.012f);
	glVertex3f(-17.8f / s, 39.5f / s, 0.0f / s);
	glVertex3f(-18.4f / s, 40.4f / s, 0.0f / s);
	glVertex3f(-15.8f / s, 40.8f / s, 0.0f / s);
	glVertex3f(-16.4f / s, 41.8f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 41.1f / s, 0.0f / s);
	glVertex3f(-13.5f / s, 42.0f / s, 0.0f / s);
	glEnd();


	//***************************************** 3nd Dev *********************************************
	//***************************************** Dev lok *******************************************
	//********************* Dev01 (Right Arm) *********************************
	glLoadIdentity();
	glTranslatef(-4.5f, 1.9f, -7.0f);
	glScalef(0.75f, 0.75f, 0.75f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.75686f, 0.63529f, 0.63529f);
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
	glColor3f(0.75686f, 0.63529f, 0.63529f);
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


	//*** Dev Right arm (golden bracelate)
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.988f, 0.761f, 0.012f);
	glVertex3f(-14.4f / s, 12.6f / s, 0.0f / s);
	glVertex3f(-15.1f / s, 11.1f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 10.6f / s, 0.0f / s);
	glVertex3f(-13.7f / s, 9.2f / s, 0.0f / s);
	glVertex3f(-9.9f / s, 9.2f / s, 0.0f / s);
	glVertex3f(-10.6f / s, 7.7f / s, 0.0f / s);
	glEnd();


	//********************** Dev upper body (cheast) *********************************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 1.0f, 0.0f);
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


	//*************************** Dev Head ****************************
	//**** Face *****
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.95686f, 0.83529f, 0.83529f);
	glVertex3f(-10.0f / s, 67.0f / s, 0.0f / s);
	glVertex3f(-11.0f / s, 74.0f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 68.0f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 64.0f / s, 0.0f / s);
	glVertex3f(-15.0f / s, 61.0f / s, 0.0f / s);
	glVertex3f(-14.0f / s, 56.0f / s, 0.0f / s);
	glVertex3f(-11.0f / s, 56.0f / s, 0.0f / s);
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


	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-11.5f / s, 56.5f / s, 0.0f / s);
	glVertex3f(-7.0f / s, 58.0f / s, 0.0f / s);
	glEnd();


	//******* Jaw *********
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.95686f, 0.83529f, 0.83529f);
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

		glVertex3f(fX + (-7.0f / s), fY + (66.0f / s), 0.0f);
	}
	glEnd();


	//****** Eye Circle (inner)
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-7.0f / s, 66.0f / s, 0.0f);
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


	//****************** mukut Upper part *******************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 1.0);
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
	glColor3f(0.0f, 0.0f, 1.0f);
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
	//glColor3f(0.8, 0.373, 0.063);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-8.0f / s, 78.0f / s, 0.0f);
	glVertex3f(-6.0f / s, 78.0f / s, 0.0f);
	glVertex3f(-5.0f / s, 82.0f / s, 0.0f);
	glVertex3f(-9.0f / s, 80.0f / s, 0.0f);
	glVertex3f(-10.0f / s, 74.0f / s, 0.0f);
	glVertex3f(-6.0f / s, 78.0f / s, 0.0f);
	glEnd();


	//****************** mukut Lower part (right unit) *******************
	glBegin(GL_TRIANGLE_FAN);
	//glColor3f(0.8, 0.373, 0.063);
	glColor3f(0.0f, 0.0f, 1.0f);
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
	glColor3f(1.0, 0.0, 0.0);
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


	//********************* Dev (Left Arm) **********************************
	glTranslatef(0.24f, 0.03f, 0.0f);
	glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.75686f, 0.63529f, 0.63529f);
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


	//Duppatta
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-11.0f / s, 39.0f / s, 0.0f / s);
	glVertex3f(-4.0f / s, 31.0f / s, 0.0f / s);
	glVertex3f(-8.0f / s, 5.0f / s, 0.0f / s);
	glVertex3f(-16.0f / s, 15.0f / s, 0.0f / s);
	glEnd();


	//*********Left Arm (Hand) ************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.75686f, 0.63529f, 0.63529f);
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


	//*** Dev Left arm (golden bracelate)
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.988f, 0.761f, 0.012f);
	glVertex3f(-17.8f / s, 39.5f / s, 0.0f / s);
	glVertex3f(-18.4f / s, 40.4f / s, 0.0f / s);
	glVertex3f(-15.8f / s, 40.8f / s, 0.0f / s);
	glVertex3f(-16.4f / s, 41.8f / s, 0.0f / s);
	glVertex3f(-13.0f / s, 41.1f / s, 0.0f / s);
	glVertex3f(-13.5f / s, 42.0f / s, 0.0f / s);
	glEnd();



	//****************************** DRAW Cloud 01 **************************
	//****************** Clouds **************************************
	//1st big
	struct Circle cloud01;
	cloud01.color.r = 1.0f; cloud01.color.g = 0.9f; cloud01.color.b = 0.6f;
	cloud01.angle.from = 0.0f;
	cloud01.angle.to = 181.0f;
	cloud01.center.xCoordinate = 0.0f;
	cloud01.center.yCoordinate = 0.0f;
	cloud01.radius.xAxis = 0.7f;
	cloud01.radius.yAxis = 0.5f;


	//2nd mini
	struct Circle cloud02;
	cloud02.color.r = 1.0f; cloud02.color.g = 0.9f; cloud02.color.b = 0.6f;
	cloud02.angle.from = 0.0f;
	cloud02.angle.to = 181.0f;
	cloud02.center.xCoordinate = -0.5f;
	cloud02.center.yCoordinate = 0.0f;
	cloud02.radius.xAxis = 0.5f;
	cloud02.radius.yAxis = 0.3f;


	//3rd mini
	struct Circle cloud03;
	cloud03.color.r = 1.0f; cloud03.color.g = 0.9f; cloud03.color.b =0.6f;
	cloud03.angle.from = 0.0f;
	cloud03.angle.to = 181.0f;
	cloud03.center.xCoordinate = 0.5f;
	cloud03.center.yCoordinate = 0.0f;
	cloud03.radius.xAxis = 0.7f;
	cloud03.radius.yAxis = 0.2f;


	//*********** Draw Cloud Call ***********
	glLoadIdentity();
	glTranslatef(-3.2f, 1.2f, -5.0f);
	glScalef(0.5f, 0.5f, 0.5f);
	DrawCircle(GL_TRIANGLE_FAN, cloud02);
	DrawCircle(GL_TRIANGLE_FAN, cloud03);
	DrawCircle(GL_TRIANGLE_FAN, cloud01);






	//***************************************** Birds 01 *******************************************************
	glLoadIdentity();
	glTranslatef(0.0f + xBird / s, 2.0f + yBird / s, -8.0f + zBird / s);

	glBegin(GL_TRIANGLES);
	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.2f, 0.2f, 0.0f);
	glVertex3f(-0.1f, 0.05f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.5f,0.5f,0.5f);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(-0.5f,0.3f,0.0f);
	glVertex3f(-0.2f,-0.1f,0.0f);
	glEnd();

	//**************************************** Bird 02 *******************************************************
	glLoadIdentity();
	glTranslatef(-5.0f - xBird / s, 2.5f + yBird / s, -10.0f + zBird / s);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

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


	//**************************************** Bird 03 *******************************************************
	glLoadIdentity();
	glTranslatef(5.0f + xBird / s, 2.2f + yBird / s, -10.0f + zBird / s);

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


	//***************************************** Birds 04 *******************************************************
	glLoadIdentity();
	glTranslatef(-12.0f + (xBird / s) * 4.5, 4.5f, -20.0f);

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

	//**************************************** Bird 05 *******************************************************
	glLoadIdentity();
	glTranslatef(12.0f - ((xBird / s) * 5), 0.0f + yBird / s, -18.0f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

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


	//**************************************** Bird 06 *******************************************************
	glLoadIdentity();
	glTranslatef(1.0f + ((xBird / s) * 2), -4.2f + yBird / s, -19.0f);

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