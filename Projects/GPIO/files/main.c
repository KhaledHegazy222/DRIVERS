/* 
	Created By: Khaled Hegazy
	File Name : main.c
*/

#ifndef Khaled
	#define __AVR_ATmega32__
#endif

#include "gpio.h"
#include "std_types.h"
#include <util/delay.h>

void display(u8 x){

	// Common Anode Seven Segment Display
	u8 ssd[10] = {
		0x03,//0
		0x9F,//1
		0x25,//2
		0x0D,//3
		0x99,//4
		0x49,//5
		0x41,//6
		0x1F,//7
		0x01,//8
		0x09 //9
	};


	GPIO_SetPinVal(B,PIN_0,HIGH);
	GPIO_SetPortVal(A,ssd[x%10]);
    _delay_ms(50);
	GPIO_SetPinVal(B,PIN_0,LOW);
	


	GPIO_SetPinVal(B,PIN_1,HIGH);
	GPIO_SetPortVal(A,ssd[x/10]);
    _delay_ms(50);
	GPIO_SetPinVal(B,PIN_1,LOW);

}



int main(void){

	GPIO_SetPortDir(A,0xff);

	GPIO_SetPortDir(B,0xff);
	
	GPIO_SetPinDir(B,PIN_2,INPUT);
	
	GPIO_SetPinDir(B,PIN_3,INPUT);
	
	GPIO_SetPinVal(B,PIN_1,HIGH);
	
	u8 cnt = 0;
	while(1){
		u8 inc = 0;
		while(GPIO_GetPinVal(B,PIN_2) == 1){
			inc = 1;
			display(cnt);
		}
		
		while(GPIO_GetPinVal(B,PIN_3)==1){
			cnt = 0;
			display(cnt);
		}
		
		if(inc){
			cnt++;
		}
		display(cnt);
	}
}

/*
	i called display function 3 times to guarantee that the both seven segment keep switching when i press any button :)
*/


