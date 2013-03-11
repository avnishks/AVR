#include"uart.h"
#include<util/delay.h>

unsigned int a,b;
int main(void)
{
uart1_init();
while(1)
{
x_channel();
y_channel();
}

}

void x_channel(void)
{
   ADMUX= 0XC1; // CHANNEL 1
   ADCSRA= 0XE3; //Fosc/16,free running mode
   while(!(ADCSRA&(1<<ADIF)));
   b= ADCL;
   a= ADCH;
   a=((a<<8)|b);
   uart1_tx_string("Y-Axis \t X-Axis\n");
   uart1_num(a);
   uart1_tx_char('\t');
   _delay_ms(1000);

}

void y_channel(void)
{
   ADMUX= 0XC2; // CHANNEL 1
   ADCSRA= 0XE4; //Fosc/16,free running mode
   while(!(ADCSRA&(1<<ADIF)));
   b= ADCL;
   a= ADCH;
   a=((a<<8)|b);
   uart1_num(a);
   uart1_tx_char('\n');
   _delay_ms(1000);

}
