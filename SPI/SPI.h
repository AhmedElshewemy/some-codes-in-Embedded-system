/*
 * SPI.h
 *
 *  Created on: Aug 24, 2023
 *      Author: btc
 */

#ifndef SPI_H_
#define SPI_H_
#include"STD_TYPES.h"


void SPI_MasterInit(void);
u8 SPI_u8MasterTracieve(u8 Date);
void SPI_SelveInit(void);
u8 SPI_u8SlaveTracieve(u8 Date);



#endif /* SPI_H_ */
