/* 
	Created By: Khaled Hegazy
	File Name : main.c
*/


// User Configuration
#ifndef Khaled
	#define __AVR_ATmega32__
#endif




// Libraries Included
#include <util/delay.h>
#include "uart.h"
#include "gpio.h"



// Main Function
int main(void){

	UART_Init(9600);

	while(1){
		UART_SendTxt("Hello World");
		_delay_ms(1000);

	}

}