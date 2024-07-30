import cv2

# Read an image from file
image_path = "rubina.jpg"  # Replace with the actual path to your image
image = cv2.imread(image_path)

# Check if the image is loaded successfully
if image is not None:
    # Resize the image to a smaller size (e.g., half the original size)
    scale_percent = 20  # Adjust the scale factor as needed
    width = int(image.shape[1] * scale_percent / 100)
    height = int(image.shape[0] * scale_percent / 100)
    resized_image = cv2.resize(image, (width, height))

    # Display the resized image
    cv2.imshow("Resized Image", resized_image)
    cv2.waitKey(0)  # Wait for any key press
    cv2.destroyAllWindows()  # Close the displayed window

    # Save the resized image with a new name
    save_path = "path/to/your/saved/resized_image.jpg"  # Replace with the desired save path and filename
    cv2.imwrite(save_path, resized_image)
    print(f"Resized image saved successfully at: {save_path}")
else:
    print(f"Error: Unable to load the image from {image_path}")
