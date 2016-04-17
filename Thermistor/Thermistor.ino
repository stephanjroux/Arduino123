#include <Adafruit_NeoPixel.h>    // Load Adafruit NeoPixel Library

Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, 2, NEO_GRB);   // Set up NeoPixel

int tmpnum, basenum, numdif, n;    // Initialize variable

void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.setBrightness(50);
  strip.show();
  basenum = analogRead(0);
  tmpnum = 0;
}

void loop() {
  tmpnum = analogRead(0);
  if (tmpnum < basenum) {
     basenum = tmpnum;
     numdif = 0;
    }
  else{
    numdif = tmpnum - basenum;  
    }
  
  for (n=0;n<4;n++){
    strip.setPixelColor(n,0,0,0);
    }
  if (numdif > 10) strip.setPixelColor(0,0,0,255);
  if (numdif > 30) strip.setPixelColor(1,0,0,255);
  if (numdif > 50) strip.setPixelColor(2,0,0,255);
  if (numdif > 80) strip.setPixelColor(3,0,0,255);

  strip.show();

  Serial.print(basenum);
  Serial.print("   ");
  Serial.print(numdif);
  Serial.print("   ");
  Serial.println(tmpnum);
  delay(10);
}
