#include "SPI_Private.h"
#include "BITCALC.h"
#define SPI_Interrupt    INTR_ENABLE  /* interrupt is enabled choose INTR_Disable to disable the interrupt*/
#define SPI_CLOCKPOLARITY CPOL_ENABLE /* CLK POLARITY is enabled choose CPOL_Disable to disable CLK POLARITY*/
#define SPI_CLOCKPHASE   CPHA_ENABLE  /* CLK PHASE is enabled choose CPHA_Disable to disable*/
#define SPI_MODE         1            /*Master MODE IS ENABLED CHOOSE 1 TO ENABLE Slave Mode*/
#define SPI_INTRFlag    IntrF_Enable  /* INTERRUPT FLAG IS ENABLED CHOOSE IntrF_Disable to Disable it */
#define SPI_ON_OFF      SPI_ON        /* SPI IS ON CHOOSE SPI_OFF TO DISABLE IT*/
#define SPI_CLKRATE       0           /* choose The suitable SCK*/
