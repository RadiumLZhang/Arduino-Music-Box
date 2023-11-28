#define NOTE_D0 -1
#define NOTE_D1 294
#define NOTE_D2 330
#define NOTE_D3 350
#define NOTE_D4 393
#define NOTE_D5 441
#define NOTE_D6 495
#define NOTE_D7 556

#define NOTE_DL1 147
#define NOTE_DL2 165
#define NOTE_DL3 175
#define NOTE_DL4 196
#define NOTE_DL5 221
#define NOTE_DL6 248
#define NOTE_DL7 278

#define NOTE_DH1 589
#define NOTE_DH2 661
#define NOTE_DH3 700
#define NOTE_DH4 786
#define NOTE_DH5 882
#define NOTE_DH6 990
#define NOTE_DH7 112

int tune[] = {
  NOTE_D0, NOTE_D0, NOTE_D0, NOTE_D6, NOTE_D7, NOTE_DH1, NOTE_D7, NOTE_DH1, NOTE_DH3, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D3, NOTE_D3,
  NOTE_D6, NOTE_D5, NOTE_D6, NOTE_DH1, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D3, NOTE_D4, NOTE_D3, NOTE_D4, NOTE_DH1,
  NOTE_D3, NOTE_D3, NOTE_D0, NOTE_DH1, NOTE_DH1, NOTE_DH1, NOTE_D7, NOTE_D4, NOTE_D4, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D0, NOTE_D6, NOTE_D7,
  NOTE_DH1, NOTE_D7, NOTE_DH1, NOTE_DH3, NOTE_D7, NOTE_D7, NOTE_D7, NOTE_D3, NOTE_D3, NOTE_D6, NOTE_D5, NOTE_D6, NOTE_DH1,
  NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D2, NOTE_D3, NOTE_D4, NOTE_DH1, NOTE_D7, NOTE_D7, NOTE_DH1, NOTE_DH1, NOTE_DH2, NOTE_DH2, NOTE_DH3, NOTE_DH1, NOTE_DH1, NOTE_DH1,
  NOTE_DH1, NOTE_D7, NOTE_D6, NOTE_D6, NOTE_D7, NOTE_D5, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_DH1, NOTE_DH2, NOTE_DH3, NOTE_DH2, NOTE_DH3, NOTE_DH5,
  NOTE_DH2, NOTE_DH2, NOTE_DH2, NOTE_D5, NOTE_D5, NOTE_DH1, NOTE_D7, NOTE_DH1, NOTE_DH3, NOTE_DH3, NOTE_DH3, NOTE_DH3, NOTE_DH3,
  NOTE_D6, NOTE_D7, NOTE_DH1, NOTE_D7, NOTE_DH2, NOTE_DH2, NOTE_DH1, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_DH4, NOTE_DH3, NOTE_DH2, NOTE_DH1,
  NOTE_DH3, NOTE_DH3, NOTE_DH3, NOTE_DH3, NOTE_DH6, NOTE_DH6, NOTE_DH5, NOTE_DH5, NOTE_DH3, NOTE_DH2, NOTE_DH1, NOTE_DH1, NOTE_D0, NOTE_DH1,
  NOTE_DH2, NOTE_DH1, NOTE_DH2, NOTE_DH2, NOTE_DH5, NOTE_DH3, NOTE_DH3, NOTE_DH3, NOTE_DH3, NOTE_DH6, NOTE_DH6, NOTE_DH5, NOTE_DH5,
  NOTE_DH3, NOTE_DH2, NOTE_DH1, NOTE_DH1, NOTE_D0, NOTE_DH1, NOTE_DH2, NOTE_DH1, NOTE_DH2, NOTE_DH2, NOTE_D7, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_D6, NOTE_D7
};

float duration[] =

  {
    1, 1, 1, 0.5, 0.5, 1 + 0.5, 0.5, 1, 1, 1, 1, 1, 0.5, 0.5,
    1 + 0.5, 0.5, 1, 1, 1, 1, 1, 1, 1 + 0.5, 0.5, 1, 1,
    1, 1, 0.5, 0.5, 0.5, 0.5, 1 + 0.5, 0.5, 1, 1, 1, 1, 1, 0.5, 0.5,
    1 + 0.5, 0.5, 1, 1, 1, 1, 1, 0.5, 0.5, 1 + 0.5, 0.5, 1, 1,
    1, 1, 1, 0.5, 0.5, 1, 0.5, 0.25, 0.25, 0.25, 0.5, 0.5, 0.5, 0.5, 0.25, 0.5, 1,
    0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1, 1, 0.5, 0.5, 1 + 0.5, 0.5, 1, 1,
    1, 1, 1, 0.5, 0.5, 1.5, 0.5, 1, 1, 1, 1, 1, 1,
    0.5, 0.5, 1, 1, 0.5, 0.5, 1.5, 0.25, 0.5, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0.5, 1, 1, 0.5, 0.5,
    1, 0.5, 0.5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    0.5, 0.5, 1, 1, 0.5, 0.5, 1, 0.5, 0.25, 0.5, 1, 1, 1, 1, 0.5, 0.5
  };

