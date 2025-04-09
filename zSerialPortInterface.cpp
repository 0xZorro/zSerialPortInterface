// ============================================
// zSerialPortInterface - Arduino LED Controller
// ============================================
// Author: Jose Luis Ocana (GitHub: 0xZorro)
// Created: 2025-04-09
// Description: A Windows API-based C++ tool to communicate with an Arduino
//              over a serial COM port. Sends PWM commands to control the
//              brightness of 4 LEDs (r, g, b, y) using text-based input.
//              Also supports 'exit' command to power off LEDs and close the port.
//
// License: MIT License (see LICENSE file for details)
// Version: 1.0
// Repository: https://github.com/0xZorro/SerialPortInterface
// ============================================

#include <windows.h>
#include <iostream>
#include <string>

int main() {
    // Open the serial port (e.g., COM3)
    HANDLE hSerial = CreateFileW(
        L"COM3",                     // Serial port name (wide string for Unicode)
        GENERIC_READ | GENERIC_WRITE, // Access mode: read and write
        0,                            // No sharing
        NULL,                         // Default security attributes
        OPEN_EXISTING,                // Open only if it exists
        0,                            // No special flags
        NULL                          // No template file
    );

    if (hSerial == INVALID_HANDLE_VALUE) {
        std::cerr << "Error opening serial port\n";
        return 1;
    }

    // Configure serial port parameters
    DCB dcbSerialParams = { 0 };
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    if (!GetCommState(hSerial, &dcbSerialParams)) {
        std::cerr << "Error getting port state\n";
        return 1;
    }

    dcbSerialParams.BaudRate = CBR_9600;   // Baud rate: 9600
    dcbSerialParams.ByteSize = 8;          // Data bits: 8
    dcbSerialParams.StopBits = ONESTOPBIT; // Stop bit: 1
    dcbSerialParams.Parity = NOPARITY;   // No parity

    if (!SetCommState(hSerial, &dcbSerialParams)) {
        std::cerr << "Error setting port state\n";
        return 1;
    }

    // Main communication loop
    std::string command;
    DWORD bytesWritten;

    while (true) {
        std::cout << "Enter command (e.g. r128, g255): ";
        std::getline(std::cin, command);

        // Exit condition
        if (command == "exit") {
            std::cout << "Turning off all LEDs and exiting...\n";

            // Send shutdown command to Arduino (e.g. x0)
            std::string shutdownCmd = "x0";
            WriteFile(hSerial, shutdownCmd.c_str(), shutdownCmd.size(), &bytesWritten, NULL);
            break;
        }

        if (command.empty()) continue;

        // Send command to Arduino
        if (!WriteFile(hSerial, command.c_str(), command.size(), &bytesWritten, NULL)) {
            std::cerr << "Write failed\n";
        }

        // Read response from Arduino
        char buffer[100];
        DWORD bytesRead;
        if (ReadFile(hSerial, buffer, sizeof(buffer) - 1, &bytesRead, NULL)) {
            buffer[bytesRead] = '\0'; // Null-terminate string
            std::cout << "Arduino: " << buffer << "\n";
        }
    }

    // Close the serial port (unreachable in this loop)
    CloseHandle(hSerial);
    return 0;
}
