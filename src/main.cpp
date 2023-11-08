#include <Arduino.h>
#include <ArduinoJson.h>
#include <string.h>
#include <oled_display_weather.h>
int i = 0;
void setup()
{
  oled_display_weather_init();
  digitalWrite(PD2, LOW);
}
void loop()
{
  pinMode(PD2, OUTPUT);
  DynamicJsonDocument jsonBuffer(2048);
  while (Serial.available() > 0)
  {
    String c = Serial.readStringUntil('\n');
    DeserializationError error = deserializeJson(jsonBuffer, c);
    if (error)
    {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
    }
    else
    {
      String city(jsonBuffer["data"]["now"]["cityname"]);
      String weather(jsonBuffer["data"]["now"]["weather"]);
      String date(jsonBuffer["data"]["now"]["date"]);
      String temp(jsonBuffer["data"]["now"]["temp"]);
      OLED_Clear();
      OLED_DisPlay_Off();
      OLED_Clear();
      oled_display_city(city);
      oled_display_weather_word(weather);
      oled_display_time(date);
      oled_display_temp(temp);
      OLED_DisPlay_On();
      digitalWrite(PD2, HIGH);
    }
  }
}
