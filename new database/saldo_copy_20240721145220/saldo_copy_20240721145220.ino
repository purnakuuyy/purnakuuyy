#include <ESP8266WiFi.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <NewPing.h>

#define SS_PIN D2
#define RST_PIN D0
#define TRIGGER_PIN D1
#define ECHO_PIN D4
#define MAX_DISTANCE 200

const char* ssid = "Purnamah";
const char* password = "123tuyul";
const char* server = "localhost"; // Change to your server's address

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo myservo;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();
  myservo.attach(D2);
  myservo.write(0); // Ensure servo is closed

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

void loop() {
  // Check for RFID card
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    String uid = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      uid += String(mfrc522.uid.uidByte[i], HEX);
    }
    Serial.println("Card detected: " + uid);
    myservo.write(90); // Open servo
    
    if (WiFi.status() == WL_CONNECTED) {
      WiFiClient client;
      if (client.connect(server, 80)) {
        String url = "/log_event.php?uid=" + uid + "&price=14500";
        client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                     "Host: " + server + "\r\n" + 
                     "Connection: close\r\n\r\n");
        client.stop();
      }
    }
    delay(5000); // Keep servo open for 5 seconds
    myservo.write(0); // Close servo
  }

  // Check distance sensor
  unsigned int distance = sonar.ping_cm();
  if (distance > 0 && distance < 10) { // Adjust distance threshold as needed
    myservo.write(0); // Close servo
  }
}