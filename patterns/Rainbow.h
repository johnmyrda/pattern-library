#ifndef RAINBOW_H
#define RAINBOW_H

#include "Pattern.h"

class Rainbow: public Pattern{

public:

  Rainbow(int8_t rainbow_density) : rainbow_density(rainbow_density){}

  void call(LedArray leds, uint16_t frame){
    leds.push(CRGB::Black);
    if(rainbow_density >-2 && rainbow_density <2){
      fill_rainbow(leds.head, 1, frame);
    } else if(rainbow_density>1){
      fill_rainbow(leds.head, 1, frame * rainbow_density);
    } else {
      fill_rainbow(leds.head, 1, (frame / -rainbow_density));
    }

  }

protected:
  int8_t rainbow_density;

};


#endif
