#include <Arduino.h>
#include "DHT.h"

// Cấu hình chân kết nối và loại cảm biến
#define DHTPIN 4          // Chân Data của DHT22 nối vào GPIO4
#define DHTTYPE DHT22     // Khai báo loại cảm biến là DHT22

// Khởi tạo đối tượng DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Khởi tạo Serial với baud rate 115200 (Phù hợp với ESP32)
  Serial.begin(115200);
  delay(2000); 
  
  Serial.println(F("\n\n=== DHT22 Sensor Reading ==="));
  Serial.println(F("Reading temperature and humidity from DHT22 on GPIO4"));
  
  // Bắt đầu khởi chạy cảm biến
  dht.begin();
  Serial.println(F("Waiting for sensor to initialize..."));
}

void loop() {
  // DHT22 cần ít nhất 2 giây để cập nhật dữ liệu mới
  delay(2000);

  // Đọc độ ẩm (Humidity)
  float h = dht.readHumidity();
  // Đọc nhiệt độ độ C (Celsius)
  float t = dht.readTemperature();

  // Kiểm tra xem việc đọc dữ liệu có thành công không
  if (isnan(h) || isnan(t)) {
    Serial.println(F("✗ Failed to read from DHT sensor! Check wiring."));
    return;
  }

  // In kết quả ra Serial Monitor
  Serial.print(F("✓ Humidity: "));
  Serial.print(h);
  Serial.print(F("%  |  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C"));
}