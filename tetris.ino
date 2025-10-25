/*
====================================================

Gerekli Malzemeler:
| Malzeme         | Adet | Açıklama           |
|-----------------|------|--------------------|
| Arduino Uno/Nano| 1    | Mikrodenetleyici   |
| Piezo Buzzer    | 1    | Ses çıkışı         |
| Jumper Kablo    | 2    | Bağlantı için      |
| Breadboard      | 1    | Devre kurmak için  |

🔌 Bağlantılar:
| Buzzer Ucu     | Arduino Pini |
|----------------|---------------|
| + (Uzun bacak) | 8             |
| - (Kısa bacak) | GND           |

====================================================
*/

#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988

int buzzer = 8;

// Tetris (Korobeiniki) ana tema melodisi
int melody[] = {
  NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4,
  NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_C5,
  NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_A4, 0,
  NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_C5,
  NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_B4, 0
};

// Nota süreleri (4 = çeyrek nota, 8 = sekizlik nota)
int noteDurations[] = {
  8, 8, 8, 8, 8, 8, 4,
  8, 8, 4, 8, 8, 8, 8,
  8, 4, 8, 8, 4, 8,
  8, 8, 4, 8, 8, 8, 8,
  8, 4, 8, 8, 4, 8
};

void setup() {
  for (int thisNote = 0; thisNote < 34; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzer, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzer);
  }
}

void loop() {
  // Müzik yalnızca bir kez çalacak.
}
