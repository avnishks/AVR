

int main()
{
unsigned char data;
while(1)
{
  data=uart1_rx_char();
  uart1_tx_char(data);

}
}
