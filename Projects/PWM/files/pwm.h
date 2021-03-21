/* 								 
	Created By 	: 	Khaled Hegazy 	
	File Name	:	pwm.h 			
*/ 								
	 								
	 								
#ifndef Khaled						
	#define __AVR_ATmega32__		
#endif								
	 													
	 						
#include "std_types.h"		
	 						

#ifndef __PWM_H__
	#define __PWM_H__
	
	 								
	 								
	 								 								
	 						
	void PWM_InitTimer0();
	void PWM_StartTimer0();	
	void PWM_GenerateTimer0(u16 d_cycle);

	void PWM_InitTimer1();
	void PWM_StartTimer1();
	void PWM_GenerateTimer1(u16 d_cycle);

	void PWM_InitTimer2();
	void PWM_StartTimer2();
	void PWM_GenerateTimer2(u16 d_cycle);	
	 								
	 								
	 								
#endif								
