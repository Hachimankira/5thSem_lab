import cv2
import numpy as np
import matplotlib.pyplot as plt
import os

def extract_edges(image_path):
    original_image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)

    blurred_image = cv2.GaussianBlur(original_image, (5, 5), 0)

    edges = cv2.Canny(blurred_image, 50, 150)

    return original_image, edges

if __name__ == "__main__":
    image_path = 'boudh.jpg'
    output_folder = 'output_image'
    output_image_path = os.path.join(output_folder, '20.jpg')
    original, edges = extract_edges(image_path)

    plt.figure(figsize=(10, 5))

    plt.subplot(1, 2, 1)
    plt.imshow(original, cmap='gray')
    plt.title('Original Image')
    plt.axis('off')

    plt.subplot(1, 2, 2)
    plt.imshow(edges, cmap='gray')
    plt.title('Edges')
    plt.axis('off')

    plt.savefig(output_image_path, bbox_inches='tight')
    plt.show()
