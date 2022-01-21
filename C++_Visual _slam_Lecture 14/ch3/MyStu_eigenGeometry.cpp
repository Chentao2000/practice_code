#include <iostream>
#include <cmath>
using namespace std;

#include <Eigen/Core>
// Eigen 几何模块
#include <Eigen/Geometry>

int main( int argc ,char ** argv)
{
    Eigen::Matrix3d rotation_matrix = Eigen::Matrix3d::Identity();
    // 3D旋转矩阵直接使用 Matrix3d 或者 Matrix3f
    Eigen::AngleAxisd rotation_vector ( M_PI/4, Eigen::Vector3d( 0,0,1) ) ; 
    //沿 Z 轴旋转了 45 度
    cout.precision(3);
    cout << " rotation matrix = \n" << rotation_vector.matrix() <<endl;
    // 用 matrix() 转换成矩阵
    
    // 也可以直接赋值
    rotation_matrix = rotation_vector.toRotationMatrix();

    //用AngleAxis 进行坐标变换
    Eigen::Vector3d v (1,0,0);
    Eigen::Vector3d  v_rotated = rotation_vector*v;
    cout   << " ( 1,0,0) after rotation = " << v_rotated.transpose()<<endl;

    // 或者用 旋转矩阵 
    v_rotated = rotation_matrix*v;
    cout  << "(1,0,0) after roattion =  " << v_rotated.transpose() << endl ;


// 欧拉角 ： 可以将旋转矩阵 直接转换成欧拉角:
Eigen::Vector3d euler_angles = rotation_matrix.eulerAngles(2,1,0 );
// ZYX 顺序 ，即 roll pitch yaw 顺序

cout <<" yaw pitch roll " << euler_angles.transpose()<<endl;

// 欧式变换矩阵 使用 Eigen :: Isometry
    Eigen::Isometry3d T=Eigen::Isometry3d::Identity();                // 虽然称为3d，实质上是4＊4的矩阵
    T.rotate ( rotation_vector );                                     // 按照rotation_vector进行旋转
    T.pretranslate(Eigen::Vector3d(1  , 3,  4));

    cout << "Transform matrix = \n" <<  T.matrix()  <<  endl;

    // 用变换矩阵 进行坐标变换:
    Eigen::Vector3d  v_transformed  = T *v ; // 相当于 R*v + t
    cout << "v  tranformed   " << v_transformed.transpose() <<endl;

    // 对于仿射 和 射影变换 ，使用 Eigen:: Affine3d 和 Eigen:: Projective 3d 即可  

    // 四元数：
    Eigen::Quaterniond q  = Eigen::Quaterniond(rotation_vector);
    cout << " quaternion = \n" << q.coeffs() <<endl;
    // 请注意 coffes  = 系数 的顺序 是 （x，y，z, w） w 为实部， 前三者为虚部

    // 也可以把旋转矩阵赋给它：
    q = Eigen::Quaterniond(rotation_matrix);
    cout << "quaternion " << q.coeffs() <<endl;
    // 使用四元数旋转一个向量 ，使用重载方法即可 
    v_rotated = q*v; // 注意数学上是qvq^{-1}
    cout << "(1,0,0) after rotation = " << v_rotated.transpose()<<endl;
    return 0 ;







}
