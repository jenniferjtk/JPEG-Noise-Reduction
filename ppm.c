#include "ppm.h"
#include <assert.h>

/*
  Reads a PPM file and returns an image_t pointer.
  Assumes P6 (binary) format for the pixel data.
*/
image_t* read_ppm(FILE* image_file) {
    header_t header;
    // Read header
    fscanf(image_file, "%s", header.MAGIC_NUMBER);
    fscanf(image_file, "%d %d", &header.WIDTH, &header.HEIGHT);
    fscanf(image_file, "%d", &header.MAX_VAL);

    // Allocate memory for the image
    image_t* image = allocateMemory(&header);

    // Consume the newline after MAX_VAL
    fgetc(image_file);

    // Read pixel data
    for (int i = 0; i < header.HEIGHT; i++) {
        for (int j = 0; j < header.WIDTH; j++) {
            fscanf(image_file, "%c%c%c",
                &image->pixels[i][j].R,
                &image->pixels[i][j].G,
                &image->pixels[i][j].B);
        }
    }

    return image;
}

/*
  Writes an image to a PPM file (P6 format).
*/
void write_ppm(FILE* out_file, image_t* image) {
    fprintf(out_file, "%s\n", image->header.MAGIC_NUMBER);
    fprintf(out_file, "%d %d\n", image->header.WIDTH, image->header.HEIGHT);
    fprintf(out_file, "%d\n", image->header.MAX_VAL);

    for (int i = 0; i < image->header.HEIGHT; i++) {
        for (int j = 0; j < image->header.WIDTH; j++) {
            fprintf(out_file, "%c%c%c",
                image->pixels[i][j].R,
                image->pixels[i][j].G,
                image->pixels[i][j].B);
        }
    }
}

/*
  Allocates memory for the image structure and its pixels.
*/
image_t* allocateMemory(header_t* header) {
    image_t* image = malloc(sizeof(image_t));
    image->header = *header;

    image->pixels = malloc(header->HEIGHT * sizeof(pixel_t*));
    for (int i = 0; i < header->HEIGHT; i++) {
        image->pixels[i] = malloc(header->WIDTH * sizeof(pixel_t));
    }

    return image;
}

/*
  Frees the memory used by an image.
*/
void freeMemory(image_t* image) {
    for (int i = 0; i < image->header.HEIGHT; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    free(image);
}
