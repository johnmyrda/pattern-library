#ifndef GRADIENT_H
#define GRADIENT_H

#include <Pattern.h>

class Gradient: public Pattern{

public:

  Gradient(){}

  void call(LedArray leds, uint16_t frame){
    for (uint16_t i = 0; i < leds.length; i++)
    {
      uint8_t x = frame - 8 * i;
      leds.head[i] = CRGB(x, 255 - x, x);
    }
  }

protected:
  uint8_t rainbow_density;

};


#endif
