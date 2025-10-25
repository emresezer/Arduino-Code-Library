/*
====================================================
 Kullanılan Malzemeler:
- Arduino Uno / Nano
- 6 Servo Motor (Robot kol eksenleri için)
- 6 Piezo Buzzer (her eksen için bir)
- Jumper kablolar ve robot kol mekanizması

 Açıklama:
- Her buzzer belirli bir ton ürettiğinde, o eksen hareket eder.
- Basit kontrol: Her eksen, buzzer tonuna göre belirli bir açıda pozisyon alır.
- Bu örnek, tone → servo açısı mantığı ile çalışır.
====================================================
*/

#include <Servo.h>

// Servo motor pinleri
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

const int servoPins[] = {2,3,4,5,6,7}; // servo pinleri
const int buzzerPins[] = {8,9,10,11,12,13}; // buzzer pinleri

void setup() {
  // Servoları ata
  servo1.attach(servoPins[0]);
  servo2.attach(servoPins[1]);
  servo3.attach(servoPins[2]);
  servo4.attach(servoPins[3]);
  servo5.attach(servoPins[4]);
  servo6.attach(servoPins[5]);

  // Buzzer pinleri çıkış
  for(int i=0;i<6;i++){
    pinMode(buzzerPins[i], OUTPUT);
  }
}

void loop() {
  // Örnek: her buzzer basıldığında servo hareketi
  // Bu örnekte buzzer tone üretiyor, manuel basım simülasyonu

  for(int i=0;i<6;i++){
    tone(buzzerPins[i], 1000+i*200, 500); // Her buzzer farklı ton
    delay(500); // 0.5 saniye bekle

    // Ton sonrası servo açısını değiştir
    int angle = random(0,180); // örnek rastgele pozisyon
    switch(i){
      case 0: servo1.write(angle); break;
      case 1: servo2.write(angle); break;
      case 2: servo3.write(angle); break;
      case 3: servo4.write(angle); break;
      case 4: servo5.write(angle); break;
      case 5: servo6.write(angle); break;
    }

    delay(500);
    noTone(buzzerPins[i]); // ton kapat
  }
}
