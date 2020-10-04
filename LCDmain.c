/*
 * LCDmain.c
 *
 *  Created on: May 19, 2020
 *      Author: menna
 */
#include<avr/io.h>
#include<util/delay.h>
#include"LCDpriv.h"
#include"LCDheader.h"
#include "UART_PRIV.h"
#include "UART_Config.h"
#include "UART_Header.h"
#include "DIO_INTERFACE.h"
#include "DIO_CONFIG.h"
#include "DIO_PRIVATE.h"


	int main (void)
	{
	DIO_SetPortDirection( 0 ,  1 ) ;
	DIO_SetPinDirection( 8 ,  1 ) ;
	DIO_SetPinDirection( 9 ,  1 ) ;
	DIO_SetPinDirection( 10 ,  1 ) ;

	init_LCD();
	LCD_write_string("A,B,C");
	LCD_cmd(0xc0);
	return 0;
	}


