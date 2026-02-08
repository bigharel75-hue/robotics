#include <stdlib.h>
#include <time.h>
#define in1 9
#define in2 8
#define enable 3
int count = 60;
void setup() 
{
  srand(time(NULL));
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enable, OUTPUT);
  pinMode(4, INPUT_PULLUP);
}
void loop()
{
  if (digitalRead(4) == LOW)
  {
    count = rand() % 256;
    delay(1000);
  }
  analogWrite(enable, count);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(100);
}
