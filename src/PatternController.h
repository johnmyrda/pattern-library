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

 public:
    // Create an instance of the PatternController library
    //I think this is going to need to take in a number of
    // LEDS and a CRGB pointer or something
    PatternController(CRGB * leds, uint16_t length);

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

    void addRainbow();

    //util functions
    static CRGB random_color();
    static CRGB complementary_color(CRGB color);
    //static void shift_leds(CRGB * leds, uint16_t nLeds, int16_t shift_amount);

 protected:
    void rainbow_pattern(uint8_t rainbow_density);

    void usa_pattern();

    void generic_pattern(CRGB * pattern, uint8_t pattern_length);

    void larson_scanner_wipe();

    void complementary_color_bars(CRGB color, uint8_t length);

    void chasing_random_colors(uint8_t spacing);

    unsigned long previous_millis;

    //frame interval in milliseconds
    uint16_t frame_interval;
    uint16_t pattern_duration;

private:
  void shift_leds(int16_t shift_amount);
  void push(CRGB color);


};

#endif
