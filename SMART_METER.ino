#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define VOLTAGE_PIN 34
#define CURRENT_PIN 35

LiquidCrystal_I2C lcd(0x27, 16, 2);

float voltage = 0;
float current = 0;
float power = 0;
float energy = 0;

unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();

  pinMode(VOLTAGE_PIN, INPUT);
  pinMode(CURRENT_PIN, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("Smart Energy");
  lcd.setCursor(0, 1);
  lcd.print("Meter");
  delay(2000);
  lcd.clear();
}

void loop() {

  int voltageADC = analogRead(VOLTAGE_PIN);
  int currentADC = analogRead(CURRENT_PIN);

  // Convert ADC values (Calibration Required)
  voltage = (voltageADC * 3.3 / 4095.0) * 75.0;
  current = ((currentADC * 3.3 / 4095.0) - 2.5) / 0.185;

  if (current < 0)
    current = -current;

  power = voltage * current;

  unsigned long currentMillis = millis();
  float hours = (currentMillis - previousMillis) / 3600000.0;
  energy += power * hours;

  previousMillis = currentMillis;

  lcd.setCursor(0, 0);
  lcd.print("V:");
  lcd.print(voltage, 1);
  lcd.print(" I:");
  lcd.print(current, 1);

  lcd.setCursor(0, 1);
  lcd.print("E:");
  lcd.print(energy / 1000.0, 3);
  lcd.print("kWh");

  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" V  Current: ");
  Serial.print(current);
  Serial.print(" A  Power: ");
  Serial.print(power);
  Serial.print(" W  Energy: ");
  Serial.print(energy / 1000.0);
  Serial.println(" kWh");

  delay(1000);
}
