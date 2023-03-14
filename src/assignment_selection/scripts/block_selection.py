#!/usr/bin/env python

# Name: block_slection
# Author: Tom Richards (tomtommrichards@gmail.com), Conor Nichols (cjnichols1@sheffield.ac.uk), Annanthavel Santhanavel Ramesh(asanthanavelramesh1@sheffield.ac.uk)

import rospy

from gazebo_msgs.srv import GetModelState
from block_controller.msg import Blocks
from path_planning.srv import PathPlan
from std_msgs.msg import String
from geometry_msgs.msg import Pose

import math
from operator import itemgetter

# Global variable to store blockData as it appears from subscriber
blockData = None

def callback(data):
    global blockData
    blockData = data

def choose_block():
    # Setup block_pos listener
    rospy.Subscriber('/blocks_pos', Blocks, callback)

    # Define robot namespaces being used - also defines number of robots
    robot_namespaces = ["mover6_a", "mover6_b"]
    
    # Setup path_planner service
    rospy.wait_for_service('path_planner')
    path_service = rospy.ServiceProxy('path_planner', PathPlan)

    # Declare ROS Node name
    rospy.init_node('block_selector')

    # Set Loop rate
    T = 5
    rate = rospy.Rate(1/T)

    while blockData is None:
        rospy.loginfo("Block Selection - Waiting for data.")
        rospy.sleep(0.1)
    rospy.loginfo("Block Selection - Got block data,")

    # Loop Selection until script is terminated
    while not rospy.is_shutdown():
        ## Making array of block names ##

        # Wait for blockData to read in by subscriber
        while blockData is None:
            rospy.loginfo("Block Selection - Waiting for data.")
            rate.sleep()
        rospy.loginfo("Block Selection - Got block data,")

        # Iterate through blockData and retrieve list of block names
        blockNames = []
        for block_num in range(len(blockData.block_data)):
            blockNames.append("block" + str(blockData.block_data[block_num].block_number))
        rospy.loginfo("Block Selection - Block list built.")

        print(blockNames)

        ## ////////////////////////////////////////////
        # Getting distance from each robot to blocks and sellecting the smallest
        roboColect = []
        for blockName in blockNames:     
            reldist = []
            for robot in robot_namespaces:
                temp =  specific_block_pos(blockName, robot)
                reldist.append(math.sqrt(temp[0]**2+temp[1]**2+temp[2]**2))
            roboColect.append([blockName, reldist.index(min(reldist)), min(reldist)])
        
        # Ordering list on nearest
        sorted(roboColect,key=itemgetter(2))
        
        # Splitting into seperate lists
        goCollect = []
        for i in range(len(robot_namespaces)):
            goCollect.append([])
            for nextBlock in roboColect:
                if nextBlock[1] == i:
                    goCollect[i].append(nextBlock[0])
        rospy.loginfo("Block Selection - Block selection complete. Beginnning publishing.")
        
        ## ////////////////////////////////////////////
        
        n = 20
        layers = math.ceil(n/3)
        print(layers)
        tower_pos = [] #this has to be a 3 column * layers(value) matrix
        h=0.5
        angle=0

        for i in range(layers):
            w=0.25
            home_pos = [w,0.25,h,angle]
            for j in range(3):
                home_pos = [w,0.25,h,angle]
                tower_pos.append(home_pos)
                w=w+1
            h=h+1

            if angle==0:
                angle=90*(math.pi/180)
            elif angle==90*(math.pi/180):
                angle=0

        # Publish assignments
        for i in range(len(tower_pos)):
            block_name = str(blockNames[i])

            end_pos = Pose()
            end_pos.position.x = tower_pos[i][0]
            end_pos.position.y = tower_pos[i][1]
            end_pos.position.z = tower_pos[i][2]
            end_pos.orientation.w = tower_pos[i][3]
                    
            robot_name = str(robot_namespaces[0])
            ## ////////////////////////////////////////////
                    
            try:
                success = path_service(block_name, end_pos, robot_name)

                if not(success):
                    rospy.loginfo("Block Selection - Service call returned False.")
                            
            except rospy.ServiceException as e:
                rospy.loginfo("Block Selection - Service call failed: %s"%e)

                    

                rate.sleep()

def specific_block_pos(specific_model_name, reference_model_name):
    # Use service to get position of specific block named
    rospy.wait_for_service('gazebo/get_model_state')
    model_state_service = rospy.ServiceProxy('gazebo/get_model_state', GetModelState)
    data = model_state_service(specific_model_name, reference_model_name).pose.position

    # Return ModelState object with position relative to world 
    return [data.x, data.y, data.z]

if __name__ == '__main__':
    try:
        choose_block()
    except rospy.ROSInterruptException:
        pass
