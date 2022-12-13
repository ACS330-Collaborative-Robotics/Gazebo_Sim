#include <ros/ros.h>
#include "std_msgs/String.h"
#include "control_msgs/JointJog.h"
#include "sensor_msgs/JointState.h"
#include "basic_movement/Joints.h"

#include <sstream>
#include <iostream>
#include <stdio.h>

// TODO:
// Imploment listener for where to go
// implemnt a is this robot moving
// 


/* Create node */
float jointdemand_1, jointdemand_2, jointdemand_3, jointdemand_4, jointdemand_5, jointdemand_6;
float joint1, joint2, joint3, joint4, joint5, joint6;
bool know_states, know_demands, moving_state;

void jointsCallback(const sensor_msgs::JointState::ConstPtr& msg) {
	int i=0;
	for(std::vector<double>::const_iterator it = msg->position.begin(); it != msg->position.end(); ++it) {
		if(i==0) {
			joint1=*it;
		}
		if(i==1) {
			joint2=*it;
		}
		if(i==2) {
			joint3=*it;
		}
		if(i==3) {
			joint4=*it;
		}
		if(i==4) {
			joint5=*it;
		}
		if(i==5) {
			joint6=*it;
		}
		i++;
	}
	know_states = true;
	ROS_INFO("Received State %f\t%f\t%f\t%f\t%f\t%f", joint1, joint2, joint3, joint4, joint5, joint6);
}

void listenerJointAngles(const basic_movement::Joints::ConstPtr& msg){
	jointdemand_1=msg->joints[0];
	jointdemand_2=msg->joints[1];
	jointdemand_3=msg->joints[2];
	jointdemand_4=msg->joints[3];
	jointdemand_5=msg->joints[4];
	jointdemand_6=msg->joints[5];
	ROS_INFO("Received Goals %f\t%f\t%f\t%f\t%f\t%f", jointdemand_1, jointdemand_2, jointdemand_3, jointdemand_4, jointdemand_5, jointdemand_6);
	know_demands = true;
}


int main(int argc, char **argv) {
	know_states=false;
	know_demands=false;
	moving_state=false;
	ros::init(argc, argv, "goal_movement_example");
	ros::NodeHandle n;

	/* Create publisher to attach to JointJog */
	ros::Publisher chatter_pub = n.advertise<control_msgs::JointJog>("/JointJog",1);
	ros::Publisher moving = n.advertise<std_msgs::String>("/mover6_a/physical/moving_state",1000);

	ros::Subscriber chatter_sub = n.subscribe("/joint_states", 1000, jointsCallback);
	ros::Subscriber joint_demands = n.subscribe("/mover6_a/physical/joint_angles", 10000, listenerJointAngles);
	

	ros::Rate loop_rate(10);

	int counter = 0;

	const char* joints[6]
        = { "joint1", "joint2", "joint3", "joint4", "joint5", "joint6" };

	ros::Duration(2.0).sleep();
	while(ros::ok()) {
		if(know_states && know_demands) {
			float joint_demands[6]= {jointdemand_1, jointdemand_2, jointdemand_3, jointdemand_4, jointdemand_5, jointdemand_6};
			float joint_gains[6] = {0.25, 0.25, 0.25, 0.25, 0.25, 0.1};
			float jointpos[6] = {joint1, joint2, joint3, joint4, joint5, joint6}; 
			for (int i=0;i<6;i++){
				if(abs(joint_demands[i]-jointpos[i])>0.04) {

					ROS_INFO("Setting message Go to set point");
					control_msgs::JointJog msg_start;
					std::stringstream ss;
					ss << joints[i];

					msg_start.joint_names.push_back(ss.str());
					msg_start.velocities.push_back(joint_gains[i]*(joint_demands[i]-jointpos[i])/abs(joint_demands[i]-jointpos[i]));
					msg_start.duration=5; //Unfortunately duration isn't implemented...

					ROS_INFO("Sending message");
					chatter_pub.publish(msg_start);
					moving_state = true;
				}
				if(abs(joint_demands[i]-jointpos[i])<0.04) {

					ROS_INFO("Setting message Stay Still");
					control_msgs::JointJog msg_start;
					std::stringstream ss;
					ss << joints[i];

					msg_start.joint_names.push_back(ss.str());
					msg_start.velocities.push_back(0);
					msg_start.duration=5; //Unfortunately duration isn't implemented...

					ROS_INFO("Sending message");
					chatter_pub.publish(msg_start);
				}
				std_msgs::String state;
				std::stringstream system_state;
				if(moving_state == true){
					system_state << "Moving";
				}
				else {
					system_state << "Stationery";
				}
				ROS_INFO(system_state);
				state.data = system_state.str();
				chatter_pub.publish(state);
				ros::spinOnce();
			}

		}

		ros::spinOnce();
		loop_rate.sleep();

	}
	return 0;
}
