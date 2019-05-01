int inputPin = 0;
int ledPin = 12;
int inputPinState = 0;
int inputPinState_prevCycle = 1;
int ledState = LOW;

void setup() {
  pinMode(inputPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  //Serial.begin(9600);
  //while(!Serial){}
}

void loop() {

  inputPinState = digitalRead(inputPin);

  if(inputPinState > inputPinState_prevCycle){
    delay(200);
    if(ledState == LOW){
      ledState = HIGH;
    }
    else{
      ledState = LOW;
    }
  }

  digitalWrite(ledPin, ledState);
  
  inputPinState_prevCycle = inputPinState;
  //Serial.println(inputPinState);
  //delay(1000);
}
