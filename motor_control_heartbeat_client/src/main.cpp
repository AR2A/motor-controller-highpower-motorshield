#include <string>
#include <stdint.h>
#include "ros/ros.h"
#include <ros/console.h>
#include <arduino_motor_control/heartbeat.h>

using namespace std;

uint8_t count_ones(const uint8_t value) {
    uint8_t sum_of_ones = 0;

    for (int i = 0; i < 8; i++) {
        if (value & (1 << i) != 0) {
            sum_of_ones++;
        }
    }

    return sum_of_ones;
}

int main(int argc, char *argv[]) {
    string heartbeatMsgName;
    cout << "\nargc=" << argc << "\n";
    if (argc < 2) {
        ROS_INFO("argc=%d", argc);
        heartbeatMsgName = "default_heartbeat_msg_name";
    } else {
        heartbeatMsgName = argv[1];
    }

    ros::init(argc, argv, heartbeatMsgName);
    ros::NodeHandle nh;
    ros::Rate r(1); // 1 hz
    ros::ServiceClient heartbeatClient = nh.serviceClient<
                                         arduino_motor_control::heartbeat::Request,
                                         arduino_motor_control::heartbeat::Response>(heartbeatMsgName);
    arduino_motor_control::heartbeat srv;

    srv.request.Request = 1;

    while (ros::ok()) {
        if (heartbeatClient.call(srv)) {
            ROS_INFO("Sum_of_ons: %d", (uint8_t) srv.response.Response);

            if (srv.response.Response
                    != count_ones((uint8_t) srv.request.Request)) {
                ROS_INFO(
                    "Wrong return value from service arduino_motor_control::heartbeat");
                //ToDo: user-specific-part
            }

            srv.request.Request = srv.response.Response + 1;
        } else {
            ROS_INFO("Failed to call service arduino_motor_control::heartbeat");
        }
        r.sleep();
    }

    return 0;
}
