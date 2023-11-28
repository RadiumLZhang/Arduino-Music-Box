
void moveServo() {
  // Check if the servo is attached
  if (myServo.attached()) {
    // Check the lightSwitch variable before moving the servo
    if (lightSwitch) {
      // Increment or decrement the servo position
      servoPosition += servoDirection;
      // Check if we've reached the limits (0 or 180 degrees)
      if (servoPosition <= 0 || servoPosition >= 180) {
        servoDirection *= -1;  // Reverse direction
      }
      // Move the servo to the current position
      myServo.write(servoPosition);
    }
  }
}