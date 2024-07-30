import cv2
import numpy as np
import matplotlib.pyplot as plt
import os

img = cv2.imread('boudh.jpg')

output_folder = 'output_image'
os.makedirs(output_folder, exist_ok=True)

output_image_path = os.path.join(output_folder, 'output_image.jpg')

# Gaussian Blur
output_gaus = cv2.GaussianBlur(img, (5, 5), 0)

# Median Blur (reduction of noise)
output_med = cv2.medianBlur(img, 5)

# Min Blur
kernel_min = np.ones((5, 5), np.uint8)
output_min = cv2.erode(img, kernel_min, iterations=1)

# Max Blur
kernel_max = np.ones((5, 5), np.uint8)
output_max = cv2.dilate(img, kernel_max, iterations=1)

# Weighted Average Filtering
kernel_weighted_average = np.array([[1, 2, 1],
                                    [2, 4, 2],
                                    [1, 2, 1]]) / 16.0  # Normalize the kernel
output_weighted_average = cv2.filter2D(img, -1, kernel_weighted_average)

plt.figure(figsize=(12, 10))

plt.subplot(2, 3, 1)
plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
plt.title('Normal Image')
plt.axis('off')


plt.subplot(2, 3, 2)
plt.imshow(cv2.cvtColor(output_med, cv2.COLOR_BGR2RGB))
plt.title('Median Blur')
plt.axis('off')

plt.subplot(2, 3, 3)
plt.imshow(cv2.cvtColor(output_min, cv2.COLOR_BGR2RGB))
plt.title('Min Blur (Erosion)')
plt.axis('off')

plt.subplot(2, 3, 4)
plt.imshow(cv2.cvtColor(output_max, cv2.COLOR_BGR2RGB))
plt.title('Max Blur (Dilation)')
plt.axis('off')

plt.subplot(2, 3, 5)
plt.imshow(cv2.cvtColor(output_weighted_average, cv2.COLOR_BGR2RGB))
plt.title('Weighted Average Filtering')
plt.axis('off')

plt.subplot(2, 3, 6)
plt.imshow(cv2.cvtColor(output_gaus, cv2.COLOR_BGR2RGB))
plt.title('Gaussian Blur')
plt.axis('off')

plt.savefig(output_image_path, bbox_inches='tight')
plt.show()

cv2.waitKey(0)
cv2.destroyAllWindows()
