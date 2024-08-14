#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    int** data;
} Image;

typedef struct {
    int size;
    float** data;
} Kernel;

Image* convolution(Image* input_image, Kernel* kernel) {
    int i, j, m, n;
    float sum;
    int new_width = input_image->width - kernel->size + 1;
    int new_height = input_image->height - kernel->size + 1;
    
    // Create output image
    Image* output_image = (Image*)malloc(sizeof(Image));
    output_image->width = new_width;
    output_image->height = new_height;
    
    // Allocate memory for output image data
    output_image->data = (int**)malloc(new_height * sizeof(int*));
    for (i = 0; i < new_height; i++) {
        output_image->data[i] = (int*)malloc(new_width * sizeof(int));
    }
    
    // Perform convolution
    for (i = 0; i < new_height; i++) {
        for (j = 0; j < new_width; j++) {
            sum = 0.0;
            for (m = 0; m < kernel->size; m++) {
                for (n = 0; n < kernel->size; n++) {
                    sum += input_image->data[i + m][j + n] * kernel->data[m][n];
                }
            }
            output_image->data[i][j] = (int)sum;
        }
    }
    
    return output_image;
}

// Function to free the allocated memory
void freeImage(Image* img) {
    for (int i = 0; i < img->height; i++) {
        free(img->data[i]);
    }
    free(img->data);
    free(img);
}

// Function to create a sample image (for testing purposes)
Image* createSampleImage(int width, int height) {
    Image* img = (Image*)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        img->data[i] = (int*)malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            img->data[i][j] = i * width + j;  // Sample data
        }
    }
    return img;
}

// Function to create a sample kernel (for testing purposes)
Kernel* createSampleKernel(int size) {
    Kernel* kernel = (Kernel*)malloc(sizeof(Kernel));
    kernel->size = size;
    kernel->data = (float**)malloc(size * sizeof(float*));
    for (int i = 0; i < size; i++) {
        kernel->data[i] = (float*)malloc(size * sizeof(float));
        for (int j = 0; j < size; j++) {
            kernel->data[i][j] = 1.0f / (size * size);  // Simple averaging kernel
        }
    }
    return kernel;
}

int main() {
    // Create a sample 5x5 image
    Image* input_image = createSampleImage(5, 5);
    
    // Create a sample 3x3 kernel
    Kernel* kernel = createSampleKernel(3);
    
    // Perform convolution

    for (int i = 0; i < input_image->height; i++) {
        for (int j = 0; j < input_image->width; j++) {
            printf("%d ", input_image->data[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < kernel->size; i++) {
        for (int j = 0; j < kernel->size; j++) {
            printf("%f ", kernel->data[i][j]);
        }
        printf("\n");
    }

    Image* output_image = convolution(input_image, kernel);
    
    // Print output image
    printf("\nOutput Image:\n");
    for (int i = 0; i < output_image->height; i++) {
        for (int j = 0; j < output_image->width; j++) {
            printf("%d ", output_image->data[i][j]);
        }
        printf("\n");
    }
    
    // Free allocated memory
    freeImage(input_image);
    freeImage(output_image);
    // Free kernel memory (not implemented here for brevity)
    
    return 0;
}