void uart1_tx_string(unsigned char *ptr)
{
	while(*ptr!='\0')
	{
		uart1_tx_char(*ptr);
		ptr++;
	}
}
