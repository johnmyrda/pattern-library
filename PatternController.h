#ifndef PatternController_h
#define PatternController_h

#include "Leds.h"
#include "patterns/Pattern.h"
#include "Arduino.h"
#include <FastLED.h>

#ifndef PATTERN_ARRAY_MAX_SIZE
#define PATTERN_ARRAY_MAX_SIZE 8
#endif

class PatternController
{
  //need to keep track of time at a class level

  LedArray _leds;
  Pattern* patterns[PATTERN_ARRAY_MAX_SIZE];
  uint8_t current_pattern = 0;
  uint8_t pattern_array_size = 0;
  uint32_t now = 0;
  uint32_t pattern_start_ts = 0;


public:
    bool cycle = true;
    bool randomize = true;
    uint32_t pattern_duration = 30000;//ms
    uint16_t frame_interval = 100; //ms
    uint16_t frame = 0;


    // Create an instance of the PatternController library
    PatternController(CRGB * leds, uint16_t length);

    //FPS = 1000/frame_interval
    void set_fps(uint8_t fps);

    // run a specific pattern right now
    //not sure yet how this plays with duration
    //void run(Pattern pattern, list of args);

    //add pattern to list of patterns
    void add(Pattern * pattern);

    //remove all patterns from list of patterns
    void clear();

    //skip the current pattern
    void next_pattern();

    //Analagous to FastLED show
    void show();

 protected:
    unsigned long previous_millis;

};

#endif
