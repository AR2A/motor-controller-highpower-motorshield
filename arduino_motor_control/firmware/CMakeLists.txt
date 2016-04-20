cmake_minimum_required(VERSION 2.8.3)

include_directories(${ROS_LIB_DIR} arduino_libs /usr/lib/avr/include/)


generate_arduino_firmware(arduino_motor_control
	SRCS arduino_libs/Motor_Control/Motor_Control.cpp arduino_libs/Motor_Control/Lxr_Motorshield.cpp arduino_motor_control.cpp arduino_libs/LXR_Highpower_Motorshield/LXR_Highpower_Motorshield.cpp ${ROS_LIB_DIR}/time.cpp
	BOARD uno
	PORT /dev/ttyACM1
	#PORT /dev/ttyACM2
)
