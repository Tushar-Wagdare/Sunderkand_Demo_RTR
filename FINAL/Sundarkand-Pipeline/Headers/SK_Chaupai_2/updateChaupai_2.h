#pragma once

#include <windows.h>

void updateChaupai_2(void)
{
	//_______________________________________Hanumanji Default Animation______________________________//




//___Head___
	if (rHead <= 0.0f && bHead == FALSE)
	{
		rHead = rHead + 0.002f;
	}
	else if (rHead >= -2.0f)
	{
		bHead = TRUE;
		rHead = rHead - 0.002f;
	}
	else
	{
		bHead = FALSE;
	}

	//___Tail___
	if (rTail <= 5.0f && bTail == FALSE)
	{
		rTail = rTail + 0.03f;
	}
	else if (rTail >= -2.0f)
	{
		bTail = TRUE;
		rTail = rTail - 0.03f;
	}
	else
	{
		bTail = FALSE;
	}

	//___Leg___
	if (bHanumanRotate == TRUE && rotate_left_leg <= 12.0f && bRotateLeg == FALSE)
	{
		rotate_left_leg = rotate_left_leg + 0.03;
		rotate_right_leg = rotate_right_leg - 0.03;
	}
	else if (rotate_left_leg >= -5.0f && bHanumanRotate == TRUE)
	{
		bRotateLeg = TRUE;
		rotate_left_leg = rotate_left_leg - 0.03;
		rotate_right_leg = rotate_right_leg + 0.03;
	}
	else
	{
		bRotateLeg = FALSE;
	}

	switch (main_sceen)
	{
	case 2:
		/*GLfloat xHanuman = 700.0f;
		GLfloat yHanuman = 100.0f;
		GLfloat zHanuman = -600.0f;*/
		//***__________________________________Default Baground Animation_____________________________//
		//Water Animation Automation UPDATE
		if (xWater <= 25.0f && bWater == FALSE)
		{
			xWater = xWater + 0.01f;
			yWater = yWater + 0.003f;
		}
		else if (xWater >= 0.0f)
		{
			bWater = TRUE;
			xWater = xWater - 0.01f;
			yWater = yWater - 0.003f;
		}
		else
		{
			bWater = FALSE;
		}
		//Cloud Animation Automation
		if (xCloud <= 1600.0f)
		{
			xCloud = xCloud + 0.1f;
			yCloud = yCloud + 0.0005f;
			zCloud = zCloud - 0.03;
		}
		else
		{
			xCloud = -800.0f;
			yCloud = -8.0f;
			zCloud = 1.0f;
		}
		//Bird Animation Automation
		if (zBird <= 900.0f)
		{
			xBird = xBird + 0.1f;
			yBird = yBird + 0.05f;
			zBird = zBird + 1.0f;
		}
		else
		{
			xBird = 0.0f;
			yBird = 0.0f;
			zBird = -9000.0f;
		}


		//_________________________________________Sursa Default Animation________________________________________//
		//___Sursa Default Animation___
		if (sursa_rotate >= -10 && bSursa == FALSE)
		{
			sursa_rotate = sursa_rotate - 0.01;
			sursa_yTranslate = sursa_yTranslate + 0.0001;
		}
		else if (sursa_rotate <= 5)
		{
			bSursa = TRUE;
			sursa_rotate = sursa_rotate + 0.01;
			sursa_yTranslate = sursa_yTranslate - 0.0001;
		}
		else
		{
			bSursa = FALSE;
		}


		//****** Main Sceens Animation *****//
		switch (short_sceen)
		{
		case 1:
			//Hanumanji Flying Towords Lanka
			bHanumanRotate = TRUE;
			if (xHanuman >= 150.0f)
			{
				xHanuman = xHanuman - 0.18f;
				zHanuman = zHanuman + 0.09f;
			}
			break;


		case 2:
			//***** Sursa Transformations Update *****
			//____Sursa Comming Up___
			if (ySursa <= -30.0f)
			{
				ySursa = ySursa + 0.05f;
			}
			//Hanumanji Talking To Sursa
			if (ySursa >= -31.0f && yHanuman >= -30.0f)
			{
				bHanumanRotate = FALSE;
				yHanuman = yHanuman - 0.1f;
			}
			break;


		case 3:
			if (xScaleSursa >= 0.5f && sSursa == FALSE)
			{
				xScaleSursa = xScaleSursa - 0.01f;
				yScaleSursa = yScaleSursa - 0.01f;
				zScaleSursa = zScaleSursa - 0.01f;

				xScaleHanuman = xScaleHanuman - 0.012f;
				yScaleHanuman = yScaleHanuman - 0.012f;
				zScaleHanuman = zScaleHanuman - 0.012f;
			}
			else if (xScaleSursa <= 0.9f)
			{
				sSursa = TRUE;
				xScaleSursa = xScaleSursa + 0.001f;
				yScaleSursa = yScaleSursa + 0.001f;
				zScaleSursa = zScaleSursa + 0.001f;
			}
			else if (xScaleHanuman <= 1.4f && sSursa >= 0.89f)
			{
				xScaleHanuman = xScaleHanuman + 0.0012f;
				yScaleHanuman = yScaleHanuman + 0.0012f;
				zScaleHanuman = zScaleHanuman + 0.0012f;
			}
			break;


		case 4:
			if (xScaleSursa <= 1.5f)
			{
				xScaleSursa = xScaleSursa + 0.001f;
				yScaleSursa = yScaleSursa + 0.001f;
				zScaleSursa = zScaleSursa + 0.001f;
			}
			else if (xScaleHanuman <= 2.5f)
			{
				xScaleHanuman = xScaleHanuman + 0.0012f;
				yScaleHanuman = yScaleHanuman + 0.0012f;
				zScaleHanuman = zScaleHanuman + 0.0012f;
			}
			break;


		case 5:
			if (xScaleSursa <= 2.5f)
			{
				xScaleSursa = xScaleSursa + 0.001f;
				yScaleSursa = yScaleSursa + 0.001f;
				zScaleSursa = zScaleSursa + 0.001f;

				xScaleHanuman = xScaleHanuman + 0.001f;
				yScaleHanuman = yScaleHanuman + 0.001f;
				zScaleHanuman = zScaleHanuman + 0.001f;

				xHanuman = xHanuman + 0.01f;
			}
			break;


		case 6:
			if (xScaleHanuman >= 0.2)
			{
				xScaleHanuman = xScaleHanuman - 0.001f;
				yScaleHanuman = yScaleHanuman - 0.001f;
				zScaleHanuman = zScaleHanuman - 0.001f;

				yHanuman = yHanuman + 0.02f;
			}
			break;

		case 7:
			if (xHanuman >= 0.0f)
			{
				//bHanumanRotate = TRUE;
				xHanuman = xHanuman - 0.05f;
			}
			else if (xHanuman <= 150)
			{
				xHanuman = xHanuman + 0.05f;
			}
			break;
			//bHanumanRotate = TRUE;





		default:
			break;
		}
		break;

	//case 1:

	//	if (yMainakTranslate <= -0.3f)
	//	{
	//		yMainakTranslate += 0.002f;
	//	}

	//	/*if (xHanumanTranslate >= -1.5f)
	//	{
	//		xHanumanTranslate -= 0.0005f;
	//	}*/

	//	//Hanumanji Flying Towords Lanka
	//	bHanumanRotate = TRUE;
	//	if (xHanuman >= -450.0f)
	//	{
	//		xHanuman = xHanuman - 0.38f;
	//		zHanuman = zHanuman + 0.19f;
	//	}

	//	break;


	default:
		break;
	}
}
