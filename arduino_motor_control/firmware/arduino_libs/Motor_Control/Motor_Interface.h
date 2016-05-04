/**
 * \author   Gerald D.
 * \brief    motor interface
 * \file     Motor_Interface.h
 * \license  BSD-3-License
 */

#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/
#include <stdint.h>

#include <Arduino.h>

#include <ros.h>
#include <Wire.h>

#include <arduino_motor_control/current.h>
#include <arduino_motor_control/speed.h>

/**************************************************************************************
 * INTERFACE
 **************************************************************************************/
class MotorInterface {
  public:
    // empty virtual destructor for proper cleanup
    virtual ~MotorInterface() {
    }
    
    /* This function sets the motor speed and the value has to be in the range 
       from 1.0 to -1.0 :
        value:  0.0   -> stop
        value: |1.0|  -> fastest speed
	positive value-> forward 
        negative value-> backward
    */
    virtual void SetSpeed(const arduino_motor_control::speed & s) = 0;
};

#endif //MOTOR_INTERFACE_H_
