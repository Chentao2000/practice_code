/***************************************************************************************************************************
* controller_test.h
*
* Author: Qyp
*
* Update Time: 2020.1.10
*               Controller_Test类用于控制器测试，提供圆形、8字、阶跃响应三种参考输入
*                   1、圆形需设置圆心、半径、线速度、旋转方向等参数
*                   2、8字需设置圆心、半径、角速度等参数
*                   3、阶跃响应需设置响应大小及响应间隔

***************************************************************************************************************************/
//  位置环控制 ：  输入:期望位置或速度、当前位置/速度
// 输出:机体z轴升力,期望姿态角
#ifndef CONTROLLER_TEST_H
#define CONTROLLER_TEST_H

#include <Eigen/Eigen>
#include <math.h>
#include <math_utils.h>
#include <prometheus_control_utils.h>
#include <prometheus_msgs/PositionReference.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>


using namespace std;

class Controller_Test
{
    public:
        //构造函数
        Controller_Test(void):
            Controller_Test_nh("~")
        {
            Controller_Test_nh.param<float>("Controller_Test/Circle/Center_x", circle_center[0], 0.0);
            Controller_Test_nh.param<float>("Controller_Test/Circle/Center_y", circle_center[1], 0.0);
            Controller_Test_nh.param<float>("Controller_Test/Circle/Center_z", circle_center[2], 1.0);
            Controller_Test_nh.param<float>("Controller_Test/Circle/circle_radius", circle_radius, 2.0);
            Controller_Test_nh.param<float>("Controller_Test/Circle/linear_vel", linear_vel, 0.5);
            Controller_Test_nh.param<float>("Controller_Test/Circle/direction", direction, 1.0);

            Controller_Test_nh.param<float>("Controller_Test/Eight/Center_x", eight_origin_[0], 0.0);
            Controller_Test_nh.param<float>("Controller_Test/Eight/Center_y", eight_origin_[1], 0.0);
            Controller_Test_nh.param<float>("Controller_Test/Eight/Center_z", eight_origin_[2], 1.0);
            Controller_Test_nh.param<float>("Controller_Test/Eight/omega", eight_omega_, 0.5);
            Controller_Test_nh.param<float>("Controller_Test/Eight/radial", radial, 2.0);

            Controller_Test_nh.param<float>("Controller_Test/Step/step_length", step_length, 0.0);
            Controller_Test_nh.param<float>("Controller_Test/Step/step_interval", step_interval, 0.0);

        }

        //Printf the Controller_Test parameter
        void printf_param();

        //Controller_Test Calculation [Input: time_from_start; Output: Circle_trajectory;]
        prometheus_msgs::PositionReference Circle_trajectory_generation(float time_from_start);

        prometheus_msgs::PositionReference Eight_trajectory_generation(float time_from_start);

        prometheus_msgs::PositionReference Step_trajectory_generation(float time_from_start);

        prometheus_msgs::PositionReference Line_trajectory_generation(float time_from_start);

    private:

        ros::NodeHandle Controller_Test_nh;

        // Circle Parameter
        Eigen::Vector3f circle_center;
        float circle_radius;
        float linear_vel;
        float direction;         //direction = 1 for CCW 逆时针, direction = -1 for CW 顺时针

        // Eight Shape Parameter
        Eigen::Vector3f eight_origin_;
        float radial;
        float eight_omega_;

        // Step
        float step_length;
        float step_interval;
        
};


