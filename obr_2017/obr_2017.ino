/*
#
# obr_2017.ino - v0.4.b
# Made by Flávio Monteiro
# Aug 12, 2017
#
# MIT License
#
*/

#include "SerialHelper.h"
#include "ColorSensors.h"
#include "RegularStepperControl.h"
#include "UltrasonicSensor.h"

void setup() {
  Serial.begin(9600);

  displayVersionInfo();
  setupColorSensorsPins();
  setupRegularStepperControl();

  ultrasonicSensor.setTimeout(5000); // 5ms
}
void loop() {
  while((!leftSensorIndicatesGreen()) || (!rightSensorIndicatesGreen()) || (!leftSensorIndicatesBlack()) || (!rightSensorIndicatesBlack()) || (!distanceToHitSomethingSmall())) {
    updateColorSensorsValues();
    updateUltrasonicSensorDistance();

    goForward();
  }

  if(lastEv == 0) {
    turnLeftUntilNoMoreGreen();
  }

  if(lastEv == 1) {
    turnRightUntilNoMoreGreen();
  }

  if(lastEv == 2) {
    turnRightUntilNoMoreLeftBlack();
  }

  if(lastEv == 3) {
    turnLeftUntilNoMoreRightBlack();
  }

  if(lastEv == 4) {
    goAroundObject();
  }
}
