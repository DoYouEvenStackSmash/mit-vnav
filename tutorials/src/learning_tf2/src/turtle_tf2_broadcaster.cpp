#include <ros/ros.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>
#include <turtlesim/Pose.h>

std::string turtle_name;

void poseCallback(const turtlesim::PoseConstPtr& msg) {
    // publishes transforms
    static tf2_ros::TransformBroadcaster br;

    geometry_msgs::TransformStamped transformStamped;
    // frame needs a timestamp
    transformStamped.header.stamp = ros::Time::now();
    // set name of parent frame
    transformStamped.header.frame_id = "world";
    // set name of child frame
    transformStamped.child_frame_id = turtle_name;

    // copy information from 3d turtle pose into 3d transformation
    transformStamped.transform.translation.x = msg->x;
    transformStamped.transform.translation.y = msg->y;
    transformStamped.transform.translation.z = 0.0; // no movement in z

    tf2::Quaternion q;
    q.setRPY(0, 0, msg->theta);
    transformStamped.transform.rotation.x = q.x();
    transformStamped.transform.rotation.y = q.y();
    transformStamped.transform.rotation.z = q.z();
    transformStamped.transform.rotation.w = q.w();

    br.sendTransform(transformStamped);
}

int main(int argc, char** argv) {
    ros::init(argc,argv,"my_tf2_broadcaster");
    ros::NodeHandle private_node("~");
    if (! private_node.hasParam("turtle"))
        {
            if (argc != 2 ){ROS_ERROR("need turtle name as argument"); return -1;};
            turtle_name = argv[1];
        }
    else
    {
        private_node.getParam("turtle", turtle_name);
    }
    ros::NodeHandle node;
    ros::Subscriber sub = node.subscribe(turtle_name+"/pose", 10, &poseCallback);
    ros::spin();
    return 0;
}