prometheus_msgs::PositionReference Controller_Test::Circle_trajectory_generation(float time_from_start)
{
    prometheus_msgs::PositionReference Circle_trajectory;
    float omega;
    int my_circle_radius = 2;
    if( my_circle_radius != 0)
    {
        omega = direction * fabs(linear_vel / my_circle_radius);  //fabs 求绝对值
        // omega = 方向  * |（线速度  /  半径）| =角速度
    }else
    {
        omega = 0.0;
    }
    const float angle = time_from_start * omega;  // 角度 等于 角速度乘以时间开始
    // const float cos_angle = cos(angle);  
    // const float sin_angle = sin(angle);
/* -------------------------------------------------------------------------------------- */
// 画个爱心代码x=12*sin(t)-4*sin(3*t),y=13*cos(t)-5*cos(2*t)-2*cos(3*t)-cos(4*t)
     const float cos_angle = 12*sin(angle) - 4*sin( 3 * angle);  
     const float sin_angle = 13*cos(angle) - 5*cos(2*angle) -2*cos(3*angle) - cos(4*angle) ;
    //cout << "omega : " << omega  * 180/M_PI <<" [deg/s] " <<endl;
    //cout << "angle : " << angle  * 180/M_PI <<" [deg] " <<endl;
// 位置的导数 就等于速度 ： derivatives
        const float cos_angle_derivatives  =( 12*cos(angle) -12*cos( 3 * angle));
        const float sin_angle_derivatives   = (-13*sin(angle) +10*sin(2*angle) +6*sin(3*angle) +4*sin(4*angle) );
// 速度的导数等于加速度 ：derivatives2
        const float cos_angle_derivatives2  =  ( -12*sin(angle) + 12*3*sin(3*angle)  );
        const float sin_angle_derivatives2   = (-13*cos(angle) +20*cos(2*angle) +18*cos(3 * angle) +16*cos(4*angle) );
/* -------------------------------------------------------------------------------------- */
    Circle_trajectory.header.stamp = ros::Time::now();

    Circle_trajectory.time_from_start = time_from_start;  // 获取参数 获取运行的时间

    Circle_trajectory.Move_mode = prometheus_msgs::PositionReference::TRAJECTORY;

    //Circle_trajectory.position_ref[0] =(12*sin(angle) - 4 sin(3*angel))*circle_radius+ circle_center[0]; //  x 就是 半径 乘以 cos 角度 + 当前的位置
    //Circle_trajectory.position_ref[1] = (13cos(angle) - 5cos(2*angle) -2cos(3*angle) - cos(4*angle) ) * circle_radius  + circle_center[1]; //  y 就是 半径 乘以 sin 角度 + 当前的位置
    Circle_trajectory.position_ref[0] = cos_angle; +circle_center[0];//  x 就是 半径 乘以 cos 角度 + 当前的位置
    Circle_trajectory.position_ref[1] = sin_angle; +circle_center[1];//  y 就是 半径 乘以 sin 角度 + 当前的位置
    Circle_trajectory.position_ref[2] = circle_center[2]; // 当前的位置

    Circle_trajectory.velocity_ref[0] =  (cos_angle_derivatives);  // 期望 x 速度 就是   半径乘以 角速度 * sin 角度  =  线速度 * 角度 
    Circle_trajectory.velocity_ref[1] = (sin_angle_derivatives);//期望 cos 速度 就是   半径乘以 角速度 * cos 角度  =  线速度 * 角度 
    Circle_trajectory.velocity_ref[2] = 0;

// 期望加速度x ： 角速度的平方 * cos 角度 乘以  角度值
    //l加速度与线速度的关系：；a=v^2/R
    //加速度与角速度的关系：；a=w^2*R 
    // 期望加速度y ： 角速度的平方 * sin 角度 乘以  角度值
    // pow 是求 次方

    Circle_trajectory.acceleration_ref[0] =  cos_angle_derivatives2;  // 期望加速度x ： 角速度的平方 * cos 角度 乘以  角度值
    //l加速度与线速度的关系：；a=v^2/R
    //加速度与角速度的关系：；a=w^2*R 
    Circle_trajectory.acceleration_ref[1] =  sin_angle_derivatives2;// 期望加速度y ： 角速度的平方 * sin 角度 乘以  角度值
    // pow 是求 次方
    Circle_trajectory.acceleration_ref[2] = 0;

    // Circle_trajectory.jerk_ref[0] = circle_radius * pow(omega, 3.0) * sin_angle;
    // Circle_trajectory.jerk_ref[1] = - circle_radius * pow(omega, 3.0) * cos_angle;
    // Circle_trajectory.jerk_ref[2] = 0;

    // Circle_trajectory.snap_ref[0] = circle_radius * pow(omega, 4.0) * cos_angle;
    // Circle_trajectory.snap_ref[1] = circle_radius * pow(omega, 4.0) * sin_angle;
    // Circle_trajectory.snap_ref[2] = 0;

    Circle_trajectory.yaw_ref = 0;
    // Circle_trajectory.yaw_rate_ref = 0;
    // Circle_trajectory.yaw_acceleration_ref = 0;

    return Circle_trajectory;  // 返回一个轨迹 数组 ，这个数组包括了 期望位置  期望角速度  期望角加速度
}

