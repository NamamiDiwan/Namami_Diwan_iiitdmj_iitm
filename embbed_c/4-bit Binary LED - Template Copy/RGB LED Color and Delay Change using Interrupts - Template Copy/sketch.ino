#include <Arduino.h>

#define colorBtnPin 6
#define durationBtnPin 7
#define redPin   11
#define greenPin 10
#define bluePin  9

// Color pattern: {R, G, B}
bool colors[][3] = {
  {1,1,1}, {1,0,0}, {0,1,0}, {0,0,1},  // wrgb
  {0,1,1}, {1,1,0}, {1,0,1}, {0,0,0}   // cymk (last = off)
};

char* colorNames[] = {
  "white","red","green","blue",
  "cyan","yellow","megenta","black" // black is just off
};

int delays[] = {1000, 800, 600, 400, 200};

#define NUM_COLORS (sizeof(colors)/sizeof(colors[0]))
#define NUM_DELAYS (sizeof(delays)/sizeof(delays[0]))

volatile int colorIndex = 0;
volatile int delayIndex = 0;
unsigned long lastColorInterrupt = 0;
unsigned long lastDelayInterrupt = 0;
const int debounceTime = 50;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(colorBtnPin, INPUT_PULLUP);
  pinMode(durationBtnPin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(colorBtnPin), changeColorISR, FALLING);
  attachInterrupt(digitalPinToInterrupt(durationBtnPin), changeDelayISR, FALLING);
}

void changeColorISR() {
  if (millis() - lastColorInterrupt > debounceTime) {
    colorIndex = (colorIndex + 1) % NUM_COLORS;
    lastColorInterrupt = millis();
  }
}

void changeDelayISR() {
  if (millis() - lastDelayInterrupt > debounceTime) {
    delayIndex = (delayIndex + 1) % NUM_DELAYS;
    lastDelayInterrupt = millis();
  }
}

void loop() {
  digitalWrite(redPin,   colors[colorIndex][0]);
  digitalWrite(greenPin, colors[colorIndex][1]);
  digitalWrite(bluePin,  colors[colorIndex][2]);
  delay(delays[delayIndex]);
}
