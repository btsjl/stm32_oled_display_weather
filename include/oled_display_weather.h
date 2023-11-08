#ifndef __OLED_DISPLAY_WEATHER_H
#define __OLED_DISPLAY_WEATHER_H
#include<oled.h>
#include<oled_ram_ctr.h>
struct iconinfo
{
    uint8_t x;
    uint8_t y;
    uint8_t w;
    uint8_t h;
};
void oled_display_weather_init();
void oled_display_weather_icon(String name);
void oled_display_weather_word(String name);
void oled_display_city(String name);
void oled_display_time(String name);
void oled_display_temp(String name);
#endif