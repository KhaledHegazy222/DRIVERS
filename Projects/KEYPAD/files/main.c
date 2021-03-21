/* 
	Created By: Khaled Hegazy
	File Name : main.c
*/

#ifndef Khaled
	#define __AVR_ATmega32__
#endif



#include "std_types.h"
#include "bit_math.h"
#include "lcd.h"
#include "gpio.h"

int main(void){
	GPIO_SetPortDir(A,0xff);
	GPIO_SetPortDir(B,0x07);
	GPIO_SetPortDir(C,0xf0);
	GPIO_SetPortVal(C,0xff);
	
	LCD_Init();
	
	
    while (1){
		u8 c = KPAD_Scan();
		if(c != 0){
			LCD_WriteChar(c);
		}
    }
}

