
#define  F_CPU 1000000UL

#include <util/delay.h>


#include "lcd.h"
#include "gpio.h"
#include "bit_math.h"


static void send(u8 msg){
	GPIO_SetPinVal(lcd_ctr,RW,0); // Rw = 0
	
	
	GPIO_SetPortVal(lcd_data,msg); // PORTA = cmd
	
	
	GPIO_SetPinVal(lcd_ctr,E,1); // Enable = 1
	_delay_ms(1);
	GPIO_SetPinVal(lcd_ctr,E,0); // Enable = 0
	
}
static void send4(u8 msg){
	GPIO_SetPinVal(lcd_ctr,RW,0); // Rw = 0



	u8 dt = GPIO_GetPortVal(lcd_data);
	dt &= 0x0f; // Mask The Upper Nibble
	dt |= (msg & 0xf0); // Send The Upper Four bits 
	GPIO_SetPortVal(lcd_data,dt);
	
	

	GPIO_SetPinVal(lcd_ctr,E,1); // Enable = 1
	_delay_ms(1);
	GPIO_SetPinVal(lcd_ctr,E,0); // Enable = 0
	_delay_ms(1);
	
	
	
	dt = GPIO_GetPortVal(lcd_data);
	dt &= 0x0f; // Clear The Upper Nibble
	dt |= (msg)<<4; // Send The Lower Four Bits
	GPIO_SetPortVal(lcd_data,dt);
	
	
		
	GPIO_SetPinVal(lcd_ctr,E,1); // Enable = 1
	_delay_ms(1);
	GPIO_SetPinVal(lcd_ctr,E,0); // Enable = 0
	_delay_ms(1);
	
	
}




void LCD_Init(void){
	
	GPIO_SetPortDir(lcd_data,0xff);
	GPIO_SetPinDir(lcd_ctr,RS,OUTPUT);
	GPIO_SetPinDir(lcd_ctr,RW,OUTPUT);
	GPIO_SetPinDir(lcd_ctr,E,OUTPUT);
	
	
	
	_delay_ms(35); // Wait For Power
	
	LCD_WriteCMD(0b00111000); // 8bit mode + 2 line mode + 5*8 mode
	_delay_ms(1);
	
	
	LCD_WriteCMD(0b00001100); // Display On + No Cursor + No Blink
	_delay_ms(1);
	
	LCD_WriteCMD(0b00000001); // Clear Display
	_delay_ms(2);
	
	LCD_WriteCMD(0b00000110); // Entry Mode (increment  + NO Shift)
	_delay_ms(1);
}
void LCD_Init4(void){
	

	
	GPIO_SetPinDir(lcd_data,PIN_4,OUTPUT);
	GPIO_SetPinDir(lcd_data,PIN_5,OUTPUT);
	GPIO_SetPinDir(lcd_data,PIN_6,OUTPUT);
	GPIO_SetPinDir(lcd_data,PIN_7,OUTPUT);
	GPIO_SetPinDir(lcd_ctr,RS,OUTPUT);
	GPIO_SetPinDir(lcd_ctr,RW,OUTPUT);
	GPIO_SetPinDir(lcd_ctr,E,OUTPUT);
	
	_delay_ms(35); // Wait For Power
	
	
	/* Init 4 Bit Mod */
	GPIO_SetPinVal(lcd_ctr,RS,0); 
	GPIO_SetPinVal(lcd_ctr,RW,0); 
	
	u8 dt = GPIO_GetPortVal(lcd_data);
	dt &= 0x0f;
	dt |= 0x20;
	GPIO_SetPortVal(lcd_data,dt);
	
	
	GPIO_SetPinVal(lcd_ctr,E,1); 
	_delay_ms(1);
	GPIO_SetPinVal(lcd_ctr,E,0); 
	_delay_ms(1);
	/* Init 4 Bit Mod */
	



	
	
	LCD_WriteCMD4(0x28);// 4 bit mode + 2 line mode + 5 * 8
	_delay_ms(1);
	
	LCD_WriteCMD4(0x0C); // Display On + No Cursor + No Blink
	_delay_ms(1);
	
	LCD_WriteCMD4(0x01);// Clear Display
	_delay_ms(2);
	
	LCD_WriteCMD4(0x06);// Entry Mode (increament + No Shift)
	_delay_ms(1);
	
}


void LCD_ClearScreen(void){
	LCD_WriteCMD(0x01); // Clear Display + Return Home 
	_delay_ms(2);
}




