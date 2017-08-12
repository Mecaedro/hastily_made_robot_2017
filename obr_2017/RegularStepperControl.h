#include <Stepper.h>

const byte stepsPerRevolution = 128;

int leftMotorSpeed = 32;
int rightMotorSpeed = 32;

Stepper stepper_on_the_left(stepsPerRevolution, 4, 5, 6, 7);
Stepper stepper_on_the_right(stepsPerRevolution, 11, 10, 9, 8);

void updateMotorsSpeed() {
  stepper_on_the_right.setSpeed(leftMotorSpeed);
  stepper_on_the_left.setSpeed(rightMotorSpeed);
}

void setupRegularStepperControl() {
  updateMotorsSpeed();
}

void goForward() {
  stepper_on_the_right.step(-1); 
  stepper_on_the_left.step(-1); 
  delay(20);
}

void goBackward() {
  stepper_on_the_right.step(1); 
  stepper_on_the_left.step(1);
  delay(20);
}

void turnLeftUntilNoMoreGreen() {
  leftMotorSpeed = 24;
  rightMotorSpeed = 32;
  updateMotorsSpeed();
  while(leftSensorIndicatesGreen()) {
    updateColorSensorsValues();
    goForward(); // "kind of"
  }
  leftMotorSpeed = 32;
  updateMotorsSpeed();
}

void turnRightUntilNoMoreGreen() {
  leftMotorSpeed = 32;
  rightMotorSpeed = 24;
  updateMotorsSpeed();
  while(rightSensorIndicatesGreen()) {
    updateColorSensorsValues();
    goForward(); // "kind of"
  }
  rightMotorSpeed = 32;
  updateMotorsSpeed();
}

void turnLeftUntilNoMoreRightBlack() {
  leftMotorSpeed = 24;
  rightMotorSpeed = 32;
  updateMotorsSpeed();
  while(rightSensorIndicatesBlack()) {
    updateColorSensorsValues();
    goForward(); // "kind of"
  }
  leftMotorSpeed = 32;
  updateMotorsSpeed();
}

void turnRightUntilNoMoreLeftBlack() {
  leftMotorSpeed = 32;
  rightMotorSpeed = 24;
  updateMotorsSpeed();
  while(leftSensorIndicatesBlack()) {
    updateColorSensorsValues();
    goForward(); // "kind of"
  }
  rightMotorSpeed = 32;
  updateMotorsSpeed();
}

