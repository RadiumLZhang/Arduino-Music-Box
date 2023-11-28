// Pin definitions
const int ldrPin = A0;    // Photoresistor connected to analog pin A0
const int servoPin = 9;   // Servo motor signal pin
const int buzzerPin = 8;  // Buzzer signal pin

// The tune and duration array
const int MAX_SAMPLES = 300;
int tune[MAX_SAMPLES];
int duration[MAX_SAMPLES];
int currentIndex = 0;     // To keep track of the current index being read
bool isTuneData = false;  // To indicate whether the incoming data is tune or duration


WiFiServer server(80);
Servo myServo;  // Create servo object to control a servo

bool lightSwitch = false;
int servoPosition = 0;        // Variable to store the servo position
int servoDirection = 1;       // Variable to store the servo direction

int currentNote = 0;              // Variable to store the current note being played
int tuneSize = 0;                 // Variable to store the size of the tune


unsigned long lastLightCheck = 0;
unsigned long lastMotion = 0;
unsigned long lastTune = 0;