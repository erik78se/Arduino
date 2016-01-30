/* Sweep
 by BARRAGAN <http://barraganstudio.com> 
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/ 

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
  int pos = 0;
  myservo.write(pos);
  delay(4000);
  pos = 90;                                
  myservo.write(pos);              // tell servo to go to position in variable 'pos' 
  delay(2000);
  pos = 175;                                
  myservo.write(pos);              // tell servo to go to position in variable 'pos' 
  delay(2000);
} 