void LCD_MoveCursor(u8 row,u8 col){
	row--;
	col--;
	u8 location = (1<<7)|((row*0x40) + col); // Calculate The Required Location
	LCD_WriteCMD(location); // Set The Address Counter To The Specified Location in The DDRAM  
	_delay_ms(1);
}
void LCD_MoveCursor4(u8 row,u8 col){
	row--;
	col--;
	u8 location = (1<<7)|((row*0x40) + col);// Calculate The Required Location
	LCD_WriteCMD4(location);// Set The Address Counter To The Specified Location in The DDRAM  
	_delay_ms(1);
	_delay_ms(1);
}



void LCD_WriteCMD(u8 cmd){
	GPIO_SetPinVal(lcd_ctr,RS,0); // Rs = 0
	send(cmd);
	
}
void LCD_WriteCMD4(u8 cmd){
	GPIO_SetPinVal(lcd_ctr,RS,0); // Rs = 0
	send4(cmd);
	
}


void LCD_WriteChar(u8 chr){
	GPIO_SetPinVal(lcd_ctr,RS,1); // Rs = 1
	send(chr);
}
void LCD_WriteChar4(u8 chr){
	GPIO_SetPinVal(lcd_ctr,RS,1); // Rs = 1
	send4(chr);
}


void LCD_WriteTxt(u8* str){
	u8 i = 0;
	while(str[i]){
		LCD_WriteChar(str[i++]);
	}
}
void LCD_WriteTxt4(u8* str){
	u8 i = 0;
	while(str[i]){
		LCD_WriteChar4(str[i++]);
	}
}


void LCD_WriteCharAt(u8 chr,u8 row,u8 col){
	LCD_MoveCursor(row,col);
	LCD_WriteChar(chr);
}
void LCD_WriteCharAt4(u8 chr,u8 row,u8 col){
	LCD_MoveCursor4(row,col);
	LCD_WriteChar4(chr);
}




void LCD_WriteTxtAt(u8* str,u8 row,u8 col){
	LCD_MoveCursor(row,col);
	u8 i = 0;
	while(str[i]){
		if(col > 16){
			LCD_MoveCursor(2,1);
			col = 1;
		}
		LCD_WriteChar(str[i]);
		col++;
		i++;
	}
}
void LCD_WriteTxtAt4(u8* str,u8 row,u8 col){
	LCD_MoveCursor4(row,col);
	u8 i = 0;
	while(str[i]){
		if(col > 16){
			LCD_MoveCursor4(2,1);
			col = 1;
		}
		LCD_WriteChar4(str[i]);
		col++;
		i++;
	}
}



u8 LCD_GetAddress(void){
	GPIO_SetPortDir(lcd_data,0x00); // Set PortA As Input To Recieve Data
	GPIO_SetPinVal(lcd_ctr,RS,0); // Rs = 0
	GPIO_SetPinVal(lcd_ctr,RW,1); // Rw = 1
	
	GPIO_SetPinVal(lcd_ctr,E,1); // Enable = 1
	_delay_ms(1);
	GPIO_SetPinVal(lcd_ctr,E,2); // Enable = 0
	

	u8 ret = GPIO_GetPortVal(lcd_data);
	GPIO_SetPortDir(lcd_data,0xff); // Return PortA To Output Mode 

	return ret;
}



void LCD_AddCustom(u8* pattern,u8 address){
	address--;
	u8 location = 0x40 | (address * 8); // Calculate The Specified Location in The CGROM
	LCD_WriteCMD(location);  // Setting The Address Counter To The Location in CGROM
	_delay_ms(1);
	
	
	LCD_WriteChar(pattern[0]); // Writing Data To CGROM Memory ......
	_delay_ms(1);
	
	LCD_WriteChar(pattern[1]);
	_delay_ms(1);
	
	LCD_WriteChar(pattern[2]);
	_delay_ms(1);
	
	LCD_WriteChar(pattern[3]);
	_delay_ms(1);
	
	LCD_WriteChar(pattern[4]);
	_delay_ms(1);
	
	LCD_WriteChar(pattern[5]);
	_delay_ms(1);
	
	LCD_WriteChar(pattern[6]);
	_delay_ms(1);
	
	LCD_WriteChar(pattern[7]);
	_delay_ms(1);
	
	LCD_WriteCMD(1<<7); // Return Address Counter To DDRAM Memory And Set it To 0x00
	
}

void LCD_DrawCustom(u8 address){
	address--;
	LCD_WriteChar(address); 
}




