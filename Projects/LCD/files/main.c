/* 
	Created By: Khaled Hegazy
	File Name : main.c
*/

#ifndef Khaled
	#define __AVR_ATmega32__
#endif




#include "lcd.h"
#include "std_types.h"
#include "gpio.h"





u8 Word[4][8] = {
	{
		0b00000100,
		0b00000000,
		0b00001110,
		0b00000001,
		
		0b00000001,
		0b00011111,
		0b00000000,
		0b00000000
	},
	{
		0b00000000,
		0b00000100,
		0b00000100,	
		0b00000100,
		
		0b00000100,
		0b00000111,
		0b00000000,
		0b00000000
		
	},
	{
		0b00000000,
		0b00000100,
		0b00000100,
		0b00000100,
		
		0b00000100,
		0b00011100,
		0b00000000,
		0b00000000
	},
	{
		0b00000000,
		0b00000000,
		0b00000010,
		0b00000010,
		
		0b00000010,
		0b00011111,
		0b00000000,
		0b00000000
	}
};

int main(void){
	GPIO_SetPortDir(A,0xff);
	GPIO_SetPortDir(B,0xff);
	LCD_Init();
	LCD_AddCustom(Word[0],1);
	LCD_AddCustom(Word[1],2);
	LCD_AddCustom(Word[2],3);
	LCD_AddCustom(Word[3],4);
	LCD_MoveCursor(1,13);
	LCD_DrawCustom(4);
	LCD_DrawCustom(3);
	LCD_DrawCustom(2);
	LCD_DrawCustom(1);
	
	
	
	while (1);
}

