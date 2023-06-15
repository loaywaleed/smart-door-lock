/*
 * Servo.c
 *
 * Created: 05/12/2022 12:11:20 pm
 *  Author: Loay
 */ 
#include "servo.h"

void Servo_Init() {
	//DDRD |= (1<<PD5);	/* Make OC1A pin as output */
	TCNT1 = 0;		/* Set timer1 count zero */
	ICR1 = 2499;		/* Set TOP count for timer1 in ICR1 register */

	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
	TCCR1A = (1<<WGM11)|(1<<COM1A1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);

}

void Servo_Angle(u8 angle) {
	if (angle == 0) {
		OCR1A = 65;	/* Set servo shaft at -90° position */	
	} else if (angle == 90) {
		OCR1A = 175;	
	} else if (angle == 180) {
		OCR1A = 300;
	}
}
