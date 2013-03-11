#include<avr/io.h>
#include"uart.h"

unsigned char count=100;
int main()
{ 
 uart1_init();
 TCCR0 = 0x07; //fosc/10124, normal mode
 //TCNT0 = 100; //generate 10 ms delays
 
 while(1)
 {
 	while(count!=0)
 	{
 		while(!(TIFR&(1<<TOV0)));//wait for TOV0=1
 		count --;
 		TIFR |= (1<<TOV0); //clear the flag
 		TCNT0=100;
 	}
 	count=100;
 	uart1_tx_char('A');
 }
 return(0);
}
