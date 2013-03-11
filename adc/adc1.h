#include<avr/io.h>
void adc_init(void)
{
ADMUX |=((1<<7)|(1<<6)|(1<<5));//choosing internal ref volt. as 2.56V nd selectin channel-0
ADCSRA=0XE7;
 
}

unsigned ldr_result(void)
{
unsigned char result;
while(!(ADCSRA&(1<<ADIF)));
result=ADCH;

return result;
}


