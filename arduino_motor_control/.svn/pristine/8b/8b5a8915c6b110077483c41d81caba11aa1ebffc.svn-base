#ifndef _ROS_arduino_motor_control_set_speed_direction_h
#define _ROS_arduino_motor_control_set_speed_direction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arduino_motor_control
{

  class set_speed_direction : public ros::Msg
  {
    public:
      uint8_t speed;
      uint8_t direction;

    set_speed_direction():
      speed(0),
      direction(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->speed >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speed);
      *(outbuffer + offset + 0) = (this->direction >> (8 * 0)) & 0xFF;
      offset += sizeof(this->direction);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->speed =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->speed);
      this->direction =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->direction);
     return offset;
    }

    const char * getType(){ return "arduino_motor_control/set_speed_direction"; };
    const char * getMD5(){ return "0faad143a673fdb26c8bece2f4e2face"; };

  };

}
#endif