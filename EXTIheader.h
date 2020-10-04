/*
 * EXTIheader.h
 *
 *  Created on: Jun 13, 2020
 *      Author: menna
 */

#ifndef EXTIHEADER_H_
#define EXTIHEADER_H_



#include "avr/io.h"
#include <avr/interrupt.h>
#include "BITCALC.h"
#include "STD_TYPE.h"
#include "DIO_INTERFACE.h"
#include "EXTIpriv.h"
#include "EXTIconfig.h"


/****************************************************************************/

/* EXT-INTR MODES */
#define INT2_FALLINGEDGE		0
#define INT2_RISINGEDGE			1

#define INT1_LOWLEVEL			0
#define INT1_LOGICALCHAMGE		1
#define INT1_FALLINGEDGE		2
#define INT1_RISINGEDGE			3

#define INT0_LOWLEVEL			0
#define INT0_LOGICALCHAMGE		1
#define INT0_FALLINGEDGE		2
#define INT0_RISINGEDGE			3

#define INT0_ON					1
#define INT0_OFF				0

#define INT1_ON					1
#define INT1_OFF				0

#define INT2_ON					1
#define INT2_OFF				0

#define FLAG0_ON				1
#define FLAG0_OFF				0

#define FLAG1_ON				1
#define FLAG1_OFF				0

#define FLAG2_ON				1
#define FLAG2_OFF				0

/****************************************************************************/


#endif /* EXTIHEADER_H_ */
