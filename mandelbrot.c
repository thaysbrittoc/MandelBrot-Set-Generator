// Mandelbrot
// Created by
// Thays Costa(z5183075)
// Created on 2017-09-17


#include "mandelbrot.h"
#include "pixelColor.h"

#define ESCAPE_CONDITION 4

complex complexSquare (complex c);
complex complexAdd (complex a, complex b);
double complexMagnitude (complex c);
double pixelsDistance (int z);
double numberOfPixels (int z);


// Draw a single Mandelbrot tile, by calculating and colouring each of
// the pixels in the tile.
//
// The function returns this tile by filling in the `pixels` 2D array
// that is passed in to your function.
//
// The `pixels` array is TILE_SIZE high and TILE_SIZE wide.
// The bottom left corner of the image is pixels[0][0].
//
// `center` is a complex number, representing the center of the tile.
// `z` is used to calculate the distance between each pixel in the image.
// Each pixel is 2^(-z) apart from each other.
void drawMandelbrot(pixel pixels[TILE_SIZE][TILE_SIZE], complex center, int z) {

    int grid[TILE_SIZE][TILE_SIZE];
    escapeGrid(grid, center, z);

    int row = 0;
    int col = 0;
    while (row < TILE_SIZE) {
        while (col < TILE_SIZE) {
            pixels[row][col] = pixelColor(grid[row][col]);
            col++;
        }
        col = 0;
        row++;
    }

}




// Determine the number of steps required to escape the Mandelbrot set,
// for the given complex number `c`.
int escapeSteps(complex c) {
    // setting the seed: z0= 0 + 0i;
    complex z0;
    z0.re = 0;
    z0.im = 0;

    // assigning the first interaction to be equal to z0 so it will enter the loop
    complex z = z0;

    // looping to get the interaction between the complex number c and the previous interacition
    // zn = (z^2) + c  ====> this is the formula for the interaction, where z is the previous
    // interaction and c is the constant complex number.
    // The first interaction (z0) will be always (0 + 0i)
    // We will use "escape" as a flag to end up our loop when 
    // the magnitude of the complex number reaches the escape condition
    // when is greater than 4.
    int steps = 0;
    int escape = 0;
    while ((steps < MAX_STEPS) && (escape == 0)) {
        z = complexAdd(complexSquare(z), c);
        if (complexMagnitude(z) > ESCAPE_CONDITION) {
            escape = 1;
        }
    steps++;
    }
    return steps;
}

// Fill a grid of TILE_SIZE by TILE_SIZE pixels, with the number of
// steps each pixel took to escape the Mandelbrot set.
void escapeGrid(int grid[TILE_SIZE][TILE_SIZE], complex center, int z) {

    // calculates the size of the region considering the zoom and 
    // the distance between pixels.
    double regionSize = (TILE_SIZE - 1) * pixelsDistance(z);

    // coordinates of left bottom corner:
    complex pixel;
    pixel.re = center.re - (regionSize/2);
    pixel.im = center.im - (regionSize/2);

    // cordinates of right bottom corner:
    complex pixelMax;
    pixelMax.re = center.re + (regionSize/2); 
    pixelMax.im = center.im + (regionSize/2); 

    // looping through each pixel and extracting
    // the quantity of steps needed to escape
    // the set.
    int row = 0;
    int col = 0;
    while (pixel.im <= pixelMax.im){
        while (pixel.re <= pixelMax.re){
            grid[row][col] = escapeSteps(pixel);
            pixel.re += pixelsDistance(z);
            col++;
        }
        col = 0;
        row++;
        pixel.im += pixelsDistance(z);
        pixel.re = center.re - (regionSize/2);
    }
}

// Calculates the distance between pixels
// Note that the distance between pixels is: 2^(-z)
// Here we assigned one and two to be doubles so we 
// could divide it and get double as a result.
double pixelsDistance (int z) {
    int i = 1;
    double distance = 1;
    double one = 1;
    double two = 2;

    while (i <= z) {
        distance = (one/two) * distance;
        i++;
    }
    return distance;

}


// gets one complex number c and squares it
complex complexSquare(complex c) {
    complex squared;
    squared.re = ((c.re * c.re) - (c.im * c.im));
    squared.im = (2 * c.re * c.im);
    return squared;
}


// sum two complex numbers c and d 
// c = (a + bi)  and d = (e + fi)
// then c + d = (a + e) + (b + f)i
complex complexAdd(complex a, complex b){
    complex added;
    added.re = (a.re + b.re);
    added.im = (a.im + b.im);

    return added;
}


// calculates the magnitude of a complex number c.
// the magnitude of c =>>>> |c| = c.re^2 + c.im^2
double complexMagnitude(complex c) {
    double realSquared = (c.re * c.re);
    double imaginarySquared = (c.im * c.im);
    double magnitude = (realSquared + imaginarySquared);

    return magnitude;
}


