#include <to_the_point.hpp>

PointClass::PointClass(ros::NodeHandle* nodehandle):nh_(*nodehandle)
{
    ROS_INFO("Setting up the System");
    location_subscriber1 = nh_.subscribe("", 
                                    100, &PointClass::subscriberCallback1, this);
}

void PointClass::subscriberCallback1(const nav_msgs::Odometry& message_holder)
{
    odomdata1 = message_holder;
}
