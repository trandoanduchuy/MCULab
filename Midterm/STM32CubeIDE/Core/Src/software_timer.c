/*
 * software_timer.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Huy
 */
#include "software_timer.h"

int timer1_flag = 0;
int timer1_counter = 0;
int timer2_flag = 0;
int timer2_counter = 0;

int TIMER_CYCLE = 10;

void setTimer1(int duration){
	timer1_counter = duration/TIMER_CYCLE;
	timer1_flag = 0;
}

void setTimer2(int duration){
	timer2_counter = duration/TIMER_CYCLE;
	timer2_flag = 0;
}

void timerRun(){
	//timer1
	if(timer1_counter > 0){
		timer1_counter--;
		if(timer1_counter == 0) timer1_flag = 1;
	}

	//timer2
	if(timer2_counter > 0){
		timer2_counter--;
		if(timer2_counter == 0) timer2_flag = 1;
	}
}
