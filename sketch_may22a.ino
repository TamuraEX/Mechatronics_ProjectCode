void setup() {
  // put your setup code here, to run once:
  // サーボモータのピン番号
   pinMode(10, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(10, HIGH);
  delayMicroseconds(2000);
  digitalWrite(10, LOW);
  delay(1000);
  digitalWrite(10, HIGH);
  delayMicroseconds(3000);
  digitalWrite(10, LOW);
  delay(1000);
}
