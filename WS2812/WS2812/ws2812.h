/*
 * ws2812.h
 *
 *  Created on: 20 paü 2018
 *      Author: Rafal
 */

#ifndef WS2812_WS2812_H_
#define WS2812_WS2812_H_

#define WS_PIN (1<<PD7)
#define WS_DDR DDRD
#define WS_PORT PORTD

typedef struct {
	uint8_t R;
	uint8_t G;
	uint8_t B;
} TWSRGB;

#define WS_LEDS_CNT 4

void ws2812_init(void);
void send_rgb(uint8_t,uint8_t,uint8_t);
void send_color(uint32_t);
void send_leds(TWSRGB * leds);


#endif /* WS2812_WS2812_H_ */
