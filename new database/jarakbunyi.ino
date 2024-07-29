#include <Servo.h>

const int pirPin = D2;       // Pin PIR Sensor
const int greenLedPin = D6;   // Pin LED hijau //
const int redLedPin = D7;     // Pin LED merah
const int buzzerPin = D8;     // Pin Buzzer

Servo servo1;
Servo servo2;

void setup() {
    Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  servo1.attach(D4);  // Pin Servo 1
  servo2.attach(D1);  // Pin Servo 2
}

void loop() {
  int pirValue = digitalRead(pirPin);

  if (pirValue == HIGH) {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
      tone(buzzerPin, 1500); 
    openDoor();
  } else {
    closeDoor();
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
      noTone(buzzerPin);
  }
}

void openDoor() {
  servo1.write(180);  // Set posisi servo 1
  servo2.write(180);  // Set posisi servo 2

}

void closeDoor() {
  servo1.write(0);  // Set posisi servo 1
  servo2.write(0);  // Set posisi servo 2
 
    // Matikan buzzer
}
