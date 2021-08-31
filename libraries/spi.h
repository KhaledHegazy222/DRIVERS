/*
	#######	Created By : Khaled Hegazy
	#######	File Name : spi.h
*/



// User Configuration
#ifndef Khaled
	#define __AVR_ATmega32__
#endif

#include "std_types.h"





// File Guard
#ifndef __SPI_H__
	#define __SPI_H__
 
 
 



	void spi_init_master(void);
	void spi_init_slave(void);
	void spi_send(u8 data);
	u8 spi_recieve(void);
	u8 spi_transmit(u8 data);


 
#endif
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
