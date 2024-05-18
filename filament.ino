void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  //A0 is analog first PIN reading value from pull down potentiometer
  int readVal = analogRead(A0);
  //Passing analog read value to Int between 0 and 9 using ternary operator
  readVal = readVal > 1000 ? 9 : floor(readVal / 100);
  numByInt(readVal);
  Serial.println(readVal);
}

/**
 * Define what filament need be active by boolean params
 * @note params name should be the same of the filament!
 * @note make sure you have linked right pins ex: a == 2, b == 3
 */
void num(bool a, bool b, bool c, bool d, bool e, bool f, bool g) {
  digitalWrite(2, a ? HIGH : LOW);
  digitalWrite(3, b ? HIGH : LOW);
  digitalWrite(4, c ? HIGH : LOW);
  digitalWrite(5, d ? HIGH : LOW);
  digitalWrite(6, e ? HIGH : LOW);
  digitalWrite(7, f ? HIGH : LOW);
  digitalWrite(8, g ? HIGH : LOW);
}

/**
 * Num by int using switch to define filaments need to be active
 */
void numByInt(int n) {
  switch (n) {
    case 0:
      num(true, true, true, true, true, true, false);
      break;
    case 1:
      num(false, true, true, false, false, false, false);
      break;
    case 2:
      num(true, true, false, true, true, false, true);
      break;
    case 3:
      num(true, true, true, true, false, false, true);
      break;
    case 4:
      num(false, true, true, false, false, true, true);
      break;
    case 5:
      num(true, false, true, true, false, true, true);
      break;
    case 6:
      num(true, false, true, true, true, true, true);
      break;
    case 7:
      num(true, true, true, false, false, false, false);
      break;
    case 8:
      num(true, true, true, true, true, true, true);
      break;
    case 9:
      num(true, true, true, true, false, true, true);
      break;
  }
}
