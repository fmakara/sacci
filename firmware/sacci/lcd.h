#ifndef LCD_H
#define LCD_H

#include <util/delay.h>

//RS PD5
//RW PD6
//E  PD7
//D4 PB0
//D5 PB1
//D6 PB2
//D7 PB3

void lcd_set_data_write(){
	DDRB |= (0x0F);
}
void lcd_set_data_read(){
	DDRB &=~(0x0F);
}
void lcd_read_pin(){
	PORTD |= (1<<6);
}
void lcd_write_pin(){
	PORTD &=~(1<<6);
}
void lcd_data_pin(){
	PORTD |= (1<<5);
}
void lcd_instr_pin(){
	PORTD &=~(1<<5);
}
void lcd_pulse_e(){
	_delay_us(10);
	PORTD |= (1<<7);
	_delay_us(10);
	PORTD &=~(1<<7);
	_delay_us(10);
}
void lcd_write_4bit(char c){
	PORTB = (PORTB&0xF0)|(c&0x0F);
}
char lcd_read_4bit(){
	return (PINB&0xF0)>>4;
}
void lcd_send_8bit(char c){ //Ou adaptar para funcionamento em 8 bits
	lcd_write_4bit(c>>4);
	lcd_pulse_e();
	lcd_write_4bit(c);
	lcd_pulse_e();
}
char lcd_read_8bit(char c){ //Ou adaptar para funcionamento em 8 bits
	char r;
	lcd_pulse_e();
	r = lcd_read_4bit()<<4;
	lcd_pulse_e();
	return r | lcd_read_4bit();	
}
void lcd_inicializar_pinos(){
	lcd_set_data_write();
	DDRD |= 0xE0;
	lcd_write_pin();
	lcd_data_pin();
	PORTD &=~(1<<7);
	PORTB |= 0xF0;
}
// Fim das funções básicas
void lcd_send_data(char d){
	lcd_data_pin();
	lcd_send_8bit(d);
}
void lcd_send_cmd(char c){
	lcd_instr_pin();
	lcd_send_8bit(c);
}
//Fim das funções intermediarias
void lcd_clear_screen(){
	//Escreve 0x20 em DDRA e seta o endereço da DDRAM pra 0x00 (AC)
	lcd_send_cmd(0x01);
	_delay_ms(5);
}
void lcd_return_home(){
	//Seta o endereço da DDRAM pra 0x00 (AC) e retorna o cursor para a posição inicial
	lcd_send_cmd(0x02);
	_delay_ms(5);
}
void lcd_entry_mode_set(char id, char sh){
	//Direção do cursor e pisca display
	char cmd = 0x04;
	if(id)cmd |= 0x02;
	if(sh)cmd |= 0x01;
	lcd_send_cmd(cmd);
	_delay_ms(1);
}
void lcd_display_control(char display, char cursor, char pisca){
	//Auto esplicativo. Display/cursor e pisca do cursor ligado/desligado, 
	char cmd = 0x08;
	if(display)cmd |= 0x04;
	if(cursor)cmd |= 0x02;
	if(pisca)cmd |= 0x01;
	lcd_send_cmd(cmd);
	_delay_ms(1);
}
void lcd_shift_control(char shift_cursor, char r_l){
	//Controla se o display vai shiftar ou se o cursor vai andar. e a direção
	char cmd = 0x10;
	if(shift_cursor)cmd |= 0x08;
	if(r_l)cmd |= 0x04;
	lcd_send_cmd(cmd);
	_delay_ms(1);
}
void lcd_function_set(char data_len, char nr_linhas, char fonte){
	//Data_len define o tamanho do barramento. nr de linhas explicativo (normalmente 1) e fonte escolhe entre 5x11 e 5x8 (normalmente 0)
	char cmd = 0x20;
	if(data_len)cmd |= 0x10;
	if(nr_linhas)cmd |= 0x08;
	if(fonte)cmd |= 0x04;
	lcd_send_cmd(cmd);
	_delay_ms(5);
}
void lcd_set_CGRAM_addr(char addr){
	lcd_send_cmd(0x40|(addr&0x3F));
	_delay_ms(1);
}
void lcd_set_DDRAM_addr(char addr){
	lcd_send_cmd(0x80|(addr&0x7F));
	_delay_ms(1);
}
// Espero que nao precise saber o estado da busy flag :P
void lcd_init(){
	lcd_inicializar_pinos();
	_delay_ms(100);
	lcd_instr_pin();
	lcd_write_4bit(0x03); //equivalente à mandar 0x30, pois estamos com apenas 4 bits
	lcd_pulse_e();
	_delay_ms(10);
	lcd_instr_pin();
	lcd_write_4bit(0x03);
	lcd_pulse_e();
	_delay_ms(1);
	lcd_instr_pin();
	lcd_write_4bit(0x03);
	lcd_pulse_e();
	_delay_ms(1);
	lcd_instr_pin();
	lcd_write_4bit(0x02);//Finalmente selecionando 4 pinos (0x20)
	lcd_pulse_e();
	_delay_ms(1);
	//Fim das funções de inicialização básicas (que nao sao necessarias em caso de 8 bits)
	lcd_function_set(0,1,0); // 4 bit, 2 linhas, 5x8
	lcd_display_control(1,0,0);//display e cursor ligados ligado, sem pisca
	lcd_entry_mode_set(1,0);
	lcd_clear_screen();
	lcd_return_home();
}
void lcd_goto(char linha, char coluna){
	linha &= 0x01;
	coluna &= 0x0F;
	lcd_set_DDRAM_addr((linha<<6)|coluna);
}
void lcd_print_str(char *str){
	while(*str!=0){
		lcd_send_data(*str);
		str++;
	}
}
void lcd_print_int(int x){
	int div;
	if(x<0){
		lcd_send_data('-');
		x = -x;
	}
	if(x==0){
		lcd_send_data('0');
		return;
	}		
	for(div=10000;div>x;div/=10);
	while(div>0){
		char res = x / div;
		x = x % div;
		div /= 10;
		lcd_send_data('0'+res);
	}
}
void lcd_print_float_31(float x){
	char buff[6] = "  0.0";
	int div, inteiro = (int)(x*10);
	if(x>=1000 || x<=-100){
		buff[0] = 'E';
		buff[1] = 'R';
		buff[2] = 'R';
	}else{
		if(x<0){//Como só tem 4 digitos, nao vou fazer lasso
			buff[0] = '-';
			inteiro = -inteiro;
		}else{
			div = inteiro/1000;
			inteiro = inteiro%1000;
			if(div>0)buff[0] = '0'+div;
		}
		div = inteiro/100;
		inteiro = inteiro%100;
		if(div>0 || buff[0]>='0')buff[1] = '0'+div;
		div = inteiro/10;
		inteiro = inteiro%10;
		buff[2] = '0'+div;
		buff[4] = '0'+inteiro;
	}
	for(div=0;div<5;div++)lcd_send_data(buff[div]);
}





#endif