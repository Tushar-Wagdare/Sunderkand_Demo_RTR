#include<windows.h>

void conveyorSurface(void)
{
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(6.5f, -0.275f, 0.0f);
	glVertex3f(-7.5f, -0.275f, 0.0f);
	glVertex3f(-7.5f, -0.3f, 0.0f);
	glVertex3f(6.5f, -0.3f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(6.5f, -0.5f, 0.0f);
	glVertex3f(-7.5f, -0.5f, 0.0f);
	glVertex3f(-7.5f, -0.575f, 0.0f);
	glVertex3f(6.5f, -0.575f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.613f, 0.615f, 0.58f);
	glVertex3f(6.5f, -0.3f, 0.0f);
	glVertex3f(-7.5f, -0.3f, 0.0f);
	glVertex3f(-7.5f, -0.5f, 0.0f);
	glVertex3f(6.5f, -0.5f, 0.0f);
	glEnd();
}

void conveyorTiles(void)
{
	glLineWidth(1.2f);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f - 7.5, -0.3f, 0.0f);
	glVertex3f(-0.075f - 7.5, -0.5f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.02f - 7.5, -0.3f, 0.0f);
	glVertex3f(-0.055f - 7.5, -0.5f, 0.0f);
	glEnd();
}

void drawConveyor(void)
{
	void conveyorSurface(void);
	void conveyorTiles(void);

	conveyorSurface();

	conveyorTiles();
	//glTranslatef(-3.5f, 0.0f, 0.0f);
	GLfloat i;
	for (i = 0.0; i < 3.5; i = i + 0.01)
	{
		glTranslatef(0.1f, 0.0f, 0.0f);
		conveyorTiles();
	}
}

void drawBoard(void)
{
	//glBegin(GL_QUADS);
	//glColor3f(0.4f, 0.2f, 0.0f);
	//glVertex3f(-0.65f, -0.1f, 0.0f);
	//glVertex3f(-0.65f -0.075f, -0.65f, 0.0f);
	//glVertex3f(0.65f - 0.075f, -0.65f, 0.0f);
	//glVertex3f(0.65f, -0.1f, 0.0f);
	//glEnd();

	//glBegin(GL_QUADS);
	//glColor3f(0.87f, 0.721f, 0.529f);
	//glVertex3f(-0.6f, -0.15f, 0.0f);
	//glVertex3f(-0.6f - 0.075f, -0.6f, 0.0f);
	//glVertex3f(0.6f - 0.075f, -0.6f, 0.0f);
	//glVertex3f(0.6f, -0.15f, 0.0f);
	//glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.2f, 0.0f);
	glVertex3f(-0.65f, -0.1f, -0.01f);
	glVertex3f(-0.65f, -0.65f, -0.01f);
	glVertex3f(0.65f, -0.65f, -0.01f);
	glVertex3f(0.65f, -0.1f, -0.01f);
	glEnd();




	glBegin(GL_QUADS);
	glColor3f(0.87f, 0.721f, 0.529f);
	glVertex3f(-0.6f, -0.15f, 0.0f);
	glVertex3f(-0.6f, -0.6f, 0.0f);
	glVertex3f(0.6f, -0.6f, 0.0f);
	glVertex3f(0.6f, -0.15f, 0.0f);
	glEnd();

}

void drawBoardTopView(void)
{
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.2f, 0.0f);
	glVertex3f(-1.55f, 0.85f, 0.0f);
	glVertex3f(-1.55f, -0.85f, 0.0f);
	glVertex3f(1.55f, -0.85f, 0.0f);
	glVertex3f(1.55f, 0.85f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.87f, 0.721f, 0.529f);
	glVertex3f(-1.5f, 0.8f, 0.0f);
	glVertex3f(-1.5f, -0.8f, 0.0f);
	glVertex3f(1.5f, -0.8f, 0.0f);
	glVertex3f(1.5f, 0.8f, 0.0f);
	glEnd();

}

void bg_frame_crossbar(void)
{
	glBegin(GL_QUADS);
	glColor3f(0.827f, 0.827f, 0.827f);
	glVertex3f(-2.0f, 1.2f, 0.0f);
	glVertex3f(-1.7f, 1.175f - 0.2, 0.0f);
	glVertex3f(-1.68f, 1.175f - 0.2, 0.0f);
	glVertex3f(-1.98f, 1.2f, 0.0f);

	glBegin(GL_QUADS);
	glColor3f(0.827f, 0.827f, 0.827f);
	glVertex3f(-2.0f, 1.175f - 0.2, 0.0f);
	glVertex3f(-1.98f, 1.175f - 0.2, 0.0f);
	glVertex3f(-1.68f, 1.2f, 0.0f);
	glVertex3f(-1.7f, 1.2f, 0.0f);
	glEnd();
}

void pillars(void)
{
	glColor3f(0.7f, 0.7f, 0.7f);	//

	glBegin(GL_QUADS);
	glVertex3f(-2.0f, 1.5f, 0.0f);
	glVertex3f(-2.0f, 0.1f, 0.0f);
	glVertex3f(-1.95f, 0.1f, 0.0f);
	glVertex3f(-1.95f, 1.5f, 0.0f);
	glEnd();
}

void bg_frame1(void)
{
	void bg_frame_crossbar(void);
	void pillars(void);

	//pillars();
	glTranslatef(-1.0, 0.0, -2.0);
	int j;
	for (j = 0; j < 12; j++)
	{
		glTranslatef(0.5, 0.0, 0.0);
		//pillars();
	}

	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);

	glBegin(GL_QUADS);
	glColor3f(0.827f, 0.827f, 0.827f);
	glVertex3f(2.5f, 1.2f, 0.0f);
	glVertex3f(-2.5f, 1.2f, 0.0f);
	glVertex3f(-2.5f, 1.175f, 0.0f);
	glVertex3f(2.5f, 1.175f, 0.0f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.827f, 0.827f, 0.827f);
	glVertex3f(2.5f, 1.2f - 0.2, 0.0f);
	glVertex3f(-2.5f, 1.2f - 0.2, 0.0f);
	glVertex3f(-2.5f, 1.175f - 0.2, 0.0f);
	glVertex3f(2.5f, 1.175f - 0.2, 0.0f);
	glEnd();

	//bg_frame_crossbar();
	glTranslatef(-1.0, 0.0, 0.0);
	int i;
	for (i = 0; i < 20; i++)
	{
		glTranslatef(0.3, 0.0, 0.0);
		bg_frame_crossbar();
	}

}

void bg_frame(void)
{
	void bg_frame_crossbar(void);
	void pillars(void);

	//pillars();
	glTranslatef(-1.0, 0.0, 0.0);
	int j;
	for (j = 0; j < 12; j++)
	{
		glTranslatef(0.5, 0.0, 0.0);
		pillars();
	}

	glLoadIdentity();    // this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);

	glBegin(GL_QUADS);
	glColor3f(0.827f, 0.827f, 0.827f);
	glVertex3f(2.5f, 1.2f, 0.0f);
	glVertex3f(-2.5f, 1.2f, 0.0f);
	glVertex3f(-2.5f, 1.175f, 0.0f);
	glVertex3f(2.5f, 1.175f, 0.0f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.827f, 0.827f, 0.827f);
	glVertex3f(2.5f, 1.2f - 0.2, 0.0f);
	glVertex3f(-2.5f, 1.2f - 0.2, 0.0f);
	glVertex3f(-2.5f, 1.175f - 0.2, 0.0f);
	glVertex3f(2.5f, 1.175f - 0.2, 0.0f);
	glEnd();

	//bg_frame_crossbar();
	glTranslatef(-1.0, 0.0, 0.0);
	int i;
	for (i = 0; i < 20; i++)
	{
		glTranslatef(0.3, 0.0, 0.0);
		bg_frame_crossbar();
	}

}

void floor_blue1(void)
{
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -6.0f);
	glScalef(3.0f, 3.0f, 3.0f);
	glBegin(GL_QUADS);
	glColor3f(0.137, 0.275, 0.494);
	glVertex3f(3.5f, 0.1, 0.0f);
	glVertex3f(-2.5f, 0.1, 0.0f);
	glVertex3f(-2.5f, -1.3f, 0.0f);
	glVertex3f(3.5f, -1.3f, 0.0f);
	glEnd();

	//yellow cross lines
	glLineWidth(1.2f);
	glBegin(GL_LINES);
	glColor3f(0.914f, 0.796f, 0.0f);
	//glColor3f(1.0, 0.0, 0.0);
	glVertex3f(2.5f, 0.0, 0.0f);
	glVertex3f(-2.5f, 0.0, 0.0f);

	glEnd();

}

void floor_blue(void)
{
	glBegin(GL_QUADS);
	glColor3f(0.137, 0.275, 0.494);
	glVertex3f(2.5f, 0.1, 0.0f);
	glVertex3f(-2.5f, 0.1, 0.0f);
	glVertex3f(-2.5f, -1.3f, 0.0f);
	glVertex3f(2.5f, -1.3f, 0.0f);
	glEnd();

	//yellow cross lines
	glLineWidth(1.2f);
	glBegin(GL_LINES);
	glColor3f(0.914f, 0.796f, 0.0f);
	//glColor3f(1.0, 0.0, 0.0);
	glVertex3f(2.5f, 0.0, 0.0f);
	glVertex3f(-2.5f, 0.0, 0.0f);

	glEnd();

}

void draw_crates(void)
{
	glBegin(GL_QUADS);
	glColor3f(0.824, 0.659, 0.412);
	glVertex3f(-1.5f, 0.2f, 0.0f);
	glVertex3f(-1.5f, 0.03f, 0.0f);
	glVertex3f(-1.4f, 0.03f, 0.0f);
	glVertex3f(-1.4f, 0.2f, 0.0f);
	glEnd();


	glBegin(GL_LINES);
	glColor3f(0.784, 0.596, 0.373);
	glVertex3f(-1.5f, 0.1f, 0.0f);
	glVertex3f(-1.4f, 0.1f, 0.0f);
	glEnd();
}

void conveyor_scenes(void)
{
	void drawConveyor(void);
	void drawBoard(void);
	void drawBoardTopView(void);

	//pipeline stages
	void drawBoardTop_VS(void);
	void drawBoardTop_TS(void);
	void drawBoardTop_GS(void);
	void drawBoardTop_R(void);
	void drawBoardTop_FP(void);
	void drawBoardTop_Test(void);

	/////////////////////
	////for testing
	//scene = 10;
	//scene_count = 1;
	/////////////////////


	switch (scene)
	{
	case 1:
		GLfloat i;
		//glLoadIdentity();
		//glTranslatef(0.0f, 0.0f, -3.0f);

		//drawConveyor();
		glTranslatef(x_translate, 0.0, 0.0);
		drawConveyor();


		glLoadIdentity();
		glTranslatef(0.0f, -0.17f, -3.0f);

		glTranslatef(x_translate - 2.0, 0.0, 0.0);
		glRotatef(-60, 1.0, 0.0, 0.0);

		drawBoard();

		if (!beltMotion)
		{
			x_translate = x_translate + 0.01;
		}


		if (x_translate >= 2.0)
		{
			beltMotion = 1;

			scene = 2;
		}
		break;

	case 2:

		glTranslatef(0.0, y_translate, z_translate);
		drawConveyor();
		glLoadIdentity();
		glTranslatef(0.0f, -0.17f + y_translate, -3.0f + z_translate);
		glTranslatef(x_translate - 2.0, 0.0, 0.0);
		glRotatef(-60, 1.0, 0.0, 0.0);

		drawBoard();

		//if(y_translate <= 0.3)
		//	y_translate = y_translate + 0.000055;

		//if (z_translate <= 0.7)
		//{
		//	z_translate = z_translate + 0.0001;
		//	//scene = 3;
		//}
		//else
		scene = 10; // 3;


		break;

	case 3:

		glTranslatef(0.0, y_translate, z_translate);
		drawConveyor();
		glLoadIdentity();
		glTranslatef(0.0f, -0.17f + y_translate, -3.0f + z_translate);
		glTranslatef(x_translate - 2.0, 0.0, 0.0);
		glRotatef(-60, 1.0, 0.0, 0.0);

		drawBoard();

		//if (y_translate >= 0.0)
		//	y_translate = y_translate - 0.000055;

		//if (z_translate >= 0.0)
		//{
		//	z_translate = z_translate - 0.0001;
		//	//scene = 3;
		//}
		//else
		//{
		//	scene = 4;
		//	x_translate = 0.0;
		//}
		scene = 4;
		x_translate = 0.0;
		break;

	case 4:
		glTranslatef(x_translate, 0.0, 0.0);
		drawConveyor();

		glLoadIdentity();
		glTranslatef(0.0f, -0.17f, -3.0f);
		glTranslatef(x_translate, 0.0, 0.0);
		glRotatef(-60, 1.0, 0.0, 0.0);

		drawBoard();

		if (x_translate <= 2.8)
		{
			x_translate = x_translate + 0.01;
		}
		else
		{
			beltMotion = 0;
			scene = 1;
			x_translate = -1.7; //0.001; // -2.0;
			scene_count = scene_count + 1;
		}


		break;

	case 10:

		glTranslatef(x_translate, 0.0, 0.0);
		drawConveyor();

		//glLoadIdentity();
		//glTranslatef(0.0f, -0.17f, -3.0f);
		//glTranslatef(x_translate, 0.0, 0.0);
		//glRotatef(-60, 1.0, 0.0, 0.0);

		//drawBoardTop_Test();


		//drawBoardTopView();
		if (scene_count == 1)
		{
			drawBoardTop_VS();
		}
		else if (scene_count == 2)
		{
			drawBoardTop_TS();
		}
		else if (scene_count == 3)
		{
			drawBoardTop_GS();
		}
		else if (scene_count == 4)
		{
			drawBoardTop_R();
		}
		else if (scene_count == 5)
		{
			drawBoardTop_FP();
		}
		else if (scene_count == 6)
		{
			drawBoardTop_Test();
		}


		test_count++;

		if (test_count == 1000)
		{
			scene = 3;
			test_count = 0;
		}

		break;

	}
	//first_time = 1;

	//fprintf(gpFILE, "scene = %d\n", scene);
}

