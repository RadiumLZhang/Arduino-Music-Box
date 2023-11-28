#include <WiFi.h>
#include <ESP32Servo.h>
#include "variables.h"
#include "Thread.h"
#include "ThreadController.h"
#include "wifi_setup.h"
#include "light_check.h"
#include "servo_control.h"
#include "tune_play.h"


void setup() {
  Serial.begin(115200);
  // ESP32-specific setup
  connectToHomeWiFi();
  // Initialize servo
  myServo.attach(servoPin, 500, 2400);
}

void loop() {
  unsigned long currentMillis = millis();

  if(currentMillis - lastLightCheck >= 100) {
    checkLight();
    lastLightCheck = currentMillis;
  }

  if(lightSwitch) {
    if(currentMillis - lastMotion >= 100000) {
      moveServo();
      lastMotion = currentMillis;
    }

    if(currentMillis - lastTune >= 400) {
      playTune();
      lastTune = currentMillis;
    }
  }
}