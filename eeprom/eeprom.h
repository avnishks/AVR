#include<avr/io.h>

void eeprom_write(unsigned int address, unsigned char data)
{
	while (EECR&(1<<EEWE));//wait till EEWE becomes 0
	EEAR = address;
	EEDR = data;
	EECR|=(1<<EEMWE);
	EECR|=(1<<EEWE);
}

unsigned int eeprom_read(unsigned int address)
{
	while(EECR&(1<<EEWE));
	EEAR=address;
	EECR|=(1<<EERE); //read operations
	return EEDR;
}
