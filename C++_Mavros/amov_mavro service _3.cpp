// 通过前面两节的学习，我们对mavros操作无人机有了深刻的理解，无非就是通过ROS去取得以下当前的飞行状态，然后发送控制让他执行
// 当前在控制的时候，你可以选取很多方式，加速度方式，位置方式，姿态方式，都是可行的
// 那么这一节，将会围绕两个服务进行我们讲解，（模式切换 解锁 
// -------------------------------------------------------------------

// 1. arming Service  加解锁服务
// 消息名称 ： mavros/cmd/arming
// 类型名称 ： mavros_msgs::CommandBool
// 类型所在头文件 ：mavros_msgs / CommandBool.h

// 服务请求参数 ：
//    bool success //是否能执行成功
//    uint8 result  // 错误信息

// 注意： 在ros中所有服务参数都在 xxx.request 中，所有返回状态都在 xxx.response 中 
// 如果我们想要解锁，那么代码可以如下来写 

// ros :: init (  argc ,argv,"offb_node " );
// ros ::  NodeHandle nh;

// ros::SeviceClient          arming_client
// nh.serviceClient     <     mavros_msgs ;; CommandBool >("mavros / cmd / arming")

// mavros_msgs::CommandBool>("mavros/cmd/arming");

// mavros_msgs::CommandBool arm_cmd;
// arm_cmd.request.value = true //注意这里是 arm_cmd.request.value ,不是arm_cmd.valuse


// arming_client.call (arm.cmd);

 // 执行完毕以后返回信息在：
 //  arm_cmd.response.success
 //  arm_cmd.response.result


 // 2. 模式切换
 // 消息名称：mavros/set_mode 
 // 类型名称：mavros_msgs::SetMode
 // 类型所在头文件 : mavros_msgs / SetMode.h


 // 服务请求参数
 // uint8 base_mode    //基本参数  如果custom_mode 不为空 此项无效
 // string custom_mode // 通常我们使用custom_mode 如果想进入offboard 模式
 // 在PX4  中赋值 “OFFBOARD ”,在 APM 中 "GUIDED"

 // 服务返回的结果：
 // bool mode _sent // 为true 表示正确切换