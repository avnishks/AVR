//CTC mode
#include<avr/io.h>
# include"uart.h"
#include<strings.h>
//#include"LCD_meag128.h"
unsigned char count = 100, sec=0, min=0, hr=0, str[10];

int main (void)
{
 uart1_init();
 TCCR0 = 0x07;
 OCR0=156;
 TCNT0=100;
 while(1)
 {
	while(count!=0)
	{
		while(!(TIFR&(1<<OCF0)));//wait for TOV0=1
		count --;
		TIFR |= (1<<OCF0); //clear the flag
		
	}
	count =100;
	sec++;
	uart1_tx_char('A');
	if(sec>59)
	{
		sec=0;
		min++;
	}

	if (min>59)
	{
		min=0;
		hr++;
	}

	if(hr>=24)
	{
		sec=0;
		min=0;
		hr=0;	
	}

	sprintf(str, "%02d; %02d; %02d\n;", hr, min, sec);
	uart1_tx_string(str);
 }
}
