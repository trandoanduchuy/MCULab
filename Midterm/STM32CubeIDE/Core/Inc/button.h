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
//ButtonReset
int isButtonResetPressedNormal();
//ButtonInc
int isButtonIncPressedNormal();
int isButtonIncPressedLong3();
int isButtonIncPressedLong1();
//ButtonDec
int isButtonDecPressedNormal();
int isButtonDecPressedLong3();
int isButtonDecPressedLong1();
//getkeyInput
void getKeyResetInput();
void getKeyIncInput();
void getKeyDecInput();

#endif /* INC_BUTTON_H_ */
