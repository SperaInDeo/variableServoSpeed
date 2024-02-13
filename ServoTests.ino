#include <Servo.h>
int dt = 10;
int servoPosOld;
int servoPosNew;
int servoDif;
int direct;
int j;
int servoPin = A5;
int servoPos = 175;
Servo teaServo;

void setup() {
  Serial.begin(9600);
  teaServo.attach(servoPin);
  teaServo.write(90);
  servoPosOld = 90;
  servoPos = servoPosOld;
}

void loop() {
  Serial.println("Input angle 0-175.");
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
    teaServo.write(servoPos);
    delay(dt);
  }
  servoPosOld = servoPos;

}
