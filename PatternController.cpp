#include "PatternController.h"

PatternController::PatternController(CRGB * leds, uint16_t length){
  _leds = LedArray(leds, length);
}

//FPS = 1000/frame_interval
void PatternController::set_fps(uint8_t fps){
  if(fps == 0){
    frame_interval = DEFAULT_FRAME_INTERVAL; // avoiding divide by zero
  } else{
    frame_interval = 1000/fps;
  }
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

  if(cycle && (now - pattern_start_ts) > pattern_duration){
    Serial.println(F("next_pattern"));
    next_pattern();
  }

  uint16_t cur_frame_interval;
  if(patterns[current_pattern]->frame_interval != 0){
    cur_frame_interval = patterns[current_pattern]->frame_interval;
  } else {
    cur_frame_interval = frame_interval;
  }

  uint32_t elapsed = now - frame_ts;
  if(elapsed > cur_frame_interval){ //&& elapsed < frame_interval*2
    frame = frame+1;
    frame_ts = frame_ts + cur_frame_interval;//*num_frames. num_frames = elapsed/frame_interval
    patterns[current_pattern]->call(_leds, frame);
  }
}

void PatternController::select_pattern(uint8_t pattern_index){
  current_pattern = pattern_index % pattern_array_size; // ensures all possible inputs are valid
  pattern_start_ts = now; // should this be last pattern start + pattern duration instead?
  frame_ts = pattern_start_ts;
  frame = 0;
  if(randomize){
    Serial.print("Randomizing pattern #");
    Serial.println(current_pattern);
    patterns[current_pattern]->randomize();
  }
}

void PatternController::next_pattern(){
  select_pattern(current_pattern + 1);
}
