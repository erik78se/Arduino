/* serial_control:
 *  Consumes <Twist> messages
 *  Transforms them into speed instructions for motors
 *  
 *  
*/
#include <ros.h>
#include <geometry_msgs/Twist.h>

// SERIAL COMMUNICATION
#define ROS_SERIAL_BAUD_RATE 57600

// MOTORS
#define LEFT_PIN_A   2
#define LEFT_PIN_B   3
#define RIGHT_PIN_A  9
#define RIGHT_PIN_B  11

//WHEEL DISTANCE
#define WHEEL_DIST 10.0 //cm

ros::NodeHandle nh;

geometry_msgs::Twist twist_msg;

////////////////////////////////////////////////////////////
// Motor drive
//
// TODO: investigate https://github.com/joshvillbrandt/legorov-ros-pkg/blob/master/arduino/LegorovController/LegorovController.pde
//
// cmd_x  : linear x velocity (forward velocity) m/s
// cmd_th : angular z velocity (rotation of heading) rad/s
void diff_drive(double cmd_x, double cmd_th) {
  float speed_wish_right = cmd_th*M_PI*WHEEL_DIST/2 + cmd_x;
  float speed_wish_left = cmd_x*2-speed_wish_right;
  /* This is where we acctually move motors later.
   *  For now, just print to console.
   */
  char log_msg[20];
  sprintf(log_msg, "L: %d", (int)(speed_wish_right*255));
  nh.loginfo(log_msg);
  sprintf(log_msg, "R: %d", (int)(speed_wish_left*255));
  nh.loginfo(log_msg); 
}

void cmd_vel_callback( const geometry_msgs::Twist& twist_msg) {
  diff_drive(twist_msg.linear.x, twist_msg.angular.z);
}

ros::Subscriber<geometry_msgs::Twist> cmd_vel_topic("cmd_vel", &cmd_vel_callback);

void setup() {
  nh.getHardware()->setBaud(ROS_SERIAL_BAUD_RATE);
  nh.initNode();
  nh.subscribe(cmd_vel_topic);
  nh.loginfo("Setup complete");
}


void loop() {
  nh.spinOnce();
}



