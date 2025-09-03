#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);

#define echoPin 2
#define trigPin 3

int led1 = 8;
int led2 = 9;
int led3 = 10;
int buzzer = 11;

long duration;
int distance;
int lastDistance = -1;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.display();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(500);
  lcd.setCursor(0, 0);
  lcd.print("System start");
  delay(1000);
  lcd.clear();
}

void loop() {
  // Trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0344 / 2;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance != lastDistance) {
    lcd.setCursor(0, 0);
    lcd.print("Distance:     ");
    lcd.setCursor(10, 0);
    lcd.print(distance);
    lcd.print(" cm");

    lcd.setCursor(0, 1);

    if (distance < 100) {
      lcd.print("Too Close      ");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(buzzer, HIGH);  // Buzzer ON when too close
    } else if (distance < 200) {
      lcd.print("Medium Range  ");
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(buzzer, LOW);  // Buzzer OFF
    } else {
      lcd.print("Far           ");
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(buzzer, LOW);  // Buzzer OFF
    }
    lastDistance = distance;
  }
  delay(250);
}
