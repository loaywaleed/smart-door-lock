/*
 * types.h
 *
 * Created: 23/10/2022 7:30:40 am
 *  Author: Loay
 */ 


#ifndef TYPES_H_
#define TYPES_H_



typedef enum{
	PINA0=0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS=32
} PIN_TYPE;

typedef enum{
	LOW=0,
	HIGH
} VOLTAGE_VALUE;

typedef enum{
	OUTPUT=0,
	INPUT,
	INPLUP
} PIN_STATUS;

typedef enum{
	PA=0,
	PB,
	PC,
	PD
} PORT_TYPE;

extern const PIN_STATUS pin_status_arr[TOTAL_PINS];



#endif /* TYPES_H_ */