#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
     DDRC = 0xff; // as o/p port
     PORTC =0xff; // leds are off
     while(1)
     { 
        PORTC = 0xaa; //glow leds
        _delay_ms(1000);
        PORTC = 0X55; //LEDS OFF
        _delay_ms(1000);

        }
}


