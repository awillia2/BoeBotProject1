#include <Servo.h>

Servo servoLeft;          // Define left servo
Servo servoRight;         // Define right servo

void setup() { 
  Serial.begin(9600);      // open the serial port at 9600 bps:    
  servoLeft.attach(12);  // Set left servo to digital pin 10
  servoRight.attach(13);  // Set right servo to digital pin 9
  
} 

void loop() {            // Loop through motion tests
  forward();             // Example: move forward
  delay(2000);           // Wait 2000 milliseconds (2 seconds)
  
}

// Motion routines for forward, reverse, turns, and stop
void forward() {
  Serial.println("forward");
  servoLeft.write(180);
  servoRight.write(0);
}
void reverse() {
  Serial.println("reverse");
  servoLeft.write(0);
  servoRight.write(180);
}
void turnRight() {
  Serial.println("turnRight");
  servoLeft.writeMicroseconds(180);
  servoRight.writeMicroseconds(180);
}
void turnLeft() {
  Serial.println("turnLeft");
  servoLeft.writeMicroseconds(0);
  servoRight.writeMicroseconds(0);
}

void stopRobot() {
  Serial.println("stopRobot");
  servoLeft.write(90);
  servoRight.write(90);
}
