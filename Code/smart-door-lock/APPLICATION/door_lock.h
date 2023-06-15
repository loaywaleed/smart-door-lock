/*
 * door_lock.h
 *
 * Created: 05/12/2022 12:53:00 pm
 *  Author: Loay
 */ 


#ifndef DOOR_LOCK_H_
#define DOOR_LOCK_H_

#define F_CPU	8000000UL
#include "../MCAL/DIO/DIO.h"
#include "../HAL/Servo/Servo.h"
#include "../HAL/LCD/lcd.h"
#include "../HAL/Keypad/keypad.h"
#include <util/delay.h>

#define		CORRECT_PASS_LED	PIND0
#define		WRONG_PASS_LED		PIND1 


void unlock(bool_t bool);




#endif /* DOOR-LOCK_H_ */