prometheus_msgs::PositionReference Controller_Test::Circle_trajectory_generation(float time_from_start)
{
    prometheus_msgs::PositionReference Circle_trajectory;
    float omega;
    if( circle_radius != 0)
    {
        omega = direction * fabs(linear_vel / circle_radius);  //fabs 求绝对值
        // omega = 方向  * |（线速度  /  半径）| =角速度
    }else
    {
        omega = 0.0;
    }
    const float angle = time_from_start * omega;  // 角度 等于 角速度乘以时间开始
    const float cos_angle = cos(angle);  
    const float sin_angle = sin(angle);

    cout << "omega : " << omega  * 180/M_PI <<" [deg/s] " <<endl;
    cout << "angle : " << angle  * 180/M_PI <<" [deg] " <<endl;

    Circle_trajectory.header.stamp = ros::Time::now();

    Circle_trajectory.time_from_start = time_from_start;  // 获取参数 获取运行的时间

    Circle_trajectory.Move_mode = prometheus_msgs::PositionReference::TRAJECTORY;
    Circle_trajectory.position_ref[0] = circle_radius * cos_angle + circle_center[0]; //  x 就是 半径 乘以 cos 角度 + 当前的位置
    Circle_trajectory.position_ref[1] = circle_radius * sin_angle + circle_center[1]; //  y 就是 半径 乘以 sin 角度 + 当前的位置
    Circle_trajectory.position_ref[2] = circle_center[2]; // 当前的位置

    Circle_trajectory.velocity_ref[0] = - circle_radius * omega * sin_angle;  // 期望 x 速度 就是   半径乘以 角速度 * sin 角度  =  线速度 * 角度 
    Circle_trajectory.velocity_ref[1] = circle_radius * omega * cos_angle;//期望 cos 速度 就是   半径乘以 角速度 * cos 角度  =  线速度 * 角度 
    Circle_trajectory.velocity_ref[2] = 0;

    Circle_trajectory.acceleration_ref[0] = - circle_radius * pow(omega, 2.0) * cos_angle;  // 期望加速度x ： 角速度的平方 * cos 角度 乘以  角度值
    //l加速度与线速度的关系：；a=v^2/R
    //加速度与角速度的关系：；a=w^2*R 
    Circle_trajectory.acceleration_ref[1] = - circle_radius * pow(omega, 2.0) * sin_angle;// 期望加速度y ： 角速度的平方 * sin 角度 乘以  角度值
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

    return Circle_trajectory;  // 返回一个轨迹 数组 ，这个数组包括了 期望位置  期望速度  期望角速度
}
