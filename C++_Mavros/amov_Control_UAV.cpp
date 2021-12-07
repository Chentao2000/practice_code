// 在第一章节中，已经给出了比较详细的列子，以后所有的新ros节点都可以根据这个例子派生而来
// 我们在这一节会在这个例子代码的
// 基础上 运用前面几章所学的知识写一个新的ros节点


// 这个新的节点一运行就会自动进入offfboard 模式，然后解锁机器，起飞，然后在空中飞行一个正方形回来再自动降落
// 首先回顾一下以前的代码：

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include<mavros_msgs/CommanBool.h>
#include<mavros_msgs/SetMode.h>
#include<mavros_msgs/State.h>

mavros_msgs:: State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}

int main(int argc,char **argv)
{
    ros::init(argc,argv,"offb_node");
    ros::NodeHandle nh;

    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
                                                            ("mavros/state",10,state_cb);
    ros::Publisher local_pos_pub = ng.advertise<geometry_msgs::PoseStamped>
                                                            ("mavros/setpoint_position/local",10);
    ros::ServiceClient arming_client = nh.serceClient<mavros_msgs::CommandBool>
                                                            ("mavros/cmd/arming");
    ros::ServiceClient ste_mode_client = nh.serviceClient<mavros_msgs::SetMode>
                                                            ("mavros/set_mode");
    ros::Rate rate(20.0);

    while(ros::ok()&& current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }

    geometry_msgs::PoseStamped pose;
    pose.pose.position.x =0;
    pose.pose.postition.y=0;
    pose.pose.postition.z=2;

    for(int i = 100;  ros :: ok(   ) &&  i > 0 ;  --i ){
        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    }
    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.rquest.value = true;
    ros::Time last_request = ros::Time::now();


    while( ros::ok(   ) ){
        if(current_state.mode != "OFFBOARD" &&(ros::Time::now()-last_request  > ros::Duration(5.0) )){
            if(set_mode_client.call (offb_ste_mode) && offb_set_mode.response.mode_sent ){
                ROS_INFO("Offboard enable");
            }
            last_request = ros::Time::now();
        }
        else{
            if( !current_state.armed&&(ros::Time::now() -last_request>  ros:: Duration(5.0))){
                if(arming_client.call(arm_cmd)&&arm_cmd.response.success){
                    ROS_INFO("Vehicle armed");

                }
                last_request = ros::Time::now();

            }
        }

        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    } 
    return 0;
  
}
// 上面 这里去掉是所有注释
// 下面 我们在主循环看见   if-else 我们会判断是否处于offboard模式
// 如果已经在offboard模式又会进入else分支中

// 判断是否没有解锁，如果没有解锁，就会执行解锁 ，下面我们现在最下面分支中添加一个else
// 如下 :

if(current_state.mode !=   "OFFBOARD" && (（ros::Time::now() - last_request > ros::Duration(5.0))){
    if(set_mode_client.call(offb_set_mode)&&offb_set_mode.response.mode_sent){
        ROS_INFO("Offboard enabled");

    }
    last_request = ros::Time::now();
}else {
    if(!current_state.armed && (ros::Time::now()-last_requeset > ros::Duration(5:0))){
        if(arming_client.call(arm_cmd)&&arm_cmd.response.success){
            ROS_INFO("Vehicle armed");
        }
        last_request = ros::Time::now();
    }
    else{
        // 这里添加一个else表示目前已经处于offboard模式并已经解锁
    }
}
