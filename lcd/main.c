#include<avr/io.h>
#include"LCD_mega128.h"

int main(void)
{
	lcd_init();//initialize
	//void lcd_cmd(0x01);//clear display
	//void lcd_cmd(0x0f);//display on, cursor blinking
	
	
	while(1)
	{
		lcd_gotoxy1(0);
		   lcd_putchar('A');
		lcd_gotoxy1(1);
		   lcd_putchar('v');
		lcd_gotoxy1(2);
		   lcd_putchar('n');
		lcd_gotoxy1(3);
		   lcd_putchar('i');
		lcd_gotoxy1(4);
		   lcd_putchar('s');
		lcd_gotoxy1(5);
		   lcd_putchar('h');
		
		lcd_gotoxy2(3);
		   lcd_putchar('K');
		lcd_gotoxy2(4);
		   lcd_putchar('u');
		lcd_gotoxy2(5);
		   lcd_putchar('m');
		lcd_gotoxy2(6);
		   lcd_putchar('a');
		lcd_gotoxy2(7);
		   lcd_putchar('r');
		   
		   //lcd_showvalue('avnish kumar singh');
		
	}
}
