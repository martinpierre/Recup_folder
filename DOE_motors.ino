/* 
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control
// Test desktop github 
// Second test
For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438
*/


#include <Wire.h>
#include <Adafruit_MotorShield.h>
#define STEPS 20

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
Adafruit_StepperMotor *myMotor = AFMS.getStepper(STEPS, 2);

//Adafruit_StepperMotor *step_by = AFMS.getStepper(512, 1);


int i = 0;
 float t0;
 float t1=0;
void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");
  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  myMotor->setSpeed(60);  // 10 rpm   
}

void loop() {
  for( i=0; i <20; i++){
  long t0 = millis();
  Serial.println("Single coil steps");
  myMotor->step(20, FORWARD,INTERLEAVE );
  //myMotor->step(10, BACKWARD, SINGLE);
  long t1 = millis();
  Serial.print(" measured RPM is ");
  Serial.println(60000.0 / (t1 - t0));
  }

  for( i=0; i <20; i++){
  long t0 = millis();
  Serial.println("Single coil steps");
 // myMotor->step(10, FORWARD, SINGLE);
  myMotor->step(20, BACKWARD, INTERLEAVE);
  long t1 = millis();
  Serial.print(" measured RPM is ");
  Serial.println(60000.0 / (t1 - t0));
  }
  /*myMotor->release();
  delay(5000);*/
  /*myMotor->step(206, FORWARD, SINGLE);
  myMotor->step(206, BACKWARD, SINGLE);*/
}
