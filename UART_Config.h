/*
 * UART_Config.h
 *
 *  Created on: Mar 31, 2020
 *      Author: menna
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_
#include "BITCALC.h"
#include "STD_TYPE.h"
#include "UART_PRIV.h"

#define F_CPU 8000000UL 		// Clock speed
#define UART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (UART_BAUDRATE * 16UL)))-1)

#define UARTSPEED 	Normal_speed	//Write Normal_speed or Double_speed
#define  RXINT		RXINT_disable	//Write RXINT_enable or RXINT_disable
#define  TXINT		TXINT_enable	//Write TXINT_enable or TXINT_disable
#define UDREINT		UDREINT_disable	//Write UDREINT_enable or UDREINT_disable
#define CHARSIZE	CHAR_8bit	//Determine the character size CHAR_8bit or CHAR_9bit
#define REGSELECT	READ_UCSRC	//READ_UCSRC or READ_UBRRH
#define MODE		ASYNC	//SYNC or ASYNC
#define PARITY		PARITY_even	//Choose parity mode PARITY_disable or PARITY_even or PARITY_odd
#define STPBIT		STPBIT_1	//Stop bit modes STPBIT_1 or STPBIT_2
#define RXEN		RXEN_enable	//Write RXEN_enable or RXEN_disable
#define TXEN		TXEN_enable	//Write TXEN_enable or TXEN_disable
#define RXC			RXC_enable	//Write RXC_enable to enable flag or RXC_disable to disable flag
#define TXC			TXC_enable	//Write TXC_enable to enable flag or TXC_disable to disable flag







#endif /* UART_CONFIG_H_ */
