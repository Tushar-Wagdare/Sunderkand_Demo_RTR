#pragma once

#include <windows.h>

#define PI 3.14159265359


void draw_simhika(void) {

	GLfloat s = 100.0f;
	//water
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	glBegin(GL_QUADS);
	//glColor3f(0.109f, 0.525f, 0.713f);
	//glColor3f(0.67f, 0.85f, 0.89f);
	glColor3f(0.46f, 0.70f, 0.77f);
	glVertex3f(-202.1 / s, 199.02 / s, 0.0f);

	glVertex3f(-203.6 / s, -202.26 / s, 0.0f);
	glColor3f(0.67f, 0.85f, 0.89f);
	glVertex3f(296.75 / s, -196.06 / s, 0.0f);
	glColor3f(0.023f, 0.223f, 0.439f);
	glVertex3f(296.75 / s, 197.47 / s, 0.0f);

	glEnd();

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
	glTranslatef(x_translate, y_translate, -3.0f);
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
	glTranslatef(x_translate, y_translate, -3.0f);
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

	// Circle
	float p1 = 0.0f;
	float q1 = 0.0f;
	const float v1 = 0.3f;

	glPointSize(3.0);
	glBegin(GL_POINTS);
	glColor3f(0.86f, 0.86f, 1.0f);
	for (float angle = 0.0f; angle <= 180.0f; angle = angle + 10)
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

