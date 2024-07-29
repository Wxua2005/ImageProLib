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

image convolution(image *img, kernel k) {
	
	int middle_x = (k.size - 1) / 2;
	int i;
	int accumulator = 0;
	
	for (i = 0; i < width; i++) {
		
	}
}