#ifndef __OLED_RAM_CTR_H
#define __OLED_RAM_CTR_H
#include <Arduino.h>
#include <eeprom.h>
struct wordinfo
{
    String name;
    unsigned short addr;
    uint16_t size;
}; 
void oled_rom_write(String name, uint8_t *dat);
uint8_t *oled_rom_read(String name);
void OLED_ROM_INIT();
uint8_t num(String name);
uint8_t *oled_rom_read(uint8_t number);
#endif