#ifndef UTIL_H
#define UTIL_H

#include <FastLED.h>

CRGB random_color(){
  return CHSV(random(255), 255, 255);
}

CRGB complementary_color(CRGB color){
  CHSV hsv_color = rgb2hsv_approximate(color);
  hsv_color.hue = hsv_color.hue - 128;
  CRGB rgb_complement;
  hsv2rgb_rainbow( hsv_color, rgb_complement);
  return rgb_complement;
}

#endif
