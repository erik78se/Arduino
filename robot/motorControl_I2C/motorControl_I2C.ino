#include <Wire.h>

// i2C setup
#define SLAVE_ADDR 0x04
int number = 0;
int state = 0;

// Motors LEFT side (controls 2 motors)
const int controlPin1 = 3; 
const int controlPin2 = 5; 
// Motors RIGHT side (controls 2 motors)
const int controlPin3 = 9; 
const int controlPin4 = 11; 

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

  switch (number) {
      case 1:
        digitalWrite(13, HIGH); // set the LED on
        forward();
        break;
      case 2:
        reverse();
        break;
      case 3:
        left();
        break;
      case 4:
        right();
        break;
      default:
        halt();
        break;
      }
   }
}
// callback for sending data
void sendData(){
  Wire.write(number);
}

void reverse() {
  Serial.print("REVERSE");
  digitalWrite(controlPin1, HIGH);
  digitalWrite(controlPin2, LOW); 
  digitalWrite(controlPin3, HIGH);
  digitalWrite(controlPin4, LOW); 
}
void forward() {
  Serial.print("FORWARD");
  digitalWrite(controlPin1, LOW);
  digitalWrite(controlPin2, HIGH); 
  digitalWrite(controlPin3, LOW);
  digitalWrite(controlPin4, HIGH); 
}
void right() {
  Serial.print("LEFT");
  digitalWrite(controlPin1, LOW);
  digitalWrite(controlPin2, HIGH); 
  digitalWrite(controlPin3, HIGH);
  digitalWrite(controlPin4, LOW);
}
void left() {
  Serial.print("RIGHT");
  digitalWrite(controlPin1, HIGH);
  digitalWrite(controlPin2, LOW); 
  digitalWrite(controlPin3, LOW);
  digitalWrite(controlPin4, HIGH);
}

void halt() {
  Serial.print("STOP");
  digitalWrite(controlPin1, LOW);
  digitalWrite(controlPin2, LOW);
  digitalWrite(controlPin3, LOW);
  digitalWrite(controlPin4, LOW); 
}
