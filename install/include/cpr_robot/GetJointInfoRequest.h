// Generated by gencpp from file cpr_robot/GetJointInfoRequest.msg
// DO NOT EDIT!


#ifndef CPR_ROBOT_MESSAGE_GETJOINTINFOREQUEST_H
#define CPR_ROBOT_MESSAGE_GETJOINTINFOREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace cpr_robot
{
template <class ContainerAllocator>
struct GetJointInfoRequest_
{
  typedef GetJointInfoRequest_<ContainerAllocator> Type;

  GetJointInfoRequest_()
    : Sender()
    , JointId(0)  {
    }
  GetJointInfoRequest_(const ContainerAllocator& _alloc)
    : Sender(_alloc)
    , JointId(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _Sender_type;
  _Sender_type Sender;

   typedef uint32_t _JointId_type;
  _JointId_type JointId;





  typedef boost::shared_ptr< ::cpr_robot::GetJointInfoRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cpr_robot::GetJointInfoRequest_<ContainerAllocator> const> ConstPtr;

}; // struct GetJointInfoRequest_

typedef ::cpr_robot::GetJointInfoRequest_<std::allocator<void> > GetJointInfoRequest;

typedef boost::shared_ptr< ::cpr_robot::GetJointInfoRequest > GetJointInfoRequestPtr;
typedef boost::shared_ptr< ::cpr_robot::GetJointInfoRequest const> GetJointInfoRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cpr_robot::GetJointInfoRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cpr_robot::GetJointInfoRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::cpr_robot::GetJointInfoRequest_<ContainerAllocator1> & lhs, const ::cpr_robot::GetJointInfoRequest_<ContainerAllocator2> & rhs)
{
  return lhs.Sender == rhs.Sender &&
    lhs.JointId == rhs.JointId;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::cpr_robot::GetJointInfoRequest_<ContainerAllocator1> & lhs, const ::cpr_robot::GetJointInfoRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace cpr_robot

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::cpr_robot::GetJointInfoRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cpr_robot::GetJointInfoRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cpr_robot::GetJointInfoRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cpr_robot::GetJointInfoRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cpr_robot::GetJointInfoRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cpr_robot::GetJointInfoRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cpr_robot::GetJointInfoRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "41358db89ee0b7be7f8dd1bad552b58e";
  }

  static const char* value(const ::cpr_robot::GetJointInfoRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x41358db89ee0b7beULL;
  static const uint64_t static_value2 = 0x7f8dd1bad552b58eULL;
};

template<class ContainerAllocator>
struct DataType< ::cpr_robot::GetJointInfoRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cpr_robot/GetJointInfoRequest";
  }

  static const char* value(const ::cpr_robot::GetJointInfoRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cpr_robot::GetJointInfoRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string Sender\n"
"uint32 JointId\n"
;
  }

  static const char* value(const ::cpr_robot::GetJointInfoRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cpr_robot::GetJointInfoRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.Sender);
      stream.next(m.JointId);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GetJointInfoRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cpr_robot::GetJointInfoRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cpr_robot::GetJointInfoRequest_<ContainerAllocator>& v)
  {
    s << indent << "Sender: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.Sender);
    s << indent << "JointId: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.JointId);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CPR_ROBOT_MESSAGE_GETJOINTINFOREQUEST_H
