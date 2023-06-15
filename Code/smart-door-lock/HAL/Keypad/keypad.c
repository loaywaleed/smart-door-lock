/*
 * keypad.c
 *
 * Created: 04/12/2022 9:40:42 pm
 *  Author: Loay
 */ 
#include "keypad.h"



//Saving all keypad button values in an array
static u8 keypad_buttons[ROWS][COLS] = {
	{'7', '8', '9', '/'},
	{'4', '5', '6', '*'},
	{'1', '2', '3', '-'},
	{'c', '0', '=', '+'}
};


u8 Keypad_GetPressedKey()
{
	u8 key = '.';
	u8 current_row, current_column;
	for (current_row=0; current_row < ROWS; current_row++){
		DIO_WritePin(OUTPUTPIN_1 + current_row, LOW);
		for(current_column = 0; current_column < COLS; current_column++)
		{
			if(!DIO_ReadPin(INPUTPIN_1 + current_column)) {
				key = keypad_buttons[current_row][current_column];
				while(!DIO_ReadPin(INPUTPIN_1 + current_column));
			}
		}
		DIO_WritePin(OUTPUTPIN_1 + current_row, HIGH);
	}
	return key;

}