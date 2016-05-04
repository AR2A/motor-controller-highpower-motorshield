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

//HARDWARE-SPECIFIC PART-> (LxrMotorshield has been derived from Motor_Interface.h)
LxrMotorshield ms; 
/* If you don't use a LXR Highpower Motorshield(LxrMotorshield), you have to implement 
   your own class (derived from Motor_Interface.h) to control your motor. */


/**************************************************************************************
 * Callback Functions 
 **************************************************************************************/
/* The following callback-functions are needed because ros::Subscriber(...) and 
   ros::ServiceServer(...) can't handle functions with this-pointer. 
   In my opinion this is the best possible workaround (better than static functions) 
   because you can have more motor controller instances without interfering each other.*/

void callbackSpeed(const arduino_motor_control::speed & s) {
    mc.set_speed(s);
}

void callbackHeartbeat(const arduino_motor_control::heartbeat::Request  &req, arduino_motor_control::heartbeat::Response &res) {
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
    /* You can call initialize with the following parameters to rename 
       msgs/srv or to run two instances on one arduino (not supported 
       from LXR Highpower Motorshield): 

         mc0.initialize(&ms0, &cf0, "currentMotor0", "heartbeatSrvMotor0", 
                        "speedMotor0", 500, 100);

         mc1.initialize(&ms1, &cf1, "currentMotor1", "heartbeatSrvMotor1", 
                        "speedMotor1", 500, 100); 
    */                          

}

void loop() {

    mc.loop();

}
