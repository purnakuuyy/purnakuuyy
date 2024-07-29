

const int ledred = D5;
const int ledyellow = D6;
const int ledgreen = D7;
void setup() {
  // put your setup code here, to run once:    
pinMode(ledred, OUTPUT); 
pinMode(ledyellow, OUTPUT);
pinMode(ledgreen, OUTPUT);
}

void loop() {
 digitalWrite(ledred, HIGH);
digitalWrite(ledyellow, HIGH);
digitalWrite(ledgreen, HIGH);
delay(2000);   
 
  digitalWrite(ledred, LOW);
digitalWrite(ledyellow, LOW);
digitalWrite(ledgreen, HIGH);
delay(1000);   
  digitalWrite(ledred, LOW);
digitalWrite(ledyellow, HIGH);
digitalWrite(ledgreen, LOW);
delay(500);
  digitalWrite(ledred, HIGH);
digitalWrite(ledyellow, LOW);
digitalWrite(ledgreen, LOW);
delay(1000);
 digitalWrite(ledred, HIGH);
digitalWrite(ledyellow, HIGH);
digitalWrite(ledgreen, HIGH);
delay(2000);   
 
  digitalWrite(ledred, HIGH);
digitalWrite(ledyellow, LOW);
digitalWrite(ledgreen, LOW);
delay(1000);
  digitalWrite(ledred, LOW);
digitalWrite(ledyellow, HIGH);
digitalWrite(ledgreen, LOW);
delay(500);
  digitalWrite(ledred, LOW);
digitalWrite(ledyellow, LOW);
digitalWrite(ledgreen, HIGH);
delay(500);
  digitalWrite(ledred, HIGH);
digitalWrite(ledyellow, HIGH);
digitalWrite(ledgreen, HIGH);
delay(2000);
  digitalWrite(ledred, HIGH);
digitalWrite(ledyellow, LOW);
digitalWrite(ledgreen, LOW);
delay(1000);
digitalWrite(ledred, LOW);
digitalWrite(ledyellow, HIGH);
digitalWrite(ledgreen, LOW);
delay(500);
digitalWrite(ledred, LOW);
digitalWrite(ledyellow, HIGH);
digitalWrite(ledgreen, LOW);
delay(500);
digitalWrite(ledred, LOW);
digitalWrite(ledyellow,LOW);
digitalWrite(ledgreen, HIGH);
delay(1000);
}

