/*
 * lcd.h
 *
 * Created: 04/12/2022 11:11:39 am
 *  Author: Loay
 */ 


#ifndef LCD_H_
#define LCD_H_

/*----------Pin defines----------*/
#define		LCD_PORT	PORTA
#define		RS			PINB0
#define		RW			PINB1
#define		EN			PINB2

#define		D4			PINA4
#define		D5			PINA5
#define		D6			PINA6
#define		D7			PINA7


/*----------Functions----------*/
void LCD_Init();
void LCD_WriteCmd(u8 cmd);
void LCD_WriteData(u8 data);
void LCD_WriteString(char *str);
void LCD_WriteChar(u8 character);
void LCD_GoTo(u8 pos_x, u8 pos_y);
void LCD_Clear();




#endif /* LCD_H_ */