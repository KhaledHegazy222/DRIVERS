/* 								 
	Created By 	: 	Khaled Hegazy 	
	File Name	:	timer.c 				
*/ 								
	 								
	 								
#ifndef Khaled						
	#define __AVR_ATmega32__		
#endif								
	 								
	 								
	 														
	 								
#include "timer.h"
#include "bit_math.h"






u8 TMR_GetTimer0(void){
	return TCNT0_reg;
}
u16 TMR_GetTimer1(void){
	return TCNT1_reg;
}
u8 TMR_GetTimer2(void){
	return TCNT2_reg;
}

void TMR_SetTimer0(u8 val){
	TCNT0_reg = val;
}
void TMR_SetTimer1(u16 val){
	TCNT1_reg = val;
}
void TMR_SetTimer2(u8 val){
	TCNT2_reg = val;
}

void TMR_InitTimer0(PRESCALLER ps,INT_STATE state,MODE mode){
	
	if(state == Enabled){
		if(mode == Ctc){
			set_bit(TIMSK_reg,TIMSK_OCIE0);
			clear_bit(TIMSK_reg,TIMSK_TOIE0);
		}
		else if(mode == Normal){
			set_bit(TIMSK_reg,TIMSK_TOIE0);
			clear_bit(TIMSK_reg,TIMSK_OCIE0);
		}
	}
	else{
		clear_bit(TIMSK_reg,TIMSK_TOIE0);
		clear_bit(TIMSK_reg,TIMSK_OCIE0);
	}
	
	switch(ps){
		case No_Source :
			clear_bit(TCCR0_reg,TCCR0_CS00);
			clear_bit(TCCR0_reg,TCCR0_CS01);
			clear_bit(TCCR0_reg,TCCR0_CS02);
		break;
		
		case No_Prescalling :
			set_bit(TCCR0_reg,TCCR0_CS00);
			clear_bit(TCCR0_reg,TCCR0_CS01);
			clear_bit(TCCR0_reg,TCCR0_CS02);
		break;
		
		case Clk_8 :
			clear_bit(TCCR0_reg,TCCR0_CS00);
			set_bit(TCCR0_reg,TCCR0_CS01);
			clear_bit(TCCR0_reg,TCCR0_CS02);
		break;
		
		case  Clk_64 :
			set_bit(TCCR0_reg,TCCR0_CS00);
			set_bit(TCCR0_reg,TCCR0_CS01);
			clear_bit(TCCR0_reg,TCCR0_CS02);
		break;
		
		case  Clk_256 :
			clear_bit(TCCR0_reg,TCCR0_CS00);
			clear_bit(TCCR0_reg,TCCR0_CS01);
			set_bit(TCCR0_reg,TCCR0_CS02);
		break;
		
		case  Clk_1024 :
			set_bit(TCCR0_reg,TCCR0_CS00);
			clear_bit(TCCR0_reg,TCCR0_CS01);
			set_bit(TCCR0_reg,TCCR0_CS02);
		break;
		
		case  Ext_Falling :
			clear_bit(TCCR0_reg,TCCR0_CS00);
			set_bit(TCCR0_reg,TCCR0_CS01);
			set_bit(TCCR0_reg,TCCR0_CS02);
		break;
		
		case Ext_Rising :
			set_bit(TCCR0_reg,TCCR0_CS00);
			set_bit(TCCR0_reg,TCCR0_CS01);
			set_bit(TCCR0_reg,TCCR0_CS02);
		break;
		
	}
	
	
	
	if(mode == Normal){
		clear_bit(TCCR0_reg,TCCR0_WGM00);
		clear_bit(TCCR0_reg,TCCR0_WGM01);
	}
	else if(mode == Pwm){
		set_bit(TCCR0_reg,TCCR0_WGM00);
		clear_bit(TCCR0_reg,TCCR0_WGM01);
	}
	else if(mode == Ctc){
		clear_bit(TCCR0_reg,TCCR0_WGM00);
		set_bit(TCCR0_reg,TCCR0_WGM01);
	}
	else if(mode == Fast_Pwm){
		set_bit(TCCR0_reg,TCCR0_WGM00);
		set_bit(TCCR0_reg,TCCR0_WGM01);
	}
	
}



/*  Timer 1 Has 16 Mode So I will Not Make A driver For it */



// Timer Two Doesn't Have Interrupt 
void TMR_InitTimer2(PRESCALLER ps,MODE mode){
	
	
	switch(ps){
		case No_Source :
			clear_bit(TCCR2_reg,TCCR2_CS20);
			clear_bit(TCCR2_reg,TCCR2_CS21);
			clear_bit(TCCR2_reg,TCCR2_CS22);
		break;
			
		case No_Prescalling :
			set_bit(TCCR2_reg,TCCR2_CS20);
			clear_bit(TCCR2_reg,TCCR2_CS21);
			clear_bit(TCCR2_reg,TCCR2_CS22);
		break;
		
		case Clk_8 :
			clear_bit(TCCR2_reg,TCCR2_CS20);
			set_bit(TCCR2_reg,TCCR2_CS21);
			clear_bit(TCCR2_reg,TCCR2_CS22);
		break;
		
		case  Clk_32 :
			set_bit(TCCR2_reg,TCCR2_CS20);
			set_bit(TCCR2_reg,TCCR2_CS21);
			clear_bit(TCCR2_reg,TCCR2_CS22);
		break;
		
		case  Clk_64 :
			clear_bit(TCCR2_reg,TCCR2_CS20);
			clear_bit(TCCR2_reg,TCCR2_CS21);
			set_bit(TCCR2_reg,TCCR2_CS22);
		break;
		
		case  Clk_128 :
			set_bit(TCCR2_reg,TCCR2_CS20);
			clear_bit(TCCR2_reg,TCCR2_CS21);
			set_bit(TCCR2_reg,TCCR2_CS22);
		break;
		
		case  Clk_256 :
			clear_bit(TCCR2_reg,TCCR2_CS20);
			set_bit(TCCR2_reg,TCCR2_CS21);
			set_bit(TCCR2_reg,TCCR2_CS22);
		break;
		
		case Clk_1024 :
			set_bit(TCCR2_reg,TCCR2_CS20);
			set_bit(TCCR2_reg,TCCR2_CS21);
			set_bit(TCCR2_reg,TCCR2_CS22);
		break;
		
	}
	
	
	
	if(mode == Normal){
		clear_bit(TCCR2_reg,TCCR2_WGM20);
		clear_bit(TCCR2_reg,TCCR2_WGM21);
	}
	else if(mode == Pwm){
		set_bit(TCCR2_reg,TCCR2_WGM20);
		clear_bit(TCCR2_reg,TCCR2_WGM21);
	}
	else if(mode == Ctc){
		clear_bit(TCCR2_reg,TCCR0_WGM00);
		set_bit(TCCR2_reg,TCCR0_WGM01);
	}
	else if(mode == Fast_Pwm){
		set_bit(TCCR2_reg,TCCR0_WGM00);
		set_bit(TCCR2_reg,TCCR0_WGM01);
	}
	
}


			
	 								
	 								
	 								
	 								

	 								
	 								
	 								
	 								
	 								
