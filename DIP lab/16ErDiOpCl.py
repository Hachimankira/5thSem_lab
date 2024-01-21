import cv2
import numpy as np
import matplotlib.pyplot as plt
import os

img = cv2.imread('nature.jpg')

output_folder = 'output_image'
os.makedirs(output_folder, exist_ok=True)

output_image_path = os.path.join(output_folder, '16a.jpg')

# Kernel for dilation and erosion
kernel = np.ones((5, 5), np.uint8)

# Dilation
result_dilation = cv2.dilate(img, kernel, iterations=1)

# Erosion
result_erosion = cv2.erode(img, kernel, iterations=1)

# Opening (erosion followed by dilation)
result_opening = cv2.morphologyEx(img, cv2.MORPH_OPEN, kernel)

# Closing (dilation followed by erosion)
result_closing = cv2.morphologyEx(img, cv2.MORPH_CLOSE, kernel)

plt.figure(figsize=(10, 8))

plt.subplot(2, 3, 1)
plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
plt.title('Original Image')
plt.axis('off')

plt.subplot(2, 3, 2)
plt.imshow(cv2.cvtColor(result_dilation, cv2.COLOR_BGR2RGB))
plt.title('Dilation')
plt.axis('off')

plt.subplot(2, 3, 3)
plt.imshow(cv2.cvtColor(result_erosion, cv2.COLOR_BGR2RGB))
plt.title('Erosion')
plt.axis('off')

plt.subplot(2, 3, 4)
plt.imshow(cv2.cvtColor(result_opening, cv2.COLOR_BGR2RGB))
plt.title('Opening')
plt.axis('off')

plt.subplot(2, 3, 5)
plt.imshow(cv2.cvtColor(result_closing,cv2.COLOR_BGR2RGB))
plt.title('Closing')
plt.axis('off')

plt.savefig(output_image_path, bbox_inches='tight')
plt.show()
