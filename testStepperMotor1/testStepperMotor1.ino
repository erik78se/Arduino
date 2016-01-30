
/*
  
Bipolar motor: 42BYGHW208, 200steps/revolution
Hbridge: L298N

*/

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor
const int microdelay = 30; //between steps, determines the speed


#define COILA1 2
#define COILA2 3
#define COILB1 4
#define COILB2 5
#define ENA 12
#define ENB 13

// As your motor has steps, NEMA17
#define STEPS_PER_REVOLUTION 200

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(STEPS_PER_REVOLUTION, COILA1, COILA2, COILB1, COILB2);


/**
  This is useful if you need to use a voltage meter
  to figure out which pins,coils have current or not.
  It sets permanently high,low values as the motors should be at
  their first sequence.
**/
void setup_for_test() {
  // Enable both coils for PWN (not needed if jumper is on)
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  
  // Set output pins for the controller
  pinMode(COILA1, OUTPUT);
  pinMode(COILA2, OUTPUT);
  pinMode(COILB1, OUTPUT);
  pinMode(COILB2, OUTPUT);
  
  // Turn them on as they are in phase 1.
  digitalWrite(COILA1, HIGH);
  digitalWrite(COILA2, LOW);
  digitalWrite(COILB1, HIGH);
  digitalWrite(COILB2, LOW);

  // Now, use your voltage meter to see what is on/off.
}

void setup() {
  // Set some initial speed.
  // myStepper.setSpeed(130);
}


void stop() {
  digitalWrite(COILA1, LOW);
  digitalWrite(COILA2, LOW);
  digitalWrite(COILB1, LOW);
  digitalWrite(COILB2, LOW); 
}

void loop() {
  myStepper.setSpeed(90);
  myStepper.step(200);
  stop();
  delay(5000);
}
