/*
 * DIO_PROG.c
 *
 *  Created on: Sep 16, 2020
 *      Author: menna
 */

/**** External and General Files ****/
/* 									*/

#include "STD_TYPE.h"
#include "BITCALC.h"

#include "DIO_INTERFACE.h"
#include "DIO_CONFIG.h"
#include "DIO_PRIVATE.h"

/*									*/
/************************************/

/* Inputs:  u8PinNB : Void															 									   */
/* Outputs: u8Error : void																								   */
/*																														   */

void DIO_Init(void){
	/* SET PORT DIRECTIONS FOR PORT A PINs  ***************************************************************/
	/*																									  */

		((Register*) DDRA_REG) -> ByteAccess = BYTE_CONC(DIO_PIN7_DIRECTION,
															   DIO_PIN6_DIRECTION,
															   DIO_PIN5_DIRECTION,
															   DIO_PIN4_DIRECTION,
															   DIO_PIN3_DIRECTION,
															   DIO_PIN2_DIRECTION,
															   DIO_PIN1_DIRECTION,
															   DIO_PIN0_DIRECTION ) ;

		/* SET PORT DIRECTIONS FOR PORT B PINs  */
		((Register*) DDRB_REG) -> ByteAccess = BYTE_CONC(DIO_PIN15_DIRECTION,
															   DIO_PIN14_DIRECTION,
														       DIO_PIN13_DIRECTION,
														       DIO_PIN12_DIRECTION,
														       DIO_PIN11_DIRECTION,
														       DIO_PIN10_DIRECTION,
														       DIO_PIN9_DIRECTION ,
														       DIO_PIN8_DIRECTION ) ;

		/* SET PORT DIRECTIONS FOR PORT C PINs  */
		((Register*) DDRC_REG) -> ByteAccess = BYTE_CONC(DIO_PIN23_DIRECTION,
															   DIO_PIN22_DIRECTION,
															   DIO_PIN21_DIRECTION,
															   DIO_PIN20_DIRECTION,
															   DIO_PIN19_DIRECTION,
															   DIO_PIN18_DIRECTION,
															   DIO_PIN17_DIRECTION,
															   DIO_PIN16_DIRECTION ) ;

		/* SET PORT DIRECTIONS FOR PORT D PINs  */
		((Register*) DDRD_REG) -> ByteAccess = BYTE_CONC(DIO_PIN31_DIRECTION,
															   DIO_PIN30_DIRECTION,
															   DIO_PIN29_DIRECTION,
															   DIO_PIN28_DIRECTION,
															   DIO_PIN27_DIRECTION,
															   DIO_PIN26_DIRECTION,
															   DIO_PIN25_DIRECTION,
															   DIO_PIN24_DIRECTION ) ;



		/* SET INITIAL VALUES FOR PORT A PINs  */
		((Register*) PORTA_REG) -> ByteAccess = BYTE_CONC(DIO_PIN7_INIT_VAL,
																DIO_PIN6_INIT_VAL,
																DIO_PIN5_INIT_VAL,
																DIO_PIN4_INIT_VAL,
																DIO_PIN3_INIT_VAL,
																DIO_PIN2_INIT_VAL,
																DIO_PIN1_INIT_VAL,
																DIO_PIN0_INIT_VAL )  ;
		/* SET INITIAL VALUES FOR PORT B PINs  */
		((Register*) PORTB_REG) -> ByteAccess = BYTE_CONC(DIO_PIN15_INIT_VAL,
																DIO_PIN14_INIT_VAL,
																DIO_PIN13_INIT_VAL,
																DIO_PIN12_INIT_VAL,
																DIO_PIN11_INIT_VAL,
																DIO_PIN10_INIT_VAL,
																DIO_PIN9_INIT_VAL ,
																DIO_PIN8_INIT_VAL )  ;

		/* SET INITIAL VALUES FOR PORT C PINs  */
		((Register*) PORTC_REG) -> ByteAccess = BYTE_CONC(DIO_PIN23_INIT_VAL,
																DIO_PIN22_INIT_VAL,
																DIO_PIN21_INIT_VAL,
																DIO_PIN20_INIT_VAL,
																DIO_PIN19_INIT_VAL,
																DIO_PIN18_INIT_VAL,
																DIO_PIN17_INIT_VAL,
																DIO_PIN16_INIT_VAL ) ;

		/* SET INITIAL VALUES FOR PORT D PINs */
		((Register*) PORTD_REG) -> ByteAccess = BYTE_CONC(DIO_PIN31_INIT_VAL,
																DIO_PIN30_INIT_VAL,
																DIO_PIN29_INIT_VAL,
																DIO_PIN28_INIT_VAL,
																DIO_PIN27_INIT_VAL,
																DIO_PIN26_INIT_VAL,
																DIO_PIN25_INIT_VAL,
																DIO_PIN24_INIT_VAL ) ;


	/******************************************************************************************************/


	return ;
	}


	/*																														   */
	/***************************************************************************************************************************/

