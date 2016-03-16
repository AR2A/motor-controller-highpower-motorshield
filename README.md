# motor-controller-highpower-motorshield
Repository for the brushed motor controller based on the LXRobotics Highpower Motorshield.

This motor-controller-package based on rosserial_arduino 
brings support for the brushed motor controller based on the LXRobotics Highpower Motorshield to ROS (Robot Operating System) 
and can be easily adapted for other motor-shields.

**Features:**

* Own message-type for speed (8-bit value) and direction which can be adapted for individual needs.
* Includes a heartbeat-service that calls a user-specific task if the arduino is disconnected from ROS. For example: stop the motor if ROS does not respond.
