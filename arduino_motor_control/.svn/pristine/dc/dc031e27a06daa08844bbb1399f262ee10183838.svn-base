#ifndef _ROS_arduino_motor_control_get_current_h
#define _ROS_arduino_motor_control_get_current_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arduino_motor_control
{

  class get_current : public ros::Msg
  {
    public:
      int32_t current_hal_bridge_1;
      int32_t current_hal_bridge_2;

    get_current():
      current_hal_bridge_1(0),
      current_hal_bridge_2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_current_hal_bridge_1;
      u_current_hal_bridge_1.real = this->current_hal_bridge_1;
      *(outbuffer + offset + 0) = (u_current_hal_bridge_1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_hal_bridge_1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_hal_bridge_1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_hal_bridge_1.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_hal_bridge_1);
      union {
        int32_t real;
        uint32_t base;
      } u_current_hal_bridge_2;
      u_current_hal_bridge_2.real = this->current_hal_bridge_2;
      *(outbuffer + offset + 0) = (u_current_hal_bridge_2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_hal_bridge_2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_hal_bridge_2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_hal_bridge_2.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_hal_bridge_2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_current_hal_bridge_1;
      u_current_hal_bridge_1.base = 0;
      u_current_hal_bridge_1.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_hal_bridge_1.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_hal_bridge_1.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_hal_bridge_1.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_hal_bridge_1 = u_current_hal_bridge_1.real;
      offset += sizeof(this->current_hal_bridge_1);
      union {
        int32_t real;
        uint32_t base;
      } u_current_hal_bridge_2;
      u_current_hal_bridge_2.base = 0;
      u_current_hal_bridge_2.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_hal_bridge_2.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_hal_bridge_2.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_hal_bridge_2.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_hal_bridge_2 = u_current_hal_bridge_2.real;
      offset += sizeof(this->current_hal_bridge_2);
     return offset;
    }

    const char * getType(){ return "arduino_motor_control/get_current"; };
    const char * getMD5(){ return "a14c8221b8a6455958b6b2e221d2b3ea"; };

  };

}
#endif