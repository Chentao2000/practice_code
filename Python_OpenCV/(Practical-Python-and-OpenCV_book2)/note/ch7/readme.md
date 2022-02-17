执行代码 :

python classify.py --images dataset/images --masks dataset/masks

-----

## 报错1：

Traceback (most recent call last):
  File "classify.py", line 9, in <module>
    from sklearn.cross_validation import train_test_split
ImportError: No module named cross_validation

  
解决:
  
  
  from sklearn.cross_validation import train_test_split

然后报错：

No module named 'sklearn.cross_validation'

原因：

这个cross_validatio这个包早就不在使用了，划分到了model_selection这个包中。
解决方法：

from sklearn.model_selection import train_test_split

参考链接：https://blog.csdn.net/qq_35962520/article/details/85295228
  
  报错解决
  
  ----
  
