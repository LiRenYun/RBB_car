#include<Servo.h>
Servo servoright;
Servo servoleft;
int time = 1000;
void setup() {
  servoright.attach(12);
  servoleft.attach(13);
  Serial.begin(9600);
}

void loop() {
  servoright.writeMicroseconds(1500);
  servoleft.writeMicroseconds(1500);
  delay(time);
  char c;
  if(Serial.available() > 0)
  {
    c = Serial.read();
    wheel_control(c);
  }
}
void wheel_control(char input)
{
  switch(input){
    case 'R':
      servoright.writeMicroseconds(1600);
      servoleft.writeMicroseconds(1600);
      delay(time);
    break;
    case 'L':
      servoright.writeMicroseconds(1400);
      servoleft.writeMicroseconds(1400);
      delay(time);
    break;
    case 'B':
      servoright.writeMicroseconds(1400);
      servoleft.writeMicroseconds(1600);
      delay(time);
    break;
    case 'F':
      servoright.writeMicroseconds(1600);
      servoleft.writeMicroseconds(1400);
      delay(time);
    break;
  }
}
