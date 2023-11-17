import processing.serial.*; // For communication with ESP32
import ddf.minim.*;         // Audio library

Serial myPort;              // Serial port for ESP32 communication
Minim minim;                // Audio manager
AudioPlayer player;         // Audio player
String[] songList = {"Song1", "Song2", "Song3"}; // Example song list
boolean isRecording = false;

void setup() {
  size(800, 600); // Set window size
  println(Serial.list()); // Print available serial ports
  myPort = new Serial(this, Serial.list()[0], 9600); // Replace with your ESP32 COM port
  minim = new Minim(this);

  // UI setup code goes here
}
