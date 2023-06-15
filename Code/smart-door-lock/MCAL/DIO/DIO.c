#include "DIO.h"


void DIO_Init()
{
	PORT_TYPE port ;
	PIN_STATUS status ;
	u8 pin_ID ;
	u8 Current_pin;
	for(Current_pin = 0; Current_pin < TOTAL_PINS; Current_pin++)
	{
		status = pin_status_arr[Current_pin];
		port = Current_pin / 8;
		pin_ID = Current_pin % 8 ;
		
		switch(status)
		{
			case OUTPUT:
			switch(port)
			{
				case PA:
				SET_BIT(DDRA , pin_ID);
				break;
				case PB:
				SET_BIT(DDRB , pin_ID);
				break;
				case PC:
				SET_BIT(DDRC , pin_ID);
				break;
				case PD:
				SET_BIT(DDRD , pin_ID);
				break;
			}
			break;
			case INPUT:
			switch(port)
			{
				case PA:
				CLEAR_BIT(DDRA , pin_ID);
				CLEAR_BIT(PORTA , pin_ID);
				break;
				case PB:
				CLEAR_BIT(DDRB , pin_ID);
				CLEAR_BIT(PORTB , pin_ID);
				break;
				case PC:
				CLEAR_BIT(DDRC , pin_ID);
				CLEAR_BIT(PORTC , pin_ID);
				break;
				case PD:
				CLEAR_BIT(DDRD , pin_ID);
				CLEAR_BIT(PORTD , pin_ID);
				break;
			}
			break;
			case INPLUP:
			switch(port)
			{
				case PA:
				CLEAR_BIT(DDRA , pin_ID);
				SET_BIT(PORTA , pin_ID);
				break;
				case PB:
				CLEAR_BIT(DDRB , pin_ID);
				SET_BIT(PORTB , pin_ID);
				break;
				case PC:
				CLEAR_BIT(DDRC , pin_ID);
				SET_BIT(PORTC , pin_ID);
				break;
				case PD:
				CLEAR_BIT(DDRD , pin_ID);
				SET_BIT(PORTD , pin_ID);
				break;
			}
			break;
		}
	}
}


void DIO_WritePin(PIN_TYPE pin, VOLTAGE_VALUE voltage)
{
	PORT_TYPE port = pin/8;
	u8 pin_number = pin%8;
	switch(voltage)
	{
		case HIGH:
		switch(port)
		{
			case PA:
			SET_BIT(PORTA, pin_number);
			break;
			case PB:
			SET_BIT(PORTB, pin_number);
			break;
			case PC:
			SET_BIT(PORTC, pin_number);
			break;
			case PD:
			SET_BIT(PORTD, pin_number);
			break;
		}
		break;
		case LOW:
		switch(port)
		{
			case PA:
			CLEAR_BIT(PORTA, pin_number);
			break;
			case PB:
			CLEAR_BIT(PORTB, pin_number);
			break;
			case PC:
			CLEAR_BIT(PORTC, pin_number);
			break;
			case PD:
			CLEAR_BIT(PORTD, pin_number);
			break;
		}
		break;
	}
	
}


VOLTAGE_VALUE DIO_ReadPin(PIN_TYPE pin)
{
	PORT_TYPE port = pin/8;
	u8 pin_number = pin%8;
	switch(port)
	{
		case PA:
		return READ_BIT(PINA, pin_number);
		break;
		case PB:
		return READ_BIT(PINB, pin_number);
		break;
		case PC:
		return READ_BIT(PINC, pin_number);
		break;
		case PD:
		return READ_BIT(PIND, pin_number);
		break;
		default:
		return 0;
		break;
	}	
	
}


void DIO_WritePort(PORT_TYPE port, u8 data)
{
	switch(port)
	{
		case PA:
		PORTA = data;
		break;
		case PB:
		PORTB = data;
		break;
		case PC:
		PORTC = data;
		break;
		case PD:
		PORTD = data;
		break;
	}
}


u8 DIO_ReadPort(PORT_TYPE port)
{
	switch(port)
	{
		case PA:
		return PINA;
		break;
		case PB:
		return PINB;
		break;
		case PC:
		return PINC;
		break;
		case PD:
		return PIND;
		break;
		default:
		return 0;
		break;
		
	}
}


void DIO_TogglePin(PIN_TYPE pin)
{
	PORT_TYPE port = pin/8;
	u8 pin_num = pin%8;
	switch(port)
	{
		case PA:
		TOGGLE_BIT(PORTA, pin_num);
		break;
		case PB:
		TOGGLE_BIT(PORTB, pin_num);
		break;
		case PC:
		TOGGLE_BIT(PORTC, pin_num);
		break;
		case PD:
		TOGGLE_BIT(PORTD, pin_num);
		break;	
	}
}

