/*
Harus terhubung sesuai (TIDAK MENYILANG)
SDA->SDA
SCL->SCL
SDA (Pin D21): Digunakan untuk komunikasi data I2C.
SCL (Pin D22): Digunakan untuk clock I2C.
LED built-in (Pin 2): Digunakan untuk menyalakan atau mematikan LED pada ESP32.
*/

#include <Wire.h>
#include <PS4Controller.h>

char ps4ButtonData = '\0'; // Data yang diterima dari PS4 controller

void setup() {
  Serial.begin(115200);  // Untuk komunikasi dengan Serial Monitor
  
  // Inisialisasi I2C Master dengan SDA=21, SCL=22 pada ESP32
  Wire.begin(21, 22);  // SDA pin 21, SCL pin 22 pada ESP32
  Serial.println("I2C Master ESP32 siap!");

  PS4.begin();
  Serial.println("PS4 Controller siap!");

  // Setup LED built-in (biasanya pin 2 pada ESP32)
  pinMode(2, OUTPUT);  // LED built-in pada pin 2 pada ESP32
}

void loop() {
  if (PS4.isConnected()) {
    // Periksa tombol PS4 dan kirim data ke STM32
    if (PS4.Right()) {
      ps4ButtonData = 'R'; // Tombol kanan
      digitalWrite(2, HIGH);  // Menyalakan LED saat tombol kanan ditekan
      Serial.println("Tombol Right Ditekan");
    } else if (PS4.Left()) {
      ps4ButtonData = 'L'; // Tombol kiri
      digitalWrite(2, HIGH);  // Menyalakan LED saat tombol kiri ditekan
      Serial.println("Tombol Left Ditekan");
    } else if (PS4.Up()) {
      ps4ButtonData = 'U'; // Tombol atas
      digitalWrite(2, HIGH);  // Menyalakan LED saat tombol atas ditekan
      Serial.println("Tombol Up Ditekan");
    } else if (PS4.Down()) {
      ps4ButtonData = 'D'; // Tombol bawah
      digitalWrite(2, HIGH);  // Menyalakan LED saat tombol bawah ditekan
      Serial.println("Tombol Down Ditekan");
    } else {
      ps4ButtonData = 'O'; // Tidak ada tombol yang ditekan
      digitalWrite(2, LOW);  // Mematikan LED jika tidak ada tombol yang ditekan
      Serial.println("Tidak ada tombol yang ditekan");
    }

    // Kirim data ke STM32 via I2C
    Wire.beginTransmission(0x4);  // Alamat I2C Slave STM32
    Wire.write(ps4ButtonData);    // Kirim data tombol
    Wire.endTransmission();       // Akhiri transmisi
    Serial.print("Data dikirim ke STM32: ");
    Serial.println(ps4ButtonData);
  }

  delay(100);
}
