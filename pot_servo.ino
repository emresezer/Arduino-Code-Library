/*
====================================================
 Kullanılan Malzemeler:
- Arduino Uno / Nano
- 1 Adet Servo Motor
- 1 Adet Potansiyometre
- Jumper Kablolar

🔌 Bağlantılar:
- Potansiyometre orta pin → A0
- Potansiyometre uç pinleri → 5V ve GND
- Servo sinyal pini → D12
- Servo güç → 5V
- Servo GND → GND

 Açıklama:
- Potansiyometreden okunan analog değer (0–1023 arası),
  servo motorun açısına (0°–180°) dönüştürülür.
- Servo motor, potansiyometreyi çevirdikçe konum değiştirir.
- Seri Monitör üzerinden servo açısı izlenebilir.

Seri Monitör:
  "Değer= 90" gibi çıktılar üretir.

====================================================
*/

#include <Servo.h>

long sure;
int mesafe;
Servo servom1;

int pot = A0;       // Potansiyometre girişi
int potDeger;       // Okunan pot değeri (0-1023)

void setup() {
  servom1.attach(12);   // Servo sinyal pini
  Serial.begin(9600);   // Seri iletişim başlat
}

void loop() {
  // Potansiyometreden okunan değeri servo açısına çevir
  potDeger = analogRead(pot);
  potDeger = map(potDeger, 0, 1023, 0, 180);

  // Servo konumunu ayarla
  servom1.write(potDeger);

  // Seri monitöre değeri yazdır
  Serial.print("Değer= ");
  Serial.println(potDeger);

  delay(10);  // Küçük bir gecikme
}
