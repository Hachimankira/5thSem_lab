import cv2
import os

image_path = 'me.jpg'
output_folder = 'output_image'

image = cv2.imread(image_path)
os.makedirs(output_folder, exist_ok=True)
output_image_path = os.path.join(output_folder, '4.jpg')
negative_image = 255 - image
cv2.imwrite(output_image_path,negative_image )
cv2.imshow('Image', negative_image)
cv2.waitKey(0)
cv2.destroyAllWindows()

