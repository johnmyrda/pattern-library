#ifndef COLORBARS_H
#define COLORBARS_H

#include "Pattern.h"
#include "Util.h"

class ColorBars: public Pattern{

public:

  ColorBars(){
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
    length = random(4,10);
  }

protected:

  CRGB color1;
  CRGB color2;
  uint8_t length;

};

#endif
