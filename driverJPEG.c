#include <stdio.h>
#include <assert.h>
#include "ppm.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return 1;
    }

    // Open input file
    FILE *input = fopen(argv[1], "rb");
    assert(input != NULL);

    // Read PPM image
    image_t *image = read_ppm(input);
    fclose(input);

    // Apply blur
    image_t *blurred = applyBlur(image);

    // Write output
    FILE *out_file = fopen(argv[2], "wb");
    write_ppm(out_file, blurred);
    fclose(out_file);

    // Free memory
    freeMemory(image);
    freeMemory(blurred);

    printf("✅ Blur effect applied! Output saved as %s\n", argv[2]);
    return 0;
}

