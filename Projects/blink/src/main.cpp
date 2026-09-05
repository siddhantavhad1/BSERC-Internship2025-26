#include <Arduino.h>

#define LED_PIN 2  // Most ESP32 DevKit boards use GPIO2 for onboard LED

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}