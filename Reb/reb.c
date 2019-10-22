/*
 \file		reb.c
 \author	${user}
 \date		${date}
 \brief		Simple Hello World! for the Ev3
*/

#include <ev3.h>

int main(void)
{
	//TODO Place here your variables

	InitEV3();

	//TODO Place here your code
	LcdPrintf(1, "Hello Rebecca!\n");

	setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);
	readSensor(IN_1);
	readSensor(IN_3);
		if(readSensor(IN_1) == 1){
			LcdPrintf(1,"Turn Right! 1st \n");
			OnRevSync(OUT_B,23);
			Wait(SEC_7 + MS_500);
			if(readSensor(IN_1) + readSensor(IN_3) == 1);
			{stop;}
		}
		else if(readSensor(IN_3) == 1){
				LcdPrintf(1,"Turn Right! 1st \n");
				OnRevSync(OUT_A,23);
				Wait(SEC_7 + MS_500);
		}

		if(readSensor(IN_1) + readSensor(IN_3) == 1)
			{stop;}

			backward();
				LcdPrintf(1,"Going Backward!\n");
				OnRevSync(OUT_AB,75);
				Wait(SEC_7);

			rotation();
				LcdPrintf(1,"Turn Right! 1st \n");
				OnFwdReg(OUT_A,23);
				Wait(SEC_7 + MS_500);

				LcdPrintf(1,"Turn Right! 2nd \n");
				OnFwdReg(OUT_A,23);
				Wait(SEC_7 + MS_500);

			forward();
				OnRevSync(OUT_AB,75);
				Wait(SEC_20); //Borde ligga mellnad 20-21

			rotatemotor();
				LcdPrintf(1,"Turn Right! 1st \n");
				OnFwdReg(OUT_A,23);
				Wait(SEC_7 + MS_500);

				LcdPrintf(1,"Turn Right! 2nd \n");
				OnFwdReg(OUT_A,23);
				Wait(SEC_7 + MS_500);

			backward();
				LcdPrintf(1,"Going Backward!\n");
				OnRevSync(OUT_AB,75);
				Wait(SEC_7);
	}

	FreeEV3();
	return 0;
}
/*
 Rebecca
*/
