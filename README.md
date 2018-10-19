# MandelBrot-Set-Generator--C-
Mandelbrot image server which is used to produce images of the Mandelbrot set.

This repository shows how I implemented the Mandelbrot image server.


From Wikipedia, the free encyclopedia
"MandelBrot Set is the set of complex numbers for which the function f(z)=z^2+c does not diverge when iterated from z=0. Eg. for which sequence f(0),f(f(0)), etc., remains bounded in absolute value.

Mandelbrot set images may be created by sampling the complex numbers and testing, for each sample point c, whether the sequence f(0),f(f(0)), ... goes to infinity."


Please check the link bellow for futher explanation about what is MandelBrot Set.

https://en.wikipedia.org/wiki/Mandelbrot_set



To run this code on your computer in order to see the results:

1) download the files in a folder in your computer
2) open the command-line interface/terminal
3) change directory (into the one that you saved the files)
4) Type on the command-line interface the command bellow and hit "enter":
    gcc -o mandelbrotServer server.c mandelbrot.c pixelColor.c
 (remember to change "gcc" into the compiler that you have intalled on your computer)
5) then type the following command:
    ./mandelbrotServer
6) You will see on the output something similar to:
   [SERVER] Access this server at http://localhost:1536/
 Then, copy "http://localhost:1536/" and paste on your browser.

Now you are able to use the mandelbrot viewer.
Play around with the viewer to find intersting results as you keep zooming into the colorfull bits of the image.

