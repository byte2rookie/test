import cv2 as cv
img =cv.imread("C:/Users/REVOLUTION/Desktop/img_v2_0c68bede-3c04-499d-b12f-23ca5064581g.jpg")

#配置参数
x,y,w,h=450,450,350,300
#画一个框
cv.rectangle(img,(x-30,y,w+100,y+200),color=(0,0,255),thickness=5)
#画一个圆
cv.circle(img,center=(440+150,440+300),radius=250,color=(0,255,0),thickness=5)



#展示一次
cv.namedWindow('zzy',cv.WINDOW_NORMAL)
cv.resizeWindow('zzy',1000,1000)
cv.imshow('zzy',img)






#按Q退出
while True:
    if ord('q')==cv.waitKey(0):
        break
cv.destroyAllWindows()





#储存一下
import os
for num in range(1, 11):
    filename = 'circles' + str(num) + '.jpg'

    if os.path.exists(filename):
        print(f"File '{filename}' already exists.")
    else:
        cv.imwrite(filename, img)
        print(f"Created file '{filename}'.")
        break
    if num >= 9:  # To limit the loop to 1-10
        break
