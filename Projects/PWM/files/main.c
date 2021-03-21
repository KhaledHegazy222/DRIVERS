/* 
	Created By: Khaled Hegazy
	File Name : main.c
*/

#ifndef Khaled
	#define __AVR_ATmega32__
#endif


#include "pwm.h"
#include "gpio.h"
int main(void){
	// Set OC0 as Output
	GPIO_SetPinDir(B,PIN_3,OUTPUT);

	// Set OC1A as Output
	GPIO_SetPinDir(D,PIN_5,OUTPUT);
	// Set OC2 as Output
	GPIO_SetPinDir(D,PIN_7,OUTPUT);
	
	PWM_InitTimer0();
	PWM_InitTimer1();
	PWM_InitTimer2();
	
	PWM_StartTimer0();
	PWM_StartTimer1();
	PWM_StartTimer2();
	
	PWM_GenerateTimer0(100);
	PWM_GenerateTimer1(70);
	PWM_GenerateTimer2(50);

	
	
    while (1){
    }
}

