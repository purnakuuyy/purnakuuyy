#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int soilMoisturePin = A0;
const int redLEDPin = D5;
const int greenLEDPin = D4;
const int relayPin = D3; // Pin relay yang mengontrol pompa

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  
  pinMode(soilMoisturePin, INPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(relayPin, OUTPUT); // Set pin relay sebagai OUTPUT
}

void loop() {
  int soilMoistureValue = analogRead(soilMoisturePin);
  
  if (soilMoistureValue < 1000) {
    digitalWrite(redLEDPin, HIGH);  // Tanah kering (indikator merah menyala)
    digitalWrite(greenLEDPin, LOW);
    digitalWrite(relayPin, HIGH);    // Menyalakan pompa melalui relay saat tanah kering
  } else {
    digitalWrite(redLEDPin, LOW);   // Tanah lembab (indikator hijau menyala)
    digitalWrite(greenLEDPin, HIGH);
    digitalWrite(relayPin, LOW);     // Mematikan pompa melalui relay saat tanah lembab
  }
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Status Tanah:   ");
  if (soilMoistureValue < 1000) {
    lcd.setCursor(0, 1);
    lcd.print("Tanah Lembab");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("Tanah kering");
  }
  
  delay(1000); // Baca kelembaban tanah setiap detik
}

