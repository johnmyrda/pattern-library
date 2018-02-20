#ifndef COLORBARS_H
#define COLORBARS_H

#include "Pattern.h"

class ColorBars: public Pattern{

public:

  ColorBars(){
    length = random(4,10);
    randomize();
  }

  ColorBars(const uint8_t length): length(length){
    randomize();
  }

  ColorBars(CRGB color1, CRGB color2, const uint8_t length): color1(color1), color2(color2), length(length){}

  void call(LedArray leds, uint16_t frame){
      if(frame % (length*2) < length){
        leds.push(color1);
      } else {
        leds.push(color2);
      }
  }

  void randomize(){
    fillRandomContrastingColors(color1, color2);

  }

protected:

  CRGB color1;
  CRGB color2;
  uint8_t length;

};

#endif