extern u8 DIO_SetPinDirection(u8 u8PinNB , u8 u8Direction ) {

	u8 Local_u8Error   ;
	u8 Local_u8PORT_ID ;
	u8 Local_u8Pin_ID  ;

	if( (u8PinNB > DIO_MAXPINNB) || ( (u8Direction>DIO_OUTPUT)&&(u8Direction!=DIO_INPUT) ) ){
		Local_u8Error = ERROR_NOK ;
	}
	else {

		Local_u8PORT_ID = u8PinNB / PINS_IN_PORT ;
		Local_u8Pin_ID  = u8PinNB % PINS_IN_PORT;


		/* Setting the Desired Pin Direction */
		switch (Local_u8PORT_ID){
		case PORTA_CHOICE:
			ASSIGN_BIT( ((Register*) DDRA_REG) -> ByteAccess , Local_u8Pin_ID , u8Direction);
			break;

		case PORTB_CHOICE:
			ASSIGN_BIT( ((Register*) DDRB_REG) -> ByteAccess , Local_u8Pin_ID , u8Direction);
			break;

		case PORTC_CHOICE:
			ASSIGN_BIT( ((Register*) DDRC_REG) -> ByteAccess , Local_u8Pin_ID , u8Direction);
			break;

		case PORTD_CHOICE:
			ASSIGN_BIT( ((Register*) DDRD_REG) -> ByteAccess , Local_u8Pin_ID , u8Direction);
			break;

		}

		Local_u8Error = ERROR_OK ;

	}


	return Local_u8Error;

}

/*																					 */
/*************************************************************************************/











/*************************************************************************************/
/* Description: Set the PINs Value ( High or Low )	        						 */
/*																					 */
/* Inputs:  u8PinNB      : The Number of Pin		         						 */
/* 		    u8Value      : The Value of the output on the chosen Pin	     		 */
/* Outputs: u8Error      : Error State												 */
/*																					 */

extern u8 DIO_SetPinValue(u8 u8PinNB , u8 u8Value ) {

	u8 Local_u8Error   ;
	u8 Local_u8PORT_ID ;
	u8 Local_u8Pin_ID  ;


	if( (u8PinNB > DIO_MAXPINNB) || ( (u8Value>DIO_PIN_HIGH)&&(u8Value!=DIO_PIN_LOW) ) ){
		Local_u8Error = ERROR_NOK ;
	}
	else {

		Local_u8PORT_ID = u8PinNB / PINS_IN_PORT ;
		Local_u8Pin_ID  = u8PinNB % PINS_IN_PORT;

		/* Setting the desired Value in required Pin */
		switch (Local_u8PORT_ID){
		case PORTA_CHOICE:
			ASSIGN_BIT( ((Register*) PORTA_REG) -> ByteAccess , Local_u8Pin_ID , u8Value);
			break;

		case PORTB_CHOICE:
			ASSIGN_BIT( ((Register*) PORTB_REG) -> ByteAccess , Local_u8Pin_ID , u8Value);
			break;

		case PORTC_CHOICE:
			ASSIGN_BIT( ((Register*) PORTC_REG) -> ByteAccess , Local_u8Pin_ID , u8Value);
			break;

		case PORTD_CHOICE:
			ASSIGN_BIT( ((Register*) PORTD_REG) -> ByteAccess , Local_u8Pin_ID , u8Value);
			break;

		}


		Local_u8Error = ERROR_OK ;
	}


	return Local_u8Error ;
}

/*																					 */
/*************************************************************************************/







/*************************************************************************************/
/* Description: Get the PINs Value ( High or Low )	        						 */
/*																					 */
/* Inputs:  u8PinNB      : The Number of Pin		         						 */
/* 		    *u8Value     : The Pointer to variable which will carry the received val.*/
/* Outputs: u8Error      : Error State												 */
/*																					 */

