#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  // Mulai komunikasi serial
  Serial.begin(115200);
  // Mulai komunikasi I2C
  Wire.begin();
  
  // Inisialisasi sensor MPU6050
  Serial.println("Inisialisasi MPU6050...");
  mpu.initialize();
  
  // Cek apakah MPU6050 terhubung dengan benar
  if (mpu.testConnection()) {
    Serial.println("MPU6050 terhubung dengan benar.");
  } else {
    Serial.println("Gagal terhubung ke MPU6050.");
    while (1);
  }
}

void loop() {
  // Membaca data akselerometer dan gyroscope
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  
  // Membaca akselerasi dan data gyroscope
  mpu.getAcceleration(&ax, &ay, &az);
  mpu.getRotation(&gx, &gy, &gz);
  
  // Menampilkan data ke serial monitor
  Serial.print("Akselerasi X: "); Serial.print(ax);
  Serial.print(" | Akselerasi Y: "); Serial.print(ay);
  Serial.print(" | Akselerasi Z: "); Serial.println(az);
  
  Serial.print("Gyroscope X: "); Serial.print(gx);
  Serial.print(" | Gyroscope Y: "); Serial.print(gy);
  Serial.print(" | Gyroscope Z: "); Serial.println(gz);
  
  // Delay sebentar untuk stabilisasi
  delay(500);
}
