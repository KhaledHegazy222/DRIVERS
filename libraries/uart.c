/*
	#######	Created By : Khaled Hegazy
	#######	File Name : uart.c
*/
 
 
 
// User Configuration
#ifndef Khaled
	#define __AVR_ATmega32__
#endif
 
#include "uart.h"
#include "std_types.h"



void UART_Init(   u16 baud){


  /* Set baud rate */
  UBRRH_reg = (unsigned char)(baud>>8);
  UBRRL_reg = (unsigned char)baud;
  /* Enable receiver and transmitter */
  UCSRB_reg = (1<<UCSRB_RXEN)|(1<<UCSRB_TXEN);
  /* Set frame format: 8data, 2stop bit */
  UCSRC_reg = (1<<UCSRC_URSEL)|(1<<UCSRC_USBS)|(3<<UCSRC_UCSZ0);


}


void UART_SendChar(u8 data){
	

	/* Wait for empty transmit buffer */
	while ( !( UCSRA_reg & (1<<UCSRA_UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR_reg = data;
}

void UART_SendTxt(u8* data){
	u8 i = 0;
	do{
		UART_SendChar(data[i]);
	}
	while(data[i++]);

}



u8 UART_RecieveChar(void){

	/* Wait for data to be received */
	while ( !(UCSRA_reg & (1<<UCSRA_RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR_reg;

}




u8 * UART_RecieveTxt(void){
	static u8 ret[20];
	u8 i = 0;
	do{
		ret[i] = UART_RecieveChar();
	}
	while(ret[i++]);

	return ret;

}



 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
