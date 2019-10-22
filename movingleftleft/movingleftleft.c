#include <stdio.h>
#include <ev3.h>

void rotateRobot();
int findMinDistance();
void forward();
void touchSensor();
void dropBook();
void backward90right();
void backward90left();
void forward25();
void rotate90();
void rotate180();



int main()
{
/*
 Vera och Garo
*/
	InitEV3();
    int indexTid = findMinDistance();
    int i;
    LcdPrintf(1,"Going to %d", indexTid);

    for(i = 0; i <= indexTid; i++) {
    	rotateRobot();
    }

    Off(OUT_AB);

   forward();

   touchSensor();

   backward90right();

   forward25();

   Off(OUT_AB);

   backward90left();

   forward();

   touchSensor();

   rotate180();

   forward();

   touchSensor();

   rotate90();

   dropBook();

    return 0;
}

int findMinDistance () {
/*
 Vera, uppdaterad av Garo
*/
    int distance;
    int minDis;
    int arrayDis[64];
    int indexTidForMinDis;
    int j;
    int k;

    setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);

    for(j = 0; j < 64; j++) {
        rotateRobot(j);
        distance = readSensor(IN_4);
        arrayDis[j] = distance;
        LcdPrintf(1, "%d: %d ", j, arrayDis[j]);
    }

    minDis = arrayDis[0];
    for(k = 1; k<=63; k++)
    {
        if(minDis > arrayDis[k])
        {
            minDis = arrayDis[k];
            indexTidForMinDis = k+1;
        }
    }

    return indexTidForMinDis;
}

void rotateRobot() {
/*
 Garo
*/

    OnFwdReg(OUT_A, 15);
    OnRevReg(OUT_B, 15);
    Wait(105);

}

void forward() {
/*
 Garo
*/
	//framåt X m
    LcdPrintf(1, "Going Forward!\n");
    OnFwdSync(OUT_AB,55);
}

void touchSensor()
{
/*
 Rebecca, uppdaterad av Garo
*/
	setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);
		int rightSens = readSensor(IN_1);
		int leftSens = readSensor(IN_3);

		OnFwdSync(OUT_AB, 50);

	 while(1)
	{
		 rightSens = readSensor(IN_1);
		 leftSens = readSensor(IN_3);


				if (rightSens == 1 && leftSens==1)
				{
					Wait(SEC_1);
					Off(OUT_AB);
					break;
				}
				if (rightSens==1)
				{ Off(OUT_AB);

					OnFwdReg(OUT_B, 50);
					Wait(SEC_3);
					Off(OUT_AB);
					break;


				}
				if (leftSens==1)
				{
					Off(OUT_AB);

					OnFwdReg(OUT_A, 50);
					Wait(SEC_3);
					Off(OUT_AB);
					break;;


				}

	}
}
void dropBook() {
/*
 Vera
*/
	 LcdPrintf(1,"Use the hand\n");
		 RotateMotor(OUT_C, 10, 90); //funkar 90 grader?
		 Wait(SEC_1);
		 RotateMotor(OUT_C, -10, 90); //onödigt men för att få tillbaka armen på ursprunglig plats (ser snyggt ut)
}
void backward90right()
{
/*
 Garo
*/
	OnRevReg(OUT_B, 23);
	Wait(2450);
	Off(OUT_AB);
}
void backward90left()
{
/*
 Garo
*/
	OnRevReg(OUT_A, 23);
	Wait(2450);
	Off(OUT_AB);
}
void forward25()
{
/*
 Garo
*/
	Off(OUT_AB);
	OnFwdSync(OUT_AB, 50);
	Wait(SEC_10+1111);
	Off(OUT_AB);
}
void rotate90()
{
/*
 Garo
*/
	OnFwdReg(OUT_A, 15);
	OnRevReg(OUT_B, 15);
	Wait(1750);
	Off(OUT_AB);
}

void rotate180()
{
/*
 Garo
*/
	OnRevSync(OUT_AB, 20);
	Wait(SEC_1);
	Off(OUT_AB);
	OnFwdReg(OUT_A, 15);
	OnRevReg(OUT_B, 15);
	Wait(3600);
	Off(OUT_AB);
}
