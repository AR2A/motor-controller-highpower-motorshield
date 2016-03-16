#ifndef _ROS_SERVICE_heartbeat_h
#define _ROS_SERVICE_heartbeat_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arduino_motor_control
{

static const char HEARTBEAT[] = "arduino_motor_control/heartbeat";

  class heartbeatRequest : public ros::Msg
  {
    public:
      uint8_t Request;

    heartbeatRequest():
      Request(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->Request >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Request);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->Request =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->Request);
     return offset;
    }

    const char * getType(){ return HEARTBEAT; };
    const char * getMD5(){ return "dd504d34bb797bb9be0484ebe2d9c70c"; };

  };

  class heartbeatResponse : public ros::Msg
  {
    public:
      uint8_t Response;

    heartbeatResponse():
      Response(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->Response >> (8 * 0)) & 0xFF;
      offset += sizeof(this->Response);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->Response =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->Response);
     return offset;
    }

    const char * getType(){ return HEARTBEAT; };
    const char * getMD5(){ return "a4e8d66a31fef25ebc43c49e7eaad48b"; };

  };

  class heartbeat {
    public:
    typedef heartbeatRequest Request;
    typedef heartbeatResponse Response;
  };

}
#endif
