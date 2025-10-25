/*
====================================================
- 3 LED: led1, led2, led3
- 5 Buton: btn1 - btn5
- Potansiyometre: A0
- Fonksiyonlar:
  1: Hepsini aç
  2: Hepsini kapat
  3: Sırayla yakıp söndür
  4: 1. LED
  5: 2. LED
  6: 3. LED
  7: Potansiyometreye geçiş
====================================================
*/

const int led1 = 2;
const int led2 = 3;
const int led3 = 4;

const int btn1 = 5;
const int btn2 = 6;
const int btn3 = 7;
const int btn4 = 8;
const int btn5 = 9;
const int btn6 = 10; // 3. LED
const int btn7 = 11; // potansiyometre modu

const int potPin = A0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(btn4, INPUT_PULLUP);
  pinMode(btn5, INPUT_PULLUP);
  pinMode(btn6, INPUT_PULLUP);
  pinMode(btn7, INPUT_PULLUP);
}

void loop() {
  // Butonlar aktif düşük (INPUT_PULLUP)

  if (digitalRead(btn1) == LOW) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  else if (digitalRead(btn2) == LOW) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  else if (digitalRead(btn3) == LOW) {
    // LED’leri sırayla yakıp söndür
    digitalWrite(led1, HIGH);
    delay(300);
    digitalWrite(led2, HIGH);
    delay(300);
    digitalWrite(led3, HIGH);
    delay(300);
    digitalWrite(led1, LOW);
    delay(300);
    digitalWrite(led2, LOW);
    delay(300);
    digitalWrite(led3, LOW);
    delay(300);
  }
  else if (digitalRead(btn4) == LOW) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  else if (digitalRead(btn5) == LOW) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }
  else if (digitalRead(btn6) == LOW) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  }
  else if (digitalRead(btn7) == LOW) {
    int potVal = analogRead(potPin);
    if (potVal < 341) { // düşük
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    }
    else if (potVal < 682) { // orta
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
    }
    else { // yüksek
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
    }
  }
}
