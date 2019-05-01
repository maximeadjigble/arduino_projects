int ledPin_default = 13;
int ledPin_external = 12;

int delayTimeMs_default = 0;
int delayTimeMs_external = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin_default, OUTPUT);
  pinMode(ledPin_external, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delayTimeMs_default = secToMs(1);
  delayTimeMs_external = secToMs(2);
  
  
  blinkLed(ledPin_default, delayTimeMs_default);
  blinkLed(ledPin_external, delayTimeMs_external);
}

void blinkLed(int ledPin, int duration) {
    digitalWrite(ledPin, HIGH);
    delay(duration);
    digitalWrite(ledPin, LOW);
    delay(duration);
}

int secToMs(int t){

  return t*1000;
}

