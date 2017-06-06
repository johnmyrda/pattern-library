#ifndef USA_H
#define USA_H

#include <Pattern.h>

class Usa: public Pattern{

public:

  Usa();

  void call();

protected:

    uint16_t pattern_duration;

};


#endif
