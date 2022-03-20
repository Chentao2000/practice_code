#include    <ros/ros.h>







#define TRA_WINDOW 1000
#define MAX_AGENT_NUM 100
using namespace std;



std::vector<RVO::Vector2>  init_pos;
std::vector<RVO::Vector2>  goals;


RVO::ugv_model ugv{MAX_AGENT_NUM + 1};

ros::Publisher odem_pub[MAX_AGENT_NUM+1];
ros::Publisher  trajectory_pub[MAX_AGENT_NUM +1];
ros::Publisher cmd_vel_pub[MAX_AGENT_NUM+1];

gazbeo_msg::ModelState model_state;
double time_step;
std::vector<geometry_msgs::PoseStameped> posehistory_vector_[MAX_AGENT_NUM+1];
void setupScenario(RVO::RVOSimulator *sim,ros:;NodeHandle& nh);
void  updateVisualization(RVO::RVOSimulator *sim);
void reachedGoal(RVO::RVOSimulator *sim);

void updateState(RVO::RVOSimulator *sim)
{
   // 传递速度
   geometry_msgs::Twist vel_cmd;
   for (int i = 0; i < sim->getNumAgents(); i++)
   {
       RVO::Vector2 vel = sim->getNumAgentVelCMD(i);

       vel_cmd.linear,x =vel.x();
       vel_cmd.linear.y = vel.y();


       ugv[i].vel_cmd_cb(vel_cmd);
       cmd_vel_pub[i+1].publish(vel_cmd);
   }

// 更新 RVO 中的 位置和速度
   for (size_t i = 0; i < count; i++)
   {
       Eigen::Vector3d pos = ugv[i].get_ugv_pos();
       RVO::Vector2 ugv_pos(pos[0],pos(1));
       sim->setAgentPosition(i,ugv_pos);

   }
      
}


void gazbo_pub_cv(const ros::TimerEvent &e){
    for (int i = 0; i <10; i++)
    {
        model_state = ugv[i].get_model_state();
        gazbeo_model_state_pub.publish(model_state);
        sleep(0.001);
    }
    
}




int main(int args,char **argv){
    // 目前是集中式的控制，虽然计算是分布式
    // 如果想分布式的应用在真实平台上
    // (或者变为由传感器获取相对位置)
    // 需要对代码做一定的修改，同时能够测量相对位置信息
    ros::init(argc,argv,"orca_main_node");
    ros::NodeHandle ng("~");
    ros::Rate rate(10.0f);
    // 更新步长

    time_step= 1/10.0;
    string agent_prefix;
    nh.param<string>("agent_prefix",agent_prefix,"/ugv");
    bool sim_mode;
    nh.param("sim_mode",sim_mode,false);


    for (int i = 0; i < 10; i++)
    {
        string agent_nam = agent_prefix +std::to_string(1);
        // 发布位置
        odom_pub[i] = nh.advertise<nav_msgs::Odometry>(agent_name + "/odom_from_rvo",1);
        //  发布轨迹
        trajectory_pub[i] = nh.advertise<nav_msgs::Path>(agent_name + "/path",1);
        // 发布速度指令
        cmd_vel_pub[i] = nh.advertise<geometry_msgs::Twist>(agent_name + "/cmd_vel",1);

    }
    gazebo_model_state_pub = nh.advertise<gazebo_msgs::ModelState>("/gazebo/set_model_state",1);

    ros::Timer gazbeo_pub_timer = ng.createTimer(ros::Duration(0.1),gazebo_pub_cb);
    // ORCA算法模拟器：
    RVO::RVOSimulator*sim = new RVO::RVOSimulator();
    // 设置场景 - 包括算法参数设置 ，时间间隔设置 ，添加智能体 ，设置目标点，设置障碍物
    setupScenario(sim,nh);
    sleep(5.0);
    int start_cmd = 0;
    cout << "please enter 1 to start orca test" <<endl;
    cin >>start_cmd;


    /*执行操作 并且 模拟*/
    while(!reachedGoal(sim) && ros::ok())
    {
        // 获取位置信息，发布位置，轨迹用于显示
        updateVisualization(sim);
        // 计算期望速度
        sim->computerVel();
        // 获取ORCA算法模拟器中的位置·和速度信息
        updateState(sim);
        // 10 HZ频率更新
        rate_sleep();
        ros::spinOnce();
    }
    delete sim;
    delete ugv;
    return 0;
}



