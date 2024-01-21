import numpy as np
import cv2

# Read the image
image = cv2.imread('img1.jpg', cv2.IMREAD_GRAYSCALE)

# Apply log transformation
c = 1  # You can adjust this constant for scaling
log_transformed = c * np.log1p(image)

# Convert back to uint8 (if necessary)
log_transformed = np.uint8(log_transformed)

# Display the images
cv2.imshow('Original Image', image)
cv2.imshow('Log Transformed Image', log_transformed)
cv2.waitKey(0)
cv2.destroyAllWindows()
