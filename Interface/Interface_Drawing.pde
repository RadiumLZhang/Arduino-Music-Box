



void drawMainPage() {
  background(255); // Set background color

  // Display buttons (assuming you have button images)
  image(button1, 50, (height - buttonHeight) / 2);
  image(button2, 200, (height - buttonHeight) / 2);
  image(button3, 350, (height - buttonHeight) / 2);
}


void drawPianoPage() {
  // Draw the piano keys as in your original piano page code
  for (int i = 0; i < 21; i++) {
    fill(i % 2 == 0 ? 255 : 0); // Alternate fill for white and black keys
    rect(i * keyWidth, 0, keyWidth, height);
  }
}

void drawUploadPage() {
  background(200); // Set a different background for the upload page
  fill(0);
  text("Click anywhere to upload and play a music file", width / 2, height / 2);
  // Additional UI elements can be added here
}
