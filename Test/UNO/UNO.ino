const int MAX_SAMPLES = 100;
int buzzerPin = 8; // Buzzer connected to pin 8
int length;
int tune[MAX_SAMPLES];
float duration[MAX_SAMPLES];
int currentIndex = 0;

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

int tune_1[] = {
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

float duration_1[] =

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

void setup() {
  
  //pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // Start serial communication at 9600 baud rate
  
    pinMode(buzzerPin, OUTPUT);  // Set the pin for the buzzer to output mode
  
    length = sizeof(tune) / sizeof(tune[0]);  // Using sizeof to determine the number of notes in the tune array
}

void loop() {
  Serial.println("Hello Hello");
  if (Serial.available() > 0) {
      String data = Serial.readStringUntil('\n'); // Read data until a newline character

      // Parse the received data into tune and duration arrays
      int tuneValue = data.toInt(); // Assuming the tune is sent as an integer
      float durationValue = data.toFloat(); // Assuming the duration is sent as a floating-point number

      // Store the values in arrays
      tune[currentIndex] = tuneValue;
      duration[currentIndex] = durationValue;
      currentIndex++;
  }

  // if tune and duration has nothing in it, play the default tune
    if (currentIndex == 0) {
        Serial.println("Playing default tune");
        playTune(tune_1, duration_1, sizeof(tune_1)/sizeof(float));
    }
    else {
        Serial.println("Playing custom tune");
        playTune(tune, duration, currentIndex);
    }
}



void playTune(int tune[], float duration[], int length) {
  
    for (int x = 0; x < length; x++)  // Loop through the number of notes
    {
      tone(buzzerPin, tune[x]);  // This function plays each note in the tune array in sequence

      delay(400 * duration[x]);  // Duration of each note; adjust the timing here. Larger value for slower speed, smaller for faster speed.

      noTone(buzzerPin);  // Stop the current note before moving to the next one
    }
    delay(5000);  // Wait for 5 seconds before the loop restarts
}




