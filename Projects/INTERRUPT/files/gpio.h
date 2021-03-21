/* 								 
	Created By 	: 	Khaled Hegazy 	
	File Name	:	gpio.h 			
*/ 								
	 								
	 								
#ifndef Khaled						
	#define __AVR_ATmega32__		
#endif								
	 								
	 												
#include "std_types.h"			
	 								
#ifndef __GPIO_H__
    #define __GPIO_H__

	 								
	 								
    #define PIND *((volatile u8*)(0x30))
    #define DDRD *((volatile u8*)(0x31))
    #define PORTD *((volatile u8*)(0x32))

    #define PINC *((volatile u8*)(0x33))
    #define DDRC *((volatile u8*)(0x34))
    #define PORTC *((volatile u8*)(0x35))

    #define PINB *((volatile u8*)(0x36))
    #define DDRB *((volatile u8*)(0x37))
    #define PORTB *((volatile u8*)(0x38))

    
    #define PINA *((volatile u8*)(0x39))
    #define DDRA *((volatile u8*)(0x3A))
    #define PORTA *((volatile u8*)(0x3B))




    void GPIO_SetPortDir(u8 port_num,u8 port_val);
    void GPIO_SetPinDir (u8 port_num , u8 pin_num,u8 pin_dir);
    void GPIO_SetPortVal(u8 port_num,u8 port_val);
    void GPIO_SetPinVal (u8 port_num , u8 pin_num , u8 pin_val);
    u8 GPIO_GetPortVal(u8 port_num);
    u8 GPIO_GetPinVal(u8 port_num, u8 pin_num);
    void GPIO_SetPullUpPin(u8 port_num , u8 pin_num);


	// PORTS 
	#define A 1
	#define B 2
	#define C 3
	#define D 4

    #define OUTPUT 1
    #define INPUT 0

    #define HIGH 1
    #define LOW 0

    #define PIN_0 0
    #define PIN_1 1
    #define PIN_2 2
    #define PIN_3 3
    #define PIN_4 4
    #define PIN_5 5
    #define PIN_6 6
    #define PIN_7 7

			
	 								
	 													
	 								
	 								
	 								
	 								
	 								
#endif								
