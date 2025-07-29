import cv2
src = cv2.imread('img.webp')
rotated = cv2.rotate(src, cv2.ROTATE_180)

cv2.imshow("180 Clockwise", rotated)
cv2.waitKey(0)
cv2.destroyAllWindows()