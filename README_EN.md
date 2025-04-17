<p align="center">
  <img src="Banner.png" alt="zSerialPortInterface" width="300"/>
</p>

# zSerialPortInterface

SerialPortInterface is a C++ application using the Windows API to communicate with an Arduino board via serial connection (COM port). The project allows users to control four individual LEDs (red, green, blue, yellow) connected to the Arduino by sending simple commands from the PC.

Unlike basic on/off switching, this project supports PWM (Pulse Width Modulation) control — allowing users to adjust the brightness of each LED by specifying a value between 0 and 255. For example, sending the command `r128` sets the red LED to 50% brightness.

Each command is acknowledged by the Arduino with a response signal sent back to the PC, ensuring reliable two-way communication.

The PC application also supports the special `exit` command to turn off all LEDs and close the connection cleanly.

This project is designed as a practical test environment for serial communication, LED control, and real-time interaction between software and hardware.

## Hardware Requirements

To run this project, you’ll need the following hardware components:

- **1x Arduino Uno** (or compatible board with PWM-capable pins)
- **1x USB cable** (to connect Arduino to the PC)
- **4x LEDs** (red, green, blue, yellow – or any colors of your choice)
- **4x 220Ω resistors** (for current limiting)
- **Breadboard and jumper wires** (for prototyping)
- **PC or Laptop** with a USB port and serial support

## Circuit Diagrams

This project includes two circuit representations for better understanding of the hardware setup:

1. **Schematic Diagram (PDF)** – A detailed and electrically accurate diagram showing all connections, pin labels, and resistor values.
2. **Breadboard View (PNG)** – A simplified, visual version of the setup, useful for a quick glance.

> Both diagrams were created using [Tinkercad Circuits](https://www.tinkercad.com/circuits) by Autodesk.

## Software Requirements

To run this project, you'll need:

### PC Side (Windows)
- **Visual Studio 2022** with C++ development tools
- No additional libraries or frameworks (uses native Windows API)
- Serial port access (e.g. COM5)

### Arduino Side
- **Arduino IDE**
- Arduino Uno board drivers

## Installation & Setup

1. Clone this repository:
   ```
   git clone https://github.com/0xZorro/SerialPortInterface.git
   ```

2. Open the `main.cpp` file from the `pc/` folder with Visual Studio 2022.

3. Create a new **Console App Project** in Visual Studio 2022.

4. Replace the auto-generated `main.cpp` in your project with the one from this repository.

5. Make sure the serial port name in the code (`COM5`) matches the port your Arduino is connected to.  
   You can check the correct port in the Arduino IDE under **Tools > Port**.

6. Build and run the application. The terminal will prompt you to enter commands like:
   - `r128` (red LED 50%)
   - `g255` (green LED full brightness)
   - `exit` (turn off all LEDs and quit)

7. Upload the Arduino sketch from the `arduino/` folder using the Arduino IDE.

8. Connect the hardware as shown in the circuit diagrams.

## Usage

Once the application is running and the Arduino is connected:

1. The console will prompt you to enter a command.
2. Type a command in the format `<letter><value>`, where:
   - `r` = red LED
   - `g` = green LED
   - `b` = blue LED
   - `y` = yellow LED
   - `<value>` = brightness between `0` (off) and `255` (full brightness)

### Examples:
- `r128` → sets red LED to 50% brightness
- `g255` → sets green LED to full brightness
- `b0` → turns blue LED off
- `y64` → sets yellow LED to low brightness
- `exit` → turns off all LEDs and exits the application

Each command is acknowledged by the Arduino via a short response code, which is displayed in the terminal.

> Make sure your COM port is correctly configured before starting the application.

## License

This project is licensed under the MIT License.  
See the [LICENSE](LICENSE) file for details.

## Author

Created by Jose Luis Ocana

Cybersecurity Learner | Python & C++ Tools 

GitHub: [0xZorro](https://github.com/0xZorro) 

TryHackMe: [https://tryhackme.com/p/0xZorro](https://tryhackme.com/p/0xZorro) 

Contact: zorro.jose@gmx.de

Originally created for testing serial communication between PC and Arduino.

## Tools Used
- [Tinkercad Circuits](https://www.tinkercad.com/circuits) – for circuit diagrams
- Windows API (Win32)
- Arduino IDE
- Visual Studio 2022

---

<div align="center">
  <img src="brand.png" alt="by 0xZorro" width="120"/>
  <br/>
  <sub>© 2025 0xZorro</sub>
</div>

---
