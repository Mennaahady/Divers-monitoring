/*
 * EXTIconfig.h
 *
 *  Created on: Jun 13, 2020
 *      Author: menna
 */

#ifndef EXTICONFIG_H_
#define EXTICONFIG_H_

#include "avr/io.h"
#include <avr/interrupt.h>
#include "BITCALC.h"
#include "STD_TYPE.h"
#include "DIO_INTERFACE.h"
#include "EXTIheader.h"
#include "EXTIpriv.h"

/********************************************/

/* EXT-INTR CONFIGURATION */
#define INT2_CONTROL		INT2_FALLINGEDGE		//INT2_FALLINGEDGE, INT2_RISINGEDGE
#define INT1_CONTROL		INT1_FALLINGEDGE		//INT1_LOWLEVEL, INT1_LOGICALCHAMGE, INT1_FALLINGEDGE, INT1_RISINGEDGE
#define INT0_CONTROL		INT0_FALLINGEDGE		//INT0_LOWLEVEL, INT0_LOGICALCHAMGE, INT0_FALLINGEDGE, INT0_RISINGEDGE
#define INT0_MODE			INT0_ON					//INT0_ON, INT0_OFF
#define INT1_MODE			INT1_ON					//INT1_ON, INT1_OFF
#define INT2_MODE			INT2_ON					//INT2_ON, INT2_OFF
#define INT0_FLAG			FLAG0_ON				//FLAG0_ON, FLAG0_OFF
#define INT1_FLAG			FLAG1_ON				//FLAG1_ON, FLAG1_OFF
#define INT2_FLAG			FLAG2_ON				//FLAG2_ON, FLAG2_OFF

/****************************************************************************/


#endif /* EXTICONFIG_H_ */
