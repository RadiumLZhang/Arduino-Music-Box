//import processing.serial.*; // For communication with ESP32
//import ddf.minim.*;         // Audio library
//
//Serial myPort;              // Serial port for ESP32 communication
//Minim minim;                // Audio manager
//AudioPlayer player;         // Audio player
//String[] songList = {"Song1", "Song2", "Song3"}; // Example song list
//boolean isRecording = false;
//
//void setup() {
//  size(800, 600); // Set window size
//  println(Serial.list()); // Print available serial ports
//  myPort = new Serial(this, Serial.list()[0], 9600); // Replace with your ESP32 COM port
//  minim = new Minim(this);
//
//  // UI setup code goes here
//}

// Main Page
PImage button1, button2, button3;
int buttonWidth, buttonHeight;


// Piano Page
import processing.sound.*;

SinOsc[] oscillators = new SinOsc[21]; // Array to hold oscillators for each key
int[] frequencies = {-1, 294, 330, 350, 393, 441, 495, 556, 147, 165, 175, 196, 221, 248, 278, 589, 661, 700, 786, 882, 990}; // Frequencies for the provided notes
char[] keyMappings = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'z', 'x', 'c', 'v', 'b', 'n'}; // Map these keys to the piano keys
int keyWidth;



void setup() {
  size(600, 200); // Adjust the size as needed

  // Main Page
  // Load images
  button1 = loadImage("Images/piano-button.png");
  button2 = loadImage("Images/piano-button.png");
  button3 = loadImage("Images/piano-button.png");

  // Assuming all buttons are the same size
  buttonWidth = button1.width;
  buttonHeight = button1.height;

  // Piano Page
  size(840, 200); // Adjusted for 21 keys
  keyWidth = width / 21;
  for (int i = 0; i < oscillators.length; i++) {
    oscillators[i] = new SinOsc(this);
    if (frequencies[i] != -1) { // Check if the frequency is valid
      oscillators[i].freq(frequencies[i]);
    }
    oscillators[i].amp(0);
  }
}
