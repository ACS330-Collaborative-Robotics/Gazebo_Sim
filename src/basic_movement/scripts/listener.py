#!/usr/bin/env python
import rospy
from std_msgs.msg import String
from basic_movement.msg import Joints

def callback(data):
    joint_demands = list(data.joints)
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.joints)
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", joint_demands[0])

    
def listener():

    # In ROS, nodes are uniquely named. If two nodes with the same
    # name are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    rospy.init_node('listener', anonymous=True)

    rospy.Subscriber("/mover6_a/physical/joint_angles", Joints, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()