#调用包
import cv2 as cv
#读取图片
gray_img=cv.imread("C:/Users/REVOLUTION/Desktop/20230723-214341.jpg")
gray_img=cv.cvtColor(gray_img,cv.COLOR_RGB2GRAY)
#查看一下
cv.namedWindow('gray_dzr', cv.WINDOW_NORMAL)
cv.resizeWindow('gray_dzr', 600, 500)
cv.imshow('gray_dzr',gray_img)
cv.waitKey(0)
cv.destroyWindow('gray_dzr')
#保存
for num in range(1,10):
    filename ='gray_dzr'+str(num)+'.jpg'
    file_exist=open(filename,mode='r')
    if not file_exist:
        cv.imwrite(filename,gray_img)
        file_exist.close()
    num += 1
    break
else:
        print(str(filename))

