unsigned long lastNoteTime = 0;
void playTune() {
  unsigned long currentMillis = millis();
  // Check if it's time to play the next note and if the lightSwitch is true
  if (currentNote < tuneSize && lightSwitch) {
    if (currentMillis - lastNoteTime >= 400 * duration[currentNote]) {
      tone(buzzerPin, tune[currentNote]);
      noTone(buzzerPin);  // Stop playing the note
      currentNote++;
      lastNoteTime = currentMillis;
    }
  } else {
    // Reset the note index to replay the tune
    currentNote = 0;
  }
}