/*
====================================================

Gerekli Malzemeler:
| Malzeme          | Adet | Açıklama            |
|------------------|------|---------------------|
| Arduino Uno/Nano | 1    | Mikrodenetleyici    |
| Piezo Buzzer     | 1    | Pasif önerilir      |
| Jumper Kablo     | 2    | Bağlantı için       |
| Breadboard       | 1    | Devre kurmak için   |

🔌 Bağlantılar:
| Buzzer Ucu      | Arduino Pini |
|-----------------|---------------|
| + (Uzun bacak)  | 8             |
| - (Kısa bacak)  | GND           |

====================================================
*/

#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988
#define REST 0

int buzzer = 8;

// 🎶 Hatırla Sevgili - sadeleştirilmiş melodi
int melody[] = {
  NOTE_E5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, REST,
  NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, REST,
  NOTE_E5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, REST,
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_E5
};

// nota süreleri (4 = çeyrek nota, 8 = sekizlik)
int noteDurations[] = {
  8,8,8,8,8,4,4,
  8,8,8,8,8,8,4,4,
  8,8,8,8,8,4,4,
  8,8,8,8,8,8,8,4
};

void setup() {
  for (int thisNote = 0; thisNote < 28; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    int note = melody[thisNote];
    if (note == REST) {
      delay(noteDuration);
    } else {
      tone(buzzer, note, noteDuration);
    }
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzer);
  }
}

void loop() {
  // Müzik bir kez çalacak.
}
