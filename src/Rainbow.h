#ifndef RAINBOW_H
#define RAINBOW_H

#include <Pattern.h>

class Rainbow: public Pattern{

public:

  Rainbow(uint8_t rainbow_density) : rainbow_density(rainbow_density){}

  void call(LedArray leds, uint16_t frame){
    leds.push(CRGB::Black);
    fill_rainbow(leds.head, 1, frame * rainbow_density);
  }

protected:
  uint8_t rainbow_density;

};


#endif
