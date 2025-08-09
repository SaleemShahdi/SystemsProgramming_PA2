#include <math.h>
#include <stdio.h>

void convert_to_YCrCb(unsigned char *rgb_pixels, unsigned char *ycc_pixels, int width, int height)
{
    int totalpixels = width * height;
    int pixelsize = 3;
    unsigned char r, g, b, y, cb, cr;
    for (int i = 0; i <= ((totalpixels - 1) * pixelsize); i = i + pixelsize)
    {
        for (int q = 0; q <= pixelsize - 1; q++)
        {
            unsigned char current = rgb_pixels[i+q];
            if (q == 0)
            {
                r = current;
            }
            else if (q == 1)
            {
                g = current;
            }
            else if (q == 2)
            {
                b = current;
            }
        }
        y = (unsigned char)round(0.299 * r + 0.587 * g + 0.114 * b);
        cb = (unsigned char)round(128 + (-0.168736 * r - 0.331264 * g + 0.5 * b));
        cr = (unsigned char)round(128 + (0.5 * r - 0.418688 * g - 0.081312 * b));
        /*if (i == 0) {
            printf("C rgb = %d %d %d\n", r, g, b);
            printf("C ycbcr = %d %d %d\n", (int)y, (int)cb, (int)cr);
        }*/
        for (int q = 0; q <= pixelsize - 1; q++)
        {
            if (q == 0)
            {
                ycc_pixels[i+q] = y;
            }
            else if (q == 1)
            {
                ycc_pixels[i+q] = cb;
            }
            else if (q == 2)
            {
                ycc_pixels[i+q] = cr;
            }
        }
    }
    return;
}