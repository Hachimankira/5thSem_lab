import cv2
import numpy as np
import matplotlib.pyplot as plt
import os

def power_law_transform_color(img, gamma):
    
    transformed_channels = [np.power(img[:, :, i]/255.0, gamma) * 255.0 for i in range(3)] 
    transformed_img = np.stack(transformed_channels, axis=-1).astype(np.uint8)

    return transformed_img

image_path = 'rubina.jpg'
original_img = cv2.imread(image_path)
output_folder = 'output_image'
output_image_path = os.path.join(output_folder, '9.jpg')

original_img_rgb = cv2.cvtColor(original_img, cv2.COLOR_BGR2RGB)
gamma = 0.5
transformed_img = power_law_transform_color(original_img, gamma)

plt.subplot(121), plt.imshow(original_img_rgb), plt.title('Original Image')
plt.subplot(122), plt.imshow(transformed_img), plt.title('Transformed Image')
plt.savefig(output_image_path, bbox_inches='tight')
plt.show()
