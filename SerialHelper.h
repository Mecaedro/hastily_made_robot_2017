void displayHorizontalSeparator() {
  Serial.println("----------");
  Serial.flush();
}

void displayVersionInfo() {
  Serial.println("obr_2017 - v0.1.0");
  Serial.println("Aug 11, 2017");
  displayHorizontalSeparator();
}

void displayInputSomethingMsg() {
  Serial.println("Send any command via this Serial interface to manually control the robot.");
  Serial.println("If you don't know the commands, please type 'help' (without the quotes).");
  Serial.flush();
}

void displayHelpText() {
  Serial.println("go_forward");
  Serial.println("go_backward");
  Serial.println("stop_moving");
  Serial.println("both_motors_speed=");
  Serial.println("left_motor_speed=");
  Serial.println("right_motor_speed=");
  Serial.println("colors");
  Serial.println("distance");
  Serial.println("jarbas_forward");
  Serial.println("jarbas_backward");
  Serial.println("jarbas_delay=");
  Serial.flush();
}

void displayNotImplementedMsg() {
  Serial.println("This command is currently not implemented");
  Serial.flush();
}

void displayCommandNotFoundMsg() {
  Serial.println("Command not found");
  Serial.flush();
}

/*
go_forward
go_backward
stop_moving
both_motors_speed=
left_motor_speed=
right_motor_speed=
colors
distance
jarbas_forward
jarbas_backward
*/
