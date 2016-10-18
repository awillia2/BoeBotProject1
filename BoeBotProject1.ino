#include <QTRSensors.h>
#include <Servo.h>
  Servo servoRight; // Define right servo
  Servo servoLeft;  // Define left servo
#define NUM_SENSORS   3     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
// sensors 1 through 3 are connected to digital pins 2 through 4, respectively
QTRSensorsRC qtrrc((unsigned char[]) {2,3,4}, NUM_SENSORS, TIMEOUT); 
unsigned int sensorValues[NUM_SENSORS];

void setup() {
//  Declare instance of Servo and then init to the proper pins
  servoRight.attach(13);
  servoLeft.attach(12);
  
  Serial.begin(9600);

  for(int i = 0; i < NUM_SENSORS; i++) {
    Serial.println(qtrrc.calibratedMinimumOn[i]);
    Serial.println("loop: " + i);
  }
  
  Serial.println();

  for(int i = 0; i < NUM_SENSORS; i++) {
    Serial.println(qtrrc.calibratedMaximumOn[i]);
    Serial.println("loop: " + i);
  }
  
  Serial.println();
  Serial.println();
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  qtrrc.read(sensorValues);
  servoLeft.writeMicroseconds(1400);//Always Under 1500. This is driving forward.
  servoRight.writeMicroseconds(1600);//Always Above 1500. 1515
  
  for(unsigned char i = 0; i < NUM_SENSORS; i++) {
    Serial.println(sensorValues[i]);
  }
  
  if(sensorValues[0] > 400) {
    Serial.println("Sensor 0: " + sensorValues[0]);
    turn(1500,2000, 1000);  // left turn
  }

  turn(1400, 1600, 0); // Moving forward
     
  if(sensorValues[2] > 400) {
    Serial.println("Sensor 2: " + sensorValues[2]);
    turn(1000, 1500, 1000); // right turn
  }
  
  delay(1000);  

}

void turn(int left, int right, int delayTime) {
  servoLeft.writeMicroseconds(left);
  servoRight.writeMicroseconds(right);
  delay(delayTime);
}
