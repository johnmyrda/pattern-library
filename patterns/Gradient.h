#ifndef GRADIENT_H
#define GRADIENT_H

#include "Pattern.h"

class Gradient: public Pattern{

public:

  Gradient(){
    randomize();
  }

  Gradient(const CRGB mod_color) : mod(mod_color){};

  void call(LedArray leds, uint16_t frame){
    for (uint16_t i = 0; i < leds.length; i++)
    {
      uint8_t x = 4 * (frame - 2 * i);
      leds.head[i] = CRGB(mod.r - x, mod.g - x, mod.b  - x).nscale8_video(127);
    }
  }

  void randomize(){
    mod = random_color();
  }

protected:
  CRGB mod = random_color();
};


#endif
