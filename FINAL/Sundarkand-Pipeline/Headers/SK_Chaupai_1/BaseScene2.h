#pragma once

#include <windows.h>

GLfloat axScaleWave = -1.2f;
GLfloat byScaleWave = 0.0f;

BOOL cbWaves = TRUE;

void drawBaseScene2(void)
{
	
	//Waves Animatiom
	if (byScaleWave <= 1.1f && cbWaves == TRUE)
	{
		byScaleWave = byScaleWave + 0.0007f;
	}
	else if (byScaleWave >= 0.5f)
	{
		byScaleWave = byScaleWave - 0.0007f;
		cbWaves = FALSE;
	}
	else
	{
		cbWaves = TRUE;
	}
	///////////////////////////////////////////////////TRANSFORMATIONS/////////////////////////////////////////////////////////
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.25f);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	// sky
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);

	GLfloat d = 150.0f;

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

	// sea
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);

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

	
	////Sea waves
	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(26.05f / d, -8.88f / d, 0.0f);
	//glVertex3f(24.658f / d, -10.148f / d, 0.0f);
	//glVertex3f(21.657f / d, -10.8745f / d, 0.0f);
	//glVertex3f(26.3636f / d, -11.0324f / d, 0.0f);
	//glVertex3f(30.564f / d, -11.0324f / d, 0.0f);
	//glVertex3f(27.722f / d, -9.93f / d, 0.0f);
	//glEnd();

	//glBegin(GL_POLYGON);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(61.13f / d, 0.66f / d, 0.0f);
	//glVertex3f(60.26f / d, -0.16f / d, 0.0f);
	//glVertex3f(58.54f / d, -0.85f / d, 0.0f);
	//glVertex3f(61.35f / d, -0.94f / d, 0.0f);
	//glVertex3f(64.0f / d, -0.62f / d, 0.0f);
	//glVertex3f(62.17f / d, -0.16f / d, 0.0f);
	//glEnd();

	//glBegin(GL_TRIANGLES);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(65.67f / d, -15.63f / d, 0.0f);
	//glVertex3f(63.0f / d, -17.0f / d, 0.0f);
	//glVertex3f(68.0f / d, -17.0f / d, 0.0f);
	//glEnd();

	//glBegin(GL_TRIANGLES);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(68.0f / d, -5.2f / d, 0.0f);
	//glVertex3f(66.0f / d, -6.0f / d, 0.0f);
	//glVertex3f(70.0f / d, -6.0f / d, 0.0f);
	//glEnd();

	//glBegin(GL_TRIANGLES);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(79.0f / d, -12.8f / d, 0.0f);
	//glVertex3f(77.0f / d, -14.5f / d, 0.0f);
	//glVertex3f(81.0f / d, -14.5f / d, 0.0f);
	//glEnd();

	//glBegin(GL_TRIANGLES);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(26.0f / d, 0.56f / d, 0.0f);
	//glVertex3f(24.0f / d, -0.68f / d, 0.0f);
	//glVertex3f(28.0f / d, -0.46f / d, 0.0f);
	//glEnd();

	//glBegin(GL_TRIANGLES);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(26.0f / d, -8.9f / d, 0.0f);
	//glVertex3f(21.0f / d, -10.8f / d, 0.0f);
	//glVertex3f(30.0f / d, -10.62f / d, 0.0f);
	//glEnd();

	//glBegin(GL_TRIANGLES);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(12.0f / d, -18.9f / d, 0.0f);
	//glVertex3f(10.0f / d, -20.8f / d, 0.0f);
	//glVertex3f(15.0f / d, -19.9f / d, 0.0f);
	//glEnd();

	//glBegin(GL_TRIANGLES);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-17.5f / d, -11.0f / d, 0.0f);
	//glVertex3f(-21.5f / d, -13.4f / d, 0.0f);
	//glVertex3f(-13.22f / d, -13.09f / d, 0.0f);
	//glEnd();

	//glBegin(GL_TRIANGLES);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-34.4f / d, -11.12f / d, 0.0f);
	//glVertex3f(-38.16f / d, -13.08f / d, 0.0f);
	//glVertex3f(-29.5f / d, -13.4f / d, 0.0f);
	//glEnd();

	//glBegin(GL_TRIANGLES);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-67.11f / d, -11.39f / d, 0.0f);
	//glVertex3f(-70.88f / d, -13.37f / d, 0.0f);
	//glVertex3f(-62.68f / d, -13.08f / d, 0.0f);
	//glEnd();

	//glBegin(GL_TRIANGLES);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-56.0f / d, -8.0f / d, 0.0f);
	//glVertex3f(-61.0f / d, -10.2f / d, 0.0f);
	//glVertex3f(-54.8f / d, -10.3f / d, 0.0f);
	//glEnd();

	//glBegin(GL_TRIANGLES);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-71.0f / d, 4.5f / d, 0.0f);
	//glVertex3f(-74.0f / d, 3.5f / d, 0.0f);
	//glVertex3f(-69.0f / d, 3.5f / d, 0.0f);
	//glEnd();


	//glBegin(GL_TRIANGLES);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-43.25f / d, -2.33f / d, 0.0f);
	//glVertex3f(-45.4f / d, -3.7f / d, 0.0f);
	//glVertex3f(-41.8f / d, -3.7f / d, 0.0f);
	//glEnd();

	//glBegin(GL_TRIANGLES);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-58.3f / d, 2.08f / d, 0.0f);
	//glVertex3f(-61.5f / d, 0.73f / d, 0.0f);
	//glVertex3f(-56.4f / d, 0.5f / d, 0.0f);
	//glEnd();

	//glBegin(GL_TRIANGLES);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-95.6f / d, -10.8f / d, 0.0f);
	//glVertex3f(-98.0f / d, -12.12f / d, 0.0f);
	//glVertex3f(-94.0f / d, -12.35f / d, 0.0f);
	//glEnd();

	//glBegin(GL_TRIANGLES);
	//glColor3f(0.376, 0.878, 1.0);
	//glVertex3f(-98.0f / d, 9.16f / d, 0.0f);
	//glVertex3f(-98.7f / d, 7.9f / d, 0.0f);
	//glVertex3f(-96.0f / d, 8.2f / d, 0.0f);
	//glEnd();

	//Sea waves
