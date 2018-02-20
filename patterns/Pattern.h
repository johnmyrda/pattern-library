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

  #define SATURATION 255
  #define VALUE 255

  static CRGB random_color(){
    return CHSV(random(255), SATURATION, VALUE);
  }

  static CRGB complementary_color(CRGB color){
    CHSV hsv_color = rgb2hsv_approximate(color);
    hsv_color.hue = hsv_color.hue - 128;
    CRGB rgb_complement;
    hsv2rgb_rainbow( hsv_color, rgb_complement);
    return rgb_complement;
  }

  static void fillRandomContrastingColors(CRGB &c1, CRGB &c2) {
    int h1 = random(255);
    int offset = random(180) - 90;
    int h2 = (h1 + 128 + offset) % 255;

    //LOG("\tRandomContrastingColors generated\th1: %d\th2: %d", h1, h2);
    c1 = CHSV(h1, SATURATION, VALUE);
    c2 = CHSV(h2, SATURATION, VALUE);
  }


};


#endif
