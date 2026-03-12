// 4-bit Binary LEDs with non-blocking delay

int ledPin[] = {13, 12, 11, 10};
int ledDelay[4] = {8000, 4000, 2000, 1000};

unsigned long lastToggle[4];
int ledState[4] = {0, 0, 0, 0};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(ledPin[i], OUTPUT);
    digitalWrite(ledPin[i], LOW);
    lastToggle[i] = millis(); // initialize time marker
  }
}

void loop() {
  unsigned long currTime = millis(); // current timestamp

  for (int i = 0; i < 4; i++) {
    // check if it's time to toggle the LED
    if (currTime - lastToggle[i] >= ledDelay[i]) {
      lastToggle[i] = currTime;     // reset timer
      ledState[i] = !ledState[i];   // flip state
      digitalWrite(ledPin[i], ledState[i]);
    }
  }
}
