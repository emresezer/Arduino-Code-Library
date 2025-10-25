/*
====================================================

Gerekli Malzemeler:
| Malzeme         | Adet | Açıklama              |
|-----------------|------|-----------------------|
| Arduino Uno/Nano| 1    | Mikrodenetleyici      |
| Kırmızı LED     | 1    | Stop ışığı            |
| Sarı LED        | 1    | Uyarı ışığı           |
| Yeşil LED       | 1    | Geçiş ışığı           |
| 220Ω Direnç     | 3    | Her LED için seri bağlı|
| Jumper Kablo    | 6    | Bağlantılar için      |
| Breadboard      | 1    | Devre kurmak için     |

🔌 Bağlantılar:
| LED             | Arduino Pin | Direnç |
|-----------------|--------------|--------|
| Kırmızı LED (+) | 13           | 220Ω   |
| Sarı LED (+)    | 12           | 220Ω   |
| Yeşil LED (+)   | 11           | 220Ω   |
| LED’lerin (-) bacağı | GND     | —      |

====================================================
*/

int kirmizi = 13;
int sari = 12;
int yesil = 11;

void setup() {
  pinMode(kirmizi, OUTPUT);
  pinMode(sari, OUTPUT);
  pinMode(yesil, OUTPUT);
}

void loop() {
  // Kırmızı ışık (Dur)
  digitalWrite(kirmizi, HIGH);
  digitalWrite(sari, LOW);
  digitalWrite(yesil, LOW);
  delay(5000);

  // Sarı ışık (Hazır ol)
  digitalWrite(kirmizi, LOW);
  digitalWrite(sari, HIGH);
  digitalWrite(yesil, LOW);
  delay(2000);

  // Yeşil ışık (Geç)
  digitalWrite(kirmizi, LOW);
  digitalWrite(sari, LOW);
  digitalWrite(yesil, HIGH);
  delay(5000);
}
