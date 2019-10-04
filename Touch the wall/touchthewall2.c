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

int findMinDistance () {
    int distance;
    int minDis;
    int arrayDis[8];
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

void rotateRobot (int l) {
    LcdPrintf(1, "Turn Right! %d \n", l);
    OnFwdReg(OUT_A, 15);
    OnRevReg(OUT_B, 15);
    Wait(2100);

}

void forward() {
	//framåt X m
    LcdPrintf(1, "Going Forward!\n");
    OnRevSync(OUT_AB,75);
    Wait(SEC_4);
}

void touchSensor()
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
}
void dropBook() {
	 LcdPrintf(1,"Use the hand\n");
		 RotateMotor(OUT_C, 10, 90); //funkar 90 grader?
		 Wait(SEC_2);
		 RotateMotor(OUT_C, 10, -90); //onödigt men för att få tillbaka armen på ursprunglig plats (ser snyggt ut)
}
	/*setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);
		readSensor(IN_1);
		readSensor(IN_3);
			if(readSensor(IN_1) == 1){
				LcdPrintf(1,"Turn Right!n");
				OnRevSync(OUT_B,23);
				Wait(SEC_7 + MS_500);

				if(readSensor(IN_1) && readSensor(IN_3) == 1){
					Off(OUT_B);
					 LcdPrintf(1, "Going Backward!\n");
					    OnFwdSync(OUT_AB,75);
					    Wait(SEC_4);

					 LcdPrintf(1, "Turn 90 degrees!\n");
					    OnFwdReg(OUT_A, 44);
					    Wait(SEC_3 + MS_700 + MS_50);
				}
			}
			else if(readSensor(IN_3) == 1){
					LcdPrintf(1,"Turn Left!\n");
					OnRevSync(OUT_A,23);
					Wait(SEC_7 + MS_500);

					if(readSensor(IN_1) && readSensor(IN_3) == 1){
						Off(OUT_B);
						 LcdPrintf(1, "Going Backward!\n");
						   OnFwdSync(OUT_AB,75);
						   Wait(SEC_4);

						 LcdPrintf(1, "Turn 90 degrees!\n");
							OnFwdReg(OUT_A, 44);
							Wait(SEC_3 + MS_700 + MS_50);
					}
			}

			if(readSensor(IN_1) && readSensor(IN_3) == 1)
				{
					Off(OUT_AB);
					 LcdPrintf(1, "Going Backward!\n");
					  OnFwdSync(OUT_AB,75);
					  Wait(SEC_4);

					 LcdPrintf(1, "Turn 90 degrees!");
					   OnFwdReg(OUT_A, 44);
					   Wait(SEC_3 + MS_700 + MS_50);
				}
}
*/
