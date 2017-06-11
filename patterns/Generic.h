#ifndef GENERIC_H
#define GENERIC_H

#include "Pattern.h"

class Generic: public Pattern{

public:

  Generic(){}

  Generic(const CRGB * pattern, const int8_t pattern_length) :
    pattern(pattern), pattern_length(pattern_length){}

  Generic(const CRGB * pattern, const int8_t pattern_length, const int8_t repeat_length) :
      pattern(pattern), pattern_length(pattern_length), repeat_length(repeat_length){}

  void call(LedArray leds, uint16_t frame){
    int pattern_index = (frame/repeat_length) % (pattern_length);
    leds.push(pattern[pattern_index]);
  }

protected:

  const CRGB * pattern;
  uint8_t pattern_length;
  uint8_t repeat_length = 1;

};


#endif
