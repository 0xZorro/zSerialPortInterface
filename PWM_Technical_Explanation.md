# PWM and Analog Output on Arduino – A Technical Overview

## What is PWM (Pulse Width Modulation)?

PWM (Pulse Width Modulation) is a technique used to simulate analog voltage levels using a digital output.  
Instead of varying the actual voltage, PWM rapidly switches the signal ON and OFF at a fixed frequency.

The **duty cycle** of this signal determines the effective output:

- **0% duty cycle** → Always OFF → 0V average
- **50% duty cycle** → ON half the time → ~2.5V average
- **100% duty cycle** → Always ON → 5V average (on typical Arduino)

Although the voltage is either HIGH (5V) or LOW (0V), the rapid toggling tricks components into perceiving a **smoothed average voltage**.

---

## What Happens Electrically?

Let's take an LED as the load on a PWM pin:

- If the pin is HIGH for 25% of the time and LOW for 75%, the LED is dimly lit
- If the pin is HIGH for 75%, the LED is much brighter

This is because the **average power** delivered is higher at a higher duty cycle.

PWM signals are essentially **square waves**, but for slow-reacting loads (like LEDs), the human eye integrates the flashes and sees a consistent brightness.

---

## Visual Representation (Duty Cycles)

| Duty Cycle | Description        | Approx. Avg Voltage (5V) |
|------------|--------------------|---------------------------|
| 0%         | Always OFF          | 0V                        |
| 25%        | Dim                 | ~1.25V                    |
| 50%        | Medium brightness   | ~2.5V                     |
| 75%        | Bright              | ~3.75V                    |
| 100%       | Fully ON            | 5V                        |

---

## Filtering the PWM – Smooth Analog Output

In some cases, especially for sensitive analog electronics (like audio or DAC simulation), PWM can be passed through a **low-pass filter** (capacitor + resistor) to smooth the signal.

This gives a nearly constant DC voltage corresponding to the duty cycle.

---

## PWM on Arduino – Behind the Scenes

Arduino's `analogWrite(pin, value)` function sets the PWM duty cycle:
- `value` ranges from 0 to 255
- The default frequency for most PWM pins is ~490 Hz
- Pins 5 and 6 often use ~980 Hz (on Uno)

Example:
```cpp
analogWrite(9, 128);  // ~50% duty cycle on pin 9
```

Note: Even though it's called `analogWrite()`, it does **not** produce a true analog voltage – just a digital PWM signal.

---

## Which Arduino Pins Support PWM?

On the Arduino Uno, the following pins support PWM:

- **3, 5, 6, 9, 10, 11**

You can recognize them by the `~` symbol next to their number on the board silkscreen.

---

## How Does It Work Internally?

PWM is usually implemented using **hardware timers** on the microcontroller. These generate consistent square wave signals with high timing accuracy, independent of your code’s execution.

---

## Summary

- PWM is a digital technique to simulate analog voltages
- Used in LED dimming, motor control, audio, and communication
- Arduino makes PWM easy with `analogWrite()`
- Filtering can convert PWM to real analog voltage

PWM is an essential technique for combining **digital control with analog behavior** – a fundamental tool in embedded systems.

Documentation written by: Jose Luis Ocana (GitHub: [0xZorro](https://github.com/0xZorro))  
Last updated: April 2025

