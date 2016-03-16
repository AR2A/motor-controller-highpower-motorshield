#include <Motor_Control/Motor_Control.h>
#include <stdint.h>
#include <Arduino.h>
#include <ros.h>
#include <Wire.h>

Motor_Control::~Motor_Control() {
	if (mPublisherCurrent != 0) {
		delete mPublisherCurrent;
	}

	if (mSubscriberSpeedAndDirection != 0) {
		delete mSubscriberSpeedAndDirection;
	}

	if (mServiceHeartbeat != 0) {
		delete mServiceHeartbeat;
	}
}

void Motor_Control::initialize(HardwareDependent * hd, sCallbackFunc *cf,
		char * currentMsgName, char * heartbeatMsgName,
		char * speedAndDirectionMsgName, const long heartbeatTimeout_ms,
		const uint8_t publishingFrequency_ms) {

	if ((hd == 0) || (cf == 0)) {
		return;
	}

	mHD = hd;
	mCF = cf;
	mHeartbeatTimeout = heartbeatTimeout_ms;
	mPublishingFrequency = publishingFrequency_ms;

	initialize_hw();

	if (mPublisherCurrent != 0) {
		delete mPublisherCurrent;
	}
	mPublisherCurrent = new ros::Publisher(currentMsgName, &mMessageCurrent);

	if (mSubscriberSpeedAndDirection != 0) {
		delete mSubscriberSpeedAndDirection;
	}
	mSubscriberSpeedAndDirection = new ros::Subscriber<
			arduino_motor_control::set_speed_direction>(
			speedAndDirectionMsgName, mCF->callback_speed_and_direction);

	if (mServiceHeartbeat != 0) {
		delete mServiceHeartbeat;
	}
	mServiceHeartbeat = new ros::ServiceServer<
			arduino_motor_control::heartbeat::Request,
			arduino_motor_control::heartbeat::Response>(heartbeatMsgName,
			mCF->callback_heartbeat);

	mNodeHandle.initNode();
	mNodeHandle.subscribe(*mSubscriberSpeedAndDirection);
	mNodeHandle.advertise(*mPublisherCurrent);
	mNodeHandle.advertiseService(*mServiceHeartbeat);

	heartbeat_timer_reset();
}

void Motor_Control::set_direction(
		const arduino_motor_control::set_speed_direction & sad) {
	if (is_heartbeat_in_time()) {
		if ((mHD != 0) && (mHD != 0)) {
			mHD->setDirection(sad);
		}
	}
}

void Motor_Control::set_speed(
		const arduino_motor_control::set_speed_direction & sad) {
	if (is_heartbeat_in_time()) {
		if ((mHD != 0) && (mHD != 0)) {
			mHD->setSpeed(sad);
		}
	}
}

void Motor_Control::get_current(arduino_motor_control::get_current & cur) {
	if ((mHD != 0) && (mHD != 0)) {
		mHD->getCurrent(mMessageCurrent);
	}
}

void Motor_Control::initialize_hw() {
	if ((mHD != 0) && (mHD != 0)) {
		mHD->initHw();
	}
}

void Motor_Control::on_error() {
	if ((mHD != 0) && (mHD != 0)) {
		mHD->onError();
	}
}

bool Motor_Control::is_heartbeat_in_time() {
	return (millis() < mHeartbeatTimer);
}

void Motor_Control::loop() {
	if (millis() > mHeartbeatTimer) {
		on_error();
	}

	if (millis() > mPublisherTimer) {
		get_current (mMessageCurrent);
		mPublisherCurrent->publish(&mMessageCurrent);

		mPublisherTimer = millis() + mPublishingFrequency;
	}
	mNodeHandle.spinOnce();
}

//implementation helper functions
uint8_t Motor_Control::count_ones(const uint8_t value) {
	uint8_t sum_of_ones = 0;

	for (int i = 0; i < 8; i++) {
		if (value & (1 << i) != 0) {
			sum_of_ones++;
		}
	}

	return sum_of_ones;
}

void Motor_Control::heartbeat_timer_reset() {
	mHeartbeatTimer = millis() + mHeartbeatTimeout;
}
