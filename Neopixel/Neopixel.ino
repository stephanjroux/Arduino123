#include <Adafruit_NeoPixel.h>    // Load Adafruit NeoPixel Library

//----------------name--------------------(pixels,PIN,Type)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, 2, NEO_GRB);

void setup() {
  strip.begin();
  strip.setBrightness(50);
  strip.show();
}

void loop() {
    // ----------------(#, G,R,B) - Green, Red, Blue
    strip.setPixelColor(0, 0,0,255);
    strip.setPixelColor(1, 0,0,255);
    strip.setPixelColor(2, 0,0,255);
    strip.setPixelColor(3, 0,0,255);
    strip.show();
    delay(1000);
    strip.setPixelColor(0,0,0,0);
    strip.setPixelColor(1,0,0,0);
    strip.setPixelColor(2,0,0,0);
    strip.setPixelColor(3,0,0,0);
    strip.show();
    delay(1000);
}
