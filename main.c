#include <reg51.h>
sbit rs = P2^0;
sbit en = P2^1;
sfr port_data=0xB0; 
void delay(unsigned int );
void lcd_cmd(unsigned char);
void lcd_init();
void charDisplay(unsigned char);
void strDisplay(unsigned char *);
unsigned int i;
void main() {
	lcd_init();
	strDisplay("Pavan");
	delay(50000);
	lcd_cmd(0x01); // to clear the display
	lcd_cmd(0xc0); // To move to second line
	strDisplay("Mahesh");
	delay(50000);
	lcd_cmd(0x01); //To clear the display
	strDisplay("Hello My Connections");
	delay(50000);
	lcd_cmd(0xc0); 
	strDisplay("Thanks for Watching " );
	delay(50000);
	for(i=0;i<10;i++) {
	lcd_cmd(0x18); //  display shift to left
	delay(10000);
	}
	delay(50000);
	for(i=0;i<10;i++) {
	lcd_cmd(0x1C); //  display shift to right
	delay(10000);
	}
	delay(50000);
	lcd_cmd(0x01);
	strDisplay("     Thanks     ");
	lcd_cmd(0xC0);
	strDisplay("  For Watching  ");
	while(1);
}
void delay(unsigned int i){
	unsigned int x;
	for(x=0;x<i;x++);
}
void lcd_cmd(unsigned char cmd){
	rs = 0; // cmd
	port_data = cmd;
	en = 1;
	delay(1000);
	en=0;
}
void charDisplay(unsigned char lcd_data){
	rs = 1; // data
	port_data = lcd_data;
	en = 1;
	delay(1000);
	en=0;
	delay(1000);
}
void lcd_init(){
	lcd_cmd(0x38); // 8 BIT MODE AND 2 LINE
	lcd_cmd(0x0F); // display on and cursor on and blink on
	lcd_cmd(0x01); //clear dispaly
	lcd_cmd(0x80); //set cursor to first line
}
void strDisplay(unsigned char *str){
	while(*str)
	charDisplay(*str++);
}
