import cv2
import matplotlib.pyplot as plt
import os

image_path = 'me.jpg'
output_folder = 'output_image'
output_image = os.path.join(output_folder, '5.jpg')

image = cv2.imread(image_path)

if len(image.shape) == 3:
    image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

histogram = cv2.calcHist([image], [0], None, [256], [0, 256])

plt.plot(histogram, color='black')
plt.xlabel('Pixel Value')
plt.ylabel('Frequency')
plt.title('Image Histogram')
plt.savefig(output_image)
plt.show()

cv2.waitKey(0)
cv2.destroyAllWindows()



