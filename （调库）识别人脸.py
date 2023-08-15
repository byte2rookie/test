import cv2 as cv

#自定义一个人脸识别函数

def face_detect_cmd(img):
    #1：先将原图片灰度化以后再使用
    img_gray=cv.cvtColor(img,cv.COLOR_RGB2GRAY)
    cv.namedWindow('zzy', cv.WINDOW_NORMAL)
    cv.resizeWindow('zzy', 1000, 1000)
    cv.imshow('zzy', img_gray)
    cv.waitKey(0)
    #2:使用已经训练好的分类器(需要额外学习到底怎么制作的分类器)
    face_detect = cv.CascadeClassifier('D:/opencv/sources/data/haarcascades/haarcascade_frontalface_alt2.xml')
    #3：多次识别增加准确度
    face = face_detect.detectMultiScale(img_gray,1.01,10,0,(50,50),(900,900))
    #读取face参数
    for x, y, w, h in face:
        # 画框
        cv.rectangle(img, (x, y), (x + w, y + h), color=(0, 0, 255), thickness=6)
    cv.namedWindow('zzy', cv.WINDOW_NORMAL)
    cv.resizeWindow('zzy', 1000, 1000)
    cv.imshow('zzy', img)






#主函数

img =cv.imread("C:/Users/REVOLUTION/Desktop/img_v2_1ec6622f-7d98-4e12-8e54-30f4c0df11eg.jpg")
face_detect_cmd(img)

#按Q退出
while True:
    if ord('q')==cv.waitKey(0):
        break
cv.destroyAllWindows()





#储存一下
import os
for num in range(1, 11):
    filename = 'multi_faces' + str(num) + '.jpg'

    if os.path.exists(filename):
        print(f"File '{filename}' already exists.")
    else:
        cv.imwrite(filename, img)
        print(f"Created file '{filename}'.")
        break
    if num >= 9:  # To limit the loop to 1-10
        break