#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
     DDRD&= ~((1<<6)|(1<<7) ) ; // s/w as input
     PORTD|= ((1<<7)|(1<<6));// enable pull ups
     DDRC= 0XFF;// o/p port for leds
     PORTC= 0XFF;// leds off
     while(1)
    { 
      if((PIND&(1<<7))==0)
      {
        PORTC = 0X55;
        _delay_ms(1000);
        
      }
      if((PIND&(1<<6))==0)
       {
         PORTC = 0XAA;
         _delay_ms(1000);

       }
    }
}
