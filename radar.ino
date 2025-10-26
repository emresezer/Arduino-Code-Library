/*
====================================================
 Kullanılan Malzemeler:
- Arduino Uno / Nano
- 1 Adet HC-SR04 Ultrasonik Mesafe Sensörü
- 3 Adet LED (uzaklık göstergesi)
- Jumper kablolar ve dirençler (220Ω önerilir)

 Bağlantılar:
 HC-SR04 Sensörü:
- VCC → 5V
- GND → GND
- TRIG → D10
- ECHO → D11

 LED Bağlantıları:
- LED1 → D5 (uzak mesafe)
- LED2 → D6 (orta mesafe)
- LED3 → D7 (yakın mesafe)
- Ortak uçlar → GND

 Açıklama:
- Mesafe sensörü, nesneye olan uzaklığı ölçer.
- Ölçülen mesafeye göre LED’ler yanar:
  - ≥ 25 cm → sadece LED1 yanar
  - 10 < mesafe < 25 cm → LED1 + LED2 yanar
  - ≤ 10 cm → tüm LED’ler yanar
- Seri monitöre mesafe değeri cm cinsinden yazdırılır.

====================================================
*/

#define trig 10
#define echo 11

long sure;
int mesafe;

// LED pinleri
int led1 = 5;
int led2 = 6;
int led3 = 7;

void setup() {
  Serial.begin(9600);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // Ultrasonik sinyal gönder
  digitalWrite(trig, HIGH);
  delay(1000);
  digitalWrite(trig, LOW);

  // Yankı süresini ölç
  sure = pulseIn(echo, HIGH);
  mesafe = (sure / 2) / 28.5;  // cm cinsinden mesafe hesaplama

  // Seri monitöre mesafe bilgisi yazdır
  Serial.print("Mesafe: ");
  Serial.print(mesafe);
  Serial.println(" cm");
  Serial.println("____");
  delay(300);

  // LED kontrolü
  if (mesafe >= 25) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } 
  else if (mesafe <= 24 && mesafe > 10) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  } 
  else if (mesafe <= 10) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }

  delay(10);
}
