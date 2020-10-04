
#include<avr/io.h>
#include<util/delay.h>
#include"LCDpriv.h"
#include"LCDheader.h"
#include"STD_TYPE.h"
#include "DIO_INTERFACE.h"
#include "DIO_CONFIG.h"
#include "DIO_PRIVATE.h"

u32 press;

void init_LCD(void)
{
LCD_cmd(0x38); //initialize lcd command
_delay_ms(1);
LCD_cmd(0x38);
_delay_ms(1);
LCD_cmd(0x38);
_delay_ms(1);
LCD_cmd(0x38);
_delay_ms(1);
LCD_cmd(0x38);
_delay_ms(1);
LCD_cmd(0x06); //auto increment cursor
_delay_ms(1);
LCD_cmd(0x0c); //display on cursor off
_delay_ms(1);
LCD_cmd(0x01); //display clear
_delay_ms(1);
LCD_cmd(0x02);
_delay_ms(1);
LCD_cmd(0x80); //first line first position
_delay_ms(1);
return ;
}
void LCD_cmd(u8 cmd)
{
PORTA=cmd;
//DIO_SetPortValue(0,cmd);
ctrl=(0<<rs)|(0<<rw)|(1<<en);
_delay_ms(1);
ctrl=(0<<rs)|(0<<rw)|(0<<en);
_delay_ms(50);
return;
}
void LCD_write(u8 data)
{
PORTA=data;
//DIO_SetPortValue(0,data);
ctrl=(1<<rs)|(0<<rw)|(1<<en);
_delay_ms(1);
ctrl=(1<<rs)|(0<<rw)|(0<<en);
_delay_ms(50);
return;
}
void LCD_write_string(u8 *str)
{
int i=0;
while(str[i]!='\0')
{
LCD_write(str[i]);
i++;
}
return;
}
