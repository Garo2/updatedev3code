#include <stdio.h>
#include <ev3.h>

int findMinDistance();
void spinRobot45(int l);
void forward();
void touchSensor();
void dropBook();

int main() {

	InitEV3();
		/*
		 --!!!--- TESTA TOUCH-SENSOR SAMTIDIGT SOM FORWARD ---!!!---
		 	       	   DENNA KOD FUNKAR EJ! snälla få den att funka:(</3
				   
		setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);
		int rightSensor = readSensor(IN_1);
		int leftSensor = readSensor(IN_3);
		while (rightSensor && leftSensor != 1) {
		    LcdPrintf(1, "Going Forward!\n");
		    OnRevSync(OUT_AB,30);
			if (rightSensor && leftSensor == 1) {
				Off(OUT_AB);
				LcdPrintf(1, "Båda touch sensor");
				Wait(SEC_1);
			}
			else if(rightSensor == 1) {
				Off(OUT_A);
				LcdPrintf(1, "Höger touch sensor");
				Wait(SEC_1);
			}
			else if (leftSensor == 1) {
				Off(OUT_B);
				LcdPrintf(1, "Vänster touch sensor");
				Wait(SEC_1);
			}
			else {
				LcdPrintf(1, "Ingen touch sensor");
				Wait(SEC_1);
			}
		}*/


//DETTA SKA EJ ÄNDRAS
    int indexTid = findMinDistance();
    int i;


    for(i = 0; i <= indexTid; i++) {
        rotateMotor(i);
    }
	
    Off(OUT_AB);
    Wait(SEC_2);

/* -- HÄR BÖRJAR PROBLEMET --
	försöka få touchSensor() att köras SAMTIDIGT som roboten åker framåt, t.ex. via forward()
	men motorerna måste isf kunnas stoppas i touchSensor(). Fundering: få touchSensor att returnera ett värde??
*/	
	
	forward(); //tills rightSensor && leftSensor == 1
	
	

// -- HÄR SLUTAR PROBLEMET --
	
//DETTA SKA EJ ÄNDRAS
    forward(); // måste vara 2,5 m

    //rotate90() beroende på vilket mål

    dropBook();

	FreeEV3();
    return 0;
}

//denna funkton funkar perfekt, rör ej!!! hehe :P
int findMinDistance () {
    int distance;
    int minDis;
    int arrayDis[8];
    int indexTidForMinDis;
    int j;
    int k;

    setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);

    for(j = 0; j <= 8; j++) {
        spinRobot45(j); //roboten spinner 45 * 8 = 360 grader
        distance = readSensor(IN_4);
        arrayDis[j] = distance;
        //LcdPrintf(1, "Avståndet Är: %d mm", arrayDis[j]);
    }

    minDis = arrayDis[0];
    for(k = 1; k<8; k++)
    {
        if(minDis > arrayDis[k])
        {
            //minDis = arrayDis[k];
            indexTidForMinDis = k;
        }
    }

    return indexTidForMinDis;
}

//roboten spinner 45 grader åt höger 
void spinRobot45(int l) {
    LcdPrintf(1, "Turning! %d\n", l);
    OnFwdReg(OUT_A, 16);
    OnRevReg(OUT_B, 16);
    Wait(SEC_2 + MS_350);

}

//roboten åker framåt på obestämd tid!! hitta tid för sträckan 2.5m
void forward() {
    LcdPrintf(1, "Going Forward!\n");
    OnRevSync(OUT_AB,30);
  //Wait(MIN_1? + SEC_?? + MS_??):
}

//denna funktion funkar om man kan köra denna + forward() samtidigt i main + stoppa motor i forward() i main
void touchSensor() {
	setAllSensorMode(TOUCH_PRESS, NO_SEN, TOUCH_PRESS, US_DIST_MM);
		int rightSensor = readSensor(IN_1);
		int leftSensor = readSensor(IN_3);

			if(rightSensor == 1){ 
				//Off(OUT_AB); behövs ja/nej??
				LcdPrintf(1,"Turn Right! \n");
				OnRevSync(OUT_B,23);
				Wait(SEC_7 + MS_500);

				if(rightSensor && leftSensor == 1){
					//Off(OUT_AB); behövs ja/nej??
					 LcdPrintf(1, "Going Backward! \n");
					    OnFwdSync(OUT_AB,75);
					    Wait(SEC_4);

					 LcdPrintf(1, "Turn 90 degrees! \n");
					    OnFwdReg(OUT_A, 44);
					    Wait(SEC_3 + MS_700 + MS_50);
				}
			}
			else if(leftSensor == 1){
				//Off(OUT_AB); behövs ja/nej??
					LcdPrintf(1,"Turn Left! \n");
					OnRevSync(OUT_A,23);
					Wait(SEC_7 + MS_500);

					if(rightSensor && leftSensor == 1){
						//Off(OUT_AB); behövs ja/nej??
						 LcdPrintf(1, "Going Backward! \n");
						   OnFwdSync(OUT_AB,75);
						   Wait(SEC_4);

						 LcdPrintf(1, "Turn 90 degrees! \n");
							OnFwdReg(OUT_A, 44);
							Wait(SEC_3 + MS_700 + MS_50);
					}
			}

			if(rightSensor && leftSensor == 1)
				{
					//Off(OUT_AB); behövs ja/nej??
					 LcdPrintf(1, "Going Backward! \n");
					  OnFwdSync(OUT_AB,75);
					  Wait(SEC_4);

					 LcdPrintf(1, "Turn 90 degrees!");
					   OnFwdReg(OUT_A, 44);
					   Wait(SEC_3 + MS_700 + MS_50);
				}
			//else fortsätt forward()
}

dropBook () {
	 LcdPrintf(1,"Use the hand\n");
		 RotateMotor(OUT_C, 10, 90); //funkar 90 grader?
		 Wait(SEC_2);
		 RotateMotor(OUT_C, 10, -90); //onödigt men för att få tillbaka armen på ursprunglig plats (ser snyggt ut)
}
