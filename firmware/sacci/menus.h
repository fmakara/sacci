#ifndef MENUS_H
#define MENUS_H

#include "buffered_lcd.h"
#include "interfaces.h"
#include "relogio.h"
#include <avr/eeprom.h>


int ler_int_pequeno(char l, char c, float inicial){
	while(1){
		lcd_print_int(l,c+1,inicial);
		LCD_BACKBUFFER[l][c] = 0x08;
		LCD_BACKBUFFER[l][c+6] = 0x09;
		LCD_CURSOR[0] = l;
		LCD_CURSOR[1] = c+5;
		switch(botoes_ler(30000)){
			case 1: inicial--; break;
			case 2: inicial++; break;
			case 3: return inicial;;
			case 4: 
			default: return -1;
		}
	}
}
float ler_float(char l, char c, float inicial){
	const float incremento[5] = {100.0, 10.0, 1.0, 0, 0.1};
	char botao, algarismo = 3;
	while(algarismo>0 && algarismo<6){
		lcd_print_float_31(l,c+1,inicial);
		LCD_BACKBUFFER[l][c] = 0x08;
		LCD_BACKBUFFER[l][c+6] = 0x09;
		LCD_CURSOR[0] = l;
		LCD_CURSOR[1] = c+algarismo;
		botao = botoes_ler(30000);
		switch(botao){
			case 1: inicial -= incremento[algarismo-1];break;
			case 2: inicial += incremento[algarismo-1];break;
			case 3: algarismo++; if(algarismo==4)algarismo=5; break;
			case 4: algarismo--; if(algarismo==4)algarismo=3; break;
			default: algarismo = 0;
		}
	}
	if(algarismo==0)return -1000.0;
	else return inicial;
}
#define CAL_MAX_PONTOS 32
const uint16_t *CAL_TAMANHO[2] = {(uint16_t*)(0*sizeof(uint16_t)), (uint16_t*)(1*sizeof(uint16_t))};
const float *CAL_VAL_X[2] = {(float*)(2*sizeof(uint16_t)),(float*)(2*sizeof(int)+CAL_MAX_PONTOS*sizeof(float))};
const float *CAL_VAL_Y[2] = {(float*)(2*sizeof(int)+2*CAL_MAX_PONTOS*sizeof(float)),(float*)(2*sizeof(int)+3*CAL_MAX_PONTOS*sizeof(float))};
const float *TEMP_MINMAX = (float*)((2+4*CAL_MAX_PONTOS)*sizeof(float)); // min0 max0 min1 max1
const uint16_t *ULTIMO_TEMPO_CORROSAO = (uint16_t*)((6+4*CAL_MAX_PONTOS)*sizeof(float));

char PARADA_EMERGENCIA;
//Leituras de ADC
int ADC_LEITURA[2];

