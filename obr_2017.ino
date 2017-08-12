/*
#
# obr_2017.ino - v0.1.0
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
  setupRegularStepperControl;

  displayInputSomethingMsg();
  displayHorizontalSeparator();
}
void loop() {
  waitForSomeCommand();
}

void waitForSomeCommand() {
  while(!Serial.available()); // Wait for Serial input
  String cmd = Serial.readString();
  Serial.println(String("Received: ") + cmd);
  Serial.flush();

  if(cmd.startsWith("go_forward")) {
    goForwardUntilStopCommand();
  } else if(cmd.startsWith("go_backward")) {
    goBackwardUntilStopCommand();
  } else if(cmd.startsWith("stop_moving")) {
    Serial.println("Not on movement currently");
    Serial.flush();
  } else if(cmd.startsWith("both_motors_speed")) {
    if(cmd.length() == 17) {
      Serial.println(String("left=") + String(leftMotorSpeed) + String(", right=") + String(rightMotorSpeed));
      Serial.flush();
    } else {
      String newValueString = cmd.substring(18, (cmd.length()));
      int newValue = newValueString.toInt();
      leftMotorSpeed = newValue;
      rightMotorSpeed = newValue;
      updateMotorsSpeed();
    }
  } else if(cmd.startsWith("left_motor_speed")) {
    if(cmd.length() == 16) {
      Serial.println(String("left=") + String(leftMotorSpeed) + String(", right=") + String(rightMotorSpeed));
      Serial.flush();
    } else {
      String newValueString = cmd.substring(17, (cmd.length()));
      int newValue = newValueString.toInt();
      leftMotorSpeed = newValue;
      rightMotorSpeed = newValue;
      updateMotorsSpeed();
    }
  } else if(cmd.startsWith("right_motor_speed")) {
    if(cmd.length() == 17) {
      Serial.println(String("left=") + String(leftMotorSpeed) + String(", right=") + String(rightMotorSpeed));
      Serial.flush();
    } else {
      String newValueString = cmd.substring(18, (cmd.length()));
      int newValue = newValueString.toInt();
      leftMotorSpeed = newValue;
      rightMotorSpeed = newValue;
      updateMotorsSpeed();
    }
  } else if(cmd.startsWith("colors")) {
    fetchColorSensorValues();
    displayColorSensorsValues();
  } else if(cmd.startsWith("distance")) {
    displayUltrasonicSensorValues();
  } else if(cmd.startsWith("delay")) {
    displayUltrasonicSensorValues();
  } else if(cmd.startsWith("jarbas_forward")) { // TODO
    displayNotImplementedMsg();;
  } else if(cmd.startsWith("jarbas_backward")) { // TODO
    displayNotImplementedMsg();
  } else if(cmd.startsWith("jarbas_delay")) { // TODO
    displayNotImplementedMsg();
  } else {
    displayCommandNotFoundMsg();
  }
  
  displayHorizontalSeparator();
  Serial.flush();
}

