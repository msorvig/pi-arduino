#include <Arduino.h>

int led = 13;
void blinkLed() {
    digitalWrite(led, HIGH);
    delay(50);
    digitalWrite(led, LOW);
    delay(150);
}
void setup() {                
    pinMode(led, OUTPUT);
    pinMode(PD4, INPUT_PULLUP);
    pinMode(PD5, INPUT);
    pinMode(PD6, OUTPUT);
    pinMode(PD7, INPUT);
}

void loop() {
    bool onButton = !digitalRead(PD4);
    bool onSound = digitalRead(PD5);
    bool onPIR = digitalRead(PD7);
    bool oneOn = (onButton || onSound || onPIR);
    digitalWrite(led, oneOn);
    digitalWrite(PD6, oneOn);
}

