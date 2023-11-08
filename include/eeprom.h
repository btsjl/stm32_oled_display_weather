#ifndef __EEPROM_H
#define __EEPROM_H
#include <Arduino.h>
#include <Wire.h>
#include <string>
void EEPROM_Init(void);
void EEPROM_Write_Byte(unsigned short addr,uint8_t dat);
uint8_t EEPROM_Read_Byte(unsigned short addr);
void EEPROM_Write_String(unsigned short addr, uint8_t *dat,int size);
uint8_t* EEPROM_Read_String(unsigned short addr,int size);
#endif
