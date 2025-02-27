/*
Harus terhubung MENYILANG 
TX->RX
RX->TX
TX (Pin PA9): Digunakan untuk komunikasi data UART.
RX (Pin PA10): Digunakan untuk clock UART.
LED built-in (Pin PC13): Digunakan untuk menyalakan atau mematikan LED pada STM32.
*/

char receivedChar = 0;  // Variabel untuk menyimpan data yang diterima

// Pin LED built-in pada STM32 (misalnya PC13)
#define LED_BUILTIN PC13

void setup() {
  Serial.begin(115200);  // Untuk komunikasi dengan Serial Monitor
  Serial1.begin(9600);  // UART1 dengan RX = PA10, TX = PA9 pada STM32
  pinMode(LED_BUILTIN, OUTPUT);  // Setup LED built-in pada STM32
  Serial.println("STM32 siap menerima data via Serial.");
}

void loop() {
  // Periksa jika ada data yang diterima di UART
  if (Serial1.available()) {
    receivedChar = Serial1.read();  // Membaca data dari Serial (TX dari ESP32)
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

  delay(100);
}
