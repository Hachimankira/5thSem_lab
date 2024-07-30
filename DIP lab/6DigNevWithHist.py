import cv2
import os
import matplotlib.pyplot as plt

image_path = 'rubina.jpg'
output_folder = 'output_image'
output_image_path = os.path.join(output_folder, '6.jpg')
image = cv2.imread(image_path)

negative_image = 255 - image

histogram = cv2.calcHist([image], [0], None, [256], [0, 256])

plt.figure(figsize=(12, 10))
plt.subplot(2, 1, 1)
plt.imshow(cv2.cvtColor(negative_image, cv2.COLOR_BGR2RGB))
plt.title('Negative Image')

plt.subplot(2, 1, 2)
histogram = cv2.calcHist([image], [0], None, [256], [0, 256])
plt.plot(histogram, color='black')
plt.xlabel('Pixel Value')
plt.ylabel('Frequency')
plt.title('Image Histogram')

plt.savefig(output_image_path)

cv2.waitKey(0)
cv2.destroyAllWindows()