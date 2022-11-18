#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def arena_locals():
    pub = rospy.Publisher('areanLocals', String, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        loacation_str = "[[9.19, 4.29], [5.43, 9.35], [1.26, 2.66], [3.92, 0.19], [5.18, 9.83], [8.3, 0.05], [0.82, 0.21], [3.97, 3.77], [7.76, 2.64], [4.32, 3.57], [1.45, 7.75], [0.87, 0.77]]"
        rospy.loginfo(loacation_str)
        pub.publish(loacation_str)
        rate.sleep()

if __name__ == '__main__':
    try:
        arena_locals()
    except rospy.ROSInterruptException:
        pass
