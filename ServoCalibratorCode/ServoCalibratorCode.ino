// Simmple loop with the goal for the user to note the difference between 
// Servo.write() and Servo.writeMicroseconds() for their specific servo via trial and error.

#include <Servo.h>
int servoPin = A5;
int servoPosition;
Servo myServo;



void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  Serial.println("enter angle in degrees");
  while (Serial.available() == 0){
  }
  servoPosition = Serial.parseInt();
  myServo.write(servoPosition);

  Serial.println("enter angle in microSeconds");
  while (Serial.available() == 0){
  }
  servoPosition = Serial.parseInt();
  myServo.writeMicroseconds(servoPosition);
}
