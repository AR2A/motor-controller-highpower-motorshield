#ifndef HARDWARE_DEPENDENT_H_
#define HARDWARE_DEPENDENT_H_
#include <stdint.h>
#include <Arduino.h>
//ROS-Messages and Services
#include <ros.h>
#include <Wire.h>
#include <arduino_motor_control/get_current.h>
#include <arduino_motor_control/set_speed_direction.h>
#include <arduino_motor_control/heartbeat.h>

class HardwareDependent {
public:
	virtual void initHw() = 0;
	virtual void setSpeed(
			const arduino_motor_control::set_speed_direction & sad) = 0;
	virtual void setDirection(
			const arduino_motor_control::set_speed_direction & sad) = 0;
	virtual void getCurrent(arduino_motor_control::get_current & cur) = 0;
	virtual void onError() = 0;
};

#endif //HARDWARE_DEPENDENT_H_
