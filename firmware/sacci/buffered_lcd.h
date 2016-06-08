#ifndef BUFFERED_LCD_H
#define BUFFERED_LCD_H

#include <util/delay.h>
#include <avr/interrupt.h>
#include "interfaces.h"

//RS PD5
//RW PD6
//E  PD7
//D4 PB0
//D5 PB1
//D6 PB2
//D7 PB3

//Buffered LCD: Usando um display LCD convencional (2x16, 5x8)
//A inicialização é feita normalmente (temporização usando delay.h)
//A partir dai, a cada 200ms o display é atualizado com o backbuffer

const char LCD_ESPECIAIS[64] = {
	0b00000000,
	0b00010001,
	0b00001010,
	0b00000100,
	0b00001010,
	0b00010001,
	0b00000000,
	0b00000000,//0-8 Xis
	0b00000000,
	0b00000001,
	0b00000010,
	0b00010100,
	0b00001000,
	0b00000000,
	0b00000000,
	0b00000000,//1-9 ok
	0b00000000,
	0b00000100,
	0b00000100,
	0b00000100,
	0b00010101,
	0b00001110,
	0b00000100,
	0b00000000,//2-A baixo
	0b00000000,
	0b00000100,
	0b00001110,
	0b00010101,
	0b00000100,
	0b00000100,
	0b00000100,
	0b00000000,//3-B Alto
	0b00001010,
	0b00000000,
	0b00010101,
	0b00001110,
	0b00001110,
	0b00010101,
	0b00000000,
	0b00001010,//4-C Aquecedor
	0b00000100,
	0b00001010,
	0b00010001,
	0b00000000,
	0b00001110,
	0b00001010,
	0b00001010,
	0b00001110,//5-D Subindo
	0b00010001,
	0b00001010,
	0b00000100,
	0b00000000,
	0b00001110,
	0b00001010,
	0b00001010,
	0b00001110,//6-E Descendo
	0b00011111,
	0b00010001,
	0b00010001,
	0b00010001,
	0b00010001,
	0b00010001,
	0b00011111,
	0b00000000//7-F
};
int  LCD_OPERACAO, LCD_ESTAGIO;
char LCD_BACKBUFFER[2][16];
char LCD_CURSOR[2];

#define LCD_MSG_DIV 3
char LCD_MSG_POS[3], LCD_MENSAGEM[128], LCD_TAM_MENSAGEM, LCD_MSG_ATUAL, LCD_MSG_COUNTER;

