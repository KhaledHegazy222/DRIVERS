

#include "std_types.h"
#ifndef PWM_H
	#define PWM_H


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