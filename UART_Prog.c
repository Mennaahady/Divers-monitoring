/*
 * UART_INIT.h
 *
 *  Created on: Mar 24, 2020
 *      Author: menna
 */

#ifndef UART_PROG_C_
#define UART_PROG_C_
#include "UART_Header.h"
#include "UART_PRIV.h"
#include "UART_Config.h"
#include "BITCALC.h"
#include "STD_TYPE.h"
#include "DIO_INTERFACE.h"

u8 Uart_Initial =0;
void UART_INIT(void){

	switch (UARTSPEED){
		case 0:		//Normal speed
			CLR_BIT(UCSRA,1);
			break;
		case 1:		//Double speed
			SET_BIT(UCSRA,1);
			break;
	}

	switch (TXC){
			case 1:		//TXC flag enable
				SET_BIT(UCSRA,6);
				break;
			case 0:		//TXC flag disable
				CLR_BIT(UCSRA,6);
				break;
	}

		switch (RXC){
				case 1:		//RXC flag enable
					SET_BIT(UCSRA,7);
					break;
				case 0:		//RXC flag disable
					CLR_BIT(UCSRA,7);
					break;
		}

	switch (TXEN){
		case 1:		//TX enable
			SET_BIT(UCSRB,3);
			break;
		case 0:		//TX disable
			CLR_BIT(UCSRB,3);
			break;
}

	switch (RXEN){
			case 1:		//RX enable
				SET_BIT(UCSRB,4);
				break;
			case 0:		//RX disable
				CLR_BIT(UCSRB,4);
				break;
	}

	switch (RXINT){
		case 1:		//RX interrupt enable
			SET_BIT(UCSRB,7);
			break;
		case 0:		//RX interrupt disable
			CLR_BIT(UCSRB,7);
			break;
}


		switch (TXINT){
			case 1:		//TX interrupt enable
				SET_BIT(UCSRB,6);
				break;
			case 0:		//TX interrupt disable
				CLR_BIT(UCSRB,6);
				break;
	}
	switch (UDREINT){
		case 1:		//UDRE interrupt enable
			SET_BIT(UCSRB,5);
			break;
		case 0:		//UDRE interrupt disable
			CLR_BIT(UCSRB,5);
			break;
}

	switch (CHARSIZE){
		case 1:		//Character size is 8 bit
			CLR_BIT(UCSRB,2);
			SET_BIT(UCSRC,1);
			SET_BIT(UCSRC,0);
			break;
		case 0:		//Character size is 9 bit
			SET_BIT(UCSRB,2);
			SET_BIT(UCSRC,1);
			SET_BIT(UCSRC,0);
			break;
}

	switch (REGSELECT){
		case 1:		//Read UCSRC
			SET_BIT(UCSRC,7);
			break;
		case 0:		//Read UBRRH
			CLR_BIT(UCSRC,7);
			break;
}

	switch (MODE){
		case 1:		//Synchronous mode
			SET_BIT(UCSRC,6);
			break;
		case 0:		//Asynchronous mode
			CLR_BIT(UCSRC,6);
			break;
}

	switch (PARITY){
		case 0:		//Parity disabled
			CLR_BIT(UCSRC,5);
			CLR_BIT(UCSRC,4);
			break;
		case 1:		//Parity even
			SET_BIT(UCSRC,5);
			CLR_BIT(UCSRC,4);
			break;
		case 2:		//Parity odd
			SET_BIT(UCSRC,5);
			SET_BIT(UCSRC,4);
			break;
}

	switch (STPBIT){
		case 0:		//1 stop bit
			CLR_BIT(UCSRC,3);
			break;
		case 1:		//2 stop bits
			SET_BIT(UCSRC,3);
			break;

}
	Uart_Initial =1;				//init var so uart_init run first

}

void Send_Char(u8 data){


	while(!(UCSRA&(1<<5)));			//Flag Check
	//while((UCSRA&0x20) == 0x00){	  // Wait until transmission Register Empty
		UDR = data;
		  UCSRA&=~(1<<5);		//Clearing Flag

}

u8 Receive_Char(){
	u8 Result;
		while(!(UCSRA&(1<<7)));   //Flag check for receive

		  Result = UDR;
		  return Result;
}

void Send_String(u8 *ptr){

	u8 i=0;
		while(ptr[i]!='\0'){
			Send_Char(ptr[i]);
			i++;
		UDR=ptr[i];

	}}



u8 Receive_String(){


	u8 i=0;
	u8 *ptr;
	ptr[i]=Receive_Char();

		while(ptr[i]!='\0'){
			i++;
			ptr[i]=Receive_Char();
		}
	ptr[i]='\0';
return UDR;
}





#endif /* UART_PROG_C_ */
