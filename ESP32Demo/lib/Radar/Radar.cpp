#include <Arduino.h>
#include "Radar.h"

#define minAngle 30
#define maxAngle 150

Radar::Radar(int servoPin, int trigPin, int echoPin)
    : servoPin(servoPin), trigPin(trigPin), echoPin(echoPin), SG90_main(servoPin), SR04_main(trigPin, echoPin)
{
    // 在构造函数中初始化 SG90_main 和 SR04_main
}

void Radar::setup()
{
    SG90_main.setup();
    SR04_main.setup();
}

void Radar::loop()
{
    for (int i = minAngle; i < maxAngle; i += 1)
    {
        Serial.print(i);
        SG90_main.rotateServo(i);
        SR04_main.loop();
        // delay(100);
    }
    for (int i = maxAngle; i > minAngle; i -= 1)
    {
        Serial.print(i);
        SG90_main.rotateServo(i);
        SR04_main.loop();
        // delay(100);
    }
}
