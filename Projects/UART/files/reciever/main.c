/* 
	Created By: Khaled Hegazy
	File Name : main.c
*/


// User Configuration
#ifndef Khaled
	#define __AVR_ATmega32__
#endif




// Libraries Included
#include "gpio.h"
#include "uart.h"
#include "lcd.h"
#include <util/delay.h>




// Main Function
int main(void){

	UART_Init(9600);
	LCD_Init4();
	while(1){
		u8 * data = UART_RecieveTxt();
		LCD_WriteTxt4(data);
		LCD_MoveCursor4(1,1);
		_delay_ms(1000);
		
		
	}

}