/*
====================================================
 Kullanılan Malzemeler:
- Arduino Uno / Nano
- 2 DC Motor (L298N ile)
- HC-05 Bluetooth Modül
- Jumper kablolar ve robot şasi

 Bağlantılar:
 L298N Motor Sürücü:
- IN1 → D2
- IN2 → D3
- IN3 → D4
- IN4 → D5
- ENA → D6 (PWM Motor A)
- ENB → D7 (PWM Motor B)
- Motor güç girişleri: Robot bataryası ile
- GND → Arduino GND

 HC-05 Bluetooth:
- TX → Arduino RX
- RX → Arduino TX (Seviye düşürücü önerilir)
- VCC → 5V
- GND → GND

 Telefon Uygulaması:
- Bluedut veya başka Bluetooth seri terminal app
- Gönderilecek karakterler:
  'F' → ileri
  'B' → geri
  'L' → sola
  'R' → sağa
  'S' → dur
====================================================
*/

const int in1 = 2;
const int in2 = 3;
const int enA = 6;
const int in3 = 4;
const int in4 = 5;
const int enB = 7;

char command;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);

  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  Serial.begin(9600); // HC-05 baud rate
}

void loop() {
  if(Serial.available()){
    command = Serial.read();
    command = toupper(command);

    switch(command){
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'L': turnLeft(); break;
      case 'R': turnRight(); break;
      case 'S': stopMotors(); break;
    }
  }
}

// Motor fonksiyonları
void forward(){
  analogWrite(enA, 200);
  analogWrite(enB, 200);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void backward(){
  analogWrite(enA, 200);
  analogWrite(enB, 200);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnLeft(){
  analogWrite(enA, 200);
  analogWrite(enB, 200);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight(){
  analogWrite(enA, 200);
  analogWrite(enB, 200);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopMotors(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
