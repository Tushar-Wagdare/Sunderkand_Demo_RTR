void draw_bird(void)
{

#define up 1
#define down 2
	int dir = up;
	GLfloat rwAngle = 360.0f, lwAngle = 0.0f, body_angle = 0.0f;
	GLfloat y1_translate = 0.5f;//-0.0659f;
	GLfloat x1_translate = -1.55f;
	int scene = 1;
	int fly_flag = 1;

	//switch case for wings movement
	switch (dir)
	{
	case up:
		//if (rwAngle > 270.0f)
		//	rwAngle -= 0.01f;

		if (lwAngle <= 65.0f)
			lwAngle += 0.05f;
		else
			dir = down;



		break;
	case down:

		if (lwAngle >= 0.0f)
			lwAngle -= 0.05f;
		else
		{
			dir = up;
			//lwAngle = 180.0f;
		}


	default:
		break;
	}

	switch (scene)
	{
	case 1:
		if (x1_translate <= -0.4)
			x1_translate += 0.0001;
		else scene = 2;

		glTranslatef(x1_translate, y1_translate, 0.0f);
		glScalef(0.5f, 0.5f, 0.0f);
		break;

	case 2:
		if (body_angle < 85.0f)
			body_angle += 0.01f;
		else
		{
			scene = 3;
			fly_flag = 0;
		}
		glTranslatef(x1_translate, y1_translate, 0.0f);
		glRotatef(body_angle, 0, 0, 1);
		glScalef(0.5f, 0.5f, 0.0f);
		break;
	case 3:
		if (y1_translate >= -1.5)
			y1_translate -= 0.000098;
		glTranslatef(x1_translate, y1_translate, 0.0f);
		glRotatef(body_angle, 0, 0, 1);
		glScalef(0.5f, 0.5f, 0.0f);
		break;
	}
}