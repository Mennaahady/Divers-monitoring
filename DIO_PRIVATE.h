/*
 * DIO_PRIVATE.h
 *
 *  Created on: Sep 16, 2020
 *      Author: menna
 */
/************************************************************************************/
/* Description : This is a Private file that contains the private definitions and  */
/*               functions implementations are needed to use in the DIO.												*/
/*																					*/
/* Created on  : Sep 26, 2020 														*/
/* Author      : Menna																*/
/************************************************************************************/


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/********* Hardware Dependencies ************/
/*									        */

/* Defining the Number of Pins in port      */
#define PINS_IN_PORT   8

/* Defining maximum No. of pins available   */
#define DIO_MAXPINNB         31

/* Defining maximum No. of ports            */
#define DIO_PORT_MAXPINNB    3

/* Defining PORTA DDR,PORT,PIN              */
#define DDRA_REG             0x3A
#define PORTA_REG            0x3B
#define PINA_REG			   0x39

/* Defining PORTB DDR,PORT,PIN              */
#define DDRB_REG             0x37
#define PORTB_REG            0x38
#define PINB_REG			   0x36

/* Defining PORTC DDR,PORT,PIN              */
#define DDRC_REG             0x34
#define PORTC_REG            0x35
#define PINC_REG			   0x33

/* Defining PORTD DDR,PORT,PIN              */
#define DDRD_REG             0x31
#define PORTD_REG            0x32
#define PIND_REG			   0x30

/* Defining the Input and Output Values     */
#define DIO_INPUT  				   0
#define DIO_OUTPUT 				   1

/* Defining the Low and High Output Values  */
/* MUST BE CHANGED ***************************************************/
#define DIO_PIN_LOW     		   0
#define DIO_PIN_HIGH   			   1

/*									        */
/********************************************/



#endif /* DIO_PRIVATE_H_ */
