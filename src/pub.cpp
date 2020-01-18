#include <string>
#include <ros/ros.h>
#include <std_msgs/String.h>

int main (int argc, char **argv)
{
	ros::init(argc, argv, "pub");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<std_msgs::String>("/chatter", 10);
	ros::Rate rate(10);
	for (size_t counter = 0; ros::ok(); ++counter)
	{
		std_msgs::String msg;
		msg.data = std::string("Hello, ROS World!: ") + std::to_string(counter);
		pub.publish(msg);
		ros::spinOnce();
		rate.sleep();
	}
	return 0;
}
