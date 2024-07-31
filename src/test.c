#include <stdio.h>
#include "png.h"

int main() {
    FILE *fp = fopen("image.png", "rb");
    if (!fp) {
        printf("Error: Could not open file\n");
        return -1;
    }

    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) {
        printf("Error: Could not create read struct\n");
        fclose(fp);
        return -1;
    }

    png_infop info = png_create_info_struct(png);
    if (!info) {
        printf("Error: Could not create info struct\n");
        png_destroy_read_struct(&png, NULL, NULL);
        fclose(fp);
        return -1;
    }

    if (setjmp(png_jmpbuf(png))) {
        printf("Error: png_jmpbuf failed\n");
        png_destroy_read_struct(&png, &info, NULL);
        fclose(fp);
        return -1;
    }

    png_init_io(png, fp);
    png_read_info(png, info);

    int width = png_get_image_width(png, info);
    int height = png_get_image_height(png, info);
    png_byte color_type = png_get_color_type(png, info);
    png_byte bit_depth = png_get_bit_depth(png, info);

    // Print the read values
    printf("Image width: %d\n", width);
    printf("Image height: %d\n", height);
    printf("Color type: %d\n", color_type);
    printf("Bit depth: %d\n", bit_depth);

    // Print color type as string
    printf("Color type: ");
    switch(color_type) {
        case PNG_COLOR_TYPE_GRAY:
            printf("Grayscale\n");
            break;
        case PNG_COLOR_TYPE_GRAY_ALPHA:
            printf("Grayscale with alpha\n");
            break;
        case PNG_COLOR_TYPE_PALETTE:
            printf("Palette\n");
            break;
        case PNG_COLOR_TYPE_RGB:
            printf("RGB\n");
            break;
        case PNG_COLOR_TYPE_RGB_ALPHA:
            printf("RGB with alpha\n");
            break;
        default:
            printf("Unknown\n");
    }

    png_destroy_read_struct(&png, &info, NULL);
    fclose(fp);

    return 0;
}