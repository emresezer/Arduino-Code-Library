// Tetris (Korobeiniki) Melody for Buzzer
// Captain Emre Sezer - DUTlab Edition

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

// Melodi notaları (Tetris ana teması)
int melody[] = {
  E5, B4, C5, D5, C5, B4, A4,
  A4, C5, E5, D5, C5, B4, C5,
  D5, E5, C5, A4, A4, 0,
  D5, F5, A5, G5, F5, E5, C5,
  E5, D5, C5, B4, B4, 0
};

// Her notanın süresi (4 = çeyrek nota, 8 = sekizlik nota vb.)
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
  // Müzik sadece bir kez çalacak
}
