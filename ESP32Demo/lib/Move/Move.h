#ifndef Move_H
#define Move_H

class Move
{
public:
    int PIN1;
    int PIN2;
    Move();
    void foreward(int PIN1, int PIN2);
    void reversal(int PIN1, int PIN2);
    void stop(int PIN1, int PIN2);
    void setup();
    void up();
    void down();
    void left();
    void right();
};

#endif
