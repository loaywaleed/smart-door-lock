/*
 * door-lock-project.c
 *
 * Created: 04/12/2022 10:41:51 am
 * Author : Loay
 */ 
#define F_CPU 8000000UL
#include "MCAL/DIO/DIO.h"
#include "HAL/LCD/lcd.h"
#include "HAL/Keypad/keypad.h"
#include "HAL/Servo/servo.h"
#include "APPLICATION/door_lock.h"
#include <util/delay.h>

#define P		1

int main(void)
{
	//Hardware initialization
	DIO_Init();
	LCD_Init();
	Servo_Init();
	//Variables declaration
	u8 wrong = 0;
	u8 entry_pass[3] = {'1','2','3'};
	u8 pos = 0;
	LCD_GoTo(0, 0);
	LCD_WriteString("Enter Password:");

    while (1) 
	{
	u8 key[3] = {0};
	//getting user input 
	u8 user_input = Keypad_GetPressedKey();
	if (user_input != '.') {
		LCD_Clear();
		LCD_GoTo(pos, 0);
		LCD_WriteChar(user_input);
		_delay_ms(50);
			if (user_input == '*') {
				pos = 0;
				unlock(FALSE);
				DIO_WritePin(WRONG_PASS_LED, LOW);
				LCD_Clear();
				LCD_GoTo(0, 0);
				LCD_WriteString("Door Locked");
				_delay_ms(1500);
				LCD_Clear();
				LCD_GoTo(0, 0);
				LCD_WriteString("Enter Password:");
			}
			else if (user_input == entry_pass[pos]) {
				key[pos] == user_input;
				pos++;
			}
			else if (user_input != entry_pass[pos]) {
				wrong++;
				pos++;
			}
			if (pos == 3) {
				if (wrong > 0) {
					wrong = 0;
					pos = 0;
					LCD_Clear();
					LCD_GoTo(0, 0);
					LCD_WriteString(" Denied");
					unlock(FALSE);
					_delay_ms(2000);
					LCD_Clear();
					LCD_GoTo(0, 0);
					LCD_WriteString("Enter Password:");
				}
				else if (pos == 3 && wrong == 0) {
					pos = 0;
					wrong = 0;
					LCD_Clear();
					LCD_GoTo(0, 0);
					LCD_WriteString(" Accepted");
					unlock(TRUE);
					
				}
			}
	}		
    }
}

