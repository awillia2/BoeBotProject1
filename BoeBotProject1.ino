#include <QTRSensors.h>
#include <Servo.h>
#define NUM_SENSORS   3     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2
// sensors 1 through 3 are connected to digital pins 2 through 4, respectively
QTRSensorsRC qtrrc((unsigned char[]) {2,3,4}, NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];

void setup() {
  // put your setup code here, to run once:
  Servo servoRight;
  Servo servoLeft;
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
//  Servo servoRight;
//  Servo servoLeft;
  servoRight.attach(13);
  servoLeft.attach(12);
  
  /*servoLeft.writeMicroseconds(1000);//Always Under 1500. This is driving forward.1485
  servoRight.writeMicroseconds(2000);//Always Above 1500. 1515*/
  qtrrc.read(sensorValues);
  servoLeft.writeMicroseconds(1400);//Always Under 1500. This is driving forward.
  servoRight.writeMicroseconds(1600);//Always Above 1500. 1515
  for(unsigned char i = 0; i < NUM_SENSORS; i++) {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  
  if(sensorValues[0] < 400) {
    Serial.print("\nSensor 0: ");
    Serial.print(sensorValues[0]);
    servoLeft.writeMicroseconds(1500);//Always Under 1500. This is turning left.
    servoRight.writeMicroseconds(1600);//Always Above 1500-this changes
  }
      
  if(sensorValues[2] < 400) {
    Serial.print("\nSensor 2: ");
    Serial.print(sensorValues[2]);
    servoLeft.writeMicroseconds(1400);//Always Under 1500-this changes 
    servoRight.writeMicroseconds(1500);//Always Above 1500. This is turning right.
  }

  Serial.println(); // uncomment this line if you are using raw values
  //Serial.println(position); // comment this line out if you are using raw values
  
  delay(1000);
  
}


