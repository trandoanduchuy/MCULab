/*
 * fsm_step1.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Huy
 */
#include "fsm_step1.h"

void fsm_step1_run(){
	switch(status){
	case INIT:
		status = NORMAL_COUNTDOWN;
		setTimer1(1000);
		break;
	case NORMAL_COUNTDOWN:
		display7SEG(counter);

		if(timer1_flag == 1){
			status = NORMAL_COUNTDOWN;
			if(counter > 0) counter--;
			else if(counter == 0) counter = 9;
			setTimer1(1000);
		}

		//Normal Press
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
		break;
	case SETTING1:
		display7SEG(counter);
		if(timer1_flag == 1){
			status = NORMAL_COUNTDOWN;
			setTimer1(1000);
		}
		//Normal Press
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

	}
}

