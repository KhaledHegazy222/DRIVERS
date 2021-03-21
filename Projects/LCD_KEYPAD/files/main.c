/* 
	Created By: Khaled Hegazy
	File Name : main.c
*/

#ifndef Khaled
	#define __AVR_ATmega32__
#endif

#include <util/delay.h>



#include "lcd.h"
#include "keypad.h"
#include "gpio.h"
#include "bit_math.h"
#include "std_types.h"





int str_eq(u8 * first,u8 * second){
	u8 i = 0;
	for(;first[i] && second[i];i++){
		if(first[i] != second[i]){
			return 0;
		}
	}
	if(first[i] == '\0' && second[i] == '\0'){
		return 1;
	}
	return 0;
}


void start(void){
	LCD_WriteTxtAt("Enter PassWord",1,1);
	LCD_MoveCursor(2,4);
}


int main(void){
	
	GPIO_SetPortDir(A,0xff);
	GPIO_SetPortDir(B,0x07);
	GPIO_SetPortDir(C,0xf0);
	
	
	GPIO_SetPullUpPin(C,0);
	GPIO_SetPullUpPin(C,1);
	GPIO_SetPullUpPin(C,2);
	GPIO_SetPullUpPin(C,3);
	
	
	
	
	LCD_Init();
	u8 Pass[20] = {0};
	u8 idx = 0;
	start();
	 while (1){
		 u8 read = KPAD_Scan();
		 if(read != 0 && read != 'O'){
			 
			 Pass[idx++] = read;
			 LCD_WriteChar(read);
		 }
		 else if(read == 'O'){
			 if(str_eq(Pass,"1234")){
				LCD_ClearScreen();
				LCD_WriteTxtAt("Welcome !",1,4);
				while(1); // Wait Forever
			 }
			 else{
				LCD_ClearScreen();
				LCD_WriteTxtAt("Wrong Pass",1,4);
				_delay_ms(200);// Wait And Try Again
				idx = 0;
				start();
			 }
		 }
		 
    }
}

