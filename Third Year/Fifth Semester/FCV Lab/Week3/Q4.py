import cv2
import numpy as np

image = cv2.imread('pj.jpg', cv2.IMREAD_GRAYSCALE)  

sobel_x = cv2.Sobel(image, cv2.CV_64F, 1, 0, ksize=3)
sobel_y = cv2.Sobel(image, cv2.CV_64F, 0, 1, ksize=3)

sobel_mag = cv2.magnitude(sobel_x, sobel_y)
sobel_mag = cv2.convertScaleAbs(sobel_mag)  

laplacian = cv2.Laplacian(image, cv2.CV_64F)
laplacian = cv2.convertScaleAbs(laplacian)

cv2.imshow('Original Image', image)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imshow('Sobel Edge Detection', sobel_mag)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imshow('Laplacian Edge Detection', laplacian)
cv2.waitKey(0)
cv2.destroyAllWindows()
