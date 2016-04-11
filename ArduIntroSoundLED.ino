#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, 2, NEO_GRB);

int maxnum,tmpnum, basenum, numdif, n , tic;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  strip.begin();
  strip.show();
  //basenum = analogRead(1);
  basenum = 450;
  maxnum = 0;
  tmpnum = 0;
}

// the loop routine runs over and over again forever:
void loop() {
  tmpnum = analogRead(1);
  if (tmpnum > maxnum) maxnum = tmpnum;
  numdif = tmpnum - basenum;  
  strip.setBrightness(50);
  for (n=0;n<4;n++){
    strip.setPixelColor(n,0,0,0);
    }
  
  if (numdif >5) strip.setPixelColor(0,255,0,0);
  if (numdif > 10) strip.setPixelColor(1,255,255,0);
  if (numdif > 15) strip.setPixelColor(2,127,255,0);
  if (numdif > 20) strip.setPixelColor(3,0,255,0);

  strip.show();

  Serial.print(maxnum);
  Serial.print("   ");
  Serial.print(numdif);
  Serial.print("   ");
  Serial.println(tmpnum);
  delay(100);
}
