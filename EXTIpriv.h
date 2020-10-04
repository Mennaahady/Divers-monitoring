/*
 * EXTIpriv.h
 *
 *  Created on: Jun 13, 2020
 *      Author: menna
 */

#ifndef EXTIPRIV_H_
#define EXTIPRIV_H_

#include "avr/io.h"
#include <avr/interrupt.h>
#include "BITCALC.h"
#include "STD_TYPE.h"
#include "DIO_INTERFACE.h"


/**********************************************/

/* Defining EXT-INTR Registers              */
#define LOCAL_MCUCR 					(*(u8*)0X55)
#define LOCAL_MCUCSR 					(*(u8*)0X54)
#define LOCAL_GICR 						(*(u8*)0X5B)
#define LOCAL_GIFR 						(*(u8*)0X5A)
#define LOCAL_SREG 						(*(u8*)0X5F)
#define SREG_(I_BIT)					GIE
#define GICR_(BIT_6)					PIE

/********************************************/

#endif /* EXTIPRIV_H_ */
