#define trig 10
#define echo 11
long sure;
int mesafe;
int led1 = 5;
int led2 = 6;
int led3 = 7;
void setup() {
  Serial.begin(9600);
  pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
digitalWrite(trig, HIGH);
  delay(1000);
  digitalWrite(trig, LOW);

  sure = pulseIn(echo, HIGH);
  mesafe = (sure/2) / 28.5;
    Serial.print("Mesafe: ");
  Serial.println(mesafe);
   Serial.println("____");
   delay(300);
 

if( mesafe >= 25 ){
  digitalWrite( led1 , HIGH); 
  digitalWrite(led2, LOW); 
  digitalWrite(led3, LOW); 
}
   if (mesafe <=24 && mesafe >10) {
    digitalWrite(led1, HIGH);
    digitalWrite (led2, HIGH);
    digitalWrite(led3, LOW); 
    
  }
  if (mesafe <=10 ) {
    digitalWrite(led1, HIGH);
    digitalWrite (led2, HIGH);
    digitalWrite(led3, HIGH); 
    
  }
  delay(10);
}
