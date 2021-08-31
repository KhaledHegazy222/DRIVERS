/*
	#######	Created By : Khaled Hegazy
	#######	File Name : spi.c
*/



// User Configuration
#ifndef Khaled
	#define __AVR_ATmega32__
#endif

#include "spi.h"

#include <avr/io.h>

#define SS 		4
#define MOSI 	5
#define MISO 	6 
#define SCK 	7



void spi_init_master(void){
	DDRB = (1 << MOSI) 	| 	(1 << SCK);
	SPCR = (1 << SPE) 	|	(1 << MSTR);
}
void spi_init_slave(void){
	DDRB = (1 << MISO);
	SPCR = (1 << SPE);
}
void spi_send(u8 data){
	SPDR = data;
	while(! (SPSR & (1 << SPIF) ));
}
u8 spi_recieve(void){	
	SPDR = 0x55;
	while(! (SPSR & (1 << SPIF) ));
	return SPDR;
}
u8 spi_transmit(u8 data){
	SPDR = data;
	while(! (SPSR & (1 << SPIF) ));
	return SPDR;
}



































