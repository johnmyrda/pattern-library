#ifndef GENERIC_H
#define GENERIC_H

#include "Pattern.h"

class Generic: public Pattern{

public:

  Generic(const CRGB * pattern, const int8_t pattern_length) :
    pattern(pattern), pattern_length(pattern_length){}

  void call(LedArray leds, uint16_t frame){
    int pattern_index = frame % pattern_length;
    leds.push(pattern[pattern_index]);
  }

protected:

  const CRGB * pattern;
  uint8_t pattern_length;

};


#endif
