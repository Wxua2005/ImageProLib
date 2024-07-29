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
image convolution(image *img, kernel k);