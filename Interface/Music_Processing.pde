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

  // DEBUG
  println("Dominant Frequency: " + dominantFrequency + " Hz");

  // Check if the arrays are full, and resize if necessary
  if (currentSample >= currentSize) {
    return;
  }

  // Store the analyzed values in the arrays
  tune[currentSample] = int(dominantFrequency);
  duration[currentSample] = QUARTER;

  // Increment the current sample counter
  currentSample++;
}
