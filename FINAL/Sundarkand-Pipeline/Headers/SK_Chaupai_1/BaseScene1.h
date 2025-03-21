#pragma once

#include <windows.h>


//GLfloat s = 100.0f;

GLfloat xMove = 0.0f;

void drawBaseScene1(void)
{
	void drawMagicalWaves(void);
	///////////////////////////////////////////////////TRANSFORMATIONS/////////////////////////////////////////////////////////
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.25f);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	// bottomost part 1
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.718, 0.984);
	glVertex3f(97.69 / s, -28.06 / s, 0.0f);

	glColor3f(0.0, 0.718, 0.984);
	glVertex3f(-98.17 / s, -28.06 / s, 0.0f);

	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-98.17 / s, -54.90 / s, 0.0f);

	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(97.69 / s, -54.69 / s, 0.0f);
	glEnd();

	
	GLfloat yScaleWave = 0.0f;
	BOOL bWaves = TRUE;
	//Waves Animatiom
	if (yScaleWave <= 7.1f && bWaves == TRUE)
	{
		yScaleWave = yScaleWave + 0.07f;
	}
	else if (yScaleWave >= 3.5f)
	{
		yScaleWave = yScaleWave - 0.07f;
		bWaves = FALSE;
	}
	else
	{
		bWaves = TRUE;
	}

	// now not in use simply uncomment tsr to undo
	glLoadIdentity();
	//glTranslatef(xMove * 0.01, 0.0f, -1.25f);
	//glRotatef(cap_angle * 0.1999, 1.0f, 1.0f, 1.0f);
	//glScalef(yScaleWave, 1.0f, 1.0f);
	//small triangles on water
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-45.3339f / s, -32.6563f / s, 0.0f);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-47.7525f / s, -31.1222f / s, 0.0f);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-50.0874f / s, -32.5205f / s, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-52.6972f / s, -47.8369f / s, 0.0f);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-55.7656f / s, -46.6952f / s, 0.0f);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-58.6438f / s, -48.0034f / s, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(5.31782f / s, -39.6697f / s, 0.0f);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-0.033084f / s, -37.1351f / s, 0.0f);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-5.38398f / s, -39.9514f / s, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-84.1238f / s, -34.6511f / s, 0.0f);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-86.2425f / s, -33.168f / s, 0.0f);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-88.3612f / s, -34.1459f / s, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-74.1821f / s, -46.3855f / s, 0.0f);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-76.6268f / s, -44.2668f / s, 0.0f);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-79.7234f / s, -45.7336f / s, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-29.2283f / s, -44.2514f / s, 0.0f);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-30.5322f / s, -42.7846f / s, 0.0f);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-32.3249f / s, -44.2514f / s, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(28.4607f / s, -51.5671f / s, 0.0f);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(24.2233f / s, -49.1224f / s, 0.0f);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(19.3339f / s, -50.5892f / s, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(35.7947f / s, -34.9433f / s, 0.0f);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(32.0462f / s, -32.8246f / s, 0.0f);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(28.4607f / s, -34.6174f / s, 0.0f);
	glEnd();




	//******1
	glLoadIdentity();
	glTranslatef(-0.9, 0.0f, -1.25f);
	glRotatef(cap_angle * 0.1999, 1.0f, 1.0f, 1.0f);
	glScalef(yScaleWave * 0.2, 1.0f, 1.0f);
	drawMagicalWaves();
	//******2
	glLoadIdentity();
	glTranslatef(-0.8, 0.0f, -1.25f);
	glRotatef(cap_angle * 0.199, 1.0f, 1.0f, 1.0f);
	glScalef(yScaleWave * 0.3, 1.0f, 1.0f);
	drawMagicalWaves();
	//******2
	glLoadIdentity();
	glTranslatef(-0.7, 0.0f, -1.25f);
	glRotatef(cap_angle * 0.1999, 1.0f, 1.0f, 1.0f);
	glScalef(yScaleWave * 0.5, 1.0f, 1.0f);
	drawMagicalWaves();
	//******2
	glLoadIdentity();
	glTranslatef(-0.6, 0.0f, -1.25f);
	glRotatef(cap_angle * 0.199, 1.0f, 1.0f, 1.0f);
	glScalef(yScaleWave * 0.7, 1.0f, 1.0f);
	drawMagicalWaves();
	//******2
	glLoadIdentity();
	glTranslatef(-0.5, 0.0f, -1.25f);
	glRotatef(cap_angle * 0.1999, 1.0f, 1.0f, 1.0f);
	glScalef(yScaleWave * 0.1, 1.0f, 1.0f);
	drawMagicalWaves();
	//******2
	glLoadIdentity();
	glTranslatef(-0.4, 0.0f, -1.25f);
	glRotatef(cap_angle * 0.199, 1.0f, 1.0f, 1.0f);
	glScalef(yScaleWave * 0.5, 1.0f, 1.0f);
	drawMagicalWaves();
	//******2
	glLoadIdentity();
	glTranslatef(-0.3, 0.0f, -1.25f);
	glRotatef(cap_angle * 0.1999, 1.0f, 1.0f, 1.0f);
	glScalef(yScaleWave * 0.4, 1.0f, 1.0f);
	drawMagicalWaves();
	//******2
	glLoadIdentity();
	glTranslatef(-0.2, 0.0f, -1.25f);
	glRotatef(cap_angle * 0.199, 1.0f, 1.0f, 1.0f);
	glScalef(yScaleWave * 0.3, 1.0f, 1.0f);
	drawMagicalWaves();
	//******2
	glLoadIdentity();
	glTranslatef(-0.1, 0.0f, -1.25f);
	glRotatef(cap_angle * 0.1999, 1.0f, 1.0f, 1.0f);
	glScalef(yScaleWave * 0.2, 1.0f, 1.0f);
	drawMagicalWaves();
	//******2
	glLoadIdentity();
	glTranslatef(-0.0, 0.0f, -1.25f);
	glRotatef(cap_angle * 0.199, 1.0f, 1.0f, 1.0f);
	glScalef(yScaleWave * 0.9, 1.0f, 1.0f);
	drawMagicalWaves();
	//******2
	glLoadIdentity();
	glTranslatef(0.1, 0.0f, -1.25f);
	glRotatef(cap_angle * 0.1999, 1.0f, 1.0f, 1.0f);
	glScalef(yScaleWave * 0.7, 1.0f, 1.0f);
	drawMagicalWaves();
	//******2
	glLoadIdentity();
	glTranslatef(0.2, 0.0f, -1.25f);
	glRotatef(cap_angle * 0.199, 1.0f, 1.0f, 1.0f);
	glScalef(yScaleWave * 0.3, 1.0f, 1.0f);
	drawMagicalWaves();
	//******2
	glLoadIdentity();
	glTranslatef(0.3, 0.0f, -1.25f);
	glRotatef(cap_angle * 0.1999, 1.0f, 1.0f, 1.0f);
	glScalef(yScaleWave * 0.4, 1.0f, 1.0f);
	drawMagicalWaves();
	//******2
	glLoadIdentity();
	glTranslatef(0.4, 0.0f, -1.25f);
	glRotatef(cap_angle * 0.199, 1.0f, 1.0f, 1.0f);
	glScalef(yScaleWave * 0.5, 1.0f, 1.0f);
	drawMagicalWaves();



	///////////////////////////
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.25f);
	// 2
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.729, 0.651, 0.427);
	glVertex3f(35.42 / s, -25.02 / s, 0.0f);
	glVertex3f(97.69 / s, -28.06 / s, 0.0f);
	glVertex3f(97.69 / s, -17.06 / s, 0.0f);
	glVertex3f(82.15 / s, -15.59 / s, 0.0f);
	glVertex3f(76.17 / s, -14.24 / s, 0.0f);
	glVertex3f(70.27 / s, -13.23 / s, 0.0f);
	glVertex3f(67.32 / s, -14.07 / s, 0.0f);
	glVertex3f(64.20 / s, -14.83 / s, 0.0f);
	glVertex3f(56.2 / s, -14.07 / s, 0.0f);
	glVertex3f(45.75 / s, -11.71 / s, 0.0f);
	glVertex3f(39.34 / s, -10.70 / s, 0.0f);
	glVertex3f(36.23 / s, -10.83 / s, 0.0f);
	glVertex3f(32.23 / s, -10.83 / s, 0.0f);
	glVertex3f(27.13 / s, -11.42 / s, 0.0f);
	glVertex3f(12.62 / s, -14.70 / s, 0.0f);
	glVertex3f(8.81 / s, -15.46 / s, 0.0f);
	glVertex3f(4.83 / s, -15.17 / s, 0.0f);
	glVertex3f(1.26 / s, -14.76 / s, 0.0f);
	glVertex3f(-1.89 / s, -14.88 / s, 0.0f);
	glVertex3f(-5.34 / s, -15.87 / s, 0.0f);
	glVertex3f(-9.49 / s, -16.69 / s, 0.0f);
	glVertex3f(-17.10 / s, -20.20 / s, 0.0f);
	glVertex3f(-98.17 / s, -19.68 / s, 0.0f);
	glVertex3f(-98.17 / s, -28.06 / s, 0.0f);
	glVertex3f(97.69 / s, -28.06 / s, 0.0f);
	glEnd();

	// 3
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.604, 0.898, 0.22);
	glVertex3f(0.0f / s, 0.0f / s, 0.0f);
	glVertex3f(97.69f / s, 5.70f / s, 0.0f);
	glVertex3f(97.69 / s, -17.06 / s, 0.0f);
	glVertex3f(82.15 / s, -15.59 / s, 0.0f);
	glVertex3f(76.17 / s, -14.24 / s, 0.0f);
	glVertex3f(70.27 / s, -13.23 / s, 0.0f);
	glVertex3f(67.32 / s, -14.07 / s, 0.0f);
	glVertex3f(64.20 / s, -14.83 / s, 0.0f);
	glVertex3f(56.2 / s, -14.07 / s, 0.0f);
	glVertex3f(45.75 / s, -11.71 / s, 0.0f);
	glVertex3f(39.34 / s, -10.70 / s, 0.0f);
	glVertex3f(36.23 / s, -10.83 / s, 0.0f);
	glVertex3f(32.23 / s, -10.83 / s, 0.0f);
	glVertex3f(27.13 / s, -11.42 / s, 0.0f);
	glVertex3f(12.62 / s, -14.70 / s, 0.0f);
	glVertex3f(8.81 / s, -15.46 / s, 0.0f);
	glVertex3f(4.83 / s, -15.17 / s, 0.0f);
	glVertex3f(1.26 / s, -14.76 / s, 0.0f);
	glVertex3f(-1.89 / s, -14.88 / s, 0.0f);
	glVertex3f(-5.34 / s, -15.87 / s, 0.0f);
	glVertex3f(-9.49 / s, -16.69 / s, 0.0f);
	glVertex3f(-17.10 / s, -20.20 / s, 0.0f);
	glVertex3f(-98.17 / s, -19.68 / s, 0.0f);
	glVertex3f(-98.17 / s, 5.66 / s, 0.0f);
	glVertex3f(97.69f / s, 5.70f / s, 0.0f);
	glEnd();

	// 4
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.345, 0.698, 0.0);
	glVertex3f(-0.45f / s, 5.88f / s, 0.0f);
	glVertex3f(-98.17f / s, 10.77f / s, 0.0f);
	glVertex3f(-98.17 / s, 5.66 / s, 0.0f);
	glVertex3f(97.69f / s, 5.70f / s, 0.0f);
	glVertex3f(97.84f / s, 10.77f / s, 0.0f);
	glVertex3f(-98.17f / s, 10.77f / s, 0.0f);
	glEnd();

	// blue sky
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.718, 0.984);
	glVertex3f(-98.17f / s, 100.0f / s, 0.0f);

	glColor3f(0.643, 0.835, 0.976);
	glVertex3f(-98.17f / s, 10.77f / s, 0.0f);

	glColor3f(0.988, 0.761, 0.012);
	glVertex3f(97.84f / s, 10.77f / s, 0.0f);

	glColor3f(0.643, 0.835, 0.976);
	glVertex3f(97.84f / s, 100.0f / s, 0.0f);
	glEnd();

	// light silver mountain
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.427, 0.588, 0.694);
	glVertex3f(53.8413f / s, 14.3137f / s, 0.0f);
	glVertex3f(-41.6256f / s, 10.7739f / s, 0.0f);
	glVertex3f(97.84f / s, 10.77f / s, 0.0f);
	glVertex3f(45.8261f / s, 81.3451f / s, 0.0f);
	glVertex3f(-41.6256f / s, 10.7739f / s, 0.0f);
	glEnd();

	// Blue mountain
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.18, 0.42);
	glVertex3f(-43.9073f / s, 24.953f / s, 0.0f);
	glVertex3f(-6.42242f / s, 24.3011f / s, 0.0f);
	glVertex3f(-38.3661f / s, 27.3976f / s, 0.0f);
	glVertex3f(-46.8409f / s, 29.8423f / s, 0.0f);
	glVertex3f(-52.8711f / s, 31.6251f / s, 0.0f);
	glVertex3f(-58.2494f / s, 33.1019f / s, 0.0f);
	glVertex3f(-64.4425f / s, 34.2427f / s, 0.0f);
	glVertex3f(-70.1467f / s, 34.2427f / s, 0.0f);
	glVertex3f(-75.199f / s, 33.7538f / s, 0.0f);
	glVertex3f(-79.9254f / s, 32.7759f / s, 0.0f);
	glVertex3f(-98.3419f / s, 27.0717f / s, 0.0f);
	glVertex3f(-98.17f / s, 10.77f / s, 0.0f);
	glVertex3f(-41.6256f / s, 10.7739f / s, 0.0f);
	glVertex3f(-6.42242f / s, 24.3011f / s, 0.0f);
	glEnd();

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

	// bird 1
	glLoadIdentity();
	glTranslatef(-4.0f, 3.2f, -10.0f);
	glTranslatef(xMove, 3.2f, -11.0f);

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
	glTranslatef(xMove, 3.2f, -11.0f);

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
	glTranslatef(-xMove +0.5, 3.2f, -11.0f);

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
	glTranslatef(-xMove * 0.3, 0.7827f, -8.0f);
	glScalef(4.5f, 4.5f, 4.5f);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.949, 0.945, 0.902);
	glVertex3f(-77.9159f / s, 38.207f /s, 0.0f);
	glVertex3f(-72.3219f / s, 37.2294f /s, 0.0f);
	glVertex3f(-75.309f / s, 37.0122f /s, 0.0f);
	glVertex3f(-79.5995f / s, 34.7311f /s, 0.0f);
	glVertex3f(-81.2932f / s, 34.5682f /s, 0.0f);
	glVertex3f(-82.8582f / s, 35.2199f /s, 0.0f);
	glVertex3f(-85.5738f / s, 34.5682f /s, 0.0f);
	glVertex3f(-87.366f / s, 35.1656f /s, 0.0f);
	glVertex3f(-88.8324f / s, 36.3061f /s, 0.0f);
	glVertex3f(-89.5928f / s, 38.0441f /s, 0.0f);
	glVertex3f(-89.2669f / s, 39.2932f /s, 0.0f);
	glVertex3f(-88.0178f / s, 40.7053f /s, 0.0f);
	glVertex3f(-86.1712f / s, 41.4657f /s, 0.0f);
	glVertex3f(-84.2703f / s, 41.8459f /s, 0.0f);
	glVertex3f(-83.7929f / s, 42.8349f /s, 0.0f);
	glVertex3f(-83.0212f / s, 43.5838f /s, 0.0f);
	glVertex3f(-82.0979f / s, 43.964f /s, 0.0f);
	glVertex3f(-81.0117f / s, 44.0183f /s, 0.0f);
	glVertex3f(-79.9254f / s, 43.6924f /s, 0.0f);
	glVertex3f(-78.7306f / s, 42.7148f /s, 0.0f);
	glVertex3f(-77.1012f / s, 41.0312f /s, 0.0f);
	glVertex3f(-75.8521f / s, 41.6286f /s, 0.0f);
	glVertex3f(-74.6572f / s, 42.2804f /s, 0.0f);
	glVertex3f(-73.4081f / s, 42.4976f /s, 0.0f);
	glVertex3f(-72.3219f / s, 42.0088f /s, 0.0f);
	glVertex3f(-71.8874f / s, 41.0312f /s, 0.0f);
	glVertex3f(-72.2132f / s, 38.9674f /s, 0.0f);
	glVertex3f(-66.1847f / s, 38.4243f /s, 0.0f);
	glVertex3f(-65.533f / s, 37.7182f /s, 0.0f);
	glVertex3f(-66.4019f / s, 37.1751f /s, 0.0f);
	glVertex3f(-66.4019f / s, 37.1751f /s, 0.0f);
	glVertex3f(-72.3219f / s, 37.2294f / s, 0.0f);
	glEnd();

	// clouds 2
	glLoadIdentity();
	glTranslatef(xMove * 0.3, 0.18f, -5.0f);
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
	glTranslatef(-xMove * 0.3, 0.48f, -5.0f);
	glScalef(7.5f, 4.5f, 4.5f);
	// clouds 3 smitas
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
	
	
	// Tree 1
	glLoadIdentity();
	glTranslatef(-4.7f, 1.98f, -20.0f);
	glScalef(2.0f, 1.0f, 1.0f);

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

	// Tree 2
	glLoadIdentity();
	glTranslatef(-5.3f, -0.29f, -8.0f);
	glScalef(1.0f, 3.0f, 1.0f);

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

	// Tree 3
	glLoadIdentity();
	glTranslatef(2.7f, 1.98f, -20.0f);
	glScalef(-1.0f, 2.0f, 1.0f);

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
	glScalef(1.0f, 2.0f, 1.0f);
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
	glScalef(1.0f, 2.0f, 1.0f);
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

	//********************************** sau ga patal turanta(mainak reused) *******************************
	glLoadIdentity();
	glTranslatef(6.0f, -4.75f, -10.0f);
	glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
	glScalef(9.55f, 9.55f, 7.55f);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.663, 0.663, 0.663);
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
	glColor3f(0.467, 0.533, 0.6);
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
	glColor3f(0.467, 0.533, 0.6);
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
	glColor3f(0.502, 0.502, 0.502);
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
	glColor3f(0.502, 0.502, 0.502);
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
	glColor3f(0.663, 0.663, 0.663);
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
	glColor3f(0.663, 0.663, 0.663);
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
	glColor3f(0.663, 0.663, 0.663);
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

	 //******************* Base of rock one color **********************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.663, 0.663, 0.663);
	glVertex3f(-4.47182f / s, -31.2442f / s, 0.0f);
	glVertex3f(80.187f / s, -32.7595f / s, 0.0f);////
	glVertex3f(43.412f / s, -32.608f / s, 0.0f);
	glVertex3f(-51.598f / s, -32.7595f / s, 0.0f);
	glVertex3f(-83.0894f / s, -32.7595f / s, 0.0f);////
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

	

}

