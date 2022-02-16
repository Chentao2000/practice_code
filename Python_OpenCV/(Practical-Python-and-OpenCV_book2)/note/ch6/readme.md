报错修改如下：

xxx.py 涉及到 joblib 直接改成 ：

import joblib # 因为 joblib 独立出来了



(cnts, _) = cv2.findContours(edged.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE) # 因为cv2.findContours 现在只会返回2个参数