extern u8 DIO_GetPinValue(u8 u8PinNB , u8 * P_u8Value ) {

	u8 Local_u8Error   ;
	u8 Local_u8PORT_ID ;
	u8 Local_u8Pin_ID  ;


	if( (u8PinNB > DIO_MAXPINNB) || ( P_u8Value == NULL ) ){
		Local_u8Error = ERROR_NOK ;
	}
	else {

		Local_u8PORT_ID = u8PinNB / PINS_IN_PORT ;
		Local_u8Pin_ID  = u8PinNB % PINS_IN_PORT;

		/* Setting the desired Value in required Pin */
		switch (Local_u8PORT_ID){
		case PORTA_CHOICE:
			* P_u8Value=GET_BIT(((Register*) PINA_REG) -> ByteAccess,Local_u8Pin_ID) ;
			break;

		case PORTB_CHOICE:
			* P_u8Value=GET_BIT(((Register*) PINB_REG) -> ByteAccess,Local_u8Pin_ID) ;
			break;

		case PORTC_CHOICE:
			* P_u8Value=GET_BIT(((Register*) PINC_REG) -> ByteAccess,Local_u8Pin_ID) ;
			break;

		case PORTD_CHOICE:
			* P_u8Value=GET_BIT(((Register*) PIND_REG) -> ByteAccess,Local_u8Pin_ID) ;
			break;

		}


		Local_u8Error = ERROR_OK ;
	}


	return Local_u8Error ;
}

/*																					 */
/*************************************************************************************/






/*************************************************************************************/
/* Description: Set the PORTs Direction ( Input or Output )							 */
/*																					 */
/* Inputs:  u8PortNB     : The Number of Port		         						 */
/* 		    u8Direction  : The Direction of the chosen Pin	            			 */
/* Outputs: u8Error      : Error State												 */
/*																					 */

extern u8 DIO_SetPortDirection(u8 u8PortNB , u8 u8Direction ) {

	u8 Local_u8Error   ;


	if( (u8PortNB > DIO_PORT_MAXPINNB) ){
		Local_u8Error = ERROR_NOK ;
	}
	else {

		/* Setting the Desired Port Direction */

		switch (u8PortNB){
		case PORTA_CHOICE:
			((Register*) DDRA_REG) -> ByteAccess = u8Direction ;
			break;

		case PORTB_CHOICE:
			((Register*) DDRB_REG) -> ByteAccess = u8Direction ;
			break;

		case PORTC_CHOICE:
			((Register*) DDRC_REG) -> ByteAccess = u8Direction ;
			break;

		case PORTD_CHOICE:
			((Register*) DDRD_REG) -> ByteAccess = u8Direction ;
			break;

		}

		Local_u8Error = ERROR_OK ;

	}


	return Local_u8Error;

}

/*																					 */
/*************************************************************************************/







/*************************************************************************************/
/* Description: Set the PORTs Value ( High or Low )	        						 */
/*																					 */
/* Inputs:  u8PortNB     : The Number of Port		         						 */
/* 		    u8Value      : The Value of the output on the chosen Pin	     		 */
/* Outputs: u8Error      : Error State												 */
/*																					 */

extern u8 DIO_SetPortValue(u8 u8PortNB , u8 u8Value ) {

	u8 Local_u8Error   ;


	if( (u8PortNB > DIO_PORT_MAXPINNB) ){
		Local_u8Error = ERROR_NOK ;
	}
	else {

		/* Setting the Desired Port Direction */

		switch (u8PortNB){
		case PORTA_CHOICE:
			((Register*) PORTA_REG) -> ByteAccess = u8Value ;
			break;

		case PORTB_CHOICE:
			((Register*) PORTB_REG) -> ByteAccess = u8Value ;
			break;

		case PORTC_CHOICE:
			((Register*) PORTC_REG) -> ByteAccess = u8Value ;
			break;

		case PORTD_CHOICE:
			((Register*) PORTD_REG) -> ByteAccess = u8Value ;
			break;

		}

		Local_u8Error = ERROR_OK ;

	}


	return Local_u8Error;

}

/*																					 */
/*************************************************************************************/







/*************************************************************************************/
/* Description: Get the PORTs Value ( High or Low )	        						 */
/*																					 */
/* Inputs:  u8PortNB     : The Number of Port		         						 */
/* 		    *u8Value     : The Pointer to variable which will carry the received val.*/
/* Outputs: u8Error      : Error State												 */
/*																					 */

extern u8 DIO_GetPortValue(u8 u8PortNB , u8 * P_u8Value ) {

	u8 Local_u8Error   ;



	if( (u8PortNB > DIO_PORT_MAXPINNB) || ( P_u8Value == NULL ) ){
		Local_u8Error = ERROR_NOK ;
	}
	else {



		/* Setting the desired Value in required Pin */
		switch (u8PortNB){
		case PORTA_CHOICE:
			* P_u8Value=((Register*) PINA_REG) -> ByteAccess ;
			break;

		case PORTB_CHOICE:
			* P_u8Value=((Register*) PINB_REG) -> ByteAccess ;
			break;

		case PORTC_CHOICE:
			* P_u8Value=((Register*) PINC_REG) -> ByteAccess ;
			break;

		case PORTD_CHOICE:
			* P_u8Value=((Register*) PIND_REG) -> ByteAccess ;
			break;

		}



		Local_u8Error = ERROR_OK ;
	}


	return Local_u8Error ;
}

/*																					 */
/*************************************************************************************/