glLoadIdentity();
glTranslatef(0.0f, 0.0f, -1.4f);
glScalef(axScaleWave, byScaleWave, 1.0f);
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


glScalef(axScaleWave, byScaleWave, 1.0f);
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

glScalef(axScaleWave, byScaleWave, 1.0f);
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
glScalef(axScaleWave, byScaleWave, 1.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.376, 0.878, 1.0);
glVertex3f(65.67f / d, -15.63f / d, 0.0f);
glVertex3f(63.0f / d, -17.0f / d, 0.0f);
glVertex3f(68.0f / d, -17.0f / d, 0.0f);
glEnd();
glLoadIdentity();
glTranslatef(0.0f, 0.0f, -1.1f);
glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

glScalef(axScaleWave, byScaleWave, 1.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.376, 0.878, 1.0);
glVertex3f(68.0f / d, -5.2f / d, 0.0f);
glVertex3f(66.0f / d, -6.0f / d, 0.0f);
glVertex3f(70.0f / d, -6.0f / d, 0.0f);
glEnd();
glLoadIdentity();
glTranslatef(0.0f, 0.0f, -1.1f);
glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

glScalef(axScaleWave, byScaleWave, 1.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.376, 0.878, 1.0);
glVertex3f(79.0f / d, -12.8f / d, 0.0f);
glVertex3f(77.0f / d, -14.5f / d, 0.0f);
glVertex3f(81.0f / d, -14.5f / d, 0.0f);
glEnd();
glLoadIdentity();
glTranslatef(0.0f, 0.0f, -1.1f);
glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

glScalef(axScaleWave, byScaleWave, 1.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.376, 0.878, 1.0);
glVertex3f(26.0f / d, 0.56f / d, 0.0f);
glVertex3f(24.0f / d, -0.68f / d, 0.0f);
glVertex3f(28.0f / d, -0.46f / d, 0.0f);
glEnd();
glLoadIdentity();
glTranslatef(0.0f, 0.0f, -1.1f);
glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


