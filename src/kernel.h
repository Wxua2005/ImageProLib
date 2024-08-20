#ifndef KERNEL_H
#define KERNEL_H

typedef struct {
	
	float **data;
	int size;
	
} Kernel;

typedef struct {

	int **data;
	int width;
	int height;

} Image;

Kernel getKernel(int size);

void readKernel(Kernel k);

Image convolution(int** input_image, Kernel k, int width, int height);

Image _loadImage(int** _image, int width, int height);

// TODO: Make addPadding function take 2D array as input rather than image
Image* addPadding(Image* input_image, int padding);

void Release(int **array, int rows);

Image read_image_from_file(const char *filename);

#endif