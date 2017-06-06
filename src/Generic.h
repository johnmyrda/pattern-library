#ifndef RAINBOW_H
#define RAINBOW_H

#include <Pattern.h>

class Generic: public Pattern{

public:

  Generic(CRGB * pattern, uint8_t pattern_length);

  void call();

protected:

    uint16_t pattern_duration;


};


#endif
