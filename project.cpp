#include "motor.h"
#define trigPin A4
#define echoPin A3
#define BAUD_RATE 115200
#define black 0 //no need of this
#define white 1024
#define motorL0 5
#define motorL1 9
#define motorR0 10
#define motorR1 6
#define CENTIMETERS_TO_DRIVE 255/50.0
#define tcrtL A1
#define tcrtR A2

motor motorL(motorL0, motorL1);//defines the motors
motor motorR(motorR0, motorR1);
int firstColor = 0;
int secColor = 0;

void setup() {
  for (int i = 3; i <= 10; i++)//defines the motors to OUTPUT
  {
    pinMode(i, OUTPUT);
  }
  pinMode(tcrtL, INPUT);//no need of this, was for line folower
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(BAUD_RATE);
  
  // Clears the Serial Monitor screen on startup/reset
  Serial.write("\033[2J"); 
  Serial.write("\033[H");

  motorL.begin();
  motorR.begin();
  Serial.println("finished serial");
}
void loop() 
{
  int distance = readUltraSonic();
  int error = (distance-15)*CENTIMETERS_TO_DRIVE;//i used const, next time ill use map, easier
  motorR.move(error);//moves the error
  motorL.move(error);
  //motorR.move((error < 0)?-100:error);
  //motorL.move((error < 0)?-100:error);
  Serial.print("distance: ");
  Serial.println(distance);
  Serial.print("error: ");
  Serial.println(error);
  Serial.print("CENTIMETERS_TO_DRIVE: ");
  Serial.println(CENTIMETERS_TO_DRIVE);
  
  delay(100);
}

int readUltraSonic()
{
  long duration = 0;
  int distance = 0;
  digitalWrite(trigPin, LOW);//resets the pin
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);//gets the duration
  distance = duration * 0.034 / 2;//calculates the distance
  return distance;
}


