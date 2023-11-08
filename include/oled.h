#ifndef __OLED_H
#define __OLED_H
#include<Arduino.h>
#include<SPI.h>
#define CLK PA5
#define SDA PA7
#define DC PD2
#define CS1 PB5
#define FS0 PA6
#define CS2 PB6
#define OLED_CMD 0
#define OLED_DATA 1
void OLED_INIT();
void OLED_WR_Byte(uint8_t dat, bool cmd);
void OLED_DisPlay_On(void);
void OLED_DisPlay_Off(void);
void OLED_Clear(void);
void OLED_address(uint8_t x, uint8_t y);
void OLED_Display_128x64(uint8_t *dp);
void OLED_Display_16x16(uint8_t x, uint8_t y, uint8_t *dp);
void OLED_Display_Picture(uint8_t x,uint8_t y,uint8_t w,uint8_t h,uint8_t *dp);
void OLED_Display_8x16(uint8_t x, uint8_t y, uint8_t *dp);
void OLED_Display_5x7(uint8_t x, uint8_t y, uint8_t *dp);
#endif
