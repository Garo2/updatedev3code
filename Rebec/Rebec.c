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
		if(readSensor(IN_1) == 1)
		{
			LcdPrintf(1, "Hello World!\n");
			Wait(SEC_2);
		}
		else {
				LcdPrintf(1, "NOPE!\n");
				Wait(SEC_2);
		}


	FreeEV3();
	return 0;
}
