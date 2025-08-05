import cv2
import numpy as np

def unsharp_mask(image, sigma=1.0, strength=1.5):
    blurred = cv2.GaussianBlur(image, (0, 0), sigma)
    sharpened = cv2.addWeighted(image, 1.0 + strength, blurred, -strength, 0)
    return sharpened

image = cv2.imread('HighRes.jpg')
sharpened_image = unsharp_mask(image)

cv2.imshow('sharpened_image.jpg', sharpened_image)
cv2.waitKey(0)
cv2.destroyAllWindows()





















'''import cv2
import numpy as np

def gaussian_kernel(size, sigma=1):
    ax = np.arange(-size // 2 + 1., size // 2 + 1.)
    xx, yy = np.meshgrid(ax, ax)
    kernel = np.exp(-(xx**2 + yy**2) / (2. * sigma**2))
    kernel = kernel / np.sum(kernel)
    return kernel

def convolve2d(image, kernel):
    if image.ndim == 2:
        return convolve_channel(image, kernel)
    elif image.ndim == 3:
        channels = []
        for d in range(image.shape[2]):
            channels.append(convolve_channel(image[:, :, d], kernel))
        return np.stack(channels, axis=2)
    else:
        raise ValueError("Unsupported image dimensions")

def convolve_channel(channel, kernel):
    k_h, k_w = kernel.shape
    pad_h = k_h // 2
    pad_w = k_w // 2
    padded = np.pad(channel, ((pad_h, pad_h), (pad_w, pad_w)), mode='reflect')
    output = np.zeros_like(channel)

    for i in range(output.shape[0]):
        for j in range(output.shape[1]):
            region = padded[i:i+k_h, j:j+k_w]
            output[i, j] = np.sum(region * kernel)
    return output

def unsharp_mask(image, sigma=1.0, strength=1.3):

    kernel_size = int(6 * sigma + 1)  
    if kernel_size % 2 == 0:
        kernel_size += 1
    kernel = gaussian_kernel(kernel_size, sigma)

    blurred = convolve2d(image, kernel)

    sharpened = (1.0 + strength) * image.astype(np.float32) - strength * blurred.astype(np.float32)


    sharpened = np.clip(sharpened, 0, 255).astype(np.uint8)

    return sharpened

image = cv2.imread('pic.jpg')

sharpened_image = unsharp_mask(image, sigma=1.0, strength=1.3)

cv2.imshow('Sharpened Image', sharpened_image)
cv2.waitKey(0)
cv2.destroyAllWindows()'''