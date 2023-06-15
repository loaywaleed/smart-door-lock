/*
 * DIO_Config.c
 *
 * Created: 03/12/2022 8:03:04 pm
 *  Author: Loay
 */ 
#include "Dio_Types.h"
const PIN_STATUS pin_status_arr[TOTAL_PINS] =
{
	OUTPUT,      /* Port A Pin 0 ADC0*/
	OUTPUT,      /* Port A Pin 1 */
	OUTPUT,      /* Port A Pin 2 */
	OUTPUT,      /* Port A Pin 3 */
	OUTPUT,      /* Port A Pin 4 */
	OUTPUT,      /* Port A Pin 5 */
	OUTPUT,      /* Port A Pin 6 */
	OUTPUT,      /* Port A Pin 7 */
	OUTPUT,      /* Port B Pin 0 */
	OUTPUT,      /* Port B Pin 1 */
	OUTPUT,		 /* Port B Pin 2 */
	OUTPUT,		 /* Port B Pin 3 */
	OUTPUT,		 /* Port B Pin 4 */
	OUTPUT,		 /* Port B Pin 5 */
	OUTPUT,		 /* Port B Pin 6 */
	OUTPUT,		 /* Port B Pin 7 */
	OUTPUT,		 /* Port C Pin 0 */			//keypad output
	OUTPUT,		 /* Port C Pin 1 */			//keypad output
	OUTPUT,		 /* Port C Pin 2 */			//keypad output
	OUTPUT,		 /* Port C Pin 3 */			//keypad output
	INPLUP,		 /* Port C Pin 4 */		    //keypad input
	INPLUP,		 /* Port C Pin 5 */		    //keypad input
	INPLUP,		 /* Port C Pin 6 */		    //keypad input
	INPLUP,		 /* Port C Pin 7 */		    //keypad input
	OUTPUT,		 /* Port D Pin 0 */		 
	OUTPUT,		 /* Port D Pin 1 */		
	OUTPUT,      /* Port D Pin 2 */		 
	OUTPUT,      /* Port D Pin 3 */		
	OUTPUT,		 /* Port D Pin 4 */
	OUTPUT,		 /* Port D Pin 5 */
	OUTPUT,		 /* Port D Pin 6 */
	OUTPUT		 /* Port D Pin 7 */
};