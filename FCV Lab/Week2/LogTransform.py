import cv2
import numpy as np
import matplotlib.pyplot as plt
img=cv2.imread('img.webp',0)
c=255/(np.log(1+np.max(img)))
log_transformed=c*np.log(1+img)
log_transformed=np.array(log_transformed,dtype=np.uint8)
plt.imshow(log_transformed, cmap='gray')
plt.show()
