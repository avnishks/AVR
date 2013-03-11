#include"uart.h"
#include<avr/io.h>
#include"adc1.h"
#include<util/delay.h>

int main(void)
{
unsigned char data;
uart1_init();// initialize adc n uart
adc_init();
while(1)
{
data= ldr_result();// read the result
uart1_num(data);
uart1_tx_char('\n');//display on uart
_delay_ms(1000);

}

}


