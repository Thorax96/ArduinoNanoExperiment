#include <Arduino.h>
#include <Logger.h>
#include <LEDS.h>
#include <Tools.h>

const int DelayTime = 1000;
const int blinkDuration = 50;

Logger myLogger;
LEDS myLeds(&myLogger);
void blink(const int& portId);


void setup() {

}

void loop() {
  const int* portIds = myLeds.getPortIds();
  Tools::forEach(portIds, blink);
  delay(DelayTime);
}

void blink(const int& portId){
  myLeds.blink(portId, blinkDuration);
}