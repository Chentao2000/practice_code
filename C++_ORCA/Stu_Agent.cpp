#include "Agent.h"
#include "KdTree.h"
#include "Obstacle.h"

// 论文笔记 ： https://www.meltycriss.com/2017/01/14/paper-orca/
// 额 自动索引就出来了 难道就存在某个具体的目录下来吗？
namespace RVO
{
    Agent::Agent(RVOSimulator*sim):
    // C++ 中的冒号就好像 python中的 .    ？ 都是解引用用的？

    maxNeighbors_(0), maxSpeed_(0.0f), neighborDist_(0.0f), radius_(0.0f), 
    sim_(sim), timeHorizon_(0.0f), timeHorizonObst_(0.0f), id_(0) { }
	/*
	 * Set the preferred velocity to be a vector of unit magnitude (speed) in the
	 * direction of the goal.
    // 设置一个更好的速度 去达到速度的 直到（巨大的）速度 
        这个反向的目标**

    // 将首选速度设置为目标方向上单位大小（速度）的向量。
    - perferred  更喜欢的 ： 首选的 
    - velocity  速度  vector  矢量
    - magnitude  大小
	 */

            void Agent::computePrefVelocity()
            {
                RVO::Vector2 goalVector = goal_ - position_;

                // 距离大小1 ，则归一化
                if (RVO :: absSq(goalVector) > 1.0f)
                {
                    goalVector = RVO::normalize(goalVector);
                    
                    /*
                    normalize() 计算归一化函数 ：计算规范类 （什么是规范类？？）
                        二维向量的归一化  The normalization of the two-dimensional vector.
                        感觉归一化也是一个大学问呀 ： https://juejin.cn/post/6844903700549369864

                    */
                }
                prefVelocity_ = goalVector ;
                // 首选速度 =  目标速度


                /*
                * Perturb （扰动）a little to avoid deadlocks due to perfect symmetry.
                为了避免死锁， 加入一些小小的扰动
                */
                float angle = std::rand() * 2.0f *M_PI / RAND_MAX;
                float dist = std::rand()*0.0001f / RAND_MAX;
                // ** rand 应该是随机数吧 ，角度
                // std::cout << dist * RVO::Vector2(std::cos(angle), std::sin(angle)) << std::endl;
                prefVelocity_ = prefVelocity_ + dist * RVO::Vector2(std::cos(angle), std::sin(angle));
                // 加入扰动 = 第一速度 +  距离*目标速度*cos角度*sin角度...
                }


        void Agent::computeNeighbors(){
            // 计算邻居：
            obstacleNeighbors_.clear();
            // . clear () 清理数据??
		    float rangeSq = sqr(timeHorizonObst_*maxSpeed_ + radius_);
            // 根据距离rangeSq来索引邻居 如果存在
			// agent->insertAgentNeighbor(agents_[i], rangeSq);
		    sim_->kdTree_->computeObstacleNeighbors(this, rangeSq);
            agentNeighbors_.clear();

		if (maxNeighbors_ > 0) {
			rangeSq = sqr(neighborDist_);
			// 根据距离rangeSq来索引邻居，如果存在
			// agent->insertAgentNeighbor(agents_[i], rangeSq);
			sim_->kdTree_->computeAgentNeighbors(this, rangeSq);


        }
        }
        // 寻找一个最新的 速度

	void Agent::computeNewVelocity()
        {
            orcaLines_.clear();
            // .clear() : clear()函數用於刪除向量容器的所有元素，從而使其大小為0。
            const float invTimeHorizonObst = 1.0f/timeHorizonObst_;
            // 创建一个 ORCA 障碍线
            for (size_t i =0 ; i < obstacleNeighbors_.size(); i++){
			    const Obstacle *obstacle1 = obstacleNeighbors_[i].second;
			    const Obstacle *obstacle2 = obstacle1->nextObstacle_;

			const Vector2 relativePosition1 = obstacle1->point_ - position_;
			const Vector2 relativePosition2 = obstacle2->point_ - position_;

            }
			/*
			 * Check if velocity obstacle of obstacle is already taken care of by
			 * previously constructed obstacle ORCA lines.
			 */
            // 检测如果速度以及检测到 障碍物 已经被注意到
            //   constructed （构建）
            //   之前 构建好 ORCA 障碍物的线条

            bool alreadyCovered = false;

            for ( size_t j = 0 ; j <orcaLines_.size() ; ++j){
				if (det(invTimeHorizonObst * relativePosition1 -orcaLines_[j].point, 
                orcaLines_[j].direction) 
                 - invTimeHorizonObst * radius_ >= -RVO_EPSILON && det(invTimeHorizonObst * relativePosition2 - orcaLines_[j].point, orcaLines_[j].direction) - invTimeHorizonObst * radius_ >=  -RVO_EPSILON) {
					alreadyCovered = true;
                    break;
            }
        }
        if(alreadyCovered){
            continue;
        }

        // 尚未覆盖 ，检查有无被碰撞
        
			const float distSq1 = absSq(relativePosition1);
			const float distSq2 = absSq(relativePosition2);
            const float radiusSq = sqr(radius_);

			const Vector2 obstacleVector = obstacle2->point_ - obstacle1->point_;
            const float s  = (- relativePostition1 * obstacleVector)/ absSq(obstacleVector);
            const float distSqLinx = absSq(- relativePostiton1 - s* obstacleVector);
            // 不知道这段代码是在说啥......

            Line line;
            // 这是一个新的类
            if ( s < 0.0f && distSq1 <=  radiusSq){
                /* Collision with left vertex. Ignore if non-convex. */
                if ( obstacle1 -> isConvex_){
            line.point = Vector2(0.0f,0.0f);
			line.direction = normalize(Vector2(-relativePosition1.y(), relativePosition1.x()));
            orcaLines_.push_back(line);
            }
            continue;
            
            else if (s > 1.0f && distSq2 <= radiusSq){
				/* Collision with right vertex. Ignore if non-convex 
				 * or if it will be taken care of by neighoring obstace 
                 学英文了哈 ：
                 Collision : 碰撞    Vertex ： 顶点 角点 至高点  non-comvex 非高点
                 neigoring 临近的   obstacle 障碍物
                 */
                	if (obstacle2->isConvex_ && det(relativePosition2, obstacle2->unitDir_) >= 0.0f) {
					line.point = Vector2(0.0f, 0.0f);
					line.direction = normalize(Vector2(-relativePosition2.y(), relativePosition2.x()));
					orcaLines_.push_back(line);
            }
            continue ;
			else if (s >= 0.0f && s < 1.0f && distSqLine <= radiusSq) {
				/* Collision with obstacle segment. */
				line.point = Vector2(0.0f, 0.0f);
				line.direction = -obstacle1->unitDir_;
				orcaLines_.push_back(line);
				continue;
			}
            }


} // namespace RVO
