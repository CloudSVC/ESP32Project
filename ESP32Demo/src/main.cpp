#include <Arduino.h>

const int trigPin = 2; // 超声波传感器的Trig引脚连接到ESP32的GPIO2
const int echoPin = 4; // 超声波传感器的Echo引脚连接到ESP32的GPIO4
int servoPin = 14;

void rotateServo(int targetAngle)
{
  int pulseWidth = map(targetAngle, 0, 180, 500, 2400);
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(servoPin, LOW);
  delay(20);
}

void setup()
{
  Serial.begin(115200); // 初始化串行通信，波特率设置为115200
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(servoPin, OUTPUT);
}

void loop()
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

  if (distance < 20) // 距离小于阈值，开盖
  {
    rotateServo(90); // 控制开盖
    delay(5000); // 暂停五秒
    rotateServo(0); // 控制关盖
  }

  delay(1000); // 每隔1秒进行一次测量
}
