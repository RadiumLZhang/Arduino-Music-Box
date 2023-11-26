// Note Frequencies
final int NOTE_D0 = -1;
final int NOTE_D1 = 294;
final int NOTE_D2 = 330;
final int NOTE_D3 = 350;
final int NOTE_D4 = 393;
final int NOTE_D5 = 441;
final int NOTE_D6 = 495;
final int NOTE_D7 = 556;

final int NOTE_DL1 = 147;
final int NOTE_DL2 = 165;
final int NOTE_DL3 = 175;
final int NOTE_DL4 = 196;
final int NOTE_DL5 = 221;
final int NOTE_DL6 = 248;
final int NOTE_DL7 = 278;

final int NOTE_DH1 = 589;
final int NOTE_DH2 = 661;
final int NOTE_DH3 = 700;
final int NOTE_DH4 = 786;
final int NOTE_DH5 = 882;
final int NOTE_DH6 = 990;
final int NOTE_DH7 = 112;

// Durations
final float WHOLE = 1;
final float HALF = 0.5;
final float QUARTER = 0.25;
final float EIGHTH = 0.25;
final float SIXTEENTH = 0.625;


void analyzeAudioAndExtractFrequencies() {
  fft.forward(song.mix);

  float maxAmp = 0;
  int maxIndex = -1;

  // Analyze the spectrum to find the frequency with the highest amplitude
  for (int i = 0; i < fft.specSize(); i++) {
    if (fft.getBand(i) > maxAmp) {
      maxAmp = fft.getBand(i);
      maxIndex = i;
    }
  }

  float dominantFrequency = fft.indexToFreq(maxIndex);
  int closestNote = getClosestNote(dominantFrequency);

    // DEBUG
    println("Dominant Frequency: " + dominantFrequency + " Hz, Closest Note: " + closestNote);

   // Calculate the duration (for test simplicity, using a fixed duration)
  float noteDuration = QUARTER; // TODO using framerate to calculate

  // Check if the arrays are full, and resize if necessary
  if (currentSample >= currentSize) {
    resizeArrays(currentSample * 2); // Double the size
  }

  // Store the analyzed values in the arrays
  tune[currentSample] = closestNote;
  duration[currentSample] = noteDuration;

  // Increment the current sample counter
  currentSample++;
}

int getClosestNote(float frequency) {
  // Define the notes with their frequencies
  int[] notes = {NOTE_D0, NOTE_D1, NOTE_D2, NOTE_D3, NOTE_D4, NOTE_D5, NOTE_D6, NOTE_D7, NOTE_DL1, NOTE_DL2, NOTE_DL3, NOTE_DL4, NOTE_DL5, NOTE_DL6, NOTE_DL7, NOTE_DH1, NOTE_DH2, NOTE_DH3, NOTE_DH4, NOTE_DH5, NOTE_DH6, NOTE_DH7};
  int closestNote = NOTE_D0;
  float minDiff = Float.MAX_VALUE;

  for (int note : notes) {
    float diff = Math.abs(frequency - note);

    if (diff < minDiff) {
      minDiff = diff;
      closestNote = note;
    }
  }

  return closestNote;
}
