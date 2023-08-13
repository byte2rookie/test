import cv2 as cv

cam=cv.VideoCapture(0)
num=1
while(cam.isOpened()):
    #读取该帧的影像
    ret,pic = cam.read()
    if ret != True:
        print("ERROR!")
    cv.imshow('camera',pic)
    k=cv.waitKey(1)&0xFF
    if k == ord('s'):
        name="pic_pers"+str(num)+".jpg"
        cv.imwrite(name,pic)
        num+=1
        print(f"pic{num} has saved!\n")
        print("-----------------------\n")
    elif k ==ord(' '):
        break
cv.destroyAllWindows()
cam.release()
