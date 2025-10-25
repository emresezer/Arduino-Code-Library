/*
====================================================
Kullanılan Malzemeler:
- Arduino Uno / Nano
- 2 DC Motor (L298N ile sürülecek)
- L298N Motor Sürücü
- HC-SR04 Ultrasonik Mesafe Sensörü
- Jumper kablolar ve robot şasi

🔌 Bağlantılar:

1️⃣ HC-SR04:
- VCC → 5V
- GND → GND
- Trig → D9
- Echo → D10

2️⃣ L298N Motor Sürücü:
- IN1 → D2
- IN2 → D3
- IN3 → D4
- IN4 → D5
- ENA → D6 (PWM, Motor A)
- ENB → D7 (PWM, Motor B)
- Motor güç girişleri: Robot bataryası ile
- GND → Arduino GND

💡 Açıklama:
- Robot ileri hareket eder.
- Ultrasonik sensör mesafe < 15 cm algılarsa, rastgele sağa veya sola dönerek çarpmayı önler.
- Motorlar L298N üzerinden PWM ile kontrol edilir.
====================================================
*/

#include <Arduino.h>

#define trigPin 9
#define echoPin 10

// Motor pinleri
#define enA 6
#define in1 2
#define in2 3
#define enB 7
#define in3 4
#define in4 5

long duration;
int distance;

void setup() {
  // Motor pinleri
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  // Ultrasonik
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
  randomSeed(analogRead(0)); // rastgele yön için
}

void loop() {
  distance = getDistance();

  if(distance > 15){ // ileri hareket
    forward();
  }
  else{
    // Engel var, rastgele yön seç
    int turn = random(0,2); // 0: sola, 1: sağa
    if(turn == 0){
      turnLeft();
      delay(500); // kısa dönüş
    } else {
      turnRight();
      delay(500);
    }
  }
}

int getDistance(){
  // Ultrasonik ölçüm
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // cm
  return distance;
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
