/* 								 
	Created By 	: 	Khaled Hegazy 	
	File Name	:	ext_int.h 			
*/ 								
	 								
	 								
#ifndef Khaled						
	#define __AVR_ATmega32__		
#endif								
	 								
// Note: initialize global interrupts in main before using
// Note: INT2 only works with rising and falling edges
// Note: EXT interrupts doesn't work in sleep mode. only (low level)


#include "std_types.h"			
	 								
	 					

#ifndef __EXT_INT_H__
	#define __EXT_INT_H__
				
	 								
	 		
	 						
	#define GICR_reg	(* ( (volatile u8 *) 0x5B ))	// General Interrupt Control Register (GICR)
	#define GIFR_reg	(* ( (volatile u8 *) 0x5A ))	// General Interrupt Flag Register (GIFR)
	#define MCUCR_reg	(* ( (volatile u8 *) 0x55 ))	// MCU Control Register (MCUCR)
	#define MCUCSR_reg	(* ( (volatile u8 *) 0x54 ))	// MCU Control and Status Register (MCUCSR)
	
	
	#define MCUCR_ISC00		0
	#define MCUCR_ISC01		1
	#define MCUCR_ISC10		2
	#define MCUCR_ISC11		3
	#define MCUCSR_ISC2		6
	
	#define GICR_INT0		6	// External Interrupt 0 Enable
	#define GICR_INT1		7	// External Interrupt 1 Enable
	#define GICR_INT2		5	// External Interrupt 2 Enable
	
	#define GIFR_INTF0		6	// External Interrupt Flag 0
	#define GIFR_INTF1		7	// External Interrupt Flag 1
	#define GIFR_INTF2		5	// External Interrupt Flag 2
	
	
 typedef enum{
	 EXT_INT_0 ,
	 EXT_INT_1 ,
	 EXT_INT_2 ,
 }EXT_INT;

 typedef enum{
	 LOW_LEVEL ,
	 ON_CHANGE ,
	 FALLIN_EDGE ,
	 RISIN_EDGE ,
 }TRIGGERING_CONDITION;


void EXT_EnableExtInt(EXT_INT ext_int , TRIGGERING_CONDITION condition , void (*func)(void));
void EXT_DisableExtInt(EXT_INT ext_int);

// Bonus functions
void EXT_InitGlobalInterrupts(void);




						
	 								
	 								
	 								
	 								
	 								
#endif								
