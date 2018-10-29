/*
 * main.c
 *
 *  Created on: 20 paü 2018
 *      Author: Rafal
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <string.h>

#include "WS2812/ws2812.h"




int main( void ) {



	ws2812_init();	///Inicializacja

	send_color(0xFF0000);	//Zapal na czerwono max jasnosc
	send_color(0x00FF00);	//Zapal na zielono max jasnosc
	send_color(0x0000FF);	//Zapal na niebiesko max jasnosc
	send_color(0xFFFFFF);	//Zapal R,G,B na max jasnosc


	while(1) {



	}

}

