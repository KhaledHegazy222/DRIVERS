/* 								 
	Created By 	: 	Khaled Hegazy 	
	File Name	:	gpio.c 				
*/ 								
	 								
	 								
#ifndef Khaled						
	#define __AVR_ATmega32__		
#endif								
	 								
	 								
	 				


#include "gpio.h"
#include "std_types.h"
#include "bit_math.h"

void GPIO_SetPortDir(u8 port_num,u8 port_val){

    switch(port_num){
        case A : assign_port(DDRA,port_val);
            break;
        case B : assign_port(DDRB,port_val);
            break;
        case C : assign_port(DDRC,port_val);
            break;
        case D : assign_port(DDRD,port_val);
    }

}




void GPIO_SetPinDir (u8 port_num , u8 pin_num,u8 pin_dir){
    switch(port_num){
        case A : 
			if(pin_dir == OUTPUT){
				set_bit(DDRA,pin_num);
			}
			else{
				clear_bit(DDRA,pin_num);
			}
            break;
		case B :
			if(pin_dir == OUTPUT){
				set_bit(DDRB,pin_num);
			}
			else{
				clear_bit(DDRB,pin_num);
			}
			break;
		case C :
			if(pin_dir == OUTPUT){
				set_bit(DDRC,pin_num);
			}
			else{
				clear_bit(DDRC,pin_num);
			}
			break;
		case D :
			if(pin_dir == OUTPUT){
				set_bit(DDRD,pin_num);
			}
			else{
				clear_bit(DDRD,pin_num);
			}
    }
}   

void GPIO_SetPortVal(u8 port_num,u8 port_val){
	switch(port_num){
		case A :
			assign_port(PORTA,port_val);
			break;
		case B :
			assign_port(PORTB,port_val);
			break;
		case C :
			assign_port(PORTC,port_val);
			break;
		case D :
			assign_port(PORTD,port_val);
	}
}

void GPIO_SetPinVal (u8 port_num , u8 pin_num , u8 pin_val){
    switch(port_num){
        case A : 
            if(pin_val){
                set_bit(PORTA,pin_num);
            }
            else{
                clear_bit(PORTA,pin_num);
            }
            break;
        case B : 
            if(pin_val){
                set_bit(PORTB,pin_num);
            }
            else{
                clear_bit(PORTB,pin_num);
            }
            break;
        case C : 
            if(pin_val){
                set_bit(PORTC,pin_num);
            }
            else{
                clear_bit(PORTC,pin_num);
            }
            break;
        case D :
            if(pin_val){
                set_bit(PORTD,pin_num);
            }
            else{
                clear_bit(PORTD,pin_num);
            }
    }
}


u8 GPIO_GetPortVal(u8 port_num){
	switch(port_num){
		case A :
			return PINA;
		case B :
			return PINB;
		case C :
			return PINC;
		case D :
			return PIND;
	}
	return 0;
}

u8 GPIO_GetPinVal(u8 port_num, u8 pin_num){
	switch(port_num){
		case A :
		return get_bit(PINA,pin_num);
		case B :
		return get_bit(PINB,pin_num);
		case C :
		return get_bit(PINC,pin_num);
		case D :
		return get_bit(PIND,pin_num);
	}
	return 0;
}
void GPIO_SetPullUpPin(u8 port_num , u8 pin_num){
	switch(port_num){
		case A:
			clear_bit(DDRA,pin_num);
			set_bit(PORTA,pin_num);
		case B:
			clear_bit(DDRB,pin_num);
			set_bit(PORTB,pin_num);
		case C:
			clear_bit(DDRC,pin_num);
			set_bit(PORTC,pin_num);
		case D:
			clear_bit(DDRD,pin_num);
			set_bit(PORTD,pin_num);
	}	
}					
	 								
	 								
	 								
	 								
					
	 								
	 								
	 								
	 								
	 								
