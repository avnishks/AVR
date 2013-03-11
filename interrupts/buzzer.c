#include<avr/io.h>
#include<avr/interrupt.h>

ISR(INT6_vect)
{
	PORTA|= (1<<3);//buzzer is on active high
}

ISR(INT7_vect)
{
	PORTA& =~(1<<3); //buzzer off
}

int main(void)
{
	DDRA|=(1<<3); //configure as o/p
	EICRB |=(1<<7)|(1<<5); 
	EICRB &=~(1<<6)|(1<<4);//interrupt on falling edge
	EIMSK|=(1<<7)|(1<<6); //enable int6 and int7
	sei();
	while(1);
}
