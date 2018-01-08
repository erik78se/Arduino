/* 
   SerialAlarm.ino  

   Copyright: ImpactVision 2018, erik@impactvi.com
   License: Public Domain
   Description: Controls a relay via serial interface and resets by a button.
   
   Sending 1, turns the relay on.
   Sending 0. turns the relay off.

   Example command line usage: 
   
   $ echo 1 > /dev/ttyAMA0
   $ echo 0 > /dev/ttyAMA0

*/


int led = 13;
int relayPin = 2;
int buttonPin = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT);
	Serial.begin(9600);
  Serial.println("Setup complete.");
}

void loop() {
  int incomingByte = 0;
  int buttonState;

  buttonState = digitalRead(buttonPin);
  
  if ( buttonState == HIGH ) {
    clearAlarm();
  }

	if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if ( incomingByte == 49) {   
      // ASCII(49) = 1
      raiseAlarm();
  	}
  	if ( incomingByte == 48 ) {
      // ASCII(48) = 0
      clearAlarm();
  	}
	}

}

void raiseAlarm() {
  Serial.println("Alarm raised!");
  digitalWrite(led, HIGH);        // turn the LED on
  digitalWrite(relayPin, HIGH);   // turn the SIGNAL on
}

void clearAlarm() {
  Serial.println("Alarm cleared!");
  digitalWrite(led, LOW);         // turn the LED off
  digitalWrite(relayPin, LOW);    // turn the SIGNAL off
}

