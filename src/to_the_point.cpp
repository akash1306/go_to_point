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

int main(int argc, char** argv)
{
    ros::init(argc, argv, "Go_To_Point_Node");
    ros::NodeHandle nh;
    std::string _uav_name_;
    mrs_lib::ParamLoader param_loader(nh, "ToPoint");
    param_loader.loadParam("/ToPoint/uav_name", _uav_name_);
    ROS_INFO("Sending Drone one Step Forward");

    PointClass pointobj(&nh);

    ros::ServiceClient client1 = nh.serviceClient<mrs_msgs::Vec4>
                                            (_uav_name_ + "/control_manager/goto");
    ros::service::waitForService(_uav_name_ + "/control_manager/goto",10);

    pointobj.goal1[0] = pointobj.odomdata1.pose.pose.position.x + 1;
    pointobj.goal1[0] = pointobj.odomdata1.pose.pose.position.x + 1;
    pointobj.goal1[0] = pointobj.odomdata1.pose.pose.position.x + 1;
    mrs_msgs::Vec4 srv1;
    srv1.request.goal = pointobj.goal1;
    client1.call(srv1);
    ROS_INFO("Movement Done. On Standby");
    ros::spin();
    return 0;

}