void drawMagicalWaves(void)
{
	//******4
	
	//small triangles on water
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-45.3339f / s, -32.6563f / s, 0.0f);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-47.7525f / s, -31.1222f / s, 0.0f);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-50.0874f / s, -32.5205f / s, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-52.6972f / s, -47.8369f / s, 0.0f);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-55.7656f / s, -46.6952f / s, 0.0f);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-58.6438f / s, -48.0034f / s, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(5.31782f / s, -39.6697f / s, 0.0f);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-0.033084f / s, -37.1351f / s, 0.0f);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-5.38398f / s, -39.9514f / s, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-84.1238f / s, -34.6511f / s, 0.0f);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-86.2425f / s, -33.168f / s, 0.0f);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-88.3612f / s, -34.1459f / s, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-74.1821f / s, -46.3855f / s, 0.0f);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-76.6268f / s, -44.2668f / s, 0.0f);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-79.7234f / s, -45.7336f / s, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-29.2283f / s, -44.2514f / s, 0.0f);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(-30.5322f / s, -42.7846f / s, 0.0f);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-32.3249f / s, -44.2514f / s, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(28.4607f / s, -51.5671f / s, 0.0f);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(24.2233f / s, -49.1224f / s, 0.0f);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(19.3339f / s, -50.5892f / s, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(35.7947f / s, -34.9433f / s, 0.0f);
	glColor3f(0.376, 0.878, 1.0);
	glVertex3f(32.0462f / s, -32.8246f / s, 0.0f);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(28.4607f / s, -34.6174f / s, 0.0f);
	glEnd();
}