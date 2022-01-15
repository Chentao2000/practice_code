## python 的异常处理
 捕捉异常可以使用try/except语句。
try/except语句用来检测try语句块中的错误，从而让except语句捕获异常信息并处理。
如果你不想在异常发生时结束你的程序，只需在try里捕获它。

语法：

以下为简单的try....except...else的语法：

try:
  <语句>        #运行别的代码
except <名字>：
  <语句>        #如果在try部份引发了'name'异常
except <名字>，<数据>:
  <语句>        #如果引发了'name'异常，获得附加的数据
else:
  <语句>        #如果没有异常发生


