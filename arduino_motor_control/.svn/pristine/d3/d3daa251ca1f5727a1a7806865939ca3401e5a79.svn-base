#ifndef LXR_MOTORSHIELD_WRAPPER_H_
#define LXR_MOTORSHIELD_WRAPPER_H_

#include <Motor_Control/Hardware_Dependent.h>

class LxrMotorshieldWrapper: public HardwareDependent {
public:
	void initHw();
	void setSpeed(const arduino_motor_control::set_speed_direction & sad);
	void setDirection(const arduino_motor_control::set_speed_direction & sad);
	void getCurrent(arduino_motor_control::get_current & cur);
	void onError();
};

#endif //LXR_MOTORSHIELD_WRAPPER_H_
