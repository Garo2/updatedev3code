/*
 \file		Ev3.c
 \author	${user}
 \date		${date}
 \brief		Simple Hello World! for the Ev3
*/

#include <ev3.h>

int main(void)
{
	//TODO Place here your variables

	InitEV3();
moving();

	//TODO Place here your code
	FreeEV3();
	return 0;
}
int moving()
{
	LcdPrintf(1, "Hello World!\n");
	Wait(SEC_1);

	LcdPrintf(1, "Going Forward!\n");
	OnFwdSync(OUT_AB,75);
	Wait(SEC_4);

	LcdPrintf(1,"Going Backward!\n");
	OnRevSync(OUT_AB,75);
	Wait(SEC_4);

	LcdPrintf(1,"Turn Right!\n");
	OnFwdReg(OUT_A,50);
	OnRevReg(OUT_B,50);
	Wait(SEC_2);

	LcdPrintf(1,"Turn Left!\n"); //Lite kommentar för test
	OnFwdReg(OUT_B,50);
	OnRevReg(OUT_A,50);
	Wait(SEC_2);

	LcdPrintf(1,"Use the hand\n");
	RotateMotor(OUT_C,10,45);
	Wait(SEC_1);
	return 0;
}