prometheus_msgs::PositionReference Controller_Test::Line_trajectory_generation(float time_from_start)
{
    prometheus_msgs::PositionReference Line_trajectory;
    float omega;
    if( circle_radius != 0)
    {
        omega = direction * fabs(linear_vel / circle_radius);
    }else
    {
        omega = 0.0;
    }
    const float angle = time_from_start * omega;
    const float cos_angle = cos(angle);
    const float sin_angle = sin(angle);


    Line_trajectory.header.stamp = ros::Time::now();

    Line_trajectory.time_from_start = time_from_start;

    Line_trajectory.Move_mode = prometheus_msgs::PositionReference::TRAJECTORY;

    Line_trajectory.position_ref[0] = 0.0;
    Line_trajectory.position_ref[1] = circle_radius * sin_angle + circle_center[1];
    Line_trajectory.position_ref[2] = circle_center[2];

    Line_trajectory.velocity_ref[0] = 0.0;
    Line_trajectory.velocity_ref[1] = circle_radius * omega * cos_angle;
    Line_trajectory.velocity_ref[2] = 0;

    Line_trajectory.acceleration_ref[0] = 0.0;
    Line_trajectory.acceleration_ref[1] = - circle_radius * pow(omega, 2.0) * sin_angle;
    Line_trajectory.acceleration_ref[2] = 0;

    // Line_trajectory.jerk_ref[0] = circle_radius * pow(omega, 3.0) * sin_angle;
    // Line_trajectory.jerk_ref[1] = - circle_radius * pow(omega, 3.0) * cos_angle;
    // Line_trajectory.jerk_ref[2] = 0;

    // Line_trajectory.snap_ref[0] = circle_radius * pow(omega, 4.0) * cos_angle;
    // Line_trajectory.snap_ref[1] = circle_radius * pow(omega, 4.0) * sin_angle;
    // Line_trajectory.snap_ref[2] = 0;

    Line_trajectory.yaw_ref = 0;
    // Line_trajectory.yaw_rate_ref = 0;
    // Line_trajectory.yaw_acceleration_ref = 0;

    return Line_trajectory;
}


prometheus_msgs::PositionReference Controller_Test::Eight_trajectory_generation(float time_from_start)
{
    Eigen::Vector3f position;
    Eigen::Vector3f velocity;
    Eigen::Vector3f acceleration;
    
    float angle = eight_omega_* time_from_start;
    const float cos_angle = cos(angle);
    const float sin_angle = sin(angle);
    /* -------------------------------------------------------------------------------------- */
// 画个爱心代码x=12*sin(t)-4*sin(3*t),y=13*cos(t)-5*cos(2*t)-2*cos(3*t)-cos(4*t)
     const float my_cos_angle = 12*sin(angle) - 4*sin( 3 * angle);  
     const float my_sin_angle = 13*cos(angle) - 5*cos(2*angle) -2*cos(3*angle) - cos(4*angle) ;
    //cout << "omega : " << omega  * 180/M_PI <<" [deg/s] " <<endl;
    //cout << "angle : " << angle  * 180/M_PI <<" [deg] " <<endl;
// 位置的导数 就等于速度 ： derivatives
        const float cos_angle_derivatives  =( 12*cos(angle) -12*cos( 3 * angle));
        const float sin_angle_derivatives   = (-13*sin(angle) +10*sin(2*angle) +6*sin(3*angle) +4*sin(4*angle) );
// 速度的导数等于加速度 ：derivatives2
        const float cos_angle_derivatives2  =  ( -12*sin(angle) + 12*3*sin(3*angle)  );
        const float sin_angle_derivatives2   = (-13*cos(angle) +20*cos(2*angle) +18*cos(3 * angle) +16*cos(4*angle) );
/* -------------------------------------------------------------------------------------- */
    Eigen::Vector3f eight_radial_ ; 
    Eigen::Vector3f eight_axis_ ; 
    eight_radial_ << radial, 0.0, 0.0; //半径
    eight_axis_ << 0.0, 0.0, 2.0;   //坐标轴
// TAO __        8字 射线轴， 数组角度  【radial   0.0    0.0】
// TAO __        8字 坐标轴， 数组角度   【 0.0    0.0   2.0 】
      position = cos_angle * eight_radial_ + sin_angle * cos_angle * eight_axis_.cross(eight_radial_)
      //  cosx* r + sinx*cosx*坐标轴*半径 + (1 - x)*半径*坐标轴*坐标轴 +初始坐标
                     + (1 - cos_angle) * eight_axis_.dot(eight_radial_) * eight_axis_ + eight_origin_;
    
//TAO__  位置 = cos（angle） * 【 0.0    0.0】  + sin（angle） * cos（angle）*(【 0.0    0.0   2.0 】 *【radial   0.0    0.0】)  + （1 - cos（angle） * 【 0.0    0.0   2.0 】 *【radial   0.0    0.0】*【 0.0    0.0   2.0 】+ 【 0 0 0】）

    velocity = eight_omega_ * (-sin_angle * eight_radial_ + (pow(cos_angle, 2) - pow(sin_angle, 2)) * eight_axis_.cross(eight_radial_)
        //  速度 =  角速度 *（-  sinx* 半径  + cosx的二次方  -  sinx 二次方）乘以 坐标轴*半径
                 + (sin_angle) * eight_axis_.dot(eight_radial_) * eight_axis_);

    acceleration << 0.0, 0.0, 0.0;

    prometheus_msgs::PositionReference Eight_trajectory;

    Eight_trajectory.header.stamp = ros::Time::now();

    Eight_trajectory.time_from_start = time_from_start;

    Eight_trajectory.Move_mode = prometheus_msgs::PositionReference::TRAJECTORY;

    Eight_trajectory.position_ref[0] = position[0];
    Eight_trajectory.position_ref[1] = position[1];
    Eight_trajectory.position_ref[2] = position[2];

    Eight_trajectory.velocity_ref[0] = velocity[0];
    Eight_trajectory.velocity_ref[1] = velocity[1];
    Eight_trajectory.velocity_ref[2] = velocity[2];

    Eight_trajectory.acceleration_ref[0] = 0;
    Eight_trajectory.acceleration_ref[1] = 0;
    Eight_trajectory.acceleration_ref[2] = 0;

    Eight_trajectory.yaw_ref = 0;

    // to be continued...

    return Eight_trajectory;
}


