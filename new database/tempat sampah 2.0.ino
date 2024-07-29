#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define trigPin 2
#define echoPin 3
#define servoPin 4

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(servoPin);
  lcd.init();
  lcd.backlight();
}

void loop() {
  long duration, cm;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = duration / 58;
  if (cm < 10) {
    myservo.write(270);
    lcd.setCursor(0,1);
    lcd.print("Garbage Open");
  } else {
    myservo.write(0);
    lcd.setCursor(0,1);
    lcd.print("Garbage Closed");
  }
  delay(500);
}
