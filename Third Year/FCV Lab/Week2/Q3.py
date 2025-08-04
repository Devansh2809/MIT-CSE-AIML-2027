import cv2
import numpy as np

image = cv2.imread('HighRes.jpg')
cv2.imshow('Original Image', image)
cv2.waitKey(0)
cv2.destroyAllWindows()

down_width = 300
down_height = 200
down_points = (down_width, down_height)
resized_down = cv2.resize(image, down_points, interpolation=cv2.INTER_LINEAR)

up_width = 600
up_height = 400
up_points = (up_width, up_height)
resized_up = cv2.resize(image, up_points, interpolation=cv2.INTER_LINEAR)

x_start, y_start = 100, 50
x_end, y_end = 400, 250
cropped = image[y_start:y_end, x_start:x_end]

cv2.imshow('Resized Down ', resized_down)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imshow('Resized Up', resized_up)
cv2.waitKey(0)
cv2.destroyAllWindows()
cv2.imshow('Cropped Image', cropped)
cv2.waitKey(0)
cv2.destroyAllWindows()
