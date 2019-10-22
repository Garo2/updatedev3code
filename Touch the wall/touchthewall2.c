#include <stdio.h>
#include <ev3.h>

void rotateRobot(int l);
int findMinDistance();
void forward();
void touchSensor();
void rotateRobot();


int main()
{

	InitEV3();
	// setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);
    int indexTid = findMinDistance();
    int i;

    for(i = 0; i < indexTid; i++) {
        rotateRobot(i);
    }

    Off(OUT_AB);

   forward();

   touchSensor();

    return 0;
}
/*
 Vera 
*/
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
        LcdPrintf(1, "Avståndet Är: %d mm", arrayDis[j]);
    }

    minDis = arrayDis[0];
    for(k = 1; k<=15; k++)
    {
        if(minDis > arrayDis[k])
        {
            minDis = arrayDis[k];
            indexTidForMinDis = k;
        }
    }

    return indexTidForMinDis;
}
/*
 Garo
*/
void rotateRobot (int l) {
    LcdPrintf(1, "Turn Right! %d \n", l);
    OnFwdReg(OUT_A, 15);
    OnRevReg(OUT_B, 15);
    Wait(2100);

}
/*
 Vera
*/
void forward() {
	//framåt X m
    LcdPrintf(1, "Going Forward!\n");
    OnRevSync(OUT_AB,75);
    Wait(SEC_4);
}

void touchSensor() /*
 Rebecca och Garo
*/
{
	setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);
		int rightSens = readSensor(IN_1);
		int leftSens = readSensor(IN_3);

		OnRevSync(OUT_AB, 50);

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

					OnRevReg(OUT_B, 70);
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

					OnRevReg(OUT_A, 70);
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
} /*
 Garo
*/
void dropBook() {
	 LcdPrintf(1,"Use the hand\n");
		 RotateMotor(OUT_C, 10, 90); //funkar 90 grader?
		 Wait(SEC_2);
		 RotateMotor(OUT_C, 10, -90); //onödigt men för att få tillbaka armen på ursprunglig plats (ser snyggt ut)
}
	
