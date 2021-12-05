
//  订阅GPS的数据
/*  
    消息名称  ： mavros/gazebo_posistion/gobal
    类型名称  ： seneor_msgs:: NavSatFix
    类型所在头文件 ： sensor_msgs/NavSatFix.h
    类型成员变量：
                                 float64 latitude  //经
                                 float64 longitude  //纬
                                 float64 altitude //海拔
                                 float64[9]  position_covariance 
                                 uint8 position_convariance_type
                        
*/

//-----------------------------
/* 订阅IMU 原始数据
2. imu_pub 
  消息名称： mavros/imu/data(或者 mavros/imu/data_raw mavros/imu/data)
  经过滤波后的数据
  类型名称 ：sensor_msgs::Imu
  类型所在头文件 ： sensor_msgs/imu.h
  类用类成员变量：
   ·geometry_msgs :: Quaterion orientation  旋转四元数（x  y w）
   ·float[64] orientation_convariance 方差 
   ·geometry_msgs::Vector3 angular_velocity // 3轴角速度（X Y Z）
   ·float[64]angular::velocity_covariance  反差
   ·geometry_msgs::Vector3 liner_acceleration // 线速度（X  Y Z ）
   ·float64[9] linear_acceleration_covariance   // 方差
   
     geometry_msgs::Quaternion 类成员变量
     float64 x
     float64 y
     float64 z
     float64 w

    geometry_msgs::Vector3 类成员变量
    float64  x
    float64 y
    float64 z

*/  
// --------------------------------------------------------------------------------
// 4. manual_control  订阅遥控器的值
/*
    消息名称： mavros/manual_control/control
    类型名称： mavros_msgs::ManualControl
    类型所在头文件：mavros_msgs/ManualControl.h
    常用类成员变量：
     float32 x
     float32 y
     float32 z
     float32 r
     uint16 buttons

*/

// --------------------------------------------------------------------------
// -------------------------------------------------------------------------
// 4. manual_control 定阅 遥控器的值
/*
     消息名称 ： mavros/manual_control/conntrol
     类型名称 ：mavro_msgs::ManualControl
     类型所在头文件 ： mavros_msgs/ManualControl.h
    常用类成员变量：
    float32 x
    float32 y
    float32 z
    float32 r
    uint16 buttons
*/

// ---------------------------------------------------------------------
// -----------------------------------------------------------------------
//   Sys_status   查询系统状态
/*
   消息名称：mavros/state
   类型名称： mavros_msgs/State.h
   类型所在头文件： mavros_msgs/State.h
   常用类成员变量：
        Bool conntected 是否连接
        bool armed  是否解锁
        bool guided  是否被引导（offboard 模式）
        string mode //模式类型
        uint18 system_status 
*/

// -------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---- 查询航点：6. waypoint
/*
消息名称 ：mavros/mission/waypoints
类型名称 ： mavros_msgs::Waypont.sh
类型所在头文件： mavros_msgs/WaypointList.h
常用类成员变量：  
uint16 current_seq/当前航点索引
mavros_msgs::Waypoint [ ] waypoint//航点列表 注意一个vector
mavros_msgs::Waypoint 类成员变量：
uint8 frame  坐标类型
uint16 comman   命令id   16 为航点
bool is cuurent 
bool autocontinue
float32 param1
float32 param2
float32 param3
float32 param4
float64 x_lat 经度 或者x坐标
float64 y_long 维度 或者y坐标
float64 z_alt  海拔或者z坐标


*/
