#include <Arduino.h>
#include "LedDemo.h"

LedDemo::LedDemo(int LedPin)
{
    this->LedPin = LedPin;
}

void LedDemo::setup()
{
    pinMode(LedPin, OUTPUT);
}

void LedDemo::loop()
{
    digitalWrite(LedPin, HIGH); // 打开LED
    delay(1000);                 // 暂停500毫秒（0.5秒）

    digitalWrite(LedPin, LOW); // 关闭LED
    delay(1000);                // 暂停500毫秒（0.5秒）
}