/* 								 
	Created By 	: 	Khaled Hegazy 	
	File Name	:	bit_math.h 			
*/ 								
	 								
	 								
#ifndef Khaled						
	#define __AVR_ATmega32__		
#endif								
	 								
	 						

#ifndef __BIT_MATH_H__
	#define __BIT_MATH_H__
		
	 								
	 				
	#define set_bit(port,bit) (port|=(1<<bit))
	#define clear_bit(port,bit) (port&=~(1<<bit))
	#define toggle_bit(port,bit) (port^=(1<<bit))
	#define assign_port(port,val) (port=val)
	#define get_bit(port,bit) ((port&(1<<bit))!=0)				
	 								
	 								
	 												
	 								
	 								
	 								
	 								
	 								
#endif								
