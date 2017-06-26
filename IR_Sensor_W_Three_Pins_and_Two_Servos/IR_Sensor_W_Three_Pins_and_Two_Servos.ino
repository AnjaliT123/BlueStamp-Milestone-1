#include <Servo.h>

int IRemitter = 3;
int IRdetector = 2;
int distance;

Servo leftServo;
Servo rightServo;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(IRemitter, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  tone(IRemitter, 38000);
  
  Serial.begin(9600);

  rightServo.attach(9);   //attaches rightServo to 9 pin
  leftServo.attach(10);   //attaches leftServo to 10 pin
  rightServo.write(90);   //no movement on this servo
  leftServo.write(90);    //no movement
  
}

void loop() {
  distance = digitalRead(IRdetector); //read from the detector 

  //if distance = 0 (LOW), infrared was detected
  //if distance = 1 (HGIH), infrared was not detected

  //use the Built in LED as output to show if infrared was detected
  //or not
  digitalWrite(LED_BUILTIN, !distance);

  //move servos if a surface was detected
  if(distance==LOW){
    leftServo.write(0);
    rightServo.write(0);
  }

  //stop the servos if no surface detected
  else{  
    leftServo.write(90);
    rightServo.write(90);
    
  }


}


