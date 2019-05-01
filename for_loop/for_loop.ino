int ledPin = 13;
int myVar = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);

  while(!Serial) {}
  
}

void loop() {
  // put your main code here, to run repeatedly:

  myVar = 0;
  while(myVar < 5) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);

    myVar = myVar + 1;
  }

  myVar = 0;
  while(myVar < 5) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);

    myVar = myVar + 1;
  }
 
}
