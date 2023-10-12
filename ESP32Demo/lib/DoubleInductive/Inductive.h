// my_module.h
#ifndef Inductive_H
#define Inductive_H

class Inductive
{
public:
    int trigPin; // 超声波传感器的Trig引脚 .h定义
    int echoPin; // 超声波传感器的Echo引脚
    int servoPin; // 舵机的信号口
    int servoPin2; // 2号舵机的信号口
    void setup();
    void loop();
    void rotateServo_1(int targetAngle);
    void rotateServo_2(int targetAngle);
    Inductive(int trigPin, int echoPin, int servoPin, int servoPin2);
};

#endif
