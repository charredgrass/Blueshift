const int NINE = 9;
const int TEN = 10;
const int ELEVEN = 11;
const int THIRTEEN = 13;

void setup() {
  pinMode(NINE, OUTPUT);
  pinMode(TEN, OUTPUT);
  pinMode(ELEVEN, OUTPUT);
  pinMode(THIRTEEN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Blueshift initialized.");
}

void loop() {
  float distance = analogRead(A0) * .0048828125;
  //use actual distance in switch statement
  if (distance >= 4.98) {
    Serial.println("Distance Sensor is goin' whack.");
    digitalWrite(THIRTEEN, HIGH);
  } else {
    digitalWrite(THIRTEEN, LOW);
  }
  if (inBetween(distance, 0, 1.0)) {
    setRGB(255, 0, 0);
  } else if (inBetween(distance, 1.0, 2.5)) {
    setRGB(0, 255, 0);
  } else if (inBetween(distance, 2.5, 4)) {
    setRGB(0, 255, propRange255(2.5, 4, distance));
  }
}

void setRGB(int red, int grn, int blu) {
  digitalWrite(NINE, red);
  digitalWrite(TEN, grn);
  digitalWrite(ELEVEN, blu);
}

bool inBetween(float num, float lower, float upper) {
  return (num >= lower && num < upper);
}

int propRange255(float low, float high, float val) {
  float thing = (val - low) / (high - low);
  return (int) (thing * 255);
}

