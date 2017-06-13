#ifndef BEACONUTIL_H
#define BEACONUTIL_H

#include <FastLED.h>

static constexpr uint8_t LEDS_PER_STICK = 8;
static constexpr uint8_t STICKS_PER_BEACON = 3;
static constexpr uint8_t LEDS_PER_BEACON = (STICKS_PER_BEACON * LEDS_PER_STICK);

uint8_t get_stick_index(uint16_t index){
  uint8_t beacon_index = index % LEDS_PER_BEACON;
  uint8_t stick_index = beacon_index % LEDS_PER_STICK;
  if(beacon_index >= LEDS_PER_STICK && beacon_index < (LEDS_PER_STICK * 2)) {
    stick_index = LEDS_PER_STICK - stick_index - 1;
  }
  return stick_index;
}

#endif
