/*
	#######	Created By : Khaled Hegazy
	#######	File Name : uart.c
*/
 
 
 
// User Configuration
#ifndef Khaled
	#define __AVR_ATmega32__
#endif
 
#include "uart.h"




void UART_Init(u16 baud){


  /* Set baud rate */
  UBRRH_reg = (unsigned char)(baud>>8);
  UBRRL_reg = (unsigned char)baud;
  /* Enable receiver and transmitter */
  UCSRB_reg = (1<<UCSRB_RXEN)|(1<<UCSRB_TXEN);
  /* Set frame format: 8data, 2stop bit */
  UCSRC_reg = (1<<UCSRC_URSEL)|(1<<UCSRC_USBS)|(3<<UCSRC_UCSZ0);


}
void UART_Transmit(u8 data){
	

	/* Wait for empty transmit buffer */
	while ( !( UCSRA_reg & (1<<UCSRA_UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR_reg = data;
}


u8 UART_Recieve(void){

	/* Wait for data to be received */
	while ( !(UCSRA_reg & (1<<UCSRA_RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR_reg;

}




 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
