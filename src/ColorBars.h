#ifndef COLORBARS_H
#define COLORBARS_H

#include <Pattern.h>

class ColorBars: public Pattern{

public:

  ColorBars(CRGB color, uint8_t length);

  void call();

protected:

    uint16_t pattern_duration;


};


#endif
