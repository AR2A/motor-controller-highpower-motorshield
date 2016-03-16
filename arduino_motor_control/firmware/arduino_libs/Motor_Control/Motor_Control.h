#ifndef MOTOR_CONTROL_H_
#define MOTOR_CONTROL_H_
#include <stdint.h>
#include <Arduino.h>

//ROS-Messages and Services
#include <ros.h>
#include <Wire.h>
#include <arduino_motor_control/get_current.h>
#include <arduino_motor_control/set_speed_direction.h>
#include <arduino_motor_control/heartbeat.h>

//hardware dependent functions
#include <Motor_Control/Hardware_Dependent.h>


//callback functions
typedef void (*fpHB)(const arduino_motor_control::heartbeat::Request &req,
		arduino_motor_control::heartbeat::Response &res);
typedef void (*fpSD)(const arduino_motor_control::set_speed_direction & sad);

typedef struct {
	fpHB callback_heartbeat;
	fpSD callback_speed_and_direction;
} sCallbackFunc;

class Motor_Control {
public:
	~Motor_Control();
	void loop();
	void initialize(HardwareDependent * hd, sCallbackFunc *cf,
			char * currentMsgName = "default_current_msg_name",
			char * heartbeatMsgName = "default_heartbeat_msg_name",
			char * speedAndDirectionMsgName =
					"default_speed_and_direction_msg_name",
			const long heartbeatTimeout_ms = 200,
			const uint8_t publishingFrequency_ms = 20);

	//hardware dependent functions
	void initialize_hw();
	void set_direction(const arduino_motor_control::set_speed_direction & sad);
	void set_speed(const arduino_motor_control::set_speed_direction & sad);
	void get_current(arduino_motor_control::get_current & cur);
	void on_error();

	//helper functions
	uint8_t count_ones(const uint8_t value);
	void heartbeat_timer_reset();
	bool is_heartbeat_in_time();

private:
	//message
	arduino_motor_control::get_current mMessageCurrent;

	//variables
	long mPublisherTimer;
	long mHeartbeatTimer;
	long mHeartbeatTimeout;
	uint8_t mPublishingFrequency;
	HardwareDependent *mHD;
	sCallbackFunc *mCF;
	ros::NodeHandle mNodeHandle;
	ros::Publisher *mPublisherCurrent;
	ros::Subscriber<arduino_motor_control::set_speed_direction> *mSubscriberSpeedAndDirection;
	ros::ServiceServer<arduino_motor_control::heartbeat::Request,
			arduino_motor_control::heartbeat::Response> *mServiceHeartbeat;
};

#endif //MOTOR_CONTROL_H_
