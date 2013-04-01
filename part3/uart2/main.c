#include<avr/interrupt.h>
#include<uart.h>
unsigned char data; // global declaration
int main(void)
{   
   uart1_init();
   uart1_tx_string("uart is initialized...\n");
   sei();
   while(1);
}

ISR(USART1_UDRE_vect)
{
  
  data=uart1_rx_char();
  UDR1=data;
}



