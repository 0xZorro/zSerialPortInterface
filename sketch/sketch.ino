// ============================================
// Arduino LED Controller for zSerialPortInterface
// ============================================
// Author: Jose Luis Ocana (GitHub: 0xZorro)
// Created: 2025-04-09
// Description: Listens to serial input from PC and controls the brightness of
//              red, green, blue, and yellow LEDs via PWM. Supports commands
//              like 'r128', 'g255', and 'x0' for shutdown on exit.
//
// License: MIT License (see LICENSE file for details)
// Version: 1.0
// Repository: https://github.com/0xZorro/SerialPortInterface
// ============================================

// Define PWM output pins for each LED
const int BLUE_PIN = 3;
const int GREEN_PIN = 5;
const int YELLOW_PIN = 6;
const int RED_PIN = 9;

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);

  // Set all LED pins as OUTPUT
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
}

void loop() {
  // Check if data is available from serial
  if (Serial.available() > 0) {
    // Read the incoming string until newline character
    String input = Serial.readStringUntil('\n');

    // Input should have at least 2 characters (e.g. r128)
    if (input.length() >= 2) {
      char ledChar = input.charAt(0);            // First character defines the LED
      int brightness = input.substring(1).toInt(); // Rest is brightness value (0–255)

      // Clamp brightness to valid PWM range
      brightness = constrain(brightness, 0, 255);

      // Select LED based on the first character
      switch (ledChar) {
        case 'r':
          analogWrite(RED_PIN, brightness);
          break;
        case 'g':
          analogWrite(GREEN_PIN, brightness);
          break;
        case 'b':
          analogWrite(BLUE_PIN, brightness);
          break;
        case 'y':
          analogWrite(YELLOW_PIN, brightness);
          break;
        case 'x': // 'x0' = shutdown command from PC app
          analogWrite(RED_PIN, 0);
          analogWrite(GREEN_PIN, 0);
          analogWrite(BLUE_PIN, 0);
          analogWrite(YELLOW_PIN, 0);
          break;
        default:
          Serial.println("Invalid command.");
          return;
      }

      // Send confirmation back to PC
      Serial.print("OK: ");
      Serial.println(input);
    }
  }
}
