/*
====================================================

Hans Zimmer - Interstellar

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
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define REST 0

int buzzer = 8;

// Interstellar - "Stay" giriş melodisi (sadeleştirilmiş)
int melody[] = {
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, REST,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_FS4, NOTE_E4, REST,
  NOTE_E4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, REST,
  NOTE_D4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4
};

// nota süreleri (4 = çeyrek, 8 = sekizlik)
int noteDurations[] = {
  8,8,8,8,4,8,4,
  8,8,8,8,4,4,
  8,8,8,8,4,8,4,
  8,8,8,8,4,4
};

void setup() {
  for (int thisNote = 0; thisNote < 26; thisNote++) {
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
  // Müzik bir kez çalacak
}
