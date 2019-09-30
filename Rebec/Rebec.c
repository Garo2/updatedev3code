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
		if(readSensor(IN_1) == 1)
		{
			LcdPrintf(1, "FIRST IS PRESSED!\n");
			Wait(SEC_2);
		}
		else {
				LcdPrintf(1, "NOPE!\n"); //det här är ett test
				Wait(SEC_2);
		}

		if(readSensor(IN_3) == 1)
		{
			LcdPrintf(1, "SECOND IS PRESSED!\n");
			Wait(SEC_2);
		}

		if(readSensor(IN_3)+readSensor(IN_1)==1)
		{
			LcdPrintf(1, "BOTH ARE PRESSED!\n");
			Wait(SEC_2);
		}

	FreeEV3();
	return 0;
}
