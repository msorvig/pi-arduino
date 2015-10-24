#include <Arduino.h>

int led = 13;
int counter = 0;

void setup() {                
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(50);
  digitalWrite(led, LOW);
  delay(150);
  digitalWrite(led, HIGH);
  delay(50);
  digitalWrite(led, LOW);
  delay(1000);
  
  Serial.print("Hello");
  Serial.println(counter);
  ++counter;
}

