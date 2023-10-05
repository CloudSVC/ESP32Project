#ifndef SR04_H
#define SR04_H

class SR04
{
public:
    int trigPin; // 超声波传感器的Trig引脚
    int echoPin; // 超声波传感器的Echo引脚
    int duration; // 双精度浮点型数据
    int distance; // 双精度浮点型数据
    SR04(int trigPin, int echoPin);
    void setup();
    void loop();
    int calculateDistance();
};

#endif
