# Soil Moisture Detector
This project(made using TINKERCAD) uses an **Arduino UNO**, a soil moisture detector and other basic circuit components to display 
the moisture level in the soil being tested.

- If the soil is **wet**, the LCD shows "WET" and remains silent.
- If the soil is **dry**, the LCD shows "DRY", LED blinks rapidly and then activates the  buzzer.

### Components
- Arduino UNO
- Soil Moisture Sensor
- 16x2 LCD Display
- LED
- Buzzer
- Resistors
- Wires

### Code
See [`soil_moisture_detector.ino`](soil_moisture_detector.ino).
 
### States
->There are 2 states for this circuit
1. DRY-> LED blinks and buzzer sounds to indicate that the soil is dry.
2. WET-> Neither LED nor buzzer indicate anything. LCD Displays that the soil is **WET**.
