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
 
 
    from tensorflow.python.eager.context import get_config
ImportError: cannot import name 'get_config'
 
 keras tensorflow
 
![图片](https://user-images.githubusercontent.com/68007558/153374359-de4cf57c-34a0-4e89-bca5-c239f1725ea5.png)

 
 ----
 
 
 
 ----
## Bug

AttributeError: module 'glm' has no attribute 'vec3':

https://log-mylife.tistory.com/entry/AttributeError-module-glm-has-no-attribute-vec3-%EC%97%90%EB%9F%AC-%ED%95%B4%EA%B2%B0

--- 
