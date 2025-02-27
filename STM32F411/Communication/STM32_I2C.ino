/*
Harus terhubung sesuai (TIDAK MENYILANG)
SDA->SDA
SCL->SCL
SDA (Pin PB7): Digunakan untuk komunikasi data I2C.
SCL (Pin PB6): Digunakan untuk clock I2C.
LED built-in (Pin PC13): Digunakan untuk menyalakan atau mematikan LED pada STM32.
*/

#include <Wire.h>

#define SLAVE_ADDRESS 0x4  // Alamat I2C Slave untuk STM32
#define LED_BUILTIN PC13   // Pin LED built-in STM32 (PC13)

char receivedChar = 0;  // Variabel untuk menyimpan data yang diterima

void setup() {
  Serial.begin(115200);  // Untuk komunikasi dengan Serial Monitor
  
  // Inisialisasi I2C sebagai Slave dengan alamat 0x4
  Wire.begin(SLAVE_ADDRESS);  // Gunakan pin SDA dan SCL default untuk STM32
  Wire.onReceive(receiveEvent);  // Callback untuk menerima data
  
  pinMode(LED_BUILTIN, OUTPUT);  // Setup LED built-in pada STM32
  Serial.println("STM32 siap menerima data via I2C.");
}

void loop() {
  // Periksa dan proses data yang diterima
  delay(100);
}

void receiveEvent(int bytes) {
  while (Wire.available()) {
    receivedChar = Wire.read();  // Membaca data dari Master (ESP32)
    Serial.print("Data diterima: ");
    Serial.println(receivedChar);

    // Menyalakan/mematikan LED berdasarkan tombol yang diterima
    if (receivedChar == 'U') {
      digitalWrite(LED_BUILTIN, LOW);  // Menyalakan LED untuk tombol 'U' (Up)
      Serial.println("LED Menyala (Up Button)");
    } else if (receivedChar == 'D') {
      digitalWrite(LED_BUILTIN, LOW);  // Menyalakan LED untuk tombol 'D' (Down)
      Serial.println("LED Menyala (Down Button)");
    } else {
      digitalWrite(LED_BUILTIN, HIGH);  // Mematikan LED jika tidak ada tombol yang diterima
      Serial.println("LED Mati");
    }
  }
}
