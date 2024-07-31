typedef struct {
	
	int **data;
	int size;
	
} kernel;

typedef struct {

	int **data;
	int width;
	int height;

} image;

kernel getKernel(int size);
void readKernel(kernel k);
image convolution(int* input_image[], kernel k);
image _loadImage(int** _image, int width, int height);
