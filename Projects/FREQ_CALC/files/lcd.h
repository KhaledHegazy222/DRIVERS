/* 								 
	Created By 	: 	Khaled Hegazy 	
	File Name	:	lcd.h 			
*/ 								
	 								
	 								
#ifndef Khaled						
	#define __AVR_ATmega32__		
#endif								
	 									

#include "std_types.h"			
	 										
	 								
	 						
#ifndef __LCD_H__
	#define __LCD_H__

		
		 								
		 			

	#define lcd_data A 
	#define lcd_ctr C
	#define RS 0
	#define RW 1
	#define EN 2	

	// D0 To D7 : PortA
	// Rs = Pin B0
	// Rw = Pin B1
	// Enable = Pin B2


	void LCD_Init(void);
	void LCD_MoveCursor(u8 row,u8 col);
	void LCD_WriteCMD(u8);
	void LCD_WriteChar(u8 chr);
	void LCD_WriteCharAt(u8 chr,u8 row,u8 col);
	void LCD_WriteTxt(u8* str);
	void LCD_WriteTxtAt(u8* str,u8 row,u8 col);
	u8 LCD_GetAddress(void);
	void LCD_ClearScreen(void);

	
	void LCD_AddCustom(u8* pattern,u8 address);
	void LCD_DrawCustom(u8 address);


	/* Four Bit Mode */
	void LCD_Init4(void);
	void LCD_MoveCursor4(u8 row,u8 col);
	void LCD_WriteCMD4(u8 cmd);
	void LCD_WriteChar4(u8 chr);
	void LCD_WriteCharAt4(u8 chr,u8 row,u8 col);
	void LCD_WriteTxt4(u8* str);
	void LCD_WriteTxtAt4(u8* str,u8 row,u8 col);
	
	
										
	 								
	 								
	 								
	 								
	 								
#endif								
