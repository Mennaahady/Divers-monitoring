/*
 * DIO_INTERFACE.h
 *
 *  Created on: Sep 16, 2020
 *      Author: menna
 */


#include "BITCALC.h"
#include "STD_TYPE.h"

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_



/**** Defining the Port Number in Numbers ***/
/*                                          */

#define PORTA_CHOICE	       0
#define PORTB_CHOICE	       1
#define PORTC_CHOICE	       2
#define PORTD_CHOICE	       3

/*                                          */
/********************************************/

#define High	1
#define Low		0
#define Input	0
#define Output	1


/**** Defining the Pin Number in Numbers ****/
/*                                          */

#define DIO_PIN0  (u8)0
#define DIO_PIN1  (u8)1
#define DIO_PIN2  (u8)2
#define DIO_PIN3  (u8)3
#define DIO_PIN4  (u8)4
#define DIO_PIN5  (u8)5
#define DIO_PIN6  (u8)6
#define DIO_PIN7  (u8)7
#define DIO_PIN8  (u8)8
#define DIO_PIN9  (u8)9
#define DIO_PIN10 (u8)10
#define DIO_PIN11 (u8)11
#define DIO_PIN12 (u8)12
#define DIO_PIN13 (u8)13
#define DIO_PIN14 (u8)14
#define DIO_PIN15 (u8)15
#define DIO_PIN16 (u8)16
#define DIO_PIN17 (u8)17
#define DIO_PIN18 (u8)18
#define DIO_PIN19 (u8)19
#define DIO_PIN20 (u8)20
#define DIO_PIN21 (u8)21
#define DIO_PIN22 (u8)22
#define DIO_PIN23 (u8)23
#define DIO_PIN24 (u8)24
#define DIO_PIN25 (u8)25
#define DIO_PIN26 (u8)26
#define DIO_PIN27 (u8)27
#define DIO_PIN28 (u8)28
#define DIO_PIN29 (u8)29
#define DIO_PIN30 (u8)30
#define DIO_PIN31 (u8)31

/*                                          */
/********************************************/

void DIO_Init( void ) ;

/********************************************/

u8 DIO_SetPinDirection(u8 u8PinNB , u8 u8Direction ) ;

/********************************************/

u8 DIO_SetPinValue(u8 u8PinNB , u8 u8Value ) ;

/********************************************/

u8 DIO_GetPinValue(u8 u8PinNB , u8 * P_u8Value ) ;

/********************************************/

u8 DIO_SetPortDirection(u8 u8PortNB , u8 u8Direction ) ;

/********************************************/

u8 DIO_SetPortValue(u8 u8PortNB , u8 u8Value ) ;

/********************************************/

u8 DIO_GetPortValue(u8 u8PortNB , u8 * P_u8Value ) ;

/********************************************/

#endif /* DIO_INTERFACE_H_ */
