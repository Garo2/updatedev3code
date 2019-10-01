/*
 \file		Rebec.c
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
	setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);
	readSensor(IN_1);
	readSensor(IN_3);

	while(readSensor(IN_1) == 0, readSensor(IN_3) == 0)
	{
		LcdPrintf(1,"Going Forward! \n");
				OnRevSync(OUT_AB,75);
				Wait(SEC_1);
	}

	while(readSensor(IN_1) == 1, readSensor(IN_3) == 0)
	{
		LcdPrintf(1, "FIRST IS PRESSED!\n");
		LcdPrintf(1,"Turn Right! \n");
		OnRevSync(OUT_B,23);
		Wait(SEC_1);
	}

	while(readSensor(IN_3) == 1, readSensor(IN_1) == 0)
	{
		LcdPrintf(1, "SECOND IS PRESSED!\n");
		LcdPrintf(1,"Turn Right!\n");
		OnRevSync(OUT_A,23);
		Wait(SEC_1);
	}

	if(readSensor(IN_3) && readSensor(IN_1)==1)
	{
		LcdPrintf(1,"Going Backward!\n");
		OnFwdReg(OUT_AB,75);
		Wait(SEC_2);

		LcdPrintf(1,"Turn Left! 1st \n");
		OnFwdReg(OUT_B,23);
		Wait(SEC_4);

		LcdPrintf(1,"Going Forward! \n");
		OnRevSync(OUT_AB,75);
		Wait(SEC_3);
			}

	FreeEV3();
	return 0;
}
