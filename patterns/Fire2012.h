// The MIT License (MIT)
//
// Copyright (c) 2013 FastLED
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
// https://github.com/FastLED/FastLED/tree/master/examples/Fire2012
// Fire2012 by Mark Kriegsman, July 2012
// as part of "Five Elements" shown here: http://youtu.be/knWiGsmgycY
////
// This basic one-dimensional 'fire' simulation works roughly as follows:
// There's a underlying array of 'heat' cells, that model the temperature
// at each point along the line.  Every cycle through the simulation,
// four steps are performed:
//  1) All cells cool down a little bit, losing heat to the air
//  2) The heat from each cell drifts 'up' and diffuses a little
//  3) Sometimes randomly new 'sparks' of heat are added at the bottom
//  4) The heat from each cell is rendered as a color into the leds array
//     The heat-to-color mapping uses a black-body radiation approximation.
//
// Temperature is in arbitrary units from 0 (cold black) to 255 (white hot).
//
// This simulation scales it self a bit depending on leds.length; it should look
// "OK" on anywhere from 20 to 100 LEDs without too much tweaking.
//
// I recommend running this simulation at anywhere from 30-100 frames per second,
// meaning an interframe delay of about 10-35 milliseconds.
//
// Looks best on a high-density LED setup (60+ pixels/meter).
//
//
// There are two main parameters you can play with to control the look and
// feel of your fire: COOLING (used in step 1 above), and SPARKING (used
// in step 3 above).
//
// COOLING: How much does the air cool as it rises?
// Less cooling = taller flames.  More cooling = shorter flames.
// Default 50, suggested range 20-100
//#define COOLING  55

// SPARKING: What chance (out of 255) is there that a new spark will be lit?
// Higher chance = more roaring fire.  Lower chance = more flickery fire.
// Default 120, suggested range 50-200.
//#define SPARKING 120


#ifndef FIRE2012_H
#define FIRE2012_H

#include "Pattern.h"

class Fire2012: public Pattern{

public:

  Fire2012(byte * heat, uint16_t length): heat(heat), length(length){}

  Fire2012(byte * heat, uint16_t length, uint8_t cooling, uint8_t sparking) : heat(heat), length(length), cooling(cooling), sparking(sparking){}

  void call(LedArray leds, uint16_t frame){
      // Array of temperature readings at each simulation cell

      // Step 1.  Cool down every cell a little
        for( uint16_t i = 0; i < length; i++) {
          heat[i] = qsub8( heat[i],  random8(0, ((cooling * 10) / length) + 2));
        }

        // Step 2.  Heat from each cell drifts 'up' and diffuses a little
        for( int k= length - 1; k >= 2; k--) {
          heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
        }

        // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
        if( random8() < sparking ) {
          int y = random8(7);
          heat[y] = qadd8( heat[y], random8(160,255) );
        }

        // Step 4.  Map from heat cells to LED colors
        for( uint16_t j = 0; j < length; j++) {
          CRGB color = HeatColor( heat[j]);
          int pixelnumber;
          if( reverse_direction ) {
            pixelnumber = (leds.length-1) - j;
          } else {
            pixelnumber = j;
          }
          leds.leds[pixelnumber] = color;
        }
  }

  void randomize(){
    // COOLING: How much does the air cool as it rises?
    // Less cooling = taller flames.  More cooling = shorter flames.
    // Default 50, suggested range 20-100
    cooling = random8(20,100);

    // SPARKING: What chance (out of 255) is there that a new spark will be lit?
    // Higher chance = more roaring fire.  Lower chance = more flickery fire.
    // Default 120, suggested range 50-200.
    sparking = random8(50, 200);
  }

protected:
  byte * heat;
  uint16_t length;

public:
  uint8_t cooling = 50;
  uint8_t sparking = 120;
  bool reverse_direction = false;

};


#endif
