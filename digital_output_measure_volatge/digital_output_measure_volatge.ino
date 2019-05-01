int output_pin = 2;
int delayTimeMs = 5000;

void setup() {
  // put your setup code here, to run once:
  pinMode(output_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(output_pin, HIGH);
    delay(delayTimeMs);
    digitalWrite(output_pin, LOW);
    delay(delayTimeMs); 
}
