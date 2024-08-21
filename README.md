# Image Processing Library In C

## Overview

This library provides a simple implementation of edge detection using the Sobel operator. It is designed to be lightweight and efficient, focusing solely on processing grayscale images to detect edges
and is made using only pure C.

## Features

- **Edge Detection**: Utilizes the Sobel operator to detect edges in grayscale images.
- More coming soon.

## Installation

```bash
git clone https://github.com/yourusername/edge-detection-library.git
```
## Compiling

```bash
gcc main.c kernel.c -o main
```

## Python Scripts

```load.py``` loads the image you want to perform edge detection on by passing the image path as a parameter and converts the image int grayscale and dumps the data into a text file for the C program to read.

```display.py``` displays the image after the convolution is done by the main.c program.

## Examples

Edge detection performed using sobel operator 

| -1 |  0 |  1 |
|----|----|----|
| -2 |  0 |  2 |
| -1 |  0 |  1 |

### Before

![WhatsApp Image 2024-08-19 at 9 55 53 PM](https://github.com/user-attachments/assets/e323c642-2360-452a-ac50-486a0868add8)


![WIN_20240817_17_02_12_Pro](https://github.com/user-attachments/assets/da5308bc-a09e-4a61-8903-d3c62edb5939)


### After

![output_image2](https://github.com/user-attachments/assets/d5748502-0d38-4e57-b220-9f9a3b9b1b3b)

![output_image2](https://github.com/user-attachments/assets/88877e31-7059-47cc-bc12-80069d870cd1)

