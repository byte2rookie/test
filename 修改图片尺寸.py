#调用包
import cv2 as cv
#读取图片+灰度处理
gray_img=cv.imread("C:/Users/REVOLUTION/Desktop/20230723-214341.jpg")
gray_img=cv.cvtColor(gray_img,cv.COLOR_RGB2GRAY)
#修改尺寸
gray_img_cut=cv.resize(gray_img,dsize=(500,500))

#查看一下原图片
cv.namedWindow('gray_dzr_cut', cv.WINDOW_NORMAL)
cv.resizeWindow('gray_dzr_cut', 700, 700)
cv.namedWindow('gray_dzr', cv.WINDOW_NORMAL)
cv.resizeWindow('gray_dzr', 700, 700)
cv.imshow('gray_dzr',gray_img)
cv.imshow('gray_dzr_cut',gray_img_cut)

#打印尺寸
print(f"原尺寸为：{gray_img.shape}")
print(f"现尺寸为：{gray_img_cut.shape}")

#按q退出
while True:
    if ord('q') == cv.waitKey(0):
        break

cv.destroyAllWindows()

#储存cut后的图片
import os
for num in range(1, 11):
    filename = 'gray_dzr_cut' + str(num) + '.jpg'

    if os.path.exists(filename):
        print(f"File '{filename}' already exists.")
    else:
        cv.imwrite(filename, gray_img_cut)
        print(f"Created file '{filename}'.")
        break
    if num >= 9:  # To limit the loop to 1-10
        break