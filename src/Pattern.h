#ifndef PATTERN_H
#define PATTERN_H

#include <Leds.h>

class Pattern{

public:

  Pattern setDuration(uint16_t pattern_duration);

  void call();

protected:

    uint16_t pattern_duration;


};


#endif
