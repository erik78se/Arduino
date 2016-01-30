// MultiStepper.pde
// -*- mode: C++ -*-
//
// Shows how to multiple simultaneous steppers
// Runs one stepper forwards and backwards, accelerating and decelerating
// at the limits. Runs other steppers at the same time
//
// Copyright (C) 2009 Mike McCauley
// $Id: HRFMessage.h,v 1.1 2009/08/15 05:32:58 mikem Exp mikem $

#include <AccelStepper.h>

// Define some steppers and the pins the will use
AccelStepper stepper1; // Defaults to 4 pins on 2, 3, 4, 5
AccelStepper stepper2(4, 6, 7, 8, 9);
AccelStepper stepper3(4, 10, 11, 12, 13);
AccelStepper stepper4(4, 14, 15, 16, 17);

void setup()
{  
    stepper1.setMaxSpeed(200.0);
    stepper1.setAcceleration(200.0);
    stepper1.moveTo(90);
    
    stepper2.setMaxSpeed(300.0);
    stepper2.setAcceleration(300.0);
    stepper2.moveTo(90);
    
    stepper3.setMaxSpeed(400.0);
    stepper3.setAcceleration(400.0);
    stepper3.moveTo(90);
   
    stepper4.setMaxSpeed(500.0);
    stepper4.setAcceleration(500.0);
    stepper4.moveTo(90); 
}

void loop()
{
    // Change direction at the limits
    if (stepper1.distanceToGo() == 0) {
	stepper1.moveTo(-stepper1.currentPosition());  
    }
    
    if (stepper2.distanceToGo() == 0) {
	stepper2.moveTo(-stepper2.currentPosition());
    }
    
    if (stepper3.distanceToGo() == 0) {
	stepper3.moveTo(-stepper3.currentPosition());
    }
    
    if (stepper4.distanceToGo() == 0) {
	stepper4.moveTo(-stepper4.currentPosition());
    }
    
    stepper1.run();
    stepper2.run();
    stepper3.run();
    stepper4.run();
 
    /**
    stepper1.run();
    stepper2.run();
    stepper3.run();
    stepper4.run();
    **/
}
