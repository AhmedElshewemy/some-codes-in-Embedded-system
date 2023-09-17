#include"USART.h"
#define F_CPU 8000000UL
#include"avr/delay.h"

#include"DIO.h"

void main(void)
{
	DIO_VidSetPinDirection( DIO_PORTD , DIO_PIN0 , DIO_INPUT );
	DIO_VidSetPinDirection( DIO_PORTD , DIO_PIN1 , DIO_OUTPUT );

	USART_VidInit();


	while(1)
	{
		_delay_ms(500);
		USART_VidSendChar('a');

	}
}