// pipeline stages...
void drawBoardTop_VS(void)
{
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	// border
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.2f, 0.0f);
	glVertex3f(-1.55f, 0.85f, 0.0f);
	glVertex3f(-1.55f, -0.85f, 0.0f);
	glVertex3f(1.55f, -0.85f, 0.0f);
	glVertex3f(1.55f, 0.85f, 0.0f);
	glEnd();


	// main screen
	glBegin(GL_QUADS);
	glColor3f(0.87f, 0.721f, 0.529f);
	glVertex3f(-1.5f, 0.8f, 0.0f);
	glVertex3f(-1.5f, -0.8f, 0.0f);
	glVertex3f(1.5f, -0.8f, 0.0f);
	glVertex3f(1.5f, 0.8f, 0.0f);
	glEnd();

	///////////////////// Vertex Shader Stage ////////////////////////


	// Triangle Dots
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);

	glEnable(GL_POINT_SMOOTH);

	glPointSize(7);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-69.753, 46.2316f, 0.0f);
	glVertex3f(-87.5968, 19.466f, 0.0f);
	glVertex3f(-52.7203, 19.466f, 0.0f);
	glEnd();

	// Circle Dots
	glLoadIdentity();
	glTranslatef(-1.1f, -0.4f, -3.0f);

	float x = 0.0f;
	float y = 0.0f;
	const float r = 0.3f;
	glBegin(GL_POINTS);
	for (float angle = 0.0f; angle <= 360.0; angle += 13)
	{
		x = cos(angle) * r;
		y = sin(angle) * r;

		glVertex3f(x, y, 0.0f);
	}
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	// Rectangle Dots
	glBegin(GL_POINTS);
	glVertex3f(0.0, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();

	// Square Dots
	glBegin(GL_POINTS);
	glVertex3f(-9.80055, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();

	//Dots shape to be drawn in Geometry Shader
	glBegin(GL_POINTS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(31.0915, 31.6322f, 0.0f);
	glVertex3f(31.4295, -22.102f, 0.0f);
	glVertex3f(85.5017, 0.540695f, 0.0f);
	glEnd();

	//AXIS
	// X
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(87.6227, 29.8244f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(89.0194, 29.8082f, 0.0f);
	glVertex3f(87.6227, 31.0425f, 0.0f);
	glVertex3f(87.6227, 28.6226f, 0.0f);
	glEnd();

	//Y
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(73.1148, 43.2817f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(73.1148, 44.9188f, 0.0f);
	glVertex3f(71.7818, 43.2817f, 0.0f);
	glVertex3f(74.3777, 43.2817f, 0.0f);
	glEnd();

	//Z
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(65.8406, 23.3181f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(65.0446, 24.152f, 0.0f);
	glVertex3f(64.514, 22.1431f, 0.0f);
	glVertex3f(66.5608f, 22.4084f, 0.0f);
	glEnd();
}

void drawBoardTop_TS(void)
{
	if (pss_slice < 20 && elapsedTime >= 0.4900f)
	{
		pss_slice += 1;
		pss_stacks += 1;
	}

	fprintf(gpFILE, "inside function drawBoardTop_TS() = %lf", elapsedTime);

	//void drawDodecahedron(void);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	// border
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.2f, 0.0f);
	glVertex3f(-1.55f, 0.85f, 0.0f);
	glVertex3f(-1.55f, -0.85f, 0.0f);
	glVertex3f(1.55f, -0.85f, 0.0f);
	glVertex3f(1.55f, 0.85f, 0.0f);
	glEnd();


	// main screen
	glBegin(GL_QUADS);
	glColor3f(0.87f, 0.721f, 0.529f);
	glVertex3f(-1.5f, 0.8f, 0.0f);
	glVertex3f(-1.5f, -0.8f, 0.0f);
	glVertex3f(1.5f, -0.8f, 0.0f);
	glVertex3f(1.5f, 0.8f, 0.0f);
	glEnd();

	///////////////////// Tessilation Stage ////////////////////////



	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);

	// Cylinder Cone
	glLoadIdentity();
	glTranslatef(-0.92f, 0.6f, -2.5f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0, 0.21, 0.36, pss_slice, pss_stacks);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	// Sphere
	glLoadIdentity();
	glTranslatef(-1.1f, -0.4f, -3.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluSphere(quadric, 0.3, pss_slice, pss_stacks);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	// Rectangle Dots
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();
	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Square Dots
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-9.80055, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();
	// Mesh like
	for (float i = -9.93574; i >= -29.199; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-9.80055, i, 0.0f);
		glVertex3f(-30.0776, i, 0.0f);
		glEnd();
	}
	for (float i = -9.80055; i >= -30.0776; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(i, -9.93574, 0.0f);
		glVertex3f(i, -29.199, 0.0f);
		glEnd();
	}

	////Dots shape to be drawn in Geometry Shader
	//glBegin(GL_LINE_LOOP);
	//glColor3f(1.0f, 1.0f, 1.0f);
	//glVertex3f(31.0915, 31.6322f, 0.0f);
	//glVertex3f(31.4295, -22.102f, 0.0f);
	//glVertex3f(85.5017, 0.540695f, 0.0f);
	//glEnd();

	//*********************** AXIS *****************************
	// X
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(87.6227, 29.8244f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(89.0194, 29.8082f, 0.0f);
	glVertex3f(87.6227, 31.0425f, 0.0f);
	glVertex3f(87.6227, 28.6226f, 0.0f);
	glEnd();

	//Y
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(73.1148, 43.2817f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(73.1148, 44.9188f, 0.0f);
	glVertex3f(71.7818, 43.2817f, 0.0f);
	glVertex3f(74.3777, 43.2817f, 0.0f);
	glEnd();

	//Z
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(65.8406, 23.3181f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(65.0446, 24.152f, 0.0f);
	glVertex3f(64.514, 22.1431f, 0.0f);
	glVertex3f(66.5608f, 22.4084f, 0.0f);
	glEnd();


}

void drawBoardTop_GS(void)
{
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	// border
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.2f, 0.0f);
	glVertex3f(-1.55f, 0.85f, 0.0f);
	glVertex3f(-1.55f, -0.85f, 0.0f);
	glVertex3f(1.55f, -0.85f, 0.0f);
	glVertex3f(1.55f, 0.85f, 0.0f);
	glEnd();

	// main screen
	glBegin(GL_QUADS);
	glColor3f(0.87f, 0.721f, 0.529f);
	glVertex3f(-1.5f, 0.8f, 0.0f);
	glVertex3f(-1.5f, -0.8f, 0.0f);
	glVertex3f(1.5f, -0.8f, 0.0f);
	glVertex3f(1.5f, 0.8f, 0.0f);
	glEnd();

	///////////////////// Geometry Stage ////////////////////////


	//
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);

	// Cylinder 1
	glLoadIdentity();
	glTranslatef(-0.92f, 0.6f, -2.5f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0, 0.21, 0.36, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Cylinder 2
	glLoadIdentity();
	glTranslatef(-0.3f, 0.6f, -2.5f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0, 0.21, 0.36, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);



	// Sphere 1
	glLoadIdentity();
	glTranslatef(-1.1f, -0.4f, -3.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluSphere(quadric, 0.3, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Sphere 1
	glLoadIdentity();
	glTranslatef(-0.3f, -0.4f, -3.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluSphere(quadric, 0.3, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	// Rectangle 1
	glLoadIdentity();
	glTranslatef(0.5f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();
	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Rectangle 2
	glLoadIdentity();
	glTranslatef(0.5f, -0.4f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();
	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Clipped Rectangle 3 to fail in test
	glLoadIdentity();
	glTranslatef(1.2f, -0.4f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();
	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Square 1
	glLoadIdentity();
	glTranslatef(0.5f, -0.2f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-9.80055, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();
	// Mesh like
	for (float i = -9.93574; i >= -29.199; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-9.80055, i, 0.0f);
		glVertex3f(-30.0776, i, 0.0f);
		glEnd();
	}
	for (float i = -9.80055; i >= -30.0776; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(i, -9.93574, 0.0f);
		glVertex3f(i, -29.199, 0.0f);
		glEnd();
	}

	// Square 2
	glLoadIdentity();
	glTranslatef(0.8f, -0.2f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-9.80055, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();
	// Mesh like
	for (float i = -9.93574; i >= -29.199; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-9.80055, i, 0.0f);
		glVertex3f(-30.0776, i, 0.0f);
		glEnd();
	}
	for (float i = -9.80055; i >= -30.0776; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(i, -9.93574, 0.0f);
		glVertex3f(i, -29.199, 0.0f);
		glEnd();
	}




	//*********************** AXIS *****************************
	glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, -3.0f);
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	// X
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(87.6227, 29.8244f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(89.0194, 29.8082f, 0.0f);
	glVertex3f(87.6227, 31.0425f, 0.0f);
	glVertex3f(87.6227, 28.6226f, 0.0f);
	glEnd();

	//Y
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(73.1148, 43.2817f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(73.1148, 44.9188f, 0.0f);
	glVertex3f(71.7818, 43.2817f, 0.0f);
	glVertex3f(74.3777, 43.2817f, 0.0f);
	glEnd();

	//Z
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(65.8406, 23.3181f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(65.0446, 24.152f, 0.0f);
	glVertex3f(64.514, 22.1431f, 0.0f);
	glVertex3f(66.5608f, 22.4084f, 0.0f);
	glEnd();


}

void drawBoardTop_R(void)
{
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	// border
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.2f, 0.0f);
	glVertex3f(-1.55f, 0.85f, 0.0f);
	glVertex3f(-1.55f, -0.85f, 0.0f);
	glVertex3f(1.55f, -0.85f, 0.0f);
	glVertex3f(1.55f, 0.85f, 0.0f);
	glEnd();

	// main screen
	glBegin(GL_QUADS);
	glColor3f(0.87f, 0.721f, 0.529f);
	glVertex3f(-1.5f, 0.8f, 0.0f);
	glVertex3f(-1.5f, -0.8f, 0.0f);
	glVertex3f(1.5f, -0.8f, 0.0f);
	glVertex3f(1.5f, 0.8f, 0.0f);
	glEnd();

	///////////////////// Rasterizer Stage ////////////////////////


	//
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);

	// Cylinder 1
	glLoadIdentity();
	glTranslatef(-0.92f, 0.6f, -2.5f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0, 0.21, 0.36, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Cylinder 2
	glLoadIdentity();
	glTranslatef(-0.3f, 0.6f, -2.5f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0, 0.21, 0.36, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);



	// Sphere 1
	glLoadIdentity();
	glTranslatef(-1.1f, -0.4f, -3.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluSphere(quadric, 0.3, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Sphere 1
	glLoadIdentity();
	glTranslatef(-0.3f, -0.4f, -3.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluSphere(quadric, 0.3, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	// Rectangle 1
	glLoadIdentity();
	glTranslatef(0.5f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();
	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Rectangle 2
	glLoadIdentity();
	glTranslatef(0.5f, -0.4f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();
	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Clipped Rectangle 3 to fail in test
	glLoadIdentity();
	glTranslatef(1.2f, -0.4f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();
	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Square 1
	glLoadIdentity();
	glTranslatef(0.5f, -0.2f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-9.80055, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();
	// Mesh like
	for (float i = -9.93574; i >= -29.199; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-9.80055, i, 0.0f);
		glVertex3f(-30.0776, i, 0.0f);
		glEnd();
	}
	for (float i = -9.80055; i >= -30.0776; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(i, -9.93574, 0.0f);
		glVertex3f(i, -29.199, 0.0f);
		glEnd();
	}

	// Square 2
	glLoadIdentity();
	glTranslatef(0.8f, -0.2f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-9.80055, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();
	// Mesh like
	for (float i = -9.93574; i >= -29.199; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-9.80055, i, 0.0f);
		glVertex3f(-30.0776, i, 0.0f);
		glEnd();
	}
	for (float i = -9.80055; i >= -30.0776; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(i, -9.93574, 0.0f);
		glVertex3f(i, -29.199, 0.0f);
		glEnd();
	}




	//*********************** AXIS *****************************
	glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, -3.0f);
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	// X
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(87.6227, 29.8244f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(89.0194, 29.8082f, 0.0f);
	glVertex3f(87.6227, 31.0425f, 0.0f);
	glVertex3f(87.6227, 28.6226f, 0.0f);
	glEnd();

	//Y
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(73.1148, 43.2817f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(73.1148, 44.9188f, 0.0f);
	glVertex3f(71.7818, 43.2817f, 0.0f);
	glVertex3f(74.3777, 43.2817f, 0.0f);
	glEnd();

	//Z NO z axis in rasterizer
	/*glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(65.8406, 23.3181f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(65.0446, 24.152f, 0.0f);
	glVertex3f(64.514, 22.1431f, 0.0f);
	glVertex3f(66.5608f, 22.4084f, 0.0f);
	glEnd();*/


}

void drawBoardTop_FP(void)
{
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	// border
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.2f, 0.0f);
	glVertex3f(-1.55f, 0.85f, 0.0f);
	glVertex3f(-1.55f, -0.85f, 0.0f);
	glVertex3f(1.55f, -0.85f, 0.0f);
	glVertex3f(1.55f, 0.85f, 0.0f);
	glEnd();

	// main screen
	glBegin(GL_QUADS);
	glColor3f(0.87f, 0.721f, 0.529f);
	glVertex3f(-1.5f, 0.8f, 0.0f);
	glVertex3f(-1.5f, -0.8f, 0.0f);
	glVertex3f(1.5f, -0.8f, 0.0f);
	glVertex3f(1.5f, 0.8f, 0.0f);
	glEnd();

	///////////////////// Rasterizer Stage ////////////////////////


	//
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);

	// Cylinder 1
	glLoadIdentity();
	glTranslatef(-0.92f, 0.6f, -2.5f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0, 0.21, 0.36, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Cylinder 2
	glLoadIdentity();
	glTranslatef(-0.3f, 0.6f, -2.5f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 1.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0, 0.21, 0.36, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);



	// Sphere 1
	glLoadIdentity();
	glTranslatef(-1.1f, -0.4f, -3.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluSphere(quadric, 0.3, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Sphere 1
	glLoadIdentity();
	glTranslatef(-0.3f, -0.4f, -3.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 1.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluSphere(quadric, 0.3, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	// Rectangle 1
	glLoadIdentity();
	glTranslatef(0.5f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 47.0428f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();


	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Rectangle 2
	glLoadIdentity();
	glTranslatef(0.5f, -0.4f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 47.0428f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();

	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Clipped Rectangle 3 to fail in test
	glLoadIdentity();
	glTranslatef(1.2f, -0.4f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();
	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Square 1
	glLoadIdentity();
	glTranslatef(0.5f, -0.2f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-9.80055, -9.93574f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();

	// Mesh like
	for (float i = -9.93574; i >= -29.199; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-9.80055, i, 0.0f);
		glVertex3f(-30.0776, i, 0.0f);
		glEnd();
	}
	for (float i = -9.80055; i >= -30.0776; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(i, -9.93574, 0.0f);
		glVertex3f(i, -29.199, 0.0f);
		glEnd();
	}

	// Square 2
	glLoadIdentity();
	glTranslatef(0.8f, -0.2f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-9.80055, -9.93574f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();

	// Mesh like
	for (float i = -9.93574; i >= -29.199; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-9.80055, i, 0.0f);
		glVertex3f(-30.0776, i, 0.0f);
		glEnd();
	}
	for (float i = -9.80055; i >= -30.0776; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(i, -9.93574, 0.0f);
		glVertex3f(i, -29.199, 0.0f);
		glEnd();
	}




	//*********************** AXIS *****************************
	glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, -3.0f);
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	// X
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(87.6227, 29.8244f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(89.0194, 29.8082f, 0.0f);
	glVertex3f(87.6227, 31.0425f, 0.0f);
	glVertex3f(87.6227, 28.6226f, 0.0f);
	glEnd();

	//Y
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(73.1148, 43.2817f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(73.1148, 44.9188f, 0.0f);
	glVertex3f(71.7818, 43.2817f, 0.0f);
	glVertex3f(74.3777, 43.2817f, 0.0f);
	glEnd();

	//Z NO z axis in rasterizer
	/*glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(65.8406, 23.3181f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(65.0446, 24.152f, 0.0f);
	glVertex3f(64.514, 22.1431f, 0.0f);
	glVertex3f(66.5608f, 22.4084f, 0.0f);
	glEnd();*/


}

void drawBoardTop_Test(void)
{
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	// border
	glBegin(GL_QUADS);
	glColor3f(0.4f, 0.2f, 0.0f);
	glVertex3f(-1.55f, 0.85f, 0.0f);
	glVertex3f(-1.55f, -0.85f, 0.0f);
	glVertex3f(1.55f, -0.85f, 0.0f);
	glVertex3f(1.55f, 0.85f, 0.0f);
	glEnd();

	// main screen
	glBegin(GL_QUADS);
	glColor3f(0.87f, 0.721f, 0.529f);
	glVertex3f(-1.5f, 0.8f, 0.0f);
	glVertex3f(-1.5f, -0.8f, 0.0f);
	glVertex3f(1.5f, -0.8f, 0.0f);
	glVertex3f(1.5f, 0.8f, 0.0f);
	glEnd();

	///////////////////// Rasterizer Stage ////////////////////////


	//
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);

	// Cylinder 1
	glLoadIdentity();
	glTranslatef(-0.92f, 0.6f, -2.5f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0, 0.21, 0.36, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Cylinder 2
	glLoadIdentity();
	glTranslatef(-0.3f, 0.6f, -2.5f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 1.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.0, 0.21, 0.36, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);



	// Sphere 1
	glLoadIdentity();
	glTranslatef(-1.1f, -0.4f, -3.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluSphere(quadric, 0.3, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Sphere 1
	glLoadIdentity();
	glTranslatef(-0.3f, -0.4f, -3.0f);
	glScalef(1.0f, 1.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.0f, 1.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluSphere(quadric, 0.3, 20, 20);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	// Rectangle 1
	glLoadIdentity();
	glTranslatef(0.5f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 47.0428f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();


	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Rectangle 2
	glLoadIdentity();
	glTranslatef(0.5f, -0.4f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 47.0428f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-40.5541, 47.0428f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-40.5541, 19.466f, 0.0f);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0, 19.466f, 0.0f);
	glEnd();

	glLineWidth(1);
	// Mesh like
	for (float i = 19.466; i < 47.0428; i += 1.51536)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(0.0, i, 0.0f);
		glVertex3f(-40.5541, i, 0.0f);
		glEnd();
	}
	for (float i = 0; i > -40.5541; i -= 1.51536)
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(i, 19.466, 0.0f);
		glVertex3f(i, 47.0428, 0.0f);
		glEnd();
	}

	// Clipped Rectangle 3 to fail in test
	//glLoadIdentity();
	//glTranslatef(1.2f, -0.4f, -1.9f);
	//glScalef(0.01f, 0.01f, 0.01f);
	//glScalef(1.0f, 1.0f, 0.01f);

	//glBegin(GL_LINE_LOOP);
	//glColor3f(1.0f, 0.0f, 0.0f);
	//glVertex3f(0.0, 47.0428f, 0.0f);
	//glVertex3f(-40.5541, 47.0428f, 0.0f);
	//glVertex3f(-40.5541, 19.466f, 0.0f);
	//glVertex3f(0.0, 19.466f, 0.0f);
	//glEnd();
	//glLineWidth(1);
	//// Mesh like
	//for (float i = 19.466; i < 47.0428; i += 1.51536)
	//{
	//	glBegin(GL_LINES);
	//	glVertex3f(0.0, i, 0.0f);
	//	glVertex3f(-40.5541, i, 0.0f);
	//	glEnd();
	//}
	//for (float i = 0; i > -40.5541; i -= 1.51536)
	//{
	//	glBegin(GL_LINES);
	//	glVertex3f(i, 19.466, 0.0f);
	//	glVertex3f(i, 47.0428, 0.0f);
	//	glEnd();
	//}

	// Square 1
	glLoadIdentity();
	glTranslatef(0.5f, -0.2f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-9.80055, -9.93574f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();

	// Mesh like
	for (float i = -9.93574; i >= -29.199; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-9.80055, i, 0.0f);
		glVertex3f(-30.0776, i, 0.0f);
		glEnd();
	}
	for (float i = -9.80055; i >= -30.0776; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(i, -9.93574, 0.0f);
		glVertex3f(i, -29.199, 0.0f);
		glEnd();
	}

	// Square 2
	glLoadIdentity();
	glTranslatef(0.8f, -0.2f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.0f, 1.0f, 0.01f);

	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-9.80055, -9.93574f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-30.0776, -9.93574f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-30.0776, -29.199f, 0.0f);

	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(-9.80055, -29.199f, 0.0f);
	glEnd();

	// Mesh like
	for (float i = -9.93574; i >= -29.199; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(-9.80055, i, 0.0f);
		glVertex3f(-30.0776, i, 0.0f);
		glEnd();
	}
	for (float i = -9.80055; i >= -30.0776; i -= 1.0)
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(i, -9.93574, 0.0f);
		glVertex3f(i, -29.199, 0.0f);
		glEnd();
	}




	//*********************** AXIS *****************************
	glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, -3.0f);
	glTranslatef(0.0f, 0.0f, -1.9f);
	glScalef(0.01f, 0.01f, 0.01f);
	// X
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(1);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(87.6227, 29.8244f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(89.0194, 29.8082f, 0.0f);
	glVertex3f(87.6227, 31.0425f, 0.0f);
	glVertex3f(87.6227, 28.6226f, 0.0f);
	glEnd();

	//Y
	glBegin(GL_LINES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(73.1148, 43.2817f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(73.1148, 44.9188f, 0.0f);
	glVertex3f(71.7818, 43.2817f, 0.0f);
	glVertex3f(74.3777, 43.2817f, 0.0f);
	glEnd();

	//Z NO z axis in rasterizer
	/*glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(73.1148, 29.8244f, 0.0f);
	glVertex3f(65.8406, 23.3181f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(65.0446, 24.152f, 0.0f);
	glVertex3f(64.514, 22.1431f, 0.0f);
	glVertex3f(66.5608f, 22.4084f, 0.0f);
	glEnd();*/


}

void scene_pipeline_stage(void)
{
	void drawConveyor(void);
	void drawBoard(void);
	void drawBoardTopView(void);
	void bg_frame(void);
	void floor_blue(void);
	void draw_crates(void);
	void conveyor_scenes(void);
	void draw_circle_with_LINES(GLfloat);
	void robo_arm(void);

	//// code
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// kontya colour ne binth clear haru colour buffer -> chotta bacchan tech frame buffer
	//glMatrixMode(GL_MODELVIEW);	//internally model view matrix bolavte...this is all zeros matrix
	//glLoadIdentity();	// this call makes model view matrix into identity matrix
	//glTranslatef(0.0f, 0.0f, -3.0f);	// z axis -ve number scrren che aath and +ve number scrren che baher

	// bg green colour
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.517f, 0.568f);
	glVertex3f(-2.5f, 2.0f, 0.0f);
	glVertex3f(-2.5f, -2.0f, 0.0f);
	glVertex3f(2.5f, -2.0f, 0.0f);
	glVertex3f(2.5f, 2.0f, 0.0f);
	glEnd();

	//floor
	floor_blue();

	// draw top background frame
	bg_frame();

	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);

	//yellow cross lines
	glLineWidth(2.5f);
	glBegin(GL_LINES);
	glColor3f(0.914f, 0.796f, 0.0f);
	glVertex3f(2.5f, -0.65, 0.0f);
	glVertex3f(-2.5f, -0.65, 0.0f);
	glEnd();

	// conveyor stands 
	int stand;
	for (stand = 0; stand < 6; stand++)
	{
		glTranslatef(0.7, 0.0, 0.0);


		//outer stand
		glLineWidth(3.5);
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-2.5f, -0.575f, 0.0f);
		glVertex3f(-2.5f, -0.8f, 0.0f);
		glEnd();

		//inner stand
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-2.45f, -0.575f + 0.1, 0.0f);
		glVertex3f(-2.45f, -0.8f + 0.1, 0.0f);
		glEnd();
	}

	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);

	draw_crates();


	//yellow cross lines
	glLineWidth(2.5f);
	glBegin(GL_LINES);
	glColor3f(0.914f, 0.796f, 0.0f);
	glVertex3f(2.5f, -0.85, 0.0f);
	glVertex3f(-2.5f, -0.85, 0.0f);
	glEnd();






	conveyor_scenes();
}

void vertex_fetch_stage(void)
{
	void drawConveyor(void);
	void draw_circle_with_LINES(GLfloat);
	void robo_arm(void);
	void bg_frame(void);
	void floor_blue(void);
	// code
	// depth step - 3
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// kontya colour ne binth clear haru colour buffer -> chotta bacchan tech frame buffer..also clear depth buffer using clear depth value - 1.0f...complusory
	glMatrixMode(GL_MODELVIEW);	//internally model view matrix bolavte...this is all zeros matrix
	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);	// z axis -ve number scrren che aath and +ve number scrren che baher

	// bg green colour
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.517f, 0.568f);
	glVertex3f(-2.5f, 2.0f, 0.0f);
	glVertex3f(-2.5f, -2.0f, 0.0f);
	glVertex3f(2.5f, -2.0f, 0.0f);
	glVertex3f(2.5f, 2.0f, 0.0f);
	glEnd();

	//floor
	floor_blue();

	//glLoadIdentity();	// this call makes model view matrix into identity matrix
	//glTranslatef(0.0f, 0.0f, -3.0f);

	// draw top background frame
	bg_frame();

	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);

	//robo arm
	robo_arm();


	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);

	//yellow cross lines
	glLineWidth(2.5f);
	glBegin(GL_LINES);
	glColor3f(0.914f, 0.796f, 0.0f);
	glVertex3f(2.5f, -0.65, 0.0f);
	glVertex3f(-2.5f, -0.65, 0.0f);
	glEnd();

	// conveyor stands 
	int stand;
	for (stand = 0; stand < 6; stand++)
	{
		glTranslatef(0.7, 0.0, 0.0);


		//outer stand
		glLineWidth(3.5);
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-2.5f, -0.575f, 0.0f);
		glVertex3f(-2.5f, -0.8f, 0.0f);
		glEnd();

		//inner stand
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-2.45f, -0.575f + 0.1, 0.0f);
		glVertex3f(-2.45f, -0.8f + 0.1, 0.0f);
		glEnd();
	}

	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);



	//yellow cross lines
	glLineWidth(2.5f);
	glBegin(GL_LINES);
	glColor3f(0.914f, 0.796f, 0.0f);
	glVertex3f(2.5f, -0.85, 0.0f);
	glVertex3f(-2.5f, -0.85, 0.0f);
	glEnd();

	// draw conveyor
	glTranslatef(x_translate, 0.0, 0.0);	//for translating conveyor on x axis
	drawConveyor();


	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);


	// draw red line moving up and down
	glTranslatef(0.0, y_line_translate, 0.0);
	glLineWidth(1.5f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.75f, -0.5f, 0.0f);
	glVertex3f(-0.75f, 0.0f, 0.0f);
	glEnd();

	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(X_circle0_translate, 0.0f, -3.0f);

	//this switch case is for different objects on conveyor belts which are alligned by the red line
	switch (condition)
	{
	case 1:
		if (X_circle0_translate >= 1.0)	// the alligning is done when the obect reaches on 1.0 co-ordinate on x-axis
		{
			draw_circle_with_LINES(0.4);	// we want the object to allign to 0.4 on y-axis after it reaches 0.1 on x-axis, so 0.4 is passed
		}
		else
			draw_circle_with_LINES(0.3);	// the initial position of the object is passed here with which it will appear on the conveyor in the beginning

		break;

	case 2:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);	// we want the object to allign to 0.4 on y-axis after it reaches 0.1 on x-axis, so 0.4 is passed
		}
		else
			draw_circle_with_LINES(0.46);	// the initial position of the object is passed here with which it will appear on the conveyor in the beginning
		break;

	case 3:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.4);
		break;

	case 4:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.44);
		break;

	case 5:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.35);
		break;

	case 6:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.33);
		break;

	case 7:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.4);
		break;

	case 8:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.46);
		break;
	default:
		break;
	}



	// we want the conveyor objects to keep coming so once the object exits on the right side of the screen after all 9 cases we are repesting the case from beginning and for that we are resetting the x-axis co-ordinates
	if (X_circle0_translate >= 4.0)
	{
		X_circle0_translate = -0.5;	// resetting the x-axis co-ordinate for object
		condition++;	// case is incremented here
		if (condition >= 9)	// case is repaeted here
			condition = 1;
	}



	x_translate = x_translate + 0.001;	// translation of the conveyor belt on x-axis is done here
	X_circle0_translate = X_circle0_translate + 0.001;	// translation of the object on the conveyor belt on x-axis is done here

	if (x_translate >= 5.0)	// resetting of the x-axis co-ordinate for the conveyor belt
	{
		x_translate = 0.0;
	}


	// the switch case for translating the red line on y-axis both up and down
	switch (line_state)
	{
	case 1:	// for up mavement
		if (y_line_translate <= 0.2)
			y_line_translate = y_line_translate + 0.001;
		else line_state = 2;
		break;

	case 2:	// for down movement
		if (y_line_translate >= 0.0)
			y_line_translate = y_line_translate - 0.001;
		else line_state = 1;
		break;
	default:
		break;
	}
}

//  the y-axis co-ordinate for the initial position of the object is passed as function parameter here
void draw_circle_with_LINES(GLfloat y_pos)
{
	GLfloat theta;
	int i;
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(1.5f);
	glBegin(GL_LINES);

	for (i = 0; i < 1000; i++)
	{
		theta = i * ((2 * 3.14159) / 1000);
		glVertex3f((0.05 * cos(theta)) - 1.8, (0.05 * sin(theta)) - y_pos, 0.0f);
		glVertex3f(0.0 - 1.8, 0.0 - y_pos, 0.0);
	}

	glEnd();
}

void draw_pixel(void)
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(20);
	glBegin(GL_POINTS);
	glVertex3f(00.0f, 0.0f, 0.0f);
	glEnd();
}

void draw_nut_bolt(void)
{
	GLfloat theta;
	int i;
	glColor3f(0.235f, 0.274f, 0.294f);
	glPointSize(1.5f);
	glBegin(GL_POLYGON);

	for (i = 1; i < 7; i++)
	{
		theta = i * ((2 * 3.14159) / 6);
		glVertex3f((0.06 * cos(theta)), (0.06 * sin(theta)), 0.0f);
	}
	glEnd();

	GLfloat n_theta;
	int n_i;
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(1.5f);
	glBegin(GL_LINES);

	for (n_i = 0; n_i < 1000; n_i++)
	{
		n_theta = n_i * ((2 * 3.14159) / 1000);
		glVertex3f((0.02 * cos(n_theta)), (0.02 * sin(n_theta)), 0.0f);
		glVertex3f(0.0, 0.0, 0.0);
	}

	glEnd();
}

void robo_arm(void)
{

	void draw_nut_bolt(void);

	//main section
	glBegin(GL_QUADS);
	glColor3f(0.965, 0.525, 0.247);	//(0.807f, 0.823f, 0.843f);
	glVertex3f(-2.5f, 0.8f, 0.0f);
	glVertex3f(-2.5f, 0.45f, 0.0f);
	glVertex3f(-0.7f, 0.55f, 0.0f);
	glVertex3f(-0.7f, 0.7f, 0.0f);
	glEnd();


	//glBegin(GL_QUADS);

	//glVertex3f(-0.75f, 0.55f, 0.0f);
	//glVertex3f(-0.3f, 0.3f, 0.0f);
	//glVertex3f(-0.25f, 0.35f, 0.0f);
	//glVertex3f(-0.7f, 0.7f, 0.0f);
	//glEnd();

	//third moving section
	glBegin(GL_QUADS);
	glColor3f(0.133, 0.329, 0.416);

	glVertex3f(-0.35f, 0.35f, 0.0f);

	glVertex3f(-0.77f, 0.12f + y_line_translate, 0.0f);
	glVertex3f(-0.74f, 0.12f + y_line_translate, 0.0f);
	glVertex3f(-0.3f, 0.3f, 0.0f);
	glEnd();

	//clamping 
	glBegin(GL_QUADS);
	glColor3f(0.965, 0.525, 0.247);
	glVertex3f(-0.68f, 0.06f + y_line_translate, 0.0f);
	glVertex3f(-0.65f, 0.06f + y_line_translate, 0.0f);
	glVertex3f(-0.74f, 0.12f + y_line_translate, 0.0f);
	glVertex3f(-0.76f, 0.12f + y_line_translate, 0.0f);	//0.77
	glEnd();

	glTranslatef(-1.5, 0.0, 0.0);
	glRotatef(180, 0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(0.965, 0.525, 0.247);
	glVertex3f(-0.68f, 0.06f + y_line_translate, 0.0f);
	glVertex3f(-0.65f, 0.06f + y_line_translate, 0.0f);
	glVertex3f(-0.74f, 0.12f + y_line_translate, 0.0f);
	glVertex3f(-0.77f, 0.12f + y_line_translate, 0.0f);
	glEnd();

	//glVertex3f(-0.75f, -0.02f + y_line_translate, 0.0f);
	//glVertex3f(-0.74f, -0.01f + y_line_translate, 0.0f);
	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);

	glBegin(GL_TRIANGLES);
	glColor3f(0.965, 0.525, 0.247);
	glVertex3f(-0.65f, 0.06f + y_line_translate, 0.0f);
	glVertex3f(-0.68f, 0.06f + y_line_translate, 0.0f);
	glVertex3f(-0.75f, -0.02f + y_line_translate, 0.0f);
	glEnd();

	glTranslatef(-1.5, 0.0, 0.0);
	glRotatef(180, 0.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.965, 0.525, 0.247);
	glVertex3f(-0.65f, 0.06f + y_line_translate, 0.0f);
	glVertex3f(-0.68f, 0.06f + y_line_translate, 0.0f);
	glVertex3f(-0.75f, -0.02f + y_line_translate, 0.0f);
	glEnd();


	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);


	//middle section
	glBegin(GL_QUADS);
	glColor3f(0.965, 0.525, 0.247);
	glVertex3f(-0.75f, 0.55f, 0.0f);
	glVertex3f(-0.3f, 0.3f, 0.0f);
	glVertex3f(-0.25f, 0.35f, 0.0f);
	glVertex3f(-0.7f, 0.7f, 0.0f);
	glEnd();

	glTranslatef(-0.75f, 0.62f, 0.0f);
	draw_nut_bolt();

	glTranslatef(0.44f, -0.27f, 0.0f);
	glScalef(0.5, 0.5, 0.0);
	draw_nut_bolt();



}

void vertex_fetch_stage_1(void)
{
	void drawConveyor(void);
	void draw_circle_with_LINES(GLfloat);
	void robo_arm(void);
	void bg_frame(void);
	void floor_blue(void);
	// code
	// depth step - 3

	// bg green colour
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.517f, 0.568f);
	glVertex3f(-2.5f, 2.0f, 0.0f);
	glVertex3f(-2.5f, -2.0f, 0.0f);
	glVertex3f(2.5f, -2.0f, 0.0f);
	glVertex3f(2.5f, 2.0f, 0.0f);
	glEnd();

	//floor
	floor_blue();

	//glLoadIdentity();	// this call makes model view matrix into identity matrix
	//glTranslatef(0.0f, 0.0f, -3.0f);

	// draw top background frame
	bg_frame();

	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);

	//robo arm
	robo_arm();


	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);

	//yellow cross lines
	glLineWidth(2.5f);
	glBegin(GL_LINES);
	glColor3f(0.914f, 0.796f, 0.0f);
	glVertex3f(2.5f, -0.65, 0.0f);
	glVertex3f(-2.5f, -0.65, 0.0f);
	glEnd();

	// conveyor stands 
	int stand;
	for (stand = 0; stand < 6; stand++)
	{
		glTranslatef(0.7, 0.0, 0.0);


		//outer stand
		glLineWidth(3.5);
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-2.5f, -0.575f, 0.0f);
		glVertex3f(-2.5f, -0.8f, 0.0f);
		glEnd();

		//inner stand
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(-2.45f, -0.575f + 0.1, 0.0f);
		glVertex3f(-2.45f, -0.8f + 0.1, 0.0f);
		glEnd();
	}

	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);



	//yellow cross lines
	glLineWidth(2.5f);
	glBegin(GL_LINES);
	glColor3f(0.914f, 0.796f, 0.0f);
	glVertex3f(2.5f, -0.85, 0.0f);
	glVertex3f(-2.5f, -0.85, 0.0f);
	glEnd();

	// draw conveyor
	glTranslatef(x_translate_vf, 0.0, 0.0);	//for translating conveyor on x axis
	drawConveyor();


	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);


	// draw red line moving up and down
	glTranslatef(0.0, y_line_translate, 0.0);
	glLineWidth(1.5f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.75f, -0.5f, 0.0f);
	glVertex3f(-0.75f, 0.0f, 0.0f);
	glEnd();

	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(X_circle0_translate, 0.0f, -3.0f);

	//this switch case is for different objects on conveyor belts which are alligned by the red line
	switch (condition)
	{
	case 1:
		if (X_circle0_translate >= 1.0)	// the alligning is done when the obect reaches on 1.0 co-ordinate on x-axis
		{
			draw_circle_with_LINES(0.4);	// we want the object to allign to 0.4 on y-axis after it reaches 0.1 on x-axis, so 0.4 is passed
		}
		else
			draw_circle_with_LINES(0.3);	// the initial position of the object is passed here with which it will appear on the conveyor in the beginning

		break;

	case 2:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);	// we want the object to allign to 0.4 on y-axis after it reaches 0.1 on x-axis, so 0.4 is passed
		}
		else
			draw_circle_with_LINES(0.46);	// the initial position of the object is passed here with which it will appear on the conveyor in the beginning
		break;

	case 3:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.4);
		break;

	case 4:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.44);
		break;

	case 5:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.35);
		break;

	case 6:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.33);
		break;

	case 7:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.4);
		break;

	case 8:
		if (X_circle0_translate >= 1.0)
		{
			draw_circle_with_LINES(0.4);
		}
		else
			draw_circle_with_LINES(0.46);
		break;
	default:
		break;
	}



	// we want the conveyor objects to keep coming so once the object exits on the right side of the screen after all 9 cases we are repesting the case from beginning and for that we are resetting the x-axis co-ordinates
	if (X_circle0_translate >= 4.0)
	{
		X_circle0_translate = -0.5;	// resetting the x-axis co-ordinate for object
		condition++;	// case is incremented here
		if (condition >= 9)	// case is repaeted here
			condition = 1;
	}



	x_translate_vf = x_translate_vf + 0.007;	// translation of the conveyor belt on x-axis is done here
	X_circle0_translate = X_circle0_translate + 0.007;	// translation of the object on the conveyor belt on x-axis is done here

	if (x_translate_vf >= 5.0)	// resetting of the x-axis co-ordinate for the conveyor belt
	{
		x_translate_vf = 0.0;
	}


	// the switch case for translating the red line on y-axis both up and down
	switch (line_state)
	{
	case 1:	// for up mavement
		if (y_line_translate <= 0.2)
			y_line_translate = y_line_translate + 0.005;
		else line_state = 2;
		break;

	case 2:	// for down movement
		if (y_line_translate >= 0.0)
			y_line_translate = y_line_translate - 0.005;
		else line_state = 1;
		break;
	default:
		break;
	}


}

