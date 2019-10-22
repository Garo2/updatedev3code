/*
 \file		rotate.c
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
	LcdPrintf(1, "Hello World!\n");
	Wait(SEC_2);

	LcdPrintf(1,"Turn Right! 1st \n");
	OnFwdReg(OUT_A,23);
	Wait(SEC_3 + MS_700 + MS_50);

	LcdPrintf(1,"Turn Right! 2st \n");
	OnFwdReg(OUT_A,23);
	Wait(SEC_3 + MS_700 + MS_50);

	LcdPrintf(1,"Turn Right! 3rd \n");
	OnFwdReg(OUT_A,23);
	Wait(SEC_3 + MS_700 + MS_50);

	LcdPrintf(1,"Turn Right! 4th \n");
	OnFwdReg(OUT_A,23);
	Wait(SEC_3 + MS_700 + MS_50);

	LcdPrintf(1,"Turn Right! 5th \n");
	OnFwdReg(OUT_A,23);
	Wait(SEC_3 + MS_700 + MS_50);

	LcdPrintf(1,"Turn Right! 6th \n");
	OnFwdReg(OUT_A,23);
	Wait(SEC_3 + MS_700 + MS_50);

	LcdPrintf(1,"Turn Right! 7th \n");
	OnFwdReg(OUT_A,23);
	Wait(SEC_3 + MS_700 + MS_50);

	LcdPrintf(1,"Turn Right! 8th \n");
	OnFwdReg(OUT_A,23);
	Wait(SEC_3 + MS_700 + MS_50);


	FreeEV3();
	return 0;
}
/*
 Garo
*/
