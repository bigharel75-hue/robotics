#include <stdlib.h>
#include <time.h>
#define IN1 9
#define IN2 8
#define ENABLE 3
int count = 60;
void activateMotor(int in1, int in2, int enable, bool direction);
void setup() 
{
  Serial.begin(115200);
  srand(time(NULL));//cals the function srand() with the function time() that gets the number of seconds passed from 1970, the function rand uses the formula (NextValue = (A / CurrentValue + C) when a and c are consts chosed by the creators of the language it does overflow until it gets to a legal sized number
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENABLE, OUTPUT);
  pinMode(4, INPUT_PULLUP);
  Serial.println("setup finishhed");
}
void loop()
{
  if (digitalRead(4) == LOW)//pin 4 is the pin of the button
  {
    count = rand() % 256;
    Serial.print("the speed is: ");
    Serial.println(count);
    delay(1000);
  }
  activateMotor(IN1,IN2,ENABLE,1);
  delay(100);
  Serial.print("activated motor\n");
}
void activateMotor(int in1, int in2, int enable, bool direction)
{
  analogWrite(enable, count);
  digitalWrite(in1, direction);
  digitalWrite(in2, !direction);
}
