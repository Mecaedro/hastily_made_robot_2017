/*
#
# obr_2017.ino - v0.2.0
# Made by Flávio Monteiro
# Aug 11, 2017
#
# MIT License
#
*/

#include "SerialHelper.h"
#include "ColorSensors.h"
#include "RegularStepperControl.h"
//#include "QuirkyStepperControl"
#include "UltrasonicSensor.h"

void setup() {
  Serial.begin(9600);

  displayVersionInfo();
  setupColorSensorsPins();
  setupRegularStepperControl();
  getColorSensorsInitialValues();
}
void loop() {
  while((!leftSensorIndicatesGreen()) || (!rightSensorIndicatesGreen()) || (!leftSensorIndicatesBlack()) || (!rightSensorIndicatesBlack())) {
    updateColorSensorsValues();
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
}


void getColorSensorsInitialValues() {
  updateColorSensorsValues();
  lls_r = l_red;
  lls_g = l_green;
  lls_b = l_blue;
  lls_c = l_clear;
  rls_r = r_red;
  rls_g = r_green;
  rls_b = r_blue;
  rls_c = r_clear;
}
