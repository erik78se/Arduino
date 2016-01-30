#include <Wire.h>

// i2C setup
#define SLAVE_ADDR 0x04
int number = 0;
int state = 0;

// Motor Hbridge on Pin2+3
const int controlPin1 = 2; 
const int controlPin2 = 3; 
bool motorEnabled = false; // Turns the motor on/off
int motorSpeed = 0; // speed of the motor
int motorDirection = 1; // current direction of the motor



void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600); 
  // start serial for output
  // initialize i2c as slave
  Wire.begin(SLAVE_ADDR);
  
  // define callbacks for i2c communication
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);

  Serial.println("Ready!");
}

void loop() {
  delay(100);
}

// callback for received data
void receiveData(int byteCount){

  while(Wire.available()) {
    number = Wire.read();
    Serial.print("data received: ");
    Serial.println(number);

  if (number == 1){
    if (state == 0){
      digitalWrite(13, HIGH); // set the LED on
      motorForward();
      state = 1;
    } 
    else {
      digitalWrite(13, LOW); // set the LED off
      motorStop();
      state = 0;
         }
    }
  }
}

// callback for sending data
void sendData(){
  Wire.write(number);
}

void motorForward() {
  Serial.print("FORWARD");
  digitalWrite(controlPin1, HIGH);
  digitalWrite(controlPin2, LOW); 
}
void motorBackward() {
  Serial.print("BACKWARD");
  digitalWrite(controlPin1, LOW);
  digitalWrite(controlPin2, HIGH); 
}
void motorStop() {
  Serial.print("STOP");
  digitalWrite(controlPin1, LOW);
  digitalWrite(controlPin2, LOW); 
}
