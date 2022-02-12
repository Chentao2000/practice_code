DenseDepth : https://github.com/ialhashim/DenseDepth

## INSTALL:

---

install：NVIDIA devices 

```
ubuntu-drivers devices   # 查询所有ubuntu推荐的驱动

sudo ubuntu-drivers autoinstall
```

 others：
 
https://blog.csdn.net/new_delete_/article/details/81544438?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164448163616780265424387%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164448163616780265424387&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~hot_rank-2-81544438.first_rank_v2_pc_rank_v29&utm_term=nvidia%E9%A9%B1%E5%8A%A8%E5%AE%89%E8%A3%85&spm=1018.2226.3001.4187

--- 
Traceback (most recent call last):
  File "test.py", line 8, in <module>
    from keras.models import load_model
ImportError: No module named keras.models

 pip3 install opencv-python
 pip3 install --upgrade h5py
 pip3 install keras==2.2.5
 pip3 install tensorflow==1.14.0
 
---
 
 Traceback (most recent call last):
  File "test.py", line 4, in <module>
    import matplotlib
ModuleNotFoundError: No module named 'matplotlib'

pip3 install matplotlib
 
 ----
 
       File "<string>", line 1, in <module>
      File "/tmp/pip-build-a_5k7i47/opencv-python/setup.py", line 10, in <module>
        import skbuild
    ModuleNotFoundError: No module named 'skbuild'
    
pip3 install scikit-build

 
 ----
 
    from tensorflow.python.eager.context import get_config
ImportError: cannot import name 'get_config'
 
 keras tensorflow
 
![图片](https://user-images.githubusercontent.com/68007558/153374359-de4cf57c-34a0-4e89-bca5-c239f1725ea5.png)

 
 ----
 
 /home/yuki/.local/lib/python3.6/site-packages/tensorflow/python/framework/dtypes.py:532: FutureWarning: Passing (type, 1) or '1type' as a synonym of type is deprecated; in a future version of numpy, it will be understood as (type, (1,)) / '(1,)type'.
  np_resource = np.dtype([("resource", np.ubyte, 1)])

 
 
 pip3 install -U numpy==1.16.4

 ----
 pip安装opencv时卡住：Running setup.py bdist_wheel for opencv-python … /
 
 
 pip update ！
 
 -------
 import skimage.transform ImportError: No module named 'skimage'
 
 pip3 install scikit-image
 
 -----
     from PySide2 import QtCore, QtGui, QtWidgets, QtOpenGL
ModuleNotFoundError: No module named 'PySide2'
 
 pip3 install pyside2
 
------
    return original_import(name, *args, **kwargs)
ModuleNotFoundError: No module named 'OpenGL'

pip3 install pyOpenGL

-------

ensupport/__feature__.py", line 142, in _import
    return original_import(name, *args, **kwargs)
ModuleNotFoundError: No module named 'glm'

 pip3 install PyGLM
------
 qt.qpa.plugin: Could not load the Qt platform plugin "xcb" in "/home/sysu/.local/lib/python3.6/site-packages/cv2/qt/plugins" even though it was found.
This application failed to start because no Qt platform plugin could be initialized. Reinstalling the application may fix this problem.

Available platform plugins are: xcb, eglfs, linuxfb, minimal, minimalegl, offscreen, vnc, wayland-egl, wayland, wayland-xcomposite-egl, wayland-xcomposite-glx, webgl.


 
 sudo pip3 install pyqt5==5.12.0

----- 
 
## Bug

AttributeError: module 'glm' has no attribute 'vec3':

https://log-mylife.tistory.com/entry/AttributeError-module-glm-has-no-attribute-vec3-%EC%97%90%EB%9F%AC-%ED%95%B4%EA%B2%B0

--- 
