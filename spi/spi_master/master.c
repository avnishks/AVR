#include<avr/io.h>
#include"uart.h"

void master_init()
{
	DDRB|=(1<<0)|(1<<1)|(1<<2); //mosi, sck as o/p
	DDRB&=~(1<<3); //miso as i/p
	PORTB|=(1<<3);//pullup
	//SPCR|=(1<<SPE)|(1<<MSTR)|(1<<SPR1)|(1<<SPR0);
	SPCR=0x53;//spi enable, master mode, DORD, prescalar
}

unsigned char master_transmit()
{
	unsigned char data;
	data=uart1_rx_char();
	SPDR=data;
	while(!(SPSR&(1<<SPIF)));
	return SPDR;	
}

int main(void)
{
	unsigned char ch;
	uart1_init();
	master_init();
	PORTB|=(1<<0); //reset slave hardware ckt
	while(1)
	{
		
		ch=master_transmit();
		PORTB&=~(1<<0);//select slave
		uart1_tx_char(ch);
	}

}
