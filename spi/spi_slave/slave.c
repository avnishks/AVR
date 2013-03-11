#include<avr/io.h>
#include"uart.h"

void slave_init(void)
{
	DDRB&=~(1<<0)|(1<<1)|(1<<2); //mosi, sck, ss as i/p
	PORTB|=(1<<0)|(1<<1)|(1<<2) ;//pullups enable
	DDRB|=(1<<3); //miso as o/p
	//SPCR|=(1<<SPE)|(1<<SPR1)|(1<<SPR0);
	SPCR=0x43;//prescalar=4, slave mode
	SPDR='B';
}

void slave_receive()
{
	unsigned char data;
	while (!(SPSR&(1<<SPIF))); //polling the flag
	data=SPDR;
	uart1_tx_char(data);

}

int main(void)
{
	uart1_init();
	slave_init();
	while(1)
	{
		slave_receive();		
	}		
}
