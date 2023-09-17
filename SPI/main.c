#include"avr/io.h"
#include"SPI.h"
#include"DIO.h"
#include"util/delay.h"
#define F_CPU 8000000UL



void main(void){
	u8 read;
DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
DIO_VidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_HIGH);
SPI_MasterInit();

while(1){
	read =SPI_u8MasterTracieve('N');
	if(read==10){
		DIO_VidTogglePinValue(DIO_PORTA,DIO_PIN0);

	}
	_delay_ms(3000);
	read =SPI_u8MasterTracieve('F');
	if(read==10){
		DIO_VidTogglePinValue(DIO_PORTA,DIO_PIN0);
	}
	_delay_ms(3000);


}


}



