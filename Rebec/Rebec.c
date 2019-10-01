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

	while(readSensor(IN_1) == 1, readSensor(IN_3) == 0)
	{
		LcdPrintf(1, "FIRST IS PRESSED!\n");
		Wait(SEC_1);
	}

	while(readSensor(IN_3) == 1, readSensor(IN_1) == 0)
	{
		LcdPrintf(1, "SECOND IS PRESSED!\n");
		Wait(SEC_1);
	}

	if(readSensor(IN_3) && readSensor(IN_1)==1)
	{
		LcdPrintf(1, "BOTH ARE PRESSED!\n");
		Wait(SEC_3);
			}

	FreeEV3();
	return 0;
}