//---------------------------------------------------- TW FUNCTIONS ----------------------------------------//
void fillBuffers(void)
{
	glLoadIdentity();
	glTranslatef(0.0f, -0.5f, -3.0f);
	glRotatef(tw_swapBuffers, 0.0f, 1.0f, 0.0f);
	//1st FrameBuffer
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.518f, 0.26f, 0.0f);
	glVertex3f(1.49f, 0.26f, 0.0f);
	glVertex3f(1.49f, -0.25f, 0.0f);
	glVertex3f(0.518f, -0.25f, 0.0f);
	glEnd();
	//1st FrameBuffer OUTLET
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.49f, -0.25f, 0.0f);
	glVertex3f(1.49f, -0.20f, 0.0f);
	glVertex3f(1.55f, -0.20f, 0.0f);
	glVertex3f(1.55f, -0.25f, 0.0f);
	glEnd();
	//1st FrameBuffer Inlet
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.4f, 0.25f, 0.0f);
	glVertex3f(1.49f, 0.25f, 0.0f);
	glVertex3f(1.54f, 0.30f, 0.0f);
	glVertex3f(1.35f, 0.30f, 0.0f);
	glEnd();

	//2st FrameBuffer
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.518f, 0.26f, 0.0f);
	glVertex3f(-1.49f, 0.26f, 0.0f);
	glVertex3f(-1.49f, -0.25f, 0.0f);
	glVertex3f(-0.518f, -0.25f, 0.0f);
	glEnd();
	//2st FrameBuffer Inlet
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.49f, -0.25f, 0.0f);
	glVertex3f(-1.49f, -0.20f, 0.0f);
	glVertex3f(-1.55f, -0.20f, 0.0f);
	glVertex3f(-1.55f, -0.25f, 0.0f);
	glEnd();
	//2st FrameBuffer Outlet
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.4f, 0.25f, 0.0f);
	glVertex3f(-1.49f, 0.25f, 0.0f);
	glVertex3f(-1.54f, 0.30f, 0.0f);
	glVertex3f(-1.35f, 0.30f, 0.0f);
	glEnd();
	//WALL 2
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.52f, -0.25f, -0.01f);
	glVertex3f(-1.52f, -0.20f, -0.01f);
	glEnd();
	////Wall 1
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.52f, -0.25f, 0.0f);
	glVertex3f(1.52f, -0.20f, 0.0f);
	glEnd();


	//_______________________________________Filling The Framebuffer 1 ________________________________//
	glLoadIdentity();
	//glEnable(GL_POINT_SMOOTH);
	if (tw_count_for_color <= (11 * 21))
	{
		//Fragments Falling Into Framebuffer
		glTranslatef(0.0f, -0.4f, -2.99f);

		glPointSize(20);
		glBegin(GL_POINTS);
		glColor3f(tw_red, tw_green, tw_blue);
		glVertex3f(-1.45f, tw_fbPointTranslate, 0.0f);
		glEnd();

		glLoadIdentity();
		glTranslatef(-1.45f, -0.22 - 0.5, -2.99f);
		//Variables For filling Frame Buffer
		float tw_red1 = 0.0f;
		float tw_green1 = 0.0f;
		float tw_blue1 = 0.0f;
		float fbYTranslate = 0.0f;
		float fbXTranslate = 0.0f;
		float r = 0.0f;
		float g = 0.0f;
		float b = 0.0f;

		//____COLOR INTERPOLATION ____
		for (int i = 1; i <= tw_count_for_color; i++)
		{
			glPointSize(20);
			glBegin(GL_POINTS);
			glColor3f(tw_red1, tw_green1, tw_blue1);
			glVertex3f(fbXTranslate + (i * 0.045f) - 0.045, fbYTranslate, 0.0f);
			glEnd();

			if (i > 42 && i < 199)
			{
				//1st Line
				if (i > 45 && i < 59)
				{
					g = 59 - i;
					b = i - 44;

					tw_red1 = 0.14f * 0;
					tw_green1 = 1.0f * (g / 15);
					tw_blue1 = 1.0f * (b / 15);
				}
				else
				{
					//2st Line
					if (i > 67 && i < 79)
					{
						g = 79 - i;
						b = i - 66;

						tw_red1 = 0.14f * 2;
						tw_green1 = 1.0f * (g / 15) * (0.14 * 8);
						tw_blue1 = 1.0f * (b / 15) * (0.14 * 8);
					}
					else
					{
						//3st Line
						if (i > 89 && i < 99)
						{
							g = 99 - i;
							b = i - 88;

							tw_red1 = 0.14f * 3;
							tw_green1 = 1.0f * (g / 15) * (0.14 * 7);
							tw_blue1 = 1.0f * (b / 15) * (0.14 * 7);
						}
						else
						{
							//4st Line
							if (i > 111 && i < 119)
							{
								g = 119 - i;
								b = i - 110;

								tw_red1 = 0.14f * 4;
								tw_green1 = 1.0f * (g / 15) * (0.14 * 5);
								tw_blue1 = 1.0f * (b / 15) * (0.14 * 5);
							}
							else
							{
								//5st Line
								if (i > 133 && i < 139)
								{
									g = 139 - i;
									b = i - 132;

									tw_red1 = 0.14f * 5;
									tw_green1 = 1.0f * (g / 15) * (0.14 * 3);
									tw_blue1 = 1.0f * (b / 15) * (0.14 * 3);
								}
								else
								{
									//6st Line
									if (i > 155 && i < 159)
									{
										g = 159 - i;
										b = i - 154;

										tw_red1 = 0.14f * 6;
										tw_green1 = 1.0f * (g / 15) * (0.14 * 1);
										tw_blue1 = 1.0f * (b / 15) * (0.14 * 1);
									}
									else
									{
										//7st Line
										if (i > 177 && i < 179)
										{
											g = 179 - i;
											b = i - 176;

											tw_red1 = 0.14f * 7;
											tw_green1 = 1.0f * (g / 15) * (0.14 * 0);
											tw_blue1 = 1.0f * (b / 15) * (0.14 * 0);
										}
										else
										{
											tw_red1 = 0.0f;
											tw_green1 = 0.0f;
											tw_blue1 = 0.0f;
										}
									}
								}
							}
						}
					}
				}
				if (i % 21 == 0)
				{
					fbYTranslate = fbYTranslate + 0.045f;
					fbXTranslate = -(i * 0.045f);
				}
			}
			else
			{
				tw_red1 = 0.0f;
				tw_green1 = 0.0f;
				tw_blue1 = 0.0f;
				if (i % 21 == 0)
				{
					fbYTranslate = fbYTranslate + 0.045f;
					fbXTranslate = -(i * 0.045f);
				}
			}
		}
	}
	else
	{
		tw_bFBfull = TRUE;
		if (tw_swapBuffers >= 180)
		{
			tw_count_for_color = 0;
		}
	}
	//____ SWAPPING BUFFERS ______
	if (tw_bFBfull)
	{
		glLoadIdentity();
		glPointSize(20);
		glTranslatef(0.0f, -0.5f, -2.99f);
		glRotatef(tw_swapBuffers, 0.0f, 1.0f, 0.0f);
		//Variables For filling Frame Buffer
		float tw_red1 = 0.0f;
		float tw_green1 = 0.0f;
		float tw_blue1 = 0.0f;
		float fbYTranslate = 0.0f;
		float fbXTranslate = 0.0f;
		float r = 0.0f;
		float g = 0.0f;
		float b = 0.0f;

		for (int i = 1; i <= (11 * 21); i++)
		{
			//glPointSize(20);
			glBegin(GL_POINTS);
			glColor3f(tw_red1, tw_green1, tw_blue1);
			glVertex3f(fbXTranslate + (i * 0.045f) - 0.045 - 1.45f, -0.22f + fbYTranslate, 0.0f);
			glEnd();

			if (i % 21 == 0)
			{
				fbYTranslate = fbYTranslate + 0.045f;
				fbXTranslate = -(i * 0.045f);
			}
			if (i > 42 && i < 199)
			{
				//1st Line
				if (i > 45 && i < 59)
				{
					g = 59 - i;
					b = i - 44;

					tw_red1 = 0.14f * 0;
					tw_green1 = 1.0f * (g / 15);
					tw_blue1 = 1.0f * (b / 15);
				}
				else
				{
					//2st Line
					if (i > 67 && i < 79)
					{
						g = 79 - i;
						b = i - 66;

						tw_red1 = 0.14f * 2;
						tw_green1 = 1.0f * (g / 15) * (0.14 * 8);
						tw_blue1 = 1.0f * (b / 15) * (0.14 * 8);
					}
					else
					{
						//3st Line
						if (i > 89 && i < 99)
						{
							g = 99 - i;
							b = i - 88;

							tw_red1 = 0.14f * 3;
							tw_green1 = 1.0f * (g / 15) * (0.14 * 7);
							tw_blue1 = 1.0f * (b / 15) * (0.14 * 7);
						}
						else
						{
							//4st Line
							if (i > 111 && i < 119)
							{
								g = 119 - i;
								b = i - 110;

								tw_red1 = 0.14f * 4;
								tw_green1 = 1.0f * (g / 15) * (0.14 * 5);
								tw_blue1 = 1.0f * (b / 15) * (0.14 * 5);
							}
							else
							{
								//5st Line
								if (i > 133 && i < 139)
								{
									g = 139 - i;
									b = i - 132;

									tw_red1 = 0.14f * 5;
									tw_green1 = 1.0f * (g / 15) * (0.14 * 3);
									tw_blue1 = 1.0f * (b / 15) * (0.14 * 3);
								}
								else
								{
									//6st Line
									if (i > 155 && i < 159)
									{
										g = 159 - i;
										b = i - 154;

										tw_red1 = 0.14f * 6;
										tw_green1 = 1.0f * (g / 15) * (0.14 * 1);
										tw_blue1 = 1.0f * (b / 15) * (0.14 * 1);
									}
									else
									{
										//7st Line
										if (i > 177 && i < 179)
										{
											g = 179 - i;
											b = i - 176;

											tw_red1 = 0.14f * 7;
											tw_green1 = 1.0f * (g / 15) * (0.14 * 0);
											tw_blue1 = 1.0f * (b / 15) * (0.14 * 0);
										}
										else
										{
											tw_red1 = 0.0f;
											tw_green1 = 0.0f;
											tw_blue1 = 0.0f;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	glDisable(GL_POINT_SMOOTH);
}

void drawPipe(void)
{
	glLoadIdentity();
	glTranslatef(1.685f + tw_xPipeTranslate, -0.225f - 0.5f, -2.98f);
	glScalef(0.02f, 0.04f, 0.04f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	gluCylinder(quadric, 1.0f, 1.0f, 5.0f, 50, 50);

	glTranslatef(0.0f, 0.0f, 5.0f);
	gluCylinder(quadric, 0.7f, 0.7f, 50.0f, 50, 50);
}

void updateBuffers(void)
{
	//*** Code ***
	if (tw_fbPointTranslate >= -0.22)
	{
		tw_fbPointTranslate = tw_fbPointTranslate - 0.1f;
	}
	else
	{
		tw_count_for_color++;
		tw_fbPointTranslate = 1.0f;
		fprintf(gpFILE, "tw_count_for_color = %d", tw_count_for_color);

		if (tw_count_for_color > 42 && tw_count_for_color < 199)
		{
			float r = 0.0f;
			float g = 0.0f;
			float b = 0.0f;

			//1st Line
			if (tw_count_for_color > 45 && tw_count_for_color < 59)
			{
				g = 59 - tw_count_for_color;
				b = tw_count_for_color - 44;

				tw_red = 0.14f * 0;
				tw_green = 1.0f * (g / 15);
				tw_blue = 1.0f * (b / 15);
			}
			else
			{
				//2st Line
				if (tw_count_for_color > 67 && tw_count_for_color < 79)
				{
					g = 79 - tw_count_for_color;
					b = tw_count_for_color - 66;

					tw_red = 0.14f * 2;
					tw_green = 1.0f * (g / 15) * (0.14 * 8);
					tw_blue = 1.0f * (b / 15) * (0.14 * 8);
				}
				else
				{
					//3st Line
					if (tw_count_for_color > 89 && tw_count_for_color < 99)
					{
						g = 99 - tw_count_for_color;
						b = tw_count_for_color - 88;

						tw_red = 0.14f * 3;
						tw_green = 1.0f * (g / 15) * (0.14 * 7);
						tw_blue = 1.0f * (b / 15) * (0.14 * 7);
					}
					else
					{
						//4st Line
						if (tw_count_for_color > 111 && tw_count_for_color < 119)
						{
							g = 119 - tw_count_for_color;
							b = tw_count_for_color - 110;

							tw_red = 0.14f * 4;
							tw_green = 1.0f * (g / 15) * (0.14 * 5);
							tw_blue = 1.0f * (b / 15) * (0.14 * 5);
						}
						else
						{
							//5st Line
							if (tw_count_for_color > 133 && tw_count_for_color < 139)
							{
								g = 139 - tw_count_for_color;
								b = tw_count_for_color - 132;

								tw_red = 0.14f * 5;
								tw_green = 1.0f * (g / 15) * (0.14 * 3);
								tw_blue = 1.0f * (b / 15) * (0.14 * 3);
							}
							else
							{
								//6st Line
								if (tw_count_for_color > 155 && tw_count_for_color < 159)
								{
									g = 159 - tw_count_for_color;
									b = tw_count_for_color - 154;

									tw_red = 0.14f * 6;
									tw_green = 1.0f * (g / 15) * (0.14 * 1);
									tw_blue = 1.0f * (b / 15) * (0.14 * 1);
								}
								else
								{
									//7st Line
									if (tw_count_for_color > 177 && tw_count_for_color < 179)
									{
										g = 179 - tw_count_for_color;
										b = tw_count_for_color - 176;

										tw_red = 0.14f * 7;
										tw_green = 1.0f * (g / 15) * (0.14 * 0);
										tw_blue = 1.0f * (b / 15) * (0.14 * 0);
									}
									else
									{
										tw_red = 0.0f;
										tw_green = 0.0f;
										tw_blue = 0.0f;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (tw_count_for_color >= (11 * 21) && tw_swapBuffers <= 180)
	{
		tw_swapBuffers = tw_swapBuffers + 0.5f;
	}
}

void SirBackView(void)
{
	glLoadIdentity();
	gluLookAt(camera.position.x, camera.position.y, camera.position.z, camera.front.x + camera.position.x, camera.front.y + camera.position.y, camera.front.z + camera.position.z, camera.up.x, camera.up.y, camera.up.z);
	glTranslatef(tw_xTransSir, tw_yTransSir, tw_zTransSir);
	glScalef(tw_xScaleSir, tw_yScaleSir, tw_zScaleSir);
	glRotatef(180, 0, 1, 0);
	glLineWidth(1);

	//Right Ear
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.45f, 0.45f);
	glVertex3f(-12.6f, 24.2f, 0.0f);
	glVertex3f(-13.2f, 22.8f, 0.0f);
	glVertex3f(-13.5f, 20.9f, 0.0f);
	glVertex3f(-13.2f, 19.2f, 0.0f);
	glVertex3f(-12.9f, 17.2f, 0.0f);
	glVertex3f(-11.8f, 17.6f, 0.0f);
	glVertex3f(-11.5f, 20.4f, 0.0f);
	glVertex3f(-11.4f, 22.2f, 0.0f);
	glVertex3f(-11.5f, 23.8f, 0.0f);
	glEnd();

	//Right Ear dot
	glEnable(GL_POINT_SMOOTH);
	glPointSize(3);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.3f, 20.6f, 0.0f);
	glEnd();
	glDisable(GL_POINT_SMOOTH);


	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(-13.5f, 14.0f, 0.0f);
	glVertex3f(-11.8f, 17.6f, 0.0f);
	glVertex3f(-12.9f, 17.2f, 0.0f);
	glVertex3f(-13.2f, 19.2f, 0.0f);
	glVertex3f(-15.0f, 18.3f, 0.0f);
	glVertex3f(-16.7f, 18.2f, 0.0f);
	glVertex3f(-18.7f, 18.1f, 0.0f);
	glVertex3f(-20.1f, 17.3f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(-23.6f, 15.0f, 0.0f);
	glVertex3f(-20.0f, 16.3f, 0.0f);
	glVertex3f(-21.3f, 18.6f, 0.0f);
	glVertex3f(-24.2f, 19.3f, 0.0f);
	glVertex3f(-24.0f, 17.9f, 0.0f);
	glEnd();

	//Left Ear
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.45f, 0.45f);
	glVertex3f(-25.4f, 22.5f, 0.0f);
	glVertex3f(-25.1f, 21.5f, 0.0f);
	glVertex3f(-24.7f, 20.1f, 0.0f);
	glVertex3f(-24.5f, 18.9f, 0.0f);
	glVertex3f(-25.3f, 19.3f, 0.0f);
	glVertex3f(-25.7f, 20.4f, 0.0f);
	glVertex3f(-26.1f, 21.6f, 0.0f);
	glVertex3f(-26.3f, 23.4f, 0.0f);
	glEnd();


	//Head Heir UPside
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(-18.5f, 30.3f, 0.0f);
	glVertex3f(-12.6f, 24.2f, 0.0f);
	glVertex3f(-11.5f, 23.8f, 0.0f);
	glVertex3f(-11.0f, 25.4f, 0.0f);
	glVertex3f(-11.1f, 27.8f, 0.0f);
	glVertex3f(-11.9f, 29.5f, 0.0f);
	glVertex3f(-13.9f, 30.8f, 0.0f);
	glVertex3f(-14.4f, 32.0f, 0.0f);
	glVertex3f(-16.4f, 32.9f, 0.0f);
	glVertex3f(-18.6f, 33.2f, 0.0f);
	glVertex3f(-20.6f, 33.2f, 0.0f);
	glVertex3f(-22.7f, 32.6f, 0.0f);
	glVertex3f(-24.1f, 31.7f, 0.0f);
	glVertex3f(-25.2f, 30.3f, 0.0f);
	glVertex3f(-25.8f, 28.7f, 0.0f);
	glVertex3f(-26.0f, 27.0f, 0.0f);
	glVertex3f(-25.6f, 25.6f, 0.0f);
	glVertex3f(-25.1f, 24.7f, 0.0f);
	glVertex3f(-25.4f, 23.5f, 0.0f);
	glVertex3f(-12.6f, 24.2f, 0.0f);
	glEnd();

	//Head Heir DOWNside
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(-19.6f, 19.5f, 0.0f);
	glVertex3f(-12.6f, 24.2f, 0.0f);
	glVertex3f(-25.4f, 23.5f, 0.0f);
	glVertex3f(-25.4f, 22.5f, 0.0f);
	glVertex3f(-25.1f, 21.5f, 0.0f);
	glVertex3f(-24.7f, 20.1f, 0.0f);
	glVertex3f(-24.5f, 18.9f, 0.0f);
	glVertex3f(-23.6f, 18.5f, 0.0f);
	glVertex3f(-22.4f, 18.2f, 0.0f);
	glVertex3f(-21.3f, 18.3f, 0.0f);
	glVertex3f(-20.0f, 17.4f, 0.0f);
	glVertex3f(-18.7f, 18.1f, 0.0f);
	glVertex3f(-16.7f, 18.2f, 0.0f);
	glVertex3f(-15.02f, 18.3f, 0.0f);
	glVertex3f(-13.2f, 19.2f, 0.0f);
	glVertex3f(-13.5f, 20.9f, 0.0f);
	glVertex3f(-13.2f, 22.8f, 0.0f);
	glVertex3f(-12.6f, 24.2f, 0.0f);
	glEnd();

	glLoadIdentity();
	gluLookAt(camera.position.x, camera.position.y, camera.position.z, camera.front.x + camera.position.x, camera.front.y + camera.position.y, camera.front.z + camera.position.z, camera.up.x, camera.up.y, camera.up.z);
	glTranslatef(0.425f + tw_xTransSir, 0.04f + tw_yTransSir, tw_zTransSir);
	glScalef(tw_xScaleSir, tw_yScaleSir, tw_zScaleSir);
	//Left Elbow
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(-53.0f, -18.8f, 0.0f);
	glVertex3f(-37.4f, -24.1f, 0.0f);
	glVertex3f(-33.7f, -25.4f, 0.0f);
	glVertex3f(-37.8f, -18.1f, 0.0f);
	glVertex3f(-44.2f, -15.1f, 0.0f);
	glVertex3f(-52.1f, -15.3f, 0.0f);
	glVertex3f(-56.7f, -13.0f, 0.0f);
	glVertex3f(-58.5f, -11.0f, 0.0f);
	glVertex3f(-60.0f, -12.5f, 0.0f);
	glVertex3f(-60.3f, -14.6f, 0.0f);
	glVertex3f(-59.0f, -16.6f, 0.0f);
	glEnd();
	//Left HAnd
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(-33.7f, -25.4f, 0.0f);
	glVertex3f(-37.4f, -24.1f, 0.0f);
	glVertex3f(-33.5f, -30.0f, 0.0f);
	glVertex3f(-37.8f, -27.4f, 0.0f);
	glVertex3f(-33.3f, -34.3f, 0.0f);
	glVertex3f(-36.0f, -30.8f, 0.0f);
	glVertex3f(-35.4f, -34.8f, 0.0f);
	glVertex3f(-36.9f, -31.9f, 0.0f);
	glVertex3f(-37.9f, -33.4f, 0.0f);
	glVertex3f(-38.9f, -31.4f, 0.0f);
	glEnd();



	//___________________ Right HAnd _______________________//
	glLoadIdentity();
	gluLookAt(camera.position.x, camera.position.y, camera.position.z, camera.front.x + camera.position.x, camera.front.y + camera.position.y, camera.front.z + camera.position.z, camera.up.x, camera.up.y, camera.up.z);
	glTranslatef(0.38f + tw_xTransSir, 0.023f + tw_yTransSir, tw_zTransSir);
	glScalef(tw_xScaleSir, tw_yScaleSir, tw_zScaleSir);
	//Card
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.5f, 0.5f);
	glVertex3f(-1.4f, -30.0f, -0.01f);
	glVertex3f(4.4f, -37.6f, -0.01f);
	glVertex3f(9.0f, -33.0f, -0.01f);
	glVertex3f(4.1f, -26.1f, -0.01f);
	glEnd();
	//RRight Shoulder
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.2f, -7.3f, 0.0f);
	glVertex3f(8.2f, -9.1f, 0.0f);
	glVertex3f(9.9f, -9.2f, 0.0f);
	glVertex3f(11.8f, -8.5f, 0.0f);
	glVertex3f(13.8f, -7.1f, 0.0f);
	glVertex3f(15.5f, -5.4f, 0.0f);
	glVertex3f(17.0f, -3.5f, 0.0f);
	glVertex3f(1.1f, 7.0f, 0.0f);
	glVertex3f(0.0f, 8.8f, 0.0f);
	glVertex3f(-0.2f, -7.3f, 0.0f);
	glEnd();
	//Right Elbow
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(12.5f, -15.3f, 0.0f);
	glVertex3f(21.1f, -9.1f, 0.0f);
	glVertex3f(20.f, -6.7f, 0.0f);
	glVertex3f(19.5f, -4.9f, 0.0f);
	glVertex3f(17.0f, -3.5f, 0.0f);
	glVertex3f(15.5f, -5.4f, 0.0f);
	glVertex3f(13.8f, -7.1f, 0.0f);
	glVertex3f(11.8f, -8.5f, 0.0f);
	glVertex3f(9.9f, -9.2f, 0.0f);
	glVertex3f(8.2f, -9.1f, 0.0f);
	glVertex3f(6.4f, -10.8f, 0.0f);
	glVertex3f(-0.5f, -14.3f, 0.0f);
	glVertex3f(-0.3f, -16.6f, 0.0f);
	glVertex3f(1.0f, -19.7f, 0.0f);
	glEnd();
	//Right Palm
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(1.0f, -19.7f, 0.0f);
	glVertex3f(-0.3f, -16.6f, 0.0f);
	glVertex3f(0.5f, -26.0f, 0.0f);
	glVertex3f(-2.2f, -27.2f, 0.0f);
	glVertex3f(3.2f, -28.0f, 0.0f);
	glVertex3f(-0.3f, -29.1f, 0.0f);
	glVertex3f(3.4f, -29.6f, 0.0f);
	glEnd();
	//Right Thumb
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(0.75f, -24.0f, 0.0f);
	glVertex3f(0.35f, -26.0f, 0.0f);
	glVertex3f(2.6f, -24.4f, 0.0f);
	glVertex3f(3.0f, -25.88f, 0.0f);
	glVertex3f(5.0f, -24.07f, 0.0f);
	glEnd();




	//Pant Drawing Right
	glLoadIdentity();
	gluLookAt(camera.position.x, camera.position.y, camera.position.z, camera.front.x + camera.position.x, camera.front.y + camera.position.y, camera.front.z + camera.position.z, camera.up.x, camera.up.y, camera.up.z);
	glTranslatef(tw_xTransSir, tw_yTransSir, tw_zTransSir);
	glScalef(tw_xScaleSir, tw_yScaleSir, tw_zScaleSir);
	glRotatef(180, 0, 1, 0);

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(-6.0f, -30.0f, 0.0f);
	glVertex3f(-20.0f, -28.0f, 0.0f);
	glVertex3f(-4.0f, -37.0f, 0.0f);
	glVertex3f(-21.0f, -53.0f, 0.0f);
	glVertex3f(-5.0f, -49.0f, 0.0f);
	glVertex3f(-20.0f, -67.0f, 0.0f);
	glVertex3f(-5.0f, -66.0f, 0.0f);
	glVertex3f(-19.0f, -76.0f, 0.0f);
	glVertex3f(-3.0f, -96.0f, 0.0f);
	glVertex3f(-16.0f, -96.0f, 0.0f);
	glEnd();

	//Pant Drawing Left
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(-20.0f, -28.0f, 0.0f);
	glVertex3f(-36.0f, -25.0f, 0.0f);
	glVertex3f(-20.0f, -31.0f, 0.0f);
	glVertex3f(-37.0f, -27.0f, 0.0f);
	glVertex3f(-20.0f, -40.0f, 0.0f);
	glVertex3f(-36.0f, -34.0f, 0.0f);
	glVertex3f(-21.0f, -53.0f, 0.0f);
	glVertex3f(-38.0f, -46.0f, 0.0f);
	glVertex3f(-23.0f, -70.0f, 0.0f);
	glVertex3f(-37.0f, -65.0f, 0.0f);
	glVertex3f(-27.0f, -85.0f, 0.0f);
	glVertex3f(-39.0f, -83.0f, 0.0f);
	glVertex3f(-28.0f, -96.0f, 0.0f);
	glVertex3f(-40.0f, -96.0f, 0.0f);
	glEnd();

	//Shirt Base
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-20.0f, 10.0f, 0.0f);
	glVertex3f(-6.0f, -30.0f, 0.0f);
	glVertex3f(-6.0f, -21.0f, 0.0f);
	glVertex3f(-1.0f, -10.0f, 0.0f);
	glVertex3f(2.0f, -12.0f, 0.0f);
	glVertex3f(10.0f, -12.0f, 0.0f);
	glVertex3f(14.0f, -10.0f, 0.0f);
	glVertex3f(16.0f, -7.0f, 0.0f);
	glVertex3f(2.0f, 5.0f, 0.0f);
	glVertex3f(1.0f, 7.0f, 0.0f);
	glVertex3f(-12.0f, 12.0f, 0.0f);
	glVertex3f(-13.0f, 14.0f, 0.0f);
	glVertex3f(-19.0f, 17.0f, 0.0f);
	glVertex3f(-23.0f, 16.0f, 0.0f);
	glVertex3f(-25.0f, 15.0f, 0.0f);
	glVertex3f(-26.0f, 13.0f, 0.0f);
	glVertex3f(-38.0f, 11.0f, 0.0f);
	glVertex3f(-38.0f, -4.0f, 0.0f);
	glVertex3f(-38.0f, -11.0f, 0.0f);
	glVertex3f(-38.0f, -13.0f, 0.0f);
	glVertex3f(-36.0f, -25.0f, 0.0f);
	glVertex3f(-32.0f, -27.0f, 0.0f);
	glVertex3f(-29.0f, -28.0f, 0.0f);
	glVertex3f(-25.0f, -30.0f, 0.0f);
	glVertex3f(-20.0f, -31.0f, 0.0f);
	glVertex3f(-15.0f, -32.0f, 0.0f);
	glVertex3f(-10.0f, -31.0f, 0.0f);
	glVertex3f(-6.0f, -30.0f, 0.0f);
	glEnd();

	//Shirt BAse
	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.2f, 0.2f);
	glVertex3f(-5.0f, -19.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-38.0f, -4.0f, 0.0f);
	glColor3f(0.5f, 0.2f, 0.2f);
	glVertex3f(-6.0f, -21.0f, 0.0f);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.5f, 0.2f, 0.2f);
	glVertex3f(-39.0f, 9.0f, 0.0f);
	glVertex3f(2.0f, 4.0f, 0.0f);
	glVertex3f(-1.0f, -10.0f, 0.0f);
	glVertex3f(1.0f, 7.0f, 0.0f);
	glVertex3f(-38.0f, -4.0f, 0.0f);
	glVertex3f(-38.0f, 11.0f, 0.0f);
	glVertex3f(-26.0f, 13.0f, 0.0f);
	glVertex3f(-19.0f, 14.0f, 0.0f);
	glVertex3f(-19.0f, 14.0f, 0.0f);
	glVertex3f(-12.0f, 12.0f, 0.0f);
	glEnd();
}

void turret1(void)
{
	glLoadIdentity();
	gluLookAt(camera.position.x, camera.position.y, camera.position.z, camera.front.x + camera.position.x, camera.front.y + camera.position.y, camera.front.z + camera.position.z, camera.up.x, camera.up.y, camera.up.z);
	glTranslatef(-20.0f, -10.0f, -7.0f);
	glScalef(2.0f, 2.0f, 2.0f);
	glRotatef(-tw_rot, 1.0f, 0.0f, 0.0f);
	//_______________________________ Bottom Base ________________________//
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -0.2f);
	glScalef(2.0f, 2.0f, 0.5f);
	glColor3f(0.149, 0.122, 0.11);
	gluSphere(quadric, 0.5f, 50, 50);
	glPopMatrix();
	//_______________________________ 1st Cylinderm ______________________//
	glColor3f(0.298, 0.259, 0.243);
	gluCylinder(quadric, 0.5f, 0.5f, 0.15, 50, 50);
	//Disk 
	glColor3f(0.337, 0.314, 0.318);
	gluDisk(quadric, 0.0, 0.5, 50, 50);

	//_______________________________ 2nd Cylinder _________________________//
	glTranslatef(0.0f, 0.0f, 0.15f);
	glColor3f(0.306, 0.275, 0.271);
	gluCylinder(quadric, 0.54f, 0.54f, 0.15, 50, 50);
	//Disk
	glColor3f(0.322, 0.29, 0.29);
	gluDisk(quadric, 0.0, 0.54, 50, 50);

	//________________________________ 3rd Cylinder _________________________//
	glTranslatef(0.0f, 0.0f, 0.15f);
	glColor3f(0.427, 0.365, 0.353);
	gluCylinder(quadric, 0.5f, 0.5f, 0.15, 50, 50);
	//Disk
	glColor3f(0.4, 0.408, 0.439);
	gluDisk(quadric, 0.0, 0.5, 50, 50);
	//Disc
	glTranslatef(0.0f, 0.0f, 0.15f);
	glColor3f(0.4, 0.408, 0.439);
	gluDisk(quadric, 0.0f, 0.5f, 50, 50);
	glPushMatrix();


	//______________________________1st Plate____________________________//
	glTranslatef(0.0f, -0.35f, 0.3f);
	glBegin(GL_QUADS);
	//Front face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.03f, 0.4f);
	glVertex3f(-0.2f, 0.03f, 0.4f);

	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.03f, 0.4f);
	glVertex3f(0.2f, -0.03f, 0.4f);
	//Right face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glVertex3f(0.2f, 0.03f, 0.4f);

	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.03f, 0.4f);
	glVertex3f(0.2f, -0.03f, -0.4f);
	//Back face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	//Left Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.03f, 0.4f);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, 0.4f);
	//Top Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, 0.03f, 0.4f);
	glVertex3f(0.2f, 0.03f, 0.4f);
	//Bottom Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.03f, 0.4f);
	glVertex3f(0.2f, -0.03f, 0.4f);
	glEnd();

	//________________________________ 2st Plate ______________________________//
	glTranslatef(0.0f, 0.75f, 0.0f);
	glBegin(GL_QUADS);
	//Front face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.03f, 0.4f);
	glVertex3f(-0.2f, 0.03f, 0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.03f, 0.4f);
	glVertex3f(0.2f, -0.03f, 0.4f);
	//Right face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glVertex3f(0.2f, 0.03f, 0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.03f, 0.4f);
	glVertex3f(0.2f, -0.03f, -0.4f);
	//Back face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	//Left Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.03f, 0.4f);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, 0.4f);
	//Top Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, 0.03f, 0.4f);
	glVertex3f(0.2f, 0.03f, 0.4f);
	//Bottom Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.03f, 0.4f);
	glVertex3f(0.2f, -0.03f, 0.4f);
	glEnd();
	glPopMatrix();



	//____________________________________ Up 1st Plate _______________________________//
	glTranslatef(-0.18f, -0.35f, 0.945f);
	glRotatef(-30, 0, 1, 0);
	glBegin(GL_QUADS);
	//Front face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.031f, 0.4f);
	glVertex3f(-0.2f, 0.031f, 0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.031f, 0.4f);
	glVertex3f(0.2f, -0.031f, 0.4f);
	//Right face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.031f, -0.4f);
	glVertex3f(0.2f, 0.031f, 0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.031f, 0.4f);
	glVertex3f(0.2f, -0.031f, -0.4f);
	//Back face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.031f, -0.4f);
	glVertex3f(0.2f, 0.031f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.031f, -0.4f);
	glVertex3f(-0.2f, -0.031f, -0.4f);
	//Left Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.031f, 0.4f);
	glVertex3f(-0.2f, 0.031f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.031f, -0.4f);
	glVertex3f(-0.2f, -0.031f, 0.4f);
	//Top Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.031f, -0.4f);
	glVertex3f(-0.2f, 0.031f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, 0.031f, 0.4f);
	glVertex3f(0.2f, 0.031f, 0.4f);
	//Bottom Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, -0.031f, -0.4f);
	glVertex3f(-0.2f, -0.031f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.031f, 0.4f);
	glVertex3f(0.2f, -0.031f, 0.4f);
	glEnd();


	//______________________________________ Up 2st Plate _______________________________//
	glTranslatef(0.0f, 0.75f, 0.0f);
	glBegin(GL_QUADS);
	//Front face
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, 0.031f, 0.4f);
	glVertex3f(-0.2f, 0.031f, 0.4f);
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, -0.031f, 0.4f);
	glVertex3f(0.2f, -0.031f, 0.4f);
	//Right face
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, 0.031f, -0.4f);
	glVertex3f(0.2f, 0.031f, 0.4f);
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, -0.031f, 0.4f);
	glVertex3f(0.2f, -0.031f, -0.4f);
	//Back face
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	//Left Face
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, 0.031f, 0.4f);
	glVertex3f(-0.2f, 0.031f, -0.4f);
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, -0.031f, -0.4f);
	glVertex3f(-0.2f, -0.031f, 0.4f);
	//Top Face
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, 0.031f, -0.4f);
	glVertex3f(-0.2f, 0.031f, -0.4f);
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.031f, 0.4f);
	glVertex3f(0.2f, 0.031f, 0.4f);
	//Bottom Face
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.031f, -0.4f);
	glVertex3f(-0.2f, -0.031f, -0.4f);
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, -0.031f, 0.4f);
	glVertex3f(0.2f, -0.031f, 0.4f);
	glEnd();
	glPushMatrix();



	//___________________________ Mid  Barrel Holder Cylinder _____________________________//
	glTranslatef(0.0f, 0.13f, 0.25f);
	glRotatef(90, 1, 0, 0);
	glColor3f(0.404, 0.4, 0.42);
	gluCylinder(quadric, 0.05f, 0.05f, 1.0f, 50, 50);
	glPopMatrix();


	//____________________________ 1st Barrel Middle ______________________________//
	glTranslatef(0.55f, -0.38f, 0.15f);
	glRotatef(-70, 0, 1, 0);
	glColor3f(tw_red, 0.0f, 0.0f);
	gluCylinder(quadric, 0.28f, 0.28f, 1.0f, 50, 50);
	//Barrel Disk 1
	glTranslatef(0.0f, 0.0f, 0.0f);
	glColor3f(0.38, 0.376, 0.392);
	gluDisk(quadric, 0.0, 0.28, 50, 50);
	//Barrel Disk 1
	glTranslatef(0.0f, 0.0f, 0.0f);
	glColor3f(0.38, 0.376, 0.392);
	gluDisk(quadric, 0.2, 0.28, 50, 50);


	//___________________________ 2st Barrel Middle _________________________________// 
	glTranslatef(0.0f, 0.0f, -1.1f);
	glPushMatrix();
	glColor3f(0.561, 0.537, 0.541);
	gluCylinder(quadric, 0.2f, 0.2f, 2.2f, 50, 50);
	glColor3f(0.682, 0.808, 0.824);
	//Ring 1
	glTranslatef(0.0f, 0.0f, 0.5f);
	gluCylinder(quadric, 0.21f, 0.21f, 0.01f, 50, 50);

	//Ring 2
	glTranslatef(0.0f, 0.0f, 0.1f);
	gluCylinder(quadric, 0.21f, 0.21f, 0.01f, 50, 50);

	//Ring 3
	glTranslatef(0.0f, 0.0f, 0.1f);
	gluCylinder(quadric, 0.21f, 0.21f, 0.01f, 50, 50);

	//Ring 4
	glTranslatef(0.0f, 0.0f, -0.3f);
	gluCylinder(quadric, 0.21f, 0.21f, 0.01f, 50, 50);
	glPopMatrix();
	//Barrel Disk 1
	glTranslatef(0.0f, 0.0f, 1.8f);
	glColor3f(0.733, 0.737, 0.769);
	gluDisk(quadric, 0.2, 0.28, 50, 50);
	//Barrel Disk 1
	glTranslatef(0.0f, 0.0f, 0.0f);
	glColor3f(0.733, 0.737, 0.769);
	gluDisk(quadric, 0.15, 0.2, 50, 50);


	//____________________________ 3nd Barrel Middle _______________________________//
	glTranslatef(0.0f, 0.0f, -2.5f);
	glColor3f(0.898, 0.463, 0.424);
	gluCylinder(quadric, 0.15f, 0.15f, 2.2f, 50, 50);

	glPushMatrix();
	//Wire
	glTranslatef(-1.8f, 0.0f, 2.5f);
	glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	gluCylinder(quadric, 0.13f, 0.13f, 100.0f, 50, 50);
	//red Lazer
	glPopMatrix();
	glLineWidth(5);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
	glColor3f(tw_red, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(15.0f, 3.5f, 0.0f);
	glEnd();
}

