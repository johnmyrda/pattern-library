#ifndef RAINBOW_H
#define RAINBOW_H

#include <Pattern.h>

class Rainbow: public Pattern{

public:

  Rainbow(uint8_t rainbow_density);

  void call();

protected:

    uint16_t pattern_duration;


};


#endif
