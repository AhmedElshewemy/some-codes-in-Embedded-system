#include"LCD.h"

void LCD_VidInit(void)
{
	//Directions
	DIO_VidSetPinDirection( LCD_RS_PORT , LCD_RS_PIN , DIO_OUTPUT );
	DIO_VidSetPinDirection( LCD_RW_PORT , LCD_RW_PIN , DIO_OUTPUT );
	DIO_VidSetPinDirection( LCD_E_PORT , LCD_E_PIN , DIO_OUTPUT );
	DIO_VidSetPortDirection( LCD_DATA_COMMAND_PORT , 0b11111111 );


	_delay_ms(35);

	LCD_VidSendCommand( 0b00111000 );

	_delay_us(45);

	LCD_VidSendCommand( 0b00001100 );

	_delay_us(45);

	LCD_VidSendCommand( 0b00000001 );

	_delay_ms(2);

	LCD_VidSendCommand( 0b00000110 );

}


void LCD_VidSendCommand( u8 Copy_U8Command )
{
	//RS = 0
	DIO_VidSetPinValue( LCD_RS_PORT , LCD_RS_PIN , DIO_LOW );

	//RW = 0
	DIO_VidSetPinValue( LCD_RW_PORT , LCD_RW_PIN , DIO_LOW );

	//Command
	DIO_VidSetPortValue( LCD_DATA_COMMAND_PORT , Copy_U8Command ) ;


	//E
	DIO_VidSetPinValue( LCD_E_PORT , LCD_E_PIN , DIO_HIGH );

	_delay_us(1);

	DIO_VidSetPinValue( LCD_E_PORT , LCD_E_PIN , DIO_LOW );

}


void LCD_VidSendChar( u8 Copy_U8Char )
{
	//RS =1
	DIO_VidSetPinValue( LCD_RS_PORT , LCD_RS_PIN , DIO_HIGH );

	//RW = 0
	DIO_VidSetPinValue( LCD_RW_PORT , LCD_RW_PIN , DIO_LOW );

	//Command
	DIO_VidSetPortValue( LCD_DATA_COMMAND_PORT , Copy_U8Char ) ;


	//E
	DIO_VidSetPinValue( LCD_E_PORT , LCD_E_PIN , DIO_HIGH );

	_delay_us(1);

	DIO_VidSetPinValue( LCD_E_PORT , LCD_E_PIN , DIO_LOW );

}










