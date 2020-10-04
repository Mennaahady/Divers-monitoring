/*
 * nrf.c
 *
 *  Created on: Jun 11, 2020
 *      Author: menna
 */

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "NRF24L01.h"
#include "BITCALC.h"
#include"STD_TYPE.h"
#include "DIO_INTERFACE.h"
#include "DIO_CONFIG.h"
#include "DIO_PRIVATE.h"

void Init_SPI()
{
	DIO_u8SetPinDirection( (u8)6 , 1 ) ;		//chip enable CE , |=set bit
	DIO_u8SetPinDirection( (u8)7 , 1 ) ;		//SS, CSN pin
	DIO_u8SetPinDirection( (u8)12 , 1 ) ;		//MOSI pin
	DIO_u8SetPinDirection( (u8)14 , 1 ) ;		//SCK pin
	DIO_u8SetPinDirection( (u8)13 , 0 ) ;		//MISO pin &=clear bit
	DIO_u8SetPinValue( (u8)7 , 1 ) ;			// SS high to start with
	DIO_u8SetPinValue( (u8)6 , 0 ) ;

	SPCR|=(1<<SPE)|(1<<MSTR)|(1<SPR0);  		//enable spi as master
	SPCR&=~_BV(SPI2X)&~_BV(SPR1); 				//set clock rate but not too important


}

u8 spi_tranceiver (u8 data)
{
	// Load data into the buffer
	SPDR = data;

	//Wait until transmission complete
	while(!(SPSR & (1<<SPIF)));   // Return received data

	return(SPDR);
}

u8 Read_Byte(u8 reg)
{
		_delay_ms(10);

		DIO_u8SetPinValue( (u8)7 , 0 ) ;
		//PORTA&=~_BV(7);
		spi_tranceiver(R_REGISTER+reg);
		_delay_ms(10);
		reg=spi_tranceiver(NOP);
		_delay_ms(10);
		//PORTA|=_BV(7);
		DIO_u8SetPinValue( (u8)7 , 1 ) ;

		return reg;
}

void Write_byte(u8 reg, u8 data)
{
	_delay_ms(10);
	DIO_u8SetPinValue( (u8)7 , 0 ) ;
	//PORTA&=~_BV(7);
	_delay_ms(10);
	spi_tranceiver(W_REGISTER + reg);
	_delay_ms(10);
	spi_tranceiver(data);
	_delay_ms(10);
	DIO_u8SetPinValue( (u8)7 , 1 ) ;
	//PORTA|=_BV(7);
}

void Init_nrf(void)
{
	_delay_ms(100);

	Write_byte(EN_AA,0x01); //Enable auto acknowledgment Transmitter gets automatic response For data pipe 0

	Write_byte(EN_RXADDR,0x01); //enable data pipe 0

    Write_byte(SETUP_AW,0x03);  //address width is 5 byte

	Write_byte(RF_CH, 0x01);  //2.401GHz

	Write_byte(RF_SETUP,0x07);  // 1Mbps 00gain

		_delay_ms(10);
		//PORTA&=~_BV(7);
		DIO_u8SetPinValue( (u8)7 , 0 ) ;
		_delay_ms(10);
		spi_tranceiver(W_REGISTER+RX_ADDR_P0); //setup p0 pipe adress for receiveing
		_delay_ms(10);
		spi_tranceiver(0x01);
		_delay_ms(10);
		spi_tranceiver(0x02);
		_delay_ms(10);
		spi_tranceiver(0x03);
		_delay_ms(10);
		spi_tranceiver(0x04);
		_delay_ms(10);
		spi_tranceiver(0x05);
		_delay_ms(10);
		//PORTA|=_BV(7);
		DIO_u8SetPinValue( (u8)7 , 1 ) ;

			_delay_ms(10);
			//PORTA&=~_BV(7);
			DIO_u8SetPinValue( (u8)7 , 0 ) ;
			_delay_ms(10);
			spi_tranceiver(W_REGISTER+TX_ADDR);  //transmitter address
			_delay_ms(10);
			spi_tranceiver(0x01);
			_delay_ms(10);
			spi_tranceiver(0x02);
			_delay_ms(10);
			spi_tranceiver(0x03);
			_delay_ms(10);
			spi_tranceiver(0x04);
			_delay_ms(10);
			spi_tranceiver(0x05);
			_delay_ms(10);
			//PORTB|=_BV(4);
			DIO_u8SetPinValue( (u8)7 , 1 ) ;

	Write_byte(RX_PW_P0,0x01); //only 1 byte for transceiving

	Write_byte(SETUP_RETR,0x2F); //750us delay with 15 retries

	Write_byte(CONFIG,0x1E); //boot up nrf as transmitter MAX_RETR interrupt disabled

	_delay_ms(100);

}

void Flush_tx(void)
{
		_delay_ms(10);
		//PORTA&=~_BV(7);
		DIO_u8SetPinValue( (u8)7 , 0 ) ;
		_delay_ms(10);
		spi_tranceiver(FLUSH_TX);
		_delay_ms(10);
		//PORTA|=_BV(7);
		DIO_u8SetPinValue( (u8)7 , 1 ) ;
		_delay_ms(10);
}

void Flush_rx(void)
{
			_delay_ms(10);
			//PORTA&=~_BV(7);
			DIO_u8SetPinValue( (u8)7 , 0 ) ;
			_delay_ms(10);
			spi_tranceiver(FLUSH_RX);
			_delay_ms(10);
			//PORTA|=_BV(7);
			DIO_u8SetPinValue( (u8)7 , 1 ) ;
			_delay_ms(10);
}

void transmit_data(u8 tdata)
{
	Flush_tx();
	Write_byte(W_TX_PAYLOAD,tdata);
	_delay_ms(10);
	//PORTA|=_BV(6);
	DIO_u8SetPinValue( (u8)6 , 1 ) ;
	_delay_ms(20);
	//PORTA&=~_BV(6);
	DIO_u8SetPinValue( (u8)6 , 0 ) ;
	_delay_ms(10);
}

void reset(void)
{
	_delay_ms(10);
	//PORTA&=~_BV(7);
	DIO_u8SetPinValue( (u8)7 , 0 ) ;
	_delay_ms(10);
	spi_tranceiver(STATUS);
	_delay_ms(10);
	spi_tranceiver(0x70);   //reset all IRQ after every successful transmit and receive
	_delay_ms(10);
	//PORTA|=_BV(7);
	DIO_u8SetPinValue( (u8)7 , 1 ) ;

}

int main(void)
{
    DDRD=0xff;
	PORTD=0x00;
	Init_SPI();
	Init_nrf();
    unsigned char data=40;

    while (1)
    {
        transmit_data(data);
		_delay_ms(500);
		reset();

    }
}
/*int main(void)
{
    DDRD=0xff;
	PORTD=0x00;
	Init_SPI();
	Init_nrf();
	unsigned char data;

    while (1)
    {
		  receive_payload();
          spi_tranceiver(R_RX_PAYLOAD);
		  _delay_ms(10);
		  data=spi_tranceiver(NOP);
		  if(data==40)
		  {
			  PORTD=PORTD+1;
		  }
		  _delay_ms(10);
		  reset();
    }
}
*/
