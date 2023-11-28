#ifdef ARDUINO_ARCH_ESP32
#include "WiFi.h"

// Home WiFi Settings
const char* home_ssid = "I believe Wi can Fi";
const char* home_password = "Jirachi666";

// Enterprise Settings
const char* edu_ssid = "eduroam";
const char* edu_username = "lzhang793";    // Your Enterprise username
const char* edu_password = "Vanessa0729";  // Your Enterprise password
// Select WiFi Network
bool useEnterprise = false;  // Set to true to connect to Eduroam, false for home WiFi

WiFiServer server(80);

/* Wifi Settings*/
void connectToHomeWiFi() {
  Serial.println("Connecting to Home WiFi...");
  WiFi.begin(home_ssid, home_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected to Home WiFi");
}

void connectToEduroam() {
  Serial.println("Connecting to Eduroam...");
  WiFi.disconnect(true);
  delay(1000);

  WiFi.mode(WIFI_STA);
  esp_wifi_sta_wpa2_ent_set_identity((uint8_t*)edu_username, strlen(edu_username));
  esp_wifi_sta_wpa2_ent_set_username((uint8_t*)edu_username, strlen(edu_username));
  esp_wifi_sta_wpa2_ent_set_password((uint8_t*)edu_password, strlen(edu_password));
  esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT();
  esp_wifi_sta_wpa2_ent_enable(&config);

  WiFi.begin(edu_ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Connected to Eduroam");
}
#endif


#include <Arduino.h>
#include <Servo.h>


const int servoPin = 9;  // Servo connected to GPIO15
const int ldrPin = A0;   // Photoresistor connected to A0

// Buzzer pin
const int buzzerPin = 8;  // Change this to a suitable GPIO pin

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

Servo myServo;  // Create a servo object
void setup() {

  myServo.attach(servoPin);
#ifdef ARDUINO_ARCH_ESP32
  Serial.begin(115200);
  // ESP32-specific setup
  pinMode(buzzerPin, OUTPUT);
  if (useEduroam) {
    connectToEduroam();
  } else {
    connectToHomeWiFi();
  }
#else
  Serial.begin(9600);
  // Uno-specific setup
  Serial.println("This is an Uno");
  pinMode(buzzerPin, OUTPUT);

  // Attach the servo to the specified pin


#endif
}

bool lightSwitch = false;
void loop() {

  
  // analog read
  int ldrValue = analogRead(ldrPin);
  lightSwitch = ldrValue > 100;

  // Example: Play a tune
  if (lightSwitch) {
    activateMotorAndBuzzer();
  } else {
    deactivateMotorAndBuzzer();
  }
  playTune(tune, duration, sizeof(tune) / sizeof(tune[0]));
  delay(10000);  // Delay between playbacks
}

// Motor
void activateMotorAndBuzzer() {
  playTune(tune, duration, sizeof(tune) / sizeof(tune[0]));
  moveFigure();
}

void deactivateMotorAndBuzzer() {
  stopTune();
  stopFigure();
}

void playTune(int* tune, float* duration, int length) {
  for (int x = 0; x < length && lightSwitch; x++)  // Loop through the number of notes
  {
    Serial.println("Song is playing...");
    tone(buzzerPin, tune[x]);  // This function plays each note in the tune array in sequence

    delay(400 * duration[x]);  // Duration of each note; adjust the timing here. Larger value for slower speed, smaller for faster speed.

    noTone(buzzerPin);  // Stop the current note before moving to the next one
  }
  
}

void stopTune() {
  noTone(buzzerPin);
}


int pos = 0;  //var to store the servo position

void moveFigure() {
  Serial.println("moveFigure");
  delay(1000);
  // Loop from 0 to 180
  for (int i = 0; i <= 180 && lightSwitch; ++i) {
    myServo.write(i);
  }


  // Loop from 180 to 0
  for (int i = 180; i >= 0 && lightSwitch; --i) {
    myServo.write(i);
  }
}

void stopFigure() {
}