#include <CurieTimerOne.h>
#include <BlynkSimpleCurieBLE.h>
#include <CurieBLE.h>
#include <CurieIMU.h>

int buzzerPin = 3;
int ledPin = 2;
bool setAlarmOn = false;
bool startCountDown = false;
int setAlarm = false;
int alarmTimer = 2000;
int soundLevel = 0;
int oneMilSecInUsec = 1000;
float timestamp = 0;
int counterAlarm = 0;
int alarmTimer_temp = 0;

char auth[] = "YourAuthCode";

BLEPeripheral  blePeripheral;

void callbackFunc()   
{ 
  soundLevel = analogRead(A0);
  
  //Serial.println(soundLevel);
  if(soundLevel >= 650){
    Serial.println("Voice STOP command detected!");
    stopAlarm();
  }

  if(startCountDown){
    if(timestamp >= alarmTimer){
      setAlarmOn = true;
      startCountDown = false;
    }
    else{
      timestamp = timestamp + 0.001;
    }
  }
  else{
    timestamp = 0;
  }
  
  counterAlarm = counterAlarm + 1;

  if(counterAlarm >= 1750){
    counterAlarm = 0;
  }
}

void stopAlarm()
{
    setAlarmOn = false;
    startCountDown = false;
    timestamp = 0;
    analogWrite(buzzerPin, 0);
    digitalWrite(ledPin, LOW);
    Serial.println("Alarm Turned Off");
}
  
void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
  delay(1000);

  blePeripheral.setLocalName("Blynk");
  blePeripheral.setDeviceName("Blynk");
  blePeripheral.setAppearance(384);

  Blynk.begin(blePeripheral, auth);

  blePeripheral.begin();

  Serial.println("Waiting for connections...");

  CurieIMU.begin();
  CurieIMU.attachInterrupt(callbackTap);
  
  CurieIMU.setAccelerometerRange(4);
  CurieIMU.setDetectionThreshold(CURIE_IMU_TAP, 250);
  CurieIMU.interrupts(CURIE_IMU_TAP);
    
  //Start the timer
  CurieTimerOne.start(oneMilSecInUsec, &callbackFunc);
}

void loop() {
  Blynk.run();
  blePeripheral.poll();
  
  if(setAlarmOn){
      playAlarmSound();
  }
}

void callbackTap()
{
  if (CurieIMU.getInterruptStatus(CURIE_IMU_TAP)) {
     Serial.println("Tap detected!");
     stopAlarm();
  }
}

BLYNK_WRITE(V0)
{
  alarmTimer_temp = param.asInt();

  Blynk.virtualWrite(V2, (int)(1000*timestamp));
}

BLYNK_WRITE(V1)
{
  int set = param.asInt();

  if(set){
    alarmTimer = alarmTimer_temp;
    startCountDown = true;
    Serial.print("Alarm starts in: ");
    Serial.println(alarmTimer);
  }
}

BLYNK_WRITE(V3)
{
  int _stop = param.asInt();

  if(_stop){
     Serial.println("Remote Stop button ON!");
     stopAlarm();
  }
}

void playAlarmSound(){
  if(counterAlarm <= 250){
    digitalWrite(ledPin, HIGH);
    analogWrite(buzzerPin, 200);
  }
  else if((counterAlarm > 250) && (counterAlarm <= 500)){
    analogWrite(buzzerPin, 0);
  }
  else if((counterAlarm > 500) && (counterAlarm <= 750)){
    analogWrite(buzzerPin, 200);
  }
  else{
    digitalWrite(ledPin, LOW);
    analogWrite(buzzerPin, 0);
  }
}
