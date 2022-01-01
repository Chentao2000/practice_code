
参考链接 ： https://blog.csdn.net/catherine627/article/details/83548063

gazebo 模型存放的位置： /home/usr_name/.gazebo/models.

我们建立我们的模型文件 

```yaml
mkdir ~/.gazebo/models/my_ground_plane
mkdir -p ~/.gazebo/models/my_ground_plane/materials/textures 
mkdir -p ~/.gazebo/models/my_ground_plane/materials/scripts
```

(参考链接中 mdkir 纯属卖坑 ，实际压根没有这个指令)

接下来创建第一个文件 my_ground_plane.material   (material 是材料用具的意思)

```yaml
cd ..  # 回到 materials 目录
cd scripts  #进入 scripts
touch my_ground_plane.material # 创建这个文件
gedit my_ground_plane.material  #编写
```
然后把这一段复制进去


```yaml
material MyGroundPlane/Image
#这个就是目录啦
        {
          technique  # 技巧
          {
            pass # 通过
            {
              ambient 1 1 1 1.000000  # 环境的
              diffuse 1 1 1 1.000000  # 弥漫的
              specular 0.03 0.03 0.03 1.000000 # 镜面反射的
 
              texture_unit #纹理单位
              {
                texture MyImage.png #  纹理
                # 疑问点 1. 在这两个地方放图片可不可以显示图片
              }
            }
          }
        }
```

3. 在textures文件夹下放想要贴的纹理图片，这里取名为MyImage.png

4. 回到my_ground_plane文件夹下，创建文件model.sdf，内容为

```yaml
<?xml version="1.0" encoding="UTF-8"?>
# UTF-8 万国码
<sdf version="1.4">
# sdf 版本
   <model name="my_ground_plane">
   # 模型的名字
      <static>true</static>
      <link name="link">
         <collision name="collision">
            <geometry>
               <plane>
                  <normal>0 0 1</normal>
                  <size>100 100</size>
               </plane>
            </geometry>
            <surface>
               <friction>
                  <ode>
                     <mu>100</mu>
                     <mu2>50</mu2>
                  </ode>
               </friction>
            </surface>
         </collision>
         <visual name="visual">
            <cast_shadows>false</cast_shadows>
            <geometry>
               <plane>
                  <normal>0 0 1</normal>
                  <size>100 100</size>
               </plane>
            </geometry>
            <material>
               <script>
                  <uri>model://my_ground_plane/materials/scripts</uri>
                  <uri>model://my_ground_plane/materials/textures/</uri>
                  # 模型存放的位置
                  <name>MyGroundPlane/Image</name>
                  # 图片存放的地方
               </script>
            </material>
         </visual>
      </link>
   </model>
</sdf>
```
在my_ground_plane文件夹下，创建文件model.config，内容如下：

```yaml
<?xml version="1.0" encoding="UTF-8"?>
<model>
   <name>My Ground Plane</name>
   <version>1.0</version>
   <sdf version="1.4">model.sdf</sdf>
   # 还是是加入模型
   <description>My textured ground plane.</description>
</model>
```


// --------------------------------------
扩展 ，增加 模型 ，选中 add ，选中gazebo_model 文件 ，你会发现一个宝藏
