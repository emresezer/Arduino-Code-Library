/*
====================================================
Kullanılan Malzemeler:
- Arduino Uno / Nano
- HC-05 Bluetooth modülü
- BME280 sensör (Basınç, Sıcaklık, Nem)
- Jumper kablolar, breadboard

🔌 Bağlantılar:
- BME280 VCC → 3.3V veya 5V
- BME280 GND → GND
- BME280 SDA → A4 (Arduino Uno)
- BME280 SCL → A5 (Arduino Uno)
- HC-05 TX → Arduino RX
- HC-05 RX → Arduino TX (Seviye düşürücü önerilir)
- HC-05 VCC → 5V
- HC-05 GND → GND

📱 Telefon Uygulaması:
- BluEdut (https://play.google.com/store/apps/details?id=bluedut.dutlab.app&hl=tr)

💡 Açıklama:
- Arduino BME280’den sıcaklık, nem ve basınç verilerini okur.
- HC-05 üzerinden Bluetooth ile telefona gönderir.
- BluEdut uygulaması ile verileri gerçek zamanlı görüntüleyebilirsiniz.
- Veriler format olarak CSV veya okunabilir metin halinde gönderilir.
====================================================
*/

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME280 bme; // I2C kullanıyoruz

void setup() {
  Serial.begin(9600); // HC-05 baudrate
  if (!bme.begin(0x76)) {  // Sensör adresi 0x76 veya 0x77 olabilir
    Serial.println("BME280 bulunamadı! Lütfen bağlantıları kontrol edin.");
    while (1);
  }
}

void loop() {
  float temperature = bme.readTemperature(); // °C
  float humidity = bme.readHumidity();       // %
  float pressure = bme.readPressure() / 100.0F; // hPa

  // Bluetooth üzerinden gönder
  Serial.print("Sicaklik: ");
  Serial.print(temperature);
  Serial.print(" C, ");
  
  Serial.print("Nem: ");
  Serial.print(humidity);
  Serial.print(" %, ");
  
  Serial.print("Basinc: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  delay(2000); // 2 saniye aralıklarla veri gönder
}
