#include <CurieIMU.h>
#include <MadgwickAHRS.h>

Madgwick filter;
unsigned long microsPerReading, microsPrevious;

int led1Pin = 3;
int led2Pin = 5;
int led3Pin = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  while(!Serial){};

  CurieIMU.begin();
  CurieIMU.setGyroRate(25);
  CurieIMU.setAccelerometerRate(25);
  filter.begin(25);

  CurieIMU.setAccelerometerRange(2);
  CurieIMU.setGyroRange(250);

  microsPerReading = 1000000 / 25;
  microsPrevious = micros();
}

void loop() {
  // put your main code here, to run repeatedly:
  int aix, aiy, aiz;
  int gix, giy, giz;
  float ax, ay, az;
  float gx, gy, gz;
  float roll, pitch, yaw;
  unsigned long microNow;
  int pwmLed1, pwmLed2, pwmLed3;
  
  microNow = micros();

  if(microNow - microsPrevious >= microsPerReading){
    
    CurieIMU.readMotionSensor(aix, aiy, aiz, gix, giy, giz);

    ax = convertRawAcceleration(aix);
    ay = convertRawAcceleration(aiy);
    az = convertRawAcceleration(aiz);
    gx = convertRawGyro(gix);
    gy = convertRawGyro(giy);
    gz = convertRawGyro(giz);

    filter.updateIMU(gx, gy, gz, ax, ay, az);
    
    roll = filter.getRoll();
    pitch = filter.getPitch();
    yaw = filter.getYaw();
    
    Serial.print(roll);
    Serial.print(" ");
    Serial.print(pitch); 
    Serial.print(" ");  
    Serial.println(yaw);

    microsPrevious = microsPrevious + microsPerReading;

    pwmLed1 = map((int)roll, -20, 20, 0, 150);
    pwmLed2 = map((int)pitch, -20, 20, 0, 150);
    pwmLed3 = map((int)yaw, 180, 220, 0, 150);
    
    analogWrite(led1Pin, pwmLed1);
    analogWrite(led2Pin, pwmLed2);
    analogWrite(led3Pin, pwmLed3);
    
  }
  
}

float convertRawAcceleration(int aRaw){

  float a = (aRaw * 2.0) / 32768.0;

  return a;
}

float convertRawGyro(int gRaw){

  float g = (gRaw * 250.0) / 32768.0;

  return g;
}

