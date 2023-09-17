#ifndef KBD_H_
#define KBD_H_
#include"avr/delay.h"
#include"DIO.h"




#define   KBD_PORT  DIO_PORTD


void KBD_VidInit(void);


u8 KBD_U8GetPressedKey(void);




#endif
