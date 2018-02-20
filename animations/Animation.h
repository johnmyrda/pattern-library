#ifndef ANIMATION_H
#define ANIMATION_H

#include <FastLED.h>
#include "patterns/Pattern.h"

class Animation{
  public:
    Animation(CRGB* leds, int num_leds, int num_frames)
             : num_frames_(num_frames), frame_(0) {
                   leds_ = LedArray(leds, num_leds);
               };

    bool nextFrame() {
      generateNextFrame();
      frame_++;
      return (frame_ < num_frames_);
    };

    void reset(int num_frames){
        num_frames_ = num_frames_;
        restart();
    }

    void restart(){
        frame_ = 0;
    }

    virtual void generateNextFrame() = 0;

  protected:
    LedArray leds_;
    int num_frames_, frame_;
};

#endif  // ANIMATION_H