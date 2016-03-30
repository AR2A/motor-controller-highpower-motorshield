# motor-controller-highpower-motorshield
Repository for the brushed motor controller based on the LXRobotics Highpower Motorshield.

##1. Introduction
This motor-controller-package based on rosserial_arduino 
brings support for the brushed motor controller based on the LXRobotics Highpower Motorshield to ROS (Robot Operating System) 
and can be easily adapted for other motor-shields.

**1.2. Features**
* Own message-type for speed (8-bit value) and direction which can be adapted for individual needs.
* Includes a heartbeat-service that calls a user-specific task if the arduino is disconnected from ROS. For example: stop the motor if ROS does not respond.

**1.3. Overview**
![alt tag](https://raw.githubusercontent.com/AR2A/motor-controller-highpower-motorshield/master/doc/img/schematic_overview.png)

**1.4. Dependencies**

This software is built on the Robotic Operating System (ROS - Indigo) and on the Arduino IDE, which needs to be installed first. For further information how to install ROS see http://wiki.ros.org/indigo/Installation and for how to run the Arduino IDE directly in ROS see section 3.Installing the Software on http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup


##2. How to Install
In order to install the motor controller, clone the latest version from the repository into your catkin workspace, compile the packages and upload to the Arduino Uno using ROS.

**2.1.Download the Source Code**

Move to the src-folder in your catkin-workspace:

    $ cd ~/catkin_ws/src/

Clone the repository:

    $ git clone https://github.com/AR2A/motor-controller-highpower-motorshield


**2.2. Build the Packages**

Move to your catkin-workspace:

    $ cd ~/catkin_ws/

Compile the packages:

    $ catkin_make

**2.3 Upload to the Arduino Uno**

Now connect an Arduino Uno, confirm that it comes up as /dev/ttyACM1 (or change the firmware's CMakeLists.txt accordingly), and program it:

    $ catkin_make arduino_motor_control-upload


##3. How to Launche
Move to your catkin-workspace:

    $ cd ~/catkin_ws/

To add the workspace to your ROS environment you need to source the generated setup file:

    $ source devel/setup.bash

You can launch the motor controller node with:

    $ roslaunch motor_startup motor_startup.launch


##4. ROS API

**4.1. Node: arduino_motor_control**

This Node runs directly on the Arduino Uno, monitors the current power consumption, controls the motor and includes a heartbeat-service that calls a user-specific task if the arduino is disconnected from ROS.

4.1.1. Subscribed Topics
* speed_and_direction (arduino_motor_control/set_speed_direction):

4.1.2. Published Topics
* current (arduino_motor_control/get_current):

4.1.3. Services
* heartbeat (arduino_motor_control/heartbeat):


**4.2. Node: motor_control_heartbeat_client**
This is the Heartbeat-Client an runs on the main ROS-System.
4.2.1 Needed Services
* heartbeat (arduino_motor_control/heartbeat):


**4.3. Node: motor_startup**

Contains the launch file.
