// Traffic Light Simulation for STM32 (Wokwi)
// Using pins: Green = 13, Yellow = 12, Red = 11

#define g_ledpin 13
#define y_ledpin 12
#define r_ledpin 11

void setup() {
  pinMode(g_ledpin, OUTPUT);
  pinMode(y_ledpin, OUTPUT);
  pinMode(r_ledpin, OUTPUT);
}

void loop() {
  // GREEN light ON
  digitalWrite(g_ledpin, HIGH);
  digitalWrite(y_ledpin, LOW);
  digitalWrite(r_ledpin, LOW);
  delay(5000); // 5 seconds

  // YELLOW light ON
  digitalWrite(g_ledpin, LOW);
  digitalWrite(y_ledpin, HIGH);
  digitalWrite(r_ledpin, LOW);
  delay(2000); // 2 seconds

  // RED light ON
  digitalWrite(g_ledpin, LOW);
  digitalWrite(y_ledpin, LOW);
  digitalWrite(r_ledpin, HIGH);
  delay(5000); // 5 seconds
}
