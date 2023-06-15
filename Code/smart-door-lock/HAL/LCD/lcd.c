/*
 * CFile1.c
 *
 * Created: 04/12/2022 11:11:44 am
 *  Author: Loay
 */ 
#define F_CPU 1000000UL
#include "../../MCAL/DIO/DIO.h"
#include "lcd.h"
#include <util/delay.h>


void LCD_Init() {
	//setting lcd_port to high
	DIO_WritePort(LCD_PORT, HIGH);
	//delay at start
	_delay_ms(20);
	LCD_WriteCmd(0x02);
	LCD_WriteCmd(0x28);                // Enable 4-bit mode
	LCD_WriteCmd(0x0C);                // Display on , Cursor off (0x0E) Display on , Cursor blinking
	LCD_WriteCmd(0x01);                // Clear LCD
	LCD_WriteCmd(0x06);               // shift cursor to right (increment cursor)
	LCD_WriteCmd(0x80);
}

void LCD_WriteCmd(u8 cmd) {
	//receiving commands
	DIO_WritePin(RS, LOW);
	DIO_WritePin(RW, LOW);
	
	//sending higher nibble
	DIO_WritePin(D4, READ_BIT(cmd, 4));
	DIO_WritePin(D5, READ_BIT(cmd, 5));
	DIO_WritePin(D6, READ_BIT(cmd, 6));
	DIO_WritePin(D7, READ_BIT(cmd, 7));
	
	//sending data
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	_delay_ms(1);
	
	//sending lower nibble
	DIO_WritePin(D4, READ_BIT(cmd, 0));
	DIO_WritePin(D5, READ_BIT(cmd, 1));
	DIO_WritePin(D6, READ_BIT(cmd, 2));
	DIO_WritePin(D7, READ_BIT(cmd, 3));
	
	//sending data
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	_delay_ms(2);
}

void LCD_WriteData(u8 data) {
	
	//receiving commands
	DIO_WritePin(RS, HIGH);
	DIO_WritePin(RW, LOW);
		
	//sending higher nibble
	DIO_WritePin(D4, READ_BIT(data, 4));
	DIO_WritePin(D5, READ_BIT(data, 5));
	DIO_WritePin(D6, READ_BIT(data, 6));
	DIO_WritePin(D7, READ_BIT(data, 7));
		
	//sending data
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	_delay_ms(1);
	
	//sending lower nibble
	DIO_WritePin(D4, READ_BIT(data, 0));
	DIO_WritePin(D5, READ_BIT(data, 1));
	DIO_WritePin(D6, READ_BIT(data, 2));
	DIO_WritePin(D7, READ_BIT(data, 3));
		
	//sending data
	DIO_WritePin(EN, HIGH);
	_delay_ms(1);
	DIO_WritePin(EN, LOW);
	_delay_ms(1);
}
void LCD_WriteString(char *str) {
	u8 i = 0;
	while (str[i]!=0)
	{
		LCD_WriteData(str[i]);
		_delay_ms(1);
		i++;
	}
}

void LCD_GoTo(u8 pos_x, u8 pos_y) {
	
	u8 address = 0;
	if (pos_x == 0)
	{
		address = 0x80;
	} else if(pos_y == 1)
	{
		address = 0xC0;
	}
	if (pos_y < 16)
	{
		address += pos_y;
	}
	LCD_WriteCmd(address);

}

void LCD_WriteChar(u8 character) {
	LCD_WriteData(character);
}


void LCD_Clear() {
	LCD_WriteCmd(0x01);
	LCD_GoTo(0, 0);
}
