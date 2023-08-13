import cv2 as cv

#自定义一个人脸识别函数

def face_detect_cmd(img):
    #1：先将原图片灰度化以后再使用
    img_gray=cv.cvtColor(img,cv.COLOR_RGB2GRAY)
    #2:使用已经训练好的分类器(需要额外学习到底怎么制作的分类器)
    face_detect = cv.CascadeClassifier('D:/opencv/sources/data/haarcascades/haarcascade_frontalface_alt2.xml')
    #3：多次识别增加准确度
    face = face_detect.detectMultiScale(img_gray,1.05,5,0,(50,50),(900,900))
    #读取face参数
    for x, y, w, h in face:
        # 画框
        cv.rectangle(img, (x, y), (x + w, y + h), color=(0, 0, 255), thickness=6)
    cv.imshow('zzy', img)

#摄像头打开
cam=cv.VideoCapture(0)
#视频识别
#cam=cv.VideoCapture("C:/Users/REVOLUTION/Desktop/成电飞书20230813-221115.mp4")
#进行人脸识别

while True:
    flag, frame = cam.read()
    if not flag:
        break
    face_detect_cmd(frame)
    if ord('q')==cv.waitKey(0):
        break



cv.destroyAllWindows()
cam.release()