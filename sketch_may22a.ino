#include<Servo.h>

Servo servo;

void setup() {
  // put your setup code here, to run once:
  // サーボモータのピン番号
  servo.attach(10, 500, 2400);
  pinMode(10, OUTPUT);


}

void loop() {
  servo.write(0);
  delay(1000);
  servo.write(90);
  delay(1000);
}

/*
// put your main code here, to run repeatedly:
  servo(10,500,2500);
  digitalWrite(10, HIGH);
  delayMicroseconds(5000);
  digitalWrite(10, LOW);
  delay(1000);
  digitalWrite(10, HIGH);
  delayMicroseconds(5000);
  digitalWrite(10, LOW);
  delay(1000);
  */
