#ifndef PATTERN_H
#define PATTERN_H

#include <Leds.h>

class Pattern{

public:

  Pattern rainbow(uint8_t rainbow_density);

  Pattern usa();

  Pattern generic_pattern(CRGB * pattern, uint8_t pattern_length);

  Pattern larson_scanner_wipe();

  Pattern complementary_color_bars(CRGB color, uint8_t length);

  Pattern chasing_random_colors(uint8_t spacing);

  Pattern * setDuration(uint16_t duration);

  void call();

protected:

    uint16_t pattern_duration;


};


#endif
