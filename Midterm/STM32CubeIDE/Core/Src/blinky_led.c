/*
 * blinky_led.c
 *
 *  Created on: Nov 8, 2022
 *      Author: Huy
 */
#include "blinky_led.h"
#include "main.h"

void blinky_led_run(){
	switch(signal){
	case ON:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);

		if(timer2_flag == 1){
			signal = OFF;
			setTimer2(1000);
		}
		break;
	case OFF:
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);

		if(timer2_flag == 1){
			signal = ON;
			setTimer2(1000);
		}
		break;
	default:
		break;
	}
}
