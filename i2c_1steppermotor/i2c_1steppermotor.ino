#include <Wire.h>
#include <AccelStepper.h>

#define COILA1 2
#define COILA2 3
#define COILB1 4
#define COILB2 5
#define ENA 12
#define ENB 13

AccelStepper stepper1; // Defaults to 4 pins on 2, 3, 4, 5

// As your motor has steps, NEMA17
#define STEPS_PER_REVOLUTION 200

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor
const int microdelay = 30; //between steps, determines the speed

// initialize the stepper library on pins
// Stepper myStepper(STEPS_PER_REVOLUTION, COILA1, COILA2, COILB1, COILB2);

// i2c address for slave
#define SLAVE_ADDR 0x04

int number = 0;

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600); 
  // start serial for output
  // initialize i2c as slave
  Wire.begin(SLAVE_ADDR);
  
  // define callbacks for i2c communication
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);

  stepper1.setMaxSpeed(200.0);
  stepper1.setAcceleration(200.0);
  stepper1.moveTo(180);
  stepper1.run();
  Serial.println("Ready!");
  // stop();
}

void loop() {
  if (stepper1.distanceToGo() == 0) {
    stop();
  } else {
    stepper1.run();
  }
  // Serial.print("running");
  // delay(3000);
}

// Stepper stop function
void stop() {
  Serial.print("Stopped.");
  digitalWrite(COILA1, LOW);
  digitalWrite(COILA2, LOW);
  digitalWrite(COILB1, LOW);
  digitalWrite(COILB2, LOW); 
}


// callback for received data
void receiveData(int byteCount){
  while( Wire.available() ) {
    number = Wire.read();
    Serial.print("data received: ");
    Serial.println(number);
    stepper1.moveTo(number);
  }
}

// callback for sending data
void sendData(){
  Wire.write(number);
}
