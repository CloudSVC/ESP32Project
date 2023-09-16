#include <../lib/Inductive/Inductive.h>
// #include <../lib/LedDemo/LedDemo.h>

// 将对应引脚数据发送给类
Inductive inductive_main(2, 4, 14);
// LedDemo ledDemo_main(2);

void setup()
{
    inductive_main.setup();
    // ledDemo_main.setup();
}

void loop()
{
    inductive_main.loop();
    // ledDemo_main.loop();
}