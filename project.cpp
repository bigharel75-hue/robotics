#include "motor.h"
#define trigPin A4
#define echoPin A3
#define BAUD_RATE 115200
#define black 0
#define white 1024
#define motorL0 5
#define motorL1 9
#define motorR0 6
#define motorR1 10
#define CENTIMETERS_TO_DRIVE 255/50.0
#define tcrtL A1
#define tcrtR A2

motor motorL(motorL0, motorL1);
motor motorR(motorR0, motorR1);
int firstColor = 0;
int secColor = 0;

void setup() {
  for (int i = 3; i <= 10; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(tcrtL, INPUT);
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
  int distance = readUltraSonic()*(CENTIMETERS_TO_DRIVE - 10);
  motorL.move(distance);
  motorR.move(distance);
  Serial.print("distance: ");
  Serial.println(distance);
  delay(10);
}

int readUltraSonic()
{
  long duration = 0;
  int distance = 0;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}
int getGoodDistance()
{
  
}
