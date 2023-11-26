import ddf.minim.*;
import ddf.minim.analysis.*;
import processing.serial.*;

Serial arduinoPort;
Minim minim;
AudioPlayer player;
FFT fft;

void setup() {
  size(512, 200);

  // Serial Communication
  println(Serial.list());
  arduinoPort = new Serial(this, Serial.list()[1], 9600); // Adjust the index [0] as per your serial port

  // Minim Audio Setup
  minim = new Minim(this);
  player = minim.loadFile("Audio/lastchristmas.mp3", 2048);
  player.play();
  fft = new FFT(player.bufferSize(), player.sampleRate());
}

void draw() {
  fft.forward(player.mix);
  for (int i = 0; i < fft.specSize(); i++) {
    // Analyzing the frequency spectrum
    float frequency = fft.indexToFreq(i);
    float amplitude = fft.getBand(i);
    if (amplitude > 50) { // Example threshold, adjust as needed
      arduinoPort.write(frequency + "\n"); // Sending frequency to Arduino
      delay(50); // Adjust delay as per your requirement
    }
  }
}
