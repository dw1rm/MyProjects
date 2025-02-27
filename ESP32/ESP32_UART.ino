/*
Harus terhubung MENYILANG 
TX->RX
RX->TX
RX (Pin D16): Digunakan untuk komunikasi data UART.
TX (Pin D17): Digunakan untuk clock UART.
LED built-in (Pin 2): Digunakan untuk menyalakan atau mematikan LED pada ESP32.
*/

#include <PS4Controller.h>

char ps4ButtonData = '\0'; // Data yang diterima dari PS4 controller

void setup() {
  Serial.begin(115200);  // Untuk komunikasi dengan Serial Monitor
  Serial2.begin(9600, SERIAL_8N1, 16, 17);  // UART2 dengan RX = 16, TX = 17 pada ESP32

  PS4.begin();
  Serial.println("PS4 Controller siap!");

  // Setup LED built-in (biasanya pin 2 pada ESP32)
  pinMode(2, OUTPUT);  // LED built-in pada ESP32
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

    // Kirim data ke STM32 via Serial (TX)
    Serial2.write(ps4ButtonData);  // Kirim data ke STM32 melalui UART2
    Serial.print("Data dikirim ke STM32: ");
    Serial.println(ps4ButtonData);
  }

  delay(100);
}
