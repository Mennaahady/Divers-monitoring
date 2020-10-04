/*
 * MS5540c.c

 *
 *  Created on: Aug 1, 2020
 *      Author: menna
 */


#include "BITCALC.h"
#include"DIO_INTERFACE.h"
#include"STD_TYPE.h"
#include "DIO_CONFIG.h"
#include"SPI_Interface.h"
#include"SPI_Private.h"
#include "SPI_config.h"
#include "DIO_PRIVATE.h"
#include <util/delay.h>
#include"LCDheader.h"
#include"LCDpriv.h"
#include "Timers_Int.h"
#include "Timers_Config.h"
#include "Timers_priv.h"
#include "avr/interrupt.h"


char SPI_Transmit(char cData){

   SPDR = cData;
   while(!(SPSR & (1<<7)))
      ;
   return SPDR;
}

void SPISlave(){
(CLR_BIT(SPCR,4));

			DIO_SetPinDirection((u8)12,0); //SS
	 	 	DIO_SetPinValue((u8)12,1);
	 	    DIO_SetPinDirection((u8)13,0); //MOSI
	 	    DIO_SetPinDirection((u8)14,1); //MISO
	 	    DIO_SetPinDirection((u8)15,0); //ck
}

void SPIMaster(){
(SET_BIT(SPCR,4));
			DIO_SetPinDirection((u8)12 ,1); //SS
	 	 	DIO_SetPinValue((u8)12 ,1);
	 	 	DIO_SetPinDirection((u8)13,1); //MOSI
	 	 	DIO_SetPinDirection((u8)14,0); //MISO
	 	 	DIO_SetPinDirection((u8)15,1); //ck
}

u8 clock = 9;
void resetsensor() //this function keeps the sketch a little shorter
{
//set master mode
SPIMaster();

SPI_Transmit(0x15);
SPI_Transmit(0x55);
SPI_Transmit(0x40);
}
void setup()
{

//setting ss, ck, mosi outputs, ck, mosi low, ss high
			DIO_SetPinDirection((u8)12 ,1); //SS
	 	 	DIO_SetPinValue((u8)12 ,1); //ss high

	 	 	DIO_SetPinDirection((u8)13,1); //MOSI
	 	 	DIO_SetPinDirection((u8)15,1); //ck
	 	 	DIO_SetPinValue((u8)13 ,1); //MOSI low
	 	 	DIO_SetPinValue((u8)15 ,1); //ck low

 	 			CLR_BIT(SPCR,5); //DORD 0 so MSB of the data word is transmitted
//divide 16 MHz to communicate on 500 kHz
	SET_BIT(SPCR,0);
	CLR_BIT(SPCR,1);
	CLR_BIT(SPSR,0);

	 	 	DIO_SetPinDirection(clock,1); //pinMode(clock, OUTPUT)
			_delay_ms(100);
			}
