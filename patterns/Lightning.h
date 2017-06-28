#ifndef LIGHTNING_H
#define LIGHTNING_H

#include "Pattern.h"
#include "Util.h"

class Lightning: public Pattern{

public:

  Lightning(CRGB color, const uint8_t length): color(color), length(length){}

  void call(LedArray leds, uint16_t frame){
      uint8_t segments = leds.length/length;
      for(int i = 0; i < segments; i++){
        apply_lightning(&leds.leds[i*length], length);
      }
      //add some stuff for final non-uniform segment, if any
  }

  void apply_lightning(CRGB * leds, uint8_t segment_length){
    uint8_t random_strike = random8();
    const uint8_t strike_frequency = 5;
    time_since_last_strike = millis() - time_of_last_strike;
    if(random_strike < strike_frequency && time_since_last_strike > min_time_between_strikes){
      time_since_last_strike = 0;
      time_of_last_strike = millis();
      min_time_between_strikes = random16(500, 3000);
      fill_solid(leds, segment_length, color);
    } else {
      fadeToBlackBy(leds, segment_length, 8);
    }
  }

  void randomize(){
    uint8_t rand_int = random(8);
    if(rand_int == 0){
      color = CRGB::White;
    } else {
      color = random_color();
    }
  }

protected:

  CRGB color;
  uint8_t length;
  uint16_t time_since_last_strike = 1000;
  uint16_t time_of_last_strike = 0;
  uint16_t min_time_between_strikes = 800;

};

#endif
