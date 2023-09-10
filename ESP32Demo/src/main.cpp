
#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;
void setup()
{
    // 蓝牙模块
    Serial.begin(115200);
    SerialBT.begin("nndty"); // 如果没有参数传入则默认是蓝牙名称是: "ESP32"
    // SerialBT.setPin("123456");   // 蓝牙连接的配对码
    Serial.printf("BT initial ok and ready to pair. \r\n");

    // 将小灯引脚设为输出模式
    pinMode(2, OUTPUT);
}

void loop()
{
    // 蓝牙模块
    if (Serial.available())
    {
        SerialBT.write(Serial.read());
    }
    if (SerialBT.available())
    {
        Serial.write(SerialBT.read());
    }
    delay(1);


    // 频闪小灯
    analogWrite(2, 1000); // 点亮LED
    delay(500); // 延时500毫秒
    analogWrite(2, 0); // 关闭LED
    delay(500); // 延时500毫秒
}