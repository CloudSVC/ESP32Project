#ifndef Radar_H
#define Radar_H
#include <SG90.h>
#include <SR04.h>

class Radar
{
public:
    int servoPin; // 舵机的信号口连接到ESP32的GPIO14
    int trigPin;  //
    int echoPin;  //
    Radar(int servoPin, int trigPin, int echoPin);
    void setup();
    void loop();
    SG90 SG90_main;
    SR04 SR04_main;
};

#endif
