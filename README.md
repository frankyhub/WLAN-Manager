<a name="oben"></a>

<div align="center">

|[:skull:ISSUE](https://github.com/frankyhub/WLAN-Manager/issues?q=is%3Aissue)|[:speech_balloon: Forum /Discussion](https://github.com/frankyhub/WLAN-Manager/discussions)|[:grey_question:WiKi](https://github.com/frankyhub/WLAN-Manager/wiki)||
|--|--|--|--|
| | | | |
|![Static Badge](https://img.shields.io/badge/RepoNr.:-%20121-blue)|<a href="https://github.com/frankyhub/WLAN-Manager/issues">![GitHub issues](https://img.shields.io/github/issues/frankyhub/WLAN-Manager)![GitHub closed issues](https://img.shields.io/github/issues-closed/frankyhub/WLAN-Manager)|<a href="https://github.com/frankyhub/WLAN-Manager/discussions">![GitHub Discussions](https://img.shields.io/github/discussions/frankyhub/WLAN-Manager)|<a href="https://github.com/frankyhub/WLAN-Manager/releases">![GitHub release (with filter)](https://img.shields.io/github/v/release/frankyhub/WLAN-Manager)|
|![GitHub Created At](https://img.shields.io/github/created-at/frankyhub/WLAN-Manager)| <a href="https://github.com/frankyhub/WLAN-Manager/pulse" alt="Activity"><img src="https://img.shields.io/github/commit-activity/m/badges/shields" />| <a href="https://github.com/frankyhub/WLAN-Manager/graphs/traffic"><img alt="ViewCount" src="https://views.whatilearened.today/views/github/frankyhub/github-clone-count-badge.svg">  |<a href="https://github.com/frankyhub?tab=stars"> ![GitHub User's stars](https://img.shields.io/github/stars/frankyhub)|





---


## Story
Das Repo beinhaltet drei Programme für einen WLAN Manager. Das Programm "WLAN-Manager.ino" aktiviert einen WLAN-Manager ohne weitere Funktion. Das Programm eignet sich ideal für die Ergänzung eines eigenen Codes. 

Das Programm "WLAN-Manager_mit_WEB-Server.ino" beinhaltet zusätzlich einen WEB-Server als Beispiel. Mit dem Programm wird die interne LED mit GPIO 2 ein/ausgeschaltet.

Mit dem Programm "SPIFFS_formatieren.ino" wird das ESP32 Filesystem formatiert und die WLAN-Zugangsdaten gelöscht.

## In den WLAN Einstellungen den Access Point wählen 

![Bild](/pic/0wlan.png)

## und im Browser die Adresse 192.168.4.1 starten 

![Bild](/pic/1WiFiManager.png)

## anschließend die WLAN Daten SSID und Password eingeben

![Bild](/pic/2captivewlan.png)

## Sind die WLAN Daten korrekt, wir im seriellen Monitor die IP des WEB-Servers angezeigt

![Bild](/pic/seriel.png)

## Jetzt kann der WEB-Servers mit der angezeigten IP gestartet werden

![Bild](/pic/webserver.png)

## Die WLAN Daten können mit dem Programm "SPIFFS_formatieren.ino" gelöscht werden

![Bild](/pic/format.png)

---

<div style="position:absolute; left:2cm; ">   
<ol class="breadcrumb" style="border-top: 2px solid black;border-bottom:2px solid black; height: 45px; width: 900px;"> <p align="center"><a href="#oben">nach oben</a></p></ol>
</div>  

---
