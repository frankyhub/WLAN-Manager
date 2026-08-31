/*************************************************************************************************
                                      PROGRAMMINFO
**************************************************************************************************
Funktion: ESP32 SPIFFS formatieren
**************************************************************************************************
Version: 30.05.2021
**************************************************************************************************
Board: ESP32 Dev Module
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
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  Serial.println("\n\n----Listing files before format----");
  listAllFiles();

 bool formatted = SPIFFS.format();

  if(formatted){
    Serial.println("\n\nSuccess formatting");
  }else{
    Serial.println("\n\nError formatting");
  }

  Serial.println("\n\n----Listing files after format----");
  listAllFiles();


}

void loop() {}
