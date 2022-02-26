   Yolov3 install blog:
      
    https://blog.csdn.net/debjiu/article/details/80824439?spm=1001.2014.3001.5502
  
    https://pjreddie.com/darknet/yolo/

Debug:


1.  yolo: Demo needs OpenCV for webcam images:

https://blog.csdn.net/lucky404/article/details/88292577



--------------------------
可能是内存的原因，跑YOLO 能出来检测目标结果 ，但是弹不出图片框 和 视频框 
- 但是 跑 Tiny 是成功的 ，但是帧率好低呀 才1.0左右
- 这个提供跑 Tiny 的 两个demo 执行代码表示

摄像头
```
./darknet detector demo cfg/coco.data cfg/yolov3-tiny.cfg yolov3-tiny.weights
```

图片
```
./darknet detect cfg/yolov3.cfg yolov3.weights data/dog.jpg
```

