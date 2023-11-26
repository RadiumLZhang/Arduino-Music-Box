int buzzerPin = 8; // Buzzer connected to pin 8

void setup() {
  
  //pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // Start serial communication at 9600 baud rate
}

void loop() {
  Serial.println("Hello Hello");
  if (Serial.available()) { // Check if data is available to read
    int frequency = Serial.parseInt(); // Read the frequency
    // print the received frequency to the console
    Serial.println("Frequency received: " + String(frequency) + "Hz");
    if (frequency > 0) {
      tone(buzzerPin, frequency); // Play the received frequency
    } else {
      noTone(buzzerPin); // Stop the buzzer if frequency is 0 or invalid
    }
  }
  else {
    Serial.println("No data received"); // Print a message if no data is received
    noTone(buzzerPin); // Stop the buzzer if no data is available
  }
}
