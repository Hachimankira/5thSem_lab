import cv2
import numpy as np
import matplotlib.pyplot as plt
import os
def piecewise_linear_transform_color(img):
    
    lut_channels = [np.zeros(256, dtype=np.uint8) for _ in range(3)] 
    for i in range(3):
        
        lut_channels[i][:50] = np.linspace(0, 100, 50, endpoint=False, dtype=np.uint8)
        lut_channels[i][50:150] = np.linspace(100, 200, 100, endpoint=False, dtype=np.uint8)
        lut_channels[i][150:] = np.linspace(200, 255, 106, dtype=np.uint8)

    transformed_channels = [cv2.LUT(img[:, :, i], lut_channels[i]) for i in range(3)]
    transformed_img = np.stack(transformed_channels, axis=-1)

    return transformed_img

image_path = 'rubina.jpg'
output_folder = 'output_image'
original_img = cv2.imread(image_path)
output_image_path = os.path.join(output_folder, '8.jpg')


original_img_rgb = cv2.cvtColor(original_img, cv2.COLOR_BGR2RGB)


transformed_img = piecewise_linear_transform_color(original_img)


plt.subplot(121), plt.imshow(original_img_rgb), plt.title('Original Image')
plt.subplot(122), plt.imshow(transformed_img), plt.title('Transformed Image')
plt.savefig(output_image_path, bbox_inches='tight')
plt.show()

