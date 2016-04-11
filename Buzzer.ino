#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, 2, NEO_GRB);


int maxnum,tmpnum, basenum, numdif, n , tic;
bool ison;



void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.setBrightness(50);
  strip.show();
  basenum = analogRead(1);
  maxnum = 0;
  tmpnum = 0;
  ison = false;
  pinMode(13,INPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
}