void lcd_set_data_write(){
	DDRB |= (0x0F);
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
inline void lcd_high_e(){
	PORTD |= (1<<7);
}
inline void lcd_low_e(){
	PORTD &=~(1<<7);
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
void lcd_send_8bit(char c){ //Ou adaptar para funcionamento em 8 bits
	lcd_write_4bit(c>>4);
	lcd_pulse_e();
	lcd_write_4bit(c);
	lcd_pulse_e();
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
	_delay_ms(2);
}
void lcd_display_control(char display, char cursor, char pisca){
	//Auto esplicativo. Display/cursor e pisca do cursor ligado/desligado,
	char cmd = 0x08;
	if(display)cmd |= 0x04;
	if(cursor)cmd |= 0x02;
	if(pisca)cmd |= 0x01;
	lcd_send_cmd(cmd);
	_delay_ms(2);
}
void lcd_shift_control(char shift_cursor, char r_l){
	//Controla se o display vai shiftar ou se o cursor vai andar. e a direção
	char cmd = 0x10;
	if(shift_cursor)cmd |= 0x08;
	if(r_l)cmd |= 0x04;
	lcd_send_cmd(cmd);
	_delay_us(50);
}
void lcd_function_set(char data_len, char nr_linhas, char fonte){
	//Data_len define o tamanho do barramento. nr de linhas explicativo (normalmente 1) e fonte escolhe entre 5x11 e 5x8 (normalmente 0)
	char cmd = 0x20;
	if(data_len)cmd |= 0x10;
	if(nr_linhas)cmd |= 0x08;
	if(fonte)cmd |= 0x04;
	lcd_send_cmd(cmd);
	_delay_us(50);
}
void lcd_set_CGRAM_addr(char addr){
	lcd_send_cmd(0x40|(addr&0x3F));
	_delay_us(50);
}
void lcd_set_DDRAM_addr(char addr){
	lcd_send_cmd(0x80|(addr&0x7F));
	_delay_us(50);
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
	lcd_display_control(1,1,1);//display e cursor ligados ligado, sem pisca
	lcd_entry_mode_set(1,0);
	lcd_clear_screen();
	lcd_return_home();
	lcd_set_CGRAM_addr(0);
	for(int i=0;i<64;i++){
		lcd_send_data(LCD_ESPECIAIS[i]);
		_delay_ms(1);
	}	
	lcd_set_DDRAM_addr(0);
	LCD_OPERACAO = 0;
	LCD_ESTAGIO = 0;
	for(int i=0;i<16;i++){
		LCD_BACKBUFFER[0][i] = ' ';
		LCD_BACKBUFFER[1][i] = ' ';
	}
	LCD_CURSOR[0] = 0;
	LCD_CURSOR[1] = 0;
	//Agora configuramos o relogio e as interrupcoes.
	//Como o tempo de operação minimo é 50us, o clock pode ter as suas bordas com esta duração
	//Portanto, TIMER0 vai ser interrompido a cada 50us e vai executar alguma coisa
	TCCR0A = (1<<WGM01)|(1<<WGM00);//Modo Fast PWM, interrompendo com OCRA
	TCCR0B = (1<<WGM02)|(1<<CS01);// CLK = 16MHz/8 = 2MHz (0.5us)
	OCR0A = 100;// periodo=0.5us*100 = 50us
	TIMSK0 = (1<<TOIE0);//Interrupcoes de overflow abilitadas
	sei();//Interrupcoes globais habilitadas
}
ISR(TIMER0_OVF_vect){
	if(LCD_OPERACAO==0){// goto 0,0 -> instr 0x80
		switch(LCD_ESTAGIO){
			case 0: lcd_instr_pin();lcd_write_4bit(0x08);LCD_ESTAGIO++;break;
			case 1: lcd_high_e();LCD_ESTAGIO++;break;
			case 2: lcd_low_e();LCD_ESTAGIO++;break;
			case 3: lcd_write_4bit(0x00);LCD_ESTAGIO++;break;
			case 4: lcd_high_e();LCD_ESTAGIO++;break;
			case 5: lcd_low_e();LCD_ESTAGIO++;break;
			case 6: LCD_OPERACAO++; LCD_ESTAGIO=0;break;
		}
	}else if(LCD_OPERACAO<17){// Mandar dados da primeira linha
		switch(LCD_ESTAGIO){
			case 0: lcd_data_pin();lcd_write_4bit(LCD_BACKBUFFER[0][LCD_OPERACAO-1]>>4);LCD_ESTAGIO++;break;
			case 1: lcd_high_e();LCD_ESTAGIO++;break;
			case 2: lcd_low_e();LCD_ESTAGIO++;break;
			case 3: lcd_write_4bit(LCD_BACKBUFFER[0][LCD_OPERACAO-1]);LCD_ESTAGIO++;break;
			case 4: lcd_high_e();LCD_ESTAGIO++;break;
			case 5: lcd_low_e();LCD_ESTAGIO++;break;
			case 6: LCD_OPERACAO++; LCD_ESTAGIO=0;break;
		}
	}else if(LCD_OPERACAO==17){// goto 1,0 -> instr 0xC0
		switch(LCD_ESTAGIO){
			case 0: lcd_instr_pin();lcd_write_4bit(0x0C);LCD_ESTAGIO++;break;
			case 1: lcd_high_e();LCD_ESTAGIO++;break;
			case 2: lcd_low_e();LCD_ESTAGIO++;break;
			case 3: lcd_write_4bit(0x00);LCD_ESTAGIO++;break;
			case 4: lcd_high_e();LCD_ESTAGIO++;break;
			case 5: lcd_low_e();LCD_ESTAGIO++;break;
			case 6: LCD_OPERACAO++; LCD_ESTAGIO=0;break;
		}
	}else if(LCD_OPERACAO<34){// Mandar dados da segunda linha
		switch(LCD_ESTAGIO){
			case 0: lcd_data_pin();lcd_write_4bit(LCD_BACKBUFFER[1][LCD_OPERACAO-18]>>4);LCD_ESTAGIO++;break;
			case 1: lcd_high_e();LCD_ESTAGIO++;break;
			case 2: lcd_low_e();LCD_ESTAGIO++;break;
			case 3: lcd_write_4bit(LCD_BACKBUFFER[1][LCD_OPERACAO-18]);LCD_ESTAGIO++;break;
			case 4: lcd_high_e();LCD_ESTAGIO++;break;
			case 5: lcd_low_e();LCD_ESTAGIO++;break;
			case 6: LCD_OPERACAO++; LCD_ESTAGIO=0;break;
		}
	}else if(LCD_OPERACAO==34){// goto CURSOR -> instr 0x80 | (0x40) | coluna
		switch(LCD_ESTAGIO){
			case 0: 
				if(LCD_CURSOR[0]==0){
					lcd_instr_pin();lcd_write_4bit(0x08);LCD_ESTAGIO++;break;
				}else if(LCD_CURSOR[0]==1){
					lcd_instr_pin();lcd_write_4bit(0x0C);LCD_ESTAGIO++;break;
				}else{
					lcd_instr_pin();lcd_write_4bit(0x0B);LCD_ESTAGIO++;break;
				}
			case 1: lcd_high_e();LCD_ESTAGIO++;break;
			case 2: lcd_low_e();LCD_ESTAGIO++;break;
			case 3: lcd_write_4bit(LCD_CURSOR[1]);LCD_ESTAGIO++;break;
			case 4: lcd_high_e();LCD_ESTAGIO++;break;
			case 5: lcd_low_e();LCD_ESTAGIO++;break;
			case 6: LCD_OPERACAO++; LCD_ESTAGIO=0;break;
		}
	}else{
		LCD_OPERACAO++;
		if(LCD_OPERACAO>=3000){
			LCD_OPERACAO=0;
			LCD_ESTAGIO=0;
			if(LCD_TAM_MENSAGEM>0){
				LCD_MSG_COUNTER++;
				if(LCD_MSG_COUNTER >= LCD_MSG_DIV){
					char i;
					LCD_MSG_ATUAL++;
					if(LCD_MSG_ATUAL>=LCD_TAM_MENSAGEM)LCD_MSG_ATUAL = 0;
					for(i=0;i<LCD_MSG_POS[2];i++)
						LCD_BACKBUFFER[LCD_MSG_POS[0]][LCD_MSG_POS[1]+i] = LCD_MENSAGEM[(LCD_MSG_ATUAL+i)%LCD_TAM_MENSAGEM];
					LCD_MSG_COUNTER = 0;
				}					
			}
			if(estado_aquecedor()){
				LCD_BACKBUFFER[0][15] = 0x0C;
			}else{
				LCD_BACKBUFFER[0][15] = ' ';
			}
			if(estado_motor()==2){
				LCD_BACKBUFFER[1][15] = 0x0D;
			}else if(estado_motor()==1){
				LCD_BACKBUFFER[1][15] = 0x0E;
			}else{
				LCD_BACKBUFFER[1][15] = ' ';
			}
		}
	}
}
/*
void lcd_goto(char linha, char coluna){
	linha &= 0x01;
	coluna &= 0x0F;
	lcd_set_DDRAM_addr((linha<<6)|coluna);
}*/
void lcd_print_str(char l, char c, char *str){
	char o = 0;
	while(str[o]!=0 && c<16){
		LCD_BACKBUFFER[l][c] = str[o];
		c++;
		o++;
	}
}
void lcd_print_int(char l, char c, int x){
	int div;
	if(x<0){
		LCD_BACKBUFFER[l][c] = '-';
		c++;
		x = -x;
	}
	if(x==0){
		LCD_BACKBUFFER[l][c] = '0';
		return;
	}
	for(div=10000;div>x;div/=10);
	while(div>0){
		char res = x / div;
		x = x % div;
		div /= 10;
		LCD_BACKBUFFER[l][c] = '0'+res;
		c++;
	}
}
void lcd_print_float_31(char l, char c, float x){
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
	lcd_print_str(l, c, buff);
}
void lcd_clear(){
	for(int i=0;i<16;i++){
		LCD_BACKBUFFER[0][i] = ' ';
		LCD_BACKBUFFER[1][i] = ' ';
	}
	LCD_TAM_MENSAGEM = 0;
}
void lcd_set_mensagem(char l, char c, char comp, char* msg){
	LCD_TAM_MENSAGEM = 0;
	for(LCD_TAM_MENSAGEM=0;msg[LCD_TAM_MENSAGEM]!=0;LCD_TAM_MENSAGEM++)LCD_MENSAGEM[LCD_TAM_MENSAGEM]=msg[LCD_TAM_MENSAGEM];
	LCD_MENSAGEM[LCD_TAM_MENSAGEM]=' ';
	LCD_MENSAGEM[LCD_TAM_MENSAGEM+1]='*';
	LCD_MENSAGEM[LCD_TAM_MENSAGEM+2]=' ';
	LCD_TAM_MENSAGEM+=3;
	LCD_MSG_POS[0] = l;
	LCD_MSG_POS[1] = c;
	LCD_MSG_POS[2] = comp;
	LCD_MSG_ATUAL = LCD_TAM_MENSAGEM -2;
	LCD_MSG_COUNTER = 0;
}



#endif