void  GetIntialPosAndGoal(int i ){

    if(i == 0){
		init_pos.push_back(RVO::Vector2(10.0f,  10.0f));
		goals.push_back(RVO::Vector2(-10.0f, -10.0f));

		init_pos.push_back(RVO::Vector2(10.0f,  5.0f));
		goals.push_back(RVO::Vector2(-10.0f, -5.0f));

		init_pos.push_back(RVO::Vector2(10.0f,  0.0f));
		goals.push_back(RVO::Vector2(-10.0f, 0.0f));

		init_pos.push_back(RVO::Vector2(10.0f,  -5.0f));
		goals.push_back(RVO::Vector2(-10.0f, 5.0f));

		init_pos.push_back(RVO::Vector2(10.0f,  -10.0f));
		goals.push_back(RVO::Vector2(-10.0f, 10.0f));

		init_pos.push_back(RVO::Vector2(-10.0f,  -10.0f));
		goals.push_back(RVO::Vector2(10.0f, 10.0f));

		init_pos.push_back(RVO::Vector2(-10.0f,  -5.0f));
		goals.push_back(RVO::Vector2(10.0f, 5.0f));

		init_pos.push_back(RVO::Vector2(-10.0f,  0.0f));
		goals.push_back(RVO::Vector2(10.0f, 0.0f));

		init_pos.push_back(RVO::Vector2(-10.0f,  5.0f));
		goals.push_back(RVO::Vector2(10.0f, -5.0f));

		init_pos.push_back(RVO::Vector2(-10.0f,  10.0f));
		goals.push_back(RVO::Vector2(10.0f, -10.0f));
    }else if(i == 1)
	{
		init_pos.push_back(RVO::Vector2(-9.0f,  2.0f));
		goals.push_back(RVO::Vector2(9.0f, 2.0f));

		init_pos.push_back(RVO::Vector2(-9.0f,  1.0f));
		goals.push_back(RVO::Vector2(9.0f, 1.0f));

		init_pos.push_back(RVO::Vector2(-9.0f,  0.0f));
		goals.push_back(RVO::Vector2(9.0f, 0.0f));

		init_pos.push_back(RVO::Vector2(-9.0f,  -1.0f));
		goals.push_back(RVO::Vector2(9.0f, -1.0f));

		init_pos.push_back(RVO::Vector2(-9.0f,  -2.0f));
		goals.push_back(RVO::Vector2(9.0f, -2.0f));

		init_pos.push_back(RVO::Vector2(-10.0f,  2.0f));
		goals.push_back(RVO::Vector2(8.0f, 2.0f));

		init_pos.push_back(RVO::Vector2(-10.0f,  1.0f));
		goals.push_back(RVO::Vector2(8.0f, 1.0f));

		init_pos.push_back(RVO::Vector2(-10.0f,  0.0f));
		goals.push_back(RVO::Vector2(8.0f, 0.0f));

		init_pos.push_back(RVO::Vector2(-10.0f,  -1.0f));
		goals.push_back(RVO::Vector2(8.0f, -1.0f));

		init_pos.push_back(RVO::Vector2(-10.0f,  -2.0f));
		goals.push_back(RVO::Vector2(8.0f, -2.0f));
	}
    std::cout << init_pos.size() <<std::endl;

}


