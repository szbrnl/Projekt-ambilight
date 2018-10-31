/*
 * ws2812.c
 *
 *  Created on: 20 pa� 2018
 *      Author: Rafal
 */

#include <avr/io.h>
#include <util/delay.h>

#include "ws2812.h"

//CALL - 2 takty zegarowe



void ws2812_init(void) {
	WS_DDR |= WS_PIN;
}

static void send_zero(void) {
	WS_PORT |= WS_PIN;
	asm("nop");	asm("nop");	asm("nop");
	///Nie rob nic przez 1 takt zegara
	WS_PORT &= ~WS_PIN;

}

static void send_one(void) {
	WS_PORT |= WS_PIN;
	asm("nop");	asm("nop");	asm("nop"); asm("nop");
	asm("nop");	asm("nop");	asm("nop"); asm("nop");
	WS_PORT &= ~WS_PIN;
}

void send_rgb(uint8_t r,uint8_t g, uint8_t b) {


	if( g & 128 ) send_one(); else send_zero();
	if( g & 64 ) send_one(); else send_zero();
	if( g & 32 ) send_one(); else send_zero();
	if( g & 16 ) send_one(); else send_zero();
	if( g & 8 ) send_one(); else send_zero();
	if( g & 4 ) send_one(); else send_zero();
	if( g & 2 ) send_one(); else send_zero();
	if( g & 1 ) send_one(); else send_zero();

	if( r & 128 ) send_one(); else send_zero();
	if( r & 64 ) send_one(); else send_zero();
	if( r & 32 ) send_one(); else send_zero();
	if( r & 16 ) send_one(); else send_zero();
	if( r & 8 ) send_one(); else send_zero();
	if( r & 4 ) send_one(); else send_zero();
	if( r & 2 ) send_one(); else send_zero();
	if( r & 1 ) send_one(); else send_zero();

	if( b & 128 ) send_one(); else send_zero();
	if( b & 64 ) send_one(); else send_zero();
	if( b & 32 ) send_one(); else send_zero();
	if( b & 16 ) send_one(); else send_zero();
	if( b & 8 ) send_one(); else send_zero();
	if( b & 4 ) send_one(); else send_zero();
	if( b & 2 ) send_one(); else send_zero();
	if( b & 1 ) send_one(); else send_zero();


}

void send_color(uint32_t color) {

	uint8_t r = color>>16, g = color>>8, b = color;

	send_rgb(r, g, b);
}

void send_leds(TWSRGB * leds) {

	uint8_t i;
	uint8_t *wsk = (uint8_t*)leds;

	for(i=0; i<WS_LEDS_CNT; i++) {
		send_rgb(*wsk,*(wsk+1),*(wsk+2));
		wsk += 3;
	}

	_delay_us(30);
}


