#include <Arduino.h>
#include "Inductive.h"

// const int trigPin = 2; // 超声波传感器的Trig引脚连接到ESP32的GPIO2
// const int echoPin = 4; // 超声波传感器的Echo引脚连接到ESP32的GPIO4
// int servoPin = 14; // 舵机1的信号口连接到ESP32的GPIO14  0°
// int servoPin2 = 18; // 舵机2的信号口连接到ESP32的GPIO18  180°
Inductive::Inductive(int trigPin, int echoPin, int servoPin, int servoPin2)
{
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    this->servoPin = servoPin;
    this->servoPin2 = servoPin2;
}

void Inductive::rotateServo_1(int targetAngle)
{
    int pulseWidth = map(targetAngle, 0, 180, 500, 2400);
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(servoPin, LOW);
    delay(20);
}
void Inductive::rotateServo_2(int targetAngle)
{
    int pulseWidth = map(targetAngle, 0, 180, 500, 2400);
    digitalWrite(servoPin2, HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(servoPin2, LOW);
    delay(20);
}

void Inductive::setup()
{
    Serial.begin(115200); // 初始化串行通信，波特率设置为115200
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(servoPin, OUTPUT);
    pinMode(servoPin2, OUTPUT);
}

void Inductive::loop()
{
    long duration;
    int distance;

    // 发送超声波脉冲
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // 计算回波时间
    duration = pulseIn(echoPin, HIGH);

    // 将回波时间转换为距离（单位：厘米）
    distance = duration * 0.034 / 2;

    // 打印距离到串行监视器
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance < 40) // 距离小于阈值，开盖
    {
        // 控制开盖
        rotateServo_1(60);
        rotateServo_2(120);
        delay(5000);     // 暂停五秒
        // 控制关盖
        rotateServo_1(0);
        rotateServo_2(180);
    }

    delay(1000); // 每隔1秒进行一次测量
}