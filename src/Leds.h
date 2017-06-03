#ifndef _LEDS_H
#define _LEDS_H

#include <FastLED.h>

// the definition of the leds class.
struct LedArray
{
  uint16_t length;
  uint8_t shift_direction;
  CRGB * leds;
  CRGB * head;
  CRGB * tail;
  bool reverse;

  LedArray (){}

  LedArray (CRGB * new_leds, uint16_t new_length) {
    leds = new_leds;
    length = new_length;
    set_reverse(false);
  }

  CRGB get(uint16_t index){
    if(!reverse){
      return leds[index];
    } else {
      return leds[length - index - 1];
    }
  }

  void push (CRGB color) {
    shift_leds(shift_direction);
    *head = color;
  }

  void push_back(CRGB color){
    shift_leds(shift_direction * -1);
    *tail = color;
  }

  void shift_leds(int16_t amount){
    CRGB temp[length];
    for (uint16_t x = 0; x < (length - amount); x++) {
      temp[x + amount] = leds[x];
    }
    memcpy(leds, temp, sizeof(CRGB) * length);
  }

  void set_reverse(bool is_reverse){
    reverse = is_reverse;
    if(!is_reverse){
      head = &leds[0];
      tail = &leds[length - 1];
      shift_direction = 1;
    } else {
      head = &leds[length -1];
      tail = &leds[0];
      shift_direction = -1;
    }
  }

};
#endif // _LEDS_H
