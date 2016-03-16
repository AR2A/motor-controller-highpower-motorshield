#include <stdint.h>
#include <Arduino.h>
#include <Motor_Control/Motor_Control.h>
#include <Motor_Control/Hardware_Dependent.h>
#include <Motor_Control/Lxr_Motorshield_Wrapper.h>

//hardware-specific part

LxrMotorshieldWrapper mw;

//callback-functions
void callbackSpeedAndDirection(const arduino_motor_control::set_speed_direction & sad);
void callbackHeartbeat(const arduino_motor_control::heartbeat::Request  &req, arduino_motor_control::heartbeat::Response &res);

//initialize and run motor control class
Motor_Control mc;

sCallbackFunc callbackFunctions = {
	.callback_heartbeat = callbackHeartbeat,
	.callback_speed_and_direction = callbackSpeedAndDirection
};

void setup() {
	//mc.initialize(&hardwareDependent, &callbackFunctions);
	//mc.initialize(&hardwareDependent, &callbackFunctions, "heartbeat", "setSpeedAndDirection");
	mc.initialize(&mw, &callbackFunctions, "current0", "heartbeat0",
			"setSpeedAndDirection0", (2 * 1000), 20);
}

void loop() {
	mc.loop();
}

//callback-functions implementation
void callbackSpeedAndDirection(const arduino_motor_control::set_speed_direction & sad){
	mc.set_speed(sad);
	mc.set_direction(sad);
	//mc.heartbeat_timer_reset();	//ToDo: delete this line after debugging
}
void callbackHeartbeat(const arduino_motor_control::heartbeat::Request  &req, arduino_motor_control::heartbeat::Response &res){
	res.Response = mc.count_ones((uint8_t)req.Request);
	mc.heartbeat_timer_reset();
}
