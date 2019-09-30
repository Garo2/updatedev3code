#include <stdio.h>
#include <ev3.h>

void rotateMotor(int l);
int findMinDistance();
void forward();
void touchSensor();

int main() {

	InitEV3();
	// setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);
    int indexTid = findMinDistance();
    int i;

    for(i = 0; i < indexTid; i++) {
        rotateMotor(i);
    }
    Off(OUT_A);

   // forward();

   // touchSensor();

    return 0;
}

int findMinDistance () {
    int distance;
    int minDis;
    int arrayDis[8];
    int indexTidForMinDis;
    int j;
   

    setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);

    for(j = 0; j < 9; j++) {
        rotateMotor(j);
        distance = readSensor(IN_4);
        arrayDis[j] = distance;
        LcdPrintf(1, "Avståndet Är: %d mm", arrayDis[j]);
    }

    minDis = arrayDis[0];
    for(j = 1; j<8; j++)
    {
        if(minDis > arrayDis[j])
        {
            minDis = arrayDis[j];
            indexTidForMinDis = j;
        }
    }

    return indexTidForMinDis;
}

void rotateMotor (int l) {
    LcdPrintf(1, "Turn Right! %d \n", l);
    OnFwdReg(OUT_A, 15);
    OnRevReg(OUT_B, 15);
    Wait(SEC_2 + MS_100);

}

void forward() {
	//framåt X m
    LcdPrintf(1, "Going Forward!\n");
    OnRevSync(OUT_AB,75);
    Wait(SEC_4);
}

void touchSensor() {
	setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);
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
