# USAGE
# python cam.py --face cascades/haarcascade_frontalface_default.xml
# python cam.py --face cascades/haarcascade_frontalface_default.xml --video video/adrian_face.mov


# 嘤嘤嘤，从这节开始 即使我看的懂英文，我要写英文 为了学习英文  ,不只是简单照抄 ，起码过了两遍脑子了！
# import the necessary packages
from pyimagesearch.facedetector import FaceDetector
from pyimagesearch import imutils
import argparse
import cv2

ap =argparse.ArgumentParser()
ap.add_argument("-f" , "--face" , required= True, help= " path to where the face cascade resides")
ap.add_argument("-v" , "--video", help= " path to teh ( opntional video file )")
#不输入 video就会用默认摄像头 （机载摄像头）


args = vars(ap.parse_args())

# 构建人脸检测器

fd = FaceDetector(args["faces"])

# if a video path was not supplied,grat ,the reference
# to the gray
if not args.get(" video",False):
    camera = cv2.VideoCapture(0)

# 否则  otherwise , load the video
else : 
    camera = cv2.VideoCapture(args["video"])


    # keep looping

while True:
    # grab the current frame
    (grabbed , frame) = camera.read()

    # if we are viewing a video and we did not grab a frame
    # then we have reched the end of the video

    if args.get("video") and not grabbed:
        break

#  resize the frame and conveit it to grayscale 

    frame = imutils.resize(frame,width=300)
    gray = cv2.cvtColor(frame ,cv2.COLOR_BGR2GRAY)

    #dect faces in the image and then clone the frame
    # so that we can draw on it

    faceRect = fd.detect(gray,scaleFactor= 1.1, minNeighbors= 5, minSize= (30,30) ,frameClone = frame.copy())
    frameClone = frame.copy()

    # loop over the face bounding boxes and draw them
    for ( fX, fY , fW, fH) in faceRect:
        cv2.rectangle(frameClone , ( fX ,fY) , ( fX + fW , fY + fH) , (0,255,0) , 2)
        
    # show our detectd faces
        cv2.imshow("Face" , frameClone)
        if cv2.waitKey(1) & 0xFF == ord("q"):
            break

        # cleanup the camera and close any open windows
        camera.release()
        cv2.destroyAllWindows()
