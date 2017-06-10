#ifndef LARSONSCANNER_H
#define LARSONSCANNER_H

#include "Pattern.h"
#include "Util.h"

class LarsonScanner: public Pattern{

public:

  LarsonScanner(){};

  void call(LedArray leds, uint16_t frame){
    //frame_interval = 30;
    //elapsed / frame_interval;
    // 0 == forwards, 1 = backwards
    int direction = (frame / leds.length) % 2;
    if(direction == 0){
      CRGB next_color = CRGB::Black;
      if(frame > leds.length){
        //not the first time
        next_color = complementary_color(*leds.tail);
      } else if(frame == 0) {
        //The first led the first time
        next_color = random_color();
      } else {
        //later frames the first time
        next_color = leds.get(1);
      }
    } else {
      CRGB next_color = complementary_color(*leds.head);
      leds.push_back(next_color);
    }
  }

};


#endif
