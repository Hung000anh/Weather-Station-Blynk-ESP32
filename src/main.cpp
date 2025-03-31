
#define DHTPIN 21      // Chân kết nối DHT22
#define DHTTYPE DHT22 // Loại cảm biến
#define BLYNK_TEMPLATE_ID "TMPL6EFuIC96E"
#define BLYNK_TEMPLATE_NAME "weather station 2"
#define BLYNK_AUTH_TOKEN "VkWpRCRZGQIJSWO84pJwIYVW-TN8n3T6"

#include <DHT.h>
#include <WiFi.h>
#include <Arduino.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";
char auth[] = BLYNK_AUTH_TOKEN;

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  // Debug console
  Serial.begin(115200);
  delay(1000);
  Blynk.begin(auth, ssid, pass);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature(); // Đọc nhiệt độ
  float humidity = dht.readHumidity();

  Serial.print("Nhiệt độ: ");
  Serial.print(temp);
  Serial.println("°C");
  Serial.print("Độ Ẩm: ");
  Serial.print(humidity);
  Serial.println("%");

  Blynk.virtualWrite(V1, temp); // Gửi dữ liệu nhiệt độ đến V1
  Blynk.virtualWrite(V0, humidity); // Gửi dữ liệu độ ẩm đến V0
  delay(1000);
}