/*
	#######	Created By : Khaled Hegazy
	#######	File Name : uart.h
*/
 
 
 
// User Configuration
#ifndef Khaled
	#define __AVR_ATmega32__
#endif
 
 
#include "std_types.h"



// File Guard
#ifndef __UART_H__
	#define __UART_H__
 


// =================================================> Registers <=================================================
	
 	#define UCSRA_reg       (* ( (volatile u8 *) 0x2B ))    // USART Control and Status Register A – UCSRA
 	#define UCSRB_reg       (* ( (volatile u8 *) 0x2A ))    // USART Control and Status Register A – UCSRA
 	#define UCSRC_reg       (* ( (volatile u8 *) 0x40 ))    // USART Control and Status Register A – UCSRA
 	#define UBRRL_reg       (* ( (volatile u8 *) 0x29 ))    // USART Baud Rate Low Register – UBRRL
 	#define UBRRH_reg       (* ( (volatile u8 *) 0x40 ))    // USART Baud Rate High Register – UBRRH
	#define UDR_reg       	(* ( (volatile u8 *) 0x2C ))    // USART I/O Data Register – UDR




// =================================================> Bits <=================================================


	#define UCSRA_RXC             	7       // Timer/Counter0 Overflow Interrupt Enable
	#define UCSRA_TXC             	6       // Timer/Counter0 Overflow Interrupt Enable
	#define UCSRA_UDRE             	5       // Timer/Counter0 Overflow Interrupt Enable

	#define UCSRB_RXEN             	4       // Timer/Counter0 Overflow Interrupt Enable
	#define UCSRB_TXEN             	3       // Timer/Counter0 Overflow Interrupt Enable
	#define UCSRB_UCSZ2             2       // Timer/Counter0 Overflow Interrupt Enable

	#define UCSRC_URSEL             7       // Timer/Counter0 Overflow Interrupt Enable
	#define UCSRC_UPM1              5       // Timer/Counter0 Overflow Interrupt Enable
	#define UCSRC_UPM0	            4       // Timer/Counter0 Overflow Interrupt Enable
	#define UCSRC_USBS           	3       // Timer/Counter0 Overflow Interrupt Enable
	#define UCSRC_UCSZ1             2       // Timer/Counter0 Overflow Interrupt Enable
	#define UCSRC_UCSZ0             1       // Timer/Counter0 Overflow Interrupt Enable
	




typedef enum{
	NO_PARITY ,
	EVEN_PARITY ,
	ODD_PARITY ,
}PARITY_BIT;

typedef enum{
	BIT_5 ,
	BIT_6 ,
	BIT_7 ,
	BIT_8 
}CHAR_SIZE;


// =================================================> Functions <=================================================


	void UART_Init(u16 baud);
	

	void UART_SendChar(u8 data);
	void UART_SendTxt(u8* data);

	u8 UART_RecieveChar(void);
	u8 * UART_RecieveTxt(void);
 
 
#endif
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
