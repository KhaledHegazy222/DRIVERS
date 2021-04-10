

#ifndef BIT_MATH_H
	#define BIT_MATH_H




	#define set_bit(port,bit) (port|=(1<<bit))
	#define clear_bit(port,bit) (port&=~(1<<bit))
	#define toggle_bit(port,bit) (port^=(1<<bit))
	#define assign_port(port,val) (port=val)
	#define get_bit(port,bit) ((port&(1<<bit))!=0)


#endif 