/*
 * EXTIprog.c
 *
 *  Created on: Jun 13, 2020
 *      Author: menna
 */



#include "avr/io.h"
#include <avr/interrupt.h>
#include "BITCALC.h"
#include "STD_TYPE.h"
#include "DIO_INTERFACE.h"
#include "EXTIheader.h"
#include "EXTIpriv.h"
#include "EXTIconfig.h"


/****************************************************************************/

/* EXT-INTR SETTING THE MODES EXT-INIT */
/****************************************************************************/

void EXT_INIT (void){

	switch (INT2_CONTROL){
		case 1:	//RISING EGDE
			SET_BIT(LOCAL_GICR,5);
			SET_BIT(LOCAL_MCUCSR,6);
			break;
		case 0:	//FALLING EDGE
			SET_BIT(LOCAL_GICR,5);
			CLR_BIT(LOCAL_MCUCSR,6);
			break;

	}
	switch (INT1_CONTROL){
			case 0:	//INT1_LOWLEVEL
				SET_BIT(LOCAL_GICR,7);
				CLR_BIT(LOCAL_MCUCR,3);
				CLR_BIT(LOCAL_MCUCR,2);
				break;
			case 1:	//INT1_LOGICALCHAMGE
				SET_BIT(LOCAL_GICR,7);
				SET_BIT(LOCAL_MCUCR,2);
				CLR_BIT(LOCAL_MCUCR,3);
				break;
			case 2:	//INT1_FALLINGEDGE
				SET_BIT(LOCAL_GICR,7);
				SET_BIT(LOCAL_MCUCR,3);
				CLR_BIT(LOCAL_MCUCR,2);
				break;
			case 3:	//INT1_RISINGEDGE
				SET_BIT(LOCAL_GICR,7);
				SET_BIT(LOCAL_MCUCR,3);
				SET_BIT(LOCAL_MCUCR,2);
				break;
}
	switch (INT0_CONTROL){
				case 0:	//INT0_LOWLEVEL
					SET_BIT(LOCAL_GICR,6);
					CLR_BIT(LOCAL_MCUCR,1);
					CLR_BIT(LOCAL_MCUCR,0);
					break;
				case 1:	//INT0_LOGICALCHAMGE
					SET_BIT(LOCAL_GICR,6);
					SET_BIT(LOCAL_MCUCR,0);
					CLR_BIT(LOCAL_MCUCR,1);
					break;
				case 2:	//INT0_FALLINGEDGE
					SET_BIT(LOCAL_GICR,6);
					SET_BIT(LOCAL_MCUCR,1);
					CLR_BIT(LOCAL_MCUCR,0);
					break;
				case 3:	//INT0_RISINGEDGE
					SET_BIT(LOCAL_GICR,6);
					SET_BIT(LOCAL_MCUCR,1);
					SET_BIT(LOCAL_MCUCR,0);
					break;
}
	switch (INT0_MODE){
		case 0:	//INT0_OFF
			CLR_BIT(LOCAL_GICR,6);
			break;
		case 1:	//INT0_ON
			SET_BIT(LOCAL_GICR,6);
}
	switch (INT1_MODE){
			case 0:	//INT1_OFF
				CLR_BIT(LOCAL_GICR,7);
				break;
			case 1:	//INT1_ON
				SET_BIT(LOCAL_GICR,7);
}
	switch (INT2_MODE){
			case 0:	//INT2_OFF
				CLR_BIT(LOCAL_GICR,5);
				break;
			case 1:	//INT2_ON
				SET_BIT(LOCAL_GICR,5);
}
	switch (INT0_FLAG){
			case 0:	//FLAG0_OFF
				CLR_BIT(LOCAL_GIFR,6);
				break;
			case 1:	//FLAG0_ON
				SET_BIT(LOCAL_GICR,6);
				SET_BIT(LOCAL_GIFR,6);
}
	switch (INT1_FLAG){
				case 0:	//FLAG1_OFF
					CLR_BIT(LOCAL_GIFR,7);
					break;
				case 1:	//FLAG1_ON
					SET_BIT(LOCAL_GICR,7);
					SET_BIT(LOCAL_GIFR,7);
}
	switch (INT2_FLAG){
				case 0:	//FLAG2_OFF
					CLR_BIT(LOCAL_GIFR,5);
					break;
				case 1:	//FLAG2_ON
					SET_BIT(LOCAL_GICR,5);
					SET_BIT(LOCAL_GIFR,5);
		}}

/****************************************************************************/
