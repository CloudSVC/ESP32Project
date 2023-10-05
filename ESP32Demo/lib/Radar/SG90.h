#ifndef SG90_H
#define SG90_H

class SG90
{
public:
    int servoPin; // 舵机的信号口连接到ESP32的GPIO14
    SG90(int servoPin);
    void rotateServo(int targetAngle);
    void setup();
    void loop();
    void rangeRotate(int maxAngle, int minAngle);
};

#endif
