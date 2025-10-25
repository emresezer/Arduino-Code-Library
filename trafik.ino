int kirmizi = 13;
int sari = 12;
int yesil = 11;

void setup() {
  pinMode(kirmizi, OUTPUT);
  pinMode(sari, OUTPUT);
  pinMode(yesil, OUTPUT);
}

void loop() {
  // Kırmızı ışık
  digitalWrite(kirmizi, HIGH);
  digitalWrite(sari, LOW);
  digitalWrite(yesil, LOW);
  delay(5000);

  // Sarı ışık
  digitalWrite(kirmizi, LOW);
  digitalWrite(sari, HIGH);
  digitalWrite(yesil, LOW);
  delay(2000);

  // Yeşil ışık
  digitalWrite(kirmizi, LOW);
  digitalWrite(sari, LOW);
  digitalWrite(yesil, HIGH);
  delay(5000);
}
