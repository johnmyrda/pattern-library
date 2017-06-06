#include "PatternController.h"

PatternController::PatternController(CRGB * leds, uint16_t length){
  _leds = LedArray(leds, length);
}

//FPS = 1000/frame_interval
void PatternController::setFPS(uint8_t fps){
  frame_interval = 1000/fps;
}
