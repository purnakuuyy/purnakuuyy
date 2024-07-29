#define THINGER_SERIAL_DEBUG
#include <ThingerESP8266.h>
#define user "Purnama"
#define device_id "ohmganteng"
#define credential "123tuyul"
#define SSID "Purnama's Galaxy M51"
#define pass "123i0T12"
ThingerESP8266 thing (user,device_id,credential);
#include <Servo.h>
#define trigPin D4
#define echoPin D6
#define LED1 D8
#define LED2 D7
#define LED3 D1
Servo srv;
void setup() {
srv.attach(D3); 
  pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
Serial.begin(115200);
thing.add_wifi(SSID, pass);
thing ["TEST"] << digitalPin(LED1);
}

void loop() {
  // put your main code here, to run repeatedly:
  thing.handle();
digitalWrite(trigPin, LOW);
delayMicroseconds(10);
digitalWrite(trigPin, HIGH);
delayMicroseconds(20);
long waktu = pulseIn(echoPin, HIGH);
float cm = waktu/58;
  if (cm < 10){
    srv.write(180);
    digitalWrite(LED1, HIGH);
     digitalWrite(LED3, LOW);
      digitalWrite(LED2, LOW);
     delay(1000);
  }
  if(cm = 12){
      digitalWrite(LED1, LOW);
     digitalWrite(LED3, HIGH);
          digitalWrite(LED2, LOW);
     delay(1000);
  }
   if (cm > 10){
    srv.write(0);
    digitalWrite(LED1, LOW);
     digitalWrite(LED3, LOW);
      digitalWrite(LED2, HIGH);
     delay(1000);
  }
}
