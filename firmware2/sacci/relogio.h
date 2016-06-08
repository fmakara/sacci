#ifndef RELOGIO_H
#define RELOGIO_H

#include <avr/interrupt.h>
#include "interfaces.h"

//Projeto feito para clock de 16MHz
long int MILLIS, SEGUNDOS;
int MILLIS_TOPPED;

void relogio_init(){
	// Timer 2 usado para milisegundos (e segundos);
	TCCR2A = (1<<WGM21)|(1<<WGM20);// modo Fast PWM (interrupcoes e top com OCRA);
	TCCR2B = (1<<WGM22)|(1<<CS22)|(1<<CS20);// 16MHz/128 = 125000
	OCR2A  = 125-1; // 125000/125 = 1000
	TIMSK2 = (1<<TOIE2);
	ASSR = 0;
	sei();//habilita interrupcoes
	MILLIS = 0;
	SEGUNDOS = 0;
	MILLIS_TOPPED = 0;
}
void interrupt_1ms(); //Para fins de leitura (e nao ter ponteiros de funcoes), função definida em menus.h
ISR(TIMER2_OVF_vect){
	MILLIS++;
	MILLIS_TOPPED++;
	if(MILLIS_TOPPED>=1000){
		MILLIS_TOPPED = 0;
		SEGUNDOS++;
	}
	interrupt_1ms();
}


#endif