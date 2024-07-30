import cv2
import os

image_path = 'rubina.jpg'
output_folder = 'output_image'
output_image_path = os.path.join(output_folder, '3a.jpg')

image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)

os.makedirs(output_folder, exist_ok=True)

output_image_path = os.path.join(output_folder, 'OutputImage.jpg')

threshold_value = 128  

ret, binary_image = cv2.threshold(image, threshold_value, 255, cv2.THRESH_BINARY)

binary_image = cv2.bitwise_not(binary_image)

cv2.imwrite('3.jpg', binary_image)

cv2.imshow('Binary Image', binary_image)
cv2.waitKey(0)
cv2.destroyAllWindows()
