#ifndef AnimationController_h
#define AnimationController_h

#include "Leds.h"
#include "animations/Animation.h"
#include "Arduino.h"
#include <FastLED.h>

#ifndef ANIMATION_SLOTS
#define ANIMATION_SLOTS 8
#endif

#define DEFAULT_FRAME_INTERVAL 100

class AnimationController
{
  //need to keep track of time at a class level

  Animation* animations[ANIMATION_SLOTS];
  unsigned long last_frame_start_times[ANIMATION_SLOTS];
  bool active[ANIMATION_SLOTS] = {false};

public:
    uint16_t frame_interval = DEFAULT_FRAME_INTERVAL; //ms

    // Create an instance of the AnimationController library
    AnimationController();

    //FPS = 1000/frame_interval
    void set_fps(uint8_t fps);

    // run a specific pattern right now
    //not sure yet how this plays with duration
    //void run(Pattern pattern, list of args);

    //set animation in slot
    void set(Animation * animation, uint8_t slot_index);

    //clear all animation slots
    void clear();

    //Select pattern by index. Wraps around if pattern index > number of patterns
    void fire_animation(uint8_t slot_index);

    //Analagous to FastLED show
    void show();

 protected:
    unsigned long previous_millis;

};

#endif
