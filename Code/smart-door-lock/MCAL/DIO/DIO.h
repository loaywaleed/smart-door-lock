
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "../../atmega16.h"
#include "../../bit_math.h"
#include "../../std_datatypes.h"
#include "DIO_Types.h"



void DIO_WritePin(PIN_TYPE pin, VOLTAGE_VALUE voltage);
VOLTAGE_VALUE DIO_ReadPin(PIN_TYPE pin);
void DIO_WritePort(PORT_TYPE port, u8 data);
VOLTAGE_VALUE DIO_ReadPort(PORT_TYPE port);
void DIO_TogglePin(PIN_TYPE pin);
void DIO_Init();





#endif /* DIO_INTERFACE_H_ */