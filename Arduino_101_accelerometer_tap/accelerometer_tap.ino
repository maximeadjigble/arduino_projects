#include "CurieIMU.h"

bool stateLed = false;
int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);

  CurieIMU.begin();
  CurieIMU.setAccelerometerRange(4);

  CurieIMU.attachInterrupt(eventCallback);
  CurieIMU.interrupts(CURIE_IMU_TAP);
  CurieIMU.setDetectionThreshold(CURIE_IMU_TAP, 750);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void eventCallback() {
  if(CurieIMU.getInterruptStatus(CURIE_IMU_TAP)){
    
    if(CurieIMU.tapDetected(Z_AXIS, NEGATIVE) ||
      CurieIMU.tapDetected(Z_AXIS, POSITIVE)){
        stateLed = !stateLed;
        digitalWrite(ledPin, stateLed);
      }
  }
}

