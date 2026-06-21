# Smart Energy Meter

## Description
A Smart Energy Meter is an IoT-based system that measures voltage, current, power, and energy consumption in real time using ESP32, a voltage sensor, and an ACS712 current sensor. The measured values are displayed on an I2C LCD and can be transmitted to the cloud via Wi‑Fi for remote monitoring.

## Components Used
- ESP32
- Voltage Sensor Module
- ACS712 Current Sensor
- 16x2 I2C LCD
- Jumper Wires
- Power Supply

## Connections

### Voltage Sensor
| Sensor Pin | ESP32 Pin |
|------------|-----------|
| S | GPIO34 |
| + | 3.3V |
| - | GND |

### ACS712 Current Sensor
| Sensor Pin | ESP32 Pin |
|------------|-----------|
| OUT | GPIO35 |
| VCC | 5V |
| GND | GND |

### I2C LCD
| LCD Pin | ESP32 Pin |
|----------|-----------|
| SDA | GPIO21 |
| SCL | GPIO22 |
| VCC | 3.3V/5V |
| GND | GND |

## Working
1. Voltage sensor measures supply voltage.
2. ACS712 measures load current.
3. ESP32 reads sensor values through ADC pins.
4. Power and energy consumption are calculated.
5. Readings are displayed on the LCD.
6. Data is uploaded to the cloud using Wi‑Fi.

## Features
- Real-time monitoring
- Energy consumption calculation
- LCD display
- Wi‑Fi cloud connectivity
- Low-cost IoT solution

## Applications
- Smart Homes
- Energy Monitoring
- Industrial Automation
- Smart Grid Systems

## Author
Akhand Parasar