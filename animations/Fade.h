#ifndef FADE_H
#define FADE_H

#include "Animation.h"
#include "pixeltypes.h"

class Fade: public Animation{

public:

  Fade(CRGB* leds, int num_leds, int num_frames)
             : Animation(leds, num_leds, num_frames) {
               randomize();
             }

  Fade(CRGB* leds, int num_leds, int num_frames, CRGB new_color)
             : Animation(leds, num_leds, num_frames) {
               color_ = new_color;
             }

  void generateNextFrame(){
    CRGB faded = color_;
    uint8_t dim_value = 255 - (frame_ + 1)*255/num_frames_;
    faded.nscale8(dim_value);
    fill_solid(leds_.head, leds_.length, faded);
  }

  void randomize(){
    color_ = Pattern::random_color();
  }

protected:
  CRGB color_;

};

#endif