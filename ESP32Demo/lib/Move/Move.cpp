#include <Arduino.h>
#include "Move.h"

// 安装方式如下
// 1   2
//  驱动
// 3   4
// pin口奇数为负极， IN奇数为正极
// 电机1
#define IN1 12 // 定义IN1为Digital Pin 12
#define IN2 13 // 定义IN2为Digital Pin 13
// 电机2
#define IN3 26 // 定义IN3为Digital Pin 26
#define IN4 27 // 定义IN4为Digital Pin 27
// 电机3
#define IN5 32 // 定义IN5为Digital Pin 32
#define IN6 33 // 定义IN6为Digital Pin 33 
// 电机4
#define IN7 34 // 定义IN7为Digital Pin 34
#define IN8 35 // 定义IN8为Digital Pin 35

Move::Move()
{
}

void Move::setup()
{
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(IN5, OUTPUT);
    pinMode(IN6, OUTPUT);
    pinMode(IN7, OUTPUT);
    pinMode(IN8, OUTPUT);
}

void Move::foreward(int PIN1, int PIN2)
{
    // 电机正转
    digitalWrite(PIN1, HIGH); // 设置IN1为高电平
    digitalWrite(PIN2, LOW);  // 设置IN2为低电平
}

void Move::reversal(int PIN1, int PIN2)
{
    // 电机反转
    digitalWrite(PIN1, LOW);  // 设置IN1为低电平
    digitalWrite(PIN2, HIGH); // 设置IN2为高电平
}

void Move::stop(int PIN1, int PIN2)
{
    // 停止电机
    digitalWrite(IN1, LOW); // 设置IN1为低电平
    digitalWrite(IN2, LOW); // 设置IN2为低电平
}

void Move::up()
{
    foreward(IN1, IN2); // 电机1
    foreward(IN3, IN4); // 电机2
    foreward(IN5, IN6); // 电机3
    foreward(IN7, IN8); // 电机4
}

void Move::down()
{
    stop(IN1, IN2); // 电机1
    stop(IN3, IN4); // 电机2
    stop(IN5, IN6); // 电机3
    stop(IN7, IN8); // 电机4
}

void Move::left()
{
    reversal(IN1, IN2); // 电机1
    foreward(IN3, IN4); // 电机2
    foreward(IN5, IN6); // 电机3
    reversal(IN7, IN8); // 电机4
}

void Move::right()
{
    foreward(IN1, IN2); // 电机1
    reversal(IN3, IN4); // 电机2
    reversal(IN5, IN6); // 电机3
    foreward(IN7, IN8); // 电机4
}