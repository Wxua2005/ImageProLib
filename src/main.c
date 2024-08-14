#include <stdio.h>
#include <stdlib.h>
#include "kernel.h"

int main(){
	int i, j;
	Kernel k1 = getKernel(3);
	int **image2;

	int width = 5;
	int height = 5;
	image2 = (int **)malloc(height * sizeof(int *));
	for (i = 0; i < height; i++) {
		image2[i] = (int *)malloc(width * sizeof(int));
	}

	int values[7][7] = {
		{1, 1, 3, 2, 0, 1, 1},
		{1, 1, 3, 2, 0, 1, 1},
		{2, 2, 1, 0, 1, 3, 3},
		{1, 1, 3, 2, 1, 1, 1},
		{2, 2, 0, 2, 3, 2, 2},
		{1, 1, 3, 1, 2, 1, 1},
		{1, 1, 3, 1, 2, 1, 1}
	};

	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			image2[i][j] = values[i][j];
		}
	}

	Image img = convolution(image2, k1);

	printf("\n");
	for (int i = 0; i < img.height; i++) {
		for (int j = 0; j < img.width; j++) {
			printf("%d\t", img.data[i][j]);
		}
		printf("\n");
	}

	Release(image2, height);

	return 0;
}