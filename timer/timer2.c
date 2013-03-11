#include<avr/io.h>
# include"uart.h"
#include<strings.h>
#include"LCD_mega128.h"

unsigned char count = 100, sec=0, min=0, hr=0, str[10];

int main (void)
{
	lcd_init();
	uart1_init();
	TCCR0 = 0x07;
	while(1)
	{
		while(count!=0)
 		{
 			while(!(TIFR&(1<<TOV0)));//wait for TOV0=1
 			count --;
 			TIFR |= (1<<TOV0); //clear the flag
 			TCNT0=100;
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
		
		
		lcd_gotoxy1(1);
	        lcd_string(str);
	}
}







