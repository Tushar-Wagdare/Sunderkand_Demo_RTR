#pragma once

#include <windows.h>

#define PI 3.14159265359


GLfloat yMainakTranslate = -1.5f;

void drawMainakParvat(void)
{
	GLfloat s = 100.0f;

	// ************************** Sky And water ************************
	//********************** Background Color ************************

	void DrawCircle(GLenum, struct Circle);

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

			DrawCircle(GL_TRIANGLE_FAN, circle01);
		}
	}

	//water bottom plane color
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.718, 0.984);
	glVertex3f(-2.5f, -0.5f, 0.0f);
	glVertex3f(-2.5f, -1.5f, 0.0f);
	glVertex3f(2.5f, -1.5f, 0.0f);
	glVertex3f(2.5f, -0.5f, 0.0f);
	glEnd();


}