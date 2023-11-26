import processing.sound.*;

SinOsc[] oscillators = new SinOsc[21]; // Array to hold oscillators for each key
int[] frequencies = {-1, 294, 330, 350, 393, 441, 495, 556, 147, 165, 175, 196, 221, 248, 278, 589, 661, 700, 786, 882, 990}; // Frequencies for the provided notes
char[] keyMappings = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'z', 'x', 'c', 'v', 'b', 'n'}; // Map these keys to the piano keys
int keyWidth;

void setup() {
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

void draw() {
  for (int i = 0; i < 21; i++) {
    fill(i % 2 == 0 ? 255 : 0); // Alternate fill for white and black keys
    rect(i * keyWidth, 0, keyWidth, height);
  }
}

void keyPressed() {
  for (int i = 0; i < keyMappings.length; i++) {
    if (key == keyMappings[i] && frequencies[i] != -1) {
      playNote(i);
      break;
    }
  }
}

void keyReleased() {
  stopAllNotes();
}

void mousePressed() {
  int keyIndex = mouseX / keyWidth;
  if (keyIndex >= 0 && keyIndex < oscillators.length && frequencies[keyIndex] != -1) {
    playNote(keyIndex);
  }
}

void mouseReleased() {
  stopAllNotes();
}

void playNote(int index) {
  oscillators[index].amp(0.5);
  oscillators[index].play();
}

void stopAllNotes() {
  for (SinOsc osc : oscillators) {
    osc.amp(0);
  }
}
