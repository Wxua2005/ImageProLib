#include "kernel.h"
#include <stdio.h>
#include <stdlib.h>

kernel getKernel(int size) {
	int i, j;
	kernel k1;
	
	int **array = (int **)(malloc(sizeof(int *) * size)); // dynamically allocating outer array
	
	for (i = 0; i < size; i++) {
		
		array[i] = (int *)(malloc(sizeof(int) * size)); // looping through array and allocating memory
		
	}
	
	printf("Enter the kernel values\n");
	fflush(stdout); // Flushing the buffer output
	
	for (i = 0; i < size; i++) { 	// Reading values of the kernel from the user
		for (j = 0; j < size; j++) {
			scanf("%d", &array[i][j]);
		}
	}
	
	k1.data = array;
	k1.size = size;
	
	return k1;
}

void readKernel(kernel k) {
	int i;
	int j;
	
	printf("Kernel\n");
	fflush(stdout);
	
	for (i = 0; i < k.size; i++) { 	// Displaying values of the kernel
		for (j = 0; j < k.size; j++) {
			printf("%d\t", k.data[i][j]);
		}
		printf("\n");
	}
}

image convolution(int* input_image[], kernel k) {

	int i, j, m, n;
	int sum;
	int width = 5;
	int height = 5;
	
	image img;
	img.width = width;
	img.height = height;
	
	img.data = (int **)(malloc(sizeof(int *) * height));
	
	for (i = 0; i < height; i++) {
		img.data[i] = (int *)(malloc(sizeof(int) * width));
	}
	
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			sum = 0;
			for (m = 0; m < k.size; m++) {
				for (n = 0; n < k.size; n++) {
					if (i + m < height && j + n < width) {
						sum += input_image[i + m][j + n] * k.data[m][n];
					}
				}
			}
			img.data[i][j] = sum;
		}
	}
	
	return img;

}

image _loadImage(int** _image, int width, int height) {
	int i;
	image img; 
	img.width = width;
	img.height = height;

	img.data = (int **)(malloc(sizeof(int *) * height));

	for (i = 0; i < height; i++) {
		img.data[i] = (int *)(malloc(sizeof(int) * width));
	}

	for (i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			img.data[i][j] = _image[i][j];
		}
	}
	return img;
}
