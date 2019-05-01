float degreeC = 22;
float degreeF = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  while(!Serial){}

  degreeF = (9.0/5)*degreeC + 32;
  
  Serial.println(degreeF);
}

void loop() {
  // put your main code here, to run repeatedly:

}