void setupScenario(RVO::RVOSimulator * sim, ros::NodeHandle &nh){
    // 获取初始位置 与目标位置
    GetIntialPosAndGoal(1);
/*
Specify the default paramters for agent that ars subsequently added 
参数 ：
 - neighborDist ,邻居区 ： 
   The maximum distance (center point to center point ) to  other agents
   the agent takes into account in the navigation
   The larger this number the longer the running time of the simulation
   if the number is too low ,the Simulation will no t be safe ,Must be non-negative

 - maxNeighbors  最大邻居:
	// maxNeighbors: The maximum number of other agents the agent takes into account in the navigation.
	// The larger this number, the longer the running time of the simulation. 
	//If the number is too low, the simulation will not be safe.
	

 - timeHorizon  时间地平线
 : The minimal amount of time for which the agent's velocities that are computed by the simulation 
	//are safe with respect to other agents. 
	//The larger this number, the sooner this agent will respond to the presence of other agents, 
	//but the less freedom the agent has in choosing its velocities. Must be positive.

 - radius 半径
    The radius of the agent. Must be non-negative.
 
 
 - maxSpeed  最大速度
 
 - velocity 速度 ： 


*/

// 设置算法参数
sim->setAgentDefaults(3.0f,10,2,2.0f,2.0f,0.5f,0.5f);
// 设置时间间隔
sim ->setTimeStep(time_step);
// Add Agent
for (int  i = 0; i < int_pos.size(); i++)
{
    sim->addAgent(int_pos[i]);
    ugv[i].init(nh,i+1,init_pos[i],time_step);
}

// Set Goals
for (int i = 0; i < sim -> getNumAgents(); ++i)
{
    sim -> setAgentGoal(i,goals[i]);
}

/*
 Add(polygonal ) obstacles , specifying their vertices in counterclockwise
order 
*/

// 逆时针

	obstacle1.push_back(RVO::Vector2(1.0f, 1.0f));
	obstacle1.push_back(RVO::Vector2(-1.0f, 1.0f));
	obstacle1.push_back(RVO::Vector2(-1.0f, 1.0f));
	obstacle1.push_back(RVO::Vector2(1.0f, -1.0f));

	obstacle2.push_back(RVO::Vector2(10.0f, 40.0f));
	obstacle2.push_back(RVO::Vector2(10.0f, 10.0f));
	obstacle2.push_back(RVO::Vector2(40.0f, 10.0f));
	obstacle2.push_back(RVO::Vector2(40.0f, 40.0f));

	obstacle3.push_back(RVO::Vector2(10.0f, -40.0f));
	obstacle3.push_back(RVO::Vector2(40.0f, -40.0f));
	obstacle3.push_back(RVO::Vector2(40.0f, -10.0f));
	obstacle3.push_back(RVO::Vector2(10.0f, -10.0f));

	obstacle4.push_back(RVO::Vector2(-10.0f, -40.0f));
	obstacle4.push_back(RVO::Vector2(-10.0f, -10.0f));
	obstacle4.push_back(RVO::Vector2(-40.0f, -10.0f));
	obstacle4.push_back(RVO::Vector2(-40.0f, -40.0f));

    sim->addObstacle(obstacle1);


    sim->processObstacles();

    std::cout << "setupScenario success!"<<std::endl;

}


void updateVisualiztion(RVO::RVOSimulator*sim){
    static int printf_num = 0;
    printf_num++;
    if(printf_num > 10)
    {
        // Output the current postition of all the agents
        for (size_t i = 0; i < count; i++)
        {
            nav_msgs::Odeometry odom;
            RVO::Vector2 pos = sim->getAgentPosition(i);

            odom.header.stamp = ros::Time::now();
            odom.header.frame_id = "world";
            odom.child_frame_id = "base_link";
		odom.pose.pose.position.x = pos.x();
		odom.pose.pose.position.y = pos.y();
		odom.pose.pose.position.z = 0.0;
		odom.pose.pose.orientation.x = 0.0;
		odom.pose.pose.orientation.y = 0.0;
		odom.pose.pose.orientation.z = 0.0;
		odom.pose.pose.orientation.w = 1.0;
		odom.twist.twist.linear.x = 0.0;
		odom.twist.twist.linear.y = 0.0;
		odom.twist.twist.linear.z = 0.0;

        odom_pub[i+1].publish(odom);

        // 发布无人机运动轨迹，用于rviz显示
        geometry_msgs::PoseStamped agent_pos;
        agent_pos.header.stamp = ros::Time::now();
		agent_pos.header.frame_id = "world";
		agent_pos.pose.position.x = pos.x();
		agent_pos.pose.position.y = pos.y();
		agent_pos.pose.position.z = 0.0;
		agent_pos.pose.orientation = odom.pose.pose.orientation;

		//发布无人机的位姿 和 轨迹 用作rviz中显示
		posehistory_vector_[i+1].insert(posehistory_vector_[i+1].begin(), agent_pos);
		if (posehistory_vector_[i+1].size() > TRA_WINDOW)
		{
			posehistory_vector_[i+1].pop_back();
		}

		nav_msgs::Path agent_trajectory;
		agent_trajectory.header.stamp = ros::Time::now();
		agent_trajectory.header.frame_id = "world";
		agent_trajectory.poses = posehistory_vector_[i+1];
		trajectory_pub[i+1].publish(agent_trajectory);
	}
    }
}


bool reachedGoal(RVO::RVOSimulator *sim)
{
	/* Check if all agents have reached their goals. */
	for (size_t i = 0; i < sim->getNumAgents(); ++i) {
		if (RVO::absSq(sim->getAgentPosition(i) - goals[i]) > 0.05f * 0.05f) {
			return false;
		}
	}

	std::cout << "Reach the Goal! " << std::endl;

	return true;
}