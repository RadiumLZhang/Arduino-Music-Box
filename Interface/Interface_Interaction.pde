void mousePressed() {
  if (currentPage == MAIN_PAGE) {
    // Assuming button1 is for the piano page
    int buttonYTop = (height - buttonHeight) / 2;
    int buttonYBottom = buttonYTop + buttonHeight;

    // Check if Button 1 is clicked
    if (mouseX > 50 && mouseX < 50 + buttonWidth && mouseY > buttonYTop && mouseY < buttonYBottom) {
      currentPage = PIANO_PAGE; // Switch to the piano page
    }
    // Check if Button 2 is clicked
    else if (mouseX > 200 && mouseX < 200 + buttonWidth && mouseY > buttonYTop && mouseY < buttonYBottom) {
      currentPage = UPLOAD_PAGE; // Switch to upload page
    }
    // Check if Button 3 is clicked
    else if (mouseX > 350 && mouseX < 350 + buttonWidth && mouseY > buttonYTop && mouseY < buttonYBottom) {
      currentPage = PLAYING_PAGE; // Switch to Arduino page
    }
  } else if (currentPage == PIANO_PAGE) {
    // Handle piano page interactions
    int keyIndex = mouseX / keyWidth;
    if (keyIndex >= 0 && keyIndex < oscillators.length && frequencies[keyIndex] != -1) {
      playNote(keyIndex);
    }
  } else if (currentPage == UPLOAD_PAGE) {
    selectMusicFile();
  }
}

void mouseReleased() {
  if (currentPage == PIANO_PAGE) {
    stopAllNotes();
  }
}

void keyPressed() {

  if (currentPage != MAIN_PAGE && key == ESC) {
    currentPage = MAIN_PAGE; // Return to main page
    key = 0; // Prevent default ESC behavior
  }
  if (currentPage == PIANO_PAGE) {
    for (int i = 0; i < keyMappings.length; i++) {
      if (key == keyMappings[i] && frequencies[i] != -1) {
        playNote(i);
        break;
      }
    }
  }
}

void keyReleased() {
  if (currentPage == PIANO_PAGE) {
    stopAllNotes();
  }
}
