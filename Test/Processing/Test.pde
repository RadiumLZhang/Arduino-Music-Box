import processing.serial.*;

Serial myPort; // Create object from Serial class

void setup() {
  printArray(Serial.list()); // List all the available serial ports
  myPort = new Serial(this, Serial.list()[1], 9600); // Change [0] to the index of your Arduino port
}

void draw() {
  int frequency = 440; // Define the frequency (e.g., A4 note)
  myPort.write(frequency + "\n"); // Send the frequency to Arduino
  delay(1000); // Delay for a second
}
