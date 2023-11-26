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
  int numSamples = 1024;  // Adjust this number as needed
  tune = new int[numSamples];
  duration = new float[numSamples];
  currentSize = numSamples;
  currentSample = 0;
  
  FileDialog fd = new FileDialog(new Frame(), "Choose a file", FileDialog.LOAD);
  fd.setVisible(true);
  String filename = fd.getFile();
  if (filename != null) {
    filePath = fd.getDirectory() + fd.getFile();
    // Load your song //<>//
    song = minim.loadFile(filePath, numSamples);
    //song.play(); //<>//

    fft = new ddf.minim.analysis.FFT(song.bufferSize(), song.sampleRate());

    currentPage = MAIN_PAGE; // Switch back to the main page
  }
}

// Function to resize the arrays
void resizeArrays(int newSize) {
  int[] newTune = new int[newSize];
  float[] newDuration = new float[newSize];

  // Copy the existing data to the new arrays
  for (int i = 0; i < currentSize; i++) {
    newTune[i] = tune[i];
    newDuration[i] = duration[i];
  }

  // Update the arrays with the new sizes
  tune = newTune;
  duration = newDuration;
  currentSize = newSize;
}
