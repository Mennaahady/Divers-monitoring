/*
 * DIO.c
 *
 *  Created on: Oct 4, 2020
 *      Author: menna
 */

#include "STD_TYPE.h"
#include "BITCALC.h"
#include <util/delay.h>
#include "DIO_INTERFACE.h"
#include "DIO_CONFIG.h"
#include "DIO_PRIVATE.h"


int main (){

	DIO_SetPinDirection((u8)0 , DIO_OUTPUT) ;
	DIO_SetPinDirection((u8)1 , DIO_OUTPUT);
while(1){

	DIO_SetPinValue((u8)0 ,  DIO_PIN_HIGH) ;
	DIO_SetPinValue((u8)1 ,  DIO_PIN_HIGH) ;
	_delay_ms(500);
	DIO_SetPinValue((u8)0 ,  DIO_PIN_LOW) ;
	DIO_SetPinValue((u8)1 ,  DIO_PIN_LOW) ;
	_delay_ms(500);
	DIO_SetPinValue((u8)0 ,  DIO_PIN_HIGH) ;
	DIO_SetPinValue((u8)1 ,  DIO_PIN_HIGH) ;

}

}

