#ifndef LARSONSCANNER_H
#define LARSONSCANNER_H

#include <Pattern.h>

class LarsonScanner: public Pattern{

public:

  LarsonScanner();

  void call();

protected:

    uint16_t pattern_duration;


};


#endif
