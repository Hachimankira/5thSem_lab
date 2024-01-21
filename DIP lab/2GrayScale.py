import cv2

image_path = 'me.jpg'
image = cv2.imread(image_path)

gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

cv2.imwrite('gray_image.jpg', gray_image)

cv2.imshow('Gray Image', gray_image)

threshold_value = 70  

ret, binary_image = cv2.threshold(gray_image, threshold_value, 255, cv2.THRESH_BINARY)

cv2.imwrite('binary_image1.jpg', binary_image)

cv2.imshow('Binary Image', binary_image)
cv2.waitKey(0)
cv2.destroyAllWindows()

