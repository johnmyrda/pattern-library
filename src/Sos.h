#ifndef SOS_H
#define SOS_H

#include <Pattern.h>

class Sos: public Pattern{

public:

  Sos() {}

  void call(LedArray leds, uint16_t frame){
    constexpr uint8_t num_intervals = 34;
    constexpr bool SOS[num_intervals] =    {1, 0, 1, 0, 1,  0, 0, 0,    1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1,   0, 0, 0,    1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0};
    int interval_time = 300; //in milliseconds
    long mod_time = interval_time * num_intervals;
    byte current_time_unit = (millis() % mod_time) / interval_time;
    //SOS in binary -             S -s_s_s     space-___ O-l_l_l                  space-___ S -s_s_s
    if (SOS[current_time_unit]) {
      fill_solid(leds.head, leds.length, CRGB::Red);
    } else {
      fill_solid(leds.head, leds.length, CRGB::Black);
    }
  }

};


#endif