void turret2(void)
{
	glLoadIdentity();
	gluLookAt(camera.position.x, camera.position.y, camera.position.z, camera.front.x + camera.position.x, camera.front.y + camera.position.y, camera.front.z + camera.position.z, camera.up.x, camera.up.y, camera.up.z);
	glTranslatef(-20.0f, -10.0f, -14.0f);
	glScalef(2.0f, 2.0f, 2.0f);
	glRotatef(-tw_rot, 1.0f, 0.0f, 0.0f);

	//_______________________________ Bottom Base ________________________//
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -0.2f);
	glScalef(2.0f, 2.0f, 0.5f);
	glColor3f(0.149, 0.122, 0.11);
	gluSphere(quadric, 0.5f, 50, 50);
	glPopMatrix();
	//_______________________________ 1st Cylinderm ______________________//
	glColor3f(0.298, 0.259, 0.243);
	gluCylinder(quadric, 0.5f, 0.5f, 0.15, 50, 50);
	//Disk 
	glColor3f(0.337, 0.314, 0.318);
	gluDisk(quadric, 0.0, 0.5, 50, 50);

	//_______________________________ 2nd Cylinder _________________________//
	glTranslatef(0.0f, 0.0f, 0.15f);
	glColor3f(0.306, 0.275, 0.271);
	gluCylinder(quadric, 0.54f, 0.54f, 0.15, 50, 50);
	//Disk
	glColor3f(0.322, 0.29, 0.29);
	gluDisk(quadric, 0.0, 0.54, 50, 50);

	//________________________________ 3rd Cylinder _________________________//
	glTranslatef(0.0f, 0.0f, 0.15f);
	glColor3f(0.427, 0.365, 0.353);
	gluCylinder(quadric, 0.5f, 0.5f, 0.15, 50, 50);
	//Disk
	glColor3f(0.4, 0.408, 0.439);
	gluDisk(quadric, 0.0, 0.5, 50, 50);
	//Disc
	glTranslatef(0.0f, 0.0f, 0.15f);
	glColor3f(0.4, 0.408, 0.439);
	gluDisk(quadric, 0.0f, 0.5f, 50, 50);
	glPushMatrix();


	//______________________________1st Plate____________________________//
	glTranslatef(0.0f, -0.35f, 0.3f);
	glBegin(GL_QUADS);
	//Front face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.03f, 0.4f);
	glVertex3f(-0.2f, 0.03f, 0.4f);

	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.03f, 0.4f);
	glVertex3f(0.2f, -0.03f, 0.4f);
	//Right face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glVertex3f(0.2f, 0.03f, 0.4f);

	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.03f, 0.4f);
	glVertex3f(0.2f, -0.03f, -0.4f);
	//Back face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	//Left Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.03f, 0.4f);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, 0.4f);
	//Top Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, 0.03f, 0.4f);
	glVertex3f(0.2f, 0.03f, 0.4f);
	//Bottom Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.03f, 0.4f);
	glVertex3f(0.2f, -0.03f, 0.4f);
	glEnd();

	//________________________________ 2st Plate ______________________________//
	glTranslatef(0.0f, 0.75f, 0.0f);
	glBegin(GL_QUADS);
	//Front face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.03f, 0.4f);
	glVertex3f(-0.2f, 0.03f, 0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.03f, 0.4f);
	glVertex3f(0.2f, -0.03f, 0.4f);
	//Right face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glVertex3f(0.2f, 0.03f, 0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.03f, 0.4f);
	glVertex3f(0.2f, -0.03f, -0.4f);
	//Back face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	//Left Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.03f, 0.4f);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, 0.4f);
	//Top Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, 0.03f, 0.4f);
	glVertex3f(0.2f, 0.03f, 0.4f);
	//Bottom Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.03f, 0.4f);
	glVertex3f(0.2f, -0.03f, 0.4f);
	glEnd();
	glPopMatrix();



	//____________________________________ Up 1st Plate _______________________________//
	glTranslatef(-0.18f, -0.35f, 0.945f);
	glRotatef(-30, 0, 1, 0);
	glBegin(GL_QUADS);
	//Front face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.031f, 0.4f);
	glVertex3f(-0.2f, 0.031f, 0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.031f, 0.4f);
	glVertex3f(0.2f, -0.031f, 0.4f);
	//Right face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.031f, -0.4f);
	glVertex3f(0.2f, 0.031f, 0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.031f, 0.4f);
	glVertex3f(0.2f, -0.031f, -0.4f);
	//Back face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.031f, -0.4f);
	glVertex3f(0.2f, 0.031f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.031f, -0.4f);
	glVertex3f(-0.2f, -0.031f, -0.4f);
	//Left Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.031f, 0.4f);
	glVertex3f(-0.2f, 0.031f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.031f, -0.4f);
	glVertex3f(-0.2f, -0.031f, 0.4f);
	//Top Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.031f, -0.4f);
	glVertex3f(-0.2f, 0.031f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, 0.031f, 0.4f);
	glVertex3f(0.2f, 0.031f, 0.4f);
	//Bottom Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, -0.031f, -0.4f);
	glVertex3f(-0.2f, -0.031f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.031f, 0.4f);
	glVertex3f(0.2f, -0.031f, 0.4f);
	glEnd();


	//______________________________________ Up 2st Plate _______________________________//
	glTranslatef(0.0f, 0.75f, 0.0f);
	glBegin(GL_QUADS);
	//Front face
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, 0.031f, 0.4f);
	glVertex3f(-0.2f, 0.031f, 0.4f);
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, -0.031f, 0.4f);
	glVertex3f(0.2f, -0.031f, 0.4f);
	//Right face
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, 0.031f, -0.4f);
	glVertex3f(0.2f, 0.031f, 0.4f);
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, -0.031f, 0.4f);
	glVertex3f(0.2f, -0.031f, -0.4f);
	//Back face
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	//Left Face
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, 0.031f, 0.4f);
	glVertex3f(-0.2f, 0.031f, -0.4f);
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, -0.031f, -0.4f);
	glVertex3f(-0.2f, -0.031f, 0.4f);
	//Top Face
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, 0.031f, -0.4f);
	glVertex3f(-0.2f, 0.031f, -0.4f);
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.031f, 0.4f);
	glVertex3f(0.2f, 0.031f, 0.4f);
	//Bottom Face
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.031f, -0.4f);
	glVertex3f(-0.2f, -0.031f, -0.4f);
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, -0.031f, 0.4f);
	glVertex3f(0.2f, -0.031f, 0.4f);
	glEnd();
	glPushMatrix();



	//___________________________ Mid  Barrel Holder Cylinder _____________________________//
	glTranslatef(0.0f, 0.13f, 0.25f);
	glRotatef(90, 1, 0, 0);
	glColor3f(0.404, 0.4, 0.42);
	gluCylinder(quadric, 0.05f, 0.05f, 1.0f, 50, 50);
	glPopMatrix();


	//____________________________ 1st Barrel Middle ______________________________//
	glTranslatef(0.55f, -0.38f, 0.15f);
	glRotatef(-70, 0, 1, 0);
	glColor3f(0.0f, tw_green, 0.0f);
	gluCylinder(quadric, 0.28f, 0.28f, 1.0f, 50, 50);
	//Barrel Disk 1
	glTranslatef(0.0f, 0.0f, 0.0f);
	glColor3f(0.38, 0.376, 0.392);
	gluDisk(quadric, 0.0, 0.28, 50, 50);
	//Barrel Disk 1
	glTranslatef(0.0f, 0.0f, 0.0f);
	glColor3f(0.38, 0.376, 0.392);
	gluDisk(quadric, 0.2, 0.28, 50, 50);


	//___________________________ 2st Barrel Middle _________________________________// 
	glTranslatef(0.0f, 0.0f, -1.1f);
	glPushMatrix();
	glColor3f(0.561, 0.537, 0.541);
	gluCylinder(quadric, 0.2f, 0.2f, 2.2f, 50, 50);
	glColor3f(0.682, 0.808, 0.824);
	//Ring 1
	glTranslatef(0.0f, 0.0f, 0.5f);
	gluCylinder(quadric, 0.21f, 0.21f, 0.01f, 50, 50);

	//Ring 2
	glTranslatef(0.0f, 0.0f, 0.1f);
	gluCylinder(quadric, 0.21f, 0.21f, 0.01f, 50, 50);

	//Ring 3
	glTranslatef(0.0f, 0.0f, 0.1f);
	gluCylinder(quadric, 0.21f, 0.21f, 0.01f, 50, 50);

	//Ring 4
	glTranslatef(0.0f, 0.0f, -0.3f);
	gluCylinder(quadric, 0.21f, 0.21f, 0.01f, 50, 50);
	glPopMatrix();
	//Barrel Disk 1
	glTranslatef(0.0f, 0.0f, 1.8f);
	glColor3f(0.733, 0.737, 0.769);
	gluDisk(quadric, 0.2, 0.28, 50, 50);
	//Barrel Disk 1
	glTranslatef(0.0f, 0.0f, 0.0f);
	glColor3f(0.733, 0.737, 0.769);
	gluDisk(quadric, 0.15, 0.2, 50, 50);


	//____________________________ 3nd Barrel Middle _______________________________//
	glTranslatef(0.0f, 0.0f, -2.5f);
	glColor3f(0.0f, 0.7f, 0.0f);
	gluCylinder(quadric, 0.15f, 0.15f, 2.2f, 50, 50);



	glPushMatrix();
	//Wire
	glTranslatef(-1.8f, 0.0f, 2.5f);
	glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	gluCylinder(quadric, 0.13f, 0.13f, 100.0f, 50, 50);
	//red Lazer
	glPopMatrix();


	glLineWidth(5);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
	glColor3f(0.0f, tw_green, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(15.0f, 0.0f, 0.0f);
	glEnd();

}

void turret3(void)
{

	glLoadIdentity();
	gluLookAt(camera.position.x, camera.position.y, camera.position.z, camera.front.x + camera.position.x, camera.front.y + camera.position.y, camera.front.z + camera.position.z, camera.up.x, camera.up.y, camera.up.z);
	glTranslatef(-20.0f, -10.0f, -20.0f);
	glScalef(2.0f, 2.0f, 2.0f);
	glRotatef(-tw_rot, 1.0f, 0.0f, 0.0f);

	//_______________________________ Bottom Base ________________________//
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -0.2f);
	glScalef(2.0f, 2.0f, 0.5f);
	glColor3f(0.149, 0.122, 0.11);
	gluSphere(quadric, 0.5f, 50, 50);
	glPopMatrix();
	//_______________________________ 1st Cylinderm ______________________//
	glColor3f(0.298, 0.259, 0.243);
	gluCylinder(quadric, 0.5f, 0.5f, 0.15, 50, 50);
	//Disk 
	glColor3f(0.337, 0.314, 0.318);
	gluDisk(quadric, 0.0, 0.5, 50, 50);

	//_______________________________ 2nd Cylinder _________________________//
	glTranslatef(0.0f, 0.0f, 0.15f);
	glColor3f(0.306, 0.275, 0.271);
	gluCylinder(quadric, 0.54f, 0.54f, 0.15, 50, 50);
	//Disk
	glColor3f(0.322, 0.29, 0.29);
	gluDisk(quadric, 0.0, 0.54, 50, 50);

	//________________________________ 3rd Cylinder _________________________//
	glTranslatef(0.0f, 0.0f, 0.15f);
	glColor3f(0.427, 0.365, 0.353);
	gluCylinder(quadric, 0.5f, 0.5f, 0.15, 50, 50);
	//Disk
	glColor3f(0.4, 0.408, 0.439);
	gluDisk(quadric, 0.0, 0.5, 50, 50);
	//Disc
	glTranslatef(0.0f, 0.0f, 0.15f);
	glColor3f(0.4, 0.408, 0.439);
	gluDisk(quadric, 0.0f, 0.5f, 50, 50);
	glPushMatrix();


	//______________________________1st Plate____________________________//
	glTranslatef(0.0f, -0.35f, 0.3f);
	glBegin(GL_QUADS);
	//Front face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.03f, 0.4f);
	glVertex3f(-0.2f, 0.03f, 0.4f);

	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.03f, 0.4f);
	glVertex3f(0.2f, -0.03f, 0.4f);
	//Right face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glVertex3f(0.2f, 0.03f, 0.4f);

	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.03f, 0.4f);
	glVertex3f(0.2f, -0.03f, -0.4f);
	//Back face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	//Left Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.03f, 0.4f);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, 0.4f);
	//Top Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, 0.03f, 0.4f);
	glVertex3f(0.2f, 0.03f, 0.4f);
	//Bottom Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.03f, 0.4f);
	glVertex3f(0.2f, -0.03f, 0.4f);
	glEnd();

	//________________________________ 2st Plate ______________________________//
	glTranslatef(0.0f, 0.75f, 0.0f);
	glBegin(GL_QUADS);
	//Front face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.03f, 0.4f);
	glVertex3f(-0.2f, 0.03f, 0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.03f, 0.4f);
	glVertex3f(0.2f, -0.03f, 0.4f);
	//Right face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glVertex3f(0.2f, 0.03f, 0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.03f, 0.4f);
	glVertex3f(0.2f, -0.03f, -0.4f);
	//Back face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	//Left Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.03f, 0.4f);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, 0.4f);
	//Top Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, 0.03f, 0.4f);
	glVertex3f(0.2f, 0.03f, 0.4f);
	//Bottom Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.03f, 0.4f);
	glVertex3f(0.2f, -0.03f, 0.4f);
	glEnd();
	glPopMatrix();



	//____________________________________ Up 1st Plate _______________________________//
	glTranslatef(-0.18f, -0.35f, 0.945f);
	glRotatef(-30, 0, 1, 0);
	glBegin(GL_QUADS);
	//Front face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.031f, 0.4f);
	glVertex3f(-0.2f, 0.031f, 0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.031f, 0.4f);
	glVertex3f(0.2f, -0.031f, 0.4f);
	//Right face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.031f, -0.4f);
	glVertex3f(0.2f, 0.031f, 0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.031f, 0.4f);
	glVertex3f(0.2f, -0.031f, -0.4f);
	//Back face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.031f, -0.4f);
	glVertex3f(0.2f, 0.031f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.031f, -0.4f);
	glVertex3f(-0.2f, -0.031f, -0.4f);
	//Left Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.031f, 0.4f);
	glVertex3f(-0.2f, 0.031f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.031f, -0.4f);
	glVertex3f(-0.2f, -0.031f, 0.4f);
	//Top Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, 0.031f, -0.4f);
	glVertex3f(-0.2f, 0.031f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, 0.031f, 0.4f);
	glVertex3f(0.2f, 0.031f, 0.4f);
	//Bottom Face
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, -0.031f, -0.4f);
	glVertex3f(-0.2f, -0.031f, -0.4f);
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, -0.031f, 0.4f);
	glVertex3f(0.2f, -0.031f, 0.4f);
	glEnd();


	//______________________________________ Up 2st Plate _______________________________//
	glTranslatef(0.0f, 0.75f, 0.0f);
	glBegin(GL_QUADS);
	//Front face
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, 0.031f, 0.4f);
	glVertex3f(-0.2f, 0.031f, 0.4f);
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, -0.031f, 0.4f);
	glVertex3f(0.2f, -0.031f, 0.4f);
	//Right face
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, 0.031f, -0.4f);
	glVertex3f(0.2f, 0.031f, 0.4f);
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, -0.031f, 0.4f);
	glVertex3f(0.2f, -0.031f, -0.4f);
	//Back face
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, 0.03f, -0.4f);
	glVertex3f(0.2f, 0.03f, -0.4f);
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(0.2f, -0.03f, -0.4f);
	glVertex3f(-0.2f, -0.03f, -0.4f);
	//Left Face
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(-0.2f, 0.031f, 0.4f);
	glVertex3f(-0.2f, 0.031f, -0.4f);
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, -0.031f, -0.4f);
	glVertex3f(-0.2f, -0.031f, 0.4f);
	//Top Face
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, 0.031f, -0.4f);
	glVertex3f(-0.2f, 0.031f, -0.4f);
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, 0.031f, 0.4f);
	glVertex3f(0.2f, 0.031f, 0.4f);
	//Bottom Face
	glColor3f(0.584, 0.561, 0.545);
	glVertex3f(0.2f, -0.031f, -0.4f);
	glVertex3f(-0.2f, -0.031f, -0.4f);
	glColor3f(0.404, 0.4, 0.42);
	glVertex3f(-0.2f, -0.031f, 0.4f);
	glVertex3f(0.2f, -0.031f, 0.4f);
	glEnd();
	glPushMatrix();



	//___________________________ Mid  Barrel Holder Cylinder _____________________________//
	glTranslatef(0.0f, 0.13f, 0.25f);
	glRotatef(90, 1, 0, 0);
	glColor3f(0.404, 0.4, 0.42);
	gluCylinder(quadric, 0.05f, 0.05f, 1.0f, 50, 50);
	glPopMatrix();


	//____________________________ 1st Barrel Middle ______________________________//
	glTranslatef(0.55f, -0.38f, 0.15f);
	glRotatef(-70, 0, 1, 0);
	glColor3f(0.0f, 0.0f, tw_blue);
	gluCylinder(quadric, 0.28f, 0.28f, 1.0f, 50, 50);
	//Barrel Disk 1
	glTranslatef(0.0f, 0.0f, 0.0f);
	glColor3f(0.38, 0.376, 0.392);
	gluDisk(quadric, 0.0, 0.28, 50, 50);
	//Barrel Disk 1
	glTranslatef(0.0f, 0.0f, 0.0f);
	glColor3f(0.38, 0.376, 0.392);
	gluDisk(quadric, 0.2, 0.28, 50, 50);


	//___________________________ 2st Barrel Middle _________________________________// 
	glTranslatef(0.0f, 0.0f, -1.1f);
	glPushMatrix();
	glColor3f(0.561, 0.537, 0.541);
	gluCylinder(quadric, 0.2f, 0.2f, 2.2f, 50, 50);
	glColor3f(0.682, 0.808, 0.824);
	//Ring 1
	glTranslatef(0.0f, 0.0f, 0.5f);
	gluCylinder(quadric, 0.21f, 0.21f, 0.01f, 50, 50);

	//Ring 2
	glTranslatef(0.0f, 0.0f, 0.1f);
	gluCylinder(quadric, 0.21f, 0.21f, 0.01f, 50, 50);

	//Ring 3
	glTranslatef(0.0f, 0.0f, 0.1f);
	gluCylinder(quadric, 0.21f, 0.21f, 0.01f, 50, 50);

	//Ring 4
	glTranslatef(0.0f, 0.0f, -0.3f);
	gluCylinder(quadric, 0.21f, 0.21f, 0.01f, 50, 50);
	glPopMatrix();
	//Barrel Disk 1
	glTranslatef(0.0f, 0.0f, 1.8f);
	glColor3f(0.733, 0.737, 0.769);
	gluDisk(quadric, 0.2, 0.28, 50, 50);
	//Barrel Disk 1
	glTranslatef(0.0f, 0.0f, 0.0f);
	glColor3f(0.733, 0.737, 0.769);
	gluDisk(quadric, 0.15, 0.2, 50, 50);


	//____________________________ 3nd Barrel Middle _______________________________//
	glTranslatef(0.0f, 0.0f, -2.5f);
	glColor3f(0.0f, 0.0f, 0.5f);
	gluCylinder(quadric, 0.15f, 0.15f, 2.2f, 50, 50);


	glPushMatrix();
	//Wire
	glTranslatef(-1.8f, 0.0f, 2.5f);
	glRotatef(10.0f, 0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	gluCylinder(quadric, 0.13f, 0.13f, 100.0f, 50, 50);
	//red Lazer
	glPopMatrix();


	glLineWidth(5);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, tw_blue);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(15.0f, -3.0f, 0.0f);
	glEnd();
	glDisable(GL_LINE_SMOOTH);

}

