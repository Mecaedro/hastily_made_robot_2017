#include <ST_HW_HC_SR04.h>

ST_HW_HC_SR04 ultrasonicSensor(41, 40); // ST_HW_HC_SR04(TRIG, ECHO)

int distance = 0;

bool distanceToHitSomethingSmall() {
  /*if(distance < 8) {
    return true;
  }*/

  return false;
}

void updateUltrasonicSensorDistance() {
  distance = ultrasonicSensor.getHitTime() / 29;
}

