#ifndef LedDemo_H
#define LedDemo_H

class LedDemo
{
public:
    int LedPin; // 你的LED连接到ESP32的GPIO引脚，可以根据需要修改
    LedDemo(int LedPin);
    void setup();
    void loop();
};

#endif
