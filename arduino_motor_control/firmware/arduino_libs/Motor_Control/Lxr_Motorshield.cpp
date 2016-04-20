/**
 * \author   Gerald D.
 * \brief    LXR Motorshield Class   
 * \file     Lxr_Motorshield.cpp
 * \license  BSD-3-License
 */

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/
#include <Motor_Control/Lxr_Motorshield.h>

#include <LXR_Highpower_Motorshield/LXR_Highpower_Motorshield.h>

/**************************************************************************************
 * HELPER-FUNCTIONS
 **************************************************************************************/
uint8_t LxrMotorshield::ConvertSpeed(const double speed) {
	uint8_t speedAs8BitValue = 0;

	if (speed < 0) {
		speedAs8BitValue = (0xFF * (speed * -1)) && 0xFF;
	} else {
		speedAs8BitValue = (0xFF * speed) && 0xFF;
	}

	return speedAs8BitValue;
}

/**************************************************************************************
 * IMPLEMENTATION 
 **************************************************************************************/
void LxrMotorshield::SetSpeed(const arduino_motor_control::speed & s) {

	//set direction
	if (s.speed >= 0) {
		//forward
		LXR_Highpower_Motorshield::set_direction(FWD);
	} else {
		//backward
		LXR_Highpower_Motorshield::set_direction(BWD);
	}

	LXR_Highpower_Motorshield::set_speed(ConvertSpeed(s.speed));
}

arduino_motor_control::current LxrMotorshield::GetCurrent() {
	arduino_motor_control::current cur;

	//get values
	cur.current_hal_bridge_1 =
			LXR_Highpower_Motorshield::get_current_half_brigde_1();
	cur.current_hal_bridge_2 =
			LXR_Highpower_Motorshield::get_current_half_brigde_2();

	return cur;
}

