/*
  Arduino Starter Kit example
 Project 10  - Zoetrope

 This sketch is written to accompany Project 10 in the
 Arduino Starter Kit

 Parts required:
 two 10 kilohm resistors
 2 momentary pushbuttons
 one 10 kilohm potentiometer
 motor
 9V battery
 H-Bridge

 Created 13 September 2012
 by Scott Fitzgerald
 Thanks to Federico Vanzati for improvements

 http://arduino.cc/starterKit

 This example code is part of the public domain
 */

const int controlPin1 = 2; 
const int controlPin2 = 3; 

const int controlPin3 = 7; 
const int controlPin4 = 8; 

const int enablePin = 9;   // connected to pin 1 on the H-bridge



bool motorEnabled = false; // Turns the motor on/off
int motorSpeed = 0; // speed of the motor
int motorDirection = 1; // current direction of the motor

void setup() {
  Serial.begin(9600);
  
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(controlPin3, OUTPUT);
  pinMode(controlPin4, OUTPUT);
  
  pinMode(enablePin, OUTPUT);
  // pull the enable pin LOW to start
  digitalWrite(enablePin, LOW);

  pinMode(13, OUTPUT);
}

void loop() {
  Serial.println("MOTOR RAN");
  motorEnabled = true;
  motorSpeed = 1 / 2;
  digitalWrite(13, HIGH);
  delay(1500);
  digitalWrite(13, LOW);
  delay(1500);
  // change the direction the motor spins by talking
  // to the control pins on the H-Bridge
  if (motorDirection == 1) {
    motorDirection = 0;
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
    
    digitalWrite(controlPin3, HIGH);
    digitalWrite(controlPin4, LOW);
  }
  else {
    motorDirection = 1;
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
    
    digitalWrite(controlPin3, LOW);
    digitalWrite(controlPin4, HIGH);
  }
  
}


