//void sendCommandToESP32(String command) {
//  myPort.write(command);
//}

//void readFromESP32() {
//  if (myPort.available() > 0) {
//    String inData = myPort.readStringUntil('\n');
//    if (inData != null) {
//      // Process received data
//    }
//  }
//}
import processing.serial.*;
Serial arduinoPort;  // Create a Serial object

void sendTuneAndDurationToArduino(int[] tuneData, float[] durationData, int dataSize) {
  print("Sending tune and duration data to Arduino: ");
  // Convert tune and duration arrays to a format suitable for sending
  String dataToSend = "";

  for (int i = 0; i < currentSample; i++) {
    // Concatenate tune and duration values with a delimiter (e.g., comma)
    dataToSend += tune[i] + "," + duration[i] + ",";
  }

  println(dataToSend);
  // Send the data to Arduino
  arduinoPort.write(dataToSend);
}


void debugFromArduino() {
  if ( arduinoPort.available() > 0) {  // If data is available,
    String val = arduinoPort.readStringUntil('\n');         // read it and store it in val
    if (val != null) {
      println(val); // Print it out in the console
    }
  }
}
