import cv2
import numpy as np


def get_neighbors(p, direction):
    offsets = [(-1, -1), (0, -1), (1, -1), (1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0)]
    neighbors = []

    for offset in offsets[direction * 2: direction * 2 + 3]:
        neighbors.append((p[0] + offset[0], p[1] + offset[1]))

    return tuple(neighbors)


def rotate_clockwise(direction):
    return (direction + 1) % 3


def is_valid_pixel(p, image):
    return 0 <= p[0] < image.shape[0] and 0 <= p[1] < image.shape[1] and image[p[0], p[1]] == 255


def find_contours(image):
    contours = []
    visited_pixels = set()

    height, width = image.shape

    def explore_contour(start_pixel):
        contour = [start_pixel]
        current_pixel = start_pixel
        visited_pixels.add(start_pixel)

        direction = 1
        rotations = 0

        while True:
            neighbors = get_neighbors(current_pixel, direction)

            valid_neighbor = next((neighbor for neighbor in neighbors if is_valid_pixel(neighbor, image)), None)

            if valid_neighbor is not None:
                contour.append(valid_neighbor)
                current_pixel = valid_neighbor
                image[current_pixel[0], current_pixel[1]] = 0
                visited_pixels.add(current_pixel)
                rotations = 0
                direction = rotate_clockwise(direction)
            elif rotations == 3:
                break
            else:
                rotations += 1
                direction = rotate_clockwise(direction)

        contours.append(contour)

    for y in range(height):
        for x in range(width):
            if image[y, x] == 255 and (y, x) not in visited_pixels:
                explore_contour((y, x))

    return contours


def visualize_contours(image, contours):
    blank_image = np.zeros((image.shape[0], image.shape[1], 3), np.uint8)
    blank_image[:, :] = (255, 255, 255)

    for contour in contours:
        for pixel in contour:
            blank_image[pixel[0], pixel[1]] = (30, 83, 57)

    cv2.imshow("Contour Image", blank_image)
    cv2.imshow("Original Image", image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()


def main():
    image_path = "image.jpg"
    image = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)

    (thresh, BnW_image) = cv2.threshold(image, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)

    result = find_contours(BnW_image)
    visualize_contours(image, result)


if __name__ == "__main__":
    main()