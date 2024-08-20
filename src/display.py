import numpy as np
import cv2 as cv

def read_image_from_text_file(file_path):
    with open(file_path, 'r') as file:
        # Read all lines from the file
        lines = file.readlines()

    data = []
    for line in lines:
        row = list(map(int, line.split()))
        data.append(row)

    image_array = np.array(data, dtype=np.int32)  # Use int32 to avoid overflow before clamping

    # Apply the clamping
    image_array[image_array < 0] = 0
    image_array[image_array > 255] = 255

    # Convert to uint8 after clamping
    image_array = image_array.astype(np.uint8)

    return image_array

file_path = 'output_image2.txt' 
image_array = read_image_from_text_file(file_path)

print("Image shape:", image_array.shape)
cv.imshow('Image', image_array)
cv.waitKey(0)
cv.destroyAllWindows()
