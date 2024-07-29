#include <WiFi.h>
#include <HTTPClient.h>
#include <Servo.h>

// Inisialisasi Servo
Servo servo1;
Servo servo2;

// Pin definisi untuk sensor ultrasonik
const int trigPin1 = 14;
const int echoPin1 = 27;
const int trigPin2 = 32;
const int echoPin2 = 33;

// Pin definisi untuk LED
const int ledHijauPin = 16;
const int ledMerahPin = 17;

// WiFi credentials
const char* ssid = "JENI CANTIK";
const char* password = "123tuyul12";

// Server PHP URL
const char* serverName = "http://localhost/insert.php";

// Fungsi untuk membaca jarak dari sensor ultrasonik
long readUltrasonic(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

void setup() {
  Serial.begin(115200);

  // Inisialisasi pin
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(ledHijauPin, OUTPUT);
  pinMode(ledMerahPin, OUTPUT);

  // Attach servo
  servo1.attach(26);
  servo2.attach(25);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  long distance1 = readUltrasonic(trigPin1, echoPin1);
  long distance2 = readUltrasonic(trigPin2, echoPin2);

  if (distance1 < 10) { // Sesuaikan jarak sesuai kebutuhan
    // Sensor 1 high: buka pintu, nyalakan LED hijau
    servo1.write(90);  // Adjust angle as needed
    digitalWrite(ledHijauPin, HIGH);
    digitalWrite(ledMerahPin, LOW);

    // Kirim data ke server
    sendDataToServer("open");
  } else if (distance2 < 10) { // Sesuaikan jarak sesuai kebutuhan
    // Sensor 2 high: tutup pintu, nyalakan LED merah
    servo1.write(0);  // Adjust angle as needed
    digitalWrite(ledHijauPin, LOW);
    digitalWrite(ledMerahPin, HIGH);

    // Kirim data ke server
    sendDataToServer("close");
  }

  delay(1000); // Delay untuk mencegah pembacaan berulang terlalu cepat
}

void sendDataToServer(String status) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = serverName + "?status=" + status;
    http.begin(url);
    int httpResponseCode = http.GET();
    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.print("Error on sending GET: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
}
