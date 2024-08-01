import cv2 
import numpy as np 
import matplotlib.pyplot as plt 

img = cv2.imread("rnsit.jpg") 

height, width = img.shape[:2]

quad1 = img[:height//2, :width//2] 
quad2 = img[:height//2, width//2:] 
quad3 = img[height//2:, :width//2] 
quad4 = img[height//2:, width//2:] 

plt.figure(figsize=(10, 5)) 
plt.subplot(1, 2, 1) 
plt.imshow(cv2.cvtColor(quad1, cv2.COLOR_BGR2RGB)) 
plt.title("1") 
plt.axis("off") 

plt.subplot(1, 2, 2) 
plt.imshow(cv2.cvtColor(quad2, cv2.COLOR_BGR2RGB))  
plt.title("2") 
plt.axis("off") 

plt.figure(figsize=(10, 5)) 
plt.subplot(1, 2, 1) 
plt.imshow(cv2.cvtColor(quad3, cv2.COLOR_BGR2RGB))  
plt.title("3") 
plt.axis("off") 

plt.subplot(1, 2, 2) 
plt.imshow(cv2.cvtColor(quad4, cv2.COLOR_BGR2RGB))  
plt.title("4") 
plt.axis("off") 

plt.show()