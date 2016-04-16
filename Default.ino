#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, 2, NEO_GRB);

int n;

void setup() {
  strip.begin();
  strip.setBrightness(50);
  strip.show();
  n=0;
}

void loop() {
  if (n<5){
    strip.setPixelColor(0 ,0,0,255);
    strip.show();
    delay(300);
    strip.setPixelColor(0 ,0,0,0);
    strip.show();
    delay(300);
    n++;
  }
 }
