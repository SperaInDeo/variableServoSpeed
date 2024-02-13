#include <Servo.h>
int dt = 1;
int servoPosOld;
int servoPosNew;
int servoDif;
int direct;
int j;
int servoPin = A5;
int servoPos = 1500;
Servo teaServo;

void setup() {
  Serial.begin(9600);
  teaServo.attach(servoPin);
  teaServo.writeMicroseconds(1500);
  servoPosOld = 1500;
  servoPos = servoPosOld;
}

void loop() {
  Serial.println("Input angle 575-2375.");
  while (Serial.available() == 0){
  }
  servoPosNew = Serial.parseInt();
  servoDif = servoPosNew - servoPosOld;
  if (servoDif < 0){
    servoDif = servoDif*(-1);
    direct = 0;
  }
  else{
    direct = 1;
  }
  for (j=1; j<=servoDif; j++){
    if (direct == 0){
      servoPos--;
    }
    else{
      servoPos++;
    }
    teaServo.writeMicroseconds(servoPos);
    delay(dt);
  }
  servoPosOld = servoPos;

}
