/****************************************************************************
Tiitle : Draw a flower using the ROS turtle emulator FOR C++
 Author  : AMOV-ANUU 
Data  : 2021 6 14
****************************************************************************/
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdio.h>

int main(int argc,char **argv)
{
    ros::init(argc,argv,"hello_turtle");
    //Init  of  the ROS program "hello_turtle"


    ros::NodeHandle n;
    //  Create a RosNodeHanele n

	ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 100);
    // Create a Publisher，make name /turtle1/cmd_vel的topic， message type:  geometry_msgs::Twist，quene: 10

    ros::Rate loop_rate(100);
    // setup the ROS rate

 		int  count = 0; //Cycle counter
		int  all_count=0; //The total counter


    while(ros::ok())
    {
            // inti geometry_msgs::Twist  
            geometry_msgs::Twist vel_msg;

		all_count++;  
		count ++;
		if(count <100)  // Draw a flower

		{       		
			vel_msg.angular.z = 0.5; vel_msg.linear.x=1;         
				ROS_INFO( "count  = %d ",count);   
		}else if((count>100)&&(count <200))
		{
			vel_msg.angular.z = 0.5; vel_msg.linear.y=1;            
				ROS_INFO( "count  = %d ",count); 
		}else if(count>200)		count=0;

        // publisher a msgs
             turtle_vel_pub.publish(vel_msg);
		ROS_INFO("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]", vel_msg.linear.x, vel_msg.angular.z);

        // Delay according to cycle frequency
        loop_rate.sleep();
    }
    return 0;

}
