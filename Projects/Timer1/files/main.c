/* 
	Created By: Khaled Hegazy
	File Name : main.c
*/

#ifndef Khaled
	#define __AVR_ATmega32__
#endif


#include "bit_math.h"

#include "gpio.h"
#include "timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>

u8 cnt1 = 0;
u8 cnt2 = 0;
u8 cnt3 = 0;
u8 cnt4 = 0;


ISR(TIMER1_OVF_vect){
	TCNT1_reg = 64559;

	cnt1++;
	cnt2++;
	cnt3++;
	cnt4++;
	if(cnt1 % 1 == 0){
		toggle_bit(PORTA,PIN_0);
	}
	if(cnt2 % 2 == 0){
		toggle_bit(PORTA,PIN_1);
	}
	if(cnt3 % 3 == 0){
		toggle_bit(PORTA,PIN_2);
	}
	if(cnt4 % 4 == 0){
		toggle_bit(PORTA,PIN_3);
	}
	
	
	
}



int main(void){
	
	GPIO_SetPinDir(A,PIN_0,OUTPUT);
	GPIO_SetPinDir(A,PIN_1,OUTPUT);
	GPIO_SetPinDir(A,PIN_2,OUTPUT);
	GPIO_SetPinDir(A,PIN_3,OUTPUT);
	
	
	
	TCNT1_reg = 64559; // Time To Over Flow Is One Second
	
	
	// These Four Lines Are For Set The Timer1 In Normal Mode 
	clear_bit(TCCR1A_reg,TCCR1A_WGM10);  
	clear_bit(TCCR1A_reg,TCCR1A_WGM11);
	clear_bit(TCCR1B_reg,TCCR1B_WGM12);
	clear_bit(TCCR1B_reg,TCCR1B_WGM13);
	
	
	// Set The Prescaler On clk/1024
	set_bit(TCCR1B_reg,TCCR1B_CS10);
	clear_bit(TCCR1B_reg,TCCR1B_CS11);
	set_bit(TCCR1B_reg,TCCR1B_CS12);
	
	set_bit(TIMSK_reg,TIMSK_TOIE1); // Enable Timer 1 OverFlow Interrupt;
	
	
	sei(); // Enable Global Interrupt in Status Register 
	
	
    while (1){
	
	
    }
}

