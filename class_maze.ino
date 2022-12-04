// Demo program for testing library and board - flip the switch to turn on/off buzzer

#include <Adafruit_CircuitPlayground.h>

// we light one pixel at a time, this is our counter
uint8_t pixeln = 0;
uint8_t delaytime=10;
const uint8_t spTIME[]      PROGMEM = {0x0E,0x28,0xAC,0x2D,0x01,0x5D,0xB6,0x0D,0x33,0xF3,0x54,0xB3,0x60,0xBA,0x8C,0x54,0x5C,0xCD,0x2D,0xD4,0x32,0x73,0x0F,0x8E,0x34,0x33,0xCB,0x4A,0x25,0xD4,0x25,0x83,0x2C,0x2B,0xD5,0x50,0x97,0x08,0x32,0xEC,0xD4,0xDC,0x4C,0x33,0xC8,0x70,0x73,0x0F,0x33,0xCD,0x20,0xC3,0xCB,0x43,0xDD,0x3C,0xCD,0x8C,0x20,0x77,0x89,0xF4,0x94,0xB2,0xE2,0xE2,0x35,0x22,0x5D,0xD6,0x4A,0x8A,0x96,0xCC,0x36,0x25,0x2D,0xC9,0x9A,0x7B,0xC2,0x18,0x87,0x24,0x4B,0x1C,0xC9,0x50,0x19,0x92,0x2C,0x71,0x34,0x4B,0x45,0x8A,0x8B,0xC4,0x96,0xB6,0x5A,0x29,0x2A,0x92,0x5A,0xCA,0x53,0x96,0x20,0x05,0x09,0xF5,0x92,0x5D,0xBC,0xE8,0x58,0x4A,0xDD,0xAE,0x73,0xBD,0x65,0x4B,0x8D,0x78,0xCA,0x2B,0x4E,0xD8,0xD9,0xED,0x22,0x20,0x06,0x75,0x00,0x00,0x80,0xFF,0x07};
uint8_t start=0;
uint8_t winner=0;
  //0=playing, 1=winner, 2=loser

void setup() {
  Serial.begin(9600);
  Serial.println("Circuit Playground test!");
  // turn off speaker when not in use
  CircuitPlayground.speaker.enable(false);

  CircuitPlayground.begin();
  start=0;
  winner=0;
}

//main program loop
void loop() {



  // idle loop
  while(start==0){
    // test Red #13 LED
    CircuitPlayground.redLED(HIGH);
    delay(20*delaytime);
    CircuitPlayground.redLED(LOW);
    delay(20*delaytime);

    if (CircuitPlayground.leftButton()) {
      Serial.println("Start Game");
      // start the game
     Serial.print("starting now.... ");

      start=1;
    CircuitPlayground.redLED(HIGH);
    delay(150);
    CircuitPlayground.redLED(LOW);
    delay(75);
    CircuitPlayground.redLED(HIGH);
    delay(150);
    CircuitPlayground.redLED(LOW);
    delay(75);
    CircuitPlayground.redLED(HIGH);
    delay(150);
    CircuitPlayground.redLED(LOW);
    delay(75);
    CircuitPlayground.redLED(HIGH);
    delay(150);
    CircuitPlayground.redLED(LOW);
    delay(75);
    CircuitPlayground.redLED(HIGH);
    delay(150);
    CircuitPlayground.redLED(LOW);
    delay(1000);
    }

    if (CircuitPlayground.rightButton()) {
      Serial.println("Add Time");
      delaytime = delaytime+10;
      Serial.println(delaytime,DEC);
        CircuitPlayground.redLED(HIGH);
        delay(75);
        CircuitPlayground.redLED(LOW);
        delay(75);
        CircuitPlayground.redLED(HIGH);
        delay(75);
        CircuitPlayground.redLED(LOW);
      delay(75);
    }

  }

  //back in 
  if(CircuitPlayground.lightSensor()>25)
  {
  /************* TEST 10 NEOPIXELS */
    CircuitPlayground.setPixelColor(pixeln++, CircuitPlayground.colorWheel(25 * pixeln));
    if (pixeln == 11) {
      pixeln = 0;
      CircuitPlayground.clearPixels();
      delaytime--;
      Serial.println("Delay decrease");
    }
    delay(delaytime*100);
  
    //decrease time
    if (delaytime<0) {
    // time is up
    winner=2;
    CircuitPlayground.clearPixels();
    delay(10);
    }
  } else {  
      Serial.print("Light sensor: ");
      Serial.println(CircuitPlayground.lightSensor());
      delay(10);
      // winner
      winner=1;
      CircuitPlayground.clearPixels();
      delay(10);
  }

  //winner
  while(winner==1){
    Serial.println("Winner");
    CircuitPlayground.playTone(440,100);    
    CircuitPlayground.playTone(1760,100);
    delay(200);
    CircuitPlayground.playTone(440,100);    
    CircuitPlayground.playTone(1760,100);
    for(pixeln=0;pixeln<12;pixeln++){
    CircuitPlayground.setPixelColor(pixeln++, CircuitPlayground.colorWheel(25*3));
    delay(200);
       }
    for(pixeln=0;pixeln<12;pixeln++){
    CircuitPlayground.setPixelColor(pixeln++, CircuitPlayground.colorWheel(25 * 6));
    delay(200);
       }
  }

  //loser
  while(winner==2){
    CircuitPlayground.redLED(HIGH);
    CircuitPlayground.playTone(1760,100);
    CircuitPlayground.playTone(440,100);    

    Serial.println("Time Up");
    delay(1000);
    CircuitPlayground.redLED(LOW);
    delay(1000);
    for(pixeln=0;pixeln<12;pixeln++){
    CircuitPlayground.setPixelColor(pixeln++, CircuitPlayground.colorWheel(25 * 0));
    delay(200);
       }
    CircuitPlayground.playTone(1760,100);
    CircuitPlayground.playTone(440,100);   
    for(pixeln=0;pixeln<12;pixeln++){
    CircuitPlayground.setPixelColor(pixeln++, CircuitPlayground.colorWheel(25 * 1));
    delay(200);
       }

  }

} 



