#include <Motor_Control/Lxr_Motorshield_Wrapper.h>
#include <LXR_Highpower_Motorshield/LXR_Highpower_Motorshield.h>
#define FORWARD 1

void LxrMotorshieldWrapper::initHw() {
	LXR_Highpower_Motorshield::begin();
}

void LxrMotorshieldWrapper::setSpeed(
		const arduino_motor_control::set_speed_direction & sad) {
	LXR_Highpower_Motorshield::set_speed((uint8_t) sad.speed);
}

void LxrMotorshieldWrapper::setDirection(
		const arduino_motor_control::set_speed_direction & sad) {
	if (sad.direction == FORWARD) {
		LXR_Highpower_Motorshield::set_direction (FWD);
	} else { //backward
		LXR_Highpower_Motorshield::set_direction (BWD);
	}
}

void LxrMotorshieldWrapper::getCurrent(
		arduino_motor_control::get_current & cur) {
	cur.current_hal_bridge_1 =
			LXR_Highpower_Motorshield::get_current_half_brigde_1();
	cur.current_hal_bridge_2 =
			LXR_Highpower_Motorshield::get_current_half_brigde_2();
}

void LxrMotorshieldWrapper::onError() {
	LXR_Highpower_Motorshield::set_speed(0);
}
