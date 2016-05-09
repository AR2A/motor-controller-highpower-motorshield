cmake_minimum_required(VERSION 2.8.3)
project(motor_control_heartbeat_client)

find_package(catkin REQUIRED COMPONENTS 
  arduino_motor_control roscpp std_msgs rospy genmsg
)

find_package(Boost REQUIRED COMPONENTS filesystem)


################################################
## Declare ROS messages, services and actions ##
################################################


################################################
## Declare ROS dynamic reconfigure parameters ##
################################################


###################################
## catkin specific configuration ##
###################################
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES process_imu_data
#  CATKIN_DEPENDS avr_imu
#  DEPENDS system_lib
)


###########
## Build ##
###########
include_directories(
  ${Boost_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
  /usr/includes/
)

 add_executable(motor_control_heartbeat_client_node src/main.cpp)

 target_link_libraries(motor_control_heartbeat_client_node
   ${catkin_LIBRARIES}
 )

#############
## Install ##
#############


#############
## Testing ##
#############
