
#include"STD_TYPES.h"
#include"DIO.h"
#define F_CPU 8000000UL
#include"avr/delay.h"


#define   LCD_RS_PORT      DIO_PORTA
#define   LCD_RS_PIN       DIO_PIN0

#define   LCD_RW_PORT      DIO_PORTA
#define   LCD_RW_PIN       DIO_PIN1

#define   LCD_E_PORT      DIO_PORTA
#define   LCD_E_PIN       DIO_PIN2

#define   LCD_DATA_COMMAND_PORT   DIO_PORTB




//Init
void LCD_VidInit(void);


//Send command
void LCD_VidSendCommand( u8 Copy_U8Command );


//Send Data  ---> char , string , Number
void LCD_VidSendChar( u8 Copy_U8Char );


//Send String
void LCD_VidSendString( u8 *Copy_Pu8String ) ;

//Send Number
void LCD_VidSendNumber( u32 Copy_U8Number );

//Goto
void LCD_VidGoToLocation ( u8 Copy_U8RowNumber , u8 Copy_U8ColNumber );

