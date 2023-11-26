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

void selectMusicFile() {
  FileDialog fd = new FileDialog(new Frame(), "Choose a file", FileDialog.LOAD);
  fd.setVisible(true);
  String filename = fd.getFile();
  if (filename != null) {
    filePath = fd.getDirectory() + fd.getFile();
    playMusicFile(filePath);
    currentPage = MAIN_PAGE; // Switch back to the main page
  }
}

void playMusicFile(String path) {
  if (musicFile != null) {
    musicFile.stop(); // Stop any currently playing music
  }
  musicFile = new SoundFile(this, path);
  musicFile.play();
}
