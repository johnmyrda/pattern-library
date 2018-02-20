#include "AnimationController.h"

// Create an instance of the AnimationController library
AnimationController::AnimationController(){};

//FPS = 1000/frame_interval
void AnimationController::set_fps(uint8_t fps){
  if(fps == 0){
    frame_interval = DEFAULT_FRAME_INTERVAL; // avoiding divide by zero
  } else{
    frame_interval = 1000/fps;
  }
}

void AnimationController::set(Animation * animation, uint8_t slot_index){
  if(slot_index < ANIMATION_SLOTS){
    animations[slot_index] = animation;
    //Serial.println("Pattern Added");
  }
  //Debug message if out of bounds?
}

void AnimationController::clear(){
  for(int i = 0; i < ANIMATION_SLOTS; i++){
    animations[i] = NULL;
  }
}

void AnimationController::show(){
  unsigned long now = millis();
  
  for(int i = 0; i < ANIMATION_SLOTS; i++){
      if(active[i]){
        if(now - last_frame_start_times[i] > frame_interval){
            last_frame_start_times[i] = now;
            active[i] = animations[i]->nextFrame();
        }
      }
  }
}

void AnimationController::fire_animation(uint8_t slot_index){
  last_frame_start_times[slot_index] = millis();
  active[slot_index] = true;
}
