/**
 * \author   Gerald D.
 * \brief    hardware abstraction layer 
 * \file     arduino_motor_control.cpp
 * \license  BSD-3-License
 */


/**************************************************************************************
 * INCLUDES
 **************************************************************************************/
#include <stdint.h>

#include <Arduino.h>

#include <Motor_Control/Motor_Control.h>

//HARDWARE-SPECIFIC
#include <Motor_Control/Lxr_Motorshield.h>

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/
Motor_Control mc;
LxrMotorshield ms; //HARDWARE-SPECIFIC


/**************************************************************************************
 * Callback Functions
 **************************************************************************************/
void callbackSpeed(const arduino_motor_control::speed & s){
	mc.set_speed(s);
}

void callbackHeartbeat(const arduino_motor_control::heartbeat::Request  &req, arduino_motor_control::heartbeat::Response &res){
	res.Response = mc.count_ones((uint8_t)req.Request);
	mc.heartbeat_timer_reset();
}

sCallbackFunc cf = {
	.callback_heartbeat = callbackHeartbeat,
	.callback_speed = callbackSpeed
};

/**************************************************************************************
 * ARDUINO FRAMEWORK FUNCTIONS
 **************************************************************************************/

void setup() {
	mc.initialize(&ms, &cf);
}


void loop() {
	mc.loop();
}




