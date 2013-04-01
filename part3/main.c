#include"uart.h"

int main()
{
 unsigned char data;
 unsigned char str[100];
 uart1_init();
  while(1)
  {
    
    uart1_rx_string(str);// recieves string at desired location
    uart1_tx_string(str);// transmits the string thru serial port

 }

}




