int ledPin = 3;
int valPot = 0;

void setup() {
}

void loop() {
  valPot = analogRead(A0);
  valPot = map(valPot, 0, 1023, 0, 255);
  analogWrite(ledPin, valPot);
}
