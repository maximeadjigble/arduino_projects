int soundLevel = 0;
int ledPin = 12;
bool toggle = false;

void toggleLEDState(){
   digitalWrite(ledPin, toggle);
   toggle = !toggle;
}

void setup() {
   pinMode(ledPin, OUTPUT);
}

void loop(){
   soundLevel = analogRead(A0);

   if(soundLevel >= 650) {
      delay(100);
      toggleLEDState();
   }
   delay(1);
}