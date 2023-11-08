#include <oled_ram_ctr.h>
wordinfo info_word[] = {
    {"png_fengmian", 0, 768},
    {"png_qing", 768, 128},
    {"png_yv", 896, 128},
    {"png_lei", 1024, 128},
    {"png_xue", 1152, 128},
    {"png_yin", 1280, 128},
    {"0", 1408, 16},
    {"1", 1424, 16},
    {"2", 1440, 16},
    {"3", 1456, 16},
    {"4", 1472, 16},
    {"5", 1488, 16},
    {"6", 1520, 16},
    {"7", 1520, 16},
    {"8", 1536, 16},
    {"9", 1552, 16},
    {"晴", 1568, 32},
    {"多", 1600, 32},
    {"云", 1632, 32},
    {"雷", 1664, 32},
    {"阵", 1696, 32},
    {"雨", 1728, 32},
    {"大", 1760, 32},
    {"小", 1792, 32},
    {"中", 1824, 32},
    {"暴", 1856, 32},
    {"雪",1888,32},
    {"武",1920,32},
    {"汉",1952,32},
    {"-",1984,16},
    {"ssd",2000,32},
    {".",2032,16},
    {"阴",2048,32}
};
int word_info_size = 33;
void oled_rom_write(String name, uint8_t *dat)
{
    int i;
    for (i = 0; i < word_info_size; i++)
    {
        if (name.equals(info_word[i].name))
            EEPROM_Write_String(info_word[i].addr, dat, info_word[i].size);
    }
}
uint8_t *oled_rom_read(String name)
{
    int i;
    for (i = 0; i < word_info_size; i++)
    {
        if (name.equals(info_word[i].name))
            return EEPROM_Read_String(info_word[i].addr, info_word[i].size);
    }
    return 0;
}

uint8_t *oled_rom_read(uint8_t number)
{
    return EEPROM_Read_String(info_word[number].addr, info_word[number].size);
}
uint8_t num(String name)
{
    if (name.equals("png_fengmian"))
        return 0;
    else if (name.equals("png_qing"))
        return 1;
    else if (name.equals("png_yv"))
        return 2;
    else if (name.equals("png_lei"))
        return 3;
    else if (name.equals("png_xun"))
        return 4;
    else if (name.equals("png_yin"))
        return 5;
    else
        return 7;
}

void OLED_ROM_INIT()
{
    EEPROM_Init();
}