glScalef(axScaleWave, byScaleWave, 1.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.376, 0.878, 1.0);
glVertex3f(26.0f / d, -8.9f / d, 0.0f);
glVertex3f(21.0f / d, -10.8f / d, 0.0f);
glVertex3f(30.0f / d, -10.62f / d, 0.0f);
glEnd();
glLoadIdentity();
glTranslatef(0.0f, 0.0f, -1.1f);
glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

glScalef(axScaleWave, byScaleWave, 1.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.376, 0.878, 1.0);
glVertex3f(12.0f / d, -18.9f / d, 0.0f);
glVertex3f(10.0f / d, -20.8f / d, 0.0f);
glVertex3f(15.0f / d, -19.9f / d, 0.0f);
glEnd();
glLoadIdentity();
glTranslatef(0.0f, 0.0f, -1.1f);
glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

glScalef(axScaleWave, byScaleWave, 1.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.376, 0.878, 1.0);
glVertex3f(-17.5f / d, -11.0f / d, 0.0f);
glVertex3f(-21.5f / d, -13.4f / d, 0.0f);
glVertex3f(-13.22f / d, -13.09f / d, 0.0f);
glEnd();
glLoadIdentity();
glTranslatef(0.0f, 0.0f, -1.1f);
glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


glScalef(axScaleWave, byScaleWave, 1.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.376, 0.878, 1.0);
glVertex3f(-17.5f / d, -11.0f / d, 0.0f);
glVertex3f(-21.5f / d, -13.4f / d, 0.0f);
glVertex3f(-13.22f / d, -13.09f / d, 0.0f);
glEnd();
glLoadIdentity();
glTranslatef(0.0f, 0.0f, -1.6f);
glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

glScalef(axScaleWave, byScaleWave, 1.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.376, 0.878, 1.0);
glVertex3f(-34.4f / d, -11.12f / d, 0.0f);
glVertex3f(-38.16f / d, -13.08f / d, 0.0f);
glVertex3f(-29.5f / d, -13.4f / d, 0.0f);
glEnd();
glLoadIdentity();
glTranslatef(0.0f, 0.0f, -1.1f);
glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

glScalef(axScaleWave, byScaleWave, 1.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.376, 0.878, 1.0);
glVertex3f(-67.11f / d, -11.39f / d, 0.0f);
glVertex3f(-70.88f / d, -13.37f / d, 0.0f);
glVertex3f(-62.68f / d, -13.08f / d, 0.0f);
glEnd();
glLoadIdentity();
glTranslatef(0.0f, 0.0f, -1.1f);
glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

glScalef(axScaleWave, byScaleWave, 1.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.376, 0.878, 1.0);
glVertex3f(-67.11f / d, -11.39f / d, 0.0f);
glVertex3f(-70.88f / d, -13.37f / d, 0.0f);
glVertex3f(-62.68f / d, -13.08f / d, 0.0f);
glEnd();
glLoadIdentity();
glTranslatef(0.0f, 0.0f, -1.3f);
glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

glScalef(axScaleWave, byScaleWave, 1.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.376, 0.878, 1.0);
glVertex3f(-56.0f / d, -8.0f / d, 0.0f);
glVertex3f(-61.0f / d, -10.2f / d, 0.0f);
glVertex3f(-54.8f / d, -10.3f / d, 0.0f);
glEnd();
glLoadIdentity();
glTranslatef(0.0f, 0.0f, -1.1f);
glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


glScalef(axScaleWave, byScaleWave, 1.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.376, 0.878, 1.0);
glVertex3f(-71.0f / d, 4.5f / d, 0.0f);
glVertex3f(-74.0f / d, 3.5f / d, 0.0f);
glVertex3f(-69.0f / d, 3.5f / d, 0.0f);
glEnd();
glLoadIdentity();
glTranslatef(0.0f, 0.0f, -1.1f);
glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

