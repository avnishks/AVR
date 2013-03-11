#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
     DDRC = 0xff; // as o/p port
     PORTC =0xff; // leds are off
     while(1)
     { 
        PORTC = 0x7f; //glow leds
        _delay_ms(1600);
PORTC = 0x3f; //glow leds
        _delay_ms(1400);
PORTC = 0x1f; //glow leds
        _delay_ms(1200);
PORTC = 0x0f; //glow leds
        _delay_ms(1000);
PORTC = 0x07; //glow leds
        _delay_ms(800);
PORTC = 0x03; //glow leds
        _delay_ms(600);
PORTC = 0x01; //glow leds
        _delay_ms(400);
        PORTC = 0X00; //LEDS OFF
        _delay_ms(200);

        }
}


