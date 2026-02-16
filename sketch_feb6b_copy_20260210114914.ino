#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ---------- WiFi ----------
#define WIFI_SSID "Jon iPhone 16"
#define WIFI_PASS "jon42027"

// ---------- ThingsBoard MQTT ----------
#define MQTT_SERVER "thingsboard.cloud"
#define MQTT_PORT 1883
#define MQTT_TOKEN "yd4iu4e72dpa1gi19kmp"

// ---------- Pins ----------
#define DHTPIN 15
#define DHTTYPE DHT22
#define RED_LED 5
#define RELAY_PIN 18

// ---------- Thresholds ----------
#define TEMP_DANGER 35.0

// ---------- Objects ----------
WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void connectWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void connectMQTT() {
  while (!client.connected()) {
    client.connect("ESP32", MQTT_TOKEN, NULL);
    delay(500);
  }
}

void setup() {
  Serial.begin(115200);
  delay(3000);   //cuz USB CDC needs time to enumerate
  Serial.println("ESP32-S2 booting...");

  pinMode(RED_LED, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RED_LED, LOW);
  digitalWrite(RELAY_PIN, LOW);

  Wire.begin(8, 9);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  dht.begin();
  connectWiFi();

  client.setServer(MQTT_SERVER, MQTT_PORT);
  connectMQTT();
}

void loop() {
  if (!client.connected()) connectMQTT();
  client.loop();

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) return;

  // ---------- Heat Logic ----------
  bool danger = temp >= TEMP_DANGER;

  digitalWrite(RED_LED, danger ? HIGH : LOW);
  digitalWrite(RELAY_PIN, danger ? HIGH : LOW);

  // ---------- OLED ----------
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Temp: "); display.print(temp); display.println(" C");
  display.print("Humidity: "); display.print(hum); display.println(" %");
  display.println(danger ? "STATUS: DANGER" : "STATUS: OK");
  display.display();

// ---------- MQTT Payload ----------
String payload = "{";
payload += "\"temperature\":" + String(temp, 2) + ",";
payload += "\"humidity\":" + String(hum, 2) + ",";
payload += "\"heatDanger\":" + String(danger ? "true" : "false");
payload += "}";

client.publish("v1/devices/me/telemetry", payload.c_str());


  delay(30000);
}


