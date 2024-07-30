import cv2
import numpy as np
import os

img=cv2.imread('rubina.jpg')
c=(255/np.log(1+np.max(img)))
log_time_img = c*np.log(1+img)
log_time_img=np.array(log_time_img, dtype=np.uint8)
cv2.imshow('OutputImage.jpg', log_time_img)

output_folder = 'output_image'

output_image_path = os.path.join(output_folder, '10.jpg')

cv2.imwrite(output_image_path, log_time_img)
            
cv2.waitKey(0)
cv2.destroyAllWindows()