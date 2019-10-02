#include <stdio.h>
#include <ev3.h>

void rotateMotor();
int findMinDistance();
void forward();
void touchSensor();

int main() {

	InitEV3();
    setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);


    int indexTid = findMinDistance();
    int i;

    for(i = 0; i <= indexTid; i++) {
        LcdPrintf(1, "%d, ", i);
        rotateMotor();
    }

    forward();


   // Off(OUT_A);

	FreeEV3();
    return 0;
}



void rotateMotor () {
	  OnFwdReg(OUT_B, 30);
	    OnRevReg(OUT_A, 30);
	    Wait(MS_600 + MS_50);
}

int findMinDistance () {
    int minDis;
    int arrayDis[15];
    int indexTidForMinDis;
    int j;


    setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);
    readSensor(IN_4);

    for(j = 0; j <= 15; j++) {
        rotateMotor();
        arrayDis[j] = readSensor(IN_4);
        LcdPrintf(1, "%d: %d ", j, arrayDis[j]);
    }

    minDis = arrayDis[0];

    for(j = 1; j <= 15; j++)
    {
        if(minDis > arrayDis[j])
        {
            minDis = arrayDis[j];
            indexTidForMinDis = j;
        }
    }
    return indexTidForMinDis;
}

void forward() {
	//framåt X m
    LcdPrintf(1, "Going Forward!\n");
    OnRevSync(OUT_AB,75);
    Wait(SEC_20);
}

