/*************************************************************************************************
                                      PROGRAMMINFO
**************************************************************************************************
Funktion: WLAN Manager mit WEB Server
**************************************************************************************************
Version: 31.08.2026
**************************************************************************************************
Board: ESP32vn IoT UNO V1.0.6
**************************************************************************************************
Libraries:
WiFiManager (von tzapu) https://github.com/tzapu/wifimanager
FS und SPIFFS (standardmäßig in ESP32 Core enthalten)
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

const char* ssid     = "ESP32-Access-Point"; //SSID
const char* password = ""; //kein Passwort

WiFiServer server(80);

String header;

String output2State = "aus";

// GPIO pin
const int output2 = 2;

void initSPIFFS() {
  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS konnte nicht initialisiert werden!");
  } else {
    Serial.println("SPIFFS gestartet.");
  }
}

void connectWiFi() {
  WiFiManager wm;

  if (!wm.autoConnect("AccesPoint")) {
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

  pinMode(output2, OUTPUT);
  digitalWrite(output2, LOW);

  Serial.print("Setze Access Point…");

  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP Addresse: ");
  Serial.println(IP);
  
  server.begin();

}

void loop(){
  WiFiClient client = server.available();   // Liste Clients

  if (client) {                             
    Serial.println("Neuer Client.");          
    String currentLine = "";                
    while (client.connected()) {            
      if (client.available()) {             
        char c = client.read();             
        Serial.write(c);                   
        header += c;
        if (c == '\n') {                   
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // schaltet den GPIO ein und aus
            if (header.indexOf("GET /2/ein") >= 0) {
              Serial.println("GPIO 2 an");
              output2State = "ein";
              digitalWrite(output2, HIGH);
            } else if (header.indexOf("GET /2/aus") >= 0) {
              Serial.println("GPIO 2 aus");
              output2State = "aus";
              digitalWrite(output2, LOW);
                        }
            
            // Die HTML-Webseite anzeigen
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS zum gestalten der Ein-/Aus-Schalter
            // Du kannst die Hintergrundfarbe und die Schriftgröße nach Belieben ändern
            client.println("<style>html { font-family: Helvetica; display: inline-block; font-weight: bold; font-size: 30px; margin: 3px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            
            // Webseitenüberschrift
            client.println("<body><h1>ESP32 Web Server</h1>");
            
            // Aktuellen Zustand anzeigen und AN/AUS-Tasten für GPIO 2 - interne LED 
            client.println("<p>GPIO 2 interne LED - Status: " + output2State + "</p>");
            // Wenn der output2State aus ist, zeigt er den EIN-Button an       
            if (output2State=="aus") {
              client.println("<p><a href=\"/2/ein\"><button class=\"button\">Schalte EIN</button></a></p>");
            } else {
              client.println("<p><a href=\"/2/aus\"><button class=\"button button2\">Schalte AUS</button></a></p>");
            } 

            // Die HTTP-Antwort endet mit einer weiteren Leerzeile
            client.println();
            // While-Schleife ausbrechen
            break;
          } else { // wenn du einen Zeilenumbruch bekommst, dann lösche die aktuelle Zeile
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;      
        }
      }
    }
    // Die Header-Variable löschen
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client Verbindung getrennt.");
    Serial.println("");
  }
}
