import processing.serial.*;

Serial arduinoPort;
int[] melody = {262, 262, 392, 392, 440, 440, 392, 349, 349, 329, 329, 294, 294, 262, 392, 392, 349, 349, 329, 329, 294, 392, 392, 349, 349, 329, 329, 294, 262, 262, 392, 392, 440, 440, 392, 349, 349, 329, 329, 294, 294, 262};
int noteDuration = 1000; // Duration of each note in milliseconds

void setup() {
  println(Serial.list());
  arduinoPort = new Serial(this, Serial.list()[1], 9600); // Adjust the index [0] as per your serial port
  playMelody();
}

void playMelody() {
  for (int i = 0; i < melody.length; i++) {
    arduinoPort.write(melody[i] + "\n");
    delay(noteDuration);
  }
}
