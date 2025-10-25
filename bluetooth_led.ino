/*
====================================================
- LED: ledPin
- HC-05 Bluetooth modülü ile seri haberleşme
- Kod:
   '1' → LED yanar
   '2' → LED söner
====================================================
*/

const int ledPin = 13; // LED Arduino üzerinde
char incomingChar;     // Gelen veri için değişken

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // HC-05 varsayılan baudrate
}

void loop() {
  if (Serial.available() > 0) {
    incomingChar = Serial.read();
    
    if (incomingChar == '1') {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
    }
    else if (incomingChar == '2') {
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
    }
  }
}
