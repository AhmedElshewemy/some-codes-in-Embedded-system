#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"DIO.h"
#include"avr/interrupt.h"
//#include"SPI.h"



void SPI_MasterInit(void){
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_INPUT);
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN4,DIO_OUTPUT);
	DIO_VidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_HIGH);
	SPCR=0b01011110;

	/*there's another bit to make the pre_scaler (Fosc/64) */
	/*but it will be zero, so i won't change, and the default is zero */
}

u8 SPI_u8MasterTracieve(u8 Date)
{
	DIO_VidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_LOW);
	SPDR=Date;

	while((GET_BIT(SPSR,SPIF))==0);

	DIO_VidSetPinValue(DIO_PORTB,DIO_PIN4,DIO_HIGH);


	return SPDR;
	//return the data that was recieved from the slave


}



void SPI_SelveInit(void){
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_INPUT);
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_INPUT);
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN4,DIO_INPUT);
	SPCR=0b01001110;

}




u8 SPI_u8SlaveTracieve(u8 Date)
{
	SPDR=Date;

	while((GET_BIT(SPSR,SPIF))==0);

	return SPDR;
	//return the data that was recieved from the Master


}
