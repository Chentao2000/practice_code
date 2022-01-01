
 /*******************************************************************************************************
*
std  px4_pos_controller.cpp
*
* Author: Qyp
 // 这个是学习 prometheus的代码 所仿写的代码文件
 // 其中 会加入不少关于自己的理解和学习心得
 // 原文件是 在 Prometheus - Module s control Utilities px4_pos_control.cpp中 
*
* Introduction:  PX4 Position Controller 
*         1. 从应用层节点订阅/prometheus/control_command话题（ControlCommand.msg），接收来自上层的控制指令。
*         2. 从px4_pos_estimator.cpp节点订阅无人机的状态信息（DroneState.msg）。
*         3. 调用位置环控制算法，计算加速度控制量，并转换为期望角度。（可选择cascade_PID, PID, UDE, passivity-UDE, NE+UDE位置控制算法）
*         4. 通过command_to_mavros.h将计算出来的控制指令发送至飞控（通过mavros包发送mavlink消息）
*         5. PX4固件通过mavlink_receiver.cpp接收该mavlink消息。
*************************************************************************************************/ 
#include <ros/ros.h>
#include "state_from_mavros.h"
#include "command_to_mavros.h"
#include "prometheus_control_utils.h"
#include "message_utils.h"
#include "control_common.h"
#include "Position_Controller/pos_controller_cascade_PID.h"
#include "Position_Controller/pos_controller_PID.h"
#include "Position_Controller/pos_controller_UDE.h"
#include "Position_Controller/pos_controller_NE.h"
#include "Position_Controller/pos_controller_Passivity.h"
#include "Filter/LowPassFilter.h"
#define NODE_NAME "pos_controller"

// 一堆头文件
using namespace std;
// 变量声明
float cur_time;                          // 程序运行时间
string controller_type          // 控制器类型
float Takeoff_height;             //默认起飞高度
float Disarm_heitht;               // 自动上锁高度
float Land_speed;                   // 降落高度



// 地理围栏：
Eigen::Vector2fgeo_fence_x;
Eigen::Vectro2fgeo_fence_y;
Eigen::Vector2fgeo_fence_z;
/*
Eigen是可以用来进行线性代数、矩阵、向量操作等运算的C++库，它里面包含了很多算法
*/
Eigne::Vector3d Takeoff_postition; // 起飞位置
prometheus_msgs::DroneState_DroneState; //无人机状态量
prometheus_msgs::ControlCommand Command_Now;  // 无人机当前执行命令
prometheus_msgs::ControlCommand Command_Last;  //无人机上一条执行的命令


prometheus_msgs::ControlOutput_Controlput;
prometheus_msgs::ControlCommand Command_Now; // 无人机当前执行的命令
prometheus_msgs::ControlCommand Command_Last; //无人机上一条执行命令

prometheus_msgs::ControlOutput_ControlOutput;
prometheus_msgs::AttitudeReference_AttitudeReference; // 位置控制器输出 ，即状态环参考量
prometheus_msgs::Message messages;
prometheus_msgs::LogMessageControl LogMessage;



// Rviz  显示 ： 期望位置
geometry_msgs :: PoseStamped ref_pose_rviz;
float dt = 0;


float disturbance_a_xy,disturbace_b_xy;
float disturbance_a_z,disturbace_b_z;
float disturbance_T;
float disturbance_start_time;
float disturbacne_end_time;


ros::Publisher att_ref_pub;
ros::Publisher rviz_ref_pose_pub;
ros::Publisher message_pub;
ros::Publisher log_message_pub;
Eigen::Vector3d throttle_sp;



