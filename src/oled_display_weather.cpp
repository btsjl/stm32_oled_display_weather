#include <oled_display_weather.h>
iconinfo info[32] = {
    {16, 0, 96, 64},
    {48, 0, 32, 32},
    {48, 0, 32, 32},
    {48, 0, 32, 32},
    {48, 0, 32, 32},
    {48, 0, 32, 32},
};
void oled_display_weather_init()
{
    OLED_INIT();
    EEPROM_Init();
    Serial.begin(115200);
}
void oled_display_weather_icon(String name)
{
    uint8_t *dat = oled_rom_read(name);
    OLED_Display_Picture(info[num(name)].x, info[num(name)].y, info[num(name)].w, info[num(name)].h, dat);
    free(dat);
}

void oled_display_city(String name)
{
    int n = name.length();
    char a[4];
    a[3] = '\0';
    int j, i, k = 0;
    for (i = 0; i < n / 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            a[j] = name[i * 3 + j];
        }
        String name_0(a);
        OLED_Display_16x16(16 * i, 0, oled_rom_read(name_0));
    }
}

void oled_display_weather_word(String name)
{
    int n = name.length();
    char a[4];
    a[3] = '\0';
    int j, i;
    for (i = 0; i < n / 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            a[j] = name[i * 3 + j];
        }
        String name_0(a);
        if (name_0 == "雨")
        {
            oled_display_weather_icon("png_yv");
        }
        else if (name_0 == "阴")
        {
            oled_display_weather_icon("png_yin");
        }
        else if (name_0 == "晴")
        {
            oled_display_weather_icon("png_qing");
        }
        else if (name_0 == "雪")
        {
            oled_display_weather_icon("png_xue");
        }
        else if (name_0 == "雷")
        {
            oled_display_weather_icon("png_lei");
        }
        else if (name_0 == "云")
        {
            oled_display_weather_icon("png_yin");
        }
        else;
        OLED_Display_16x16(16 * i, 4, oled_rom_read(name_0));
    }
}
void oled_display_time(String name)
{
    char a[2];
    a[1] = '\0';
    a[0] = name[0];
    String name_1(a);
    OLED_Display_8x16(0, 6, oled_rom_read("2"));
    OLED_Display_8x16(8, 6, oled_rom_read("0"));
    OLED_Display_8x16(16, 6, oled_rom_read("2"));
    OLED_Display_8x16(24, 6, oled_rom_read("3"));
    OLED_Display_8x16(32, 6, oled_rom_read("-"));
    OLED_Display_8x16(40, 6, oled_rom_read(name_1));
    name_1[0] = name[1];
    OLED_Display_8x16(48, 6, oled_rom_read(name_1));
    OLED_Display_8x16(56, 6, oled_rom_read("-"));
    name_1[0] = name[5];
    OLED_Display_8x16(64, 6, oled_rom_read(name_1));
    name_1[0] = name[6];
    OLED_Display_8x16(72, 6, oled_rom_read(name_1));
}

void oled_display_temp(String name)
{
    char a[2];
    a[1] = '\0';
    a[0] = name[0];
    int n = name.length(), i,k=1;
    String name_1(a);
    for (i = n - 1; i >= 0; i--)
    {
        name_1[0] = name[i];
        OLED_Display_8x16(128 - 8 * k, 0, oled_rom_read(name_1));
        k++;
    }
    OLED_Display_16x16(112, 2, oled_rom_read("ssd"));
}