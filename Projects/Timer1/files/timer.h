/* 								 
	Created By 	: 	Khaled Hegazy 	
	File Name	:	timer.h 			
*/ 								
	 								
	 								
#ifndef Khaled						
	#define __AVR_ATmega32__		
#endif								
	 								
	 							
#include "std_types.h"
								
#ifndef __TIMER_H__
	#define __TIMER_H__

		
	 								
	 								
// =================================================> Registers <=================================================


	#define TIMSK_reg	(* ( (volatile u8 *) 0x59 ))	// Timer/Counter Interrupt Mask Register (TIMSK)
	#define TIFR_reg    (* ( (volatile u8 *) 0x58 ))	// Timer/Counter Interrupt Flag Register (TIFR)
	
	// Timer 0 (8 bit)
		#define TCNT0_reg	(* ( (volatile u8 *) 0x52 ))	//Timer/Counter0 counter value (TCNT0)
		#define TCCR0_reg	(* ( (volatile u8 *) 0x53 ))	// Timer/Counter0 Control Register (TCCR0)
		#define OCR0_reg	(* ( (volatile u8 *) 0x5C ))	// Timer/Counter0 Output Compare Register (OCR0)

	// Timer 1 (16 Bit)
		#define TCNT1_reg	(* ( (volatile u16 *) 0x4C ))	// Timer/Counter1 counter value (TCNT1)
		#define TCCR1A_reg	(* ( (volatile u8 *) 0x4F ))	// Timer/Counter1 Control Register A (TCCR1A)
		#define TCCR1B_reg	(* ( (volatile u8 *) 0x4E ))	// Timer/Counter1 Control Register B (TCCR1B)
		#define OCR1A_reg	(* ( (volatile u16 *) 0x4A ))	// Timer/Counter1 – Output Compare Register A (OCR1A)
		#define OCR1B_reg	(* ( (volatile u16 *) 0x48 ))	// Timer/Counter1 – Output Compare Register B (OCR1B)

	// Timer 2 (8 bit)
		#define TCNT2_reg	(* ( (volatile u8 *) 0x44 ))	//Timer/Counter2 counter value (TCNT2)
		#define TCCR2_reg	(* ( (volatile u8 *) 0x45 ))	// Timer/Counter2 Control Register (TCCR2)
		#define OCR2_reg	(* ( (volatile u8 *) 0x43 ))	// Timer/Counter2 Output Compare Register (OCR2)


// =================================================> Bits <=================================================


	#define TIMSK_TOIE0		0	// Timer/Counter0 Overflow Interrupt Enable
	#define TIMSK_OCIE0		1	// Timer/Counter0, Output Compare Match Interrupt Enable
	#define TIMSK_TOIE1		2	// Timer/Counter1 Overflow Interrupt Enable
	#define TIMSK_OCIE1B	3	// Timer/Counter0, Output Compare Match Interrupt Enable
	#define TIMSK_OCIE1A	4	// Timer/Counter0, Output Compare Match Interrupt Enable
	#define TIMSK_TICIE1	5	// Timer/Counter0, Output Compare Match Interrupt Enable
	#define TIMSK_TOIE2		6	// Timer/Counter0, Output Compare Match Interrupt Enable
	#define TIMSK_OCIE2		7	// Timer/Counter0, Output Compare Match Interrupt Enable
	
	
	
	#define TIFR_TOV0		0	// Timer/Counter0, Overflow Flag
	#define TIFR_TOV1		2	// Timer/Counter1, Overflow Flag
	
	
		
	#define TCCR0_CS00		0	// Timer/Counter0 Clock Select bit0
	#define TCCR0_CS01		1	// Timer/Counter0 Clock Select bit1
	#define TCCR0_CS02		2	// Timer/Counter0 Clock Select bit2	
	#define TCCR0_WGM01		3	// Timer/Counter0 Waveform Generation Mode bit1
	#define TCCR0_COM00		4   // Timer/Counter0 Compare Match Output Mode
	#define TCCR0_COM01		5   // Timer/Counter0 Compare Match Output Mode
	#define TCCR0_WGM00		6	// Timer/Counter0 Waveform Generation Mode bit0
	

	#define TCCR1A_WGM10	0	// Timer/Counter1 Waveform Generation Mode bit0
	#define TCCR1A_WGM11	1	// Timer/Counter1 Waveform Generation Mode bit1
	#define TCCR1A_COM1B0	4	// Timer/Counter1 Compare Output Mode for Compare unit B
	#define TCCR1A_COM1B1	5	// Timer/Counter1 Compare Output Mode for Compare unit B
	#define TCCR1A_COM1A0	6	// Timer/Counter1 Compare Output Mode for Compare unit A
	#define TCCR1A_COM1A1	7	// Timer/Counter1 Compare Output Mode for Compare unit A
	
	#define TCCR1B_CS10		0	// Timer/Counter1 Clock Select bit0
	#define TCCR1B_CS11		1	// Timer/Counter1 Clock Select bit1
	#define TCCR1B_CS12		2	// Timer/Counter1 Clock Select bit2
	#define TCCR1B_WGM12	3	// Timer/Counter1 Waveform Generation Mode bit2
	#define TCCR1B_WGM13	4	// Timer/Counter1 Waveform Generation Mode bit3
	
	
	#define TCCR2_CS20		0	// Timer/Counter2 Clock Select bit0
	#define TCCR2_CS21		1	// Timer/Counter2 Clock Select bit1
	#define TCCR2_CS22		2	// Timer/Counter2 Clock Select bit2	
	#define TCCR2_WGM21		3	// Timer/Counter2 Waveform Generation Mode bit1
	#define TCCR2_COM20		4	// Timer/Counter2 Compare Match Output Mode
	#define TCCR2_COM21		5	// Timer/Counter2 Compare Match Output Mode
	#define TCCR2_WGM20		6	// Timer/Counter2 Waveform Generation Mode bit0
	
	
	
	
	typedef enum{
		Normal,		
		Pwm,
		Ctc,
		Fast_Pwm
	}MODE;
	typedef enum{
		Enabled,
		Disabled
	}INT_STATE;
	typedef enum{
		No_Source,
		No_Prescalling,
		Clk_8,
		Clk_32,
		Clk_64,
		Clk_128,
		Clk_256,
		Clk_1024,
		Ext_Rising,
		Ext_Falling
	}PRESCALLER;
	
	
	
// =================================================> Functions <=================================================

	u8 TMR_GetTimer0(void);
	u16 TMR_GetTimer1(void);
	u8 TMR_GetTimer2(void);

	void TMR_SetTimer0(u8 val);
	void TMR_SetTimer1(u16 val);
	void TMR_SetTimer2(u8 val);
	
	void TMR_InitTimer0(PRESCALLER ps,INT_STATE state,MODE mode);
	void TMR_InitTimer2(PRESCALLER ps,MODE mode);

	 								
	 							
	 								
	 								
	 								
	 								
	 								
#endif								
