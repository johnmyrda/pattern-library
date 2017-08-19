#ifndef PATTERN_H
#define PATTERN_H

#include "../Leds.h"

class Pattern{

public:

  uint16_t frame_interval = 0;

  virtual void call(LedArray _leds, uint16_t frame) = 0;

  virtual void randomize(){};

  //FPS = 1000/frame_interval
  void set_fps(uint8_t fps){
    if(fps == 0){
      frame_interval = 0; // 0 means use the PatternController frame_interval
    } else{
      frame_interval = 1000/fps;
    }
  }

};


#endif