prometheus_msgs::PositionReference Controller_Test::Step_trajectory_generation(float time_from_start)
{
    prometheus_msgs::PositionReference Step_trajectory;

    Step_trajectory.header.stamp = ros::Time::now();

    Step_trajectory.time_from_start = time_from_start;

    Step_trajectory.Move_mode = prometheus_msgs::PositionReference::TRAJECTORY;

    int i = time_from_start / step_interval;

    if( i%2 == 0)
    {
        Step_trajectory.position_ref[0] = step_length;
    }else 
    {
        Step_trajectory.position_ref[0] = - step_length;
    }

    Step_trajectory.position_ref[1] = 0;
    Step_trajectory.position_ref[2] = 1.0;

    Step_trajectory.velocity_ref[0] = 0;
    Step_trajectory.velocity_ref[1] = 0;
    Step_trajectory.velocity_ref[2] = 0;

    Step_trajectory.acceleration_ref[0] = 0;
    Step_trajectory.acceleration_ref[1] = 0;
    Step_trajectory.acceleration_ref[2] = 0;

    Step_trajectory.yaw_ref = 0;

    return Step_trajectory;
}

// 【打印参数函数】
void Controller_Test::printf_param()
{
    cout <<">>>>>>>>>>>>>>>>>>>>>>>>>Controller_Test Parameter <<<<<<<<<<<<<<<<<<<<<<" <<endl;
    cout <<"Circle Shape:  " <<endl;
    cout <<"circle_center :  " << circle_center[0] <<" [m] "<< circle_center[1] <<" [m] "<< circle_center[2] <<" [m] "<<endl;
    cout <<"circle_radius :  "<< circle_radius <<" [m] " <<"linear_vel : "<< linear_vel <<" [m/s] "<<"direction : "<< direction << endl;

    cout <<"Eight Shape:  " <<endl;
    cout <<"eight_origin_ :  "<< eight_origin_[0] <<" [m] "<< eight_origin_[1] <<" [m] "<< eight_origin_[2] <<" [m] "<<endl;
    cout <<"eight_omega_ :  "<< eight_omega_  <<" [rad/s] " << "radial : "<< radial << endl;

    cout <<"Step:  " <<endl;
    cout <<"step_length :  "<< step_length << " [m] step_interval : "<< step_interval << " [s] "<<endl;
}


#endif
