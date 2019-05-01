//Declare the pins on which the LEDs are connected
int ledPinRed = 2;
int ledPinYellow = 1;
int ledPinGreen = 0;

void setup() {
  // Set the pins 1, 2, 3 as output
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinYellow, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);

  //Turn OFF all the LEDs
  digitalWrite(ledPinRed, LOW);
  digitalWrite(ledPinYellow, LOW);
  digitalWrite(ledPinGreen, LOW);
}

void loop() {
  // Successively Turn on each LED
  changeLedState(ledPinRed, 3000);
  changeLedState(ledPinYellow, 1000);
  changeLedState(ledPinGreen, 3000);
}

void changeLedState(int ledPin, int duration){
  //Turn ON the selected LED and turn off  
  //all the other ones
  if(ledPin == ledPinRed){
    digitalWrite(ledPinRed, HIGH);
    digitalWrite(ledPinYellow, LOW);
    digitalWrite(ledPinGreen, LOW);
  }
  else if(ledPin == ledPinYellow){
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinYellow, HIGH);
    digitalWrite(ledPinGreen, LOW);
  }
  else if(ledPin == ledPinGreen){
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinYellow, LOW);
    digitalWrite(ledPinGreen, HIGH);
  }
  else{
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinYellow, LOW);
    digitalWrite(ledPinGreen, LOW);
  }
  
  delay(duration);
}
