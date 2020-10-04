/*
 * UART_main.c
 *
 *  Created on: Mar 31, 2020
 *      Author: menna
 */

#include<avr/io.h>
#include "BITCALC.h"
#include "STD_TYPE.h"
#include "UART_PRIV.h"
#include "UART_Config.h"
#include "DIO_INTERFACE.h"
#include "DIO_CONFIG.h"
#include "DIO_PRIVATE.h"
#include "UART_Header.h"
#include <util/delay.h>
#include"LCDpriv.h"
#include"LCDheader.h"






int main (void){


		UCSRA=0b0000000;
		UCSRC=0b10000110;
		UCSRB=0b00011000;
		UBRRH=0b00000000;
		UBRRL=51;

		DIO_SetPortDirection( 0 ,  1 ) ;
		DIO_SetPinDirection( 8 ,  1 ) ;
		DIO_SetPinDirection( 9 ,  1 ) ;
		DIO_SetPinDirection( 10 ,  1 ) ;
		init_LCD();
		UART_INIT();

		u32 RX;


		while (1){
	RX=Receive_String();
	LCD_write_string(RX);
			_delay_ms(2000);
		}


}


