#include <Arduino.h>

int counter = 0;
int stopPin = 2;

bool serialOn = false;

void setup() {                
    pinMode(stopPin, INPUT_PULLUP);
}

void loop() {
    int val = digitalRead(stopPin);
    bool enableSerial = !val;

    if (enableSerial && !serialOn) {
        serialOn = true;
        Serial.begin(9600);
    } else if (!enableSerial && serialOn) {
        serialOn = false;
        Serial.end();
    }

    if (serialOn) {
        Serial.print("Hello ");
        Serial.println(counter);
        ++counter;
    }
    delay(1000);
}
