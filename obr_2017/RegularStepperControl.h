#include <AccelStepper.h>
#include <AFMotor.h>

const byte stepsPerRevolution = 128;

int leftMotorSpeed = 32;
int rightMotorSpeed = 32;

AF_Stepper stepper_on_the_left(stepsPerRevolution, 1);
AF_Stepper stepper_on_the_right(stepsPerRevolution, 2);

void updateMotorsSpeed() {
  stepper_on_the_left.setSpeed(rightMotorSpeed);
  stepper_on_the_right.setSpeed(leftMotorSpeed);
}

void setupRegularStepperControl() {
  updateMotorsSpeed();
}

void goForward() {
  stepper_on_the_right.onestep(BACKWARD, SINGLE);
  stepper_on_the_left.onestep(BACKWARD, SINGLE);
  delay(20);
}

void goForwardWithMoreTorque() {
  stepper_on_the_right.onestep(BACKWARD, DOUBLE);
  stepper_on_the_left.onestep(BACKWARD, DOUBLE);
  delay(20);
}

void goBackward() {
  stepper_on_the_right.onestep(FORWARD, SINGLE);
  stepper_on_the_left.onestep(FORWARD, SINGLE);
  delay(20);
}

void goBackwardWithMoreTorque() {
  stepper_on_the_right.onestep(FORWARD, DOUBLE);
  stepper_on_the_left.onestep(FORWARD, DOUBLE);
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

void goAroundObject() {
  // Turn right
  leftMotorSpeed = 32;
  rightMotorSpeed = 24;
  updateMotorsSpeed();
  unsigned long  start = millis();
  while(millis() > (start+2000)) {
    updateColorSensorsValues();
    goForward(); // "kind of"
  }

  // Go straight
  leftMotorSpeed = 32;
  rightMotorSpeed = 32;
  updateMotorsSpeed();
  start = millis();
  while(millis() > (start+2000)) {
    updateColorSensorsValues();
    goForward(); // "kind of"
  }

  // Turn left again
  leftMotorSpeed = 24;
  rightMotorSpeed = 32;
  updateMotorsSpeed();
  start = millis();
  while(millis() > (start+2000)) {
    updateColorSensorsValues();
    goForward(); // "kind of"
  }

  // Reset
  leftMotorSpeed = 32;
  rightMotorSpeed = 32;
  updateMotorsSpeed();
}
