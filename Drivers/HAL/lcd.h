#include "std_types.h"

#ifndef LCD_H
	#define LCD_H




	// D0 To D7 : PortA
	// Rs = Pin B0
	// Rw = Pin B1
	// Enable = Pin B2


	void LCD_Init(void);
	void LCD_MoveCursor(u8,u8);
	void LCD_WriteCMD(u8);
	void LCD_WriteChar(u8);
	void LCD_WriteCharAt(u8,u8,u8);
	void LCD_WriteTxt(u8*);
	void LCD_WriteTxtAt(u8*,u8,u8);
	u8 LCD_GetAddress(void);
	void LCD_ClearScreen(void);


	void LCD_AddCustom(u8*,u8);
	void LCD_DrawCustom(u8);


	/* Four Bit Mode */
	void LCD_Init4(void);
	void LCD_MoveCursor4(u8,u8);
	void LCD_WriteCMD4(u8);
	void LCD_WriteChar4(u8);
	void LCD_WriteCharAt4(u8,u8,u8);
	void LCD_WriteTxt4(u8*);
	void LCD_WriteTxtAt4(u8*,u8,u8);
	
	


#endif 