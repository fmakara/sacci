#ifndef INTERFACES_H
#define INTERFACES_H


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
	return (PORTC&(1<<5))>0;
}
void aquecedor_ligar(){
	PORTC |= (1<<5);
}
void aquecedor_desligar(){
	PORTC &= ~(1<<5);
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
void init_interfaces(){
	//resistencia/aquecedor
	DDRC |= (1<<5);
	PORTC &= ~(1<<5);
	//motor
	DDRD |= (1<<2)|(1<<3);
	PORTD &= ~((1<<2)|(1<<3));
	//botoes
	DDRD &=~((1<<0)|(1<<1)|(1<<4));
	DDRC &=~(1<<4);
	MCUCR &= ~(1<<4);
	PORTD |= (1<<0)|(1<<1)|(1<<4);
	PORTC |= (1<<4);
	//fimdecurso
	DDRC &=~((1<<2)|(1<<3));
	PORTC &=~((1<<2)|(1<<3));
	//analog
	ADMUX  = 0b01000000;//bits forma natural(2-8), Referencia 5V.
	ADCSRA = 0b10000111;//clk/128, ADC habilitado
	DIDR0  = 0b00000011;//Pinos PC0 e PC1 analogicos
}
char botao_cima(){
	return (PINC&(1<<4))==0;
}
char botao_baixo(){
	return (PIND&(1<<4))==0;
}
char botao_direita(){
	return (PIND&(1<<0))==0;
}
char botao_esquerda(){
	return (PIND&(1<<1))==0;
}
char fdc_1(){
	return (PINC&(1<<2))>0;
}
char fdc_2(){
	return (PINC&(1<<3))>0;
}
char botoes_ler(int timeout){
	char maximo = 0;
	char leitura;
	while(maximo==0){
		leitura = ((botao_baixo()&0x01)<<0)|((botao_cima()&0x01)<<1)|((botao_direita()&0x01)<<2)|((botao_esquerda()&0x01)<<3);
		maximo |= leitura;
		_delay_ms(1);
		timeout--;
		if(timeout==0)return 0;
	}
	_delay_ms(100);
	while(leitura!=0){
		leitura = ((botao_baixo()&0x01)<<0)|((botao_cima()&0x01)<<1)|((botao_direita()&0x01)<<2)|((botao_esquerda()&0x01)<<3);
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
	}
	return 0;
}

#endif