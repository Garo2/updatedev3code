#include <stdio.h>
#include <ev3.h>

void rotateRobot();
int findMinDistance();
void forward();
void touchSensor();
void dropBook();
void backward90left();
void forward25();
void rotate180();



int main()
{

	InitEV3();
	// setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);
    int indexTid = findMinDistance();
    int i;
    LcdPrintf(1,"Going to %d", indexTid);

    for(i = 0; i <= indexTid; i++) {
    	rotateRobot();
    }

    Off(OUT_AB);

   forward();

   touchSensor();

   backward90left();

   forward25();

   rotate180();

   dropBook();

    return 0;
}

int findMinDistance () {
    int distance;
    int minDis;
    int arrayDis[15];
    int indexTidForMinDis;
    int j;
    int k;

    setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);

    for(j = 0; j < 16; j++) {
        rotateRobot(j);
        distance = readSensor(IN_4);
        arrayDis[j] = distance;
        LcdPrintf(1, "%d: %d ", j, arrayDis[j]);
    }

    minDis = arrayDis[0];
    for(k = 1; k<=15; k++)
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

    OnFwdReg(OUT_A, 15);
    OnRevReg(OUT_B, 15);
    Wait(420);

}

void forward() {
	//framåt X m
    LcdPrintf(1, "Going Forward!\n");
    OnFwdSync(OUT_AB,50);
}

void touchSensor()
{
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
					Wait(100);
					Off(OUT_AB);
					break;
				}
				if (rightSens==1)
				{
					Off(OUT_AB);

					OnFwdReg(OUT_B, 30);
					Wait(SEC_1);

					rightSens = readSensor(IN_1);
					leftSens = readSensor(IN_3);

					if (rightSens==1 && leftSens==1)
					{
						Wait(100);
						Off(OUT_AB);
						break;
					}
				}
				if (leftSens==1)
				{
					Off(OUT_AB);

					OnFwdReg(OUT_A, 30);
					Wait(SEC_1);

					rightSens = readSensor(IN_1);
					leftSens = readSensor(IN_3);

					if (rightSens==1 && leftSens==1)
					{
						Wait(100);
						Off(OUT_AB);
						break;
					}
				}

	}
}
void dropBook() {
	 LcdPrintf(1,"Use the hand\n");
		 RotateMotor(OUT_C, 10, 90); //funkar 90 grader?
		 Wait(SEC_1);
		 RotateMotor(OUT_C, -10, 90); //onödigt men för att få tillbaka armen på ursprunglig plats (ser snyggt ut)
}
void backward90left()
{
	OnRevReg(OUT_A, 23);
	Wait(2500);
	Off(OUT_AB);
}
void forward25()
{
	Off(OUT_AB);
	OnFwdSync(OUT_AB, 50);
	Wait(SEC_10+111);
	Off(OUT_AB);
}
void rotate180()
{
	OnFwdReg(OUT_A, 15);
	OnRevReg(OUT_B, 15);
	Wait(3360);
	Off(OUT_AB);
}
