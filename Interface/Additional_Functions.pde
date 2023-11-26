void playMusic() {
  println("Playing Music");
  // Add code to play music
}

void showLibrary() {
  println("Showing Library");
  // Add code to show music library
}

void openSettings() {
  println("Opening Settings");
  // Add code to open settings
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