void loop()
{

	//setting pin directions

	 DIO_SetPinDirection((u8)27  , 1 ) ;
	 DIO_SetPinDirection((u8)28  , 1 ) ;

	//Fast PW mode for 16-bit timer (Timer1)

	//waveform generation mode

	CLR_BIT(TCCR1B,4); //WGM13
	SET_BIT(TCCR1B,3); //WGM12
	CLR_BIT(TCCR1A,1); //WGM11
	SET_BIT(TCCR1A,0); //WGM10

	//compare output mode

	CLR_BIT(TCCR1A,7); //COM1A1
	CLR_BIT(TCCR1A,5); //COM1B1
	SET_BIT(TCCR1A,6); //COM1A0
	SET_BIT(TCCR1A,4); //COM1B0

	//clock select

	CLR_BIT(TCCR1B,2); //CS12
	CLR_BIT(TCCR1B,1); //CS11
	SET_BIT(TCCR1B,0); //CS10

	//Overflow Interrupt Enable

	SET_BIT(TIMSK,2); //TOIE1


	while(1){

//TCCR1B = (TCCR1B & 0xF8) | 1 ; //generates the MCKL signal
  //analogWrite (clock, 128) ;


		//duty cycle setting


		OCR1B= (clock/100)*255;
		sei();

		_delay_ms(1000);
		clock+=10;
		if(clock>=100){
		clock=0;
		}
  resetsensor();//resets the sensor - caution: afterwards

  u8 word1 = 0;
  u8 word11 = 0;

  SPI_Transmit(0x1D); //send first byte of command to get calibration word 1
  SPI_Transmit(0x50); //send second byte of command to get calibration word 1

	//change mode in order to listen - slave mode
			SPISlave();

word1 = SPI_Transmit(0x00); //send dummy byte to read first byte of word
word1 = word1 << 8; //shift returned byte
word11 = SPI_Transmit(0x00); //send dummy byte to read second byte of word
word1 = word1 | word11; //combine first and second byte of word
resetsensor();//resets the sensor
//Calibration word 2; see comments on calibration word 1
u8 word2 = 0;
u8 word22 = 0;
SPI_Transmit(0x1D);
SPI_Transmit(0x60);
//change mode in order to listen - slave mode
SPISlave();

word2 = SPI_Transmit(0x00);
word2 = word2 <<8;
word22 = SPI_Transmit(0x00);
word2 = word2 | word22;

resetsensor();//resets the sensor

//Calibration word 3; see comments on calibration word 1

u8 word3 = 0;
u8 word33 = 0;
SPI_Transmit(0x1D);
SPI_Transmit(0x90);

//change mode in order to listen - slave mode
SPISlave();

word3 = SPI_Transmit(0x00);
	word3 = word3 <<8;
	word33 = SPI_Transmit(0x00);
	word3 = word3 | word33;
	resetsensor(); //resets the sensor

	//Calibration word 4; see comments on calibration word 1

	u8 word4 = 0;
	u8 word44 = 0;
	SPI_Transmit(0x1D);
	SPI_Transmit(0xA0);

	//change mode in order to listen - slave mode
	SPISlave();

	word4 = SPI_Transmit(0x00);
	word4 = word4 <<8;
	word44 = SPI_Transmit(0x00);
	word4 = word4 | word44;
	u32 c1 = word1 << 1;
	u32 c2 = ((word3 & 0x3F) >> 6) | ((word4 & 0x3F));
	u32 c3 = (word4 << 6) ;
	u32 c4 = (word3 << 6);
	u32 c5 = (word2 << 6) | ((word1 & 0x1) >> 10);
	u32 c6 = word2 & 0x3F;

	resetsensor();//resets the sensor

//Temperature:
	u8 tempMSB = 0; //first byte of value
	u8 tempLSB = 0; //last byte of value
	u8 D2 = 0;
	SPI_Transmit(0x0F); //send first byte of command to get temperature value
	SPI_Transmit(0x20); //send second byte of command to get temperature value
	_delay_ms(35); //wait for conversion end

	//change mode in order to listen - slave mode
	SPISlave();
	tempMSB = SPI_Transmit(0x00); //send dummy byte to read first byte of value
	tempMSB = tempMSB << 8; //shift first byte
	tempLSB = SPI_Transmit(0x00); //send dummy byte to read second byte of value
	D2 = tempMSB | tempLSB; //combine first and second byte of value

	resetsensor();//resets the sensor

	//Pressure:
	u8 presMSB = 0; //first byte of value
	u8 presLSB =0; //last byte of value  unsigned
	int D1 = 0;
	SPI_Transmit(0x0F); //send first byte of command to get pressure value
	SPI_Transmit(0x40); //send second byte of command to get pressure value
	_delay_ms(35); //wait for conversion end

	//change mode in order to listen - slave mode
	SPISlave();

	presMSB = SPI_Transmit(0x00); //send dummy byte to read first byte of value
	presMSB = presMSB << 8; //shift first byte
	presLSB = SPI_Transmit(0x00); //send dummy byte to read second byte of value
	D1 = presMSB | presLSB;
	const u32 UT1 = (c5 * 8) + 20224;
	const u32 dT =(D2 - UT1);
	const u32 TEMP = 200 + ((dT * (c6 + 50))/1024);
	const u32 OFF  = (c2*4) + (((c4 - 512) * dT)/4096);
	const u32 SENS = c1 + ((c3 * dT)/1024) + 24576;
	u32 PCOMP = ((((SENS * (D1 - 7168))/16384)- OFF)/32)+250;
	float TEMPREAL = TEMP/10;

	int main(){


	LCD_write_string("pressure =    ");
	LCD_write_string(PCOMP);
	LCD_write_string(" mbar");


	const u32 dT2 = dT - ((dT >> 7 * dT >> 7) >> 3);
	const float TEMPCOMP = (200 + (dT2*(c6+100) >>11))/10;

	LCD_write_string("temperature =    ");
	LCD_write_string(TEMPCOMP);
	LCD_write_string(" °C");

	LCD_write_string("************************************");


	_delay_ms(1000);
	}
}
}
