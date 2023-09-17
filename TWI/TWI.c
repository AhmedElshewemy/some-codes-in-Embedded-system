#include "TWI.h"

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"avr/io.h"


void TWI_VidMasterInit(void){
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);

    TWBR=3;
    SET_BIT(TWCR,TWEN);
}



void TWI_VidStartCondition(void){

}


void TWI_VidSalveAddress(u8 U8copySalveAdress){

}



void TWI_VidMasterSendDate(u8 U8date){

}


u8 TWI_VidMasterResDate(void){

}

void TWI_VidStopCondition(void){

}




/////////////////////////////////





void TWI_VidSalveInit(u8 copy_U8SlaveAddress){


	TWAR=(copy_U8SlaveAddress<<1);



SET_BIT(TWCR,TWEN);

}

void TWI_VidSlaveSendDate(u8 U8copyDate){




}

void TWI_VidSlaveResDate(u8 U8copyDate){




}






