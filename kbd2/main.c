
#include"DIO.h"
#include"LCD.h"

void main(void)
{
	u8 str[] = "ahmed" ;

	LCD_VidInit();

	LCD_VidGoToLocation( LCD_Second_LINE , 2 );
	LCD_VidSendString(str);

	while(1);
}

