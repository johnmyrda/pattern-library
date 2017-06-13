#ifndef BEACONPULSE2_H
#define BEACONPULSE2_H

#include "Pattern.h"
#include "Util.h"
#include "BeaconUtil.h"

class BeaconPulse2: public Pattern{

enum Direction {INCREASING, DECREASING};

public:

  BeaconPulse2(){
    randomize();
  };

  BeaconPulse2(const CRGB color) : color(color){}

  void call(LedArray leds, uint16_t frame){
    uint8_t cur_brightness = sin8(frame * speed);
    //uint8_t wavelength = max_levels / speed;
    uint8_t num_beacons = leds.length / LEDS_PER_BEACON;
    if(cur_brightness >= prev_brightness){
      if(direction == DECREASING){
        beacon_number = (beacon_number + 1) % num_beacons;
      }
      direction = INCREASING;
    } else {
      direction = DECREASING;
    }
    prev_brightness = cur_brightness;
    //uint8_t cur_beacon_number = (frame / wavelength) % num_beacons;
    Serial.print("cur_brightness: ");
    Serial.println(cur_brightness);
    for(uint16_t i = 0; i < leds.length; i++){
      uint8_t cur_beacon = i / LEDS_PER_BEACON;
      if((cur_beacon + beacon_number) % 2){
        leds.leds[i] = color;
        leds.leds[i].subtractFromRGB(255 - cur_brightness);
      } else{
        leds.leds[i] = CRGB::Black;
      }
    }
  }

  void randomize(){
    color = random_color();
    //speed = random(1,8);
  }

protected:
  CRGB color;
  Direction direction = INCREASING;
  uint8_t speed = 2;
  uint8_t prev_brightness = 0;
  uint8_t beacon_number = 0;
  static constexpr uint16_t max_levels = 256;


};

#endif
