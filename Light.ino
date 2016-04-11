#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, 2, NEO_GRB);

int maxnum,tmpnum, basenum, numdif, n , tic;

void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.setBrightness(50);
  strip.show();
  basenum = analogRead(1);
  maxnum = 0;
  tmpnum = 0;
}

void loop() {
  tmpnum = analogRead(1);
  numdif = tmpnum - basenum;  

  for (n=0;n<4;n++){
    strip.setPixelColor(n,0,0,0);
    }
  if (numdif > 30) strip.setPixelColor(0,255,0,0);
  if (numdif > 60) strip.setPixelColor(1,255,255,0);
  if (numdif > 100) strip.setPixelColor(2,127,255,0);
  if (numdif > 150) strip.setPixelColor(3,0,255,0);

  strip.show();

  Serial.print(maxnum);
  Serial.print("   ");
  Serial.print(numdif);
  Serial.print("   ");
  Serial.println(tmpnum);
  delay(10);
}