float corrigir_sensor(char index, float raw){
	int tamanho = eeprom_read_word(CAL_TAMANHO[index]);
	int offset;
	if(tamanho==0)return 25.0;
	if(tamanho==1)return eeprom_read_float(CAL_VAL_Y[index]);
	for(offset=1;eeprom_read_float(CAL_VAL_X[index]+offset)<raw && offset<tamanho-1; offset++);
	//Agora o valor está entre VAL_VAL_X[offset] e CAL_VAL_X[offset+_1], ou vai ser tratado como se estivesse
	//Da wikipedia, y = y0+(y1-y0)*(x-x0)/(x1-x0)
	float x0 = eeprom_read_float(CAL_VAL_X[index]+offset-1);
	float x1 = eeprom_read_float(CAL_VAL_X[index]+offset);
	float y0 = eeprom_read_float(CAL_VAL_Y[index]+offset-1);
	float y1 = eeprom_read_float(CAL_VAL_Y[index]+offset);
	return y0+(y1-y0)*(raw-x0)/(x1-x0);
}
void init_menus(){
	PARADA_EMERGENCIA = 0;
	ADC_LEITURA[0] = adc_read(0);
	ADC_LEITURA[1] = adc_read(1);
}
void inicializar_calibracao(){
	eeprom_write_word(CAL_TAMANHO[0], 5);
	eeprom_write_word(CAL_TAMANHO[1], 5);
	eeprom_write_float(CAL_VAL_X[0]+0, 1);
	eeprom_write_float(CAL_VAL_X[0]+1, 2);
	eeprom_write_float(CAL_VAL_X[0]+2, 3);
	eeprom_write_float(CAL_VAL_X[0]+3, 4);
	eeprom_write_float(CAL_VAL_X[0]+4, 5);
	eeprom_write_float(CAL_VAL_Y[0]+0, 0);
	eeprom_write_float(CAL_VAL_Y[0]+1, 69.3);
	eeprom_write_float(CAL_VAL_Y[0]+2, 109.8);
	eeprom_write_float(CAL_VAL_Y[0]+3, 138.6);
	eeprom_write_float(CAL_VAL_Y[0]+4, 160.9);
	eeprom_write_float(CAL_VAL_X[1]+0, 1);
	eeprom_write_float(CAL_VAL_X[1]+1, 2);
	eeprom_write_float(CAL_VAL_X[1]+2, 3);
	eeprom_write_float(CAL_VAL_X[1]+3, 4);
	eeprom_write_float(CAL_VAL_X[1]+4, 5);
	eeprom_write_float(CAL_VAL_Y[1]+0, 0);
	eeprom_write_float(CAL_VAL_Y[1]+1, 69.3);
	eeprom_write_float(CAL_VAL_Y[1]+2, 109.8);
	eeprom_write_float(CAL_VAL_Y[1]+3, 138.6);
	eeprom_write_float(CAL_VAL_Y[1]+4, 160.9);
	eeprom_write_float(TEMP_MINMAX+0, 40.0);
	eeprom_write_float(TEMP_MINMAX+1, 80.0);
	eeprom_write_float(TEMP_MINMAX+2, 40.0);
	eeprom_write_float(TEMP_MINMAX+3, 80.0);
	eeprom_write_word(ULTIMO_TEMPO_CORROSAO, 15);
}
int menu_principal(){
	int atual = 0;
	const char menus[7][16] = {
		"Corroer placa  ",
		"Aquecedor L/D  ",
		"Suporte   S/D  ",
		"Info termometro",
		"Temp. Maximas  ",
		"Calib. term. 1 ",
		"Calib. term. 2 "
	};
	lcd_clear();
	LCD_CURSOR[0] = -1;
	lcd_set_mensagem(0,0,15,"Selecione o que deseja fazer com cima/baixo e OK");
	while(1){
		lcd_print_str(1,0,menus[atual]);
		switch(botoes_ler(30000)){
			case 1: atual++; if(atual>7)atual=0; break;
			case 2: atual--; if(atual<0)atual=7-1; break;
			case 3: return atual;
		}
	}		
}
void menu_corroer_placa(){
	int tempo;
	lcd_clear();
	LCD_CURSOR[0] = -1;
	PARADA_EMERGENCIA = 0;
	lcd_print_str(0,0,"  LEVANTANDO   ");
	lcd_print_str(1,0,"               ");
	motor_subir();
	while(!fdc_1()){
		_delay_ms(100);
		if(PARADA_EMERGENCIA){
			//Motor e aquecedor já parados durante a interrupção
			lcd_print_str(0,0,"    PARADA     ");
			lcd_print_str(1,0,"  EMERGENCIA   ");
			_delay_ms(1000);
			return;
		}
	}
	motor_parar();
	lcd_clear();
	lcd_set_mensagem(0,0,15,"Coloque a placa no suporte e entre com tempo de corrosao (minutos)");
	lcd_print_str(1,0,"           min ");
	tempo = ler_int_pequeno(1,4,eeprom_read_word(ULTIMO_TEMPO_CORROSAO));
	lcd_clear();
	if(tempo>0){
		if(PARADA_EMERGENCIA){
			//Motor e aquecedor já parados durante a interrupção
			lcd_print_str(0,0,"    PARADA     ");
			lcd_print_str(1,0,"  EMERGENCIA   ");
			_delay_ms(1000);
			return;
		}
		eeprom_write_word(ULTIMO_TEMPO_CORROSAO, tempo);
		tempo *= 60;
		lcd_print_str(0,0,"   DESCENDO    ");
		lcd_print_str(1,0,"               ");
		motor_descer();
		while(!fdc_2()){
			_delay_ms(100);
			if(PARADA_EMERGENCIA){
				//Motor e aquecedor já parados durante a interrupção
				lcd_print_str(0,0,"    PARADA     ");
				lcd_print_str(1,0,"  EMERGENCIA   ");
				_delay_ms(1000);
				return;
			}
		}
		motor_parar();
		//Comecando corrosão
		SEGUNDOS = 0;
		while(tempo-SEGUNDOS>0){
			int seg = (tempo-SEGUNDOS)%60;
			int min = (tempo-SEGUNDOS)/60;
			float t1 = corrigir_sensor(0,ADC_LEITURA[0]);
			float t2 = corrigir_sensor(1,ADC_LEITURA[1]);
			if(PARADA_EMERGENCIA){
				//Motor e aquecedor já parados durante a interrupção
				lcd_print_str(0,0,"    PARADA     ");
				lcd_print_str(1,0,"  EMERGENCIA   ");
				_delay_ms(1000);
				return;
			}
			if(t1<eeprom_read_float(TEMP_MINMAX+0) && 
			   t2<eeprom_read_float(TEMP_MINMAX+2)){
				aquecedor_ligar();
			}
			if(t1>eeprom_read_float(TEMP_MINMAX+1) ||
			   t2>eeprom_read_float(TEMP_MINMAX+3)){
				aquecedor_desligar();
			}
			lcd_print_str(0,0,"T1:           m");
			lcd_print_str(1,0,"T2:         seg");
			lcd_print_float_31(0,3,t1);
			lcd_print_float_31(1,3,t2);
			lcd_print_int(0,11,min);
			lcd_print_int(1,11,seg);
			motor_subir();
			_delay_ms(500);
			if(PARADA_EMERGENCIA){
				//Motor e aquecedor já parados durante a interrupção
				lcd_print_str(0,0,"    PARADA     ");
				lcd_print_str(1,0,"  EMERGENCIA   ");
				_delay_ms(1000);
				return;
			}
			motor_descer();
			while(!fdc_2()){
				_delay_ms(100);
				if(PARADA_EMERGENCIA){
					//Motor e aquecedor já parados durante a interrupção
					lcd_print_str(0,0,"    PARADA     ");
					lcd_print_str(1,0,"  EMERGENCIA   ");
					_delay_ms(1000);
					return;
				}
			}
			motor_parar();
		}
		lcd_print_str(0,0,"  LEVANTANDO   ");
		lcd_print_str(1,0,"               ");
		motor_subir();
		while(!fdc_1()){
			_delay_ms(100);
			if(PARADA_EMERGENCIA){
				//Motor e aquecedor já parados durante a interrupção
				lcd_print_str(0,0,"    PARADA     ");
				lcd_print_str(1,0,"  EMERGENCIA   ");
				_delay_ms(1000);
				return;
			}
		}
		motor_parar();
		lcd_print_str(0,0,"     FIM       ");
		lcd_print_str(1,0,"               ");
		_delay_ms(1000);
	}
}
void menu_liga_aquecedor(){
	char ultimo_estado = -1;
	lcd_clear();
	LCD_CURSOR[0] = -1;
	while(1){
		if(estado_aquecedor()!=ultimo_estado){
			ultimo_estado = estado_aquecedor();
			if(ultimo_estado){
				lcd_set_mensagem(0,0,15,"Aquecedor LIGADO!");
				lcd_print_str(1,0,"\x08voltar  desl.\x09");
			}else{
				lcd_set_mensagem(0,0,15,"Aquecedor DESLIGADO");
				lcd_print_str(1,0,"\x08voltar  ligar\x09");
			}				
		}
		switch(botoes_ler(1000)){
			case 3: 
				if(estado_aquecedor())aquecedor_desligar();
				else aquecedor_ligar();
				break;
			case 4: return;
		}
	}
}
void menu_subir_suporte(){
	lcd_clear();
	LCD_CURSOR[0] = -1;
	lcd_set_mensagem(0,0,15,"Aperte os botoes \x0A e \x0B para subir/descer o suporte ou \x08 para voltar");
	while(1){
		if(botao_esquerda())return;
		if(botao_cima() && !fdc_1()){
			motor_subir();
			lcd_print_str(1,0,"Subindo ");
		}else if(botao_baixo() && !fdc_2()){
			motor_descer();
			lcd_print_str(1,0,"Descendo");
		}else{
			motor_parar();
			lcd_print_str(1,0,"Parado  ");
		}
		_delay_ms(200);
	}
	
}
void menu_calibrar_termometro(int index){
	char fim_aquisicao = 0;
	int nrPontos = 0;
	float cal_x[CAL_MAX_PONTOS], cal_y[CAL_MAX_PONTOS];
	lcd_clear();
	lcd_set_mensagem(0,0,15,"Para a calibracao, voce devera manter um termometro o mais proximo possivel do NTC.");
	lcd_print_str(1,0,"Leia e apos \x09");
	if(botoes_ler(50000)!=3)return;
	lcd_set_mensagem(0,0,15,"Entao, para adicionar um ponto de calibracao aperte \x09 e digite a temperatura atual.");
	if(botoes_ler(50000)!=3)return;
	lcd_set_mensagem(0,0,15,"Quando tiver pontos suficientes, aperte \x08 para finalizar");
	if(botoes_ler(50000)!=3)return;
	lcd_set_mensagem(0,0,15,"Para salvar o grupo de pontos na memoria aperte entao \x09. Para descartar \x08.");
	if(botoes_ler(50000)!=3)return;
	lcd_clear();
	while(!fim_aquisicao){
		int offset;
		float raw = adc_read(index);
		lcd_print_str(0,0,"Previsao:     \xDF");
		lcd_print_str(1,0,"\x08fim      add\x09");
		LCD_CURSOR[0] = -1;
		float previsao;
		if(nrPontos==0) previsao=25.0;
		else if(nrPontos==1) previsao=cal_y[0];
		else{
			for(offset=1;cal_x[offset]<raw && offset<nrPontos-1; offset++);
			previsao = cal_y[offset-1]+(cal_y[offset]-cal_y[offset-1])*(raw-cal_x[offset-1])/(cal_x[offset]-cal_x[offset-1]);
		}
		lcd_print_float_31(0,9,previsao);
		switch(botoes_ler(1000)){
			case 4:	fim_aquisicao = 1; break;
			case 3:
				lcd_print_str(0,0,"\x0A\x0B\x08\x09 p/ editar ");
				lcd_print_str(1,0,"            \xDFC ");
				previsao = ler_float(1,2,previsao);
				if(previsao>-100){
					for(offset=0;cal_x[offset]<raw && offset<nrPontos; offset++);
					for(int k=nrPontos-1;k>=offset;k--){
						cal_x[k+1] = cal_x[k];
						cal_y[k+1] = cal_y[k];
					}
					cal_x[offset] = raw;
					cal_y[offset] = previsao;
					nrPontos++;
				}
		}
	}
	lcd_print_str(0,0,"Salvar     pts?");
	lcd_print_str(1,0,"\x08nao      sim\x09 ");
	lcd_print_int(0,7,nrPontos);
	if(botoes_ler(30000)==3){
		eeprom_write_word(CAL_TAMANHO[index],nrPontos);
		eeprom_write_block(cal_x,CAL_VAL_X[index],sizeof(float)*nrPontos);
		eeprom_write_block(cal_y,CAL_VAL_Y[index],sizeof(float)*nrPontos);
		lcd_print_str(0,0,"   CALIBRACAO  ");
		lcd_print_str(1,0,"   CONCLUIDA   ");
		_delay_ms(2000);
	}
}
void menu_temperaturas(){
	int i = 0;
	float buff;
	lcd_clear();
	LCD_CURSOR[0]=-1;
	lcd_set_mensagem(0,0,15,"Configure aqui as temperaturas maximas e de acionamento (minimas) com \x0A \x0B \x09. \x08 para voltar");
	while(1){
		switch(i){
			case 0: lcd_print_str(1,0,"Tmin 0:        "); break;
			case 1: lcd_print_str(1,0,"Tmax 0:        "); break;
			case 2: lcd_print_str(1,0,"Tmin 1:        "); break;
			case 3: lcd_print_str(1,0,"Tmax 1:        "); break;
		}
		lcd_print_float_31(1,7,eeprom_read_float(TEMP_MINMAX+i));
		switch(botoes_ler(10000)){
			case 1: i++; if(i>=4)i=0; break;
			case 2: i--; if(i<0)i=3; break;
			case 3: 
				lcd_print_str(1,0,"               ");
				buff = ler_float(1,3,eeprom_read_float(TEMP_MINMAX+i));
				LCD_CURSOR[0]=-1;
				if(buff>-100){
					eeprom_write_float(TEMP_MINMAX+i, buff);
				}
				break;
			case 4: return;
		}
	}
}
void menu_info_temperatura(){
	int menu = 0;
	int offset1 = eeprom_read_word(CAL_TAMANHO[0]);
	int offset2 = eeprom_read_word(CAL_TAMANHO[1]);
	lcd_clear();
	LCD_CURSOR[0]=-1;
	while(1){
		if(menu==0){
			lcd_print_str(0,0,"Term.1:        ");
			lcd_print_str(1,0,"Term.2:        ");
			lcd_print_float_31(0,8,corrigir_sensor(0,ADC_LEITURA[0]));
			lcd_print_float_31(1,8,corrigir_sensor(1,ADC_LEITURA[1]));
		}else if(menu<=offset1){
			lcd_print_str(0,0,"S1: Codigo     ");
			lcd_print_str(1,0,"      ->       ");
			lcd_print_int(0,11,menu-1);
			lcd_print_float_31(1,0,	eeprom_read_float(CAL_VAL_X[0]+menu-1));
			lcd_print_float_31(1,8,	eeprom_read_float(CAL_VAL_Y[0]+menu-1));
		}else{
			lcd_print_str(0,0,"S2: Codigo     ");
			lcd_print_str(1,0,"      ->       ");
			lcd_print_int(0,11,menu-1-offset1);
			lcd_print_float_31(1,0,	eeprom_read_float(CAL_VAL_X[1]+menu-1-offset1));
			lcd_print_float_31(1,8,	eeprom_read_float(CAL_VAL_Y[1]+menu-1-offset1));
		}
		switch(botoes_ler(1000)){
			case 1: 
				menu++; 
				if(menu>offset1+offset2)
					menu = 0;
				break;
			case 2: 
				menu--; 
				if(menu<0)
					menu = offset1+offset2;
				break;
			case 4: return;
		}
	}
	
}
void interrupt_1ms(){
	int buff;
	if(botao_baixo() && botao_esquerda()){
		motor_parar();
		aquecedor_desligar();
		PARADA_EMERGENCIA = 1;
	}
	if(MILLIS_TOPPED&1){
		buff = async_adc_read(0); //Valor do 1 aqui
		ADC_LEITURA[1] = (ADC_LEITURA[1]*7+buff)>>3;
	}else{
		buff = async_adc_read(1); //valor do 0 retornado
		ADC_LEITURA[0] = (ADC_LEITURA[0]*7+buff)>>3;
	}
	if((MILLIS_TOPPED%100)==0){
		float t0 = corrigir_sensor(0,ADC_LEITURA[0]);
		float t1 = corrigir_sensor(1,ADC_LEITURA[1]);
		if(t0>eeprom_read_float(TEMP_MINMAX+1) || t1>eeprom_read_float(TEMP_MINMAX+3)){
			aquecedor_desligar();
		}
	}
}
#endif