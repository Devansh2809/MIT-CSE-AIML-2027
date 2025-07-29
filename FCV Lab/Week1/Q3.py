import cv2
img = cv2.imread('img.webp',1)
pixel_bgr = img[100, 51]
blue_value = pixel_bgr[0]
green_value = pixel_bgr[1]
red_value = pixel_bgr[2]
print(f"BGR values of pixel (51, 100): Blue={blue_value}, Green={green_value}, Red={red_value}")

