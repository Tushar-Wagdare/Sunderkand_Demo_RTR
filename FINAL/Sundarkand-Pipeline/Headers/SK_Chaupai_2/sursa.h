#pragma once
#include <windows.h>


void drawSursa(void)
{
	//************************************ JAW (Movement Wala Part ) **************************************
	//***** Transformations ******
	glLoadIdentity();
	glTranslatef(-0.5f + sursa_xTranslate / s, sursa_yTranslate + ySursa / s, -3.0f + sursa_zTranslate / s);
	glScalef(xScaleSursa, yScaleSursa, zScaleSursa);
	glRotatef(sursa_rotate, 0.0f, 0.0f, 1.0f);


	// Lower jaw (without teeth)
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.129, 0.361, 0.31);
	glVertex3f(1.08636f / s, 8.20033f / s, 0.0f);
	glVertex3f(6.97863f / s, 8.94532f / s, 0.0f);
	glVertex3f(41.6347f / s, 5.24064f / s, 0.0f);
	glVertex3f(34.5639f / s, -2.66313f / s, 0.0f);
	glVertex3f(11.9769f / s, -4.81008f / s, 0.0f);
	glVertex3f(7.981f / s, -5.14872f / s, 0.0f);
	glVertex3f(4.05282f / s, -6.4694f / s, 0.0f);
	glVertex3f(0.111088f / s, -8.82631f / s, 0.0f);
	glVertex3f(-13.1526f / s, -11.9959f / s, 0.0f);
	glEnd();

	// Lower jaw's 5 teeth
	glBegin(GL_TRIANGLES);
	glColor3f(0.976, 0.988, 0.894);
	glVertex3f(10.4896f / s, 8.45274f / s, 0.0f);
	glVertex3f(14.8783f / s, 15.6747f / s, 0.0f);
	glVertex3f(14.83f / s, 8.06263f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.976, 0.988, 0.894);
	glVertex3f(18.3406f / s, 7.57499f / s, 0.0f);
	glVertex3f(22.3879f / s, 14.8945f / s, 0.0f);
	glVertex3f(22.4855f / s, 7.18488f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.976, 0.988, 0.894);
	glVertex3f(24.241f / s, 7.02354f / s, 0.0f);
	glVertex3f(28.3859f / s, 14.2118f / s, 0.0f);
	glVertex3f(28.776f / s, 6.59972f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.976, 0.988, 0.894);
	glVertex3f(31.4092f / s, 6.20466f / s, 0.0f);
	glVertex3f(35.1152f / s, 13.7242f / s, 0.0f);
	glVertex3f(35.9442f / s, 5.8f / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.976, 0.988, 0.894);
	glVertex3f(38.0898f / s, 5.8f / s, 0.0f);
	glVertex3f(41.3082f / s, 13.0902f / s, 0.0f);
	glVertex3f(41.6347f / s, 5.0f / s, 0.0f);
	glEnd();


	//************************************ Horn (Backside) *********************************************
	//***** Transformations ******
	glLoadIdentity();
	glTranslatef(-0.5f + sursa_xTranslate / s, sursa_yTranslate + ySursa / s, -3.0f + sursa_zTranslate / s);
	glScalef(xScaleSursa, yScaleSursa, zScaleSursa);

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(1.71499f / s, 53.5908f / s, 0.0f);
	glVertex3f(-8.11577f / s, 74.8323f / s, 0.0f);
	glVertex3f(-8.40835f / s, 50.782f / s, 0.0f);
	glEnd();


	//*********************************** Sursa Main Body **********************************************

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.129, 0.361, 0.31);
	glVertex3f(-10.1f / s, 39.6f / s, 0.0f);
	glVertex3f(-2.3f / s, -20.1f / s, 0.0f);
	glVertex3f(1.0f / s, 8.2f / s, 0.0f);
	glVertex3f(5.6f / s, 19.7f / s, 0.0f);
	glVertex3f(41.6f / s, 29.3f / s, 0.0f);
	glVertex3f(45.5f / s, 36.5f / s, 0.0f);
	glVertex3f(43.3f / s, 40.0f / s, 0.0f);
	glVertex3f(40.1f / s, 43.2f / s, 0.0f);
	glVertex3f(36.2f / s, 46.8f / s, 0.0f);
	glVertex3f(29.6f / s, 50.8f / s, 0.0f);
	glVertex3f(24.2f / s, 53.2f / s, 0.0f);
	glVertex3f(19.8f / s, 58.2f / s, 0.0f);
	glVertex3f(15.4f / s, 60.5f / s, 0.0f);
	glVertex3f(9.2f / s, 61.6f / s, 0.0f);
	glVertex3f(0.6f / s, 61.5f / s, 0.0f);
	glVertex3f(-30.8f / s, 62.9f / s, 0.0f);
	glVertex3f(-25.1f / s, 54.4f / s, 0.0f);
	glVertex3f(-46.9f / s, 51.7f / s, 0.0f);
	glVertex3f(-36.7f / s, 44.2f / s, 0.0f);
	glVertex3f(-59.9f / s, 37.2f / s, 0.0f);
	glVertex3f(-47.6f / s, 30.9f / s, 0.0f);
	glVertex3f(-70.1f / s, 19.2f / s, 0.0f);
	glVertex3f(-51.2f / s, 20.1f / s, 0.0f);
	glVertex3f(-69.6f / s, -0.6f / s, 0.0f);
	glVertex3f(-57.5f / s, 0.8f / s, 0.0f);
	glVertex3f(-64.4f / s, -24.8f / s, 0.0f);
	glVertex3f(-52.9f / s, -14.5f / s, 0.0f);
	glVertex3f(-2.3f / s, -20.1f / s, 0.0f);
	glEnd();


	//************************************ Upper jaw's 5 teeth ********************************
	glBegin(GL_TRIANGLES);
	glColor3f(0.976, 0.988, 0.894);
	glVertex3f(9.51174 / s, 20.9837 / s, 0.0f);
	glVertex3f(10.0928 / s, 14.592 / s, 0.0f);
	glVertex3f(12.417 / s, 21.739 / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.976, 0.988, 0.894);
	glVertex3f(17.4142 / s, 22.9593 / s, 0.0f);
	glVertex3f(18.7987 / s, 17.2649 / s, 0.0f);
	glVertex3f(21.5397 / s, 24.0633 / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.976, 0.988, 0.894);
	glVertex3f(25.2585 / s, 25.1573 / s, 0.0f);
	glVertex3f(26.7693 / s, 19.5891 / s, 0.0f);
	glVertex3f(29.7327 / s, 26.2713 / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.976, 0.988, 0.894);
	glVertex3f(32.4636 / s, 27.0267 / s, 0.0f);
	glVertex3f(33.5677 / s, 21.739  / s, 0.0f);
	glVertex3f(36.7635 / s, 28.0726 / s, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.976, 0.988, 0.894);
	glVertex3f(37.8094 / s, 28.5956 / s, 0.0f);
	glVertex3f(38.9715 / s, 22.8431 / s, 0.0f);
	glVertex3f(41.6677 / s, 29.3974 / s, 0.0f);
	glEnd();


	//************************************ Horn (Front) *********************************************
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-48.1703  / s, 70.0949  / s, 0.0f);
	glVertex3f(-22.478  / s, 41.7809  / s, 0.0f);
	glVertex3f(-13.04  / s, 49.1216  / s, 0.0f);
	glEnd();


    //*********************************** SURSA TaIL ************************************************
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.129, 0.361, 0.31);
	glVertex3f(-2.3f / s, -20.1f / s, 0.0f);
	glVertex3f(-52.2f / s, -14.5f / s, 0.0f);
	glVertex3f(0.0f / s, -24.8f / s, 0.0f);
	glVertex3f(-50.6f / s, -19.9f / s, 0.0f);
	glVertex3f(3.3f / s, -30.2f / s, 0.0f);
	glVertex3f(-44.2f / s, -30.5f / s, 0.0f);
	glVertex3f(6.3f / s, -36.4f / s, 0.0f);
	glVertex3f(-40.3f / s, -35.3f / s, 0.0f);
	glVertex3f(7.5f / s, -42.6f / s, 0.0f);
	glVertex3f(-38.4f / s, -40.2f / s, 0.0f);
	glVertex3f(8.2f / s, -49.7f / s, 0.0f);
	glVertex3f(-37.2f / s, -46.7f / s, 0.0f);
	glVertex3f(5.5f / s, -57.0f / s, 0.0f);
	glVertex3f(-37.8f / s, -54.8f / s, 0.0f);
	glVertex3f(2.5f / s, -63.1f / s, 0.0f);
	glVertex3f(-39.6f / s, -62.4f / s, 0.0f);
	glVertex3f(-0.7f / s, -70.7f / s, 0.0f);
	glVertex3f(-41.7f / s, -67.3f / s, 0.0f);
	glVertex3f(-4.8f / s, -76.3f / s, 0.0f);
	glVertex3f(-44.4f / s, -72.3f / s, 0.0f);
	glVertex3f(-10.1f / s, -81.4f / s, 0.0f);
	glVertex3f(-49.1f / s, -76.7f / s, 0.0f);
	glVertex3f(-20.5f / s, -90.8f / s, 0.0f);
	glVertex3f(-56.5f / s, -82.0f / s, 0.0f);
	glVertex3f(-22.5f / s, -101.1f / s, 0.0f);
	glVertex3f(-58.4f / s, -89.9f / s, 0.0f);
	glVertex3f(-19.6f / s, -106.5f / s, 0.0f);
	glVertex3f(-52.1f / s, -99.5f / s, 0.0f);
	glVertex3f(20.6f / s, -126.8f / s, 0.0f);
	glEnd();

	//*** Line (tail)***
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f,0.0f,0.0f);
	glVertex3f(1.0f / s, 8.2f / s, 0.0f);
	glVertex3f(-10.0f / s, 4.2f / s, 0.0f);
	glVertex3f(-20.2f / s, -2.9f / s, 0.0f);
	glVertex3f(-24.0f / s, -10.1f / s, 0.0f);
	glVertex3f(-20.7f / s, -19.5f / s, 0.0f);
	glVertex3f(-16.0f / s, -28.0f / s, 0.0f);
	glVertex3f(-14.0f / s, -39.0f / s, 0.0f);
	glVertex3f(-14.0f / s, -50.0f / s, 0.0f);
	glVertex3f(-17.0f / s, -60.0f / s, 0.0f);
	glVertex3f(-23.0f / s, -70.0f / s, 0.0f);
	glVertex3f(-29.0f / s, -80.0f / s, 0.0f);
	glVertex3f(-35.0f / s, -87.0f / s, 0.0f);
	glVertex3f(-39.0f / s, -95.0f / s, 0.0f);
	glVertex3f(-37.0f / s, -105.0f / s, 0.0f);
	glEnd();



	//********************************** Sursa EYE *************************************************
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.216, 0.059, 0.098);
	glVertex3f(19.9f / s, 42.5f / s, 0.0f);
	glVertex3f(22.9f / s, 39.3f / s, 0.0f);
	glVertex3f(24.0f / s, 41.7f / s, 0.0f);
	glVertex3f(22.2f / s, 43.8f / s, 0.0f);
	glVertex3f(21.9f / s, 45.4f / s, 0.0f);
	glVertex3f(19.6f / s, 46.7f / s, 0.0f);
	glVertex3f(17.4f / s, 46.1f / s, 0.0f);
	glVertex3f(16.3f / s, 44.6f / s, 0.0f);
	glVertex3f(16.5f / s, 42.4f / s, 0.0f);
	glVertex3f(18.0f / s, 39.9f / s, 0.0f);
	glVertex3f(22.9f / s, 39.3f / s, 0.0f);
	glEnd();


	if (bSursa == FALSE)
	{
		//*** EYE center ***
		glPointSize(7);
		glBegin(GL_POINTS);
		glColor3f(0.557, 0.122, 0.118);
		glVertex3f(19.9f / s, 42.5f / s, 0.0f);
		glEnd();
	}

}

