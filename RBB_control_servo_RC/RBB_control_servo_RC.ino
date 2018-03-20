#include<Servo.h>
SoftwareSerial BT(8, 9); // 接收腳, 傳送腳
Servo servoright;
Servo servoleft;
int time = 1000;
char val;  // 儲存接收資料的變數
void setup() {
  servoright.attach(12);
  servoleft.attach(13);
  Serial.begin(9600);
  BT.begin(38400);
}

void loop() {
  servoright.detach();
  servoleft.detach();
  delay(time);
  char c;
  if(Serial.available() > 0)
  {
    c = Serial.read();
    wheel_control(c);
  }
  if (BT.available()) {
    val = BT.read();
    wheel_control(val);
  }
}
void wheel_control(char input)
{
  servoright.attach(12);
  servoleft.attach(13);
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
    case 'F':
      servoright.writeMicroseconds(1400);
      servoleft.writeMicroseconds(1600);
      delay(time);
    break;
    case 'B':
      servoright.writeMicroseconds(1600);
      servoleft.writeMicroseconds(1400);
      delay(time);
    break;
  }
}
