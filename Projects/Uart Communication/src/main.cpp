#include <Arduino.h>
#include <Servo.h>

Servo legServo;

#define SERVO_PIN 13
#define RXD2 16
#define TXD2 17

void setup() {
  Serial.begin(115200);        // USB serial - for debug monitor
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);  // UART2 - talks to "Pi"

  legServo.attach(SERVO_PIN);
  legServo.write(90);  // neutral position

  Serial.println("ESP32 ready. Waiting for commands on UART2...");
}

void loop() {
  if (Serial2.available()) {
    String command = Serial2.readStringUntil('\n');
    command.trim();

    Serial.print("Received: ");
    Serial.println(command);

    if (command == "FORWARD") {
      legServo.write(120);
      Serial.println("-> Moving forward");
    }
    else if (command == "BACKWARD") {
      legServo.write(60);
      Serial.println("-> Moving backward");
    }
    else if (command == "STOP") {
      legServo.write(90);
      Serial.println("-> Stopped");
    }
    else {
      Serial.println("-> Unknown command");
    }
  }
}