/* 
	Created By: Khaled Hegazy
	File Name : main.c
*/

#ifndef Khaled
	#define __AVR_ATmega32__
#endif


/* 
	Important Comment :
	========================> The Frequency Calculator isn't Very Accurate in High Frequencies :(
*/


#include <avr/interrupt.h>
#include <util/delay.h>

#include "std_types.h"
#include "bit_math.h"
#include "gpio.h"
#include "timer.h"
#include "lcd.h"
volatile u64 factor = 0;
volatile u64 freq = 0;
volatile u8 changed = 1;

ISR(TIMER0_OVF_vect){
	factor++;
}

ISR(TIMER1_OVF_vect){
	freq = factor * 256 + TCNT0_reg;  // Freq = How Many Pulses In This Second
	factor = 0;
	TCNT0_reg = 0;
	TCNT1_reg = 64559;
	changed = 1;
}

void dsp(u64 val){
	LCD_ClearScreen();
	LCD_WriteTxtAt("Freq ",1,1);
	u8 txt[19];
	s8 idx = 0;
	while(val){
		txt[idx++] = (val%10)+ '0';
		val /= 10;
	}
	idx--;
	u8 print = 1;
	while(idx >= 0){
		print = 0;
		LCD_WriteChar(txt[idx--]);
	}
	if(print){
		LCD_WriteChar('0');
	}
	
	LCD_WriteTxt(" HZ");
	
}







int main(void){
	
		LCD_Init();

		GPIO_SetPinDir(B,PIN_0,INPUT); // T0 
		

		



/*	======================================> Timer 0 <======================================  */

	TMR_InitTimer0(Ext_Rising,Enabled,Normal);

/*	======================================> Timer 1 <======================================  */
	// Waveform Generation Mode : Normal Mode
	clear_bit(TCCR1A_reg,TCCR1A_WGM10);
	clear_bit(TCCR1A_reg,TCCR1A_WGM11);
	clear_bit(TCCR1B_reg,TCCR1B_WGM12);
	clear_bit(TCCR1B_reg,TCCR1B_WGM13);

	// Clock Select :  Clk/1024 
	set_bit(TCCR1B_reg,TCCR1B_CS10);
	clear_bit(TCCR1B_reg,TCCR1B_CS11);
	set_bit(TCCR1B_reg,TCCR1B_CS12);

	TCNT1_reg = 64559; // Time To Over Flow Is One Second


	set_bit(TIMSK_reg,TIMSK_TOIE1); // Enable Over Flow Interrupt For Timer 1


		
		
	sei(); // Enable Global Interrupt
		
		
		

	
	
	
    while (1){
		if(changed){
			dsp(freq);
			changed = 0;
		}
	}
}

