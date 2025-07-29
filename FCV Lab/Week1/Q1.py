import cv2
 
img_grayscale = cv2.imread('img.webp',0)
 
cv2.imshow('graycsale image',img_grayscale)

cv2.waitKey(0)

cv2.destroyAllWindows()

cv2.imwrite('grayscale.jpg',img_grayscale)