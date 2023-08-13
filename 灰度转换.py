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
cv.destroyAllWindows()


#保存 我们采用chatgpt更改后的写法
import os
for num in range(1, 11):
    filename = 'gray_dzr' + str(num) + '.jpg'

    if os.path.exists(filename):
        print(f"File '{filename}' already exists.")
    else:
        cv.imwrite(filename, gray_img)
        print(f"Created file '{filename}'.")
        break
    if num >= 9:  # To limit the loop to 1-10
        break


