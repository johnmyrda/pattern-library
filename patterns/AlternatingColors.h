#ifndef ALTERNATINGCOLORS_H
#define ALTERNATINGCOLORS_H

#include "Pattern.h"

class AlternatingColors: public Pattern{

public:

  AlternatingColors(){
    length = random(4,10);
    randomize();
  }

  AlternatingColors(const uint8_t length): length(length){
    randomize();
  }

  AlternatingColors(CRGB color1, CRGB color2, const uint8_t length): color1(color1), color2(color2), length(length){}

  void call(LedArray leds, uint16_t frame){
    if(frame % 25 == 0){
      leds.shift_leds(length);
      if(frame % 2){
        fill_solid(leds.leds, length, color1);
      } else {
        fill_solid(leds.leds, length, color2);
      }
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