glScalef(axScaleWave, byScaleWave, 1.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.376, 0.878, 1.0);
glVertex3f(-43.25f / d, -2.33f / d, 0.0f);
glVertex3f(-45.4f / d, -3.7f / d, 0.0f);
glVertex3f(-41.8f / d, -3.7f / d, 0.0f);
glEnd();
glLoadIdentity();
glTranslatef(0.0f, 0.0f, -1.1f);
glRotatef(180.0f, 0.0f, 1.0f, 0.0f);

glScalef(axScaleWave, byScaleWave, 1.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.376, 0.878, 1.0);
glVertex3f(-58.3f / d, 2.08f / d, 0.0f);
glVertex3f(-61.5f / d, 0.73f / d, 0.0f);
glVertex3f(-56.4f / d, 0.5f / d, 0.0f);
glEnd();
glLoadIdentity();
glTranslatef(0.0f, 0.0f, -1.1f);
glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


glScalef(axScaleWave, byScaleWave, 1.0f);
glBegin(GL_TRIANGLES);
glColor3f(0.376, 0.878, 1.0);
glVertex3f(-95.6f / d, -10.8f / d, 0.0f);
glVertex3f(-98.0f / d, -12.12f / d, 0.0f);
glVertex3f(-94.0f / d, -12.35f / d, 0.0f);
glEnd();
glLoadIdentity();
glTranslatef(0.0f, 0.0f, -1.1f);
glRotatef(180.0f, 0.0f, 1.0f, 0.0f);


	//sea mountain

	//dark
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.18, 0.388);
	glVertex3f(-44.3f / d, 13.65f / d, 0.0f);
	glVertex3f(-53.26f / d, 17.27f / d, 0.0f);
	glVertex3f(-62.31f / d, 22.48f / d, 0.0f);
	glVertex3f(-72.46f / d, 17.65f / d, 0.0f);
	glVertex3f(-67.4f / d, 13.08f / d, 0.0f);
	glEnd();

	//light
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


	//sand
	/*glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);

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
	glVertex3f(-60.0f / d, -33.0f / d, 0.0f);
	glVertex3f(-80.0f / d, -32.0f / d, 0.0f);
	glVertex3f(-100.0f / d, -30.0f / d, 0.0f);
	glVertex3f(-130.0f / d, -20.0f / d, 0.0f);
	glVertex3f(-150.0f / d, -10.0f / d, 0.0f);
	glVertex3f(-150.0f / d, -100.0f / d, 0.0f);
	glVertex3f(150.0f / d, -100.0f / d, 0.0f);
	glVertex3f(150.0f / d, -10.0f / d, 0.0f);
	glEnd();*/
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.1f);

	//GLfloat d = 150.0f;

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


	//startfish
	/*glLoadIdentity();
	glScalef(0.5f, 0.5f, 0.5f);
	glTranslatef(0.0f, 0.0f, -1.2f);
	glBegin(GL_POLYGON);
	glColor3f(0.773, 0.545, 0.62);
	glVertex3f(-31.4301f / d, -42.2346f / d, 0.0f);
	glVertex3f(-34.6897f / d, -38.1602f / d, 0.0f);
	glVertex3f(-36.1565f / d, -42.3976f / d, 0.0f);
	glVertex3f(-41.5347f / d, -43.0495f / d, 0.0f);
	glVertex3f(-38.6011f / d, -47.287f / d, 0.0f);
	glVertex3f(-40.5569f / d, -52.6653f / d, 0.0f);
	glVertex3f(-34.0377f / d, -48.1019f / d, 0.0f);
	glVertex3f(-28.4965f / d, -50.8725f / d, 0.0f);
	glVertex3f(-29.8003f / d, -45.8202f / d, 0.0f);
	glVertex3f(-26.2148f / d, -42.0717f / d, 0.0f);
	glEnd();*/


	/*glPointSize(6.0f);
	glBegin(GL_POINTS);
	glColor3f(0.741, 0.451, 0.71);
	glVertex3f(-33.6846f / d, -43.294f / d, 0.0f);
	glVertex3f(-36.0756f / d, -44.5705f / d, 0.0f);
	glVertex3f(-34.6897f / d, -38.1602f / d, 0.0f);
	glVertex3f(-35.4882f / d, -46.8884f / d, 0.0f);
	glVertex3f(-31.7611f / d, -47.299f / d, 0.0f);
	glVertex3f(-31.458f / d, -44.478f / d, 0.0f);
	glEnd();*/


	/*glPointSize(9.0f);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	glColor3f(0.043, 0.471, 0.624);
	glVertex3f(-82.4453f / d, -42.1433f / d, 0.0f);
	glEnd();

	glPointSize(9.0f);
	glBegin(GL_POINTS);
	glColor3f(0.043, 0.471, 0.624);
	glVertex3f(-82.7282f / d, -44.0296f / d, 0.0f);
	glEnd();*/



	//rock
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.3f);

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


	// clouds

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

	// small tree
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -0.9f);

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
	

	// tree pink converted into green
	glTranslatef(2.3f, -0.7f, -2.0f);
	glScalef(1.0f, 5.0f, 0.0f);
	//glScalef();
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
}


