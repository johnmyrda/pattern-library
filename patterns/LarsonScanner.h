#ifndef LARSONSCANNER_H
#define LARSONSCANNER_H

#include "Pattern.h"
#include "Util.h"

class LarsonScanner: public Pattern{

public:

  //LarsonScanner(){};

  LarsonScanner(CRGB color1, CRGB color2) : color1(color1), color2(color2){}

  void call(LedArray leds, uint16_t frame){
    // 0 == forwards, 1 = backwards
    int direction = (frame / leds.length) % 2;
    if(direction == 0){
      leds.push(color1);
    } else {
      leds.push_back(color2);
    }
  }

  void randomize(){
    fillRandomContrastingColors(color1, color2);
  }

protected:
  CRGB color1;
  CRGB color2;

};



#endif
