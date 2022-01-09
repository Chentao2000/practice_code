# tello  使用 Python 控制
# 从这个官方代码来看 ，这开放了一个命令行接收和发送的 “字符”通信的API接口
# 这是设计的有够简单
# （看了一遍 做做笔记）
import threading
import socket
import sys
import time
import platform
# 模块 Platform  : 这个模块尝试尽可能多的 平台标识数据，它通过函数API来提供这些信息

host = ''
post = 9000
locaddr = (host,port)


# 创建 UDP 接收字 模块 sock
sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

tello_adress = ('192.168.10.1',8889)
sock.bind(locaddr)

def recv():
    count = 0
    while True:
        try:
            data,sever = sock.recvfrom(1518)
            print(data.decode(encoding= "utf-8")
        except Exception:
            print("\nExit...\n"))
            break

print ('\r\n\r\nTello Python3 Demo.\r\n')

print ('Tello: command takeoff land flip forward back left right \r\n       up down cw ccw speed speed?\r\n')

print ('end -- quit demo.\r\n')

# 这里还用了进程：
recvThread = threading.Thread(target=recv)
recvThread.start()


# 这里代码自动判断Python版本 ， 感觉很实用 可以记下来 
while True: 
    try:
        python_version = str(platform.python_version())
        version_init_num = int(python_version.partition('.')[0]) 
       # print (version_init_num)
        if version_init_num == 3:
            msg = input("");
        elif version_init_num == 2:
            msg = raw_input("");

                    if not msg:
            break  

        if 'end' in msg:
            print ('...')
            # 如果结束了 就打印....
            sock.close()  
            break

        # Send data
        msg = msg.encode(encoding="utf-8") 
        sent = sock.sendto(msg, tello_address)
    except KeyboardInterrupt:
        print ('\n . . .\n')
            # 发送完成 也打印....
        sock.close()  
        break
