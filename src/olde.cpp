#include <oled.h>
void OLED_INIT()
{
    pinMode(DC, OUTPUT);
    pinMode(CS1, OUTPUT);
    pinMode(CS2, OUTPUT);
    SPI.begin();
}
void OLED_WR_Byte(uint8_t dat, bool cmd)
{
    if (cmd)
        digitalWrite(DC, HIGH);
    else
        digitalWrite(DC, LOW);
    digitalWrite(CS1, LOW);
    SPI.transfer(dat);
    digitalWrite(DC, HIGH);
    digitalWrite(CS1, HIGH);
}
void OLED_DisPlay_On(void)
{
    OLED_WR_Byte(0x8D, OLED_CMD); // 电荷泵使能
    OLED_WR_Byte(0x14, OLED_CMD); // 开启电荷泵
    OLED_WR_Byte(0xAF, OLED_CMD); // 点亮屏幕
}

void OLED_DisPlay_Off(void)
{
    OLED_WR_Byte(0x8D, OLED_CMD); // 电荷泵使能
    OLED_WR_Byte(0x10, OLED_CMD); // 关闭电荷泵
    OLED_WR_Byte(0xAE, OLED_CMD); // 关闭屏幕
}

void OLED_Clear(void)
{
    uint8_t i, j;
    for (i = 0; i < 8; i++)
    {
        OLED_address(0, i);
        for (j = 0; j < 128; j++)
        {
            OLED_WR_Byte(0x00, OLED_DATA); // 写数据到OLED,每写完一个8位的数据后列地址自动加1
        }
    }
}

void OLED_address(uint8_t x, uint8_t y)
{
    x += 2;
    OLED_WR_Byte(0xb0 + y, OLED_CMD);                 // 设置页地址
    OLED_WR_Byte(((x & 0xf0) >> 4) | 0x10, OLED_CMD); // 设置列地址的高4位
    OLED_WR_Byte((x & 0x0f), OLED_CMD);               // 设置列地址的低4位
}

void OLED_Display_128x64(uint8_t *dp)
{
    uint8_t i, j;
    for (i = 0; i < 8; i++)
    {
        OLED_address(0, i);
        for (j = 0; j < 128; j++)
        {
            OLED_WR_Byte(*dp, OLED_DATA); // 写数据到OLED,每写完一个8位的数据后列地址自动加1
            dp++;
        }
    }
}
void OLED_Display_16x16(uint8_t x, uint8_t y, uint8_t *dp)
{
    uint8_t i, j;
    for (j = 0; j < 2; j++)
    {
        OLED_address(x, y);
        for (i = 0; i < 16; i++)
        {
            OLED_WR_Byte(*dp, OLED_DATA); // 写数据到OLED,每写完一个8位的数据后列地址自动加1
            dp++;
        }
        y++;
    }
}

/*
显示图片
x,y位置

*/

void OLED_Display_Picture(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t *dp)
{
    uint8_t i, j;
    for (j = 0; j < h / 8; j++)
    {
        OLED_address(x, y);
        for (i = 0; i < w; i++)
        {
            OLED_WR_Byte(*dp, OLED_DATA); // 写数据到OLED,每写完一个8位的数据后列地址自动加1
            dp++;
        }
        y++;
    }
}

void OLED_Display_8x16(uint8_t x, uint8_t y, uint8_t *dp)
{
    uint8_t i, j;
    for (j = 0; j < 2; j++)
    {
        OLED_address(x, y);
        for (i = 0; i < 8; i++)
        {
            OLED_WR_Byte(*dp, OLED_DATA); // 写数据到LCD,每写完一个8位的数据后列地址自动加1
            dp++;
        }
        y++;
    }
}

void OLED_Display_5x7(uint8_t x, uint8_t y, uint8_t *dp)
{
    uint8_t i;
    OLED_address(x, y);
    for (i = 0; i < 6; i++)
    {
        OLED_WR_Byte(*dp, OLED_DATA);
        dp++;
    }
}
