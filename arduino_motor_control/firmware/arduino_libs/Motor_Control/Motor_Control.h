/**
 * \author   Gerald D.
 * \brief
 * \file     Motor_Controler.h
 * \license  BSD-3-License
 */

#ifndef MOTOR_CONTROL_H_
#define MOTOR_CONTROL_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/
#include <stdint.h>

#include <Arduino.h>

//ROS-Messages and Services
#include <ros.h>
#include <Wire.h>
#include <arduino_motor_control/current.h>
#include <arduino_motor_control/speed.h>
#include <arduino_motor_control/heartbeat.h>

//hardware dependent functions
#include <Motor_Control/Motor_Interface.h>

//callback functions
typedef void (*fpHB)(const arduino_motor_control::heartbeat::Request &req,
                     arduino_motor_control::heartbeat::Response &res);
typedef void (*fpSD)(const arduino_motor_control::speed & s);

typedef struct {
    fpHB callback_heartbeat;
    fpSD callback_speed;
} sCallbackFunc;



class Motor_Control {
  public:
    ~Motor_Control();
    void loop();
    void initialize(MotorInterface *mi, sCallbackFunc *cf,
                    char *currentMsgName 				 = "default_current_msg_name",
                    char *heartbeatMsgName 			 	 = "default_heartbeat_msg_name",
                    char *speedMsgName 				  	 = "default_speed_msg_name",
                    const long heartbeatTimeout_ms 		 = 200,
                    const uint8_t publishingFrequency_ms = 20);

    //motor_interface functions
    void set_speed(const arduino_motor_control::speed & s);
    void get_current(arduino_motor_control::current & cur);

    //helper functions
    void on_error();
    uint8_t count_ones(const uint8_t value);
    void heartbeat_timer_reset();
    bool is_heartbeat_in_time();

  private:
    //message
    arduino_motor_control::current mMessageCurrent;

    //variables
    long mPublisherTimer;
    long mHeartbeatTimer;
    long mHeartbeatTimeout;

    uint8_t mPublishingFrequency;
    MotorInterface *mMI;
    sCallbackFunc *mCF;
    ros::NodeHandle mNodeHandle;
    ros::Publisher *mPublisherCurrent;
    ros::Subscriber<arduino_motor_control::speed> *mSubscriberSpeed;
    ros::ServiceServer<arduino_motor_control::heartbeat::Request,
        arduino_motor_control::heartbeat::Response> *mServiceHeartbeat;
};

#endif //MOTOR_CONTROL_H_
