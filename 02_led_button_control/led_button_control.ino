int inputPin = 0;
int ledPin = 12;
int buttonState = 0;
int buttonStateTm1 = 0;
int ledState = LOW;

void setup() {
  pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(inputPin);
  if(buttonState > buttonStateTm1){
    delay(200);
    ledState = !ledState;
  }
  digitalWrite(ledPin, ledState);
  buttonStateTm1 = buttonState;
}
