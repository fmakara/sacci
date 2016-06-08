/*
 * sacci.c
 *
 * Created: 17/02/2016 22:07:59
 *  Author: Makara
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "buffered_lcd.h"
#include "interfaces.h"
#include "relogio.h"
#include "menus.h"



int main(void){
	init_interfaces();
	lcd_init();
	relogio_init();
	inicializar_calibracao();
	//lcd_set_mensagem(1,0,6,"Favor entrar com valor para ser guardado");
    while(1){
		int selecao = menu_principal();
		switch(selecao){
			case 0: menu_corroer_placa(); break;
			case 1: menu_liga_aquecedor(); break;
			case 2: menu_subir_suporte(); break;
			case 3: menu_info_temperatura(); break;
			case 4: menu_temperaturas(); break;
			case 5: menu_calibrar_termometro(0); break;
			case 6: menu_calibrar_termometro(1); break;
		}
    }
}