/* 								 
	Created By 	: 	Khaled Hegazy 	
	File Name	:	pwm.c 				
*/ 								
	 								
	 								
#ifndef Khaled						
	#define __AVR_ATmega32__		
#endif								
	 								
	 								
	 								
	 											
	 								
#include "pwm.h"
#include "timer.h"
#include "std_types.h"
#include "bit_math.h"

void PWM_InitTimer0(){
	// Fast PWM Mode
	set_bit(TCCR0_reg,TCCR0_WGM00);
	set_bit(TCCR0_reg,TCCR0_WGM01);
	
	// Non-Inverting Mode (PWM)
	clear_bit(TCCR0_reg, TCCR0_COM00);
	set_bit(TCCR0_reg, TCCR0_COM01);
	
}

void PWM_InitTimer1(){
	// Fast PWM Mode 8 bit
	set_bit(TCCR1A_reg, TCCR1A_WGM10);
	clear_bit(TCCR1A_reg, TCCR1A_WGM11);
	set_bit(TCCR1B_reg, TCCR1B_WGM12);
	clear_bit(TCCR1B_reg, TCCR1B_WGM13);
	
	// Non-Inverting Mode (PWM)
	clear_bit(TCCR1A_reg, TCCR1A_COM1A0);
	set_bit(TCCR1A_reg, TCCR1A_COM1A1);
	
}

void PWM_InitTimer2(){
	// Fast PWM Mode
	set_bit(TCCR2_reg, TCCR2_WGM20);
	set_bit(TCCR2_reg, TCCR2_WGM21);
	
	// Non-Inverting Mode(PWM)
	clear_bit(TCCR2_reg, TCCR2_COM20);
	set_bit(TCCR2_reg, TCCR2_COM21);
	
}


void PWM_StartTimer0(){
	
	
	// No Prescalling Clock Selection
	set_bit(TCCR0_reg,TCCR0_CS00);
	clear_bit(TCCR0_reg,TCCR0_CS01);
	clear_bit(TCCR0_reg,TCCR0_CS02);
}
void PWM_StartTimer1(){
	
	
	// No Prescalling Clock Selection
	set_bit(TCCR1B_reg, TCCR1B_CS10);
	clear_bit(TCCR1B_reg, TCCR1B_CS11);
	clear_bit(TCCR1B_reg, TCCR1B_CS12);

}
void PWM_StartTimer2(){

	// No Prescalling Clock Selection
	set_bit(TCCR2_reg,TCCR2_CS20);
	clear_bit(TCCR2_reg,TCCR2_CS21);
	clear_bit(TCCR2_reg,TCCR2_CS22);
		
}

void PWM_GenerateTimer0(u16 d_cycle){
	OCR0_reg = ((d_cycle * 256) / 100) - 1;
}
void PWM_GenerateTimer1(u16 d_cycle){
	OCR1A_reg = ((d_cycle * 256) / 100) - 1;
}
void PWM_GenerateTimer2(u16 d_cycle){
	OCR2_reg = ((d_cycle * 256) / 100) - 1;

}
					
	 										
	 								
	 								
	 								
	 								
