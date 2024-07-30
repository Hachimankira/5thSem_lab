import cv2
import matplotlib.pyplot as plt
import os

image_path = 'rubina.jpg'
output_folder = 'output_image'

image = cv2.imread(image_path)
output_image_path = os.path.join(output_folder, '7.jpg')
output_hist_path = os.path.join(output_folder, '7a.jpg')

if len(image.shape) == 3:
        image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

equalized_image = cv2.equalizeHist(image)

histogram = cv2.calcHist([image], [0], None, [256], [0, 256])

plt.plot(histogram, color='black')
plt.xlabel('Pixel Value')
plt.ylabel('Frequency')
plt.title('Image Histogram')
plt.savefig(output_hist_path)
plt.show()

plt.imshow(equalized_image, cmap='gray')
plt.title('Equalized Image')
plt.axis('off')
plt.savefig(output_image_path)
plt.show()


