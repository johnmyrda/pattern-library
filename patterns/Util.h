#ifndef UTIL_H
#define UTIL_H

#include <FastLED.h>

#define SATURATION 255
#define VALUE 255

CRGB random_color(){
  return CHSV(random(255), SATURATION, VALUE);
}

CRGB complementary_color(CRGB color){
  CHSV hsv_color = rgb2hsv_approximate(color);
  hsv_color.hue = hsv_color.hue - 128;
  CRGB rgb_complement;
  hsv2rgb_rainbow( hsv_color, rgb_complement);
  return rgb_complement;
}

void fillRandomContrastingColors(CRGB &c1, CRGB &c2) {
  int h1 = random(255);
  int offset = random(180) - 90;
  int h2 = (h1 + 128 + offset) % 255;

  //LOG("\tRandomContrastingColors generated\th1: %d\th2: %d", h1, h2);
  c1 = CHSV(h1, SATURATION, VALUE);
  c2 = CHSV(h2, SATURATION, VALUE);
}

#endif
