#include <Servo.h>
int servoPosNew;
int servoPin = A5;
int myServoSpeed = 2;
bool notRunning = 1;
Servo myServo;

// Documentation
// Requires #include <Servo.h>
// Servo functionServo is the servo object usually created at the beginning of the sketch w/ example: Servo myServo;
// int servoPosition (1-180). Check your model. 550-2400 fall within the limits for servo model SM-S2309S
// int servoSpeed. milliseconds to delay the action of the servo motor. recommend values between 1-100
// Returns bool moveComplete = 1 after the movement has finished.
// Function should run in an undelayed loop while it returns moveComplete = 0 for best performance
//  Each time the function is run it will execute a single step (position)
//  if the number of prescribed milliseconds servoSpeed has elapsed.
// Currently only gives 170 degrees of motion to account for cheaper servos
// Motion values (575, 2375) should currently be hardcoded in depending on initial testing of particular servo.

bool speraInServo(Servo functionServo, int servoPosition, unsigned int servoSpeed){
  static bool moveComplete = 1;
  static unsigned long moveTime;
  static int currentPosition;
  // First time new servoPosition is received only variables
  if (moveComplete == 1){
    currentPosition = functionServo.read();
    currentPosition = map(currentPosition, 0, 180, 550, 2400);
    moveTime = millis();
  }

  servoPosition = map(servoPosition, 0, 180, 550, 2400);
  if (millis() >= moveTime){
      if (servoPosition < currentPosition){
        currentPosition--;
        functionServo.writeMicroseconds(currentPosition);
      }
      else if (servoPosition > currentPosition){
        currentPosition++;
        functionServo.writeMicroseconds(currentPosition);
      }
      else{
        moveComplete = 1;
        return moveComplete;
      }
      moveTime += servoSpeed;
  }
  moveComplete = 0;
  return moveComplete;
}

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  // Just to check if servo initializes and moves properly at the beginning or upon restart
  myServo.writeMicroseconds(700);
}

void loop() {
  if (notRunning == 1){
    Serial.println("Input angle 0-180.");
    while (Serial.available() == 0){
    }
    servoPosNew = Serial.parseInt();
  }
  
  notRunning = speraInServo(myServo, servoPosNew, myServoSpeed);
}
