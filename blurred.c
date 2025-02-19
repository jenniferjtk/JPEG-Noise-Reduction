#include "ppm.h"

image_t* applyBlur(image_t* img) {
    header_t header = img->header;
    image_t* blurred = allocateMemory(&header);

    for (int i = 0; i < header.HEIGHT; i++) {
        for (int j = 0; j < header.WIDTH; j++) {
            int redSum = 0, greenSum = 0, blueSum = 0;
            int count = 0;

            // Loop through neighboring pixels (-1 to +1 in both directions)
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di;
                    int nj = j + dj;

                    // Check if the neighbor is within bounds
                    if (ni >= 0 && ni < header.HEIGHT && nj >= 0 && nj < header.WIDTH) {
                        redSum += img->pixels[ni][nj].R;
                        greenSum += img->pixels[ni][nj].G;
                        blueSum += img->pixels[ni][nj].B;
                        count++;
                    }
                }
            }

            // Compute the average color for blurring
            blurred->pixels[i][j].R = redSum / count;
            blurred->pixels[i][j].G = greenSum / count;
            blurred->pixels[i][j].B = blueSum / count;
        }
    }
    return blurred;
}
