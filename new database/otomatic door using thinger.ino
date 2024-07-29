#define THINGER_SERIAL_DEBUG
#include <ThingerESP8266.h>
#define user "Purnama"
#define device_id "ohmganteng"
#define credential "123tuyul"
#define SSID "Ruang Kelas Lt.2"
#define pass ""
ThingerESP8266 thing (user,device_id,credential);
#define LED1 D8
#include <Servo.h>
#define trigPin D4
#define echoPin D6
Servo srv;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
thing.add_wifi(SSID, pass);
thing ["TEST"] << digitalPin(LED1);
  pinMode(LED1, OUTPUT);
   digitalWrite(LED1, HIGH);
   delay(1000);
srv.attach(D3); 
  pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
thing["ultra"] >>[] (pson& out){
digitalWrite(trigPin, LOW);
delayMicroseconds(10);
digitalWrite(trigPin, HIGH);
delayMicroseconds(20);
long waktu = pulseIn(echoPin, HIGH);
float jarak = waktu/58;
out ["Jarak"] = jarak;
};
}


void loop() {
  // put your main code here, to run repeatedly:
thing.handle();
}
