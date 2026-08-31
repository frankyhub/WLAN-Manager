/*************************************************************************************************
                                      PROGRAMMINFO
**************************************************************************************************
Funktion: ESP32 SPIFFS formatieren
**************************************************************************************************
Version: 31.08.2026
**************************************************************************************************
Board: ESP32vn IoT UNO V1.0.6
**************************************************************************************************
C++ Arduino IDE V1.8.13
**************************************************************************************************
Einstellungen:
https://dl.espressif.com/dl/package_esp32_index.json
http://dan.drown.org/stm32duino/package_STM32duino_index.json
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json
**************************************************************************************************
1. Strg+K Ordner auswaehlen
2. ESP32 Sketch Data Upload
3. Hochladen
4. Mit dem Seriellen Monitor testen
**************************************************************************************************/
#include "SPIFFS.h"
 
void listAllFiles(){
 
  File root = SPIFFS.open("/");
 
  File file = root.openNextFile();
 
  while(file){
 
      Serial.print("FILE: ");
      Serial.println(file.name());
 
      file = root.openNextFile();
  }
 
}
 
void setup() {
 
  Serial.begin(115200);
 
  if (!SPIFFS.begin(true)) {
    Serial.println("Beim Start von SPIFFS ist ein Fehler aufgetreten");
    return;
  }
 
  Serial.println("\n\n----Dateien vor dem Formatieren auflisten----");
  listAllFiles();
 
  bool formatted = SPIFFS.format();
 
  if(formatted){
    Serial.println("\n\nErfolgreiche Formatierung");
  }else{
    Serial.println("\n\nFehler beim Formatieren");
  }
 
  Serial.println("\n\n----Dateien nach dem Formatieren auflisten----");
  listAllFiles();
}
 
void loop() {}
