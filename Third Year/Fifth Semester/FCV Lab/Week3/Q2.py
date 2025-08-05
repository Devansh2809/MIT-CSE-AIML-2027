import cv2
import numpy as np

img = cv2.imread('HighRes.jpg', cv2.IMREAD_GRAYSCALE)

sobelx = cv2.Sobel(img, cv2.CV_64F, 1, 0, ksize=3)
sobely = cv2.Sobel(img, cv2.CV_64F, 0, 1, ksize=3)

gradient_mag = cv2.magnitude(sobelx, sobely)

gradient_mag = cv2.normalize(gradient_mag, None, 0, 255, cv2.NORM_MINMAX)
gradient_mag = np.uint8(gradient_mag)

cv2.imshow('Original Image', img)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imshow('Gradient Magnitude', gradient_mag)
cv2.waitKey(0)
cv2.destroyAllWindows()
