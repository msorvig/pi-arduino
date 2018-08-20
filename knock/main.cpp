#include <Arduino.h>

// This program records the timing of "knocks" (digital input events),
// and then plays them back.

// The Arduino will be in one of sevaral modes:
enum Mode {
    Waiting,    // Waiting for knock
    Recording,  // Recording knocks
    Playback,   // Playing back knocks
};
Mode mode = Waiting;

// Recorded knocks storage
const int maxRecordedKnocks = 10;
int knockDelays[maxRecordedKnocks];
int knockDelayCount = 0;

const int knockDuration = 20;
const int cooldownTime = 500; // delay after playback
const int recordIdleTime = 1500;

bool addKnock(int delay) {
    if (knockDelayCount + 1 == maxRecordedKnocks)
        return true; // full
    
    knockDelays[knockDelayCount] = delay;
    ++knockDelayCount;
    return false;
}

// Led handling
int led = 13;
void blinkLed() {
    digitalWrite(led, HIGH);
    delay(50);
    digitalWrite(led, LOW);
    delay(150);
}

bool ledState = false; // assume off
void toggleLed() {
    ledState = !ledState;
    digitalWrite(led, ledState);
}
void setLed(bool state) {
    digitalWrite(led, state);
}

int inputPin = PD4;
void setupInput() {
    pinMode(PD4, INPUT_PULLUP);    
}
bool readInputLevel() {
    return !digitalRead(inputPin);
}
bool inputLevel = false;
enum Edge {
    Stable,
    Rising,
    Falling,
};
Edge inputEdge() {
    bool currentInputLevel = readInputLevel();
    if (inputLevel == currentInputLevel)
        return Stable;
    
    inputLevel = currentInputLevel;
    return inputLevel ? Rising : Falling;
}

void setup() {                
    pinMode(led, OUTPUT);
    
    setupInput();

    blinkLed();
    delay(1000);
}

int beginRecordTime = 0;
int lastRecordedKnock = 0;

void reset() {
    // reset state
    knockDelayCount = 0;
    setLed(false);
}

void wait() {
    // reset state
    reset();

    if (inputEdge() == Rising) {
        addKnock(0);
        int now = millis();
        beginRecordTime = now;
        lastRecordedKnock = now;
        mode = Recording;
    }
}

void record()
{
    int now = millis();
    if ((now - lastRecordedKnock) > recordIdleTime)
        mode = Playback;

    if (inputEdge() == Rising) {
        int delay = now - lastRecordedKnock;
        lastRecordedKnock = now;
        bool storageFull = addKnock(delay);
        if (storageFull)
            mode = Playback;
    }
}

void playback()
{
  for (int i = 0; i < knockDelayCount; ++i) {
      delay(knockDelays[i]);
      blinkLed();
  }
  reset();
  delay(cooldownTime);
  mode = Waiting;
}

void loop() {
    switch (mode) {
        case Waiting:
            wait();
        break;
        case Recording:
          record();
        break;
        case Playback:
            playback();
        break;
    }
}

