#include "PatternController.h"

PatternController::PatternController(CRGB * leds, uint16_t length){
  _leds = LedArray(leds, length);
}

//FPS = 1000/frame_interval
void PatternController::set_fps(uint8_t fps){
  frame_interval = 1000/fps;
}

void PatternController::add(Pattern * pattern){
  if(pattern_array_size < PATTERN_ARRAY_MAX_SIZE){
    patterns[pattern_array_size] = pattern;
    pattern_array_size++;
    Serial.println("Pattern Added");
  }
  //Debug message if full?
}

void PatternController::clear(){
  for(int i = 0; i < PATTERN_ARRAY_MAX_SIZE; i++){
    patterns[i] = NULL;
  }
  current_pattern = 0;
  pattern_array_size = 0;
}

void PatternController::show(){
  now = millis();

  if((now - pattern_start_ts) > pattern_duration && cycle){
    Serial.println(F("next_pattern"));
    next_pattern();
  }
  uint16_t new_frame = (now - pattern_start_ts) / frame_interval;
  if(new_frame != frame){
    frame = new_frame;
    patterns[current_pattern]->call(_leds, frame);
  }
}

void PatternController::next_pattern(){
  current_pattern++;
  if(current_pattern >= pattern_array_size){
    current_pattern = 0;
  }
  pattern_start_ts = now;
  Serial.print(F("Now on pattern #"));
  Serial.println(current_pattern);

}