#include <WiFi.h>
#include "Thread.h"
#include "ThreadController.h"
#include <ESP32Servo.h>
Servo myservo;

// Home WiFi Settings
const char* home_ssid = "I believe Wi can Fi";
const char* home_password = "Jirachi666";

// Select WiFi Network
bool useEnterprise = false;  // Set to true to connect to Eduroam, false for home WiFi

WiFiServer server(80);

/* Wifi Settings*/
void connectToHomeWiFi() {
  Serial.println("Connecting to Home WiFi...");
  WiFi.begin(home_ssid, home_password);

  // while (WiFi.status() != WL_CONNECTED) {
  //   delay(500);
  //   Serial.print(".");
  // }

  Serial.println("Connected to Home WiFi");
}


// Pin definitions
const int ldrPin = A0;    // Photoresistor connected to analog pin A0
const int servoPin = 9;   // Servo motor signal pin
const int buzzerPin = 8;  // Buzzer signal pin

// Thread objects
// ThreadController that will control all threads
ThreadController controller = ThreadController();

// Threads
Thread checkLightThread = Thread();
Thread moveServoThread = Thread();
Thread playTuneThread = Thread();

bool lightSwitch = false;  // Initialize the lightSwitch variable

Servo myServo;
int servoPosition = 0;
int servoDirection = 1;  // 1 for increasing, -1 for decreasing

int currentNote = 0;  // Index of the current note


int tuneSize = sizeof(tune) / sizeof(tune[0]);  // Number of notes in the tune

void setup() {

  Serial.begin(115200);
  // ESP32-specific setup

  connectToHomeWiFi();
  playTune();

  // Initialize servo
  myServo.attach(servoPin);

  // Configure and add threads to the controller
  checkLightThread.onRun(checkLight);
  checkLightThread.setInterval(100);  // Run every 100 ms
  controller.add(&checkLightThread);

  moveServoThread.onRun(moveServo);
  moveServoThread.setInterval(20);  // Run every 20 ms
  controller.add(&moveServoThread);

  playTuneThread.onRun(playTune);
  playTuneThread.setInterval(400);  // Run every 400 ms
  controller.add(&playTuneThread);
}


void loop() {
  Serial.println("loop");
  if (!myservo.attached()) {
    myservo.setPeriodHertz(50);      // standard 50 hz servo
    myservo.attach(33, 1000, 2000);  // Attach the servo after it has been detatched
  }
  myservo.write(0);
  controller.run();
}

// Thread 1 function to check light level
void checkLight() {
  while (true) {
    // Analog read
    int ldrValue = analogRead(ldrPin);

    // Check if light level is above a threshold (e.g., 100)
    lightSwitch = ldrValue > 100;

    // You can use the lightSwitch variable for further logic

    // Check the lightSwitch variable and stop the song and motion if needed
    if (!lightSwitch) {
      noTone(buzzerPin);  // Stop playing the tune
      // Optionally, you can stop the servo motion as well
      // servoDirection = 0;
    }
  }
}
// Thread 2 function to move servo
void moveServo() {
  while (true) {
    // Check the lightSwitch variable before moving the servo
    if (lightSwitch) {
      // Increment or decrement the servo position
      servoPosition += servoDirection;

      // Check if we've reached the limits (0 or 180 degrees)
      if (servoPosition <= 0 || servoPosition >= 180) {
        servoDirection *= -1;  // Reverse direction
      }

      // Move the servo to the current position
      myServo.write(servoPosition);
    }
  }
}
// Thread 3 function to play the tune
void playTune() {
  while (true) {
    // Check if it's time to play the next note and if the lightSwitch is true
    if (currentNote < tuneSize && lightSwitch) {
      tone(buzzerPin, tune[currentNote]);
      delay(400 * duration[currentNote]);
      noTone(buzzerPin);  // Stop playing the note
      currentNote++;
    } else {
      // Reset the note index to replay the tune
      currentNote = 0;
    }
  }
}
