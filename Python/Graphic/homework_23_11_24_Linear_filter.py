from PIL import Image
from tkinter import filedialog
import numpy as np
from scipy.signal import convolve2d
import matplotlib.pyplot as plt

def custom_linear_filter(image, kernel):
    result = convolve2d(image, kernel, mode='same', boundary='symm')
    return result

if __name__ == "__main__":
    input_image_path = filedialog.askopenfilename()
    output_image_path = "output_image.jpg"

    # Example coefficients for a more complex filter
    filter_coefficients = [
        0, 0, 0,
        0, -1, 0,
        0, 0, 0
    ]

    # Check if the sum of coefficients is zero
    sum_of_coefficients = sum(filter_coefficients)

    # Open the input image
    input_image = Image.open(input_image_path).convert("RGB")  # Force reading as color image

    # Convert image to numpy array
    input_array = np.array(input_image.convert("L"), dtype=np.uint8)  # Convert to grayscale and set data type

    if sum_of_coefficients != 0:
    # Normalize the coefficients
        filter_coefficients = np.array(filter_coefficients) / sum_of_coefficients

    # Apply the custom filter to the image
    filtered_array = custom_linear_filter(input_array, np.reshape(filter_coefficients, (3, 3)))

    # Convert back to PIL Image
    filtered_image = Image.fromarray(filtered_array.astype(np.uint8)).convert("L")

    # Display and save the result
    plt.figure(figsize=(10, 5))

    plt.subplot(1, 2, 1)
    plt.imshow(input_image)
    plt.title('Original Image')

    plt.subplot(1, 2, 2)
    plt.imshow(filtered_array, cmap='gray')
    plt.title('Filtered Image')

    plt.show()

    filtered_image.save(output_image_path)