#define  F_CPU 1000000
#include <util/delay.h>


#include "std_types.h"
#include "gpio.h"
#include "bit_math.h"
#include "keypad.h"

u8 KPAD_Scan(void){
	static u8 current = 1;
	GPIO_SetPinVal(C,4,get_bit(~current,0));
	GPIO_SetPinVal(C,5,get_bit(~current,1));
	GPIO_SetPinVal(C,6,get_bit(~current,2));
	GPIO_SetPinVal(C,7,get_bit(~current,3));
	
	if(current == 0b00001000){
		current = 1;
	}
	else{
		current <<= 1;
	}
	
	_delay_ms(50);
	
	
	u8 value = GPIO_GetPortVal(C);
	
	
	
	switch(value){
		case 0b11101110 : return '7';
		case 0b11101101 : return '4';
		case 0b11101011 : return '1';
		case 0b11100111 : return 'O';
		
		case 0b11011110 : return '8';
		case 0b11011101 : return '5';
		case 0b11011011 : return '2';
		case 0b11010111 : return '0';
		
		case 0b10111110 : return '9';
		case 0b10111101 : return '6';
		case 0b10111011 : return '3';
		case 0b10110111 : return '=';
		
		case 0b01111110 : return '/';		
		case 0b01111101 : return 'x';
		case 0b01111011 : return '-';
		case 0b01110111 : return '+';
	}
	
	
	
	return 0;

	
}