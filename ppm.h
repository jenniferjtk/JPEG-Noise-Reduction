#ifndef PPM
#define PPM

#include <stdio.h>
#include <stdlib.h>

typedef struct header {
    char MAGIC_NUMBER[3];
    int WIDTH, HEIGHT, MAX_VAL;
} header_t;

typedef struct pixel {
    unsigned char R, G, B;
} pixel_t;

// PPM Image representation
typedef struct image {
    header_t header;
    pixel_t** pixels;
} image_t;

// Function prototypes
void openInputFiles(char* nameBuffer, FILE** input, int num_files);
image_t* read_ppm(FILE* image_file);
void write_ppm(FILE* out_file, image_t* image);
image_t* applyBlur(image_t* img);
image_t* allocateMemory(header_t* header);
void freeMemory(image_t* image);

#endif
