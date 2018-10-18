// Pixel Color
// Created by
// Thays Costa(z5183075)
// Created on 2017-09-17
#include "mandelbrot.h"
#include "pixelColor.h"
#include <math.h>
#include <stdlib.h>

// This function should take a number (of steps taken to escape the
// Mandelbrot set), and convert it to a color.
pixel pixelColor(int steps) {
    pixel color = {
        .red = 0,
        .green = 0,
        .blue = 0,
    };


    if (steps == 256) {
        color.red = 0;
        color.green = 0;
        color.blue = 0;
    } else if (steps <255 && steps > 180) {
        color.red = 12 + steps/2;
        color.green = 44 + steps;
        color.blue = 56 + (steps % 256);
    } else if (steps <180 && steps > 120) {
        color.red = 18 + steps;
        color.green = 44 + (steps % 256);
        color.blue = 18 + steps/2;
    } else {
        color.red = 32 + (steps % 256);
        color.green = 12 + steps/2;
        color.blue = 24 + steps;
    }
    return color;
}

