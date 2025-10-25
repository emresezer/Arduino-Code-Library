/*
====================================================
 Kullanılan Malzemeler:
- Arduino Uno / Nano
- 2 DC Motor (L298N ile)
- 2 adet IR çizgi sensörü (Sol ve Sağ)
- L298N Motor Sürücü
- Jumper kablolar, robot şasi

 Bağlantılar:

 IR Sensörler:
- Sol Sensör → A0
- Sağ Sensör → A1

 L298N Motor Sürücü:
- IN1 → D2
- IN2 → D3
- IN3 → D4
- IN4 → D5
- ENA → D6 (PWM Motor A)
- ENB → D7 (PWM Motor B)

 Açıklama:
- Sol ve sağ sensörler çizgi üzerindeyse LOW döner.
- Hız önemli değil, motorlar yavaş hareket edecek (PWM 150).
====================================================
*/

#define leftSensor A0
#define rightSensor A1

#define enA 6
#define in1 2
#define in2 3
#define enB 7
#define in3 4
#define in4 5

void setup(){
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);

  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
}

void loop(){
  int leftVal = digitalRead(leftSensor);
  int rightVal = digitalRead(rightSensor);

  // Her iki sensör çizgi üzerinde → ileri
  if(leftVal == LOW && rightVal == LOW){
    forward();
  }
  // Sol sensör çizgi üzerinde, sağ sensör beyaz → sağa dön
  else if(leftVal == LOW && rightVal == HIGH){
    turnRight();
  }
  // Sağ sensör çizgi üzerinde, sol sensör beyaz → sola dön
  else if(leftVal == HIGH && rightVal == LOW){
    turnLeft();
  }
  // Hiçbiri çizgi üzerinde → dur
  else{
    stopMotors();
  }
}

void forward(){
  analogWrite(enA, 150);
  analogWrite(enB, 150);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnLeft(){
  analogWrite(enA, 100);
  analogWrite(enB, 100);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight(){
  analogWrite(enA, 100);
  analogWrite(enB, 100);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopMotors(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
