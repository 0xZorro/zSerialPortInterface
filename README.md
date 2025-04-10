# zSerialPortInterface

**zSerialPortInterface** ist eine C++-Anwendung, die über die Windows-API mit einem Arduino-Board per serieller Schnittstelle (COM-Port) kommuniziert.  
Das Projekt ermöglicht es, vier LEDs (rot, grün, blau, gelb) am Arduino zu steuern – durch einfache Kommandos, die vom PC gesendet werden.

Im Gegensatz zu einfacher Ein-/Aus-Schaltung unterstützt dieses Projekt auch **PWM (Pulsweitenmodulation)** – so kann die Helligkeit jeder LED durch einen Wert zwischen 0 und 255 eingestellt werden.  
Beispiel: `r128` stellt die rote LED auf 50 % Helligkeit.

Jedes Kommando wird vom Arduino mit einem Antwortsignal bestätigt – für eine zuverlässige bidirektionale Kommunikation.

Zusätzlich unterstützt die PC-Anwendung das Kommando `exit`, um alle LEDs auszuschalten und die Verbindung sauber zu beenden.

Dieses Projekt dient als praktische Testumgebung für serielle Kommunikation, LED-Steuerung und Interaktion zwischen Software und Hardware in Echtzeit.

---

## Hardware-Anforderungen

Um dieses Projekt nutzen zu können, benötigst du folgende Komponenten:

- **1x Arduino Uno** (oder ein kompatibles Board mit PWM-fähigen Pins)
- **1x USB-Kabel** (zur Verbindung mit dem PC)
- **4x LEDs** (z. B. rot, grün, blau, gelb)
- **4x 220Ω Widerstände** (zur Strombegrenzung)
- **Breadboard und Jumper-Kabel** (für den Aufbau)
- **PC oder Laptop** mit USB-Anschluss

---

## Schaltpläne

Dieses Projekt enthält zwei Darstellungen der Schaltung zur besseren Übersicht:

- **Shematic Diagram (PDF)** – Eine technische, elektrische Zeichnung mit Pin-Belegung und Widerstandswerten
- **Breadboard View (PNG)** – Eine symbolische, vereinfachte Darstellung des Aufbaus

> Beide Darstellungen wurden mit **Tinkercad Circuits** von Autodesk erstellt.

---

## Software-Voraussetzungen

### Auf dem PC (Windows):
- **Visual Studio 2022** mit C++-Entwicklungstools
- Keine zusätzlichen Frameworks nötig (reine Windows API)
- Zugriff auf die serielle Schnittstelle (z. B. COM5)

### Auf dem Arduino:
- **Arduino IDE**
- Arduino Uno-Treiber

---

## Installation & Einrichtung

1. Klone dieses Repository:

```bash
git clone https://github.com/0xZorro/SerialPortInterface.git
```

2. Öffne die Datei `main.cpp` aus dem Ordner `pc/` mit **Visual Studio 2022**.

3. Erstelle ein neues Konsolenprojekt in Visual Studio 2022.

4. Ersetze die automatisch erzeugte `main.cpp` durch die Datei aus diesem Repository.

5. Stelle sicher, dass der COM-Port im Code (z. B. `"COM5"`) mit dem Port übereinstimmt, an dem dein Arduino angeschlossen ist.  
   Diesen findest du in der Arduino IDE unter **Werkzeuge > Port**.

6. Baue und starte das Projekt. Die Konsole fordert dich zur Eingabe von Kommandos auf, z. B.:

- `r128` (rote LED auf 50 % Helligkeit)
- `g255` (grüne LED volle Helligkeit)
- `exit` (alle LEDs aus und Anwendung beenden)

7. Lade den Arduino-Sketch aus dem Ordner `arduino/` mit der Arduino IDE hoch.

8. Verbinde die Hardware wie in den Schaltplänen dargestellt.

---

## Anwendung

Wenn die Anwendung läuft und das Arduino verbunden ist:

- Gib in der Konsole ein Kommando ein im Format `<Buchstabe><Wert>`, wobei:
  - `r` = rote LED
  - `g` = grüne LED
  - `b` = blaue LED
  - `y` = gelbe LED
  - `<Wert>` = Helligkeit zwischen `0` (aus) und `255` (volle Helligkeit)

### Beispiele:
- `r128` → rote LED auf 50 % Helligkeit
- `g255` → grüne LED volle Helligkeit
- `b0` → blaue LED ausschalten
- `y64` → gelbe LED auf niedrige Helligkeit
- `exit` → alle LEDs aus + Anwendung beenden

Jedes Kommando wird vom Arduino mit einer Rückmeldung bestätigt, die in der Konsole angezeigt wird.

> Achte darauf, dass der COM-Port korrekt eingestellt ist, bevor du das Programm startest.

---

## Lizenz

Dieses Projekt steht unter der MIT-Lizenz – siehe [LICENSE](LICENSE) für Details.

---

## Autor

**Created by Jose Luis Ocana**

Cybersecurity Learner | Python & C++ Tools

(GitHub: [0xZorro](https://github.com/0xZorro))  

TryHackMe: https://tryhackme.com/p/0xZorro

Contact: zorro.jose@gmx.de

Ursprünglich erstellt zur Testung serieller Kommunikation zwischen PC und Arduino.

---

## Verwendete Tools

- **Tinkercad Circuits** – für die Schaltplan-Erstellung  
- **Windows API (Win32)**  
- **Arduino IDE**  
- **Visual Studio 2022**
