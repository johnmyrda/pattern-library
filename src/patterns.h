#ifndef Patterns_h
#define Patterns_h

#include <inttypes.h>
// Uncomment the following line for "LOCK-OUT" debounce method
// //#define BOUNCE_LOCK_OUT
//
// // Uncomment the following line for "BOUNCE_WITH_PROMPT_DETECTION" debounce method
// //#define BOUNCE_WITH_PROMPT_DETECTION
//
// #include <inttypes.h>
//
// #ifndef _BV
// #define _BV(n) (1<<(n))
// #endif

class PatternController
{
  //need to keep track of time at a class level
  uint16_t now;
  uint16_t elapsed;
  uint16_t frame;


 public:
    // Create an instance of the PatternController library
    //I think this is going to need to take in a number of
    // LEDS and a CRGB pointer or something
    PatternController();

    //figure out how to use templates to set these on
    //a pattern by pattern basis
    void setFrameInterval(uint16_t interval);

    //FPS = 1000/frame_interval
    void setFPS(uint8_t fps);

    //Global pattern duration - I want to set this
    //on a per-pattern level too
    void setDuration(uint16_t duration);

    // run a specific pattern right now
    //not sure yet how this plays with duration
    void run(Pattern pattern, list of args);

    //add pattern to list of patterns
    void add(Pattern pattern, list of args);

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
    uint16_t interval_millis;
};

#endif
