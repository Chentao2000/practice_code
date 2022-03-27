原文链接 ： https://mp.weixin.qq.com/s/iQHoVpssi7yJM_e-C631MQ


什么是串级PID?

- 串级PID ，就是两个 串起来的PID 
- 外环是位置环， 内环是速度焕，最终的执行器是电机: 电机输出了速度和位置

![271f35230202683bfdb6b948d4946cac](https://user-images.githubusercontent.com/68007558/160285254-e01cb4f9-a5c2-4c4f-bc6e-5a880cf18a69.jpg)

执行器也可以是 四轴飞行器，整体过程如下：
- 外环给定相应的位置高度，外环PID输出 就是 内环 PID 的期望值
- 内环PID 输出将产生相应的油门大小，最终飞行器上升的速度
- 内环反馈至是速度 ，控制相应的速度达到外环所需的速度期望值
- 最终外环到达期望的位置

（PID 的算法控制其实是一种无系统模型的控制，可以根据参数经验经验去调试系统，但是实际的物理对象的模型早就确定好了）
PID 的输入量 和输出量 的物理意义也会因为实际的被控对象而改变


.....




单 PID 的输出 作为内环PID 的输入，下面是 单环PID的伪算法：
```c
previous_error := 0 //上一次的偏差
integral := 0 // 积分和
// 循环
// 采样周期 为 dt
loop:
  // setpoint 设定值
  // measured_value 反馈值
      error := setpoint - measured_value // 计算得到偏差
      integral := integral + error X dt // 计算得到积分累加和
      derivative := (error - previous_error) / dt //计算得到微分
      output := kp x error + ki x integral + kd x derivative // 计算PID输出
      previous_error := error //保存当前偏差为下一次采用，时间
      wait(dt) // 等待下一次采用
      goto loop
```
串级PID 需要的操作：
```c
previous_error := 0 // 上一次偏差
integral := 0 // 积分和

previous_error_inner := 0 // 内环 PID 上一次的偏差
integral_inner := 0 // 内环PID 积分和

// 循环
// 采用周期 dt
loop : 
      // 外环计算
      // setpoint 外环设定值
      // emeaured_value 外环反馈值
          error := setpoint - measured_value // 计算得到偏差
          integral := integral + error x dt // 计算得到积分累加和
          derivative := (error - previous_error)/ (n *dt) // 计算得到微分
          output := kp x error + ki x integral + kd x derivative //计算得到PID输出
          previous_error := error //保存当前偏差为下一次采用所需要的历史偏差
          
          
          setpoint_inner = output // 外环PID输出赋值给内环PID输入
          wait(n*dt)                  //等待下一次采用
            
          loop_inner :
          // setpoint_inee 内环设定值
          // measured_value_inner 内环反馈值
                  error_inner := stepoint_inner - measured_value_inner // 计算得到偏差
                  integral_inner := integral_inner  + error_inner x dt // 计算积分累加和
                  derivative_inner := (error_inner - previous_error_inner)/dt //计算得到的微分
                  
                  // 计算得到PID 输出
                  output_inner := Kp_inner x error +Ki_inner x interal_inner  + Kd x derivative_inner
                  previous_error_inner := error_inner //保存当前偏差为下一所需要的历史偏差
                  wait(dt) // 等待下一次采样
                  goto loop_inner
          
          
          
          
          
          

```
