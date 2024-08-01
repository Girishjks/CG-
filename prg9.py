import cv2 
import numpy as np 
import matplotlib.pyplot as plt 


image_path = "logo.jpeg" 
img = cv2.imread(image_path) 

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY) 

edges = cv2.Canny(gray, 100, 200) 

kernel = np.ones((5, 5), np.float32) / 25  
texture = cv2.filter2D(gray, -1, kernel)  

plt.figure(figsize=(10, 5)) 
plt.subplot(1, 3, 1) 
plt.title("Original Image") 
plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB)) 
plt.axis('off') 

plt.subplot(1, 3, 2) 
plt.title("Edges") 
plt.imshow(edges, cmap='gray') 
plt.axis('off') 

plt.subplot(1, 3, 3) 
plt.title("Texture") 
plt.imshow(texture, cmap='gray') 
plt.axis('off')

plt.show() 