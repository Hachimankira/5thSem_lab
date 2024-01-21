import cv2
import os

image_path = 'me.jpg'
output_folder = 'output_image'

image = cv2.imread(image_path)

os.makedirs(output_folder, exist_ok=True)

output_image_path = os.path.join(output_folder, 'saved_me.jpg')

cv2.imwrite(output_image_path, image)

cv2.imshow('Image', image)
cv2.waitKey(0)  
cv2.destroyAllWindows()  

print(f"Image saved to: {output_image_path}")
