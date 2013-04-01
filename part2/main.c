#include"uart_string.h"
#include"uart.h"	

int main(void)
{

	uart1_init();
	uart1_tx_string("nclnscdlsn	lnslcnslasss\n");
	while(1);
	
}
