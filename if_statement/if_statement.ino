int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  while(!Serial){}
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(counter);

  if(counter < 5){
    Serial.println("Counter is less than 5");
  }
  else{
    Serial.println("Counter is greater or equal to 5");
  }

  counter = counter + 1;

  if(counter == 10){
    counter = 0;
  }

  delay(1000);
}
