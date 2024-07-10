from PIL import Image
from tkinter import filedialog


def histogram_equalization(input_image_path, output_image_path):
    # Open the image
    image = Image.open(input_image_path)

    # Convert the image to grayscale (if it's a color image)
    if image.mode != 'L':
        image = image.convert('L')

    # Get the image histogram
    histogram = image.histogram()

    # Calculate the cumulative distribution function (CDF) of the histogram
    cdf = [sum(histogram[:i+1]) for i in range(256)]

    # Normalize the CDF
    num_pixels = len(image.getdata())
    cdf_normalized = [((cdf[i] - cdf[0]) / (num_pixels - 1)) * 255 for i in range(256)]

    # Apply the equalization to the image
    equalized_image = image.point(cdf_normalized)

    # Save the equalized image
    equalized_image.save(output_image_path)


if __name__ == "__main__":
    input_image_path = filedialog.askopenfilename()
    output_image_path = "output_image.jpg"

    histogram_equalization(input_image_path, output_image_path)
    print(f"Image has been histogram equalized and saved as {output_image_path}")
