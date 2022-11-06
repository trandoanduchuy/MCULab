/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Huy
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButtonResetPressedNormal();
int isButtonIncPressedNormal();
int isButtonDecPressedNormal();
int isButtonIncPressedLong3();
int isButtonIncPressedLong1();
int isButtonDecPressedLong3();
int isButtonDecPressedLong1();


void getKeyResetInput();
void getKeyIncInput();
void getKeyDecInput();

#endif /* INC_BUTTON_H_ */
