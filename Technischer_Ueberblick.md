# PWM und Analoge Ausgabe am Arduino – Technischer Überblick

## Was ist PWM (Pulsweitenmodulation)?

PWM (Pulsweitenmodulation) ist eine Technik, um analoge Spannungswerte mithilfe eines digitalen Ausgangs zu simulieren.  
Anstatt die Spannung kontinuierlich zu verändern, schaltet PWM das Signal mit einer festen Frequenz sehr schnell EIN und AUS.

Der **Tastgrad** (Duty Cycle) bestimmt dabei die effektive Ausgangsspannung:

- **0 % Tastgrad** → immer AUS → 0 V im Mittel
- **50 % Tastgrad** → halb EIN, halb AUS → ca. 2,5 V im Mittel
- **100 % Tastgrad** → immer EIN → 5 V im Mittel (bei typischem Arduino)

Obwohl die Spannung nur zwischen HIGH (5 V) und LOW (0 V) wechselt, erzeugt das schnelle Umschalten für angeschlossene Komponenten den Eindruck einer **geglätteten Durchschnittsspannung**.

---

## Was passiert elektrisch?

Beispiel: Eine LED ist an einem PWM-Ausgang angeschlossen:

- Ist der Pin 25 % der Zeit HIGH und 75 % LOW → LED leuchtet schwach
- Ist der Pin 75 % der Zeit HIGH → LED leuchtet deutlich heller

Das liegt daran, dass bei höherem Tastgrad **mehr Leistung** an die LED geliefert wird.

PWM-Signale sind im Grunde **Rechtecksignale**, aber für träge Lasten wie LEDs erscheint das Leuchten dem Auge als kontinuierlich.

---

## Visuelle Darstellung (Tastverhältnisse)

| Tastgrad | Beschreibung         | Ø Spannung (bei 5 V)       |
|----------|----------------------|-----------------------------|
| 0 %      | Immer AUS             | 0 V                         |
| 25 %     | Schwach               | ca. 1,25 V                  |
| 50 %     | Mittelhell            | ca. 2,5 V                   |
| 75 %     | Hell                  | ca. 3,75 V                  |
| 100 %    | Voll EIN              | 5 V                         |

---

## PWM glätten – nahezu echte Analogspannung

In manchen Anwendungen (z. B. Audio) kann das PWM-Signal durch einen **Tiefpassfilter** (Kondensator + Widerstand) geglättet werden.  
Das Ergebnis ist eine nahezu konstante Gleichspannung, entsprechend dem Tastgrad.

---

## PWM am Arduino – Was passiert im Hintergrund?

Die Arduino-Funktion `analogWrite(pin, wert)` setzt den PWM-Tastgrad:

- `wert` liegt zwischen 0 und 255
- Die Standardfrequenz für PWM-Pins beträgt ca. 490 Hz
- Auf den Pins 5 und 6 liegt sie oft bei ca. 980 Hz (bei Uno)

Beispiel:
```cpp
analogWrite(9, 128);  // ca. 50 % Tastgrad auf Pin 9
```

Hinweis: Obwohl die Funktion `analogWrite()` heißt, erzeugt sie **keine echte Analogspannung**, sondern ein digitales PWM-Signal.

---

## Welche Pins unterstützen PWM beim Arduino Uno?

Am Arduino Uno unterstützen folgende Pins PWM:

- **3, 5, 6, 9, 10, 11**

Sie sind meist mit einem `~` Symbol auf der Platine gekennzeichnet.

---

## Wie funktioniert es intern?

PWM wird intern mit **Hardware-Timern** im Mikrocontroller erzeugt.  
Diese erzeugen präzise Rechtecksignale unabhängig von deinem Programmlauf – zuverlässig und zeitgenau.

---

## Zusammenfassung

- PWM ist eine digitale Methode zur Simulation analoger Spannungen
- Anwendung z. B. in LED-Dimmung, Motorsteuerung, Audio, Kommunikation
- Arduino macht PWM mit `analogWrite()` einfach zugänglich
- Mit Filterung kann PWM in echte Gleichspannung überführt werden

PWM verbindet **digitale Steuerung mit analogem Verhalten** – ein fundamentales Werkzeug in der Embedded-Entwicklung.


Documentation written by: Jose Luis Ocana (GitHub: [0xZorro](https://github.com/0xZorro))  
Last updated: April 2025
