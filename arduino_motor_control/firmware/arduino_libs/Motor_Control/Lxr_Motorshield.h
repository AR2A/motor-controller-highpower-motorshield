/**
 * \author   Gerald D.
 * \brief    LXR Motorshield Class  
 * \file     Lxr_Motorshield.h
 * \license  BSD-3-License
 */

#ifndef LXR_MOTORSHIELD_H_
#define LXR_MOTORSHIELD_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/
#include <stdint.h>

#include <Motor_Control/Motor_Interface.h>


/**************************************************************************************
 * ABSTRACT INTERFACE
 **************************************************************************************/
class LxrMotorshield: public MotorInterface {
public:
	// DTor
	~LxrMotorshield();

	//setter
	void SetSpeed(const arduino_motor_control::speed & s);
	
private:
	//helper-functions
	uint8_t ConvertSpeed(const double speed);
};

#endif //LXR_MOTORSHIELD_H_
