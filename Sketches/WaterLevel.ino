#define SENSOR_PIN  A0
#define LED_YELLOW  9   // Low
#define LED_GREEN   10  // Average
#define LED_RED     11  // High

// Calibration values — adjust based on your sensor
#define LOW_THRESHOLD     300
#define HIGH_THRESHOLD    600

int readWaterLevel() {
  return analogRead(SENSOR_PIN);
}

const char* getLevel(int raw) {
  if (raw < LOW_THRESHOLD)  return "Low";
  if (raw < HIGH_THRESHOLD) return "Average";
  return "High";
}

void setLEDs(const char* level) {
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN,  LOW);
  digitalWrite(LED_RED,    LOW);

  if (strcmp(level, "Low") == 0)     digitalWrite(LED_YELLOW, HIGH);
  else if (strcmp(level, "Average") == 0) digitalWrite(LED_GREEN, HIGH);
  else                               digitalWrite(LED_RED, HIGH);
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN,  OUTPUT);
  pinMode(LED_RED,    OUTPUT);
}

void loop() {
  int raw = readWaterLevel();
  const char* level = getLevel(raw);

  setLEDs(level);

  Serial.print("Raw: ");
  Serial.print(raw);
  Serial.print(" | Level: ");
  Serial.println(level);

  delay(500);
}
