/* 
	Created By: Khaled Hegazy
	File Name : main.c
*/

#ifndef Khaled
	#define __AVR_ATmega32__
#endif



#include "std_types.h"
#include "lcd.h"
#include "gpio.h"
#include "ext_int.h"


u8 seconds = 0;

u8 hours = 0;
u8 minutes = 0;
u8 days =  1;
u8 months = 1;
u16 years = 2021;



void min_inc(void){
	minutes++;
}
void hour_inc(void){
	hours++;
}

void reset(void){
	minutes = 0;
	hours = 0;
	days = 1;
	months = 1;
	years = 2021;
}




void present(char* text){
	upd();
	text[0] = (days/10)%10 + '0';
	text[1] = (days)%10 + '0';
	text[2] = '/';
	
	text[3] = (months/10)%10 + '0';
	text[4] = (months)%10 + '0';
	text[5] = '/';	
	
	text[6] = (years/1000)%10 + '0';
	text[7] = (years/100)%10 + '0';
	text[8] = (years/10) %10 + '0';
	text[9] = (years)%10 + '0';
	text[10] = ' ';
	
	text[11] = (hours/10)+ '0';
	text[12] = (hours%10)+ '0';
	text[13] = ':';
	text[14] = (minutes/10)+ '0';
	text[15] = (minutes%10)+ '0'; 
	text[16] = '\0';
}

void upd(void){
	minutes += seconds/60;
	seconds %= 60;
	hours += minutes/60;
	minutes %= 60;
	days += hours/24;
	hours %= 24;
	months += days/31;
	days %= 31;
	years += months/13;
	months %= 13;
	
	if(!days){
		days++;
	}
	if(!months){
		months++;
	}
	
}

int main(void){
	
	
	GPIO_SetPortDir(A,0xff);
	GPIO_SetPinDir(B,5,OUTPUT);
	GPIO_SetPinDir(B,6,OUTPUT);
	GPIO_SetPinDir(B,7,OUTPUT);
	GPIO_SetPinDir(B,2,INPUT);
	GPIO_SetPinDir(D,2,INPUT);
	GPIO_SetPinDir(D,3,INPUT);
	
	LCD_Init();
	// INT0 For Reset
	EXT_EnableExtInt(EXT_INT_0,FALLIN_EDGE,reset);
	// INT1 For Increasing Minutes
	EXT_EnableExtInt(EXT_INT_1,FALLIN_EDGE,min_inc);
	// INT2 For Increasing Hours
	EXT_EnableExtInt(EXT_INT_2,FALLIN_EDGE,hour_inc);
	
	// Set The Global Interrupt 
	EXT_InitGlobalInterrupts();
	u8 text[17];
	u8 not_cleared = 1;
    while (1){		
		
		for(u32 i = 0 ;i<35;i++){ // Approximation of 1second
			if(minutes && not_cleared){
 				minutes = 0;
				not_cleared = 0;
			}
			
			present(text);
			
			LCD_WriteTxtAt(text,1,1);
		}
		seconds++;

    }
}

