#ifndef USA_H
#define USA_H

#include "Pattern.h"
#include "Generic.h"



  class Usa: public Pattern{

  static const CRGB usa_pattern[3];

  public:

    Usa(){
        usa_generic = Generic(usa_pattern, 3);
    };

    Usa(uint8_t repeat_length) {
        usa_generic = Generic(usa_pattern, 3, repeat_length);
    }

    void call(LedArray leds, uint16_t frame){
      usa_generic.call(leds, frame);
    }


  protected:
    Generic usa_generic;
  };

  const CRGB Usa::usa_pattern[3] = {CRGB::Red, CRGB::White, CRGB::Blue};

#endif
