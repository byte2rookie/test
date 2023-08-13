#调用cv包
import cv2 as cv

#存放图片
img=cv.imread("C:/Users/REVOLUTION\Desktop/20230723-214341.jpg")

cv.namedWindow('dzr',cv.WINDOW_NORMAL)
cv.resizeWindow('dzr',780,560)
#展示图片
cv.imshow('dzr', img)
#延时函数（展示时间）
cv.waitKey(0)
#关闭
cv.destroyAllWindows()

