/*************************************************************************************************
                                      PROGRAMMINFO
**************************************************************************************************
Funktion: WLAN Manager ohne WEB Server

**************************************************************************************************
Version: 31.08.2026
**************************************************************************************************
Board: ESP32vn IoT UNO V1.0.6
**************************************************************************************************
Libraries:
WiFiManager (von tzapu) https://github.com/tzapu/wifimanager
SPIFFS
**************************************************************************************************
C++ Arduino IDE V1.8.19

**************************************************************************************************
Einstellungen:
https://dl.espressif.com/dl/package_esp32_index.json
http://dan.drown.org/stm32duino/package_STM32duino_index.json
http://arduino.esp8266.com/stable/package_esp8266com_index.json
**************************************************************************************************/
#include <Arduino.h>
#include <WiFiManager.h>         // Librarie für Access Point Manager https://github.com/tzapu/wifimanager
#include <FS.h>
#include <SPIFFS.h>



void initSPIFFS() {
  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS konnte nicht initialisiert werden!");
  } else {
    Serial.println("SPIFFS gestartet.");
  }
}

void connectWiFi() {
  WiFiManager wm;

  if (!wm.autoConnect("AccessPoint")) {
    Serial.println("Keine Verbindung möglich, starte neu...");
    delay(3000);
    ESP.restart();
  }

  Serial.print("Verbunden mit: ");
  Serial.println(WiFi.SSID());
  Serial.print("IP-Adresse: ");
  Serial.println(WiFi.localIP());
}


void setup() {
  Serial.begin(115200);

  initSPIFFS();
  connectWiFi();


}

void loop() {
  delay(500);
}
