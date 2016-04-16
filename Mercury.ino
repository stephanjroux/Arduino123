#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, 2, NEO_GRB);

int n , x, tiltangle, tiltcount, oldtiltangle, lockstage, lockstagecounter, loopdelay;
int swpin = 7;
char printstring;

void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.setBrightness(50);
  strip.show();
  pinMode(swpin,INPUT_PULLUP);

  tiltcount=0;
  lockstage = 0;
  lockstagecounter = 0;
  loopdelay = 100;
}

void loop() {
  tiltangle = digitalRead(7);
  
  for (n=0;n<4;n++){
    strip.setPixelColor(n,0,0,0);
    }
  
  if (tiltangle != oldtiltangle) {  //It changed
    ++tiltcount;
    oldtiltangle = tiltangle;
  }

  if (tiltangle == LOW){
    strip.setPixelColor(0,0,0,255);
  }

  if ((tiltcount == 10)&&(lockstage == 0)){
    lockstage=1;
    }

  if ((tiltcount == 10)&&(lockstage == 1)){
    strip.setPixelColor(1,0,0,255);
    }

  if (lockstage == 2){
        strip.setPixelColor(1,0,0,255);
        strip.setPixelColor(2,0,0,255);
        if (tiltcount == 10){
            lockstage = 3;
            lockstagecounter = 0;
            }
        else if (lockstagecounter > (10000/loopdelay)){
            lockstage = 0;
            lockstagecounter = 0;
            }
        else {
            lockstagecounter++;
            }
        }  

  if (lockstage == 3){
      if (lockstagecounter < (1000/loopdelay)){
          ++ lockstagecounter;
          strip.setPixelColor(1,0,0,255);
          strip.setPixelColor(2,0,0,255);
          strip.setPixelColor(3,0,0,255);
          }
      else {
            for (x=0;x<4;x++){
              for (n=0;n<4;n++){
                  strip.setPixelColor(n,0,0,255);
                  }
              strip.show();
              delay(100);
              for (n=0;n<4;n++){
                  strip.setPixelColor(n,0,0,0);
                  }
              strip.show();
              delay(100);
              }
          while(1){
              rainbowCycle(5);
              }
          }
      }
  
  if ((tiltcount > 10)&&(lockstage == 1)){
        tiltcount = 0;
        lockstage = 0;
        lockstagecounter = 0;
      }
  else if (lockstage == 1)
      {
        if (lockstagecounter >(3000/loopdelay)){
            tiltcount = 0;
            lockstage = 2;
            }
        else{
            lockstagecounter++;
            }
      }
      
  Serial.println("TC:" +  String(tiltcount) + " TA:"+ tiltangle + " LS:" + lockstage + " LSC: "+lockstagecounter);
  strip.show();
  delay(loopdelay);
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
