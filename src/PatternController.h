#ifndef PatternController_h
#define PatternController_h

#include <inttypes.h>
#include <FastLED.h>
#include <Leds.h>

class PatternController
{
  //need to keep track of time at a class level
  uint16_t _now;
  uint16_t _elapsed;
  uint16_t _frame;
  LedArray _leds;
  //Array<Pattern> patterns;
  uint16_t duration = 30;//seconds
  uint16_t frame_interval = 100; //ms


 public:
    // Create an instance of the PatternController library
    //I think this is going to need to take in a number of
    // LEDS and a CRGB pointer or something
    PatternController(CRGB * leds, uint16_t length);

    //FPS = 1000/frame_interval
    void setFPS(uint8_t fps);

    // run a specific pattern right now
    //not sure yet how this plays with duration
    //void run(Pattern pattern, list of args);

    //add pattern to list of patterns
    //void add(Pattern pattern, list of args);

    //remove all patterns from list of patterns
    void clear();

    //skip the current pattern
    void skip();

    //set whether or not the pattern
    //changes automatically
    void cycle(bool cycle);

    //Analagous to FastLED show
    void show();

 protected:
    unsigned long previous_millis;

};

#endif
