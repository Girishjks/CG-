import cv2 
import numpy as np 
import matplotlib.pyplot as plt 

img = cv2.imread("rnsit.jpg", cv2.IMREAD_GRAYSCALE) 

gaussian_blur = cv2.GaussianBlur(img, (5, 5), 0) 

bilateral_blur = cv2.bilateralFilter(img, 9, 75, 75) 

plt.figure(figsize=(25, 10)) 
plt.subplot(1, 3, 1) 
plt.imshow(img, cmap='gray') 
plt.title("Original Grayscale Image") 
plt.axis("off") 

plt.subplot(1, 3, 2) 
plt.imshow(gaussian_blur, cmap='gray') 
plt.title("Blurred Image (Gaussian Blur)") 
plt.axis("off") 

plt.subplot(1, 3, 3) 
plt.imshow(bilateral_blur, cmap='gray') 
plt.title("Smoothened Image (Bilateral Filter)") 
plt.axis("off") 

plt.show()