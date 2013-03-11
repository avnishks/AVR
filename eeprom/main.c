#include"uart.h"
#include"eeprom.h"

int main()
{
	unsigned char data;
	uart1_init();
	//eeprom_write(0x100, 'A');
	data=eeprom_read(0x100);
	uart1_tx_char(data);
	while(1);
	
}
