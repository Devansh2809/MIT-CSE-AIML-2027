import cv2
import numpy as np
image = cv2.imread('pic.jpg') 

box_filtered = cv2.boxFilter(image, ddepth=-1, ksize=(7, 7), normalize=True)

gaussian_filtered = cv2.GaussianBlur(image, ksize=(7, 7), sigmaX=0)


cv2.imshow('Original', image)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imshow('Box Filter', box_filtered)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imshow('Gaussian Filter', gaussian_filtered)
cv2.waitKey(0)
cv2.destroyAllWindows()
