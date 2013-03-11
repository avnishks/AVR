#include<avr/io.h>
#include<avr/interrupt.h>

ISR(INT6_vect)
{
	PORTC= 0x00;
}

ISR(INT7_vect)
{
	PORTC =0xff; //buzzer off
}

int main(void)
{
	DDRC=0xff; //leds as o/p
	DDRE&=~(1<<7)|(1<<6);//switch as i/p
	/PORTE |=(1<<7)|(1<<6);//enable pull ups
	
	EICRB |=(1<<7)|(1<<5); 
	EICRB &=~(1<<6)|(1<<4);//interrupt on falling edge
	EIMSK|=(1<<7)|(1<<6); //enable int6 and int7
	sei();
	while(1);
}
