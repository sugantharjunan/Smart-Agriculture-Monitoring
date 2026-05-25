#include <ESP8266WiFi.h>

const char* ssid = "suganth";
const char* password = "*Suganth345";
const char* server = "api.thingspeak.com";
String apiKey = "LZ211VN4IVEHOTRU";

WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    data.trim();
    
    int firstComma = data.indexOf(",");
    int secondComma = data.indexOf(",", firstComma + 1);
    int thirdComma = data.indexOf(",", secondComma + 1);

    float temperature = data.substring(0, firstComma).toFloat();
    float humidity = data.substring(firstComma + 1, secondComma).toFloat();
    int rain = data.substring(secondComma + 1, thirdComma).toInt();
    int soil = data.substring(thirdComma + 1).toInt();

    if (client.connect(server, 80)) {
      String url = "/update?api_key=" + apiKey;
      url += "&field1=" + String(temperature);
      url += "&field2=" + String(humidity);
      url += "&field3=" + String(rain);
      url += "&field4=" + String(soil);

      client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                   "Host: " + server + "\r\n" +
                   "Connection: close\r\n\r\n");
      client.stop();
    }
  }
  delay(2000);
}