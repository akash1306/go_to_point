#ifndef TOPOINT
#define TOPOINT
#include <ros/ros.h>
#include <iostream>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PointStamped.h>
#include <mrs_msgs/Vec4.h>
#include <mrs_msgs/ControlManagerDiagnostics.h>
#include <mrs_msgs/Float64Stamped.h>
#include <mrs_msgs/ReferenceStamped.h>
#include <mrs_lib/param_loader.h>
#include <std_msgs/Float64MultiArray.h>
#include <Eigen/Dense>
#include <math.h>


class PointClass 
{
public:
    PointClass(ros::NodeHandle* nodehandle); 
    void servicestarter();
    boost::array<double,4> goal1 = {0.0, 0.0, 0.0, 0.0};
    nav_msgs::Odometry odomdata1;
private:
	ros::Subscriber location_subscriber1;

    
    
    ros::NodeHandle nh_; 
    

    void subscriberCallback1(const nav_msgs::Odometry& message_holder); 
    
};
#endif 