/* serial_control:
 *  Consumes <Twist> messages
 *  Transforms them into speed instructions for motors
 *  
 *  After programming the arduino: 
 *  $ rosrun rosserial_python serial_node.py /dev/ttyAMA0
 *  
*/
#include <ros.h>
#include <geometry_msgs/Twist.h>

// SERIAL COMMUNICATION
#define ROS_SERIAL_BAUD_RATE 57600

// MOTORS
#define E1 10   // Enable Pin for motor 1
#define E2 6    // Enable Pin for motor 2
#define I1 3    // Control pin 1 for motor 1
#define I2 5    // Control pin 2 for motor 1
#define I3 9    // Control pin 1 for motor 2
#define I4 11   // Control pin 2 for motor 2
#define WHEEL_DIST 0.1

ros::NodeHandle nh;

geometry_msgs::Twist twist_msg;

double lspeed = 0;
double rspeed = 0;

void MotorSpeeds(float left, float right) {
  lspeed = left*255;
  rspeed = right*255;
  
  analogWrite(E1, lspeed);  // Set left motor speed
  analogWrite(E2, rspeed);  // Set right motor speed

  // Set direction of the two motors based on the sign of the speed
  if ( left >= 0 ) {
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
  } else {
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
  }
  if ( right >= 0 ) {
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
  } else {
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
  }

}

////////////////////////////////////////////////////////////
// Motor drive
//
// TODO: investigate https://github.com/joshvillbrandt/legorov-ros-pkg/blob/master/arduino/LegorovController/LegorovController.pde
//
// cmd_x  : linear x velocity (forward velocity) m/s
// cmd_th : angular z velocity (rotation of heading) rad/s
void diff_drive(float cmd_x, float cmd_th) {
  float speed_wish_right = cmd_th*M_PI*WHEEL_DIST/2 + cmd_x;
  float speed_wish_left = cmd_x*2-speed_wish_right;
  /* This is where we acctually move motors later.
   *  For now, just print to console.
   */
  char log_msg[200];
  // dtostrf(floatVar, minStringWidthIncDecimalPoint, numVarsAfterDecimal, charBuf);
  dtostrf(cmd_x*255, 1, 4, log_msg);
  nh.loginfo(log_msg);
  
  
  // sprintf(log_msg, "R: %d", (double)(speed_wish_left));
  // nh.loginfo(log_msg); 

  MotorSpeeds(cmd_x,cmd_x);
  
}

void cmd_vel_callback( const geometry_msgs::Twist& twist_msg) {
  diff_drive(twist_msg.linear.x, twist_msg.angular.z);
}

ros::Subscriber<geometry_msgs::Twist> cmd_vel_topic("cmd_vel", &cmd_vel_callback);


void setupPins() {
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);
}



void setup() {
  nh.getHardware()->setBaud(ROS_SERIAL_BAUD_RATE);
  nh.initNode();
  nh.subscribe(cmd_vel_topic);
  nh.loginfo("Serial setup complete");
  
  setupPins();
  nh.loginfo("Pins setup complete");
}




void loop() {
  nh.spinOnce();
}


