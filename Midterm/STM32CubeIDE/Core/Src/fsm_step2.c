/*
 * fsm_step2.c
 *
 *  Created on: Nov 6, 2022
 *      Author: Huy
 */
#include "fsm_step2.h"

void fsm_step2_run(){
	switch(status){
	case SETTING2:
		display7SEG(counter);

		if(timer1_flag == 1){
			status = NORMAL_COUNTDOWN;
			setTimer1(1000);
		}

		//Normall Press
		if(isButtonResetPressedNormal() == 1){
			status = SETTING1;
			counter = 0;
			setTimer1(10000);
		}
		if(isButtonIncPressedNormal() == 1){
			status = SETTING1;
			if(counter < 9) counter++;
			else if(counter == 9) counter = 0;
			setTimer1(10000);
		}
		if(isButtonDecPressedNormal() == 1){
			status = SETTING1;
			if(counter > 0) counter--;
			else if(counter == 0) counter = 9;
			setTimer1(10000);
		}
		//Long Press
		if(isButtonIncPressedLong1() == 1){
			status = SETTING2;
			if(counter < 9) counter++;
			else if(counter == 9) counter = 0;
			setTimer1(10000);
		}
		if(isButtonDecPressedLong1() == 1){
			status = SETTING2;
			if(counter > 0) counter--;
			else if(counter == 0) counter = 9;
			setTimer1(10000);
		}
		break;
	default:
		break;
	}
}

