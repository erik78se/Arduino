# Setup
* ROS version: jade
* rosserial_python

# Enable programming the Arduino-mini-pro from Serial
# Arduino(DRT) -> GPI17(Rpi2)
apt-get install arduino-mk

# Create a package "robojoy" with dependencies
catkin_create_pkg robojoy std_msgs rospy roscpp joy teleop_twist_joy rosserial_python

cd catkin_ws/
source ./devel/setup.sh

# On master
roscore -v

# On joystick node
rosrun joy joy_node

# On joystick node
rosrun teleop_twist_joy teleop_node

# Test to see twist messaged on /cmd_vel topic
rostopic echo /cmd_vel

# On the arduino serial connected node
rosrun rosserial_python serial_node.py /dev/ttyAMA0

# Alternative, use the launchfile
