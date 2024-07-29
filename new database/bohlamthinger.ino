#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Mengatur detail koneksi WiFi
char auth[] = "GqlNx-w-wddn7DmcVBqBgne0ZQdi7n2l";
char ssid[] = "Purnamah";
char pass[] = "123tuyul";

// Menggunakan pin D1 pada ESP8266 sebagai output kontrol relay
const int relayPin = D5;

void setup() {
 Serial.begin(9600);
  // Mengatur pin sebagai OUTPUT
  pinMode(relayPin, OUTPUT);

  // Menghubungkan ESP8266 ke jaringan WiFi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  // Menghubungkan ESP8266 ke Blynk
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  // Menjalankan Blynk untuk menangani koneksi dan perintah
  Blynk.run();
}

// Fungsi untuk mengendalikan relay melalui tombol di aplikasi Blynk
BLYNK_WRITE(V0) {
  int relayStatus = param.asInt();
  if (relayStatus == HIGH) {
    digitalWrite(relayPin, LOW);  // Menyalakan relay
  } else {
    digitalWrite(relayPin, HIGH);  // Mematikan relay
  }
}
