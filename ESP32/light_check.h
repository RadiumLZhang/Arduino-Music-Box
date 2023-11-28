void checkLight() {
  // Analog read
  int ldrValue = analogRead(ldrPin);
  // Check if light level is above a threshold (e.g., 100)
  lightSwitch = ldrValue > 100;
  // You can use the lightSwitch variable for further logic
  // Check the lightSwitch variable and stop the song and motion if needed
  if (!lightSwitch) {
    noTone(buzzerPin);  // Stop playing the tune
    // Optionally, you can stop the servo motion as well
    // servoDirection = 0;
  }
}