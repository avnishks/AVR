# include <avr/io.h>	
	
void uart1_init(void)
{
	UBRR1H =0X00;
	UBRR1L =0X67; //9600 Baud rate
	UCSR1C |=(1<<UCSZ1)|(1<<UCSZ0); //8 bit data mode, 1 stop bit, no parity
	UCSR1B |=(1<<RXEN)|(1<<TXEN);   //enabling transmission and reception
}

void uart1_tx_char(unsigned char data)
{
	while(! (UCSR1A&(1<<UDRE))); // waiting till UDRE=0
	UDR1 = data;
}
void uart1_tx_string(unsigned char *ptr)
{
	while(*ptr!='\0')
	{
		uart1_tx_char(*ptr);
		ptr++;
	}
}
