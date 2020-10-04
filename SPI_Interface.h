/*
 * SPI_Interface.h
 *
 *  Created on: Oct 5, 2019
 *      Author: lenovo
 */
#include"STD_TYPE.h"
#include"BITCALC.h"
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_
#define INTR_ENABLE 1
#define INTR_DISABLE 0
#define SPI_ON 1
#define SPI_OFF 0
#define CPOL_ENABLE 1
#define CPOL_DISABLE 0
#define CPHA_ENABLE 1
#define CPHA_DISABLE 0
#define MASTER_ENABLE 1
#define SLAVE_ENABLE 1
#define IntrF_Enable 1
#define IntrF_Disable 0



void SPI_Initialize(void);
u8 SPI_ReceiveString(u8*ptr );
void SPI_SendString (u8*ptr);
void SPI_sendChar(u8 u8data);
u8 SPI_ReceiveChar();
#define MASTER 0
#define SLAVE 1
#endif /* SPI_INTERFACE_H_ */
