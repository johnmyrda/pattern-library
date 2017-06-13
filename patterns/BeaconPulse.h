#ifndef BEACONPULSE_H
#define BEACONPULSE_H

#include "Pattern.h"
#include "Util.h"
#include "BeaconUtil.h"

class BeaconPulse: public Pattern{

public:

  BeaconPulse(){
    randomize();
  };

  BeaconPulse(const CRGB color) : color(color){}

  void call(LedArray leds, uint16_t frame){
    uint8_t modifier = max_levels / brightness_levels;
    uint8_t cur_brightness = (frame % brightness_levels) * modifier + modifier - 1;

    uint8_t num_beacons = leds.length / LEDS_PER_BEACON;
    uint8_t cur_beacon_number = (frame / brightness_levels) % num_beacons;
    uint8_t prev_beacon_number = (cur_beacon_number + num_beacons - 1) % num_beacons;
    for(uint16_t i = 0; i < leds.length; i++){
      uint8_t beacon_number = i / LEDS_PER_BEACON;
      if(beacon_number == cur_beacon_number){
        leds.leds[i] = color;
        leds.leds[i].subtractFromRGB(255 - cur_brightness);
      } else if(beacon_number == prev_beacon_number){
        leds.leds[i] = color;
        leds.leds[i].subtractFromRGB(cur_brightness);
      } else{
        leds.leds[i] = CRGB::Black;
      }
    }
  }

  // uint16_t calculate_brightness_levels(uint8_t speed){
  //   double log_2_speed = log(double(speed + 1))/log(2.0);
  //   if(log_2_speed < 2.0){
  //     log_2_speed = 2.0;
  //   }
  //   double temp_brightness_levels = 256.0/log_2_speed;
  //   return uint16_t(temp_brightness_levels);
  // }

  void randomize(){
    color = random_color();
    brightness_levels = random(30,150);
  }

protected:
  CRGB color;
  uint16_t brightness_levels = 64;
  static constexpr uint16_t max_levels = 256;
};

#endif
