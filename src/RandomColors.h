#ifndef RANDOMCOLORS_H
#define RANDOMCOLORS_H

#include <Pattern.h>

class RandomColors: public Pattern{

public:

  RandomColors(uint8_t spacing);

  void call();

protected:

    uint16_t pattern_duration;


};


#endif
