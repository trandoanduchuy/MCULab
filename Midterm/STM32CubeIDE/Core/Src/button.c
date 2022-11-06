/*
 * button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Huy
 */
#include "button.h"
//ButtonReset
// Normal Press
int ButtonResetNormal_flag = 0;
int isButtonResetPressedNormal(){
	if(ButtonResetNormal_flag == 1){
		ButtonResetNormal_flag = 0;
		return 1;
	}
	return 0;
}
void subKeyResetProcessNormal(){
	ButtonResetNormal_flag = 1;
}

// getKeyInput
int KeyResetReg0 = NORMAL_STATE;
int KeyResetReg1 = NORMAL_STATE;
int KeyResetReg2 = NORMAL_STATE;
int KeyResetReg3 = NORMAL_STATE;
int TimerForKeyResetPress = 200;

void getKeyResetInput(){
	KeyResetReg0 = KeyResetReg1;
	KeyResetReg1 = KeyResetReg2;
	KeyResetReg2 = HAL_GPIO_ReadPin(ButtonReset_GPIO_Port, ButtonReset_Pin);

	if(KeyResetReg0 == KeyResetReg1 && KeyResetReg1 == KeyResetReg2){
		if(KeyResetReg3 != KeyResetReg2){
			//Normal Press
			KeyResetReg3 = KeyResetReg2;
			if(KeyResetReg2 == PRESSED_STATE){
				subKeyResetProcessNormal();
				TimerForKeyResetPress = 200;
			}
		}
		else{
			//Long Press
			TimerForKeyResetPress--;
			if(TimerForKeyResetPress == 0){
				KeyResetReg3 = NORMAL_STATE;
			}
		}
	}
}

//ButtonInc
// Normal Press
int ButtonIncNormal_flag = 0;
int isButtonIncPressedNormal(){
	if(ButtonIncNormal_flag == 1){
		ButtonIncNormal_flag = 0;
		return 1;
	}
	return 0;
}
void subKeyIncProcessNormal(){
	ButtonIncNormal_flag = 1;
}


//Long Press 3
int ButtonIncLong3_flag = 0;
int isButtonIncPressedLong3(){
	if(ButtonIncLong3_flag == 1){
		ButtonIncLong3_flag = 0;
		return 1;
	}
	return 0;
}
void subKeyIncProcesslong3(){
	ButtonIncLong3_flag = 1;
}

//Long Press 1
int ButtonIncLong1_flag = 0;
int isButtonIncPressedLong1(){
	if(ButtonIncLong1_flag == 1){
		ButtonIncLong1_flag = 0;
		return 1;
	}
	return 0;
}
void subKeyIncProcessLong1(){
	ButtonIncLong1_flag = 1;
}


//getKeyInput
int KeyIncReg0 = NORMAL_STATE;
int KeyIncReg1 = NORMAL_STATE;
int KeyIncReg2 = NORMAL_STATE;
int KeyIncReg3 = NORMAL_STATE;
int TimerForKeyIncPress3 = 300;
int TimerForKeyIncPress1 = 100;

void getKeyIncInput(){
	KeyIncReg0 = KeyIncReg1;
	KeyIncReg1 = KeyIncReg2;
	KeyIncReg2 = HAL_GPIO_ReadPin(ButtonInc_GPIO_Port, ButtonInc_Pin);

	if(KeyIncReg0 == KeyIncReg1 && KeyIncReg1 == KeyIncReg2){
		if(KeyIncReg3 != KeyIncReg2){
			// Normal Press
			KeyIncReg3 = KeyIncReg2;
			if(KeyIncReg2 == PRESSED_STATE){
				subKeyIncProcessNormal();
				TimerForKeyIncPress3 = 300;
				TimerForKeyIncPress1 = 100;
			}
		}
		else{
			// Long Press
			TimerForKeyIncPress1--;
			if(TimerForKeyIncPress1 == 0){
				if(KeyIncReg2 == PRESSED_STATE){
					subKeyIncProcessLong1();
				}
				TimerForKeyIncPress1 = 100;
			}

			TimerForKeyIncPress3--;
			if(TimerForKeyIncPress3 == 0){
				if(KeyIncReg2 == PRESSED_STATE){
					subKeyIncProcesslong3();
				}
				TimerForKeyIncPress3 = 300;
			}
		}
	}
}

//ButtonDec
//Normal Press
int ButtonDecNormal_flag = 0;
int isButtonDecPressedNormal(){
	if(ButtonDecNormal_flag == 1){
		ButtonDecNormal_flag = 0;
		return 1;
	}
	return 0;
}
void subKeyDecProcessNormal(){
	ButtonDecNormal_flag = 1;
}

//Long Press 3
int ButtonDecLong3_flag = 0;
int isButtonDecPressedLong3(){
	if(ButtonDecLong3_flag == 1){
		ButtonDecLong3_flag = 0;
		return 1;
	}
	return 0;
}
void subKeyDecProcesslong3(){
	ButtonDecLong3_flag = 1;
}

//Long Press 1
int ButtonDecLong1_flag = 0;
int isButtonDecPressedLong1(){
	if(ButtonDecLong1_flag == 1){
		ButtonDecLong1_flag = 0;
		return 1;
	}
	return 0;
}
void subKeyDecProcessLong1(){
	ButtonDecLong1_flag = 1;
}

// getKeyInput
int KeyDecReg0 = NORMAL_STATE;
int KeyDecReg1 = NORMAL_STATE;
int KeyDecReg2 = NORMAL_STATE;
int KeyDecReg3 = NORMAL_STATE;
int TimerForKeyDecPress3 = 300;
int TimerForKeyDecPress1 = 100;

void getKeyDecInput(){
	KeyDecReg0 = KeyDecReg1;
	KeyDecReg1 = KeyDecReg2;
	KeyDecReg2 = HAL_GPIO_ReadPin(ButtonDec_GPIO_Port, ButtonDec_Pin);

	if(KeyDecReg0 == KeyDecReg1 && KeyDecReg1 == KeyDecReg2){
		if(KeyDecReg3 != KeyDecReg2){
			//Normal Press
			KeyDecReg3 = KeyDecReg2;
			if(KeyDecReg2 == PRESSED_STATE){
				subKeyDecProcessNormal();
				TimerForKeyDecPress3 = 300;
				TimerForKeyDecPress1 = 100;
			}
		}
		else{
			//Long Press
			TimerForKeyDecPress1--;
			if(TimerForKeyDecPress1 == 0){
				if(KeyDecReg2 == PRESSED_STATE){
					subKeyDecProcessLong1();
				}
				TimerForKeyDecPress1 = 100;
			}

			TimerForKeyDecPress3--;
			if(TimerForKeyDecPress3 == 0){
				if(KeyDecReg2 == PRESSED_STATE){
					subKeyDecProcesslong3();
				}
				TimerForKeyDecPress3 = 300;
			}
		}
	}
}
