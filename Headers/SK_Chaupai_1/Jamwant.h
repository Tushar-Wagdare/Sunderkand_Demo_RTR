#pragma once

#include <windows.h>

#define PI 3.14159265359


void drawJamwant(void)
{

	///////////////////////////////////////////////////TRANSFORMATIONS/////////////////////////////////////////////////////////
	glLoadIdentity();
	glTranslatef(-0.0f, 0.0f, -8.0f);
	glScalef(0.40f, 0.40f, 0.40f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Crown
	glBegin(GL_POLYGON); //crown tip
	glColor3f(0.984, 0.914, 0.008);
	glVertex3f(0.399696f, 2.35704f, 0.0f);
	glVertex3f(0.423208f, 2.32177f, 0.0f);
	glVertex3f(0.464353f, 2.35116f, 0.0f);
	glVertex3f(0.434964f, 2.38643f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.984, 0.914, 0.008);
	glVertex3f(0.387941f, 2.19833f, 0.0f);
	glVertex3f(0.423208f, 2.32177f, 0.0f);
	glVertex3f(0.30565f, 2.2865f, 0.0f);
	glVertex3f(0.270383f, 2.2336f, 0.0f);
	glVertex3f(0.217482f, 2.19245f, 0.0f);
	glVertex3f(0.146947f, 2.17482f, 0.0f);
	glVertex3f(0.129314f, 2.10428f, 0.0f);
	glVertex3f(0.211604f, 2.05726f, 0.0f);
	glVertex3f(0.30565f, 2.03963f, 0.0f);
	glVertex3f(0.423208f, 2.02963f, 0.0f);
	glVertex3f(0.552522f, 2.03963f, 0.0f);
	glVertex3f(0.623056f, 2.08665f, 0.0f);
	glVertex3f(0.540766f, 2.15131f, 0.0f);
	glVertex3f(0.505499f, 2.24535f, 0.0f);
	glVertex3f(0.423208f, 2.32177f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.984, 0.914, 0.008);
	glVertex3f(0.288017f, 1.90619f, 0.0f);
	glVertex3f(0.30565f, 2.03963f, 0.0f);
	glVertex3f(0.211604f, 2.05726f, 0.0f);
	glVertex3f(0.129314f, 2.10428f, 0.0f);
	glVertex3f(0.017634f, 2.06902f, 0.0f);
	glVertex3f(-0.047023f, 2.00436f, 0.0f);
	glVertex3f(-0.08229f, 1.89856f, 0.0f);
	glVertex3f(-0.070535f, 1.82802f, 0.0f);
	glVertex3f(0.593667f, 1.73398f, 0.0f);
	glVertex3f(0.64069f, 1.8339f, 0.0f);
	glVertex3f(0.646568f, 1.93383f, 0.0f);
	glVertex3f(0.552522f, 2.03963f, 0.0f);
	glVertex3f(0.423208f, 2.02963f, 0.0f);
	glVertex3f(0.30565f, 2.03963f, 0.0f);
	glEnd();


	//mouth
	glBegin(GL_POLYGON);
	glColor3f(0.58, 0.58, 0.58);
	glVertex3f(0.042125f, 1.81333f, 0.0f);
	glVertex3f(-0.070535f, 1.82802f, 0.0f);
	glVertex3f(-0.158861f, 1.78376f, 0.0f);
	glVertex3f(-0.403725f, 1.57563f, 0.0f);
	glVertex3f(-0.373117f, 1.4532f, 0.0f);
	glVertex3f(-0.299658f, 1.41034f, 0.0f);
	glVertex3f(-0.104662f, 1.40187f, 0.0f);
	glVertex3f(0.081311f, 1.54882f, 0.0f);
	glEnd();

	//side-face
	glBegin(GL_POLYGON);
	glColor3f(0.388, 0.388, 0.388);
	glVertex3f(0.302711f, 1.77316f, 0.0f);
	glVertex3f(0.042125f, 1.81333f, 0.0f);
	glVertex3f(0.081311f, 1.54882f, 0.0f);
	glVertex3f(-0.104662f, 1.40187f, 0.0f);
	glVertex3f(0.026747f, 1.30013f, 0.0f);
	glVertex3f(0.081855f, 1.22807f, 0.0f);
	glVertex3f(0.295362f, 1.4397f, 0.0f);
	glEnd();

	//head back fur
	glBegin(GL_POLYGON);
	glColor3f(0.188, 0.192, 0.184);
	glVertex3f(0.593667f, 1.73398f, 0.0f);
	glVertex3f(0.302711f, 1.77316f, 0.0f);
	glVertex3f(0.30026f, 1.55726f, 0.0f);
	glVertex3f(0.295362f, 1.4397f, 0.0f);
	glVertex3f(0.295362f, 1.4397f, 0.0f);
	glVertex3f(0.081855f, 1.22807f, 0.0f);
	glVertex3f(0.10305f, 1.14329f, 0.0f);
	glVertex3f(0.10305f, 1.0034f, 0.0f);
	glVertex3f(0.548148f, 1.21535f, 0.0f);
	glVertex3f(0.637168f, 1.24926f, 0.0f);
	glVertex3f(0.679558f, 1.30861f, 0.0f);
	glEnd();

	//Eye
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-0.031188f, 1.78884f, 0.0f);
	glVertex3f(-0.080171f, 1.72026f, 0.0f);
	glVertex3f(-0.036086f, 1.69087f, 0.0f);
	glVertex3f(0.007998f, 1.72516f, 0.0f);
	glEnd();

	//Nose
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-0.290795f, 1.65169f, 0.0f);
	glVertex3f(-0.403725f, 1.57563f, 0.0f);
	glVertex3f(-0.373117f, 1.4532f, 0.0f);
	glVertex3f(-0.2761f, 1.55862f, 0.0f);
	glEnd();


	glLoadIdentity();
	glTranslatef(-0.0f, 0.0f, -8.0f);
	glScalef(0.40f, 0.40f, 0.40f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(-cap_angle*2, 0.0f, 0.0f, 1.0f);
	//Right hand
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.188, 0.192, 0.184);
	glVertex3f(-0.265895f, 0.596114f, 0.0f);
	glVertex3f(-0.328376f, 0.802142f, 0.0f);
	glVertex3f(-0.389604f, 0.883779f, 0.0f);
	glVertex3f(-0.463077f, 0.883779f, 0.0f);
	glVertex3f(-0.712072f, 0.977662f, 0.0f);
	glVertex3f(-0.846773f, 1.07563f, 0.0f);
	glVertex3f(-0.989639f, 1.12461f, 0.0f);
	glVertex3f(-1.07944f, 1.07971f, 0.0f);
	glVertex3f(-1.07536f, 0.989908f, 0.0f);
	glVertex3f(-1.09169f, 0.900107f, 0.0f);
	glVertex3f(-1.03862f, 0.818469f, 0.0f);
	glVertex3f(-0.961066f, 0.736832f, 0.0f);
	glVertex3f(-0.863101f, 0.708259f, 0.0f);
	glVertex3f(-0.675335f, 0.62254f, 0.0f);
	glVertex3f(-0.646762f, 0.549066f, 0.0f);
	glVertex3f(-0.540633f, 0.553148f, 0.0f);
	glVertex3f(-0.272698f, 0.317186f, 0.0f);
	glVertex3f(-0.014072f, 0.630703f, 0.0f);
	glVertex3f(0.10305f, 1.0034f, 0.0f);
	glVertex3f(0.081855f, 1.22807f, 0.0f);
	glVertex3f(0.026747f, 1.30013f, 0.0f);
	glVertex3f(-0.128364f, 1.14094f, 0.0f);
	glVertex3f(-0.161019f, 1.08787f, 0.0f);
	glVertex3f(-0.328376f, 0.802142f, 0.0f);
	glEnd();


	//right  palm
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(-0.712072f, 0.977662f, 0.0f);
	glVertex3f(-0.846773f, 1.07563f, 0.0f);
	glVertex3f(-0.989639f, 1.12461f, 0.0f);
	glVertex3f(-1.07944f, 1.07971f, 0.0f);
	glVertex3f(-1.07536f, 0.989908f, 0.0f);
	glVertex3f(-1.09169f, 0.900107f, 0.0f);
	glVertex3f(-1.03862f, 0.818469f, 0.0f);
	glVertex3f(-0.961066f, 0.736832f, 0.0f);
	glVertex3f(-0.863101f, 0.708259f, 0.0f);
	glVertex3f(-0.740645f, 0.822551f, 0.0f);
	glEnd();

	//right-bangle
	glBegin(GL_POLYGON);
	glColor3f(0.882, 0.725, 0.169);
	glVertex3f(-0.389604f, 0.883779f, 0.0f);
	glVertex3f(-0.463077f, 0.883779f, 0.0f);
	glVertex3f(-0.675335f, 0.62254f, 0.0f);
	glVertex3f(-0.646762f, 0.549066f, 0.0f);
	glVertex3f(-0.540633f, 0.553148f, 0.0f);
	glVertex3f(-0.328376f, 0.802142f, 0.0f);
	glEnd();


	glLoadIdentity();
	glTranslatef(-0.0f, 0.0f, -8.0f);
	glScalef(0.40f, 0.40f, 0.40f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	//abdomen
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.388, 0.388, 0.388);
	glVertex3f(-0.065203f, 0.402225f, 0.0f);
	glVertex3f(0.10305f, 1.0034f, 0.0f);
	glVertex3f(0.10305f, 1.14329f, 0.0f);
	glVertex3f(0.081855f, 1.22807f, 0.0f);
	glVertex3f(-0.024384f, 1.10975f, 0.0f);
	glVertex3f(-0.099219f, 1.0043f, 0.0f);
	glVertex3f(-0.228478f, 0.881845f, 0.0f);
	glVertex3f(-0.32032f, 0.704964f, 0.0f);
	glVertex3f(-0.265895f, 0.596114f, 0.0f);
	glVertex3f(-0.272698f, 0.317186f, 0.0f);
	glVertex3f(-0.361139f, 0.089282f, 0.0f);
	glVertex3f(-0.32032f, -0.043379f, 0.0f);
	glVertex3f(0.31237f, -0.02297f, 0.0f);
	glVertex3f(0.376999f, 0.187927f, 0.0f);
	glVertex3f(0.431424f, 0.538287f, 0.0f);
	glVertex3f(0.281756f, 0.834223f, 0.0f);
	glVertex3f(0.387065f, 1.13905f, 0.0f);
	glVertex3f(0.10305f, 1.0034f, 0.0f);
	glEnd();

	//back
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.188, 0.192, 0.184);
	glVertex3f(0.543675f, 0.766191f, 0.0f);
	glVertex3f(0.637168f, 1.24926f, 0.0f);
	glVertex3f(0.548148f, 1.21535f, 0.0f);
	glVertex3f(0.548148f, 1.21535f, 0.0f);
	glVertex3f(0.387065f, 1.13905f, 0.0f);
	glVertex3f(0.281756f, 0.834223f, 0.0f);
	glVertex3f(0.431424f, 0.538287f, 0.0f);
	glVertex3f(0.376999f, 0.187927f, 0.0f);
	glVertex3f(0.31237f, -0.02297f, 0.0f);
	glVertex3f(0.717155f, 0.119896f, 0.0f);
	glVertex3f(0.734163f, 0.39202f, 0.0f);
	glVertex3f(0.68314f, 0.511075f, 0.0f);
	glVertex3f(0.703549f, 0.626728f, 0.0f);
	glVertex3f(0.72736f, 0.837624f, 0.0f);
	glVertex3f(0.713754f, 1.08254f, 0.0f);
	glVertex3f(0.637168f, 1.24926f, 0.0f);
	glEnd();

	//gold necklace
	glPointSize(10.0f);
	glBegin(GL_POINTS);
	glColor3f(0.914, 0.725, 0.106);
	glVertex3f(0.024384f, 1.10975f, 0.0f);
	glVertex3f(-0.052957f, 1.01995f, 0.0f);
	glVertex3f(-0.057039f, 0.93423f, 0.0f);
	glVertex3f(-0.048875f, 0.832183f, 0.0f);
	glVertex3f(0.02868f, 0.754627f, 0.0f);
	glVertex3f(0.147055f, 0.770955f, 0.0f);
	glVertex3f(0.220528f, 0.84851f, 0.0f);
	glEnd();

	
	//


	
	
	//Left hand
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.25, 0.25, 0.25);
	glVertex3f(0.543675f, 0.766191f, 0.0f);
	glVertex3f(0.679558f, 1.30861f, 0.0f);
	glVertex3f(0.548148f, 1.21535f, 0.0f);
	glVertex3f(0.387065f, 1.13905f, 0.0f);
	glVertex3f(0.325837f, 0.971693f, 0.0f);
	glVertex3f(0.281756f, 0.834223f, 0.0f);
	glVertex3f(0.295862f, 0.528973f, 0.0f);
	glVertex3f(0.108096f, 0.357534f, 0.0f);
	glVertex3f(-0.018442f, 0.320797f, 0.0f);
	glVertex3f(-0.083752f, 0.23916f, 0.0f);
	glVertex3f(-0.206208f, 0.124868f, 0.0f);
	glVertex3f(-0.32032f, -0.043379f, 0.0f);
	glVertex3f(-0.32032f, -0.043379f, 0.0f);
	glVertex3f(-0.287845f, -0.095553f, 0.0f);
	glVertex3f(-0.361139f, -0.11141f, 0.0f);
	glVertex3f(-0.361319f, -0.226173f, 0.0f);
	glVertex3f(-0.263354f, -0.242501f, 0.0f);
	glVertex3f(-0.120489f, -0.181273f, 0.0f);
	glVertex3f(0.02918f, -0.082628f, 0.0f);
	glVertex3f(0.11626f, 0.022821f, 0.0f);
	glVertex3f(0.206061f, 0.002412f, 0.0f);
	glVertex3f(0.263207f, 0.161605f, 0.0f);
	glVertex3f(0.491792f, 0.296306f, 0.0f);
	glVertex3f(0.68314f, 0.511075f, 0.0f);
	glVertex3f(0.703549f, 0.626728f, 0.0f);
	glVertex3f(0.81426f, 0.761639f, 0.0f);
	glVertex3f(0.842833f, 0.949405f, 0.0f);
	glVertex3f(0.789768f, 1.15758f, 0.0f);
	glVertex3f(0.679558f, 1.30861f, 0.0f);
	glEnd();

	//Left palm
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex3f(-0.361139f, -0.11141f, 0.0f);
	glVertex3f(-0.361319f, -0.226173f, 0.0f);
	glVertex3f(-0.263354f, -0.242501f, 0.0f);
	glVertex3f(-0.120489f, -0.181273f, 0.0f);
	glEnd();

	//Left kada
	glBegin(GL_POLYGON);
	glColor3f(0.859, 0.698, 0.133);
	glVertex3f(0.206061f, 0.002412f, 0.0f);
	glVertex3f(0.263207f, 0.161605f, 0.0f);
	glVertex3f(0.067278f, 0.373861f, 0.0f);
	glVertex3f(-0.018442f, 0.320797f, 0.0f);
	glEnd();


	
	//dhoti-left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(-0.266462f, -0.449865f, 0.0f);
	glVertex3f(0.02918f, -0.082628f, 0.0f);
	glVertex3f(-0.120489f, -0.181273f, 0.0f);
	glVertex3f(-0.263354f, -0.242501f, 0.0f);
	glVertex3f(-0.361319f, -0.226173f, 0.0f);
	glVertex3f(-0.43654f, -0.747501f, 0.0f);
	glVertex3f(-0.252289f, -0.707816f, 0.0f);
	glVertex3f(0.02918f, -0.082628f, 0.0f);
	glEnd();

	glLineWidth(7.0f);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.831, 0.788, 0.31);
	glVertex3f(-0.43654f, -0.747501f, 0.0f);
	glVertex3f(-0.252289f, -0.707816f, 0.0f);
	glEnd();

	//dhoti-centre
	glBegin(GL_POLYGON);
	glColor3f(0.467, 0.039, 0.0);
	glVertex3f(0.11626f, 0.022821f, 0.0f);
	glVertex3f(0.02918f, -0.082628f, 0.0f);
	glVertex3f(-0.252289f, -0.707816f, 0.0f);
	glVertex3f(-0.277801f, -0.91191f, 0.0f);
	glVertex3f(0.104875f, -0.818367f, 0.0f);
	glVertex3f(0.042513f, -0.730493f, 0.0f);
	glVertex3f(0.051017f, -0.537738f, 0.0f);
	glVertex3f(0.11626f, 0.022821f, 0.0f);
	glEnd();

	glLineWidth(7.0f);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.831, 0.788, 0.31);
	glVertex3f(-0.277801f, -0.91191f, 0.0f);
	glVertex3f(0.104875f, -0.818367f, 0.0f);
	glEnd();

	//dhoti-right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.024, 0.467);
	glVertex3f(0.37133f, -0.353487f, 0.0f);
	glVertex3f(0.717155f, 0.119896f, 0.0f);
	glVertex3f(0.31237f, -0.02297f, 0.0f);
	glVertex3f(0.206061f, 0.002412f, 0.0f);
	glVertex3f(0.11626f, 0.022821f, 0.0f);
	glVertex3f(0.051017f, -0.537738f, 0.0f);
	glVertex3f(0.042513f, -0.730493f, 0.0f);
	glVertex3f(0.215425f, -0.707816f, 0.0f);
	glVertex3f(0.470542f, -0.738997f, 0.0f);
	glVertex3f(0.654793f, -0.784351f, 0.0f);
	glVertex3f(0.674636f, -0.438526f, 0.0f);
	glVertex3f(0.731328f, -0.299629f, 0.0f);
	glVertex3f(0.717155f, 0.119896f, 0.0f);
	glEnd();

	glLineWidth(7.0f);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.831, 0.788, 0.31);
	glVertex3f(0.042513f, -0.730493f, 0.0f);
	glVertex3f(0.215425f, -0.707816f, 0.0f);
	glVertex3f(0.470542f, -0.738997f, 0.0f);
	glVertex3f(0.654793f, -0.784351f, 0.0f);
	glEnd();

	glLineWidth(11.0f);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.467, 0.039, 0.0);
	glVertex3f(0.02918f, -0.082628f, 0.0f);
	glVertex3f(0.261847f, -0.094874f, 0.0f);
	glVertex3f(0.714934f, -0.005072f, 0.0f);
	glEnd();

	//Legs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.161, 0.161, 0.161);
	glVertex3f(0.047049f, -1.5531f, 0.0f);
	glVertex3f(0.654793f, -0.784351f, 0.0f);
	glVertex3f(0.470542f, -0.738997f, 0.0f);
	glVertex3f(0.215425f, -0.707816f, 0.0f);
	glVertex3f(0.042513f, -0.730493f, 0.0f);
	glVertex3f(0.104875f, -0.818367f, 0.0f);
	glVertex3f(-0.277801f, -0.91191f, 0.0f);
	glVertex3f(-0.252289f, -0.707816f, 0.0f);
	glVertex3f(-0.43654f, -0.747501f, 0.0f);
	glVertex3f(-0.401957f, -1.01226f, 0.0f);
	glVertex3f(-0.306713f, -1.31499f, 0.0f);
	glVertex3f(-0.303312f, -1.5463f, 0.0f);
	glVertex3f(-0.197864f, -1.84224f, 0.0f);
	glVertex3f(-0.194462f, -2.01231f, 0.0f);
	glVertex3f(-0.163848f, -2.11096f, 0.0f);
	glVertex3f(-0.42917f, -2.21301f, 0.0f);
	glVertex3f(-0.493799f, -2.27083f, 0.0f);
	glVertex3f(-0.476791f, -2.36948f, 0.0f);
	glVertex3f(-0.306714f, -2.38649f, 0.0f);
	glVertex3f(-0.187659f, -2.46472f, 0.0f);
	glVertex3f(0.227331f, -2.33206f, 0.0f);
	glVertex3f(0.411015f, -2.32526f, 0.0f);
	glVertex3f(0.485849f, -2.25382f, 0.0f);
	glVertex3f(0.489251f, -2.13137f, 0.0f);
	glVertex3f(0.455235f, -2.00551f, 0.0f);
	glVertex3f(0.53007f, -1.77761f, 0.0f);
	glVertex3f(0.533471f, -1.45106f, 0.0f);
	glVertex3f(0.550479f, -1.38303f, 0.0f);
	glVertex3f(0.553881f, -1.01226f, 0.0f);
	glVertex3f(0.654793f, -0.784351f, 0.0f);
	glEnd();

	//legs partition line
	glLineWidth(2.0f);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.00, 0.0);
	glVertex3f(-0.014179f, -0.87551f, 0.0f);
	glVertex3f(-0.022343f, -1.13267f, 0.0f);
	glVertex3f(0.047049f, -1.5531f, 0.0f);
	glVertex3f(0.104195f, -1.94904f, 0.0f);
	glEnd();

	glLineWidth(7.0f);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.00, 0.0);
	glVertex3f(-0.42917f, -2.21301f, 0.0f);
	glVertex3f(-0.493799f, -2.27083f, 0.0f);
	glVertex3f(-0.476791f, -2.36948f, 0.0f);
	glVertex3f(-0.306714f, -2.38649f, 0.0f);
	glVertex3f(-0.261813f, -2.28036f, 0.0f);
	glVertex3f(-0.061802f, -2.19872f, 0.0f);
	glVertex3f(-0.261813f, -2.28036f, 0.0f);
	glVertex3f(-0.306714f, -2.38649f, 0.0f);
	glVertex3f(-0.187659f, -2.46472f, 0.0f);
	glVertex3f(-0.057039f, -2.40757f, 0.0f);
	glEnd();

}