#ifndef INTERFACES_H
#define INTERFACES_H

char SHIFT_REG;
// ADC0
// ADC1
// ADC2
// ADC3
// ADC4     7     4
// 2     3     6
// 1        5     0



int adc_read(char pino){
	ADMUX  = 0b01000000 | (pino&0x07);
	ADCSRA |= (1<<ADSC);
	while(ADCSRA&(1<<ADSC));
	return ADC;
}
int async_adc_read(char pino){
	int ret = ADC;
	ADMUX  = 0b01000000 | (pino&0x07);
	ADCSRA |= (1<<ADSC);
	return ret;
}
char estado_aquecedor(){
	return (PORTD&(1<<4))>0;
}
void aquecedor_ligar(){
	PORTD |= (1<<4);
}
void aquecedor_desligar(){
	PORTD &= ~(1<<4);
}
void motor_subir(){
	PORTD &= ~(1<<2);
	PORTD |=  (1<<3);
}
void motor_descer(){
	PORTD &= ~(1<<3);
	PORTD |=  (1<<2);
}
void motor_parar(){
	PORTD &= ~((1<<2)|(1<<3));
}
char estado_motor(){
	return (PORTD>>2)&0x03;
}

void bipe(){
	PORTC |= (1<<4);
}
void silencio(){
	PORTC &= ~(1<<4);
}
#define _NOP() do { __asm__ __volatile__ ("nop"); } while (0)
void ler_shift(){
	//CLK - PC5
	//PE  - PD1
	//Q   - PD0
	SHIFT_REG = 0;
	PORTC &= ~(1<<5);
	PORTD |=  (1<<1);
	__asm__ __volatile__ ("nop");
	PORTD &= ~(1<<1);
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
	if(PIND&(1<<0))SHIFT_REG |= (1<<0);
	PORTC |=  (1<<5);
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
	if(PIND&(1<<0))SHIFT_REG |= (1<<1);
	PORTC &= ~(1<<5);
	__asm__ __volatile__ ("nop");
	PORTC |=  (1<<5);
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
	if(PIND&(1<<0))SHIFT_REG |= (1<<2);
	PORTC &= ~(1<<5);
	__asm__ __volatile__ ("nop");
	PORTC |=  (1<<5);
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
	if(PIND&(1<<0))SHIFT_REG |= (1<<3);
	PORTC &= ~(1<<5);
	__asm__ __volatile__ ("nop");
	PORTC |=  (1<<5);
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
	if(PIND&(1<<0))SHIFT_REG |= (1<<4);
	PORTC &= ~(1<<5);
	__asm__ __volatile__ ("nop");
	PORTC |=  (1<<5);
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
	if(PIND&(1<<0))SHIFT_REG |= (1<<5);
	PORTC &= ~(1<<5);
	__asm__ __volatile__ ("nop");
	PORTC |=  (1<<5);
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
	if(PIND&(1<<0))SHIFT_REG |= (1<<6);
	PORTC &= ~(1<<5);
	__asm__ __volatile__ ("nop");
	PORTC |=  (1<<5);
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
	if(PIND&(1<<0))SHIFT_REG |= (1<<7);
	PORTC &= ~(1<<5);
	__asm__ __volatile__ ("nop");
}
void init_interfaces(){
	//resistencia/aquecedor
	DDRD |= (1<<4);
	PORTD &= ~(1<<4);
	//motor
	DDRD |= (1<<2)|(1<<3);
	PORTD &= ~((1<<2)|(1<<3));
	//Shift
	//CLK - PC5
	//PE  - PD1
	//Q   - PD0
	DDRD &= ~(1<<0);
	DDRD |=  (1<<1);
	DDRC |=  (1<<5)|(1<<4);
	PORTC &= ~(1<<4);
	ler_shift();
	/*
	//botoes
	DDRD &=~((1<<0)|(1<<1)|(1<<4));
	DDRC &=~(1<<4);
	MCUCR &= ~(1<<4);
	PORTD |= (1<<0)|(1<<1)|(1<<4);
	PORTC |= (1<<4);
	//fimdecurso
	DDRC &=~((1<<2)|(1<<3));
	PORTC &=~((1<<2)|(1<<3));*/
	//analog
	ADMUX  = 0b01000000;//bits forma natural(2-8), Referencia 5V.
	ADCSRA = 0b10000111;//clk/128, ADC habilitado
	DIDR0  = 0b00001111;//Pinos PC0 e PC1 analogicos PC4 digital
}

// ADC0
// ADC1
// ADC2
// ADC3
// ADC4     7     4
// 2     3     6
// 1        5     0
char botao_cima(){
	return (SHIFT_REG&(1<<7))==0;
}
char botao_baixo(){
	return (SHIFT_REG&(1<<5))==0;
}
char botao_direita(){
	return (SHIFT_REG&(1<<6))==0;
}
char botao_esquerda(){
	return (SHIFT_REG&(1<<3))==0;
}
char botao_ok(){
	return (SHIFT_REG&(1<<4))==0;
}

char botao_cancela(){
	return (SHIFT_REG&(1<<0))==0;
}
char fdc_1(){
	return (SHIFT_REG&(1<<1))!=0;
}
char fdc_2(){
	return (SHIFT_REG&(1<<2))!=0;
}
char botoes_ler(int timeout){
	char maximo = 0;
	char leitura;
	while(maximo==0){
		leitura = ((botao_baixo()&0x01)<<0)|((botao_cima()&0x01)<<1)|((botao_direita()&0x01)<<2)|((botao_esquerda()&0x01)<<3)|((botao_ok()&0x01)<<4)|((botao_cancela()&0x01)<<5);
		maximo |= leitura;
		_delay_ms(1);
		timeout--;
		if(timeout==0)return 0;
	}
	_delay_ms(100);
	while(leitura!=0){
		leitura = ((botao_baixo()&0x01)<<0)|((botao_cima()&0x01)<<1)|((botao_direita()&0x01)<<2)|((botao_esquerda()&0x01)<<3)|((botao_ok()&0x01)<<4)|((botao_cancela()&0x01)<<5);
		maximo |= leitura;
		_delay_ms(1);
		timeout--;
		if(timeout==0)return 0;
	}
	_delay_ms(100);
	switch(maximo){
		case 0b00000001:return 1;
		case 0b00000010:return 2;
		case 0b00000100:return 3;
		case 0b00001000:return 4;
		case 0b00010000:return 5;
		case 0b00100000:return 6;
	}
	return 0;
}

#endif