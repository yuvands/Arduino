#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int sensorPin = A0;
int buzzer = 12;
int led = 13;

int lastMoisture = -1;

void setup() {
  lcd.begin(16, 2);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);//initialisation
}

void loop() {
  int moisture = analogRead(sensorPin);

  if (moisture != lastMoisture) {
    lcd.setCursor(0, 0);
    lcd.print("MOISTURE:      "); 
    lcd.setCursor(10, 0);
    lcd.print(moisture);

    lcd.setCursor(0, 1);
    if (moisture > 500) {  
      lcd.print("STATUS  : WET   ");//led refreshes
      digitalWrite(buzzer, LOW);
      digitalWrite(led, LOW);
    } else {
      lcd.print("STATUS  : DRY   ");
      digitalWrite(buzzer, HIGH);
      //Led Blinks rapidly
      blinkLed();
    }
    lastMoisture = moisture;
  }
}

//rapid blinking when moisture is found to be "DRY(below 500units)"
unsigned long previousMillis = 0;
const long interval = 100; 

void blinkLed() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    int ledState = digitalRead(led);
    digitalWrite(led, !ledState);
  }
}
