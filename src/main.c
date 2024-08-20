#include <stdio.h>
#include <stdlib.h>
#include "kernel.h"

int main(){
	int i, j;
	Kernel k1 = getKernel(3);
	
	Image img1;

	img1 = read_image_from_file("text1.txt");

	Image img2 = convolution(img1.data, k1, 1280, 720);
	img2.height = 720;
	img2.width = 1280;

	printf("\n");
	for (int i = 0; i < img2.height; i++) {
		for (int j = 0; j < img2.width; j++) {
			printf("%d\t", img2.data[i][j]);
		}
		printf("\n");
	}

	FILE *file = fopen("output_image2.txt", "w");

	for (int i = 0; i < img2.height; i++) {
        for (int j = 0; j < img2.width; j++) {
            fprintf(file, "%d ", img2.data[i][j]);
        }
        fprintf(file, "\n");
    }


	Release(img1.data, img1.height);
	Release(img2.data, img2.height);

	return 0;
}