#include <Servo.h>

// サーボモータのピン番号
const int servoPin1 = 11;
const int servoPin2 = 10;
const int servoPin3 = 9;
//const int servoPin4 = 5;

// ホールセンサ(テスト時はスイッチで代用）のピン番号
const int button_servo1_CW = 2; //ホールセンサ使用時はアナログピン
const int button_servo1_CCW = 3;
const int button_servo2_CW = 4;
const int button_servo2_CCW = 5;
const int button_servo3_CW = 6;
const int button_servo3_CCW = 7;
//const int button_servo4_CW = ;
//const int button_servo4_CCW = ;


// サーボモータの初期角
int initialAngle1 = 0;//ちゃんと決定したほうがいい
int initialAngle2 = 0;
int initialAngle3 = 0;
int initialAngle4 = 0;

// サーボモータの回転角度の範囲（たぶん制約がいる）
int minAngle = 0;
int maxAngle = 180;

// ホールセンサの値の範囲(使うとき用)
//const int minSensorValue = 0;
//const int maxSensorValue = 4098; //12bitだから

// サーボオブジェクトの宣言
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// 関数のプロトタイプ宣言
void calculateInverseKinematics(int sensorValue1, int sensorValue2, int sensorValue3, int sensorValue4);
int mapSensorValueToAngle(int sensorValue, int minSensorValue, int maxSensorValue, int minAngle, int maxAngle);
int pmax = 2400;
int pmin = 10;
int S_angle1;
int S_angle2;
int S_angle3;
int S_angle4;


void setup() {
  // シリアル通信の開始
  Serial.begin(9600);

  // サーボモータのピンを出力モードに設定
  pinMode(servoPin1, OUTPUT);
  pinMode(servoPin2, OUTPUT);
  pinMode(servoPin3, OUTPUT);
  //pinMode(servoPin4, OUTPUT);

  // サーボオブジェクトにピン番号を割り当て
  servo1.attach(servoPin1,pmin,pmax);
  servo2.attach(servoPin2,pmin,pmax);
  servo3.attach(servoPin3,pmin,pmax);
  //servo4.attach(servoPin4,pmin,pmax);

  // サーボモータの初期角度を設定
  servo1.write(initialAngle1);
  servo2.write(initialAngle2);
  servo3.write(initialAngle3);
  //servo4.write(initialAngle4);

  S_angle1 = initialAngle1;
  S_angle2 = initialAngle2;
  S_angle3 = initialAngle3;
  S_angle4 = initialAngle4;
}


void loop() {
  //スイッチの動作
  if(digitalRead(button_servo1_CW) == 0){
    if(digitalRead(button_servo1_CCW) == 1){
    S_angle1 += 1;}
  }
  if(digitalRead(button_servo1_CCW) == 0){
    if(digitalRead(button_servo1_CW) == 1){
    S_angle1 -= 1;}
  }
  if(digitalRead(button_servo2_CW) == 0){
    if(digitalRead(button_servo2_CCW) == 1){
    S_angle2 += 1;}
  }
  if(digitalRead(button_servo2_CCW) == 0){
    if(digitalRead(button_servo2_CW) == 1){
    S_angle2 -= 1;}
  }
  if(digitalRead(button_servo3_CW) == 0){
    if(digitalRead(button_servo3_CCW) == 1){
    S_angle3 += 1;}
  }
  if(digitalRead(button_servo3_CCW) == 0){
    if(digitalRead(button_servo3_CW) == 1){
    S_angle3 -= 1;}
  }



  /* ホールセンサからの入力値を読み取る
  int sensorValue1 = analogead(hallSensorPin1);　//たぶんこの辺でノイズが乗る。フィルタがいるかもしれない（ソフト的に？ハード的に？）
  int sensorValue2 = analogRead(hallSensorPin2);
  int sensorValue3 = analogRead(hallSensorPin3);
  int sensorValue4 = analogRead(hallSensorPin4);

  // 逆運動学の計算と関節角度の決定
  calculateInverseKinematics(sensorValue1, sensorValue2, sensorValue3, sensorValue4);　//

  // 一定の遅延を挿入してサーボモータを更新
  delay(100);
}

void calculateInverseKinematics(int sensorValue1, int sensorValue2, int sensorValue3, int sensorValue4) {
  // ホールセンサの値から角度をもとめる：比例関係なのでmap関数でダウンスケール（ただし、今回は単純なアームロボットじゃないのでこの辺改良要）
  int angle1 = mapSensorValueToAngle(sensorValue1, minSensorValue, maxSensorValue, minAngle, maxAngle);
  int angle2 = mapSensorValueToAngle(sensorValue2, minSensorValue, maxSensorValue, minAngle, maxAngle);
  int angle3 = mapSensorValueToAngle(sensorValue3, minSensorValue, maxSensorValue, minAngle, maxAngle);
  int angle4 = mapSensorValueToAngle(sensorValue4, minSensorValue, maxSensorValue, minAngle, maxAngle);
*/

  // サーボモータに角度をセット
  servo1.write(S_angle1);
  servo2.write(S_angle2);
  servo3.write(S_angle3);
  servo4.write(S_angle4);
  delay(70);

  // 関節角度をシリアルモニタに表示（デバッグ用）
  Serial.print("Joint Angles: ");
  Serial.print(S_angle1);
  Serial.print(", ");
  Serial.print(S_angle2);
  Serial.print(", ");
  Serial.print(S_angle3);
  Serial.print(", ");
  Serial.println(S_angle4);
}

int mapSensorValueToAngle(int sensorValue, int minSensorValue, int maxSensorValue, int minAngle, int maxAngle) {
  // ホールセンサの値を関節角度の範囲にマッピング
  return map(sensorValue, minSensorValue, maxSensorValue, minAngle, maxAngle); //まだ使ってない
}
