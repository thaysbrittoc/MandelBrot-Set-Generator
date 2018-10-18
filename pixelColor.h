// Pixel coloring function for the Mandelbrot Set
//
// You can compile the full server with the command
// dcc -o mandelbrotServer server.c mandelbrot.c pixelColor.c
//
#ifndef _PIXELCOLOR_H_
#define _PIXELCOLOR_H_

pixel pixelColor(int steps);

#endif // !defined(_PIXELCOLOR_H_)