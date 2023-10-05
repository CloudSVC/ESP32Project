#include <Arduino.h>
#include "SG90.h"

void SG90::rotateServo(int targetAngle)
{
    int pulseWidth = map(targetAngle, 0, 180, 500, 2500); // 根据参数映射脉冲宽度范围
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(servoPin, LOW);
    delay(15);
}

// 范围转动 maxAngle 最大转动幅度， minAngle 最小转动幅度
void SG90::rangeRotate(int maxAngle, int minAngle)
{
    for (int i = minAngle; i < maxAngle; i += 15) {
        Serial.print(i);
        rotateServo(i);
        delay(400);
    }
    for (int i = maxAngle; i > minAngle; i -= 15) {
        Serial.print(i);
        rotateServo(i);
        delay(400);
    }
}

SG90::SG90(int servoPin)
{
    this->servoPin = servoPin;
}

void SG90::setup()
{
    pinMode(servoPin, OUTPUT);
}