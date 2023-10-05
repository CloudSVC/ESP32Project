#include <Arduino.h>
#include <../lib/Radar/Radar.h>

Radar Radar_main(14, 2, 4);

void setup()
{
    Radar_main.setup();
}
void loop()
{
    Radar_main.loop();
}