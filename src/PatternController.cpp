#include "PatternController.h"

PatternController::PatternController(CRGB * leds, uint16_t length){
  _leds = LedArray(leds, length);
}

//figure out how to use templates to set these on
//a pattern by pattern basis
void PatternController::setFrameInterval(uint16_t interval){
  frame_interval = interval;
}

//FPS = 1000/frame_interval
void PatternController::setFPS(uint8_t fps){
  frame_interval = 1000/fps;
}

void PatternController::setDuration(uint16_t duration){
  pattern_duration = duration;
}

void PatternController::rainbow_pattern(uint8_t rainbow_density){
  _leds.push(CRGB::Black);
  fill_rainbow(_leds.head, 1, _frame * rainbow_density);
}

void PatternController::usa_pattern() {
  CRGB usa_pattern[9] = {
    CRGB::Red, CRGB::Red, CRGB::Red,
    CRGB::White, CRGB::White, CRGB::White,
    CRGB::Blue, CRGB::Blue, CRGB::Blue
  };
  generic_pattern(usa_pattern, 9);
}

void PatternController::generic_pattern(CRGB * pattern, uint8_t pattern_length){
  int pattern_index = _frame % pattern_length;
  _leds.push(pattern[pattern_index]);
}

void PatternController::larson_scanner_wipe(){
  frame_interval = 30;
  uint16_t pattern_frame = _elapsed / frame_interval;
  // 0 == forwards, 1 = backwards
  int direction = (pattern_frame / _leds.length) % 2;
  if(direction == 0){
    CRGB next_color = CRGB::Black;
    if(pattern_frame > _leds.length){
      //not the first time
      next_color = complementary_color(*_leds.tail);
    } else if(pattern_frame == 0) {
      //The first led the first time
      next_color = random_color();
    } else {
      //later frames the first time
      next_color = _leds.get(1);
    }
  } else {
    CRGB next_color = complementary_color(*_leds.head);
    _leds.push_back(next_color);
  }
}

CRGB PatternController::random_color(){
  return CHSV(random(255), 255, 255);
}

CRGB PatternController::complementary_color(CRGB color){
  CHSV hsv_color = rgb2hsv_approximate(color);
  hsv_color.hue = hsv_color.hue - 128;
  CRGB rgb_complement;
  hsv2rgb_rainbow( hsv_color, rgb_complement);
  return rgb_complement;
}

void PatternController::complementary_color_bars(CRGB color, uint8_t length){
  if(_frame % (length*2) < length){
    push(color);
  } else {
    push(complementary_color(color));
  }
}

void PatternController::chasing_random_colors(uint8_t spacing) {
  uint8_t i = 0;
  while(!_leds.get(i) && i < spacing){
    i++;
  }

  //all of the _leds up to spacing were black
  if(i == spacing){
    _leds.push(random_color());
  } else {
    _leds.push(CRGB::Black);
  }
}
