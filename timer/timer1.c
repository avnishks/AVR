#include<avr/io.h>
# include"uart.h"
unsigned char count = 100;

void delay_sec()
	{
		if (count!=0)
		{
			while(!(TIFR & (1<<TOV0))); //wait for TOV0=1
			count --;
			TIFR |=(1<<TOV0); //clear the flag
			TCNT0=100;
		}
	}
int main()
{
uart1_init();
	TCCR0 = 0x07;
	
	while(1)
	{
		delay_sec(1);
		uart1_tx_char('A');
	}
	
}
