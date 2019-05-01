int ledPin = 3;
int valPot = 0;

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  valPot = analogRead(A0);
  valPot = map(valPot, 0, 1023, 0, 255);
  
  analogWrite(ledPin, valPot);
}
