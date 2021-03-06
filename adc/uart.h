#include<avr/io.h>



void uart1_init(void)
{
 UBRR1H=0x00;
 UBRR1L=0X67;// 9600 BAUD RATE
 UCSR1C |=(1<<UCSZ1)|(1<<UCSZ0);// 8-bit data is being worked on,1 stop bit,no parity
 UCSR1B |=(1<<RXEN)|(1<<TXEN);// enables reception and transmission
 }

void uart1_tx_char(unsigned char data)
{ 
  while(! (UCSR1A&(1<<UDRE)));// wait till UDRE=0
  UDR1= data;
}

void uart1_tx_string(unsigned char *ptr)
{
  while(*ptr!='\0')
{ 
  uart1_tx_char(*ptr);
  ptr++;
}
}

unsigned char uart1_rx_char(void)
 {
   while( !(UCSR1A & (1<<RXC)));
   return UDR1;
}

unsigned char uart1_rx_string(unsigned char *ptr)
{
  unsigned char i;
  for(i=0;i<100;i++)
 {
   *(ptr+i)=uart1_rx_char();// recieves the whole string at the addr. val ptr to (ptr+string length)
   if (*(ptr+i)=='\r')// checks whedr d string has ended
   {
   *(ptr+i)='\0';
   break;
}
}
}
void uart1_num(unsigned int num)
{
   unsigned char count[5],i;
   for(i=1;i<5;i++)
{
  count[i]=num%10;
  num=num/10;
}
i--;
while(i!=0)
{
  uart1_tx_char(count[i]+48);
  i--;
}

}


