#include "std_types.h"

#ifndef LCD_H
	#define LCD_H



	#define lcd_data A 
	#define lcd_ctr B
	#define RS 0
	#define RW 1
	#define E 2




	void LCD_Init(void);
	void LCD_MoveCursor(u8 row,u8 col);
	void LCD_WriteCMD(u8 cmd);
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