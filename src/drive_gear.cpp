#include "ros/ros.h"
#include <iostream>
#include "dbw_mkz_msgs/BrakeCmd.h"
#include "dbw_mkz_msgs/GearCmd.h"
#include "std_msgs/Empty.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "drive_gear");
    ros::NodeHandle n;
    ros::Publisher dbw_pub;
    ros::Rate loop_rate(10);
    dbw_pub = n.advertise<std_msgs::Empty>("/vehicle/enable", 1);

    ros::Publisher brake_pub;
    brake_pub = n.advertise<dbw_mkz_msgs::BrakeCmd>("/vehicle/brake_cmd", 1);

    ros::Publisher gear_pub;
    gear_pub = n.advertise<dbw_mkz_msgs::GearCmd>("/vehicle/gear_cmd", 1);

    int count=0;

    std_msgs::Empty dbw_enable;
    dbw_mkz_msgs::BrakeCmd brake_msg;
    dbw_mkz_msgs::GearCmd gear_msg;

    while (ros::ok())
    {
        if (count<1)
        {
            //std::cout<<"here"<<std::endl;
            for(int i=1; i<10; i++)
            {
                dbw_pub.publish(dbw_enable);
                loop_rate.sleep();
                ros::spinOnce();
            }
        }
        else{}
        brake_msg.pedal_cmd = 1.0;
        brake_msg.pedal_cmd_type = 2;
        brake_msg.enable=true;
        brake_msg.clear=false;
        brake_msg.ignore=false;
        brake_msg.count=0;

        brake_pub.publish(brake_msg);

        gear_msg.cmd.gear=4;
        gear_msg.clear=false;

        gear_pub.publish(gear_msg);

        loop_rate.sleep();
        ros::spinOnce();
        count+=1;
        
        if (count<1000)
        {
            ros::shutdown();
        }
    }
    return 0;

}