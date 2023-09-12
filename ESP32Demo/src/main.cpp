
#include <Arduino.h>
// #include <BluetoothSerial.h>

// BluetoothSerial SerialBT;
int i;
// 定义引脚
int ledPin = 2;
void setup()
{
    // 蓝牙模块
    // Serial.begin(115200);
    // SerialBT.begin("nndty"); // 如果没有参数传入则默认是蓝牙名称是: "ESP32"   
    // // SerialBT.setPin("123456");   // 蓝牙连接的配对码
    // Serial.printf("BT initial ok and ready to pair. \r\n");

    // 将小灯引脚设为输出模式
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    // 蓝牙模块
    // if (Serial.available())
    // {
    //     SerialBT.write(Serial.read());
    // }
    // if (SerialBT.available())
    // {
    //     Serial.write(SerialBT.read());
    // }
    // delay(1);

    // 频闪小灯
    // analogWrite(ledPin, 1000); // 点亮LED
    // delay(1000); // 延时1000毫秒
    // analogWrite(ledPin, 0); // 关闭LED
    // delay(1000); // 延时1000毫秒

    // 呼吸灯
    for (i = 0; i < 255; i++)
    {
        analogWrite(ledPin, i);
        delay(10);
    }
    delay(1000); // 暂停5秒
    for (i = 255; i >= 0; i--)
    {
        analogWrite(ledPin, i);
        delay(10);
    }
}