#ifndef PATTERN_H
#define PATTERN_H

#include "../Leds.h"

class Pattern{

public:

  virtual void call(LedArray _leds, uint16_t frame) = 0;

  virtual void randomize(){};

};


#endif
