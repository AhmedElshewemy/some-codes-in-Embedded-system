

#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"Timers.h"
#include"DIO.h"
#include"avr/interrupt.h"


void TOGGLE_LED(void);

void main(void)
{
	DIO_VidSetPinDirection( DIO_PORTA , DIO_PIN0 , DIO_OUTPUT );
	Timers_VidTimer0SetCallBack(&TOGGLE_LED);
	Timers_VidTimer0Init();


	while(1);
}


void TOGGLE_LED(void)
{
	DIO_VidTogglePinValue( DIO_PORTA , DIO_PIN0 );
}


/*
 *          Toggle Led Every One sec using Timer --> OVF mode
 *
 *          F_CPU = 8M Hz , prescaler = 8 , res = 8 bits
 *
 *          number of OVF = ?    , Preload value = ?
 *
 *          Timer Frequency =  8M / 8 = 1M
 *          Timer Tick Time = 1 / 1M = 1us   ----> inc every 1us
 *          Time of OVFs  = 1us * 256 = 256 us
 *
 *				1sec = 1000000us > 256us
 *
 *          Number of OVFs = 1000000u / 256u = 3906.25 ---> 3906 complete OVF + 0.25 OVF
 *
 *          Number of ticks for  0.25  = 0.25 * 256 = 64
 *
 *          prelaod value  = 256 - 64 = 192 tick  ---> 3907
 *
 *
//////
 *          Toggle Led Every One sec using Timer --> CTC mode
 *
 *          F_CPU = 8M Hz , prescaler = 8 , res = 8 bits , OCR = 99
 *
 *            Preload value = ? , number of CTC  = ?
 *
 *          Timer Frequency =  8M / 8 = 1M
 *          Timer Tick Time = 1 / 1M = 1us   ----> inc every 1us
 *          Time of CTCs  = 100 * 1us = 100us
 *
 *				1sec = 1000000us > 100us
 *
 *          Number of CTCs = 1000000u / 100u = 10000 time
 *
 *          prelaod value  = 0
 *
 *
 *
 */








