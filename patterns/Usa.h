#ifndef USA_H
#define USA_H

#include "Pattern.h"
#include "Generic.h"

static const CRGB usa_pattern[9] = {
    CRGB::Red, CRGB::Red, CRGB::Red,
    CRGB::White, CRGB::White, CRGB::White,
    CRGB::Blue, CRGB::Blue, CRGB::Blue
  };

class Usa: public Pattern{

public:

  Usa(){};

  void call(LedArray leds, uint16_t frame){
    usa_generic.call(leds, frame);
  }


protected:

  Generic usa_generic = Generic(usa_pattern, 9);

};

#endif