////***************************************** DEMO VARIABLES SCEEN 1 ****************************************//

//Hanuman Animation 
GLfloat SP1_xHanuman         = 300.0f;
GLfloat SP1_yHanuman         = -250.0f;
GLfloat SP1_zHanuman         = -800.0f;
GLfloat SP1_rHead            = 0.0f;
GLfloat SP1_rHanuman         = 90.0f;
BOOL SP1_bHead               = FALSE;
GLfloat SP1_rTail            = 0.0f;
BOOL SP1_bTail               = FALSE;
BOOL SP1_bHanumanRotate      = FALSE;
GLfloat SP1_rotate_left_leg  = 0.0f;
GLfloat SP1_rotate_right_leg = 0.0f;
GLfloat SP1_bRotateLeg       = FALSE;
GLfloat SP1_xScaleHanuman    = 1.0f;
GLfloat SP1_yScaleHanuman    = 1.0f;
GLfloat SP1_zScaleHanuman    = 1.0f;
BOOL SP1_sHanuman            = TRUE;
BOOL SP1_bHanuman            = FALSE;
GLfloat SP1_xrHauman         = 0.0f;
GLfloat SP1_yrHauman         = 0.0f;
GLfloat SP1_zrHauman         = 1.0f;




void drawHanuman_SP1(void)
{
	glLoadIdentity();
	if (SP1_bHanumanRotate == TRUE)
	{
		glTranslatef(-0.85f * SP1_xScaleHanuman, 0.37f * SP1_yScaleHanuman, 0.0f);
		glTranslatef(SP1_xHanuman / s, SP1_yHanuman / s, -3.0f + SP1_zHanuman / s);
		glScalef(SP1_xScaleHanuman, SP1_yScaleHanuman, SP1_zScaleHanuman);
		glRotatef(180, 1.0f, 0.0f, 0.0f);
		glRotatef(SP1_rHanuman - 160.0f, 0.0f, 0.0f, 1.0f);
	}
	else
	{
		glTranslatef(0.0f + SP1_xHanuman / s, 0.0f + SP1_yHanuman / s, -3.0f + SP1_zHanuman / s);
		glScalef(SP1_xScaleHanuman, SP1_yScaleHanuman, SP1_zScaleHanuman);
	}
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


	glLoadIdentity();
	if (SP1_bHanumanRotate == TRUE)
	{
		glTranslatef(-0.1f * SP1_xScaleHanuman, -0.15f * SP1_yScaleHanuman, 0.0f);
		glTranslatef(SP1_xHanuman / s, SP1_yHanuman / s, -3.0f + SP1_zHanuman / s);
		glScalef(SP1_xScaleHanuman, SP1_yScaleHanuman, SP1_zScaleHanuman);
		glRotatef(SP1_rHanuman + SP1_rHead - 50.0f, 0.0f, 0.0f, 1.0f);
	}
	else
	{
		glTranslatef(0.0f + SP1_xHanuman / s, 0.0f + SP1_yHanuman / s, -3.0f + SP1_zHanuman / s);
		glScalef(SP1_xScaleHanuman, SP1_yScaleHanuman, SP1_zScaleHanuman);
		glRotatef(SP1_rHead, 0.0f, 0.0f, 1.0f);
	}
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
	glColor3f(0.7, 0.0, 0.0);
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

	glLoadIdentity();
	if (SP1_bHanumanRotate == TRUE)
	{
		glTranslatef(0.0f, 0.0f, 0.0f);
		glTranslatef(SP1_xHanuman / s, SP1_yHanuman / s, -3.0f + SP1_zHanuman / s);
		glScalef(SP1_xScaleHanuman, SP1_yScaleHanuman, SP1_zScaleHanuman);
		glRotatef(SP1_rHanuman - 30.0f, 0.0f, 0.0f, 1.0f);
	}
	else
	{
		glTranslatef(0.0f + SP1_xHanuman / s, 0.0f + SP1_yHanuman / s, -3.0f + SP1_zHanuman / s);
		glScalef(SP1_xScaleHanuman, SP1_yScaleHanuman, SP1_zScaleHanuman);
	}
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


	glLoadIdentity();
	if (SP1_bHanumanRotate == TRUE)
	{
		glTranslatef(-0.18f * SP1_xScaleHanuman, -0.23f * SP1_yScaleHanuman, 0.0f);
		glTranslatef(SP1_xHanuman / s, SP1_yHanuman / s, -3.0f + SP1_zHanuman / s);
		glScalef(SP1_xScaleHanuman, SP1_yScaleHanuman, SP1_zScaleHanuman);
		glRotatef(SP1_rHanuman - 65.0f, 0.0f, 0.0f, 1.0f);
	}
	else
	{
		glTranslatef(0.0f + SP1_xHanuman / s, 0.0f + SP1_yHanuman / s, -3.0f + SP1_zHanuman / s);
		glScalef(SP1_xScaleHanuman, SP1_yScaleHanuman, SP1_zScaleHanuman);
	}
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


	glLoadIdentity();
	if (SP1_bHanumanRotate == TRUE)
	{
		glTranslatef(-0.1f * SP1_xScaleHanuman, -0.13f * SP1_yScaleHanuman, 0.0f);
		glTranslatef(SP1_xHanuman / s, SP1_yHanuman / s, -3.0f + SP1_zHanuman / s);
		glScalef(SP1_xScaleHanuman, SP1_yScaleHanuman, SP1_zScaleHanuman);
		glRotatef(SP1_rHanuman - 50.0f, 0.0f, 0.0f, 1.0f);
	}
	else
	{
		glTranslatef(0.0f + SP1_xHanuman / s, 0.0f + SP1_yHanuman / s, -3.0f + SP1_zHanuman / s);
		glScalef(SP1_xScaleHanuman, SP1_yScaleHanuman, SP1_zScaleHanuman);
	}
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


	glLoadIdentity();
	if (SP1_bHanumanRotate == TRUE)
	{
		glTranslatef(0.0f, 0.15f * SP1_yScaleHanuman, 0.0f);
		glTranslatef(SP1_xHanuman / s, SP1_yHanuman / s, -3.0f + SP1_zHanuman / s);
		glScalef(SP1_xScaleHanuman, SP1_yScaleHanuman, SP1_zScaleHanuman);
		glRotatef(SP1_rHanuman + SP1_rotate_right_leg, 0.0f, 0.0f, 1.0f);
	}
	else
	{
		glTranslatef(0.0f + SP1_xHanuman / s, 0.0f + SP1_yHanuman / s, -3.0f + SP1_zHanuman / s);
		glScalef(SP1_xScaleHanuman, SP1_yScaleHanuman, SP1_zScaleHanuman);
	}
	//**************** small leg *********************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.64706f, 0.50588f, 0.50588f);
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


	glLoadIdentity();
	if (SP1_bHanumanRotate == TRUE)
	{
		glTranslatef(0.0f, -0.01f * SP1_yScaleHanuman, 0.0f);
		glTranslatef(SP1_xHanuman / s, SP1_yHanuman / s, -3.0f + SP1_zHanuman / s);
		glScalef(SP1_xScaleHanuman, SP1_yScaleHanuman, SP1_zScaleHanuman);
		glRotatef(SP1_rHanuman + SP1_rotate_left_leg, 0.0f, 0.0f, 1.0f);
	}
	else
	{
		glTranslatef(0.0f + SP1_xHanuman / s, 0.0f + SP1_yHanuman / s, -3.0f + SP1_zHanuman / s);
		glScalef(SP1_xScaleHanuman, SP1_yScaleHanuman, SP1_zScaleHanuman);
	}
	//**************** big leg *********************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.64706f, 0.50588f, 0.50588f);
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


	glLoadIdentity();
	if (SP1_bHanumanRotate == TRUE)
	{
		glTranslatef(SP1_xHanuman / s, SP1_yHanuman / s, -3.0f + SP1_zHanuman / s);
		glScalef(SP1_xScaleHanuman, SP1_yScaleHanuman, SP1_zScaleHanuman);
		glRotatef(SP1_rHanuman + SP1_rTail - 30.0f, 0.0f, 0.0f, 1.0f);
	}
	else
	{
		glTranslatef(0.0f + SP1_xHanuman / s, 0.0f + SP1_yHanuman / s, -3.0f + SP1_zHanuman / s);
		glScalef(SP1_xScaleHanuman, SP1_yScaleHanuman, SP1_zScaleHanuman);
		glRotatef(SP1_rTail, 0.0f, 0.0f, 1.0f);
	}
	//************** Draw Tail 1st part ****************
	struct Circle tail01;
	tail01.size.point_size = 3 * SP1_xScaleHanuman;
	tail01.center.xCoordinate = 28.5f / s;
	tail01.center.yCoordinate = -0.7f / s;
	tail01.radius.xAxis = -16.0f / s;
	tail01.radius.yAxis = -16.0f / s;
	tail01.color.r = 0.698f;
	tail01.color.g = 0.294;
	tail01.color.b = 0.016;
	tail01.angle.from = 30;
	tail01.angle.to = 150;
	tw_DrawCircle(GL_POINTS, tail01);


	//************** Draw Tail 2nd part ****************
	struct Circle tail02;
	tail02.size.point_size = 3 * SP1_xScaleHanuman;
	tail02.center.xCoordinate = 50.5f / s;
	tail02.center.yCoordinate = -27.5f / s;
	tail02.radius.xAxis = -20.0f / s;
	tail02.radius.yAxis = -20.0f / s;
	tail02.color.r = 0.698f;
	tail02.color.g = 0.294f;
	tail02.color.b = 0.016f;
	tail02.angle.from = 150;
	tail02.angle.to = 300;
	tw_DrawCircle(GL_POINTS, tail02);


	glBegin(GL_TRIANGLES);
	glColor3f(0.698f, 0.294f, 0.016f);
	glVertex3f(65.8f / s, -38.6f / s, 0.0f);
	glVertex3f(71.6f / s, -33.5f / s, 0.0f);
	glVertex3f(77.8f / s, -48.0f / s, 0.0f);
	glEnd();

	glLoadIdentity();
	if (SP1_bHanumanRotate == TRUE)
	{
		glTranslatef(0.0f, 0.06f * SP1_yScaleHanuman, 0.0f);
		glTranslatef(SP1_xHanuman / s, SP1_yHanuman / s, -3.0f + SP1_zHanuman / s);
		glScalef(SP1_xScaleHanuman, SP1_yScaleHanuman, SP1_zScaleHanuman);
		glRotatef(SP1_rHanuman, 0.0f, 0.0f, 1.0f);
	}
	else
	{
		glTranslatef(0.0f + SP1_xHanuman / s, 0.0f + SP1_yHanuman / s, -3.0f + SP1_zHanuman / s);
		glScalef(SP1_xScaleHanuman, SP1_yScaleHanuman, SP1_zScaleHanuman);
	}
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
