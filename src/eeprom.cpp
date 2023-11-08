#include <eeprom.h>
TwoWire Wire_1(PB11, PB10);
void EEPROM_Init()
{
    Wire_1.begin();
}
void EEPROM_Write_Byte(unsigned short addr, uint8_t dat)
{
    uint8_t addr_high = highByte(addr), addr_low = lowByte(addr);
    Wire_1.beginTransmission(0x50);
    Wire_1.write(addr_high);
    Wire_1.write(addr_low);
    Wire_1.write(dat);
    Wire_1.endTransmission();
    delay(4);
}

uint8_t EEPROM_Read_Byte(unsigned short addr)
{
    uint8_t dat;
    uint8_t addr_high = highByte(addr), addr_low = lowByte(addr);
    Wire_1.beginTransmission(0x50);
    Wire_1.write(addr_high);
    Wire_1.write(addr_low);
    Wire_1.endTransmission();
    Wire_1.requestFrom(0x50, 1);
    while (Wire_1.available() == 0)
        ;
    dat = Wire_1.read();
    return dat;
}

void EEPROM_Write_String(unsigned short addr, uint8_t *dat, int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        EEPROM_Write_Byte(addr + i, dat[i]);
    }
}

uint8_t *EEPROM_Read_String(unsigned short addr, int size)
{
    int i = 0;
    uint8_t *data = new uint8_t[size];
    for(i=0;i<size;i++)
    data[i]=EEPROM_Read_Byte(addr+i);
    return data;
}
