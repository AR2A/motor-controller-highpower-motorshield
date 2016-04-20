cmake_minimum_required(VERSION 2.8.3)
project(arduino_motor_control)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  rosserial_arduino
  rosserial_client
  std_msgs
)


################################################
## Declare ROS messages, services and actions ##
################################################

add_message_files(
 FILES
 current.msg
 speed.msg
)

 add_service_files(
   FILES
   heartbeat.srv
 )

 generate_messages(
 )

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################


###################################
## catkin specific configuration ##
###################################
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES arduino_motor_control
  CATKIN_DEPENDS roscpp rosserial_arduino rosserial_client message_runtime
#  DEPENDS system_lib
)

###########
## Build ##
###########

include_directories(
  ${catkin_INCLUDE_DIRS}
)

rosserial_generate_ros_lib(
	PACKAGE rosserial_arduino
	SCRIPT make_libraries.py
)

rosserial_configure_client(
	DIRECTORY firmware
	TOOLCHAIN_FILE ${ROSSERIAL_ARDUINO_TOOLCHAIN}
)

rosserial_add_client_target(firmware arduino_motor_control ALL)
rosserial_add_client_target(firmware arduino_motor_control-upload)

add_dependencies(arduino_motor_control_ros_lib arduino_motor_control_generate_messages_cpp)

#############
## Install ##
#############

#############
## Testing ##
#############

