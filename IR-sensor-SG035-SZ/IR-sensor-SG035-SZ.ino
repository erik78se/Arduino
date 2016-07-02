/*
 IR Infrared Obstacle Avoidance Sensor Module 
 Arduino Smart Car Robot 3-wire  
 SG035-SZ

Description of the module SG035-SZ:

    1.  When the module detects obstacles in front of the signal,
        the indicator led lights up when collision is detected.
        A continuous output signal is on the OUT port.    
        The module detects the distance 2cm ~ 30cm, detection angle 35 °.
        The detection distance is adjusted with the potentiometer.
        Distance increases clockwise.
    2.  Active infrared sensors detect reflection, 
        thus the shape of the reflectivity of the target detection in range is critical. 
        The minimum detection distance is black, white maximum. 
        Small objects from a small area, a large area from large objects.
    3.  The output port OUT sensor module can be directly connected to the microcontroller IO port , 
        you can directly drive a 5V relay ; Connection : VCC-VCC; GND-GND; OUT-IO.
    4.  Using the comparator LM393 is stable.
    5.  Can be used with 3-5V DC power supply modules. 
        When the power is turned on the power led is active.
    6.  Screw holes are 3mm.
    7.  Board size: 3.1CM * 1.5CM.
    

Interface Description (3-wire):

    1. VCC: External 3.3V-5V voltage 
       (can be directly connected to 5v MCU and 3.3v MCU)
    2. GND: GND External
    3. OUT: Digital output interfaces (0 and 1)


   @Author: Erik Lönroth
   @License: GPLv2
*/

//Use pin 13
int irSensor = 13;

void setup() {
  Serial.begin(115200);
  Serial.println("setup()");
  pinMode(irSensor, INPUT);
}


int irState;     
int numColl = 0; // Count collisions
void loop() {
  irState= digitalRead(irSensor);
  if (irState == 0 ) {
    numColl++;
    Serial.println("Collision ");
    Serial.println(numColl);
    delay(1);
  }
}