void screen1(void)
{
	glLoadIdentity();
	gluLookAt(camera.position.x, camera.position.y, camera.position.z, camera.front.x + camera.position.x, camera.front.y + camera.position.y, camera.front.z + camera.position.z, camera.up.x, camera.up.y, camera.up.z);
	glTranslatef(15.0f, 0.0f, -15.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glPushMatrix();
	glTranslatef(-16.75f, -1.45f, 1.0f);
	glScalef(30.5, 30.5, 0);
	float fbYTranslate = 0.0f;
	float fbXTranslate = 0.0f;
	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;

	for (int i = 1; i <= (11 * 21); i++)
	{
		//glPointSize(80);
		glBegin(GL_QUADS);
		//glTranslatef(0.0f, 0.0f, -5.0f);
		glColor3f(tw_red1, tw_green1, tw_blue1);
		glVertex3f(fbXTranslate + (i * 0.045f), fbYTranslate, 0.0f);
		glVertex3f(fbXTranslate + (i * 0.045f) + 0.1f, fbYTranslate, 0.0f);
		glVertex3f(fbXTranslate + (i * 0.045f) + 0.1f, fbYTranslate + 0.1f, 0.0f);
		glVertex3f(fbXTranslate + (i * 0.045f), fbYTranslate + 0.1f, 0.0f);
		glEnd();

		if (i % 21 == 0)
		{
			fbYTranslate = fbYTranslate + 0.045f;
			fbXTranslate = -(i * 0.045f);
		}
		if (i > 42 && i < 199)
		{
			//1st Line
			if (i > 45 && i < 59)
			{
				g = 59 - i;
				b = i - 44;

				tw_red1 = 0.14f * 0;
				tw_green1 = 1.0f * (g / 15);
				tw_blue1 = 1.0f * (b / 15);
			}
			else
			{
				//2st Line
				if (i > 67 && i < 79)
				{
					g = 79 - i;
					b = i - 66;

					tw_red1 = 0.14f * 2;
					tw_green1 = 1.0f * (g / 15) * (0.14 * 8);
					tw_blue1 = 1.0f * (b / 15) * (0.14 * 8);
				}
				else
				{
					//3st Line
					if (i > 89 && i < 99)
					{
						g = 99 - i;
						b = i - 88;

						tw_red1 = 0.14f * 3;
						tw_green1 = 1.0f * (g / 15) * (0.14 * 7);
						tw_blue1 = 1.0f * (b / 15) * (0.14 * 7);
					}
					else
					{
						//4st Line
						if (i > 111 && i < 119)
						{
							g = 119 - i;
							b = i - 110;

							tw_red1 = 0.14f * 4;
							tw_green1 = 1.0f * (g / 15) * (0.14 * 5);
							tw_blue1 = 1.0f * (b / 15) * (0.14 * 5);
						}
						else
						{
							//5st Line
							if (i > 133 && i < 139)
							{
								g = 139 - i;
								b = i - 132;

								tw_red1 = 0.14f * 5;
								tw_green1 = 1.0f * (g / 15) * (0.14 * 3);
								tw_blue1 = 1.0f * (b / 15) * (0.14 * 3);
							}
							else
							{
								//6st Line
								if (i > 155 && i < 159)
								{
									g = 159 - i;
									b = i - 154;

									tw_red1 = 0.14f * 6;
									tw_green1 = 1.0f * (g / 15) * (0.14 * 1);
									tw_blue1 = 1.0f * (b / 15) * (0.14 * 1);
								}
								else
								{
									//7st Line
									if (i > 177 && i < 179)
									{
										g = 179 - i;
										b = i - 176;

										tw_red1 = 0.14f * 7;
										tw_green1 = 1.0f * (g / 15) * (0.14 * 0);
										tw_blue1 = 1.0f * (b / 15) * (0.14 * 0);
									}
									else
									{
										tw_red1 = 0.0f;
										tw_green1 = 0.0f;
										tw_blue1 = 0.0f;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	glPopMatrix();


	glTranslatef(-0.1f, 6.9f, 0.0f);
	glScalef(9.0f, 9.0f, 17.0f);
	//glRotatef(-90.0f, 0, 1, 0);
	//Cube
	glBegin(GL_QUADS);
	//Front face RED
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(1.77f, 1.0f, 0.05f);
	glVertex3f(-1.77f, 1.0f, 0.05f);
	glVertex3f(-1.77f, -1.0f, 0.05f);
	glVertex3f(1.77f, -1.0f, 0.05f);
	//Right face GREEN
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(1.77f, 1.0f, -0.05f);
	glVertex3f(1.77f, 1.0f, 0.05f);
	glVertex3f(1.77f, -1.0f, 0.05f);
	glVertex3f(1.77f, -1.0f, -0.05f);
	//Back face BLUE
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(-1.77f, 1.0f, -0.05f);
	glVertex3f(1.77f, 1.0f, -0.05f);
	glVertex3f(1.77f, -1.0f, -0.05f);
	glVertex3f(-1.77f, -1.0f, -0.05f);
	//Left Face
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(-1.77f, 1.0f, 0.05f);
	glVertex3f(-1.77f, 1.0f, -0.05f);
	glVertex3f(-1.77f, -1.0f, -0.05f);
	glVertex3f(-1.77f, -1.0f, 0.05f);
	//Top Face
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(1.77f, 1.0f, -0.05f);
	glVertex3f(-1.77f, 1.0f, -0.05f);
	glVertex3f(-1.77f, 1.0f, 0.05f);
	glVertex3f(1.77f, 1.0f, 0.05f);
	//Bottom Face
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(1.77f, -1.0f, -0.05f);
	glVertex3f(-1.77f, -1.0f, -0.05f);
	glVertex3f(-1.77f, -1.0f, 0.05f);
	glVertex3f(1.77f, -1.0f, 0.05f);
	glEnd();

	//SCREEN
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(1.73f, 0.96f, 0.051f);
	glVertex3f(-1.73f, 0.96f, 0.051f);
	glVertex3f(-1.73f, -0.96f, 0.051f);
	glVertex3f(1.73f, -0.96f, 0.051f);
	glEnd();
	glPopMatrix();

	glScalef(2.0f, 1.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.8f, 0.8f, 8.5f, 50, 50);

	glTranslatef(0.0f, 0.0f, 10.0f);
	glScalef(2.0f, 4.0f, 1.0f);
	glColor3f(0.3f, 0.3f, 0.3f);
	gluSphere(quadric, 2.0f, 50, 50);



}

void screen2(void)
{
	glLoadIdentity();
	gluLookAt(camera.position.x, camera.position.y, camera.position.z, camera.front.x + camera.position.x, camera.front.y + camera.position.y, camera.front.z + camera.position.z, camera.up.x, camera.up.y, camera.up.z);
	glTranslatef(0.0f, 0.0f, -15.0f);
	//glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glPushMatrix();
	glTranslatef(-16.75f, -1.45f, 1.0f);
	glScalef(30.5, 30.5, 0);
	float fbYTranslate = 0.0f;
	float fbXTranslate = 0.0f;
	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;

	for (int i = 1; i <= (11 * 21); i++)
	{
		//glPointSize(80);
		glBegin(GL_QUADS);
		//glTranslatef(0.0f, 0.0f, -5.0f);
		glColor3f(tw_red1, tw_green1, tw_blue1);
		glVertex3f(fbXTranslate + (i * 0.045f), fbYTranslate, 0.0f);
		glVertex3f(fbXTranslate + (i * 0.045f) + 0.1f, fbYTranslate, 0.0f);
		glVertex3f(fbXTranslate + (i * 0.045f) + 0.1f, fbYTranslate + 0.1f, 0.0f);
		glVertex3f(fbXTranslate + (i * 0.045f), fbYTranslate + 0.1f, 0.0f);
		glEnd();

		if (i % 21 == 0)
		{
			fbYTranslate = fbYTranslate + 0.045f;
			fbXTranslate = -(i * 0.045f);
		}
		if (i > 42 && i < 199)
		{
			//1st Line
			if (i > 45 && i < 59)
			{
				g = 59 - i;
				b = i - 44;

				tw_red1 = 0.14f * 0;
				tw_green1 = 1.0f * (g / 15);
				tw_blue1 = 1.0f * (b / 15);
			}
			else
			{
				//2st Line
				if (i > 67 && i < 79)
				{
					g = 79 - i;
					b = i - 66;

					tw_red1 = 0.14f * 2;
					tw_green1 = 1.0f * (g / 15) * (0.14 * 8);
					tw_blue1 = 1.0f * (b / 15) * (0.14 * 8);
				}
				else
				{
					//3st Line
					if (i > 89 && i < 99)
					{
						g = 99 - i;
						b = i - 88;

						tw_red1 = 0.14f * 3;
						tw_green1 = 1.0f * (g / 15) * (0.14 * 7);
						tw_blue1 = 1.0f * (b / 15) * (0.14 * 7);
					}
					else
					{
						//4st Line
						if (i > 111 && i < 119)
						{
							g = 119 - i;
							b = i - 110;

							tw_red1 = 0.14f * 4;
							tw_green1 = 1.0f * (g / 15) * (0.14 * 5);
							tw_blue1 = 1.0f * (b / 15) * (0.14 * 5);
						}
						else
						{
							//5st Line
							if (i > 133 && i < 139)
							{
								g = 139 - i;
								b = i - 132;

								tw_red1 = 0.14f * 5;
								tw_green1 = 1.0f * (g / 15) * (0.14 * 3);
								tw_blue1 = 1.0f * (b / 15) * (0.14 * 3);
							}
							else
							{
								//6st Line
								if (i > 155 && i < 159)
								{
									g = 159 - i;
									b = i - 154;

									tw_red1 = 0.14f * 6;
									tw_green1 = 1.0f * (g / 15) * (0.14 * 1);
									tw_blue1 = 1.0f * (b / 15) * (0.14 * 1);
								}
								else
								{
									//7st Line
									if (i > 177 && i < 179)
									{
										g = 179 - i;
										b = i - 176;

										tw_red1 = 0.14f * 7;
										tw_green1 = 1.0f * (g / 15) * (0.14 * 0);
										tw_blue1 = 1.0f * (b / 15) * (0.14 * 0);
									}
									else
									{
										tw_red1 = 0.0f;
										tw_green1 = 0.0f;
										tw_blue1 = 0.0f;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	glPopMatrix();


	glTranslatef(-0.1f, 6.9f, 0.0f);
	glScalef(9.0f, 9.0f, 17.0f);
	//glRotatef(-90.0f, 0, 1, 0);
	//Cube
	glBegin(GL_QUADS);
	//Front face RED
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(1.77f, 1.0f, 0.05f);
	glVertex3f(-1.77f, 1.0f, 0.05f);
	glVertex3f(-1.77f, -1.0f, 0.05f);
	glVertex3f(1.77f, -1.0f, 0.05f);
	//Right face GREEN
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(1.77f, 1.0f, -0.05f);
	glVertex3f(1.77f, 1.0f, 0.05f);
	glVertex3f(1.77f, -1.0f, 0.05f);
	glVertex3f(1.77f, -1.0f, -0.05f);
	//Back face BLUE
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(-1.77f, 1.0f, -0.05f);
	glVertex3f(1.77f, 1.0f, -0.05f);
	glVertex3f(1.77f, -1.0f, -0.05f);
	glVertex3f(-1.77f, -1.0f, -0.05f);
	//Left Face
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(-1.77f, 1.0f, 0.05f);
	glVertex3f(-1.77f, 1.0f, -0.05f);
	glVertex3f(-1.77f, -1.0f, -0.05f);
	glVertex3f(-1.77f, -1.0f, 0.05f);
	//Top Face
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(1.77f, 1.0f, -0.05f);
	glVertex3f(-1.77f, 1.0f, -0.05f);
	glVertex3f(-1.77f, 1.0f, 0.05f);
	glVertex3f(1.77f, 1.0f, 0.05f);
	//Bottom Face
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(1.77f, -1.0f, -0.05f);
	glVertex3f(-1.77f, -1.0f, -0.05f);
	glVertex3f(-1.77f, -1.0f, 0.05f);
	glVertex3f(1.77f, -1.0f, 0.05f);
	glEnd();

	//SCREEN
	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(1.73f, 0.96f, 0.051f);
	glVertex3f(-1.73f, 0.96f, 0.051f);
	glVertex3f(-1.73f, -0.96f, 0.051f);
	glVertex3f(1.73f, -0.96f, 0.051f);
	glEnd();
	glPopMatrix();

	glScalef(2.0f, 1.0f, 1.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	gluCylinder(quadric, 0.8f, 0.8f, 8.5f, 50, 50);

	glTranslatef(0.0f, 0.0f, 10.0f);
	glScalef(2.0f, 4.0f, 1.0f);
	glColor3f(0.3f, 0.3f, 0.3f);
	gluSphere(quadric, 2.0f, 50, 50);



}

void updateColors(void)
{
	float r;
	float g;
	float b;

	//*** Code ***
	if (elapsedTime >= 0.490)
	{
		tw_count_for_color++;

		if (tw_count_for_color > 0 && tw_count_for_color < 500)
		{
			//1st Line
			if (tw_count_for_color > 45 && tw_count_for_color < 59)
			{
				g = 59 - tw_count_for_color;
				b = tw_count_for_color - 44;

				tw_red = 0.14f * 0;
				tw_green = 1.0f * (g / 15);
				tw_blue = 1.0f * (b / 15);
			}
			else
			{
				//2st Line
				if (tw_count_for_color > 67 && tw_count_for_color < 79)
				{
					g = 79 - tw_count_for_color;
					b = tw_count_for_color - 66;

					tw_red = 0.14f * 2;
					tw_green = 1.0f * (g / 15) * (0.14 * 8);
					tw_blue = 1.0f * (b / 15) * (0.14 * 8);
				}
				else
				{
					//3st Line
					if (tw_count_for_color > 89 && tw_count_for_color < 99)
					{
						g = 99 - tw_count_for_color;
						b = tw_count_for_color - 88;

						tw_red = 0.14f * 3;
						tw_green = 1.0f * (g / 15) * (0.14 * 7);
						tw_blue = 1.0f * (b / 15) * (0.14 * 7);
					}
					else
					{
						//4st Line
						if (tw_count_for_color > 111 && tw_count_for_color < 119)
						{
							g = 119 - tw_count_for_color;
							b = tw_count_for_color - 110;

							tw_red = 0.14f * 4;
							tw_green = 1.0f * (g / 15) * (0.14 * 5);
							tw_blue = 1.0f * (b / 15) * (0.14 * 5);
						}
						else
						{
							//5st Line
							if (tw_count_for_color > 133 && tw_count_for_color < 139)
							{
								g = 139 - tw_count_for_color;
								b = tw_count_for_color - 132;

								tw_red = 0.14f * 5;
								tw_green = 1.0f * (g / 15) * (0.14 * 3);
								tw_blue = 1.0f * (b / 15) * (0.14 * 3);
							}
							else
							{
								//6st Line
								if (tw_count_for_color > 155 && tw_count_for_color < 159)
								{
									g = 159 - tw_count_for_color;
									b = tw_count_for_color - 154;

									tw_red = 0.14f * 6;
									tw_green = 1.0f * (g / 15) * (0.14 * 1);
									tw_blue = 1.0f * (b / 15) * (0.14 * 1);
								}
								else
								{
									//7st Line
									if (tw_count_for_color > 177 && tw_count_for_color < 179)
									{
										g = 179 - tw_count_for_color;
										b = tw_count_for_color - 176;

										tw_red = 0.14f * 7;
										tw_green = 1.0f * (g / 15) * (0.14 * 0);
										tw_blue = 1.0f * (b / 15) * (0.14 * 0);
									}
									else
									{
										tw_red = 1.0f;
										tw_green = 1.0f;
										tw_blue = 1.0f;
									}
								}
							}
						}
					}
				}
			}
		}
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

			a = cos(f) * circle.radious.xAxis;
			b = sin(f) * circle.radious.yAxis;

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

			a = cos(f) * circle.radious.xAxis;
			b = sin(f) * circle.radious.yAxis;

			glColor3f(circle.color.r, circle.color.g, circle.color.b);
			glVertex3f(a + circle.center.xCoordinate, b + circle.center.yCoordinate, 0.0f);
		}
		glEnd();
		break;


	case GL_LINE_LOOP:
		glLineWidth(circle.size.line_width);
		glBegin(GL_LINE_LOOP);
		for (int i = circle.angle.from; i < circle.angle.to; i++)
		{
			f = (i) * (PI / 180);

			a = cos(f) * (circle.radious.xAxis);
			b = sin(f) * (circle.radious.yAxis);

			glColor3f(circle.color.r, circle.color.g, circle.color.b);
			glVertex3f(a + circle.center.xCoordinate, b + circle.center.yCoordinate, 0.0f);
		}
		glEnd();
		break;


	default:
		break;
	}
}


//Calssroom
void kalla_ka_sanga_mala(void)
{
	// PlaySound Using Resource
	PlaySound(MAKEINTRESOURCE(KALLA_KA_SANGA_MALA), GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
	sir_sound_1 = FALSE;
}

void drawCloud(void)
{
	//PlaySound
	void kalla_ka_sanga_mala(void);

	if (cloud_X_scale > 0.35f)
	{
		cloud_X_scale -= 0.05f;
		cloud_Y_scale -= 0.05f;
	}
	else
	{
		cloud_Y_scale = 0.15f;
		if (sir_sound_1 == TRUE)
		{
			kalla_ka_sanga_mala();
		}
	}
	// Tree 1
	glLoadIdentity();
	glTranslatef(0.05f, -0.23f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	//glScalef(0.5f, 0.2f, 1.0f);
	glScalef(cloud_X_scale, cloud_Y_scale, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(10.0f, 5.0f, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 15.0f;
		float y = sin(a) * 15.0f;

		glVertex3f((10.0f) + x, (5.0f) + y, 0.0f);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(27.0f, 17.0f, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 15.0f;
		float y = sin(a) * 15.0f;

		glVertex3f((27.0f) + x, (17.0f) + y, 0.0f);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(19.0f, 43.0f, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 15.0f;
		float y = sin(a) * 15.0f;

		glVertex3f((19.0f) + x, (43.0f) + y, 0.0f);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f, 30.0f, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 25.0f;
		float y = sin(a) * 25.0f;

		glVertex3f((0.0f) + x, (30.0f) + y, 0.0f);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-2.0f, 44.0f, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 20.0f;
		float y = sin(a) * 20.0f;

		glVertex3f((-2.0f) + x, (44.0f) + y, 0.0f);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-15.0f, 21.0f, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 20.0f;
		float y = sin(a) * 20.0f;

		glVertex3f((-15.0f) + x, (21.0f) + y, 0.0f);
	}
	glEnd();

	//Dots
	glEnable(GL_POINT_SMOOTH);

	glPointSize(20);
	glBegin(GL_POINTS);
	glVertex3f(40.0f, -10.0f, 0.0f);
	glEnd();

	glPointSize(15);
	glBegin(GL_POINTS);
	glVertex3f(60.0f, -30.0f, 0.0f);
	glEnd();

	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex3f(70.0f, -50.0f, 0.0f);
	glEnd();


	glDisable(GL_POINT_SMOOTH);
}

void drawCloud1(void)
{


	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(10.0f, 5.0f, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 15.0f;
		float y = sin(a) * 15.0f;

		glVertex3f((10.0f) + x, (5.0f) + y, 0.0f);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(27.0f, 17.0f, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 15.0f;
		float y = sin(a) * 15.0f;

		glVertex3f((27.0f) + x, (17.0f) + y, 0.0f);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(19.0f, 43.0f, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 15.0f;
		float y = sin(a) * 15.0f;

		glVertex3f((19.0f) + x, (43.0f) + y, 0.0f);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0.0f, 30.0f, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 25.0f;
		float y = sin(a) * 25.0f;

		glVertex3f((0.0f) + x, (30.0f) + y, 0.0f);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-2.0f, 44.0f, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 20.0f;
		float y = sin(a) * 20.0f;

		glVertex3f((-2.0f) + x, (44.0f) + y, 0.0f);
	}
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-15.0f, 21.0f, 0.0f);
	for (int i = 0; i < 363; i++)
	{
		float a = i * (3.14 / 180);
		float x = cos(a) * 20.0f;
		float y = sin(a) * 20.0f;

		glVertex3f((-15.0f) + x, (21.0f) + y, 0.0f);
	}
	glEnd();

	////Dots
	//glEnable(GL_POINT_SMOOTH);

	//glPointSize(20);
	//glBegin(GL_POINTS);
	//glVertex3f(40.0f, -10.0f, 0.0f);
	//glEnd();

	//glPointSize(15);
	//glBegin(GL_POINTS);
	//glVertex3f(60.0f, -30.0f, 0.0f);
	//glEnd();

	//glPointSize(5);
	//glBegin(GL_POINTS);
	//glVertex3f(70.0f, -50.0f, 0.0f);
	//glEnd();


	//glDisable(GL_POINT_SMOOTH);
}

void drawClassroom1(void)
{
	//Function Declaration
	void SirBackView001(void);


	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -3.0f);
	glScalef(0.022f, 0.022f, 0.022f);

	// 1
	glBegin(GL_POLYGON);
	glColor3f(0.733, 0.725, 0.725);
	glVertex3f(99.6372f, 56.22f, 0.0f);
	glVertex3f(-99.6372f, 56.22f, 0.0f);
	glVertex3f(-99.9391f, 48.6563f, 0.0f);
	glColor3f(0.753, 0.784, 0.925);
	glVertex3f(-67.2865f, 33.3984f, 0.0f);
	glVertex3f(67.2865f, 33.3984f, 0.0f);
	glVertex3f(99.9391f, 48.6563f, 0.0f);
	glEnd();

	//2 back of blackboard
	glBegin(GL_POLYGON);
	glColor3f(0.812, 0.835, 0.796);
	glVertex3f(67.2865f, 33.3984f, 0.0f);
	glVertex3f(-67.2865f, 33.3984f, 0.0f);
	glColor3f(0.518, 0.522, 0.498);
	glVertex3f(-67.2865f, -33.9797f, 0.0f);
	glVertex3f(67.2865f, -33.9797f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.812, 0.835, 0.796);
	glVertex3f(67.2865f, 33.3984f, 0.0f);

	glEnd();

	//3
	glBegin(GL_POLYGON);
	glColor3f(0.569, 0.533, 0.42);
	glVertex3f(-67.2865f, -33.9797f, 0.0f);
	glVertex3f(-67.2865f, 33.3984f, 0.0f);
	glVertex3f(-99.9391f, 48.6563f, 0.0f);
	glVertex3f(-99.9391f, -56.22f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.569, 0.533, 0.42);
	glVertex3f(67.2865f, -33.9797f, 0.0f);
	glVertex3f(67.2865f, 33.3984f, 0.0f);
	glVertex3f(99.9391f, 48.6563f, 0.0f);
	glVertex3f(99.9391f, -56.22f, 0.0f);
	glEnd();

	//4 flour
	glBegin(GL_POLYGON);
	glColor3f(0.694, 0.455, 0.192);
	glVertex3f(67.2865f, -33.9797f, 0.0f);
	glColor3f(0.416, 0.235, 0.102);
	glVertex3f(-67.2865f, -33.9797f, 0.0f);
	glVertex3f(-99.9391f, -49.6995f, 0.0f);
	glColor3f(0.416, 0.235, 0.102);
	glVertex3f(-99.9391f, -56.22f, 0.0f);
	glVertex3f(99.9391f, -56.22f, 0.0f);
	glColor3f(0.694, 0.455, 0.192);
	glVertex3f(99.9391f, -49.6995f, 0.0f);
	glEnd();

	//BlackBoard
	glBegin(GL_POLYGON);
	glColor3f(0.173, 0.173, 0.18);
	glVertex3f(20.0893f, 3.86695f, 0.0f);
	glVertex3f(-20.0893f, 3.86695f, 0.0f);
	glVertex3f(-20.0893f, -17.4484f, 0.0f);
	glVertex3f(20.0893f, -17.4484f, 0.0f);
	glEnd();

	///////////////////////////////////////////////////////////
	//window Right
	glLoadIdentity();
	glTranslatef(0.5f, -0.13f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.5f, 0.5f, 0.5f);
	// back brown
	glBegin(GL_POLYGON);
	glColor3f(0.424, 0.157, 0.075);
	glVertex3f(18.1718f, 53.1175f, 0.0f);
	glVertex3f(-18.1718f, 53.1175f, 0.0f);
	glVertex3f(-18.1718f, -38.3435f, 0.0f);
	glVertex3f(18.1718f, -38.3435f, 0.0f);
	glEnd();

	//upper back 
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(14.6406f, 49.5863f, 0.0f);
	glVertex3f(-14.6406f, 49.5863f, 0.0f);
	glVertex3f(-14.6406f, 43.0672f, 0.0f);
	glVertex3f(14.6406f, 43.0672f, 0.0f);
	glEnd();
	//inside
	glBegin(GL_POLYGON);
	glColor3f(0., 0.569, 0.878);
	glVertex3f(-1.43639f, 47.0756f, 0.0f);
	glVertex3f(-11.0252f, 47.0756f, 0.0f);
	glVertex3f(-11.0252f, 44.4819f, 0.0f);
	glVertex3f(-1.43639f, 44.4819f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0., 0.569, 0.878);
	glVertex3f(1.43639f, 47.0756f, 0.0f);
	glVertex3f(11.0252f, 47.0756f, 0.0f);
	glVertex3f(11.0252f, 44.4819f, 0.0f);
	glVertex3f(1.43639f, 44.4819f, 0.0f);
	glEnd();

	//back white
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(16.295f, 36.748f, 0.0f);
	glVertex3f(1.77035f, 36.748f, 0.0f);
	glVertex3f(1.77035f, 3.54884f, 0.0f);
	glVertex3f(16.295f, 3.54884f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-16.295f, 36.748f, 0.0f);
	glVertex3f(-1.77035f, 36.748f, 0.0f);
	glVertex3f(-1.77035f, 3.54884f, 0.0f);
	glVertex3f(-16.295f, 3.54884f, 0.0f);
	glEnd();
	//bottom white bk
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-16.295f, -36.748f, 0.0f);
	glVertex3f(-1.77035f, -36.748f, 0.0f);
	glVertex3f(-1.77035f, -3.54884f, 0.0f);
	glVertex3f(-16.295f, -3.54884f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(16.295f, -36.748f, 0.0f);
	glVertex3f(1.77035f, -36.748f, 0.0f);
	glVertex3f(1.77035f, -3.54884f, 0.0f);
	glVertex3f(16.295f, -3.54884f, 0.0f);
	glEnd();
	// in betwn brown part
	glBegin(GL_POLYGON);
	glColor3f(0.424, 0.157, 0.075);
	glVertex3f(14.1257f, -33.5413f, 0.0f);
	glVertex3f(4.41121f, -33.5413f, 0.0f);
	glVertex3f(4.41121f, -7.03852f, 0.0f);
	glVertex3f(14.1257f, -7.03852f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.424, 0.157, 0.075);
	glVertex3f(-14.1257f, -33.5413f, 0.0f);
	glVertex3f(-4.41121f, -33.5413f, 0.0f);
	glVertex3f(-4.41121f, -7.03852f, 0.0f);
	glVertex3f(-14.1257f, -7.03852f, 0.0f);
	glEnd();

	// small inside triangles 
	glBegin(GL_TRIANGLES);
	// blue
	glColor3f(0.133, 0.2, 0.416);
	glVertex3f(14.2358f, 35.7027f, 0.0f);
	glVertex3f(3.75624f, 35.7027f, 0.0f);
	glVertex3f(8.93051f, 29.7425f, 0.0f);

	glVertex3f(14.2358f, 4.52608f, 0.0f);
	glVertex3f(8.93051f, 10.7483f, 0.0f);
	glVertex3f(3.75624f, 4.52608f, 0.0f);

	//green
	glColor3f(0.122, 0.282, 0.251);
	glVertex3f(7.81706f, 28.629f, 0.0f);
	glVertex3f(2.70829f, 34.3928f, 0.0f);
	glVertex3f(2.70829f, 22.4723f, 0.0f);

	glVertex3f(7.81706f, 11.6653f, 0.0f);
	glVertex3f(2.70829f, 18.215f, 0.0f);
	glVertex3f(2.70829f, 5.44308f, 0.0f);

	glVertex3f(15.0217f, 18.215f, 0.0f);
	glVertex3f(9.78198f, 11.6653f, 0.0f);
	glVertex3f(15.0872f, 5.44308f, 0.0f);

	glVertex3f(15.0217f, 22.4723f, 0.0f);
	glVertex3f(15.0217f, 34.3928f, 0.0f);
	glVertex3f(9.78198f, 28.629f, 0.0f);
	glEnd();

	// small inside triangles 
	glBegin(GL_TRIANGLES);
	// blue
	glColor3f(0.133, 0.2, 0.416);
	glVertex3f(-14.2358f, 35.7027f, 0.0f);
	glVertex3f(-3.75624f, 35.7027f, 0.0f);
	glVertex3f(-8.93051f, 29.7425f, 0.0f);

	glVertex3f(-14.2358f, 4.52608f, 0.0f);
	glVertex3f(-8.93051f, 10.7483f, 0.0f);
	glVertex3f(-3.75624f, 4.52608f, 0.0f);

	//green
	glColor3f(-0.122, 0.282, 0.251);
	glVertex3f(-7.81706f, 28.629f, 0.0f);
	glVertex3f(-2.70829f, 34.3928f, 0.0f);
	glVertex3f(-2.70829f, 22.4723f, 0.0f);

	glVertex3f(-7.81706f, 11.6653f, 0.0f);
	glVertex3f(-2.70829f, 18.215f, 0.0f);
	glVertex3f(-2.70829f, 5.44308f, 0.0f);

	glVertex3f(-15.0217f, 18.215f, 0.0f);
	glVertex3f(-9.78198f, 11.6653f, 0.0f);
	glVertex3f(-15.0872f, 5.44308f, 0.0f);

	glVertex3f(-15.0217f, 22.4723f, 0.0f);
	glVertex3f(-15.0217f, 34.3928f, 0.0f);
	glVertex3f(-9.78198f, 28.629f, 0.0f);
	glEnd();

	// middle quad red
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.11, 0.098);
	glVertex3f(15.0217f, 20.2334f, 0.0f);
	glVertex3f(8.93051f, 27.0571f, 0.0f);
	glVertex3f(2.70829f, 20.2334f, 0.0f);
	glVertex3f(8.93051f, 12.8442f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.11, 0.098);
	glVertex3f(-15.0217f, 20.2334f, 0.0f);
	glVertex3f(-8.93051f, 27.0571f, 0.0f);
	glVertex3f(-2.70829f, 20.2334f, 0.0f);
	glVertex3f(-8.93051f, 12.8442f, 0.0f);
	glEnd();

	///////////////////////////////////////////////////////////
	//window left
	glLoadIdentity();
	glTranslatef(-0.5f, -0.13f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.5f, 0.5f, 0.5f);
	// back brown
	glBegin(GL_POLYGON);
	glColor3f(0.424, 0.157, 0.075);
	glVertex3f(18.1718f, 53.1175f, 0.0f);
	glVertex3f(-18.1718f, 53.1175f, 0.0f);
	glVertex3f(-18.1718f, -38.3435f, 0.0f);
	glVertex3f(18.1718f, -38.3435f, 0.0f);
	glEnd();

	//upper back 
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(14.6406f, 49.5863f, 0.0f);
	glVertex3f(-14.6406f, 49.5863f, 0.0f);
	glVertex3f(-14.6406f, 43.0672f, 0.0f);
	glVertex3f(14.6406f, 43.0672f, 0.0f);
	glEnd();
	//inside
	glBegin(GL_POLYGON);
	glColor3f(0., 0.569, 0.878);
	glVertex3f(-1.43639f, 47.0756f, 0.0f);
	glVertex3f(-11.0252f, 47.0756f, 0.0f);
	glVertex3f(-11.0252f, 44.4819f, 0.0f);
	glVertex3f(-1.43639f, 44.4819f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0., 0.569, 0.878);
	glVertex3f(1.43639f, 47.0756f, 0.0f);
	glVertex3f(11.0252f, 47.0756f, 0.0f);
	glVertex3f(11.0252f, 44.4819f, 0.0f);
	glVertex3f(1.43639f, 44.4819f, 0.0f);
	glEnd();

	//back white
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(16.295f, 36.748f, 0.0f);
	glVertex3f(1.77035f, 36.748f, 0.0f);
	glVertex3f(1.77035f, 3.54884f, 0.0f);
	glVertex3f(16.295f, 3.54884f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-16.295f, 36.748f, 0.0f);
	glVertex3f(-1.77035f, 36.748f, 0.0f);
	glVertex3f(-1.77035f, 3.54884f, 0.0f);
	glVertex3f(-16.295f, 3.54884f, 0.0f);
	glEnd();
	//bottom white bk
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-16.295f, -36.748f, 0.0f);
	glVertex3f(-1.77035f, -36.748f, 0.0f);
	glVertex3f(-1.77035f, -3.54884f, 0.0f);
	glVertex3f(-16.295f, -3.54884f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(16.295f, -36.748f, 0.0f);
	glVertex3f(1.77035f, -36.748f, 0.0f);
	glVertex3f(1.77035f, -3.54884f, 0.0f);
	glVertex3f(16.295f, -3.54884f, 0.0f);
	glEnd();
	// in betwn brown part
	glBegin(GL_POLYGON);
	glColor3f(0.424, 0.157, 0.075);
	glVertex3f(14.1257f, -33.5413f, 0.0f);
	glVertex3f(4.41121f, -33.5413f, 0.0f);
	glVertex3f(4.41121f, -7.03852f, 0.0f);
	glVertex3f(14.1257f, -7.03852f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.424, 0.157, 0.075);
	glVertex3f(-14.1257f, -33.5413f, 0.0f);
	glVertex3f(-4.41121f, -33.5413f, 0.0f);
	glVertex3f(-4.41121f, -7.03852f, 0.0f);
	glVertex3f(-14.1257f, -7.03852f, 0.0f);
	glEnd();

	// small inside triangles 
	glBegin(GL_TRIANGLES);
	// blue
	glColor3f(0.133, 0.2, 0.416);
	glVertex3f(14.2358f, 35.7027f, 0.0f);
	glVertex3f(3.75624f, 35.7027f, 0.0f);
	glVertex3f(8.93051f, 29.7425f, 0.0f);

	glVertex3f(14.2358f, 4.52608f, 0.0f);
	glVertex3f(8.93051f, 10.7483f, 0.0f);
	glVertex3f(3.75624f, 4.52608f, 0.0f);

	//green
	glColor3f(0.122, 0.282, 0.251);
	glVertex3f(7.81706f, 28.629f, 0.0f);
	glVertex3f(2.70829f, 34.3928f, 0.0f);
	glVertex3f(2.70829f, 22.4723f, 0.0f);

	glVertex3f(7.81706f, 11.6653f, 0.0f);
	glVertex3f(2.70829f, 18.215f, 0.0f);
	glVertex3f(2.70829f, 5.44308f, 0.0f);

	glVertex3f(15.0217f, 18.215f, 0.0f);
	glVertex3f(9.78198f, 11.6653f, 0.0f);
	glVertex3f(15.0872f, 5.44308f, 0.0f);

	glVertex3f(15.0217f, 22.4723f, 0.0f);
	glVertex3f(15.0217f, 34.3928f, 0.0f);
	glVertex3f(9.78198f, 28.629f, 0.0f);
	glEnd();

	// small inside triangles 
	glBegin(GL_TRIANGLES);
	// blue
	glColor3f(0.133, 0.2, 0.416);
	glVertex3f(-14.2358f, 35.7027f, 0.0f);
	glVertex3f(-3.75624f, 35.7027f, 0.0f);
	glVertex3f(-8.93051f, 29.7425f, 0.0f);

	glVertex3f(-14.2358f, 4.52608f, 0.0f);
	glVertex3f(-8.93051f, 10.7483f, 0.0f);
	glVertex3f(-3.75624f, 4.52608f, 0.0f);

	//green
	glColor3f(-0.122, 0.282, 0.251);
	glVertex3f(-7.81706f, 28.629f, 0.0f);
	glVertex3f(-2.70829f, 34.3928f, 0.0f);
	glVertex3f(-2.70829f, 22.4723f, 0.0f);

	glVertex3f(-7.81706f, 11.6653f, 0.0f);
	glVertex3f(-2.70829f, 18.215f, 0.0f);
	glVertex3f(-2.70829f, 5.44308f, 0.0f);

	glVertex3f(-15.0217f, 18.215f, 0.0f);
	glVertex3f(-9.78198f, 11.6653f, 0.0f);
	glVertex3f(-15.0872f, 5.44308f, 0.0f);

	glVertex3f(-15.0217f, 22.4723f, 0.0f);
	glVertex3f(-15.0217f, 34.3928f, 0.0f);
	glVertex3f(-9.78198f, 28.629f, 0.0f);
	glEnd();

	// middle quad red
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.11, 0.098);
	glVertex3f(15.0217f, 20.2334f, 0.0f);
	glVertex3f(8.93051f, 27.0571f, 0.0f);
	glVertex3f(2.70829f, 20.2334f, 0.0f);
	glVertex3f(8.93051f, 12.8442f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.11, 0.098);
	glVertex3f(-15.0217f, 20.2334f, 0.0f);
	glVertex3f(-8.93051f, 27.0571f, 0.0f);
	glVertex3f(-2.70829f, 20.2334f, 0.0f);
	glVertex3f(-8.93051f, 12.8442f, 0.0f);
	glEnd();


	glLoadIdentity();
	glTranslatef(0.0f, -0.2f, -3.0f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(1.8f, 1.8f, 1.5f);
	// CARPET
	glBegin(GL_POLYGON);
	glColor3f(0.153, 0.306, 0.322);
	glVertex3f(10.5634f, -33.5764f, 0.0f);
	glVertex3f(-10.5634f, -33.5764f, 0.0f);
	glVertex3f(-20.1836f, -50.176f, 0.0f);
	glVertex3f(20.1836f, -50.176f, 0.0f);

	glEnd();



	//Sir BAck View
	glLoadIdentity();
	SirBackView001();


	//************************* CHAIR ******************************
	glLoadIdentity();
	glTranslatef(0.0f, -0.75f, -3.0f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.25f, 0.25f, 0.5f);

	//top
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.096834, 58.8766, 0.0f);
	glVertex3f(35.5671, 59.1785, 0.0f);
	glVertex3f(36.1709, 70.048, 0.0f);
	glVertex3f(32.8497, 76.0866, 0.0f);
	glVertex3f(27.113, 80.9175, 0.0f);
	glVertex3f(21.0744, 82.1253, 0.0f);
	glVertex3f(-21.0744, 82.1253, 0.0f);
	glVertex3f(-27.113, 80.9175, 0.0f);
	glVertex3f(-32.8497, 76.0866, 0.0f);
	glVertex3f(-36.1709, 70.048, 0.0f);
	glVertex3f(-35.5671, 59.1785, 0.0f);
	glVertex3f(-0.241117, 67.6326, 0.0f);
	glVertex3f(-0.096834, 58.8766, 0.0f);
	glEnd();

	//side rods
	glEnable(GL_LINE_SMOOTH);
	glLineWidth(4);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-33.5671, 59.1785, 0.0f);
	glVertex3f(-39.6023, -64.4754, 0.0f);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3f(33.5671, 59.1785, 0.0f);
	glVertex3f(39.6023, -64.4754, 0.0f);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-38.4643, -35.4116, 0.0f);
	glVertex3f(38.4643, -35.4116, 0.0f);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-35.6971, 26.7807, 0.0f);
	glVertex3f(-28.1871, -29.7791, 0.0f);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(35.6971, 26.7807, 0.0f);
	glVertex3f(28.1871, -29.7791, 0.0f);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(30.2993, -13.5856, 0.0f);
	glVertex3f(-30.2993, -13.5856, 0.0f);
	glEnd();

	//seat
	glBegin(GL_POLYGON);
	glVertex3f(38.8199, 9.5802, 0.0f);//
	glVertex3f(25.0868, 20.733, 0.0f);
	glVertex3f(-25.0868, 20.733, 0.0f);
	glVertex3f(-38.8199, 9.5802, 0.0f);//
	glEnd();
}

void Students(void)
{
	//Function Declaration
	void drawBoy(void);
	void drawGirl(void);
	void drawBoy1(void);
	void drawGirl1(void);
	void drawBoy2(void);
	void drawGirl2(void);
	void drawBoy3(void);
	void drawGirl3(void);

	void drawBoy4(void);
	void drawBoy5(void);
	void drawGirl4(void);
	void drawBoy6(void);
	void drawGirl5(void);
	void drawBoy7(void);
	void drawGirl6(void);
	void drawBoy3(void);
	void drawGirl7(void);

	//CaLL
	drawBoy();
	drawBoy1();
	drawGirl();
	drawGirl1();
	drawBoy2();
	drawBoy3();
	drawGirl2();
	drawGirl3();

	drawBoy4();
	drawBoy5();
	drawGirl4();
	drawGirl5();
	drawBoy6();
	drawBoy7();
	drawGirl6();
	drawGirl7();

}

void drawBoy(void)
{
	glLoadIdentity();
	glTranslatef(-0.2f, -0.4f, -1.4f);
	glScalef(0.015f, 0.01f, 0.01f);
	glScalef(0.2f, 0.2f, 0.5f);

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.733, 0.725, 0.725);
	glVertex3f(-1.44927f, 56.22f, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(9.73336f, 42.6097, 0.0f);
	glVertex3f(11.1312f, 47.1527, 0.0f);
	glVertex3f(11.6554f, 50.4725, 0.0f);
	glVertex3f(8.50026f, 60.0826, 0.0f);
	glVertex3f(4.31677f, 63.4024, 0.0f);
	glVertex3f(-2.45873f, 64.1784, 0.0f);
	glVertex3f(-7.21531f, 62.3541, 0.0f);
	glVertex3f(-11.2341f, 59.9079, 0.0f);
	glVertex3f(-12.9814f, 55.8891, 0.0f);
	glVertex3f(-14.0297f, 52.3945, 0.0f);
	glVertex3f(-14.2045f, 47.5021, 0.0f);
	glVertex3f(-12.8066f, 43.8328, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-7.7395, 37.3679, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glEnd();

	//boy neck
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(6.46189f, 38.4162, 0.0f);
	glVertex3f(-7.7395f, 37.3679f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glEnd();

	//T-Shirt
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 0.675);
	glVertex3f(-0.948761f, 8.13055, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(25.4536f, 16.1265, 0.0f);
	glVertex3f(21.2162f, 24.1124, 0.0f);
	glVertex3f(14.2082f, 29.3277, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(-14.2082f, 29.3277, 0.0f);
	glVertex3f(-21.2162f, 24.1124, 0.0f);
	glVertex3f(-25.4536f, 16.1265, 0.0f);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-19.6912f, -20.2176, 0.0f);
	glVertex3f(-11.0534f, -25.1069, 0.0f);
	glVertex3f(0.029106f, -27.2256, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glEnd();

	//Bottom right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 1.0);
	glVertex3f(22.1941f, -30.3222, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(-0.3f, -25.2256, 0.0f);
	glVertex3f(0.02911f, -41.8936, 0.0f);
	glVertex3f(14.0452f, -39.9378, 0.0f);
	glVertex3f(24.3128f, -35.2115, 0.0f);
	glVertex3f(31.4838f, -25.7588, 0.0f);
	glVertex3f(31.4838f, -11.4167, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glEnd();
	//Bottom left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 1.0);
	glVertex3f(-22.1941f, -30.3222, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glVertex3f(-9.31884f, -24.5958, 0.0f);
	glVertex3f(-0.029106f, -27.2256, 0.0f);
	glVertex3f(-0.02911f, -41.8936, 0.0f);
	glVertex3f(-14.0452f, -39.9378, 0.0f);
	glVertex3f(-24.3128f, -35.2115, 0.0f);
	glVertex3f(-31.4838f, -25.7588, 0.0f);
	glVertex3f(-31.4838f, -11.4167, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(27.4094f, -11.2538, 0.0f);
	glEnd();
	//left hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-27.4094f, -11.2538, 0.0f);
	glEnd();

}

void drawBoy1(void)
{
	glLoadIdentity();
	glTranslatef(-0.2f, -0.53f, -1.4f);
	glScalef(0.015f, 0.01f, 0.01f);
	glScalef(0.2f, 0.2f, 0.5f);

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.208, 0.11, 0.122);
	glVertex3f(-1.44927f, 56.22f, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(9.73336f, 42.6097, 0.0f);
	glVertex3f(11.1312f, 47.1527, 0.0f);
	glVertex3f(11.6554f, 50.4725, 0.0f);
	glVertex3f(8.50026f, 60.0826, 0.0f);
	glVertex3f(4.31677f, 63.4024, 0.0f);
	glVertex3f(-2.45873f, 64.1784, 0.0f);
	glVertex3f(-7.21531f, 62.3541, 0.0f);
	glVertex3f(-11.2341f, 59.9079, 0.0f);
	glVertex3f(-12.9814f, 55.8891, 0.0f);
	glVertex3f(-14.0297f, 52.3945, 0.0f);
	glVertex3f(-14.2045f, 47.5021, 0.0f);
	glVertex3f(-12.8066f, 43.8328, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-7.7395, 37.3679, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glEnd();

	//boy neck
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(6.46189f, 38.4162, 0.0f);
	glVertex3f(-7.7395f, 37.3679f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glEnd();

	//T-Shirt
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.165, 0.153, 0.3);
	glVertex3f(-0.948761f, 8.13055, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(25.4536f, 16.1265, 0.0f);
	glVertex3f(21.2162f, 24.1124, 0.0f);
	glVertex3f(14.2082f, 29.3277, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(-14.2082f, 29.3277, 0.0f);
	glVertex3f(-21.2162f, 24.1124, 0.0f);
	glVertex3f(-25.4536f, 16.1265, 0.0f);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-19.6912f, -20.2176, 0.0f);
	glVertex3f(-11.0534f, -25.1069, 0.0f);
	glVertex3f(0.029106f, -27.2256, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glEnd();

	//Bottom right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0.5, 0);
	glVertex3f(22.1941f, -30.3222, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(-0.3f, -25.2256, 0.0f);
	glVertex3f(0.02911f, -41.8936, 0.0f);
	glVertex3f(14.0452f, -39.9378, 0.0f);
	glVertex3f(24.3128f, -35.2115, 0.0f);
	glVertex3f(31.4838f, -25.7588, 0.0f);
	glVertex3f(31.4838f, -11.4167, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glEnd();
	//Bottom left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0.5, 0);
	glVertex3f(-22.1941f, -30.3222, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glVertex3f(-9.31884f, -24.5958, 0.0f);
	glVertex3f(-0.029106f, -27.2256, 0.0f);
	glVertex3f(-0.02911f, -41.8936, 0.0f);
	glVertex3f(-14.0452f, -39.9378, 0.0f);
	glVertex3f(-24.3128f, -35.2115, 0.0f);
	glVertex3f(-31.4838f, -25.7588, 0.0f);
	glVertex3f(-31.4838f, -11.4167, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(27.4094f, -11.2538, 0.0f);
	glEnd();
	//left hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-27.4094f, -11.2538, 0.0f);
	glEnd();

}

void drawBoy2(void)
{
	glLoadIdentity();
	glTranslatef(-0.4f, -0.4f, -1.4f);
	glScalef(0.015f, 0.01f, 0.01f);
	glScalef(0.2f, 0.2f, 0.5f);

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.412, 0.239, 0.133);
	glVertex3f(-1.44927f, 56.22f, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(9.73336f, 42.6097, 0.0f);
	glVertex3f(11.1312f, 47.1527, 0.0f);
	glVertex3f(11.6554f, 50.4725, 0.0f);
	glVertex3f(8.50026f, 60.0826, 0.0f);
	glVertex3f(4.31677f, 63.4024, 0.0f);
	glVertex3f(-2.45873f, 64.1784, 0.0f);
	glVertex3f(-7.21531f, 62.3541, 0.0f);
	glVertex3f(-11.2341f, 59.9079, 0.0f);
	glVertex3f(-12.9814f, 55.8891, 0.0f);
	glVertex3f(-14.0297f, 52.3945, 0.0f);
	glVertex3f(-14.2045f, 47.5021, 0.0f);
	glVertex3f(-12.8066f, 43.8328, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-7.7395, 37.3679, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glEnd();

	//boy neck
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(6.46189f, 38.4162, 0.0f);
	glVertex3f(-7.7395f, 37.3679f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glEnd();

	//T-Shirt
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.678, 0.518, 0.788);
	glVertex3f(-0.948761f, 8.13055, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(25.4536f, 16.1265, 0.0f);
	glVertex3f(21.2162f, 24.1124, 0.0f);
	glVertex3f(14.2082f, 29.3277, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(-14.2082f, 29.3277, 0.0f);
	glVertex3f(-21.2162f, 24.1124, 0.0f);
	glVertex3f(-25.4536f, 16.1265, 0.0f);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-19.6912f, -20.2176, 0.0f);
	glVertex3f(-11.0534f, -25.1069, 0.0f);
	glVertex3f(0.029106f, -27.2256, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glEnd();

	//Bottom right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(22.1941f, -30.3222, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(-0.3f, -25.2256, 0.0f);
	glVertex3f(0.02911f, -41.8936, 0.0f);
	glVertex3f(14.0452f, -39.9378, 0.0f);
	glVertex3f(24.3128f, -35.2115, 0.0f);
	glVertex3f(31.4838f, -25.7588, 0.0f);
	glVertex3f(31.4838f, -11.4167, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glEnd();
	//Bottom left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-22.1941f, -30.3222, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glVertex3f(-9.31884f, -24.5958, 0.0f);
	glVertex3f(-0.029106f, -27.2256, 0.0f);
	glVertex3f(-0.02911f, -41.8936, 0.0f);
	glVertex3f(-14.0452f, -39.9378, 0.0f);
	glVertex3f(-24.3128f, -35.2115, 0.0f);
	glVertex3f(-31.4838f, -25.7588, 0.0f);
	glVertex3f(-31.4838f, -11.4167, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(27.4094f, -11.2538, 0.0f);
	glEnd();
	//left hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-27.4094f, -11.2538, 0.0f);
	glEnd();

}

void drawBoy3(void)
{
	glLoadIdentity();
	glTranslatef(-0.4f, -0.53f, -1.4f);
	glScalef(0.015f, 0.01f, 0.01f);
	glScalef(0.2f, 0.2f, 0.5f);

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.208, 0.11, 0.122);
	glVertex3f(-1.44927f, 56.22f, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(9.73336f, 42.6097, 0.0f);
	glVertex3f(11.1312f, 47.1527, 0.0f);
	glVertex3f(11.6554f, 50.4725, 0.0f);
	glVertex3f(8.50026f, 60.0826, 0.0f);
	glVertex3f(4.31677f, 63.4024, 0.0f);
	glVertex3f(-2.45873f, 64.1784, 0.0f);
	glVertex3f(-7.21531f, 62.3541, 0.0f);
	glVertex3f(-11.2341f, 59.9079, 0.0f);
	glVertex3f(-12.9814f, 55.8891, 0.0f);
	glVertex3f(-14.0297f, 52.3945, 0.0f);
	glVertex3f(-14.2045f, 47.5021, 0.0f);
	glVertex3f(-12.8066f, 43.8328, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-7.7395, 37.3679, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glEnd();

	//boy neck
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(6.46189f, 38.4162, 0.0f);
	glVertex3f(-7.7395f, 37.3679f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glEnd();

	//T-Shirt
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.561, 0.298, 0.137);
	glVertex3f(-0.948761f, 8.13055, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(25.4536f, 16.1265, 0.0f);
	glVertex3f(21.2162f, 24.1124, 0.0f);
	glVertex3f(14.2082f, 29.3277, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(-14.2082f, 29.3277, 0.0f);
	glVertex3f(-21.2162f, 24.1124, 0.0f);
	glVertex3f(-25.4536f, 16.1265, 0.0f);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-19.6912f, -20.2176, 0.0f);
	glVertex3f(-11.0534f, -25.1069, 0.0f);
	glVertex3f(0.029106f, -27.2256, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glEnd();

	//Bottom right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 1.0);
	glVertex3f(22.1941f, -30.3222, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(-0.3f, -25.2256, 0.0f);
	glVertex3f(0.02911f, -41.8936, 0.0f);
	glVertex3f(14.0452f, -39.9378, 0.0f);
	glVertex3f(24.3128f, -35.2115, 0.0f);
	glVertex3f(31.4838f, -25.7588, 0.0f);
	glVertex3f(31.4838f, -11.4167, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glEnd();
	//Bottom left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 1.0);
	glVertex3f(-22.1941f, -30.3222, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glVertex3f(-9.31884f, -24.5958, 0.0f);
	glVertex3f(-0.029106f, -27.2256, 0.0f);
	glVertex3f(-0.02911f, -41.8936, 0.0f);
	glVertex3f(-14.0452f, -39.9378, 0.0f);
	glVertex3f(-24.3128f, -35.2115, 0.0f);
	glVertex3f(-31.4838f, -25.7588, 0.0f);
	glVertex3f(-31.4838f, -11.4167, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(27.4094f, -11.2538, 0.0f);
	glEnd();
	//left hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-27.4094f, -11.2538, 0.0f);
	glEnd();

}

void drawBoy4(void)
{
	glLoadIdentity();
	glTranslatef(-0.6f, -0.4f, -1.4f);
	glScalef(0.015f, 0.01f, 0.01f);
	glScalef(0.2f, 0.2f, 0.5f);

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.647, 0.341, 0.161);
	glVertex3f(-1.44927f, 56.22f, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(9.73336f, 42.6097, 0.0f);
	glVertex3f(11.1312f, 47.1527, 0.0f);
	glVertex3f(11.6554f, 50.4725, 0.0f);
	glVertex3f(8.50026f, 60.0826, 0.0f);
	glVertex3f(4.31677f, 63.4024, 0.0f);
	glVertex3f(-2.45873f, 64.1784, 0.0f);
	glVertex3f(-7.21531f, 62.3541, 0.0f);
	glVertex3f(-11.2341f, 59.9079, 0.0f);
	glVertex3f(-12.9814f, 55.8891, 0.0f);
	glVertex3f(-14.0297f, 52.3945, 0.0f);
	glVertex3f(-14.2045f, 47.5021, 0.0f);
	glVertex3f(-12.8066f, 43.8328, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-7.7395, 37.3679, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glEnd();

	//boy neck
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(6.46189f, 38.4162, 0.0f);
	glVertex3f(-7.7395f, 37.3679f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glEnd();

	//T-Shirt
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.843, 0., 0.004);
	glVertex3f(-0.948761f, 8.13055, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(25.4536f, 16.1265, 0.0f);
	glVertex3f(21.2162f, 24.1124, 0.0f);
	glVertex3f(14.2082f, 29.3277, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(-14.2082f, 29.3277, 0.0f);
	glVertex3f(-21.2162f, 24.1124, 0.0f);
	glVertex3f(-25.4536f, 16.1265, 0.0f);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-19.6912f, -20.2176, 0.0f);
	glVertex3f(-11.0534f, -25.1069, 0.0f);
	glVertex3f(0.029106f, -27.2256, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glEnd();

	//Bottom right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(22.1941f, -30.3222, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(-0.3f, -25.2256, 0.0f);
	glVertex3f(0.02911f, -41.8936, 0.0f);
	glVertex3f(14.0452f, -39.9378, 0.0f);
	glVertex3f(24.3128f, -35.2115, 0.0f);
	glVertex3f(31.4838f, -25.7588, 0.0f);
	glVertex3f(31.4838f, -11.4167, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glEnd();
	//Bottom left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-22.1941f, -30.3222, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glVertex3f(-9.31884f, -24.5958, 0.0f);
	glVertex3f(-0.029106f, -27.2256, 0.0f);
	glVertex3f(-0.02911f, -41.8936, 0.0f);
	glVertex3f(-14.0452f, -39.9378, 0.0f);
	glVertex3f(-24.3128f, -35.2115, 0.0f);
	glVertex3f(-31.4838f, -25.7588, 0.0f);
	glVertex3f(-31.4838f, -11.4167, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(27.4094f, -11.2538, 0.0f);
	glEnd();
	//left hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-27.4094f, -11.2538, 0.0f);
	glEnd();

}

void drawBoy5(void)
{
	glLoadIdentity();
	glTranslatef(-0.6f, -0.53f, -1.4f);
	glScalef(0.015f, 0.01f, 0.01f);
	glScalef(0.2f, 0.2f, 0.5f);

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.733, 0.725, 0.725);
	glVertex3f(-1.44927f, 56.22f, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(9.73336f, 42.6097, 0.0f);
	glVertex3f(11.1312f, 47.1527, 0.0f);
	glVertex3f(11.6554f, 50.4725, 0.0f);
	glVertex3f(8.50026f, 60.0826, 0.0f);
	glVertex3f(4.31677f, 63.4024, 0.0f);
	glVertex3f(-2.45873f, 64.1784, 0.0f);
	glVertex3f(-7.21531f, 62.3541, 0.0f);
	glVertex3f(-11.2341f, 59.9079, 0.0f);
	glVertex3f(-12.9814f, 55.8891, 0.0f);
	glVertex3f(-14.0297f, 52.3945, 0.0f);
	glVertex3f(-14.2045f, 47.5021, 0.0f);
	glVertex3f(-12.8066f, 43.8328, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-7.7395, 37.3679, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glEnd();

	//boy neck
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(6.46189f, 38.4162, 0.0f);
	glVertex3f(-7.7395f, 37.3679f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glEnd();

	//T-Shirt
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.843, 0.5, 0.014);
	glVertex3f(-0.948761f, 8.13055, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(25.4536f, 16.1265, 0.0f);
	glVertex3f(21.2162f, 24.1124, 0.0f);
	glVertex3f(14.2082f, 29.3277, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(-14.2082f, 29.3277, 0.0f);
	glVertex3f(-21.2162f, 24.1124, 0.0f);
	glVertex3f(-25.4536f, 16.1265, 0.0f);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-19.6912f, -20.2176, 0.0f);
	glVertex3f(-11.0534f, -25.1069, 0.0f);
	glVertex3f(0.029106f, -27.2256, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glEnd();

	//Bottom right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(22.1941f, -30.3222, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(-0.3f, -25.2256, 0.0f);
	glVertex3f(0.02911f, -41.8936, 0.0f);
	glVertex3f(14.0452f, -39.9378, 0.0f);
	glVertex3f(24.3128f, -35.2115, 0.0f);
	glVertex3f(31.4838f, -25.7588, 0.0f);
	glVertex3f(31.4838f, -11.4167, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glEnd();
	//Bottom left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-22.1941f, -30.3222, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glVertex3f(-9.31884f, -24.5958, 0.0f);
	glVertex3f(-0.029106f, -27.2256, 0.0f);
	glVertex3f(-0.02911f, -41.8936, 0.0f);
	glVertex3f(-14.0452f, -39.9378, 0.0f);
	glVertex3f(-24.3128f, -35.2115, 0.0f);
	glVertex3f(-31.4838f, -25.7588, 0.0f);
	glVertex3f(-31.4838f, -11.4167, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(27.4094f, -11.2538, 0.0f);
	glEnd();
	//left hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-27.4094f, -11.2538, 0.0f);
	glEnd();

}

void drawBoy6(void)
{
	glLoadIdentity();
	glTranslatef(-0.8f, -0.4f, -1.4f);
	glScalef(0.015f, 0.01f, 0.01f);
	glScalef(0.2f, 0.2f, 0.5f);

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.733, 0.725, 0.725);
	glVertex3f(-1.44927f, 56.22f, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(9.73336f, 42.6097, 0.0f);
	glVertex3f(11.1312f, 47.1527, 0.0f);
	glVertex3f(11.6554f, 50.4725, 0.0f);
	glVertex3f(8.50026f, 60.0826, 0.0f);
	glVertex3f(4.31677f, 63.4024, 0.0f);
	glVertex3f(-2.45873f, 64.1784, 0.0f);
	glVertex3f(-7.21531f, 62.3541, 0.0f);
	glVertex3f(-11.2341f, 59.9079, 0.0f);
	glVertex3f(-12.9814f, 55.8891, 0.0f);
	glVertex3f(-14.0297f, 52.3945, 0.0f);
	glVertex3f(-14.2045f, 47.5021, 0.0f);
	glVertex3f(-12.8066f, 43.8328, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-7.7395, 37.3679, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glEnd();

	//boy neck
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(6.46189f, 38.4162, 0.0f);
	glVertex3f(-7.7395f, 37.3679f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glEnd();

	//T-Shirt
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.678, 0.518, 0.088);
	glVertex3f(-0.948761f, 8.13055, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(25.4536f, 16.1265, 0.0f);
	glVertex3f(21.2162f, 24.1124, 0.0f);
	glVertex3f(14.2082f, 29.3277, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(-14.2082f, 29.3277, 0.0f);
	glVertex3f(-21.2162f, 24.1124, 0.0f);
	glVertex3f(-25.4536f, 16.1265, 0.0f);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-19.6912f, -20.2176, 0.0f);
	glVertex3f(-11.0534f, -25.1069, 0.0f);
	glVertex3f(0.029106f, -27.2256, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glEnd();

	//Bottom right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 1.0);
	glVertex3f(22.1941f, -30.3222, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(-0.3f, -25.2256, 0.0f);
	glVertex3f(0.02911f, -41.8936, 0.0f);
	glVertex3f(14.0452f, -39.9378, 0.0f);
	glVertex3f(24.3128f, -35.2115, 0.0f);
	glVertex3f(31.4838f, -25.7588, 0.0f);
	glVertex3f(31.4838f, -11.4167, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glEnd();
	//Bottom left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 1.0);
	glVertex3f(-22.1941f, -30.3222, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glVertex3f(-9.31884f, -24.5958, 0.0f);
	glVertex3f(-0.029106f, -27.2256, 0.0f);
	glVertex3f(-0.02911f, -41.8936, 0.0f);
	glVertex3f(-14.0452f, -39.9378, 0.0f);
	glVertex3f(-24.3128f, -35.2115, 0.0f);
	glVertex3f(-31.4838f, -25.7588, 0.0f);
	glVertex3f(-31.4838f, -11.4167, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(27.4094f, -11.2538, 0.0f);
	glEnd();
	//left hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-27.4094f, -11.2538, 0.0f);
	glEnd();

}

void drawBoy7(void)
{
	glLoadIdentity();
	glTranslatef(-0.8f, -0.53f, -1.4f);
	glScalef(0.015f, 0.01f, 0.01f);
	glScalef(0.2f, 0.2f, 0.5f);

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.733, 0.725, 0.725);
	glVertex3f(-1.44927f, 56.22f, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(9.73336f, 42.6097, 0.0f);
	glVertex3f(11.1312f, 47.1527, 0.0f);
	glVertex3f(11.6554f, 50.4725, 0.0f);
	glVertex3f(8.50026f, 60.0826, 0.0f);
	glVertex3f(4.31677f, 63.4024, 0.0f);
	glVertex3f(-2.45873f, 64.1784, 0.0f);
	glVertex3f(-7.21531f, 62.3541, 0.0f);
	glVertex3f(-11.2341f, 59.9079, 0.0f);
	glVertex3f(-12.9814f, 55.8891, 0.0f);
	glVertex3f(-14.0297f, 52.3945, 0.0f);
	glVertex3f(-14.2045f, 47.5021, 0.0f);
	glVertex3f(-12.8066f, 43.8328, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-7.7395, 37.3679, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glEnd();

	//boy neck
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(6.46189f, 38.4162, 0.0f);
	glVertex3f(-7.7395f, 37.3679f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glEnd();

	//T-Shirt
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 0.675);
	glVertex3f(-0.948761f, 8.13055, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(25.4536f, 16.1265, 0.0f);
	glVertex3f(21.2162f, 24.1124, 0.0f);
	glVertex3f(14.2082f, 29.3277, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(-14.2082f, 29.3277, 0.0f);
	glVertex3f(-21.2162f, 24.1124, 0.0f);
	glVertex3f(-25.4536f, 16.1265, 0.0f);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-19.6912f, -20.2176, 0.0f);
	glVertex3f(-11.0534f, -25.1069, 0.0f);
	glVertex3f(0.029106f, -27.2256, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glEnd();

	//Bottom right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(22.1941f, -30.3222, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(-0.3f, -25.2256, 0.0f);
	glVertex3f(0.02911f, -41.8936, 0.0f);
	glVertex3f(14.0452f, -39.9378, 0.0f);
	glVertex3f(24.3128f, -35.2115, 0.0f);
	glVertex3f(31.4838f, -25.7588, 0.0f);
	glVertex3f(31.4838f, -11.4167, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glEnd();
	//Bottom left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(-22.1941f, -30.3222, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glVertex3f(-9.31884f, -24.5958, 0.0f);
	glVertex3f(-0.029106f, -27.2256, 0.0f);
	glVertex3f(-0.02911f, -41.8936, 0.0f);
	glVertex3f(-14.0452f, -39.9378, 0.0f);
	glVertex3f(-24.3128f, -35.2115, 0.0f);
	glVertex3f(-31.4838f, -25.7588, 0.0f);
	glVertex3f(-31.4838f, -11.4167, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(27.4094f, -11.2538, 0.0f);
	glEnd();
	//left hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-27.4094f, -11.2538, 0.0f);
	glEnd();

}

void drawGirl(void)
{
	glLoadIdentity();
	glTranslatef(0.3f, -0.4f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.2f, 0.2f, 0.5f);

	//girl neck
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(6.46189f, 38.4162, 0.0f);
	glVertex3f(-7.7395f, 37.3679f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glEnd();

	//T-Shirt
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 0.1);
	glVertex3f(-0.948761f, 8.13055, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(25.4536f, 16.1265, 0.0f);
	glVertex3f(21.2162f, 24.1124, 0.0f);
	glVertex3f(14.2082f, 29.3277, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(-14.2082f, 29.3277, 0.0f);
	glVertex3f(-21.2162f, 24.1124, 0.0f);
	glVertex3f(-25.4536f, 16.1265, 0.0f);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-19.6912f, -20.2176, 0.0f);
	glVertex3f(-11.0534f, -25.1069, 0.0f);
	glVertex3f(0.029106f, -27.2256, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glEnd();

	//Bottom right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 1.0);
	glVertex3f(22.1941f, -30.3222, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(-0.3f, -27.2256, 0.0f);
	glVertex3f(0.02911f, -41.8936, 0.0f);
	glVertex3f(14.0452f, -39.9378, 0.0f);
	glVertex3f(24.3128f, -35.2115, 0.0f);
	glVertex3f(31.4838f, -25.7588, 0.0f);
	glVertex3f(31.4838f, -11.4167, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glEnd();
	//Bottom left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 1.0);
	glVertex3f(-22.1941f, -30.3222, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glVertex3f(-9.31884f, -24.5958, 0.0f);
	glVertex3f(-0.029106f, -27.2256, 0.0f);
	glVertex3f(-0.02911f, -41.8936, 0.0f);
	glVertex3f(-14.0452f, -39.9378, 0.0f);
	glVertex3f(-24.3128f, -35.2115, 0.0f);
	glVertex3f(-31.4838f, -25.7588, 0.0f);
	glVertex3f(-31.4838f, -11.4167, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(27.4094f, -11.2538, 0.0f);
	glEnd();
	//left hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-27.4094f, -11.2538, 0.0f);
	glEnd();

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(-1.44927f, 56.22f, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(9.73336f, 42.6097, 0.0f);
	glVertex3f(11.1312f, 47.1527, 0.0f);
	glVertex3f(11.6554f, 50.4725, 0.0f);
	glVertex3f(8.50026f, 60.0826, 0.0f);
	glVertex3f(4.31677f, 63.4024, 0.0f);
	glVertex3f(-2.45873f, 64.1784, 0.0f);
	glVertex3f(-7.21531f, 62.3541, 0.0f);
	glVertex3f(-11.2341f, 59.9079, 0.0f);
	glVertex3f(-12.9814f, 55.8891, 0.0f);
	glVertex3f(-14.0297f, 52.3945, 0.0f);
	glVertex3f(-14.2045f, 47.5021, 0.0f);
	glVertex3f(-12.8066f, 43.8328, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-7.7395, 37.3679, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-18.0322, 20.4497, 0.0f);
	glVertex3f(-4.79576, 17.3518, 0.0f);
	glVertex3f(6.75088, 17.9151, 0.0f);
	glVertex3f(12.665, 23.5476, 0.0f);
	glEnd();

}

void drawGirl1(void)
{
	glLoadIdentity();
	glTranslatef(0.3f, -0.53f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.3f, 0.2f, 0.5f);

	//girl neck
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(6.46189f, 38.4162, 0.0f);
	glVertex3f(-7.7395f, 37.3679f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glEnd();

	//T-Shirt
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 0.3, 0.675);
	glVertex3f(-0.948761f, 8.13055, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(25.4536f, 16.1265, 0.0f);
	glVertex3f(21.2162f, 24.1124, 0.0f);
	glVertex3f(14.2082f, 29.3277, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(-14.2082f, 29.3277, 0.0f);
	glVertex3f(-21.2162f, 24.1124, 0.0f);
	glVertex3f(-25.4536f, 16.1265, 0.0f);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-19.6912f, -20.2176, 0.0f);
	glVertex3f(-11.0534f, -25.1069, 0.0f);
	glVertex3f(0.029106f, -27.2256, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glEnd();

	//Bottom right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(22.1941f, -30.3222, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(-0.3f, -27.2256, 0.0f);
	glVertex3f(0.02911f, -41.8936, 0.0f);
	glVertex3f(14.0452f, -39.9378, 0.0f);
	glVertex3f(24.3128f, -35.2115, 0.0f);
	glVertex3f(31.4838f, -25.7588, 0.0f);
	glVertex3f(31.4838f, -11.4167, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glEnd();
	//Bottom left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0, 0);
	glVertex3f(-22.1941f, -30.3222, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glVertex3f(-9.31884f, -24.5958, 0.0f);
	glVertex3f(-0.029106f, -27.2256, 0.0f);
	glVertex3f(-0.02911f, -41.8936, 0.0f);
	glVertex3f(-14.0452f, -39.9378, 0.0f);
	glVertex3f(-24.3128f, -35.2115, 0.0f);
	glVertex3f(-31.4838f, -25.7588, 0.0f);
	glVertex3f(-31.4838f, -11.4167, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(27.4094f, -11.2538, 0.0f);
	glEnd();
	//left hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-27.4094f, -11.2538, 0.0f);
	glEnd();

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(-1.44927f, 56.22f, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(9.73336f, 42.6097, 0.0f);
	glVertex3f(11.1312f, 47.1527, 0.0f);
	glVertex3f(11.6554f, 50.4725, 0.0f);
	glVertex3f(8.50026f, 60.0826, 0.0f);
	glVertex3f(4.31677f, 63.4024, 0.0f);
	glVertex3f(-2.45873f, 64.1784, 0.0f);
	glVertex3f(-7.21531f, 62.3541, 0.0f);
	glVertex3f(-11.2341f, 59.9079, 0.0f);
	glVertex3f(-12.9814f, 55.8891, 0.0f);
	glVertex3f(-14.0297f, 52.3945, 0.0f);
	glVertex3f(-14.2045f, 47.5021, 0.0f);
	glVertex3f(-12.8066f, 43.8328, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-7.7395, 37.3679, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.3, 0.3);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-18.0322, 20.4497, 0.0f);
	glVertex3f(-4.79576, 17.3518, 0.0f);
	glVertex3f(6.75088, 17.9151, 0.0f);
	glVertex3f(12.665, 23.5476, 0.0f);
	glEnd();

}

void drawGirl2(void)
{
	glLoadIdentity();
	glTranslatef(0.5f, -0.4f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.2f, 0.2f, 0.5f);

	//girl neck
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(6.46189f, 38.4162, 0.0f);
	glVertex3f(-7.7395f, 37.3679f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glEnd();

	//T-Shirt
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.678, 0.518, 0.088);
	glVertex3f(-0.948761f, 8.13055, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(25.4536f, 16.1265, 0.0f);
	glVertex3f(21.2162f, 24.1124, 0.0f);
	glVertex3f(14.2082f, 29.3277, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(-14.2082f, 29.3277, 0.0f);
	glVertex3f(-21.2162f, 24.1124, 0.0f);
	glVertex3f(-25.4536f, 16.1265, 0.0f);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-19.6912f, -20.2176, 0.0f);
	glVertex3f(-11.0534f, -25.1069, 0.0f);
	glVertex3f(0.029106f, -27.2256, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glEnd();

	//Bottom right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 1.0);
	glVertex3f(22.1941f, -30.3222, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(-0.3f, -27.2256, 0.0f);
	glVertex3f(0.02911f, -41.8936, 0.0f);
	glVertex3f(14.0452f, -39.9378, 0.0f);
	glVertex3f(24.3128f, -35.2115, 0.0f);
	glVertex3f(31.4838f, -25.7588, 0.0f);
	glVertex3f(31.4838f, -11.4167, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glEnd();
	//Bottom left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 1.0);
	glVertex3f(-22.1941f, -30.3222, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glVertex3f(-9.31884f, -24.5958, 0.0f);
	glVertex3f(-0.029106f, -27.2256, 0.0f);
	glVertex3f(-0.02911f, -41.8936, 0.0f);
	glVertex3f(-14.0452f, -39.9378, 0.0f);
	glVertex3f(-24.3128f, -35.2115, 0.0f);
	glVertex3f(-31.4838f, -25.7588, 0.0f);
	glVertex3f(-31.4838f, -11.4167, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(27.4094f, -11.2538, 0.0f);
	glEnd();
	//left hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-27.4094f, -11.2538, 0.0f);
	glEnd();

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.733, 0.725, 0.725);
	glVertex3f(-1.44927f, 56.22f, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(9.73336f, 42.6097, 0.0f);
	glVertex3f(11.1312f, 47.1527, 0.0f);
	glVertex3f(11.6554f, 50.4725, 0.0f);
	glVertex3f(8.50026f, 60.0826, 0.0f);
	glVertex3f(4.31677f, 63.4024, 0.0f);
	glVertex3f(-2.45873f, 64.1784, 0.0f);
	glVertex3f(-7.21531f, 62.3541, 0.0f);
	glVertex3f(-11.2341f, 59.9079, 0.0f);
	glVertex3f(-12.9814f, 55.8891, 0.0f);
	glVertex3f(-14.0297f, 52.3945, 0.0f);
	glVertex3f(-14.2045f, 47.5021, 0.0f);
	glVertex3f(-12.8066f, 43.8328, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-7.7395, 37.3679, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.733, 0.725, 0.725);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-18.0322, 20.4497, 0.0f);
	glVertex3f(-4.79576, 17.3518, 0.0f);
	glVertex3f(6.75088, 17.9151, 0.0f);
	glVertex3f(12.665, 23.5476, 0.0f);
	glEnd();

}

void drawGirl3(void)
{
	glLoadIdentity();
	glTranslatef(0.5f, -0.53f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.3f, 0.2f, 0.5f);

	//girl neck
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(6.46189f, 38.4162, 0.0f);
	glVertex3f(-7.7395f, 37.3679f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glEnd();

	//T-Shirt
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 0.675);
	glVertex3f(-0.948761f, 8.13055, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(25.4536f, 16.1265, 0.0f);
	glVertex3f(21.2162f, 24.1124, 0.0f);
	glVertex3f(14.2082f, 29.3277, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(-14.2082f, 29.3277, 0.0f);
	glVertex3f(-21.2162f, 24.1124, 0.0f);
	glVertex3f(-25.4536f, 16.1265, 0.0f);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-19.6912f, -20.2176, 0.0f);
	glVertex3f(-11.0534f, -25.1069, 0.0f);
	glVertex3f(0.029106f, -27.2256, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glEnd();

	//Bottom right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 1.0);
	glVertex3f(22.1941f, -30.3222, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(-0.3f, -27.2256, 0.0f);
	glVertex3f(0.02911f, -41.8936, 0.0f);
	glVertex3f(14.0452f, -39.9378, 0.0f);
	glVertex3f(24.3128f, -35.2115, 0.0f);
	glVertex3f(31.4838f, -25.7588, 0.0f);
	glVertex3f(31.4838f, -11.4167, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glEnd();
	//Bottom left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 1.0);
	glVertex3f(-22.1941f, -30.3222, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glVertex3f(-9.31884f, -24.5958, 0.0f);
	glVertex3f(-0.029106f, -27.2256, 0.0f);
	glVertex3f(-0.02911f, -41.8936, 0.0f);
	glVertex3f(-14.0452f, -39.9378, 0.0f);
	glVertex3f(-24.3128f, -35.2115, 0.0f);
	glVertex3f(-31.4838f, -25.7588, 0.0f);
	glVertex3f(-31.4838f, -11.4167, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(27.4094f, -11.2538, 0.0f);
	glEnd();
	//left hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-27.4094f, -11.2538, 0.0f);
	glEnd();

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.2, 0.2, 0.0);
	glVertex3f(-1.44927f, 56.22f, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(9.73336f, 42.6097, 0.0f);
	glVertex3f(11.1312f, 47.1527, 0.0f);
	glVertex3f(11.6554f, 50.4725, 0.0f);
	glVertex3f(8.50026f, 60.0826, 0.0f);
	glVertex3f(4.31677f, 63.4024, 0.0f);
	glVertex3f(-2.45873f, 64.1784, 0.0f);
	glVertex3f(-7.21531f, 62.3541, 0.0f);
	glVertex3f(-11.2341f, 59.9079, 0.0f);
	glVertex3f(-12.9814f, 55.8891, 0.0f);
	glVertex3f(-14.0297f, 52.3945, 0.0f);
	glVertex3f(-14.2045f, 47.5021, 0.0f);
	glVertex3f(-12.8066f, 43.8328, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-7.7395, 37.3679, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.0);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-18.0322, 20.4497, 0.0f);
	glVertex3f(-4.79576, 17.3518, 0.0f);
	glVertex3f(6.75088, 17.9151, 0.0f);
	glVertex3f(12.665, 23.5476, 0.0f);
	glEnd();

}

void drawGirl4(void)
{
	glLoadIdentity();
	glTranslatef(0.65f, -0.4f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.2f, 0.2f, 0.5f);

	//girl neck
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(6.46189f, 38.4162, 0.0f);
	glVertex3f(-7.7395f, 37.3679f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glEnd();

	//T-Shirt
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.843, 0., 0.004);
	glVertex3f(-0.948761f, 8.13055, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(25.4536f, 16.1265, 0.0f);
	glVertex3f(21.2162f, 24.1124, 0.0f);
	glVertex3f(14.2082f, 29.3277, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(-14.2082f, 29.3277, 0.0f);
	glVertex3f(-21.2162f, 24.1124, 0.0f);
	glVertex3f(-25.4536f, 16.1265, 0.0f);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-19.6912f, -20.2176, 0.0f);
	glVertex3f(-11.0534f, -25.1069, 0.0f);
	glVertex3f(0.029106f, -27.2256, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glEnd();

	//Bottom right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(22.1941f, -30.3222, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(-0.3f, -27.2256, 0.0f);
	glVertex3f(0.02911f, -41.8936, 0.0f);
	glVertex3f(14.0452f, -39.9378, 0.0f);
	glVertex3f(24.3128f, -35.2115, 0.0f);
	glVertex3f(31.4838f, -25.7588, 0.0f);
	glVertex3f(31.4838f, -11.4167, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glEnd();
	//Bottom left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-22.1941f, -30.3222, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glVertex3f(-9.31884f, -24.5958, 0.0f);
	glVertex3f(-0.029106f, -27.2256, 0.0f);
	glVertex3f(-0.02911f, -41.8936, 0.0f);
	glVertex3f(-14.0452f, -39.9378, 0.0f);
	glVertex3f(-24.3128f, -35.2115, 0.0f);
	glVertex3f(-31.4838f, -25.7588, 0.0f);
	glVertex3f(-31.4838f, -11.4167, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(27.4094f, -11.2538, 0.0f);
	glEnd();
	//left hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-27.4094f, -11.2538, 0.0f);
	glEnd();

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.647, 0.341, 0.161);
	glVertex3f(-1.44927f, 56.22f, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(9.73336f, 42.6097, 0.0f);
	glVertex3f(11.1312f, 47.1527, 0.0f);
	glVertex3f(11.6554f, 50.4725, 0.0f);
	glVertex3f(8.50026f, 60.0826, 0.0f);
	glVertex3f(4.31677f, 63.4024, 0.0f);
	glVertex3f(-2.45873f, 64.1784, 0.0f);
	glVertex3f(-7.21531f, 62.3541, 0.0f);
	glVertex3f(-11.2341f, 59.9079, 0.0f);
	glVertex3f(-12.9814f, 55.8891, 0.0f);
	glVertex3f(-14.0297f, 52.3945, 0.0f);
	glVertex3f(-14.2045f, 47.5021, 0.0f);
	glVertex3f(-12.8066f, 43.8328, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-7.7395, 37.3679, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.647, 0.341, 0.161);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-18.0322, 20.4497, 0.0f);
	glVertex3f(-4.79576, 17.3518, 0.0f);
	glVertex3f(6.75088, 17.9151, 0.0f);
	glVertex3f(12.665, 23.5476, 0.0f);
	glEnd();

}

void drawGirl5(void)
{
	glLoadIdentity();
	glTranslatef(0.7f, -0.53f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.3f, 0.2f, 0.5f);

	//girl neck
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(6.46189f, 38.4162, 0.0f);
	glVertex3f(-7.7395f, 37.3679f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glEnd();

	//T-Shirt
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 0.675);
	glVertex3f(-0.948761f, 8.13055, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(25.4536f, 16.1265, 0.0f);
	glVertex3f(21.2162f, 24.1124, 0.0f);
	glVertex3f(14.2082f, 29.3277, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(-14.2082f, 29.3277, 0.0f);
	glVertex3f(-21.2162f, 24.1124, 0.0f);
	glVertex3f(-25.4536f, 16.1265, 0.0f);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-19.6912f, -20.2176, 0.0f);
	glVertex3f(-11.0534f, -25.1069, 0.0f);
	glVertex3f(0.029106f, -27.2256, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glEnd();

	//Bottom right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 1.0);
	glVertex3f(22.1941f, -30.3222, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(-0.3f, -27.2256, 0.0f);
	glVertex3f(0.02911f, -41.8936, 0.0f);
	glVertex3f(14.0452f, -39.9378, 0.0f);
	glVertex3f(24.3128f, -35.2115, 0.0f);
	glVertex3f(31.4838f, -25.7588, 0.0f);
	glVertex3f(31.4838f, -11.4167, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glEnd();
	//Bottom left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0, 1.859, 1.0);
	glVertex3f(-22.1941f, -30.3222, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glVertex3f(-9.31884f, -24.5958, 0.0f);
	glVertex3f(-0.029106f, -27.2256, 0.0f);
	glVertex3f(-0.02911f, -41.8936, 0.0f);
	glVertex3f(-14.0452f, -39.9378, 0.0f);
	glVertex3f(-24.3128f, -35.2115, 0.0f);
	glVertex3f(-31.4838f, -25.7588, 0.0f);
	glVertex3f(-31.4838f, -11.4167, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(27.4094f, -11.2538, 0.0f);
	glEnd();
	//left hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-27.4094f, -11.2538, 0.0f);
	glEnd();

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.208, 0.11, 0.122);
	glVertex3f(-1.44927f, 56.22f, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(9.73336f, 42.6097, 0.0f);
	glVertex3f(11.1312f, 47.1527, 0.0f);
	glVertex3f(11.6554f, 50.4725, 0.0f);
	glVertex3f(8.50026f, 60.0826, 0.0f);
	glVertex3f(4.31677f, 63.4024, 0.0f);
	glVertex3f(-2.45873f, 64.1784, 0.0f);
	glVertex3f(-7.21531f, 62.3541, 0.0f);
	glVertex3f(-11.2341f, 59.9079, 0.0f);
	glVertex3f(-12.9814f, 55.8891, 0.0f);
	glVertex3f(-14.0297f, 52.3945, 0.0f);
	glVertex3f(-14.2045f, 47.5021, 0.0f);
	glVertex3f(-12.8066f, 43.8328, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-7.7395, 37.3679, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.208, 0.11, 0.122);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-18.0322, 20.4497, 0.0f);
	glVertex3f(-4.79576, 17.3518, 0.0f);
	glVertex3f(6.75088, 17.9151, 0.0f);
	glVertex3f(12.665, 23.5476, 0.0f);
	glEnd();

}

void drawGirl6(void)
{
	glLoadIdentity();
	glTranslatef(0.82f, -0.4f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.2f, 0.2f, 0.5f);

	//girl neck
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(6.46189f, 38.4162, 0.0f);
	glVertex3f(-7.7395f, 37.3679f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glEnd();

	//T-Shirt
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.678, 0.518, 0.788);
	glVertex3f(-0.948761f, 8.13055, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(25.4536f, 16.1265, 0.0f);
	glVertex3f(21.2162f, 24.1124, 0.0f);
	glVertex3f(14.2082f, 29.3277, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(-14.2082f, 29.3277, 0.0f);
	glVertex3f(-21.2162f, 24.1124, 0.0f);
	glVertex3f(-25.4536f, 16.1265, 0.0f);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-19.6912f, -20.2176, 0.0f);
	glVertex3f(-11.0534f, -25.1069, 0.0f);
	glVertex3f(0.029106f, -27.2256, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glEnd();

	//Bottom right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(22.1941f, -30.3222, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(-0.3f, -27.2256, 0.0f);
	glVertex3f(0.02911f, -41.8936, 0.0f);
	glVertex3f(14.0452f, -39.9378, 0.0f);
	glVertex3f(24.3128f, -35.2115, 0.0f);
	glVertex3f(31.4838f, -25.7588, 0.0f);
	glVertex3f(31.4838f, -11.4167, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glEnd();
	//Bottom left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-22.1941f, -30.3222, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glVertex3f(-9.31884f, -24.5958, 0.0f);
	glVertex3f(-0.029106f, -27.2256, 0.0f);
	glVertex3f(-0.02911f, -41.8936, 0.0f);
	glVertex3f(-14.0452f, -39.9378, 0.0f);
	glVertex3f(-24.3128f, -35.2115, 0.0f);
	glVertex3f(-31.4838f, -25.7588, 0.0f);
	glVertex3f(-31.4838f, -11.4167, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(27.4094f, -11.2538, 0.0f);
	glEnd();
	//left hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-27.4094f, -11.2538, 0.0f);
	glEnd();

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.412, 0.239, 0.133);
	glVertex3f(-1.44927f, 56.22f, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(9.73336f, 42.6097, 0.0f);
	glVertex3f(11.1312f, 47.1527, 0.0f);
	glVertex3f(11.6554f, 50.4725, 0.0f);
	glVertex3f(8.50026f, 60.0826, 0.0f);
	glVertex3f(4.31677f, 63.4024, 0.0f);
	glVertex3f(-2.45873f, 64.1784, 0.0f);
	glVertex3f(-7.21531f, 62.3541, 0.0f);
	glVertex3f(-11.2341f, 59.9079, 0.0f);
	glVertex3f(-12.9814f, 55.8891, 0.0f);
	glVertex3f(-14.0297f, 52.3945, 0.0f);
	glVertex3f(-14.2045f, 47.5021, 0.0f);
	glVertex3f(-12.8066f, 43.8328, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-7.7395, 37.3679, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.412, 0.239, 0.133);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-18.0322, 20.4497, 0.0f);
	glVertex3f(-4.79576, 17.3518, 0.0f);
	glVertex3f(6.75088, 17.9151, 0.0f);
	glVertex3f(12.665, 23.5476, 0.0f);
	glEnd();

}

void drawGirl7(void)
{
	glLoadIdentity();
	glTranslatef(0.9f, -0.53f, -1.4f);
	glScalef(0.01f, 0.01f, 0.01f);
	glScalef(0.3f, 0.2f, 0.5f);

	//girl neck
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(6.46189f, 38.4162, 0.0f);
	glVertex3f(-7.7395f, 37.3679f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glEnd();

	//T-Shirt
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.165, 0.153, 0.3);
	glVertex3f(-0.948761f, 8.13055, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(25.4536f, 16.1265, 0.0f);
	glVertex3f(21.2162f, 24.1124, 0.0f);
	glVertex3f(14.2082f, 29.3277, 0.0f);
	glVertex3f(4.61964, 31.3921f, 0.0f);
	glVertex3f(-7.46787, 31.9353f, 0.0f);
	glVertex3f(-14.2082f, 29.3277, 0.0f);
	glVertex3f(-21.2162f, 24.1124, 0.0f);
	glVertex3f(-25.4536f, 16.1265, 0.0f);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-19.6912f, -20.2176, 0.0f);
	glVertex3f(-11.0534f, -25.1069, 0.0f);
	glVertex3f(0.029106f, -27.2256, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glEnd();

	//Bottom right
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0.5, 0);
	glVertex3f(22.1941f, -30.3222, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glVertex3f(9.31884f, -25.5958, 0.0f);
	glVertex3f(-0.3f, -27.2256, 0.0f);
	glVertex3f(0.02911f, -41.8936, 0.0f);
	glVertex3f(14.0452f, -39.9378, 0.0f);
	glVertex3f(24.3128f, -35.2115, 0.0f);
	glVertex3f(31.4838f, -25.7588, 0.0f);
	glVertex3f(31.4838f, -11.4167, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(17.4677f, -20.0546, 0.0f);
	glEnd();
	//Bottom left
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0, 0.5, 0);
	glVertex3f(-22.1941f, -30.3222, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glVertex3f(-9.31884f, -24.5958, 0.0f);
	glVertex3f(-0.029106f, -27.2256, 0.0f);
	glVertex3f(-0.02911f, -41.8936, 0.0f);
	glVertex3f(-14.0452f, -39.9378, 0.0f);
	glVertex3f(-24.3128f, -35.2115, 0.0f);
	glVertex3f(-31.4838f, -25.7588, 0.0f);
	glVertex3f(-31.4838f, -11.4167, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-17.4677f, -20.0546, 0.0f);
	glEnd();

	//right hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(27.2464f, 6.18482, 0.0f);
	glVertex3f(18.6086f, 4.71802, 0.0f);
	glVertex3f(17.2826f, -11.7427, 0.0f);
	glVertex3f(27.4094f, -11.2538, 0.0f);
	glEnd();
	//left hand
	glBegin(GL_QUADS);
	glColor3f(1., 0.859, 0.675);
	glVertex3f(-27.2464f, 6.18482, 0.0f);
	glVertex3f(-18.6086f, 4.71802, 0.0f);
	glVertex3f(-17.2826f, -11.7427, 0.0f);
	glVertex3f(-27.4094f, -11.2538, 0.0f);
	glEnd();

	//Hairs
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.208, 0.11, 0.122);
	glVertex3f(-1.44927f, 56.22f, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(9.73336f, 42.6097, 0.0f);
	glVertex3f(11.1312f, 47.1527, 0.0f);
	glVertex3f(11.6554f, 50.4725, 0.0f);
	glVertex3f(8.50026f, 60.0826, 0.0f);
	glVertex3f(4.31677f, 63.4024, 0.0f);
	glVertex3f(-2.45873f, 64.1784, 0.0f);
	glVertex3f(-7.21531f, 62.3541, 0.0f);
	glVertex3f(-11.2341f, 59.9079, 0.0f);
	glVertex3f(-12.9814f, 55.8891, 0.0f);
	glVertex3f(-14.0297f, 52.3945, 0.0f);
	glVertex3f(-14.2045f, 47.5021, 0.0f);
	glVertex3f(-12.8066f, 43.8328, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-7.7395, 37.3679, 0.0f);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.208, 0.11, 0.122);
	glVertex3f(7.46189f, 38.4162, 0.0f);
	glVertex3f(-10.7099, 40.1635, 0.0f);
	glVertex3f(-18.0322, 20.4497, 0.0f);
	glVertex3f(-4.79576, 17.3518, 0.0f);
	glVertex3f(6.75088, 17.9151, 0.0f);
	glVertex3f(12.665, 23.5476, 0.0f);
	glEnd();

}

void SirBackView001(void)
{
	glTranslatef(-0.3f, -0.2f, -3.0f);
	glScalef(0.007f, 0.007f, 0.0f);
	glLineWidth(1);

	//Right Ear
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.45f, 0.45f);
	glVertex3f(-12.6f, 24.2f, 0.0f);
	glVertex3f(-13.2f, 22.8f, 0.0f);
	glVertex3f(-13.5f, 20.9f, 0.0f);
	glVertex3f(-13.2f, 19.2f, 0.0f);
	glVertex3f(-12.9f, 17.2f, 0.0f);
	glVertex3f(-11.8f, 17.6f, 0.0f);
	glVertex3f(-11.5f, 20.4f, 0.0f);
	glVertex3f(-11.4f, 22.2f, 0.0f);
	glVertex3f(-11.5f, 23.8f, 0.0f);
	//glVertex3f(f, f, 0.0f);
	glEnd();

	//Right Ear dot
	glEnable(GL_POINT_SMOOTH);
	glPointSize(3);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-12.3f, 20.6f, 0.0f);
	glEnd();
	glDisable(GL_POINT_SMOOTH);


	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(-13.5f, 14.0f, 0.0f);
	glVertex3f(-11.8f, 17.6f, 0.0f);
	glVertex3f(-12.9f, 17.2f, 0.0f);
	glVertex3f(-13.2f, 19.2f, 0.0f);
	glVertex3f(-15.0f, 18.3f, 0.0f);
	glVertex3f(-16.7f, 18.2f, 0.0f);
	glVertex3f(-18.7f, 18.1f, 0.0f);
	glVertex3f(-20.1f, 17.3f, 0.0f);
	//glVertex3f(-f, f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(-23.6f, 15.0f, 0.0f);
	glVertex3f(-20.0f, 16.3f, 0.0f);
	glVertex3f(-21.3f, 18.6f, 0.0f);
	glVertex3f(-24.2f, 19.3f, 0.0f);
	glVertex3f(-24.0f, 17.9f, 0.0f);
	//glVertex3f(-f, f, 0.0f);
	glEnd();

	//Left Ear
	glBegin(GL_POLYGON);
	glColor3f(0.8f, 0.45f, 0.45f);
	glVertex3f(-25.4f, 22.5f, 0.0f);
	glVertex3f(-25.1f, 21.5f, 0.0f);
	glVertex3f(-24.7f, 20.1f, 0.0f);
	glVertex3f(-24.5f, 18.9f, 0.0f);
	glVertex3f(-25.3f, 19.3f, 0.0f);
	glVertex3f(-25.7f, 20.4f, 0.0f);
	glVertex3f(-26.1f, 21.6f, 0.0f);
	glVertex3f(-26.3f, 23.4f, 0.0f);
	//glVertex3f(-f, f, 0.0f);
	glEnd();


	//Head Heir UPside
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(-18.5f, 30.3f, 0.0f);
	glVertex3f(-12.6f, 24.2f, 0.0f);
	glVertex3f(-11.5f, 23.8f, 0.0f);
	glVertex3f(-11.0f, 25.4f, 0.0f);
	glVertex3f(-11.1f, 27.8f, 0.0f);
	glVertex3f(-11.9f, 29.5f, 0.0f);
	glVertex3f(-13.9f, 30.8f, 0.0f);
	glVertex3f(-14.4f, 32.0f, 0.0f);
	glVertex3f(-16.4f, 32.9f, 0.0f);
	glVertex3f(-18.6f, 33.2f, 0.0f);
	glVertex3f(-20.6f, 33.2f, 0.0f);
	glVertex3f(-22.7f, 32.6f, 0.0f);
	glVertex3f(-24.1f, 31.7f, 0.0f);
	glVertex3f(-25.2f, 30.3f, 0.0f);
	glVertex3f(-25.8f, 28.7f, 0.0f);
	glVertex3f(-26.0f, 27.0f, 0.0f);
	glVertex3f(-25.6f, 25.6f, 0.0f);
	glVertex3f(-25.1f, 24.7f, 0.0f);
	glVertex3f(-25.4f, 23.5f, 0.0f);
	glVertex3f(-12.6f, 24.2f, 0.0f);
	glEnd();

	//Head Heir DOWNside
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(-19.6f, 19.5f, 0.0f);
	glVertex3f(-12.6f, 24.2f, 0.0f);
	glVertex3f(-25.4f, 23.5f, 0.0f);
	glVertex3f(-25.4f, 22.5f, 0.0f);
	glVertex3f(-25.1f, 21.5f, 0.0f);
	glVertex3f(-24.7f, 20.1f, 0.0f);
	glVertex3f(-24.5f, 18.9f, 0.0f);
	glVertex3f(-23.6f, 18.5f, 0.0f);
	glVertex3f(-22.4f, 18.2f, 0.0f);
	glVertex3f(-21.3f, 18.3f, 0.0f);
	glVertex3f(-20.0f, 17.4f, 0.0f);
	glVertex3f(-18.7f, 18.1f, 0.0f);
	glVertex3f(-16.7f, 18.2f, 0.0f);
	glVertex3f(-15.02f, 18.3f, 0.0f);
	glVertex3f(-13.2f, 19.2f, 0.0f);
	glVertex3f(-13.5f, 20.9f, 0.0f);
	glVertex3f(-13.2f, 22.8f, 0.0f);
	glVertex3f(-12.6f, 24.2f, 0.0f);
	glEnd();


	//Right Elbow
	//glTranslatef(14.5f, -10.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(14.5f, -10.0f, 0.0f);
	glVertex3f(6.5f, -11.0f, 0.0f);
	glVertex3f(14.5f, -14.0f, 0.0f);
	glVertex3f(18.0f, -10.0f, 0.0f);
	glVertex3f(20.0f, 13.5f, 0.0f);
	glVertex3f(19.0f, 17.0f, 0.0f);
	glVertex3f(15.0f, 17.0f, 0.0f);
	glVertex3f(11.7f, 4.0f, 0.0f);
	glVertex3f(11.5f, -3.5f, 0.0f);
	glVertex3f(6.5f, -11.0f, 0.0f);
	glEnd();

	//Right Palm
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(15.0f, 16.8f, 0.0f);
	glVertex3f(19.0f, 17.2f, 0.0f);
	glVertex3f(17.5f, 20.0f, 0.0f);
	glVertex3f(22.5f, 22.6f, 0.0f);
	glVertex3f(17.2f, 23.3f, 0.0f);
	glVertex3f(18.6f, 26.4f, 0.0f);
	glVertex3f(14.7f, 22.8f, 0.0f);
	glVertex3f(13.1f, 23.6f, 0.0f);
	glEnd();

	//Right Thumb
	glBegin(GL_QUAD_STRIP);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(15.0f, 16.8f, 0.0f);
	glVertex3f(15.6f, 18.2f, 0.0f);
	glVertex3f(13.1f, 18.2f, 0.0f);
	glVertex3f(14.7f, 19.5f, 0.0f);
	glVertex3f(13.7f, 20.7f, 0.0f);
	glVertex3f(15.1f, 21.1f, 0.0f);
	glVertex3f(13.0f, 22.0f, 0.0f);
	glEnd();


	//Pen
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(24.1f, 18.0f, 0.0f);
	glVertex3f(23.9f, 19.6f, 0.0f);
	glVertex3f(13.1f, 23.6f, 0.0f);
	glVertex3f(11.8f, 23.0f, 0.0f);
	glVertex3f(13.0f, 22.0f, 0.0f);
	glEnd();


	//Pant Drawing Right
	glLoadIdentity();
	glTranslatef(-0.3f, -0.2f, -3.0f);
	glScalef(0.007f, 0.007f, 0.0f);

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(-6.0f, -30.0f, 0.0f);
	glVertex3f(-20.0f, -28.0f, 0.0f);
	glVertex3f(-4.0f, -37.0f, 0.0f);
	glVertex3f(-21.0f, -53.0f, 0.0f);
	glVertex3f(-5.0f, -49.0f, 0.0f);
	glVertex3f(-20.0f, -67.0f, 0.0f);
	glVertex3f(-5.0f, -66.0f, 0.0f);
	glVertex3f(-19.0f, -76.0f, 0.0f);
	glVertex3f(-3.0f, -96.0f, 0.0f);
	glVertex3f(-16.0f, -96.0f, 0.0f);
	glEnd();

	//Pant Drawing Left
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex3f(-20.0f, -28.0f, 0.0f);
	glVertex3f(-36.0f, -25.0f, 0.0f);
	glVertex3f(-20.0f, -31.0f, 0.0f);
	glVertex3f(-37.0f, -27.0f, 0.0f);
	glVertex3f(-20.0f, -40.0f, 0.0f);
	glVertex3f(-36.0f, -34.0f, 0.0f);
	glVertex3f(-21.0f, -53.0f, 0.0f);
	glVertex3f(-38.0f, -46.0f, 0.0f);
	glVertex3f(-23.0f, -70.0f, 0.0f);
	glVertex3f(-37.0f, -65.0f, 0.0f);
	glVertex3f(-27.0f, -85.0f, 0.0f);
	glVertex3f(-39.0f, -83.0f, 0.0f);
	glVertex3f(-28.0f, -96.0f, 0.0f);
	glVertex3f(-40.0f, -96.0f, 0.0f);
	glEnd();

	//Shirt Base
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-20.0f, 10.0f, 0.0f);
	glVertex3f(-6.0f, -30.0f, 0.0f);
	glVertex3f(-6.0f, -21.0f, 0.0f);
	glVertex3f(-1.0f, -10.0f, 0.0f);
	glVertex3f(2.0f, -12.0f, 0.0f);
	glVertex3f(10.0f, -12.0f, 0.0f);
	glVertex3f(14.0f, -10.0f, 0.0f);
	glVertex3f(16.0f, -7.0f, 0.0f);
	glVertex3f(2.0f, 5.0f, 0.0f);
	glVertex3f(1.0f, 7.0f, 0.0f);
	glVertex3f(-12.0f, 12.0f, 0.0f);
	glVertex3f(-13.0f, 14.0f, 0.0f);
	glVertex3f(-19.0f, 17.0f, 0.0f);
	glVertex3f(-23.0f, 16.0f, 0.0f);
	glVertex3f(-25.0f, 15.0f, 0.0f);
	glVertex3f(-26.0f, 13.0f, 0.0f);
	glVertex3f(-38.0f, 11.0f, 0.0f);
	//glVertex3f(-39.0f, 9.0f, 0.0f);
	//glVertex3f(-54.0f, 0.0f, 0.0f);
	//glVertex3f(-49.0f, -6.0f, 0.0f);
	//glVertex3f(-46.0f, -6.0f, 0.0f);
	glVertex3f(-38.0f, -4.0f, 0.0f);
	glVertex3f(-38.0f, -11.0f, 0.0f);
	glVertex3f(-38.0f, -13.0f, 0.0f);
	glVertex3f(-36.0f, -25.0f, 0.0f);
	glVertex3f(-32.0f, -27.0f, 0.0f);
	glVertex3f(-29.0f, -28.0f, 0.0f);
	glVertex3f(-25.0f, -30.0f, 0.0f);
	glVertex3f(-20.0f, -31.0f, 0.0f);
	glVertex3f(-15.0f, -32.0f, 0.0f);
	glVertex3f(-10.0f, -31.0f, 0.0f);
	glVertex3f(-6.0f, -30.0f, 0.0f);
	glEnd();

	glTranslatef(-37.0f, 4.0f, 0.0f);
	//Left Arm Shoulder
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(8.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 7.0f, 0.0f);
	glVertex3f(-16.0f, -3.0f, 0.0f);
	glVertex3f(-10.0f, -8.0f, 0.0f);
	glVertex3f(-8.0f, -8.0f, 0.0f);
	glVertex3f(0.0f, -7.0f, 0.0f);
	glVertex3f(8.0f, 0.0f, 0.0f);
	glEnd();

	//Left Arm Elbow
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(-10.0f, -13.0f, 0.0f);
	glVertex3f(-12.0f, -15.0f, 0.0f);
	glVertex3f(-1.0f, -18.0f, 0.0f);
	glVertex3f(0.0f, -15.0f, 0.0f);
	glVertex3f(0.0f, -13.0f, 0.0f);
	glVertex3f(-5.0f, -11.0f, 0.0f);
	glVertex3f(-8.0f, -8.0f, 0.0f);
	glVertex3f(-10.0f, -8.0f, 0.0f);
	glVertex3f(-16.0f, -3.0f, 0.0f);
	glVertex3f(-18.0f, -5.0f, 0.0f);
	glVertex3f(-19.0f, -7.0f, 0.0f);
	glVertex3f(-20.0f, -9.0f, 0.0f);
	glVertex3f(-12.0f, -15.0f, 0.0f);
	glEnd();

	//Left Arm Hand
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.8f, 0.5f, 0.5f);
	glVertex3f(0.2f, -14.0f, 0.0f);
	glVertex3f(-1.2f, -19.0f, 0.0f);
	glVertex3f(2.0f, -26.0f, 0.0f);
	glVertex3f(-0.5f, -24.5f, 0.0f);
	glVertex3f(0.0f, -28.0f, 0.0f);
	glVertex3f(-3.0f, -26.0f, 0.0f);
	glVertex3f(-3.5f, -28.0f, 0.0f);
	glEnd();

	//Shirt BAse
	glTranslatef(37.0f, -4.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(0.5f, 0.2f, 0.2f);
	glVertex3f(-5.0f, -19.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-38.0f, -4.0f, 0.0f);
	glColor3f(0.5f, 0.2f, 0.2f);
	glVertex3f(-6.0f, -21.0f, 0.0f);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.5f, 0.2f, 0.2f);
	glVertex3f(-39.0f, 9.0f, 0.0f);
	glVertex3f(2.0f, 4.0f, 0.0f);
	glVertex3f(-1.0f, -10.0f, 0.0f);
	glVertex3f(1.0f, 7.0f, 0.0f);
	glVertex3f(-38.0f, -4.0f, 0.0f);
	glVertex3f(-38.0f, 11.0f, 0.0f);
	glVertex3f(-26.0f, 13.0f, 0.0f);
	glVertex3f(-19.0f, 14.0f, 0.0f);
	glVertex3f(-19.0f, 14.0f, 0.0f);
	glVertex3f(-12.0f, 12.0f, 0.0f);
	//glVertex3f(f, f, 0.0f);
	glEnd();
}

void watch(void)
{
	void DrawCircle(GLenum, struct Circle);

	glLoadIdentity();
	glTranslatef(0.0f, 0.5f, -3.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	//glScalef(0.01f, 0.01f, 0.01f);

		//Outer Part
	struct Circle watch1;
	watch1.size.point_size = 1;
	watch1.center.xCoordinate = 0.0f;
	watch1.center.yCoordinate = 0.0f;
	watch1.radious.xAxis = 1.1f;
	watch1.radious.yAxis = 1.1f;
	watch1.color.r = 1.0f;// 0.463;
	watch1.color.g = 1.0f;// 0.459;
	watch1.color.b = 1.0f;// 0.463;
	watch1.angle.from = 0;
	watch1.angle.to = 361;
	DrawCircle(GL_TRIANGLE_FAN, watch1);

	//Inner Part
	struct Circle watch;
	watch.size.point_size = 1;
	watch.center.xCoordinate = 0.0f;
	watch.center.yCoordinate = 0.0f;
	watch.radious.xAxis = 1.0f;
	watch.radious.yAxis = 1.0f;
	watch.color.r = 0.31;
	watch.color.g = 0.275;
	watch.color.b = 0.275;
	watch.angle.from = 0;
	watch.angle.to = 361;
	DrawCircle(GL_TRIANGLE_FAN, watch);



	//60 Lines

	for (int i = 0; i <= 360; i += 6)
	{
		float angle = i * (3.1436f / 180);
		float x = 0.92f * cos(angle);
		float y = 0.92f * sin(angle);

		if (i % 30 == 0)
		{
			glPointSize(3);
		}
		else
		{
			glPointSize(1);
		}
		glEnable(GL_POINT_SMOOTH);
		glBegin(GL_POINTS);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(x, y, 0.0f);
		glEnd();
		glDisable(GL_POINT_SMOOTH);
	}

	//Kate
	glLoadIdentity();
	glTranslatef(0.0f, 0.5f, -3.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-hour, 0.0f, 0.0f, 1.0f);

	//Hour Hand
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.075f, 0.05f, 0.0f);
	glVertex3f(0.075f, 0.05f, 0.0f);
	glVertex3f(0.075f, -0.05f, 0.0f);
	glVertex3f(-0.075f, -0.05f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.075f, 0.03f, 0.0f);
	glVertex3f(0.5f, 0.03f, 0.0f);
	glVertex3f(0.5f, -0.03f, 0.0f);
	glVertex3f(0.075f, -0.03f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5f, 0.03f, 0.0f);
	glVertex3f(0.6f, 0.0f, 0.0f);
	glVertex3f(0.5f, -0.03f, 0.0f);
	glEnd();

	//Minut HAnd
	glLoadIdentity();
	glTranslatef(0.0f, 0.5f, -3.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-minut, 0.0f, 0.0f, 1.0f);

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.085f, 0.03f, 0.0f);
	glVertex3f(0.085f, 0.03f, 0.0f);
	glVertex3f(0.085f, -0.03f, 0.0f);
	glVertex3f(-0.085f, -0.03f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.085f, 0.02f, 0.0f);
	glVertex3f(0.6f, 0.02f, 0.0f);
	glVertex3f(0.6f, -0.02f, 0.0f);
	glVertex3f(0.085f, -0.02f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.6f, 0.02f, 0.0f);
	glVertex3f(0.7f, 0.0f, 0.0f);
	glVertex3f(0.6f, -0.02f, 0.0f);
	glEnd();


	//Second Hand
	glLoadIdentity();
	glTranslatef(0.0f, 0.5f, -3.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-second, 0.0f, 0.0f, 1.0f);

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.095f, 0.02f, 0.0f);
	glVertex3f(0.095f, 0.02f, 0.0f);
	glVertex3f(0.095f, -0.02f, 0.0f);
	glVertex3f(-0.095f, -0.02f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.095f, 0.01f, 0.0f);
	glVertex3f(0.8f, 0.01f, 0.0f);
	glVertex3f(0.8f, -0.01f, 0.0f);
	glVertex3f(0.095f, -0.01f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.8f, 0.01f, 0.0f);
	glVertex3f(0.9f, 0.0f, 0.0f);
	glVertex3f(0.8f, -0.01f, 0.0f);
	glEnd();

	//Inner dot
	//glEnable(GL_POINT_SMOOTH);
	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glEnd();
	//glDisable(GL_POINT_SMOOTH);

}

void ceilingFan(void)
{
	glLoadIdentity();
	glTranslatef(0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glColor3f(0.322, 0.09, 0.1061);
	gluCylinder(quadric, 0.06, 0.06, 1.0, 50, 50);

	glLoadIdentity();
	glTranslatef(0.6f, 0.5f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glColor3f(0.333, 0.341, 0.357);
	gluCylinder(quadric, 0.0, 0.2, 0.5, 50, 50);

	glLoadIdentity();
	glTranslatef(0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(rotateCeilingFan, 0.0f, 1.0f, 0.0f);
	glScalef(2.5f, 1.0f, 2.5f);
	glColor3f(0.5f, 0.0f, 0.0f);
	gluSphere(quadric, 0.2, 50.0f, 50.0f);


	glLoadIdentity();
	glTranslatef(0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-rotateCeilingFan, 0.0f, 1.0f, 0.0f);
	//Fan 1
	//Cube
	glBegin(GL_QUADS);
	//Front face
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	//Right face
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	//Back face
	//glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Left Face
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Top Face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	//Bottom Face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-90.0f - rotateCeilingFan, 0.0f, 1.0f, 0.0f);
	//Fan 2
	//Cube
	glBegin(GL_QUADS);
	//Front face
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	//Right face
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	//Back face
	//glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Left Face
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Top Face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	//Bottom Face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-180.0f - rotateCeilingFan, 0.0f, 1.0f, 0.0f);
	//Fan 3
	//Cube
	glBegin(GL_QUADS);
	//Front face
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	//Right face
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	//Back face
	//glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Left Face
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Top Face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	//Bottom Face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-270.0f - rotateCeilingFan, 0.0f, 1.0f, 0.0f);
	//Fan 4
	//Cube
	glBegin(GL_QUADS);
	//Front face
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	//Right face
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	//Back face
	//glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Left Face
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Top Face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	//Bottom Face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glEnd();


	// Fan 2----------------------------------------------------------
	glLoadIdentity();
	glTranslatef(-0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glColor3f(0.322, 0.09, 0.1061);
	gluCylinder(quadric, 0.06, 0.06, 1.0, 50, 50);

	glLoadIdentity();
	glTranslatef(-0.6f, 0.5f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	glColor3f(0.333, 0.341, 0.357);
	gluCylinder(quadric, 0.0, 0.2, 0.5, 50, 50);

	glLoadIdentity();
	glTranslatef(-0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(rotateCeilingFan, 0.0f, 1.0f, 0.0f);
	glScalef(2.5f, 1.0f, 2.5f);
	glColor3f(0.5f, 0.0f, 0.0f);
	gluSphere(quadric, 0.2, 50.0f, 50.0f);


	glLoadIdentity();
	glTranslatef(-0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-rotateCeilingFan - 45.0f, 0.0f, 1.0f, 0.0f);
	//Fan 1
	//Cube
	glBegin(GL_QUADS);
	//Front face
	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	//Right face
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	//Back face
	//glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Left Face
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Top Face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	//Bottom Face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-90.0f - rotateCeilingFan - 45.0f, 0.0f, 1.0f, 0.0f);
	//Fan 2
	//Cube
	glBegin(GL_QUADS);
	//Front face
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	//Right face
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	//Back face
	//glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Left Face
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Top Face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	//Bottom Face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-180.0f - rotateCeilingFan - 45.0f, 0.0f, 1.0f, 0.0f);
	//Fan 3
	//Cube
	glBegin(GL_QUADS);
	//Front face
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	//Right face
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	//Back face
	//glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Left Face
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Top Face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	//Bottom Face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glEnd();

	glLoadIdentity();
	glTranslatef(-0.6f, 0.4f, -2.0f);
	glScalef(0.17f, 0.17f, 0.17f);
	glRotatef(-270.0f - rotateCeilingFan - 45.0f, 0.0f, 1.0f, 0.0f);
	//Fan 4
	//Cube
	glBegin(GL_QUADS);
	//Front face
	//glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	//Right face
	//glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	//Back face
	//glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Left Face
	//glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	//Top Face
	//glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.8f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, -0.2f);
	glVertex3f(0.0f, 0.04f, 0.2f);
	glVertex3f(1.8f, 0.04f, 0.2f);
	//Bottom Face
	//glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.8f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, -0.2f);
	glVertex3f(0.0f, -0.04f, 0.2f);
	glVertex3f(1.8f, -0.04f, 0.2f);
	glEnd();
}

void vb_Factory(void)
{

	// Factory 1
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, vb_z_tranlsate);
	glScalef(0.02f, 0.02f, 0.02f);

	glBegin(GL_QUADS);
	glColor3f(0.61f, 0.69f, 0.807f);
	glVertex3f(200.0f, 100.0f, 0.0f);
	glVertex3f(-200.0f, 100.0f, 0.0f);
	glVertex3f(-200.0f, -100.0f, 0.0f);
	glVertex3f(200.0f, -100.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.905f, 0.941f, 0.89f);
	glVertex3f(20.7251f, 27.48f, 0.0f);
	glVertex3f(51.8002f, 24.2f, 0.0f);
	glVertex3f(64.8985f, 17.56f, 0.0f);
	glVertex3f(-5.22f, 25.309f, 0.0f);
	glEnd();

	//quad right 
	glBegin(GL_QUADS);
	glColor3f(0.713f, 0.733f, 0.690f);
	glVertex3f(1.50583f, 24.2888f, 0.0f);
	glVertex3f(56.70f, 18.808f, 0.0f);
	glVertex3f(46.79f, -34.394f, 0.0f);
	glVertex3f(0.85255f, -22.31f, 0.0f);
	glEnd();

	//dark grey part
	glBegin(GL_QUADS);
	glColor3f(0.219f, 0.227f, 0.213f);
	glVertex3f(2.551f, 18.818f, 0.0f);
	glVertex3f(54.27f, 16.749f, 0.0f);
	glVertex3f(48.82f, -15.3f, 0.0f);
	glVertex3f(2.163f, -7.1416f, 0.0f);
	glEnd();


	//faint grey
	glBegin(GL_QUADS);
	glColor3f(0.513f, 0.533f, 0.533f);
	glVertex3f(48.827f, -16.232f, 0.0f);
	glVertex3f(2.099f, -7.5755f, 0.0f);
	glVertex3f(2.0260f, -22.562f, 0.0f);
	glVertex3f(45.60f, -33.91f, 0.0f);
	glEnd();

	//glLineWidth(2.0);
	//glBegin(GL_LINE_STRIP);
	//glColor3f(0.905f, 0.941f, 0.89f);
	//glVertex3f(55.0f, 16.59f, 0.0f);
	//glVertex3f(54.48f, 14.017f, 0.0f);
	//glVertex3f(50.8f, 14.172f, 0.0f);
	//glVertex3f(51.34f, 16.95f, 0.0f);
	//glVertex3f(55.0f, 16.59f, 0.0f);
	//glEnd();
	//

	//white base
	glBegin(GL_QUADS);
	glColor3f(0.905f, 0.941f, 0.89f);
	glVertex3f(-53.699f, 4.4482f, 0.0f);
	glVertex3f(1.788f, -4.984f, 0.0f);
	glVertex3f(1.788f, 5.488f, 0.0f);
	glVertex3f(-34.4f, 10.91f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.894f, 0.929f, 0.87f);
	glVertex3f(1.788f, 5.488f, 0.0f);
	glVertex3f(-34.42f, 10.91f, 0.0f);
	glVertex3f(-18.050f, 13.67f, 0.0f);
	glVertex3f(1.8514f, 11.915f, 0.0f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.713f, 0.733f, 0.690f);
	glVertex3f(1.46f, -5.2131f, 0.0f);
	glVertex3f(-53.99f, 4.2173f, 0.0f);
	glVertex3f(-53.52f, 2.825f, 0.0f);
	glVertex3f(1.26f, -7.44f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.513f, 0.533f, 0.533f);
	glVertex3f(-53.52f, 2.85f, 0.0f);
	glVertex3f(-51.23f, -8.549f, 0.0f);
	glVertex3f(1.088f, -22.34f, 0.0f);
	glVertex3f(1.265f, -7.4440f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.513f, 0.533f, 0.533f);
	glVertex3f(-53.52f, 2.85f, 0.0f);
	glVertex3f(-62.07f, 4.379f, 0.0f);
	glVertex3f(-60.42f, -5.690f, 0.0f);
	glVertex3f(-51.23f, -8.54f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.219f, 0.227f, 0.213f);
	glVertex3f(-54.031f, 11.389f, 0.0f);
	glVertex3f(-63.30f, 12.605f, 0.0f);
	glVertex3f(-62.075f, 4.379f, 0.0f);
	glVertex3f(-53.52f, 2.825f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.219f, 0.227f, 0.213f);
	glVertex3f(-54.031f, 11.38f, 0.0f);
	glVertex3f(-53.682f, 4.8285f, 0.0f);
	glVertex3f(-20.082f, 13.358f, 0.0f);
	glVertex3f(-19.966f, 17.364f, 0.0f);
	glEnd();


	glBegin(GL_QUADS);
	glColor3f(0.635f, 0.647f, 0.611f);
	glVertex3f(-63.30f, 12.605f, 0.0f);
	glVertex3f(-53.711f, 10.389f, 0.0f);
	glVertex3f(-19.96f, 17.364f, 0.0f);
	glVertex3f(-29.6425f, 17.779f, 0.0f);
	glEnd();

	//chimneys
	glBegin(GL_QUADS);
	glColor3f(0.219f, 0.227f, 0.213f);
	glVertex3f(-62.183f, 24.96f, 0.0f);
	glVertex3f(-60.829f, 17.8528f, 0.0f);
	glVertex3f(-57.94f, 18.0f, 0.0f);
	glVertex3f(-58.284, 25.066f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.219f, 0.227f, 0.213f);
	glVertex3f(-60.8f, 17.852f, 0.0f);
	glVertex3f(-61.599f, 12.855f, 0.0f);
	glVertex3f(-55.745f, 12.98f, 0.0f);
	glVertex3f(-57.946f, 18.00, 0.0f);
	glEnd();
	//line on right side
	glLineWidth(5.0f);
	glBegin(GL_LINES);
	glColor3f(0.713f, 0.733f, 0.690f);
	glVertex3f(25.22f, 18.079f, 0.0f);
	glVertex3f(21.451f, -27.6019f, 0.0f);
	glEnd();
	//
	////points
	//
	//
	//
	//glPointSize(8.0f);
	//glBegin(GL_POINTS);
	//glColor3f(0.219f, 0.227f, 0.213f);
	//glVertex3f(25.22f, 16.889f, 0.0f);
	//glVertex3f(24.728f, 11.43f, 0.0f);
	//glVertex3f(24.23f, 6.670f, 0.0f);
	//glVertex3f(23.935f, 1.8090f, 0.0f);
	//glVertex3f(23.538f, -3.052f, 0.0f);
	//glVertex3f(23.141f, -7.814f, 0.0f);
	//glEnd();
	//////points
	//glPointSize(8.0f);
	//glBegin(GL_POINTS);
	//glColor3f(0.513f, 0.533f, 0.533f);
	//glVertex3f(22.86f, -12.2f, 0.0f);
	//glVertex3f(22.48f, -16.588f, 0.0f);
	//glVertex3f(22.02f, -20.69f, 0.0f);
	//glVertex3f(21.82f, -26.481f, 0.0f);
	//glEnd();

	glPointSize(4.0f);
	glBegin(GL_POINTS);
	glColor3f(0.219f, 0.227f, 0.213f);
	glVertex3f(-43.538f, 3.15091f, 0.0f);
	glVertex3f(-40.150f, 2.4633f, 0.0f);
	glVertex3f(-36.565f, 1.800f, 0.0f);
	glVertex3f(-32.833f, 1.2602f, 0.0f);
	glVertex3f(-28.70f, 0.691453f, 0.0f);
	glVertex3f(-24.524f, -0.090631f, 0.0f);
	glVertex3f(-20.11f, -0.94381f, 0.0f);
	glVertex3f(-15.41f, -1.6548f, 0.0f);
	glEnd();

	//door
	glBegin(GL_QUADS);
	glColor3f(0.713f, 0.733f, 0.690f);
	glVertex3f(-45.477f, -6.5424f, 0.0f);
	glVertex3f(-45.2272f, -10.0257f, 0.0f);
	glVertex3f(-30.96f, -13.91f, 0.0f);
	glVertex3f(-31.177f, -10.29f, 0.0f);
	glEnd();

	glLineWidth(5.0f);
	glBegin(GL_LINES);
	glColor3f(0.635f, 0.647f, 0.611f);
	glVertex3f(-38.79f, -8.0097f, 0.0f);
	glVertex3f(-38.792f, -11.768f, 0.0f);
	glVertex3f(-54.031f, 11.389f, 0.0f);
	glVertex3f(-51.23f, -8.549f, 0.0f);
	glEnd();

	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, vb_z_tranlsate);
	glScalef(0.02f, 0.02f, 0.02f);

	glBegin(GL_QUADS);
	glColor3f(0.61f, 0.69f, 0.807f);
	glVertex3f(6.568f, -19.1f, 0.0f);
	glVertex3f(6.338f, -21.745f, 0.0f);
	glVertex3f(8.258f, -22.12f, 0.0f);
	glVertex3f(8.335f, -19.4409f, 0.0f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.1f, -0.02f, vb_z_tranlsate);
	glScalef(0.02f, 0.02f, 0.02f);

	glBegin(GL_QUADS);
	glColor3f(0.61f, 0.69f, 0.807f);
	glVertex3f(6.568f, -19.1f, 0.0f);
	glVertex3f(6.338f, -21.745f, 0.0f);
	glVertex3f(8.258f, -22.12f, 0.0f);
	glVertex3f(8.335f, -19.4409f, 0.0f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.2f, -0.04f, vb_z_tranlsate);
	glScalef(0.02f, 0.02f, 0.02f);

	glBegin(GL_QUADS);
	glColor3f(0.61f, 0.69f, 0.807f);
	glVertex3f(6.568f, -19.1f, 0.0f);
	glVertex3f(6.338f, -21.745f, 0.0f);
	glVertex3f(8.258f, -22.12f, 0.0f);
	glVertex3f(8.335f, -19.4409f, 0.0f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.3f, -0.06f, vb_z_tranlsate);
	glScalef(0.02f, 0.02f, 0.02f);

	glBegin(GL_QUADS);
	glColor3f(0.219f, 0.227f, 0.213f);
	glVertex3f(5.568f, -19.1f, 0.0f);
	glVertex3f(5.338f, -24.145f, 0.0f);
	glVertex3f(8.258f, -24.745f, 0.0f);
	glVertex3f(8.335f, -19.4409f, 0.0f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.45f, -0.085f, vb_z_tranlsate);
	glScalef(0.02f, 0.02f, 0.02f);

	glBegin(GL_QUADS);
	glColor3f(0.61f, 0.69f, 0.807f);
	glVertex3f(6.568f, -19.1f, 0.0f);
	glVertex3f(6.338f, -21.745f, 0.0f);
	glVertex3f(8.258f, -22.12f, 0.0f);
	glVertex3f(8.335f, -19.4409f, 0.0f);
	glEnd();
	glLoadIdentity();
	glTranslatef(0.6f, -0.12f, vb_z_tranlsate);
	glScalef(0.02f, 0.02f, 0.02f);

	glBegin(GL_QUADS);
	glColor3f(0.219f, 0.227f, 0.213f);
	glVertex3f(5.568f, -19.1f, 0.0f);
	glVertex3f(5.338f, -24.145f, 0.0f);
	glVertex3f(8.258f, -24.745f, 0.0f);
	glVertex3f(8.335f, -19.4409f, 0.0f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.7f, -0.14f, vb_z_tranlsate);
	glScalef(0.02f, 0.02f, 0.02f);

	glBegin(GL_QUADS);
	glColor3f(0.61f, 0.69f, 0.807f);
	glVertex3f(6.568f, -19.1f, 0.0f);
	glVertex3f(6.338f, -21.745f, 0.0f);
	glVertex3f(8.258f, -22.12f, 0.0f);
	glVertex3f(8.335f, -19.4409f, 0.0f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, vb_z_tranlsate);
	glScalef(0.02f, 0.02f, 0.02f);

	glBegin(GL_QUADS);
	glColor3f(0.219f, 0.227f, 0.213f);
	glVertex3f(-17.122f, -14.499f, 0.0f);
	glVertex3f(-16.81f, -17.27f, 0.0f);
	glVertex3f(-14.80f, -17.893f, 0.0f);
	glVertex3f(-15.11f, -14.808f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.219f, 0.227f, 0.213f);
	glVertex3f(-49.966f, 21.283f, 0.0f);
	glVertex3f(-49.8356f, 14.4979f, 0.0f);
	glVertex3f(-45.1482f, 14.979f, 0.0f);
	glVertex3f(-46.98f, 21.664f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.219f, 0.227f, 0.213f);
	glVertex3f(-43.22f, 25.50f, 0.0f);
	glVertex3f(-42.683f, 19.8979f, 0.0f);
	glVertex3f(-40.312f, 20.051f, 0.0f);
	glVertex3f(-40.75f, 25.597f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.219f, 0.227f, 0.213f);
	glVertex3f(-42.68f, 19.897f, 0.0f);
	glVertex3f(-43.591f, 15.812f, 0.0f);
	glVertex3f(-38.498f, 16.09f, 0.0f);
	glVertex3f(-40.3123f, 20.051f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.219f, 0.227f, 0.213f);
	glVertex3f(-32.6269f, 22.5546f, 0.0f);
	glVertex3f(-33.1319f, 16.769f, 0.0f);
	glVertex3f(-29.45f, 16.8613f, 0.0f);
	glVertex3f(-30.606f, 22.508f, 0.0f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, vb_z_tranlsate);
	glScalef(0.02f, 0.02f, 0.02f);

	glBegin(GL_QUADS);
	glColor3f(0.219f, 0.227f, 0.213f);
	glVertex3f(-21.225f, 12.76f, 0.0f);
	glVertex3f(-21.2795f, 11.40f, 0.0f);
	glVertex3f(-20.028f, 11.3459f, 0.0f);
	glVertex3f(-19.973f, 12.65f, 0.0f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.2f, 0.0f, vb_z_tranlsate);
	glScalef(0.02f, 0.02f, 0.02f);

	glBegin(GL_QUADS);
	glColor3f(0.219f, 0.227f, 0.213f);
	glVertex3f(-21.225f, 12.76f, 0.0f);
	glVertex3f(-21.2795f, 11.40f, 0.0f);
	glVertex3f(-20.028f, 11.3459f, 0.0f);
	glVertex3f(-19.973f, 12.65f, 0.0f);
	glEnd();


	
}

void AstroMediComp(void)
{
	//Astromedicomp
	glBindTexture(GL_TEXTURE_2D, texture_astro);

	glBegin(GL_QUADS);

	//front face
	//glTexCoord2f(0.0, 0.0);
	glTexCoord2f(1.0, 1.0);

	glVertex3f(200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-200.0f, -100.0f, 1.0f);

	glTexCoord2f(1.0, 0.0);
	//glTexCoord2f(0.0, 1.0);
	glVertex3f(200.0f, -100.0f, 1.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Ortho(void)
{
	//Ortho
	glBindTexture(GL_TEXTURE_2D, texture_ortho);

	glBegin(GL_QUADS);

	//front face
	//glTexCoord2f(0.0, 0.0);
	glTexCoord2f(1.0, 1.0);

	glVertex3f(200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-200.0f, -100.0f, 1.0f);

	glTexCoord2f(1.0, 0.0);
	//glTexCoord2f(0.0, 1.0);
	glVertex3f(200.0f, -100.0f, 1.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}

void TechUsed(void)
{
	//Tech Used
	glBindTexture(GL_TEXTURE_2D, texture_techused);

	glBegin(GL_QUADS);

	//front face
	//glTexCoord2f(0.0, 0.0);
	glTexCoord2f(1.0, 1.0);

	glVertex3f(200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-200.0f, -100.0f, 1.0f);

	glTexCoord2f(1.0, 0.0);
	//glTexCoord2f(0.0, 1.0);
	glVertex3f(200.0f, -100.0f, 1.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}

void GroupMem(void)
{
	//GroupMem
	glBindTexture(GL_TEXTURE_2D, texture_gmem);

	glBegin(GL_QUADS);

	//front face
	//glTexCoord2f(0.0, 0.0);
	glTexCoord2f(1.0, 1.0);

	glVertex3f(200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-200.0f, -100.0f, 1.0f);

	glTexCoord2f(1.0, 0.0);
	//glTexCoord2f(0.0, 1.0);
	glVertex3f(200.0f, -100.0f, 1.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}

void GroupLead(void)
{
	//GL
	glBindTexture(GL_TEXTURE_2D, texture_gl);

	glBegin(GL_QUADS);

	//front face
	//glTexCoord2f(0.0, 0.0);
	glTexCoord2f(1.0, 1.0);

	glVertex3f(200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-200.0f, -100.0f, 1.0f);

	glTexCoord2f(1.0, 0.0);
	//glTexCoord2f(0.0, 1.0);
	glVertex3f(200.0f, -100.0f, 1.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}


void Sir(void)
{
	//Sir
	glBindTexture(GL_TEXTURE_2D, texture_sir);

	glBegin(GL_QUADS);

	//front face
	//glTexCoord2f(0.0, 0.0);
	glTexCoord2f(1.0, 1.0);

	glVertex3f(200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-200.0f, -100.0f, 1.0f);

	glTexCoord2f(1.0, 0.0);
	//glTexCoord2f(0.0, 1.0);
	glVertex3f(200.0f, -100.0f, 1.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Madam(void)
{
	//Madam
	glBindTexture(GL_TEXTURE_2D, texture_madam);

	glBegin(GL_QUADS);

	//front face
	//glTexCoord2f(0.0, 0.0);
	glTexCoord2f(1.0, 1.0);

	glVertex3f(200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 0.0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-200.0f, 100.0f, 1.0f);

	//glTexCoord2f(1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-200.0f, -100.0f, 1.0f);

	glTexCoord2f(1.0, 0.0);
	//glTexCoord2f(0.0, 1.0);
	glVertex3f(200.0f, -100.0f, 1.0f);

	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
}


void vertex_fetch_stage_2(void)
{
	void drawConveyor(void);
	void draw_pixel(void);
	void bg_frame1(void);
	void floor_blue(void);
	// code
	// depth step - 3
	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);
	// draw top background frame
	bg_frame1();


	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(0.0f, 0.0f, -3.0f);
	// draw conveyor
	glTranslatef(x_translate_vf, 1.3, -1.0);	//for translating conveyor on x axis
	drawConveyor();

	

	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(X_circle0_translate, 0.7f, -3.0f);
	//glTranslatef(0.0f, 0.0f, -1.0f);
	draw_pixel();
	//this switch case is for different objects on conveyor belts which are alligned by the red line
	//switch (condition)
	//{
	//case 1:
	//	if (X_circle0_translate >= 1.0)	// the alligning is done when the obect reaches on 1.0 co-ordinate on x-axis
	//	{
	//		draw_circle_with_LINES(0.4);	// we want the object to allign to 0.4 on y-axis after it reaches 0.1 on x-axis, so 0.4 is passed
	//	}
	//	else
	//		draw_circle_with_LINES(0.3);	// the initial position of the object is passed here with which it will appear on the conveyor in the beginning

	//	break;

	//case 2:
	//	if (X_circle0_translate >= 1.0)
	//	{
	//		draw_circle_with_LINES(0.4);	// we want the object to allign to 0.4 on y-axis after it reaches 0.1 on x-axis, so 0.4 is passed
	//	}
	//	else
	//		draw_circle_with_LINES(0.46);	// the initial position of the object is passed here with which it will appear on the conveyor in the beginning
	//	break;

	//case 3:
	//	if (X_circle0_translate >= 1.0)
	//	{
	//		draw_circle_with_LINES(0.4);
	//	}
	//	else
	//		draw_circle_with_LINES(0.4);
	//	break;

	//case 4:
	//	if (X_circle0_translate >= 1.0)
	//	{
	//		draw_circle_with_LINES(0.4);
	//	}
	//	else
	//		draw_circle_with_LINES(0.44);
	//	break;

	//case 5:
	//	if (X_circle0_translate >= 1.0)
	//	{
	//		draw_circle_with_LINES(0.4);
	//	}
	//	else
	//		draw_circle_with_LINES(0.35);
	//	break;

	//case 6:
	//	if (X_circle0_translate >= 1.0)
	//	{
	//		draw_circle_with_LINES(0.4);
	//	}
	//	else
	//		draw_circle_with_LINES(0.33);
	//	break;

	//case 7:
	//	if (X_circle0_translate >= 1.0)
	//	{
	//		draw_circle_with_LINES(0.4);
	//	}
	//	else
	//		draw_circle_with_LINES(0.4);
	//	break;

	//case 8:
	//	if (X_circle0_translate >= 1.0)
	//	{
	//		draw_circle_with_LINES(0.4);
	//	}
	//	else
	//		draw_circle_with_LINES(0.46);
	//	break;
	//default:
	//	break;
	//}
	glLoadIdentity();	// this call makes model view matrix into identity matrix
	glTranslatef(-0.7f, -0.1, -3.0f);
	glBegin(GL_QUADS);
	//glColor3f(0.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 0.517f, 0.568f);
	glVertex3f(-0.8f, 0.6f, 0.0f);
	glVertex3f(3.0f, 0.6f, 0.0f);
	glVertex3f(3.0f, 0.9f, 0.0f);
	glVertex3f(-0.8f, 0.9f, 0.0f);
	glEnd();


	// we want the conveyor objects to keep coming so once the object exits on the right side of the screen after all 9 cases we are repesting the case from beginning and for that we are resetting the x-axis co-ordinates
	if (X_circle0_translate >= 4.0)
	{
		X_circle0_translate = -2.5;	// resetting the x-axis co-ordinate for object
	}


	x_translate_vf = x_translate_vf + 0.007;	// translation of the conveyor belt on x-axis is done here
	X_circle0_translate = X_circle0_translate + 0.3;	// translation of the object on the conveyor belt on x-axis is done here

	if (x_translate_vf >= 3.0)	// resetting of the x-axis co-ordinate for the conveyor belt
	{
		x_translate_vf = 0.0;
	}

}

