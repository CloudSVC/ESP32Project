#include <Arduino.h>
#include <../lib/Move/Move.h>

Move Move_main;

void setup()
{
  Move_main.setup();
}

void loop()
{
  Move_main.up();
}