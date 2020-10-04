
#include "avr/io.h"
#include <avr/interrupt.h>
#include "BITCALC.h"
#include "STD_TYPE.h"
#include "DIO_INTERFACE.h"
#include <util/delay.h>
#include "EXTIheader.h"
#include "EXTIpriv.h"
#include "EXTIconfig.h"

/****************************************************************************/

 int main (void){

	SET_BIT(LOCAL_SREG,7);

	// setting pin as input with pull-up:
	DIO_SetPinDirection((u8)26 , 0); //INT0 PIN
    DIO_SetPinValue((u8)26 , 1 ) ;

    /*
     * DIO_SetPinDirection((u8)27 , 0); //INT1 PIN
   	   DIO_SetPinValue((u8)27 , 1 ) ;

   	   DIO_SetPinDirection((u8)10 , 0); //INT2 PIN
   	   DIO_SetPinValue((u8)10 , 1 ) ;
     */
    DIO_SetPinDirection((u8)5 , 1);
	 while(1){
		    DIO_SetPinValue((u8)5 , 1 ) ;
		 }
	 }

    void __vector_1(void) __attribute__((signal));		// 1 is changed according to vector number
    void __vector_1(void){
    	 DIO_SetPinValue((u8)5 , 0 );		//LED test
    }
/*
  void __vector_2(void) __attribute__((signal));		// 2 is changed according to vector number
    void __vector_2(void){
    	 DIO_SetPinValue((u8)5 , 0 );		//LED test

    	  void __vector_3(void) __attribute__((signal));		// 1 is changed according to vector number
    void __vector_3(void){
    	 DIO_SetPinValue((u8)5 , 0 );		//LED test
 */
