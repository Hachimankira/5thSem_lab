import cv2
import numpy as np

def encode_rle(image):
    """Encodes a color image using Run Length Encoding for each channel."""
    encoded_data = []

    for channel in range(image.shape[2]):  # Iterate over color channels
        prev_pixel = None
        run_length = 0

        for row in image[:, :, channel]:
            for pixel in row:
                if pixel == prev_pixel:
                    run_length += 1
                else:
                    if prev_pixel is not None:
                        encoded_data.append((prev_pixel, run_length))
                    prev_pixel = pixel
                    run_length = 1

        # Add the last run
        if prev_pixel is not None:
            encoded_data.append((prev_pixel, run_length))

    return encoded_data

def decode_rle(encoded_data, image_shape):
    """Decodes a Run Length Encoded color image."""
    decoded_image = np.zeros(image_shape, dtype=np.uint8)
    index = 0

    for channel in range(decoded_image.shape[2]):  # Iterate over color channels
        for pixel, run_length in encoded_data[channel::decoded_image.shape[2]]:
            decoded_image[:, :, channel][index:index + run_length] = pixel
            index += run_length

    return decoded_image

# Example usage:
img = cv2.imread("rlc.png")  # Load as color image
encoded_img = encode_rle(img)
decoded_img = decode_rle(encoded_img, img.shape)

cv2.imshow("Original Image", img)
cv2.imshow("Decoded Image", decoded_img)
cv2.waitKey(0)
