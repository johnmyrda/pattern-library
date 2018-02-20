#ifndef BEACONSCANNER_H
#define BEACONSCANNER_H

#include "Pattern.h"
#include "BeaconUtil.h"

class BeaconScanner: public Pattern{

public:

  BeaconScanner(){
    randomize();
  };

  BeaconScanner(const CRGB color) : color(color){}

  void call(LedArray leds, uint16_t frame){
    int16_t periodic_index = PERIOD/2 - ((frame + PERIOD/2) % (PERIOD));
    uint8_t abs_periodic_index = abs(periodic_index);
    for(uint16_t i = 0; i < leds.length; i++){
      uint8_t stick_index = get_stick_index(i);
      if(stick_index == abs_periodic_index){
        leds.leds[i] = color;
      } else {
        leds.leds[i] = CRGB::Black;
      }
    }
  }

  void randomize(){
    color = random_color();
  }

protected:
  CRGB color;
  static constexpr uint8_t PERIOD = (LEDS_PER_STICK - 1) * 2;
};



#endif
