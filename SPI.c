/*
 * SPI.c
 *
 *  Created on: Apr 2, 2020
 *      Author: menna
 */
#include "SPI_config.h"
#include "SPI_Private.h"
#include "STD_TYPE.h"
#include "BITCALC.h"
#include "SPI_Interface.h"
#include <util/delay.h>
#include"LCDpriv.h"
#include"LCDheader.h"




int main(void){

	DIO_SetPortDirection( 0 ,  1 ) ;
	DIO_SetPinDirection( 8 ,  1 ) ;
	DIO_SetPinDirection( 9 ,  1 ) ;
	DIO_SetPinDirection( 10 ,  1 ) ;
	init_LCD();
	SPI_Initialize();

	u8 RX='z';


	while (1){
RX=SPI_ReceiveChar();
LCD_write(RX);
		_delay_ms(2000);
	}
}
