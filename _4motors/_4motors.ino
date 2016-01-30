
/*
  
Bipolar motor: 42BYGHW208, 200steps/revolution
Hbridge: L298N

*/

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor
const int microdelay = 30; //between steps, determines the speed


#define FL_COILA1 2
#define FL_COILA2 3
#define FL_COILB1 4
#define FL_COILB2 5

#define FR_COILA1 6
#define FR_COILA2 7
#define FR_COILB1 8
#define FR_COILB2 9

#define BL_COILA1 10
#define BL_COILA2 11
#define BL_COILB1 12
#define BL_COILB2 13

#define BR_COILA1 14
#define BR_COILA2 15
#define BR_COILB1 16
#define BR_COILB2 17

// As your motor has steps, NEMA17
#define STEPS_PER_REVOLUTION 200

// initialize the stepper library on pins
Stepper FL_Stepper(STEPS_PER_REVOLUTION, FL_COILA1, FL_COILA2, FL_COILB1, FL_COILB2);
Stepper FR_Stepper(STEPS_PER_REVOLUTION, FR_COILA1, FR_COILA2, FR_COILB1, FR_COILB2);
Stepper BL_Stepper(STEPS_PER_REVOLUTION, BL_COILA1, BL_COILA2, BL_COILB1, BL_COILB2);
Stepper BR_Stepper(STEPS_PER_REVOLUTION, BR_COILA1, BR_COILA2, BR_COILB1, BR_COILB2);

void setup() {
  FL_Stepper.setSpeed(90);
  FR_Stepper.setSpeed(90);
  BL_Stepper.setSpeed(90);
  BR_Stepper.setSpeed(90);
  // Set some initial speed.
  // myStepper.setSpeed(130);
}


void stop() {
  digitalWrite(FL_COILA1, LOW);
  digitalWrite(FL_COILA2, LOW);
  digitalWrite(FL_COILB1, LOW);
  digitalWrite(FL_COILB2, LOW);
  digitalWrite(FR_COILA1, LOW);
  digitalWrite(FR_COILA2, LOW);
  digitalWrite(FR_COILB1, LOW);
  digitalWrite(FR_COILB2, LOW);
  digitalWrite(BL_COILA1, LOW);
  digitalWrite(BL_COILA2, LOW);
  digitalWrite(BL_COILB1, LOW);
  digitalWrite(BL_COILB2, LOW);
  digitalWrite(BR_COILA1, LOW);
  digitalWrite(BR_COILA2, LOW);
  digitalWrite(BR_COILB1, LOW);
  digitalWrite(BR_COILB2, LOW); 
}

void loop() {
  FL_Stepper.step(200);
  stop();
  FR_Stepper.step(200);
  stop();
  BL_Stepper.step(200);
  stop();
  BR_Stepper.step(200);
  stop();
  delay(1000);
}
