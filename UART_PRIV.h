/*
 * UART_PRIV.h
 *
 *  Created on: Mar 24, 2020
 *      Author: menna
 */

#ifndef UART_PRIV_H_
#define UART_PRIV_H_

#include "BITCALC.h"
#include "STD_TYPE.h"

#define UCSRC (*(u8*)0x40)
#define UCSRA (*(u8*)0x2B)
#define UCSRB (*(u8*)0x2A)
#define UBRRL (*(u8*)0x29)
#define UDR (*(u8*)0x2C)
#define UBRRH (*(u8*)0x40)
#define SPCR (*(u8*)0x2D)
#define SPDR (*(u8*)0x2F)
#define SPSR (*(u8*)0x2E)


	#endif /* UART_PRIV_H_ */
