#include <Wire.h>

// i2C setup
#define SLAVE_ADDR 0x04
int number = 0;
int state = 0;

// Left motor Hbridge pins
const int controlPin1 = 9; 
const int controlPin2 = 11;

// Right motor Hbridge pins
const int controlPin3 = 3; 
const int controlPin4 = 5;


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
  // while(true) {
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
  digitalWrite(controlPin3, HIGH);
  digitalWrite(controlPin4, LOW); 
}
void motorBackward() {
  Serial.print("BACKWARD");
  digitalWrite(controlPin1, LOW);
  digitalWrite(controlPin2, HIGH);
  digitalWrite(controlPin3, LOW);
  digitalWrite(controlPin4, HIGH); 
}
void motorStop() {
  Serial.print("STOP");
  digitalWrite(controlPin1, LOW);
  digitalWrite(controlPin2, LOW);
  digitalWrite(controlPin3, LOW);
  digitalWrite(controlPin4, LOW); 
}
