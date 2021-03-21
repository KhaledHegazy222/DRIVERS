#include "ext_int.h"
#include "bit_math.h"
#include <avr/interrupt.h>


 void (*fun_0)(void);
 void (*fun_1)(void);
 void (*fun_2)(void);
 
 
 ISR(INT0_vect){
	 fun_0();
 }
 
 ISR(INT1_vect){
	 fun_1();
 }
 
 ISR(INT2_vect){
	 fun_2();
 }
 




void EXT_EnableExtInt(EXT_INT ext_int , TRIGGERING_CONDITION condition , void (*func)(void)){
	switch(ext_int){
		case EXT_INT_0 :
			fun_0 = func;
			set_bit(GICR_reg,GICR_INT0); // Enable External Interrupt INT0
			if(condition == LOW_LEVEL){
				
				clear_bit(MCUCR_reg,MCUCR_ISC00);
				clear_bit(MCUCR_reg,MCUCR_ISC01);
			}
			else if(condition == ON_CHANGE){
				
				set_bit(MCUCR_reg,MCUCR_ISC00);
				clear_bit(MCUCR_reg,MCUCR_ISC01);
			}
			else if(condition == FALLIN_EDGE){
				
				clear_bit(MCUCR_reg,MCUCR_ISC00);
				set_bit(MCUCR_reg,MCUCR_ISC01);
			}
			else if(condition == RISIN_EDGE){
				
				set_bit(MCUCR_reg,MCUCR_ISC00);
				set_bit(MCUCR_reg,MCUCR_ISC01);
			}
			
			break;
		case EXT_INT_1 :
		
			fun_1 = func;
			set_bit(GICR_reg,GICR_INT1); // Enable External Interrupt INT1
			if(condition == LOW_LEVEL){
				
				clear_bit(MCUCR_reg,MCUCR_ISC10);
				clear_bit(MCUCR_reg,MCUCR_ISC11);
			}
			else if(condition == ON_CHANGE){
				
				set_bit(MCUCR_reg,MCUCR_ISC10);
				clear_bit(MCUCR_reg,MCUCR_ISC11);
			}
			else if(condition == FALLIN_EDGE){
				
				clear_bit(MCUCR_reg,MCUCR_ISC10);
				set_bit(MCUCR_reg,MCUCR_ISC11);
			}
			else if(condition == RISIN_EDGE){
				
				set_bit(MCUCR_reg,MCUCR_ISC10);
				set_bit(MCUCR_reg,MCUCR_ISC11);
			}
			
			break;
		case EXT_INT_2 :
			fun_2 = func;
			set_bit(GICR_reg,GICR_INT2); // Enable External Interrupt INT2
			if(condition == FALLIN_EDGE){
						clear_bit(MCUCSR_reg,MCUCSR_ISC2);
			}
			else if(condition == RISIN_EDGE){
						set_bit(MCUCSR_reg,MCUCSR_ISC2);

			}
	}
}




void EXT_DisableExtInt(EXT_INT ext_int){
	if(ext_int == EXT_INT_0){
		clear_bit(GICR_reg,GICR_INT0); // Disable External Interrupt INT0
	}
	else if(ext_int == EXT_INT_1){
		clear_bit(GICR_reg,GICR_INT1); // Disable External Interrupt INT1
	}
	else if(ext_int == EXT_INT_2){
		clear_bit(GICR_reg,GICR_INT2); // Disable External Interrupt INT2
	}
}



void EXT_InitGlobalInterrupts(void){
	sei();	
}

