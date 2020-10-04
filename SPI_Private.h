/*
 * SPI_Private.h
 *
 *  Created on: Oct 5, 2019
 *      Author: lenovo
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#define SPDR *((volatile u8*)0x2F)
#define SPCR *((volatile u8*)0x2D)
#define SPSR *((volatile u8*)0x2E)

#endif /* SPI_PRIVATE_H_ */
