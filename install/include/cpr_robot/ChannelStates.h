// Generated by gencpp from file cpr_robot/ChannelStates.msg
// DO NOT EDIT!


#ifndef CPR_ROBOT_MESSAGE_CHANNELSTATES_H
#define CPR_ROBOT_MESSAGE_CHANNELSTATES_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace cpr_robot
{
template <class ContainerAllocator>
struct ChannelStates_
{
  typedef ChannelStates_<ContainerAllocator> Type;

  ChannelStates_()
    : Header()
    , state()  {
    }
  ChannelStates_(const ContainerAllocator& _alloc)
    : Header(_alloc)
    , state(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _Header_type;
  _Header_type Header;

   typedef std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> _state_type;
  _state_type state;





  typedef boost::shared_ptr< ::cpr_robot::ChannelStates_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cpr_robot::ChannelStates_<ContainerAllocator> const> ConstPtr;

}; // struct ChannelStates_

typedef ::cpr_robot::ChannelStates_<std::allocator<void> > ChannelStates;

typedef boost::shared_ptr< ::cpr_robot::ChannelStates > ChannelStatesPtr;
typedef boost::shared_ptr< ::cpr_robot::ChannelStates const> ChannelStatesConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cpr_robot::ChannelStates_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cpr_robot::ChannelStates_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::cpr_robot::ChannelStates_<ContainerAllocator1> & lhs, const ::cpr_robot::ChannelStates_<ContainerAllocator2> & rhs)
{
  return lhs.Header == rhs.Header &&
    lhs.state == rhs.state;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::cpr_robot::ChannelStates_<ContainerAllocator1> & lhs, const ::cpr_robot::ChannelStates_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace cpr_robot

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::cpr_robot::ChannelStates_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cpr_robot::ChannelStates_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cpr_robot::ChannelStates_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cpr_robot::ChannelStates_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cpr_robot::ChannelStates_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cpr_robot::ChannelStates_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cpr_robot::ChannelStates_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3787f287236939db0a71aa80023fe8b9";
  }

  static const char* value(const ::cpr_robot::ChannelStates_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3787f287236939dbULL;
  static const uint64_t static_value2 = 0x0a71aa80023fe8b9ULL;
};

template<class ContainerAllocator>
struct DataType< ::cpr_robot::ChannelStates_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cpr_robot/ChannelStates";
  }

  static const char* value(const ::cpr_robot::ChannelStates_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cpr_robot::ChannelStates_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header Header\n"
"bool[] state\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::cpr_robot::ChannelStates_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cpr_robot::ChannelStates_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.Header);
      stream.next(m.state);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ChannelStates_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cpr_robot::ChannelStates_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cpr_robot::ChannelStates_<ContainerAllocator>& v)
  {
    s << indent << "Header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.Header);
    s << indent << "state[]" << std::endl;
    for (size_t i = 0; i < v.state.size(); ++i)
    {
      s << indent << "  state[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.state[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // CPR_ROBOT_MESSAGE_CHANNELSTATES_H
