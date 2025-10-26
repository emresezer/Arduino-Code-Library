/*
Nihâvend Longa (Kemani Kevser Hanım düzenlemesi)


Gerekli Malzemeler:
| Malzeme          | Adet | Açıklama            |
|------------------|------|---------------------|
| Arduino Uno/Nano | 1    | Mikrodenetleyici    |
| Piezo Buzzer     | 1    | Pasif önerilir      |
| Jumper Kablo     | 2    | Bağlantı için       |
| Breadboard       | 1    | Devre kurmak için   |

🔌 Bağlantılar:
| Buzzer Ucu      | Arduino Pini |
|-----------------|--------------|
| + (Uzun bacak)  | 8            |
| - (Kısa bacak)  | GND          |

====================================================
*/

#define NOTE_A3 220
#define NOTE_B3 246
#define NOTE_C4 261
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 493
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_G5 784
#define REST 0

int buzzer = 8;

// Nihâvend Longa - sadeleştirilmiş melodi
int melody[] = {
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_B3, REST,
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_B3, REST,
  NOTE_A3, NOTE_A3, NOTE_B3, NOTE_A3, NOTE_G3, NOTE_E3, REST,
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_B3, REST
};

// nota süreleri (4 = çeyrek, 8 = sekizlik)
int noteDurations[] = {
  8,8,8,8,4,8,4,4,
  8,8,8,8,4,8,4,4,
  8,8,8,8,4,8,4,
  8,8,8,8,4,4
};

void setup() {
  for (int thisNote = 0; thisNote < 28; thisNote++) {
    int duration = 1000 / noteDurations[thisNote];
    int note = melody[thisNote];
    if (note == REST) {
      delay(duration);
    } else {
      tone(buzzer, note, duration);
    }
    delay(duration * 1.3);
    noTone(buzzer);
  }
}

void loop() {
  // Müzik yalnızca bir kez çalacak
}
