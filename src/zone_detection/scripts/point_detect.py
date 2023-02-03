#!/usr/bin/env python

# Name: Robot Arm Zone Detection
# Author: Andrei Codin (aacodin1@sheffield.ac.uk)

import rospy
#import tf
from shapely.geometry import Point, Polygon
from zone_controller.msg import Zones

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "%s", data.data)

def listener():
    while not rospy.is_shutdown():
        rospy.init_node('point_detect', anonymous=True)
        rospy.Subscriber("chatter", Zones, callback)
        #mover6_a_data = tf.TransformListener()
        #mover6_b_data = tf.TransformListener()
        #(transl_a,rot_a) = mover6_a_data.lookupTransform('/link6', '/base_link', rospy.Time(0))
        #(transl_b,rot_b) = mover6_b_data.lookupTransform('/link6', '/base_link', rospy.Time(0))
        mover6_a = Point(0.2, 0.1)
        mover6_b = Point(-0.2, -0.1)
        coords_a = Zones(1)
        coords_b = Zones(2)
        zone_a = Polygon(coords_a)
        zone_b = Polygon(coords_b)
        pos_a1 = mover6_a.within(zone_a)
        pos_a2 = mover6_a.within(zone_b)
        pos_b1 = mover6_b.within(zone_b)
        pos_b2 = mover6_b.within(zone_a)
        rospy.spin()


if __name__ == '__main__':
    listener()