class motor{
  private:
    int pin0;
    int pin1;

  public:
    motor(int p0, int p1) {
      pin0 = p0;
      pin1 = p1;
    }

    void begin() {
      pinMode(pin0, OUTPUT);
      pinMode(pin1, OUTPUT);
    }

    void move(int speed) {
      if (speed > 255) speed = 255;//checks if the speed is bigger than the max speed or smaller than the min speed
      if (speed < -255 ) speed = -255;
      if (speed > 0) {//checks if to drive forward or backwards
        analogWrite(pin0, speed);
        analogWrite(pin1, LOW);
      }
      else {
        analogWrite(pin1, -speed);//drive -speed cause the speed is lower than zero
        analogWrite(pin0, LOW);
      }
    }
};
