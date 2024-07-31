#include <stdio.h>
#include <stdlib.h>
#include "kernel.h"

int main(){
	int i, j;
	kernel k1 = getKernel(3);
	int **image2;

	int width = 5;
	int height = 5;
	image2 = (int **)malloc(height * sizeof(int *));
	for (i = 0; i < height; i++) {
		image2[i] = (int *)malloc(width * sizeof(int));
	}

	int values[5][5] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
	};

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			image2[i][j] = values[i][j];
		}
	}

	image img = convolution(image2, k1);

	for (int i = 0; i < img.height; i++) {
		for (int j = 0; j < img.width; j++) {
			printf("%d\t", img.data[i][j]);
		}
		printf("\n");
	}

	return 0;
}