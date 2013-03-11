#include<avr/io.h>
#include<avr/interrupt.h>

void uart0_init(void)
{
 UBRR0H=0x00;
 UBRR0L=0X67;// 9600 BAUD RATE
 UCSR0C |=(1<<UCSZ1)|(1<<UCSZ0);// 8-bit data is being worked on,1 stop bit,no parity
 UCSR0B |=(1<<RXEN)|(1<<TXEN)|(1<<RXCIE);// enables reception and transmission
 }
 
 void uart1_init(void)
{
 UBRR1H=0x00;
 UBRR1L=0X67;// 9600 BAUD RATE
 UCSR1C |=(1<<UCSZ1)|(1<<UCSZ0);// 8-bit data is being worked on,1 stop bit,no parity
 UCSR1B |=(1<<RXEN)|(1<<TXEN)|(1<<RXCIE);// enables reception and transmission
 }
 
 ISR(USART1_RX_vect)
 {
 	unsigned char data;
 	data=UDR1;
 	UDR0=data;
 }
 
 ISR(USART0_RX_vect)
 {
 	unsigned char ch;
 	ch=UDR0;
 	UDR1=ch;
 }
 
 int main()
 {
 	uart1_init();
 	uart0_init();
 	sei();
 	while(1);
 }
 
