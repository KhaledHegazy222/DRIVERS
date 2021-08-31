/*
	#######	Created By : Khaled Hegazy
	#######	File Name : i2c.h
*/



// User Configuration
#ifndef Khaled
	#define __AVR_ATmega32__
#endif

#include "std_types.h"


// File Guard
#ifndef __I2C_H__
	#define __I2C_H__
 
		
	void I2C_Init_master(u8 bit_rate);
	void I2C_Init_slave(u8 slave_address , u8 bit_rate);
	void I2C_Start(void);
	void I2C_Stop(void);
	void I2C_Write(u8 data);
	
	u8 I2C_Read(void);
	
	void I2C_Lestin(void);
	u8 I2C_ReadACK(void);
	u8 I2C_ReadNACK(void);
	u8 I2C_GetStatus(void);





 
#endif
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
