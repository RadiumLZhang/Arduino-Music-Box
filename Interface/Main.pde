PImage button1, button2, button3;
int buttonWidth, buttonHeight;

void setup() {
  size(600, 200); // Adjust the size as needed

  // Load images
  button1 = loadImage("Images/piano-button.png");
  button2 = loadImage("Images/piano-button.png");
  button3 = loadImage("Images/piano-button.png");

  // Assuming all buttons are the same size
  buttonWidth = button1.width;
  buttonHeight = button1.height;
}

void draw() {
  background(255); // Set background color

  // Display buttons
  image(button1, 50, (height - buttonHeight) / 2);
  image(button2, 200, (height - buttonHeight) / 2);
  image(button3, 350, (height - buttonHeight) / 2);
}

void mousePressed() {
  int buttonYTop = (height - buttonHeight) / 2;
  int buttonYBottom = buttonYTop + buttonHeight;

  // Check if Button 1 is clicked
  if (mouseX > 50 && mouseX < 50 + buttonWidth && mouseY > buttonYTop && mouseY < buttonYBottom) {
    playMusic();
  }
  // Check if Button 2 is clicked
  else if (mouseX > 200 && mouseX < 200 + buttonWidth && mouseY > buttonYTop && mouseY < buttonYBottom) {
    showLibrary();
  }
  // Check if Button 3 is clicked
  else if (mouseX > 350 && mouseX < 350 + buttonWidth && mouseY > buttonYTop && mouseY < buttonYBottom) {
    openSettings();
  }
}
