#ifndef RANDOMCOLORS_H
#define RANDOMCOLORS_H

#include "Pattern.h"

class RandomColors: public Pattern{

public:

  RandomColors(uint8_t spacing) : spacing(spacing){}

  void call(LedArray leds, uint16_t frame){
    uint8_t i = 0;
    while(!leds.get(i) && i < spacing){
      i++;
    }

    //all of the _leds up to spacing were black
    if(i == spacing){
      leds.push(random_color());
    } else {
      leds.push(CRGB::Black);
    }
  }

protected:
  uint8_t spacing;

};


#endif
