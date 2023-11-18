#include <Servo.h>
//global variables 
int photoresistor = A0;  //var for storing the photoresistor value
const int buzzer = 9; //buzzer on pin 9
int tempo; //var to change the tempo of the buzzer's sound
Servo myServo; //servo object to control a Servo
int pos = 0; //var to store the servo position
bool go = false;

void setup() {
  //set the buzzer as output
  pinMode(buzzer, OUTPUT); 
  myServo.attach(10); //attaches the servo on pin 10 to the servo object
  Serial.begin(9600);           //start a serial connection with the computer
}

void loop() {
  photoresistor = analogRead(A0); //read value of photoresistor
  Serial.print("Photoresistor value: ");
  Serial.println(photoresistor);          //print the photoresistor value to the serial monitor

  if (photoresistor < 7) {  //if it's dark 
    stopSound(); //stop sound
    stopFigure(); //stop moving figurine
  } else if (photoresistor >= 7) { //if it's light
    playSound(); //play sound
    Serial.println("sufficient light");
   	moveFigure(); //move figurine
  }

  //delay(500); //short delay so that the printout is easier to read
}

//helper functions to create sound and movement
void playSound() {
  //while (go) {
    tone(buzzer, 1000); //send 1KHz sound signal
    //delay(100); //not sure if this is necessary
    //Serial.println("Buzzer playing");
  //}
}

void moveFigure() { //moves back and forth
    for (pos = 0; pos <= 170; pos = pos + 1) { //around 170 is max for servo
      myServo.write(pos);
      delay(10);
    }
    for (pos = 170; pos >= 0; pos = pos - 1) {
      myServo.write(pos);
      delay(10);
    }
  //myServo.write(360); //not using pos because we want continuous movement
  Serial.println("Servo has been moved");
}

void stopSound() {
  noTone(buzzer);
}

void stopFigure() {
  myServo.write(-95); //no movement
}
