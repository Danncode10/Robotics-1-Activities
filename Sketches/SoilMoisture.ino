#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define SENSOR_PIN A0

// Calibration values — adjust based on your sensor in dry/wet soil
#define DRY_VALUE 850
#define WET_VALUE 300

LiquidCrystal_I2C lcd(0x27, 16, 2);

int readMoisture() { return analogRead(SENSOR_PIN); }

int toPercent(int raw) {
  int percent = map(raw, DRY_VALUE, WET_VALUE, 0, 100);
  return constrain(percent, 0, 100);
}

const char *getStatus(int percent) {
  if (percent < 30)
    return "Dry";
  if (percent < 70)
    return "Moist";
  return "Wet";
}

void displayMoisture(int percent, const char *status) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(percent);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Status: ");
  lcd.print(status);
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture");
  delay(1500);
}

void loop() {
  int raw = readMoisture();
  int percent = toPercent(raw);
  const char *status = getStatus(percent);

  displayMoisture(percent, status);

  Serial.print("Raw: ");
  Serial.print(raw);
  Serial.print(" | Moisture: ");
  Serial.print(percent);
  Serial.print("% | Status: ");
  Serial.println(status);

  delay(1000);
}
