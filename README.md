# Led Pattern Library
Led strip patterns for use with the popular [FastLED](https://github.com/FastLED/FastLED) Library.

## Getting Started

Clone the repo into your Arduino library path.

If you're using PlatformIO, make sure the library path is specified in your platformio.ini file, e.g.

```
[platformio]
lib_extra_dirs = ${env.HOME}/Arduino
```
## Usage

Include the FastLED library, PatternController.h, and header files for any of the patterns you want to use.

```
#include "FastLED.h"

#include "PatternController.h"

#include "patterns/ColorBars.h"
#include "patterns/Gradient.h"
```

Create a PatternController object using the constructor. Pass in the CRGB array used with FastLED and the number of LEDs for that array.

```
CRGB leds[NUM_LEDS];
PatternController pattern_master = PatternController(leds, NUM_LEDS);
```

Create pattern objects and register them with the PatternController object.

```
ColorBars cb = ColorBars(CRGB::Blue, CRGB::Black, 24);
Gradient grad = Gradient();

void setup(){
  //Other setup, such as FastLED 
  ...
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalSMD5050);
  ...
  //PatternController setup
  pattern_master.add(&cb);
  pattern_master.add(&grad);
}
```
and in the main loop, call the .show() method of the PatternController before FastLED.show()

```
void loop(){
  pattern_master.show();
  FastLED.show();
}
```


For a usage example, see [multi-beacon.cpp](https://github.com/johnmyrda/multi-beacon/blob/master/src/multi-beacon.cpp) from my [LED Beacon](https://github.com/johnmyrda/multi-beacon) project.
