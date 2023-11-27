const int MAX_SAMPLES = 100;
int buzzerPin = 8; // Buzzer connected to pin 8
int length;
int tune[MAX_SAMPLES];
float duration[MAX_SAMPLES];
int currentIndex = 0;


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
  
  for (int x = 0; x < length; x++)  // Loop through the number of notes
    {
      tone(buzzerPin, tune[x]);  // This function plays each note in the tune array in sequence
  
      delay(400 * duration[x]);  // Duration of each note; adjust the timing here. Larger value for slower speed, smaller for faster speed.
  
      noTone(buzzerPin);  // Stop the current note before moving to the next one
    }
    delay(5000);  // Wait for 5 seconds before the loop restarts
    
}




