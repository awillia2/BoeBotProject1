#include <QTRSensors.h>
#include <Servo.h>
#define NUM_SENSORS   3     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2
// sensors 1 through 3 are connected to digital pins 2 through 4, respectively
QTRSensorsRC qtrrc((unsigned char[]) {2,3,4}, NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];
//  Declare instance of Servo and then init to the proper pins
Servo servoRight;
Servo servoLeft;

void setup() {
  servoRight.attach(13);
  servoLeft.attach(12);
  
  Serial.begin(9600);

  for(int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(qtrrc.calibratedMinimumOn[i]);
    Serial.print("loop: " + i);
  }
  
  Serial.println();

  for(int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(qtrrc.calibratedMaximumOn[i]);
    Serial.print("loop: " + i);
  }
  
  Serial.println();
  Serial.println();
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(sensorValues[0] && sensorValues[1] && sensorValues[2]) {
    //1 and 2 and 3 are black STOP  
    
  } else(sensorValues[0] && sensorValues[1] && sensorValues[2]) {
    //1 and 2 and 3 are white FORWARD
    
  } else if(sensorValues[0]) {
    //1 is black LEFT
    
  } else ifsensorValues[2]) {
    //3 is black RIGHT
    
  } else {
    //Error condition met. Output error and STOP
    
  }
}

void turnRight() {}
void turnLeft() {}
void moveForward() {}
void stopRobot() {}


