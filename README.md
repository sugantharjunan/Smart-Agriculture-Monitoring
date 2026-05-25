# IoT-Based Smart Irrigation and Environmental Monitoring System

An IoT-based Smart Irrigation and Environmental Monitoring System using **Arduino UNO**, **ESP8266 NodeMCU**, **DHT11 Sensor**, **Rain Sensor**, **Soil Moisture Sensor**, and **ThingSpeak Cloud** for real-time monitoring and automated irrigation control.

---

## 📌 Project Overview

This project is designed to monitor environmental conditions and automate irrigation using IoT technology. The system continuously measures:

* 🌡️ Temperature
* 💧 Humidity
* 🌧️ Rain Detection
* 🌱 Soil Moisture

The Arduino UNO collects sensor data and sends it to the ESP8266 through serial communication. The ESP8266 uploads the sensor values to the **ThingSpeak Cloud Platform** for real-time monitoring.

The system can also control a water pump automatically based on soil moisture and rain conditions.

---

## 🚀 Features

* Real-time temperature monitoring
* Humidity monitoring
* Rain detection system
* Soil moisture monitoring
* Automatic irrigation control
* ThingSpeak cloud integration
* Wireless IoT monitoring using ESP8266
* Serial communication between Arduino and ESP8266
* Low-cost smart farming solution

---

## 🛠️ Components Used

| Component                           | Quantity    |
| ----------------------------------- | ----------- |
| Arduino UNO                         | 1           |
| ESP8266 NodeMCU                     | 1           |
| DHT11 Temperature & Humidity Sensor | 1           |
| Rain Sensor Module                  | 1           |
| Soil Moisture Sensor                | 1           |
| Relay Module                        | 1           |
| Water Pump                          | 1           |
| Jumper Wires                        | As required |
| Breadboard / PCB                    | 1           |

---

# 📂 Project Structure

```text id="8szd86"
├── ARDUINO.ino
├── ESP8266.ino
└── README.md
```

---

# ⚙️ Working Principle

## Arduino UNO Side

The Arduino UNO performs the following tasks:

* Reads temperature and humidity from the DHT11 sensor
* Detects rain status
* Monitors soil moisture condition
* Sends all sensor values to ESP8266 through serial communication
* Controls the relay-based water pump

### Sensor Data Format

```text id="h1b4sf"
temperature,humidity,rain,soil
```

Example:

```text id="e91s8k"
32.5,65.0,0,1
```

---

## ESP8266 Side

The ESP8266 performs the following operations:

* Connects to Wi-Fi
* Receives serial data from Arduino UNO
* Extracts sensor values
* Uploads data to ThingSpeak cloud using HTTP requests

---

# 📡 ThingSpeak Fields

| Field   | Sensor Data   |
| ------- | ------------- |
| Field 1 | Temperature   |
| Field 2 | Humidity      |
| Field 3 | Rain Sensor   |
| Field 4 | Soil Moisture |

---

# 🔌 Circuit Connections

## DHT11 Sensor

| DHT11 Pin | Arduino UNO   |
| --------- | ------------- |
| VCC       | 5V            |
| GND       | GND           |
| DATA      | Digital Pin 2 |

---

## Rain Sensor

| Rain Sensor | Arduino UNO   |
| ----------- | ------------- |
| VCC         | 5V            |
| GND         | GND           |
| DO          | Digital Pin 3 |

---

## Soil Moisture Sensor

| Soil Sensor | Arduino UNO   |
| ----------- | ------------- |
| VCC         | 5V            |
| GND         | GND           |
| DO          | Digital Pin 4 |

---

## Relay Module & Pump

| Relay | Arduino UNO   |
| ----- | ------------- |
| IN    | Digital Pin 5 |
| VCC   | 5V            |
| GND   | GND           |

---

## ESP8266 Communication

| ESP8266 | Arduino UNO |
| ------- | ----------- |
| TX      | RX          |
| RX      | TX          |
| GND     | GND         |

---

# 💻 Software Requirements

* Arduino IDE
* ESP8266 Board Package
* ThingSpeak Account

---

# 📚 Required Libraries

Install the following libraries in Arduino IDE:

## Arduino UNO

```cpp
DHT.h
```

## ESP8266

```cpp
ESP8266WiFi.h
```

---

# 🌐 Wi-Fi Configuration

Update your Wi-Fi credentials inside `ESP8266.ino`

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
```

---

# 🔑 ThingSpeak Configuration

Replace your API key with your own ThingSpeak Write API Key.

```cpp
String apiKey = "YOUR_API_KEY";
```

---

# ▶️ How to Run

1. Install Arduino IDE
2. Install required libraries
3. Upload `ARDUINO.ino` to Arduino UNO
4. Upload `ESP8266.ino` to ESP8266 NodeMCU
5. Connect sensors properly
6. Open ThingSpeak dashboard
7. Monitor live sensor data

---

# 📈 Applications

* Smart Irrigation System
* Precision Agriculture
* Greenhouse Monitoring
* Environmental Monitoring
* Water Conservation System
* IoT Farming Solutions

---

# 🔮 Future Enhancements

* Mobile App Integration
* Automatic Pump Scheduling
* Firebase Integration
* Buzzer Alert System
* LCD/OLED Display
* AI-based Irrigation Prediction
* Solar Powered System

---

# 📷 Output

* Live environmental monitoring
* Real-time ThingSpeak graphs
* Automatic water pump control
* Wireless IoT-based farming system

---

# 📖 Conclusion

This project demonstrates a simple and efficient IoT-based smart irrigation and environmental monitoring system using Arduino UNO and ESP8266. The system helps in water conservation, remote monitoring, and automated irrigation, making it useful for modern agriculture and smart farming applications.

