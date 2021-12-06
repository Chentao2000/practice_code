// 这 一节向大家介绍 mavros 比较常用的控制消息 以及参数代表的意义
//-------------------------------------------------------------------------------------------//


/*
        1. autuator_control 控制飞控IO输出 （混控器）
        消息名称： mavros  / actuator_control
        类型名称： mavros_msgs::ActuatorControl.h
        类型所在头文件 ：mavros_msgs/ActuatorControl.h 
        常用类成员变量 ：
         uint group_mix // 要控制的混控制器 分组 1 - 8 
        （     control group    ）
        float32[8] control // 控制量，前四个分别是 roll pitch yaw thrust


*/


//-----------------------------------------------------------------------------------------------//
// 2. setpoint_accel 控制期望加速度
/*
        消息名称 ： mavros/setpoint_accel/accel
        类型名称 ： geometry_msgs::Vector3Stamped
        类型所在头文件 ： geometry_msgs::Vector3Stamped.h
        常用类成员变量：
        geometry_msgs::Vector3 vector   // 3轴加速度
    
*/
// --------------------------------------------------------------------------------------------------//


// ---------------------------------------------------------------------------------------------------//
//  3. setpoint_attitude 控制期望姿态
/*
        消息名称 ： mavros/setpoint_attitude/attitude
        类型名称 ：geometry_msgs::PoseStamped
        类型所在头文件 ： geometry_msgs/PoseStamped.h
        常用类型所在头文件：geometry_msgs/PoseStamped.h
        常用类成员变量：
        geometry_msgs::Pose pose // 三个欧拉角 或者四元数任选其一

*/


// ---------------------------------------------------------------------------------------------------//
//  4. setpoint_posistion 控制期望姿态
/*
        消息名称 ： mavros/setpoint_position/local
        类型名称 ：geometry_msgs::PoseStamped
        类型所在头文件 ： geometry_msgs/PoseStamped.h
        常用类型所在头文件：geometry_msgs/PoseStamped.h
        常用类成员变量：
        geometry_msgs::Pose pose // NED坐标下的位置（X ,Y Z）
        只有position 成员变量生效

*/

// -------------------------------------------------------------------------------------------------------//
// 5 . setpoint_velocity 控制期望的速度
/*
        消息名称 ： mavros / setpoint_velocity/cmd_vel
        类型名称 :    geometry_msgs::TwistStamped
        类型所在头文件：geometry_msgs /TwistStamped
        常用类成员变量:
        geometry_msgs::Twist twist  //三轴加速度 
        geometry_msgs::Twist   类成员变量
        geometry_msgs::Vector3 linear //三轴线速度
        geometry_msgs::Vector3 angular  //三轴线速度

*/

// ----------------------------------------------------------------------------------------------------------//
// 6. 控制期望的位置 （GPS 坐标）
/*
    消息名称 ： mavros/setpoint_postition/global
    类型名称 ：mavros_msgs :: GlobalPositionTarget
    类型所在头文件 ：mavros_msgs/GlobalPostitionTarget.h
    常用类成员变量：
    uint8 coordinate_frame 
    // 5 为绝对GPS坐标 6 位相对高度 GPS坐标
    uint16 type_mask
    -- 以下位控制掩码，如果只想控制经纬高---

    uint16      lGNORE_LATITUDE = 1          # Position ignore flags
    uint16      IGNORE_LONGITUDE = 2
    uint16      IGNORE_ALTITUDE = 4
    uint16      IGNORE_VX = 8  #Velocity vector ignore flags
    uint16      IGNORE_VY = 16
    uint16      IGNORE_VZ = 32
    uint16      IGNORE_AFX = 64 # Acceleration/Force vector ignore flags
    uint16      IGNORE_AFY = 128
    uint16      IGNORE_AFZ = 256
    uint16      FORCE = 512 # Force in af vector flag
    uint16      IGNORE_YAW = 1024
    uint16      IGNORE_YAW_RATE = 2048

    float64     latitude//经纬高
    float64     longitude
    float32     altitude
    geometry_msgs /Vector3 velocity//速度
    geometry_msgs/Vector3 acceleration_or_force//加速度
    float32 yaw//偏航
    float32 yaw_rate//偏航速度
*/
