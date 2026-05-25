#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define RAIN_SENSOR 3
#define SOIL_MOISTURE_SENSOR 4
#define PUMP_PIN 5  // Relay connected to pin 5

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(RAIN_SENSOR, INPUT);
  pinMode(SOIL_MOISTURE_SENSOR, INPUT);
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, LOW);  // Ensure pump is off initially
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int rain = digitalRead(RAIN_SENSOR);
  int soil = digitalRead(SOIL_MOISTURE_SENSOR);

  // Sending Data to ESP8266
  Serial.print(temperature); Serial.print(",");
  Serial.print(humidity); Serial.print(",");
  Serial.print(rain); Serial.print(",");
  Serial.print(soil);
  Serial.println();

  // Receive pump control command from ESP8266
  if (Serial.available()) {
    char command = Serial.read();
    if (command == '1') digitalWrite(PUMP_PIN, HIGH); // Turn ON pump
    else if (command == '0') digitalWrite(PUMP_PIN, LOW); // Turn OFF pump
  }

  delay(2000);
}