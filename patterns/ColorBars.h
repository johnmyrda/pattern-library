#ifndef COLORBARS_H
#define COLORBARS_H

#include "Pattern.h"
#include "Util.h"

class ColorBars: public Pattern{

public:

  ColorBars(CRGB color, uint8_t length): color(color), length(length){}

  void call(LedArray leds, uint16_t frame){
      if(frame % (length*2) < length){
        leds.push(color);
      } else {
        leds.push(complementary_color(color));
      }
  }

protected:

  CRGB color;
  uint8_t length;

};

#endif
