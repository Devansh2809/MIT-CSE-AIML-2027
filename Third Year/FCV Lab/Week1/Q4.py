# Python program to explain cv2.rectangle() method 
 
# importing cv2 
import cv2 
import numpy as np
img = np.zeros((200, 200, 3), np.uint8)

cv2.rectangle(img, (50, 50), (150, 150), (0, 0, 255), 1)


cv2.imshow('image', img)
cv2.waitKey(0)
cv2.destroyAllWindows()