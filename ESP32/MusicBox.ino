//import
#include <Servo.h>
//global variables 
int photoresistor = A0;  //var for storing the photoresistor value
const int buzzer = 9; //buzzer on pin 9
int tempo; //var to change the tempo of the buzzer's sound
Servo myServo; //servo object to control a Servo
int pos = 0; //var to store the servo position
bool pass = 0;

void setup() {
  pinMode(buzzer, OUTPUT);//set the buzzer as output
  myServo.attach(10); //attaches the servo on pin 10 to the servo object
  Serial.begin(9600); //start a serial connection with the computer
}

void loop() {
  photoresistor = analogRead(A0); //read value of photoresistor
  //Serial.print("Photoresistor value: ");
  //Serial.println(photoresistor); //print the photoresistor value to the serial monitor

  if (photoresistor < 7) {  //if it's dark, may have to change 
    stopSound(); //stop sound
    stopFigure(); //stop moving figurine
  } else if (photoresistor >= 7) { //if it's light, may have to change
    playSound(); //play sound
    //Serial.println("sufficient light");
   	moveFigure(); //move figurine
  }

  //delay(500); //short delay so that the printout is easier to read
}

//helper functions to create sound and movement
void playSound() {
  tone(buzzer, 1000); //send 1KHz sound signal
  //delay(100); //not sure if this is necessary
  //Serial.println("Buzzer playing");
}

void moveFigure() { //moves back and forth
  if (pos < 170 && pass == 0) { //first part of motor movement
    Serial.println("CASE 1");
    Serial.println(pos);
    myServo.write(pos);
    pos = pos + 1; //increment to move motor forward
    
  } else if (pos >= 170 && pass == 0) { //peak of motor movement
    Serial.println("CASE 2");
    pass = 1; //change to second part of motor movement
    Serial.println("Entered peak");
    Serial.println(pos);
    myServo.write(pos);
    pos = 169; //decrement to move motor back

  } else if (pos < 170 && pos > 0 && pass == 1) { //second part of motor movement
    Serial.println("CASE 3");
    Serial.println(pos);
    myServo.write(pos);
    pos = pos - 1; //decrement to move motor back
    
  } else if (pos <= 0) {
    Serial.println("CASE 4");
    pass = 0; //change to first part of motor movement
    Serial.println("Entered valley");
    Serial.println(pos);
    myServo.write(pos);
    pos = 1;
  }
}

void stopSound() {
  noTone(buzzer);
}

void stopFigure() {
  myServo.write(pos); //no movement
}
