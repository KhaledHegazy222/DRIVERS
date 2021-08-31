/*
	#######	Created By : Khaled Hegazy
	#######	File Name : i2c.c
*/



// User Configuration
#ifndef Khaled
	#define __AVR_ATmega32__
#endif



#include "i2c.h"
#include <avr/io.h>


void I2C_Init_master(u8 bit_rate){
	TWSR = 0x00;
	TWBR = bit_rate;
	TWCR = (1 << TWINT) | (1 << TWEN);
}




void I2C_Init_slave(u8 slave_address , u8 bit_rate){
	TWBR = bit_rate;
	TWAR = slave_address << 1;
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	
}




void I2C_Start(void){
	
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
	while (!(TWCR & (1<<TWINT)));
}


void I2C_Stop(void){
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}


void I2C_Write(u8 data){
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1<<TWINT)));
}




u8 I2C_Read(void){
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
	while(!(TWCR&(1<<TWINT)));
	return TWDR;
}



void I2C_Lestin(void){
	while(!(TWCR&(1<<TWINT)));
}


u8 I2C_ReadACK(void){
	
  	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);  
  
  	while (!(TWCR & (1 << TWINT)));
  
  	return TWDR;
}
u8 I2C_ReadNACK(void){
	TWCR = (1 << TWINT) | (1 << TWEN);
  	while (!(TWCR & (1 << TWINT)));
  	return TWDR;
}
u8 I2C_GetStatus(void){
	unsigned char status;
	status = TWSR & 0xF8;
	return status;
}

























