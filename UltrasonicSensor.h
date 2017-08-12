#include <ST_HW_HC_SR04.h>

ST_HW_HC_SR04 ultrasonicSensor(41, 40); // ST_HW_HC_SR04(TRIG, ECHO)

void displayUltrasonicSensorValues() {
  int hitTime = ultrasonicSensor.getHitTime();
  int distanceInCm = hitTime / 29;

  String msg = String("hitTime=") + hitTime + String("microseconds, ") + String("realDistance=") + distanceInCm + String("cm");
  Serial.println(msg);
}

