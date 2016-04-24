# What is this?
# ======================
#
# This code is for testing serial comminucation with a arduino and a raspberry pi
# For example on a raspberry pi 2 -> [tty/serial] -> arduino 
#
# Assuming you have a ubuntu 14.04 on your raspberry pi
# ======================
# Remove from /boot/cmdline.txt 
#     console=/dev/tty1
# 
# Then move away the tty1.conf
# mv /etc/init/tty1.conf /etc/init/tty1.conf.disabled
# reboot
#
# Program the arduino
# ======================
# With this code.
# 
# Problems uploading?
# ======================
# Make sure RX[0] on your arduino is not connected, 
# or you won’t be able to load code on the arduino!
#
# Run the test
# =======================
# On the raspberry, test the code by:
#    minicom -b 9600 -o -D /dev/ttyAMA
#
# When you type a character into the console, 
# it will received by the Arduino, and it will send the corresponding ASCII code back. Check here for ASCII Table. 
# And there it is, the Raspberry Pi is talking to the Arduino over GPIO serial port.
#


byte number = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  if (Serial.available()) {
  number = Serial.read();
  Serial.print("character recieved: ");
  Serial.println(number, DEC);
  }
}
