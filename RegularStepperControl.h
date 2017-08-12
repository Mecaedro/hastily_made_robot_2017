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
  delay(20); // Brinque com esse valor para ver a diferenca :v
}

void goBackward() {
  stepper_on_the_right.step(1); 
  stepper_on_the_left.step(1);
  delay(20); // Brinque com esse valor para ver a diferenca :v
}

void goForwardUntilStopCommand() {
    while(!Serial.available()) {
      goForward();
    }
    
    Serial.readString();
}

void goBackwardUntilStopCommand() {
    while(!Serial.available()) {
      goBackward();
    }
    
    Serial.readString();
}
