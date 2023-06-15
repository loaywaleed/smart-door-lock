/*
 * door_lock.c
 *
 * Created: 05/12/2022 12:55:25 pm
 *  Author: Loay
 */ 
#include "door_lock.h"

void unlock(bool_t bool) {
	if (bool == TRUE) {
		Servo_Angle(0);
		DIO_WritePin(CORRECT_PASS_LED, HIGH);
		DIO_WritePin(WRONG_PASS_LED, LOW);
		LCD_Clear();
 		LCD_GoTo(0, 0);
 		LCD_WriteString("Welcome");
		_delay_ms(1500);
		DIO_WritePin(CORRECT_PASS_LED, LOW);
		 
	} else if (bool == FALSE) {
		Servo_Angle(180);
		DIO_WritePin(WRONG_PASS_LED, HIGH);
		DIO_WritePin(CORRECT_PASS_LED, LOW);
		_delay_ms(1500);
		DIO_WritePin(WRONG_PASS_LED, LOW);
	}
}
