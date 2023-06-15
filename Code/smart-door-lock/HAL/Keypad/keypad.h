/*
 * keypad.h
 *
 * Created: 04/12/2022 9:40:22 pm
 *  Author: Loay
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "..\..\MCAL\DIO\DIO.h"

#define ROWS	4
#define COLS	4
//set as output in DIO_Config file
#define OUTPUTPIN_1		PINC0
//set as input pull-up in DIO_Config file
#define INPUTPIN_1		PINC4


u8 Keypad_GetPressedKey();




#endif /* KEYPAD_H_ */