# Ultrasonic Distance Detector

##Overview
This project uses an ultrasonic sensor (HC-SR04) with an Arduino and other basic circuit components to measure the distance of objects.


##Components
- Arduino(Uno)
- HC-SR04 Ultrasonic Sensor
- Breadboard & Jumper Wires
- Buzzer/LED for alerts

##Code File

See [`ultrasonic_distance_detector.ino`](ultrasonic_distance_detector.ino).

##How it Works
1. Arduino sends a pulse from the TRIG pin. 
2. Sensor measures the time for the signal to bounce back. 
3. Distance is calculated using=> distance(cm) = time/58 
4. Trigger is then alerted or stays passive depending on whether threshold is exceeded or not.

##States
- There are 3 states for the sensor

1. Far(Exceeding 200cms)
2. Medium Range(100-200cms)
3. Too Close(0-100cms) Buzzer is sounded when the object is detected to be **TOO CLOSE**.
