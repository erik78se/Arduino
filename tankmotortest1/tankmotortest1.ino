/**


**/

const int LcontrolPin1 = 3; // connected to pin 7 on the H-bridge
const int LcontrolPin2 = 4; // connected to pin 2 on the H-bridge
const int RcontrolPin1 = 7; // connected to pin 15 on the H-bridge
const int RcontrolPin2 = 8; // connected to pin 10 on the H-bridge

// PWM speed
const int LenablePin = 5;   // connected to pin 1 on the H-bridge
const int RenablePin = 6;   // connected to pin 1 on the H-bridge


// const int directionSwitchPin = 4;  // connected to the switch for direction
// const int onOffSwitchStateSwitchPin = 5; // connected to the switch for turning the motor on and off
// const int potPin = A0;  // connected to the potentiometer's output

// create some variables to hold values from your inputs
int onOffSwitchState = 0;  // current state of the On/Off switch
int previousOnOffSwitchState = 0; // previous position of the on/off switch
int directionSwitchState = 0;  // current state of the direction switch
int previousDirectionSwitchState = 0;  // previous state of the direction switch

int motorEnabled = 0; // Turns the motor on/off
int motorSpeed = 0; // speed of the motor
int motorDirection = 1; // current direction of the motor




void setup() {
  // intialize the inputs and outputs
  // pinMode(directionSwitchPin, INPUT);
  // pinMode(onOffSwitchStateSwitchPin, INPUT);
  pinMode(LcontrolPin1, OUTPUT);
  pinMode(LcontrolPin2, OUTPUT);
  pinMode(RcontrolPin1, OUTPUT);
  pinMode(RcontrolPin2, OUTPUT);
  pinMode(LenablePin, OUTPUT);
  pinMode(RenablePin, OUTPUT);
  // pull the enable pin LOW to start
  digitalWrite(LenablePin, LOW);
  digitalWrite(RenablePin, LOW);

  analogWrite(LenablePin, motorSpeed);
  analogWrite(RenablePin, motorSpeed);
}


/**
  forward both motors with speed.
**/
void forward() {
    analogWrite(LenablePin, motorSpeed);
    analogWrite(RenablePin, motorSpeed);
    digitalWrite(LcontrolPin1, LOW);
    digitalWrite(LcontrolPin2, HIGH);
    digitalWrite(RcontrolPin1, LOW);
    digitalWrite(RcontrolPin2, HIGH);
}



/**
  reverse
**/
void reverse() {
    analogWrite(LenablePin, motorSpeed);
    analogWrite(RenablePin, motorSpeed);
    digitalWrite(LcontrolPin1, HIGH);
    digitalWrite(LcontrolPin2, LOW);
    digitalWrite(RcontrolPin1, HIGH);
    digitalWrite(RcontrolPin2, LOW);
}

/**
  halt motors.
**/
void halt() {
    analogWrite(LenablePin, 0);
    analogWrite(RenablePin, 0);
    digitalWrite(LcontrolPin1, LOW);
    digitalWrite(LcontrolPin2, LOW);
    digitalWrite(RcontrolPin1, LOW);
    digitalWrite(RcontrolPin2, LOW);
}

/**
  left
**/
void left() {
    analogWrite(LenablePin, motorSpeed);
    analogWrite(RenablePin, motorSpeed);
    digitalWrite(LcontrolPin1, HIGH);
    digitalWrite(LcontrolPin2, LOW);
    digitalWrite(RcontrolPin1, LOW);
    digitalWrite(RcontrolPin2, HIGH);
}


/**
  right 
**/
void right() {
    analogWrite(LenablePin, motorSpeed);
    analogWrite(RenablePin, motorSpeed);
    digitalWrite(LcontrolPin1, LOW);
    digitalWrite(LcontrolPin2, HIGH);
    digitalWrite(RcontrolPin1, HIGH);
    digitalWrite(RcontrolPin2, LOW);
}


void setSpeed(int s) {
   motorSpeed = s; 
}

void motorJogg() {
    // Motors for the tank range between 180 and 255  
  forward();
  delay(500);
  halt();
  delay(500);
  reverse();
  delay(500);
  halt();
  delay(500);
  left();
  delay(500);
  halt();
  delay(500);
  right();
  delay(500);
  halt();
  delay(500);
}


void loop() {
   setSpeed(255);
   motorJogg();
}
