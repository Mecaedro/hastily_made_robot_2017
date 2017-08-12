// TCS230 (GY-31) on the right
const byte r_s0  = 48;
const byte r_s1  = 49;
const byte r_s2  = 50;
const byte r_s3  = 51;
const byte r_out = 52;

// TCS230 (GY-31) on the left
const byte l_s0  = 22;
const byte l_s1  = 23;
const byte l_s2  = 24;
const byte l_s3  = 25;
const byte l_out = 26;

// Last detected input
int lastEv = -1; // 0=lgreen (turn lef)t, 1=rgreen (turn right), 2=lblack (turn right), 3=rblack (turn left)

// Values acquired in latest fetch
int l_red = 0;
int l_green = 0;
int l_blue = 0;
int l_clear = 0;
int r_red = 0;
int r_green = 0;
int r_blue = 0;
int r_clear = 0;

void setupColorSensorsPins() {
  // TCS230 (GY-31) on the right
  pinMode(r_s0, OUTPUT);
  pinMode(r_s1, OUTPUT);
  pinMode(r_s2, OUTPUT);
  pinMode(r_s3, OUTPUT);
  pinMode(r_out, INPUT);

  // TSC230 (GY-31) on the left
  pinMode(l_s0, OUTPUT);
  pinMode(l_s1, OUTPUT);
  pinMode(l_s2, OUTPUT);
  pinMode(l_s3, OUTPUT);
  pinMode(l_out, INPUT);

  // Set both sensors frequency scaling to 20%
  /*
   * H=HIGH, L=LOW;
   * LL = power down
   * LH = 2%
   * HL = 20%
   * HH = 100%;
   *
   */
  digitalWrite(l_s0, HIGH);
  digitalWrite(l_s1, LOW);
  digitalWrite(r_s0, HIGH);
  digitalWrite(r_s1, LOW);
}

void getColorsFromLeftSensor() {
  // Get red photodiodes value
  digitalWrite(l_s2, LOW);
  digitalWrite(l_s3, LOW);
  l_red = pulseIn(l_out, digitalRead(l_out) == HIGH ? LOW : HIGH);

  // Get blue photodiodes value
  digitalWrite(l_s2, LOW);
  digitalWrite(l_s3, HIGH);
  l_blue = pulseIn(l_out, digitalRead(l_out) == HIGH ? LOW : HIGH);

  // Get clear photodiodes value
  digitalWrite(l_s2, HIGH);
  digitalWrite(l_s3, LOW);
  l_clear = pulseIn(l_out, digitalRead(l_out) == HIGH ? LOW : HIGH);

  // Get green photodiodes value
  digitalWrite(l_s2, HIGH);
  digitalWrite(l_s3, HIGH);
  l_green = pulseIn(l_out, digitalRead(l_out) == HIGH ? LOW : HIGH);
}

void getColorsFromRightSensor() {
  // Get red photodiodes value
  digitalWrite(r_s2, LOW);
  digitalWrite(r_s3, LOW);
  r_red = pulseIn(r_out, digitalRead(r_out) == HIGH ? LOW : HIGH);

  // Get blue photodiodes value
  digitalWrite(r_s2, LOW);
  digitalWrite(r_s3, HIGH);
  r_blue = pulseIn(r_out, digitalRead(r_out) == HIGH ? LOW : HIGH);

  // Get clear photodiodes value
  digitalWrite(r_s2, HIGH);
  digitalWrite(r_s3, LOW);
  r_clear = pulseIn(r_out, digitalRead(r_out) == HIGH ? LOW : HIGH);

  // Get green photodiodes value
  digitalWrite(r_s2, HIGH);
  digitalWrite(r_s3, HIGH);
  r_green = pulseIn(r_out, digitalRead(r_out) == HIGH ? LOW : HIGH);
}

void updateColorSensorsValues() {
  getColorsFromLeftSensor();
  getColorsFromRightSensor();
}

void displayColorSensorsValues() {
  String left_rgb = String("left:  rgb(") + String(l_red) + String(", ") + String(l_green) + String(", ") + String(l_blue) + String("), clarity=" + String(l_clear));
  String right_rgb = String("right: rgb(") + String(r_red) + String(", ") + String(r_green) + String(", ") + String(r_blue) + String("), clarity=" + String(r_clear));

  Serial.println(left_rgb);
  Serial.println(right_rgb);

  Serial.flush();
}

bool leftSensorIndicatesGreen() {
  if(l_green > 70 && l_green < 91) {
    lastEv = 0;
    return true;
  }

  return false;
}

bool rightSensorIndicatesGreen() {
  if(l_green > 70 && l_green < 86) {{
    lastEv = 1;
    return true;
  }

  return false;
}

bool leftSensorIndicatesBlack() {
  if(l_red > 94) {
    lastEv = 2;
    return true;
  }

  return false;
}

bool rightSensorIndicatesBlack() {
  if(l_red > 90) {
    lastEv = 3;
    return true;
  }

  return false;
}
