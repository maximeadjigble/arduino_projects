#include "CurieTimerOne.h"

int ledPin = 12;
int defaultLedPin = 13;
bool toggle = false;

void callbackToggleLed(){
  digitalWrite(ledPin, toggle);
  toggle = !toggle;
}


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(defaultLedPin, OUTPUT);

  CurieTimerOne.start(1000000, &callbackToggleLed);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(defaultLedPin, HIGH);
  delay(500);
  digitalWrite(defaultLedPin, LOW);
  delay(500);
}
